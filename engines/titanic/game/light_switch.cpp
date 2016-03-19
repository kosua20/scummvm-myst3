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

#include "titanic/game/light_switch.h"

namespace Titanic {

int CLightSwitch::_v1;

CLightSwitch::CLightSwitch() : CBackground(), 
		_fieldE0(0), _fieldE4(0), _fieldE8(0) {
}

void CLightSwitch::save(SimpleFile *file, int indent) const {
	file->writeNumberLine(1, indent);
	file->writeNumberLine(_fieldE0, indent);
	file->writeNumberLine(_fieldE4, indent);
	file->writeNumberLine(_v1, indent);
	file->writeNumberLine(_fieldE8, indent);

	CBackground::save(file, indent);
}

void CLightSwitch::load(SimpleFile *file) {
	file->readNumber();
	_fieldE0 = file->readNumber();
	_fieldE4 = file->readNumber();
	_v1 = file->readNumber();
	_fieldE8 = file->readNumber();

	CBackground::load(file);
}

bool CLightSwitch::handleEvent(CEnterRoomMsg &msg) {
	warning("CLightSwitch::handleEvent");
	return true;
}

} // End of namespace Titanic
