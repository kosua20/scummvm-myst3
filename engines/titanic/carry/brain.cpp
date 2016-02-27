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
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#include "titanic/carry/brain.h"

namespace Titanic {

CBrain::CBrain() : CCarry(), _field12C(0),
		_field130(0), _field134(0), _field138(0) {
}

void CBrain::save(SimpleFile *file, int indent) const {
	file->writeNumberLine(1, indent);
	file->writeNumberLine(_field12C, indent);
	file->writeNumberLine(_field134, indent);
	file->writeNumberLine(_field138, indent);

	CCarry::save(file, indent);
}

void CBrain::load(SimpleFile *file) {
	file->readNumber();
	_field12C = file->readNumber();
	_field134 = file->readNumber();
	_field138 = file->readNumber();

	CCarry::load(file);
}

} // End of namespace Titanic
