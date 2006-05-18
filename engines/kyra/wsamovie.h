/* ScummVM - Scumm Interpreter
 * Copyright (C) 2004-2006 The ScummVM project
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
 * $URL$
 * $Id$
 *
 */

#ifndef WSAMOVIES_H
#define WSAMOVIES_H

#include "kyra/resource.h"

namespace Audio {
class AppendableAudioStream;
class SoundHandle;
} // end of namespace Audio

namespace Kyra {
class KyraEngine;

class Movie {
public:
	Movie(KyraEngine *vm) : _x(-1), _y(-1), _drawPage(-1), _vm(vm), _opened(false) {}
	virtual ~Movie() {}

	virtual bool opened() { return _opened; }

	virtual void open(const char *filename, int offscreen, uint8 *palette) = 0;
	virtual void close() = 0;

	virtual int frames() = 0;

	virtual void displayFrame(int frameNum) = 0;

	virtual void setX(int x) { _x = x; }
	virtual void setY(int y) { _y = y; }
	virtual void setDrawPage(int page) { _drawPage = page; }
protected:
	KyraEngine *_vm;
	bool _opened;
	
	int _x, _y;
	int _drawPage;
};

class WSAMovieV1 : public Movie {
public:
	WSAMovieV1(KyraEngine *vm);
	virtual ~WSAMovieV1();

	virtual void open(const char *filename, int offscreen, uint8 *palette);
	virtual void close();

	virtual int frames() { return _opened ? _numFrames : -1; }

	virtual void displayFrame(int frameNum);
protected:
	virtual void processFrame(int frameNum, uint8 *dst);

	enum WSAFlags {
		WF_OFFSCREEN_DECODE = 0x10,
		WF_NO_FIRST_FRAME = 0x40,
		WF_HAS_PALETTE = 0x100
	};

	uint16 _currentFrame;
	uint16 _numFrames;
	uint16 _width;
	uint16 _height;
	uint16 _flags;
	uint8 *_deltaBuffer;
	uint32 _deltaBufferSize;
	uint8 *_offscreenBuffer;
	uint32 *_frameOffsTable;
	uint8 *_frameData;
};

class KyraEngine_v3;

// it could be possible that Kyrandia2 uses exactly the same format
class WSAMovieV3 : public WSAMovieV1 {
public:
	WSAMovieV3(KyraEngine_v3 *vm);
	
	void open(const char *filename, int unk1, uint8 *palette);
	
	void setX(int x) { _x = x + _xAdd; }
	void setY(int y) { _y = y + _yAdd; }
protected:
	KyraEngine_v3 *_vm3;
	
	int16 _xAdd;
	int16 _yAdd;
};

// Kyra 3 VQA movies. Should perhaps be in another header file.

class VQAMovie : public Movie {
public:
	VQAMovie(KyraEngine *vm, OSystem *system);
	~VQAMovie();

	int frames() { return _opened ? _header.numFrames : -1; }

	void displayFrame(int frameNum);

	// Only the first parameter is used.
	virtual void open(const char *filename, int offscreen, uint8 *palette);
	void close();
	void play();

protected:
	OSystem *_system;

	struct VQAHeader {
		uint16 version;
		uint16 flags;
		uint16 numFrames;
		uint16 width;
		uint16 height;
		uint8 blockW;
		uint8 blockH;
		uint8 frameRate;
		uint8 cbParts;
		uint16 colors;
		uint16 maxBlocks;
		uint32 unk1;
		uint16 unk2;
		uint16 freq;
		uint8 channels;
		uint8 bits;
		uint32 unk3;
		uint16 unk4;
		uint32 maxCBFZSize;
		uint32 unk5;
	};

	struct Buffer {
		void *data;
		uint32 size;
	};

	Buffer _buffers[2];

	void initBuffers();
	void *allocBuffer(int num, uint32 size);
	void freeBuffers();

	int decodeFormat80(byte *inbuf, byte *outbuf);
	void decodeSND1(byte *inbuf, uint32 insize, byte *outbuf, uint32 outsize);

	Common::File _file;

	VQAHeader _header;
	uint32 *_frameInfo;
	byte *_codeBook;
	byte *_partialCodeBook;
	bool _compressedCodeBook;
	int _partialCodeBookSize;
	int _numPartialCodeBooks;
	uint32 _numVectorPointers;
	uint16 *_vectorPointers;

	byte _palette[4 * 256];
	byte *_frame;

	Audio::AppendableAudioStream *_stream;
	Audio::SoundHandle *_sound;

	uint32 readTag();
};

} // end of namespace Kyra

#endif
