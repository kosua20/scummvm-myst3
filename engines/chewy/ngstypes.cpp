/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "chewy/ngstypes.h"

namespace Chewy {

bool NewPhead::load(Common::SeekableReadStream *src) {
	src->read(id, 4);
	type = src->readUint16LE();
	PoolAnz = src->readUint16LE();

	return true;
}

bool TmfInst::load(Common::SeekableReadStream *src) {
	finetune = src->readByte();
	insvol = src->readByte();
	repstart = src->readUint32LE();
	replen = src->readUint32LE();
	laenge = src->readUint32LE();

	return true;
}

bool TmfHeader::load(Common::SeekableReadStream *src) {
	src->read(id, 4);
	for (int i = 0; i < 31; ++i)
		instrument[i].load(src);

	lied_len = src->readByte();
	pattern_anz = src->readByte();
	src->read(sequenz, 128);
	src->skip(4 * 31);

	return true;
}

bool GedPoolHeader::load(Common::SeekableReadStream *src) {
	src->read(Id, 4);
	Anz = src->readUint16LE();

	return true;
}

bool GedChunkHeader::load(Common::SeekableReadStream *src) {
	Len = src->readUint32LE();
	X = src->readSint16LE();
	Y = src->readSint16LE();
	Ebenen = src->readSint16LE();

	return true;
}

bool FlicHead::load(Common::SeekableReadStream *src) {
	size = src->readUint32LE();
	type = src->readUint16LE();
	frames = src->readUint16LE();
	width = src->readUint16LE();
	height = src->readUint16LE();
	depth = src->readUint16LE();
	flags = src->readUint16LE();
	speed = src->readUint32LE();
	reserved1 = src->readUint16LE();
	created = src->readUint32LE();
	creator = src->readUint32LE();
	updated = src->readUint32LE();
	updater = src->readUint32LE();
	aspect_dx = src->readUint16LE();
	aspect_dy = src->readUint16LE();
	src->read(reserved2, 38);
	oframe1 = src->readUint32LE();
	oframe2 = src->readUint32LE();
	src->read(reserved3, 40);

	return true;
}

bool FrameHead::load(Common::SeekableReadStream *src) {
	size = src->readUint32LE();
	type = src->readUint16LE();
	chunks = src->readUint16LE();
	src->read(reserved, 8);

	return true;
}

bool ChunkHead::load(Common::SeekableReadStream *src) {
	size = src->readUint32LE();
	type = src->readUint16LE();

	return true;
}

bool CustomFlicHead::load(Common::SeekableReadStream *src) {
	src->read(id, 4);
	size = src->readUint32LE();
	frames = src->readUint16LE();
	width = src->readUint16LE();
	height = src->readUint16LE();
	speed = src->readUint32LE();
	oframe1 = src->readUint32LE();

	return true;
}

bool CustomFrameHead::load(Common::SeekableReadStream *src) {
	size = src->readUint32LE();
	type = src->readUint16LE();
	chunks = src->readUint16LE();

	return true;
}

} // namespace Chewy
