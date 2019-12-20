/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */
#include "sound.h"
#include "dragons.h"
#include "audio/mixer.h"
#include "audio/audiostream.h"
#include "audio/decoders/raw.h"
#include "audio/decoders/xa.h"
#include "common/file.h"
#include "common/memstream.h"
#include "bigfile.h"
#include "dragonrms.h"
#include "VabSound.h"

#define RAW_CD_SECTOR_SIZE 2352

#define CDXA_TYPE_MASK     0x0E
#define CDXA_TYPE_DATA     0x08
#define CDXA_TYPE_AUDIO    0x04

namespace Dragons {

struct SpeechLocation {
	uint32 talkId;
	uint16 sectorStart;
	int8 startOffset;
	uint16 sectorEnd;
} SpeechLocation;

void CdIntToPos_0(uint32 param_1)//, byte *param_2)
{
	int iVar1;
	int iVar2;
	int iVar3;
	uint8 minute;
	uint8 second;
	uint8 sector;

	iVar3 = (param_1 + 0x96) / 0x4b;
	iVar2 = (param_1 + 0x96) % 0x4b;
	iVar1 = iVar3 / 0x3c;
	iVar3 = iVar3 % 0x3c;
	second = (char)iVar3 + (char)(iVar3 / 10) * 6;
	sector = (char)iVar2 + (char)(iVar2 / 10) * 6;
	minute = (char)iVar1 + (char)(iVar1 / 10) * 6;


	uint32 out =          (((uint)(minute >> 4) * 10 + ((uint)minute & 0xf)) * 0x3c +
						   (uint)(second >> 4) * 10 + ((uint)second & 0xf)) * 0x4b +
						  (uint)(sector >> 4) * 10 + ((uint)sector & 0xf) + -0x96;

	debug("Seek Audio %2X:%2X:%2X  in: %d out %d", minute, second, sector, param_1, out);

	return;
}

void SoundManager::playSpeech(uint32 textIndex) {
	if (isSpeechPlaying()) {
//		_vm->_mixer->stopHandle(_speechHandle);
		return;
	}

	struct SpeechLocation speechLocation;
	if (!getSpeechLocation(textIndex, &speechLocation)) {
		return;
	}

	Common::File *fd = new Common::File();
	if (!fd->open("dtspeech.xa")) {
		error("Failed to open dtspeech.xa");
	}
	CdIntToPos_0(speechLocation.sectorStart * 32);
	fd->seek(((speechLocation.sectorStart * 32) + speechLocation.startOffset) * RAW_CD_SECTOR_SIZE);
	PSXAudioTrack *_audioTrack = new PSXAudioTrack(fd, Audio::Mixer::SoundType::kSpeechSoundType);
	for (int i = 0x0; i < speechLocation.sectorEnd - speechLocation.sectorStart;i++) {
		fd->seek(((speechLocation.sectorStart * 32) + speechLocation.startOffset + i * 32) * RAW_CD_SECTOR_SIZE);
		_audioTrack->queueAudioFromSector(fd);
	}
	_audioTrack->getAudioStream()->finish();
	fd->close();
	delete fd;
	_vm->setFlags(ENGINE_FLAG_8000);
	_vm->_mixer->playStream(Audio::Mixer::kSpeechSoundType, &_speechHandle, _audioTrack->getAudioStream());
	delete _audioTrack;
}

bool SoundManager::isSpeechPlaying() {
	return _vm->_mixer->isSoundHandleActive(_speechHandle);
}

bool SoundManager::getSpeechLocation(uint32 talkId, struct SpeechLocation *location) {
	Common::File *fd = new Common::File();
	if (!fd->open("dragon.exe")) {
		error("Failed to open dragon.exe");
	}
	fd->seek(0x4e138);
	bool foundId = false;
	for (int i = 0; i < 2272; i++) {
		uint32 id = (fd->readUint32LE() & 0xffffff);
		fd->seek(-1, SEEK_CUR);
		int8 startOffset = fd->readSByte();
		uint16 start = fd->readUint16LE();
		uint16 end = fd->readUint16LE();
		if (id == talkId) {
			location->talkId = id;
			location->sectorStart = start;
			location->startOffset = startOffset;
			location->sectorEnd = end;
			foundId = true;
			debug("sectors [%d-%d] unk byte = %d", start * 32, end * 32, startOffset);
			break;
		}
	}

	fd->close();
	delete fd;

	return foundId;
}

void SoundManager::PauseCDMusic() {
	//TODO check PauseCDMusic() to see if we need any more logic.
	if(isSpeechPlaying()) {
		_vm->_mixer->stopHandle(_speechHandle);
		_vm->clearFlags(ENGINE_FLAG_8000);
	}
}

SoundManager::PSXAudioTrack::PSXAudioTrack(Common::SeekableReadStream *sector, Audio::Mixer::SoundType soundType) {
	sector->skip(19);
	byte format = sector->readByte();
	bool stereo = (format & (1 << 0)) != 0;
	uint rate = (format & (1 << 2)) ? 18900 : 37800;
	_audStream = Audio::makeQueuingAudioStream(rate, stereo);

	memset(&_adpcmStatus, 0, sizeof(_adpcmStatus));
}

SoundManager::PSXAudioTrack::~PSXAudioTrack() {
}

// Ha! It's palindromic!
#define AUDIO_DATA_CHUNK_SIZE   2304
#define AUDIO_DATA_SAMPLE_COUNT 4032

static const int s_xaTable[5][2] = {
		{   0,   0 },
		{  60,   0 },
		{ 115, -52 },
		{  98, -55 },
		{ 122, -60 }
};

void SoundManager::PSXAudioTrack::queueAudioFromSector(Common::SeekableReadStream *sector) {
	sector->skip(24);

	// This XA audio is different (yet similar) from normal XA audio! Watch out!
	// TODO: It's probably similar enough to normal XA that we can merge it somehow...
	// TODO: RTZ PSX needs the same audio code in a regular AudioStream class. Probably
	// will do something similar to QuickTime and creating a base class 'ISOMode2Parser'
	// or something similar.
	byte *buf = new byte[AUDIO_DATA_CHUNK_SIZE];
	sector->read(buf, AUDIO_DATA_CHUNK_SIZE);

	int channels = _audStream->isStereo() ? 2 : 1;
	int16 *dst = new int16[AUDIO_DATA_SAMPLE_COUNT];
	int16 *leftChannel = dst;
	int16 *rightChannel = dst + 1;

	for (byte *src = buf; src < buf + AUDIO_DATA_CHUNK_SIZE; src += 128) {
		for (int i = 0; i < 4; i++) {
			int shift = 12 - (src[4 + i * 2] & 0xf);
			int filter = src[4 + i * 2] >> 4;
			int f0 = s_xaTable[filter][0];
			int f1 = s_xaTable[filter][1];
			int16 s_1 = _adpcmStatus[0].sample[0];
			int16 s_2 = _adpcmStatus[0].sample[1];

			for (int j = 0; j < 28; j++) {
				byte d = src[16 + i + j * 4];
				int t = (int8)(d << 4) >> 4;
				int s = (t << shift) + ((s_1 * f0 + s_2 * f1 + 32) >> 6);
				s_2 = s_1;
				s_1 = CLIP<int>(s, -32768, 32767);
				*leftChannel = s_1;
				leftChannel += channels;
			}

			if (channels == 2) {
				_adpcmStatus[0].sample[0] = s_1;
				_adpcmStatus[0].sample[1] = s_2;
				s_1 = _adpcmStatus[1].sample[0];
				s_2 = _adpcmStatus[1].sample[1];
			}

			shift = 12 - (src[5 + i * 2] & 0xf);
			filter = src[5 + i * 2] >> 4;
			f0 = s_xaTable[filter][0];
			f1 = s_xaTable[filter][1];

			for (int j = 0; j < 28; j++) {
				byte d = src[16 + i + j * 4];
				int t = (int8)d >> 4;
				int s = (t << shift) + ((s_1 * f0 + s_2 * f1 + 32) >> 6);
				s_2 = s_1;
				s_1 = CLIP<int>(s, -32768, 32767);

				if (channels == 2) {
					*rightChannel = s_1;
					rightChannel += 2;
				} else {
					*leftChannel++ = s_1;
				}
			}

			if (channels == 2) {
				_adpcmStatus[1].sample[0] = s_1;
				_adpcmStatus[1].sample[1] = s_2;
			} else {
				_adpcmStatus[0].sample[0] = s_1;
				_adpcmStatus[0].sample[1] = s_2;
			}
		}
	}

	int flags = Audio::FLAG_16BITS;

	if (_audStream->isStereo())
		flags |= Audio::FLAG_STEREO;

#ifdef SCUMM_LITTLE_ENDIAN
	flags |= Audio::FLAG_LITTLE_ENDIAN;
#endif

	_audStream->queueBuffer((byte *)dst, AUDIO_DATA_SAMPLE_COUNT * 2, DisposeAfterUse::YES, flags);
	delete[] buf;
}

SoundManager::SoundManager(DragonsEngine *vm, BigfileArchive *bigFileArchive, DragonRMS *dragonRMS)
		: _vm(vm),
		  _bigFileArchive(bigFileArchive),
		  _dragonRMS(dragonRMS) {
	DAT_8006bb60_sound_related = 0;
	// TODO: Set volumes
	SomeInitSound_FUN_8003f64c();
	loadMusAndGlob();
}

SoundManager::~SoundManager() {
	delete _vabMusx;
	delete _vabGlob;
}

void SoundManager::SomeInitSound_FUN_8003f64c() {
	// TODO: Check if this changes on different game versions?
	memset(_soundArr, 0x10, sizeof(_soundArr));

	_soundArr[192] = 0x0b;
	_soundArr[193] = 0x0b;
	_soundArr[226] = _soundArr[226] | 0x80u;
	_soundArr[229] = 0x0b;
	_soundArr[230] = 0x0b;
	_soundArr[450] = 0x0b;
	_soundArr[451] = 0x0b;
	_soundArr[514] = 0x8b;
	_soundArr[515] = 0x0b;
	_soundArr[516] = 0x0b;
	_soundArr[578] = 0x0b;
	_soundArr[579] = 0x0b;
	_soundArr[580] = 0x0b;
	_soundArr[611] = 0x0b;
	_soundArr[674] = 0x8b;
	_soundArr[675] = 0x88;
	_soundArr[711] = 0x08;
	_soundArr[866] = 0x0b;
	_soundArr[896] = 0x0b;
	_soundArr[897] = _soundArr[897] | 0x80u;
	_soundArr[930] = _soundArr[930] | 0x80u;
	_soundArr[934] = 0x8b;
	_soundArr[935] = 0x8b;
	_soundArr[936] = 0x0b;
	_soundArr[937] = 0x88;
	_soundArr[941] = 0x0b;
	_soundArr[964] = 0x0b;
	_soundArr[995] = _soundArr[995] | 0x80u;
	_soundArr[1027] = 0x08;
	_soundArr[1056] = 0x8b;
	_soundArr[1059] = _soundArr[1059] | 0x80u;
	_soundArr[1122] = 0x0b;
	_soundArr[1250] = 0x08;
	_soundArr[1252] = 0x0b;
	_soundArr[1256] = 0x0b;
	_soundArr[1257] = 0x08;
	_soundArr[1258] = 0x0b;
	_soundArr[1284] = 0x0b;
	_soundArr[1378] = 0x0b;
	_soundArr[1379] = _soundArr[1379] | 0x80u;
	_soundArr[1380] = 0x0b;
	_soundArr[1385] = 0x0b;
	_soundArr[1443] = 0x8b;
	_soundArr[1444] = _soundArr[1444] | 0x80u;
	_soundArr[1445] = _soundArr[1445] | 0x80u;
	_soundArr[1446] = 0x8b;
	_soundArr[1472] = 0x8b;
	_soundArr[1508] = _soundArr[1508] | 0x80u;
	_soundArr[1575] = 0x08;
	_soundArr[1576] = 0x08;
	_soundArr[1577] = 0x08;
	_soundArr[1604] = 0x08;
	_soundArr[1605] = 0x08;
	_soundArr[1610] = 0x0b;
	_soundArr[1611] = 0x0b;
	_soundArr[1612] = 0x0b;
}

void SoundManager::loadMusAndGlob() {
	_vabMusx = loadVab("musx.vh", "musx.vb");
	_vabGlob = loadVab("glob.vh", "glob.vb");
}

VabSound * SoundManager::loadVab(const char *headerFilename, const char *bodyFilename) {
	uint32 headSize, bodySize;

	auto headData = _bigFileArchive->load(headerFilename, headSize);
	auto bodyData = _bigFileArchive->load(bodyFilename, bodySize);

	auto *headStream = new Common::MemoryReadStream(headData, headSize, DisposeAfterUse::YES);
	auto *bodyStream = new Common::MemoryReadStream(bodyData, bodySize, DisposeAfterUse::YES);

	return new VabSound(headStream, bodyStream);
}

/**
 *
 * @param soundId Bit 0x4000 set indicates STOP SOUND, bit 0x8000 set indicates SOUND IS GLOBAL (comes from glob.v[hb])
 */
void SoundManager::playOrStopSound(uint16 soundId) {
	uint16 volumeId;
	if ((soundId & 0x8000u) == 0) {
		volumeId = soundId + _vm->getCurrentSceneId() * 0x20;
	} else {
		volumeId = soundId & 0x7fffu;
	}

	if ((soundId & 0x4000u) == 0) {
		playSound(soundId, volumeId);
	} else {
		stopSound(soundId, volumeId);
	}
}

void SoundManager::playSound(uint16 soundId, uint16 volumeId) {
	byte volume = 0;

	volume = _soundArr[volumeId];
	_soundArr[volumeId] = _soundArr[volumeId] | 0x40u;      // Set bit 0x40

	auto vabSound = ((soundId & 0x8000u) != 0) ? _vabGlob : _vabMusx;

	// TODO: CdVolume!
	auto cdVolume = 1;
	auto newVolume = cdVolume * volume;
	if (newVolume < 0) {
		newVolume += 0xf;
	}

	auto realId = soundId & 0x7fffu;

	auto program = realId >> 4u;
	auto key = ((realId & 0xfu) << 1u | 0x40u);

	// TODO: Volume
	if (!_vm->_mixer->isSoundHandleActive(_sfxHandle)) {
		_vm->_mixer->playStream(Audio::Mixer::kSFXSoundType, &_sfxHandle, vabSound->getAudioStream(program, key));
	}
}

void SoundManager::stopSound(uint16 soundId, uint16 volumeId) {
	_soundArr[volumeId] = _soundArr[volumeId] & 0xbfu;      // Clear bit 0x40

	auto vabId = getVabFromSoundId(soundId);
	// TODO: Actually stop sound
	_vm->_mixer->stopHandle(_sfxHandle);
}

uint16 SoundManager::getVabFromSoundId(uint16 soundId) {
	// TODO
	return -1;
}

void SoundManager::loadMsf(uint32 sceneId) {
	char msfFileName[] = "XXXX.MSF";
	memcpy(msfFileName, _dragonRMS->getSceneName(sceneId), 4);

	if (_bigFileArchive->doesFileExist(msfFileName)) {
		uint32 msfSize;
		byte *msfData = _bigFileArchive->load(msfFileName, msfSize);

		auto *msfStream = new Common::MemoryReadStream(msfData, msfSize, DisposeAfterUse::YES);

		delete _vabMusx;
		_vabMusx = new VabSound(msfStream, _vm);
	}
}

} // End of namespace Dragons
