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

#include "chewy/defines.h"
#include "chewy/events.h"
#include "chewy/file.h"
#include "chewy/globals.h"
#include "chewy/resource.h"

namespace Chewy {

static const byte IO_PAL1[7] = { 11, 60, 14, 2, 1, 5, 4 };

Common::File *File::open(const char *name) {
	Common::File *f = new Common::File();
	if (f->open(name)) {
		return f;
	} else {
		delete f;
		return nullptr;
	}
}

bool File::readArray(Common::SeekableReadStream *src, uint16 *arr, size_t size) {
	Common::SeekableReadStream *rs = src->readStream(size * 2);

	bool result = (uint32)rs->size() == (size * 2);
	if (result) {
		for (; size > 0; --size, ++arr)
			*arr = rs->readUint16LE();
	}

	delete rs;
	return result;
}

} // namespace Chewy
