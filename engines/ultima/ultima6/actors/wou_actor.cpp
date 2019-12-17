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

#include "WOUActor.h"

namespace Ultima {
namespace Ultima6 {

bool WOUActor::can_carry_object(Obj *obj) {
	if (inventory_count_objects(INV_EXCLUDE_READIED_OBJECTS) >= 16) {
		return false;
	}

	return Actor::can_carry_object(obj);
}

bool WOUActor::can_carry_object(uint16 obj_n, uint32 qty) {
	if (inventory_count_objects(INV_EXCLUDE_READIED_OBJECTS) >= 16) {
		return false;
	}

	return Actor::can_carry_object(obj_n, qty);
}

} // End of namespace Ultima6
} // End of namespace Ultima
