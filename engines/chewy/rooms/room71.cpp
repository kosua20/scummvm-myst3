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
#include "chewy/globals.h"
#include "chewy/room.h"
#include "chewy/rooms/room71.h"
#include "chewy/sound.h"

namespace Chewy {
namespace Rooms {

int Room71::_state;
int Room71::_delay;

void Room71::entry(int16 eib_nr) {
	g_engine->_sound->playSound(0, 0);
	g_engine->_sound->playSound(0, 1);
	g_engine->_sound->playSound(0);
	g_engine->_sound->playSound(0, 1, false);
	_G(spieler).ScrollxStep = 2;
	_G(spieler_mi)[P_HOWARD].Mode = true;
	_G(spieler_mi)[P_NICHELLE].Mode = true;
	_G(spieler).ZoomXy[P_HOWARD][0] = 8;
	_G(spieler).ZoomXy[P_HOWARD][1] = 16;
	_G(spieler).ZoomXy[P_NICHELLE][0] = 8;
	_G(spieler).ZoomXy[P_NICHELLE][1] = 16;
	_G(zoom_horizont) = 0;
	_state = 0;
	_delay = 0;
	_G(SetUpScreenFunc) = setup_func;
	_G(spieler).DiaAMov = 4;
	if (!_G(spieler).R71LeopardVined && !_G(spieler).flags28_4) {
		_G(timer_nr)[0] = _G(room)->set_timer(0, 10);
		_G(det)->set_static_ani(0, -1);
	} else if (_G(spieler).R71LeopardVined) {
		_G(det)->start_detail(2, 255, ANI_VOR);
		_G(det)->show_static_spr(8);
		_G(det)->hide_static_spr(2);
		_G(det)->hide_static_spr(3);
	} else if (_G(spieler).flags28_4) {
		_G(det)->show_static_spr(5);
		_G(det)->hide_static_spr(3);
	}

	if (_G(flags).LoadGame)
		return;

	switch (eib_nr) {
	case 110:
		set_person_pos(500, 67, P_CHEWY, P_LEFT);
		set_person_pos(568, 31, P_NICHELLE, P_LEFT);
		set_person_pos(538, 35, P_HOWARD, P_LEFT);
		break;
	case 114:
		set_person_pos(70, 48, P_CHEWY, P_RIGHT);
		set_person_pos(165, 16, P_NICHELLE, P_RIGHT);
		set_person_pos(120, 18, P_HOWARD, P_RIGHT);
		break;
	default:
		break;
	}
}

void Room71::xit(int16 eib_nr) {
	_G(spieler).ScrollxStep = 1;
	if (_G(spieler).PersonRoomNr[P_HOWARD] != 71)
		return;

	switch (eib_nr) {
	case 105:
		_G(spieler).PersonRoomNr[P_HOWARD] = 74;
		_G(spieler).PersonRoomNr[P_NICHELLE] = 74;
		break;
	case 106:
		_G(spieler).PersonRoomNr[P_HOWARD] = 73;
		_G(spieler).PersonRoomNr[P_NICHELLE] = 73;
	default:
		break;
	}
}

void Room71::setup_func() {
	calc_person_look();

	if (_state) {
		if (_delay)
			--_delay;
		else {
			_delay = (_G(spieler).DelaySpeed + 1) / 2;

			if (_state == 1) {
				_G(det)->set_static_pos(3, 244 + g_engine->_rnd.getRandomNumber(4), -1 * g_engine->_rnd.getRandomNumber(4), false, false);				
			} else {
				_G(det)->set_static_pos(5, 198 + g_engine->_rnd.getRandomNumber(3), -1 * g_engine->_rnd.getRandomNumber(3), false, false);
			}
		}

	} else {
		const int posX = _G(spieler_vector)[P_CHEWY].Xypos[0];

		int howDestX, howDestY, nicDestX, nicDestY;
		if (posX < 40) {
			howDestX = 82;
			howDestY = 18;
			nicDestX = 127;
			nicDestY = 19;
		} else if (posX < 190) {
			howDestX = 229;
			howDestY = 22;
			nicDestX = 268;
			nicDestY = 22;
		} else if (posX < 290) {
			howDestX = 329;
			howDestY = 26;
			nicDestX = 368;
			nicDestY = 29;
		} else if (posX < 420) {
			howDestX = 434;
			howDestY = 36;
			nicDestX = 477;
			nicDestY = 32;
		} else {
			howDestX = 538;
			howDestY = 35;
			nicDestX = 568;
			nicDestY = 31;
		}

		go_auto_xy(howDestX, howDestY, P_HOWARD, ANI_GO);
		go_auto_xy(nicDestX, nicDestY, P_NICHELLE, ANI_GO);
	}
}

int Room71::proc1() {
	if (_G(spieler).inv_cur) {
		_G(flags).NoScroll = false;
		return 0;
	}

	hide_cur();
	auto_move(2, P_CHEWY);
	_G(flags).NoScroll = true;
	auto_scroll(256, 0);
	_delay = 0;
	if (_G(menu_item) == CUR_HOWARD) {
		proc4();
		if (_G(spieler).flags28_4) {
			if (_G(spieler).R71Val2)
				proc2();
			else
				_G(spieler).R71Val1 = 1;
		}
	} else if (_G(menu_item) == CUR_NICHELLE) {
		proc3();
		if (_G(spieler).flags28_4) {
			if (_G(spieler).R71Val1)
				proc2();
			else
				_G(spieler).R71Val2 = 1;
		}
	} else {
		_G(spieler).PersonHide[P_CHEWY] = true;
		proc5(3);
		_G(spieler).PersonHide[P_CHEWY] = false;
	}

	if (!_G(spieler).R71LeopardVined)
		start_aad_wait(432, -1);

	show_cur();
	_G(flags).NoScroll = false;
	return 1;
}

void Room71::proc2() {
	start_aad_wait(432, -1);
	start_aad_wait(433, -1);
	_G(SetUpScreenFunc) = nullptr;
	go_auto_xy(518, 35, P_HOWARD, ANI_GO);
	go_auto_xy(568, 36, P_NICHELLE, ANI_WAIT);
	_G(SetUpScreenFunc) = setup_func;
	_G(flags).NoScroll = true;
	auto_scroll(284, 0);
	_G(spieler).PersonHide[P_CHEWY] = true;
	_G(spieler).PersonHide[P_NICHELLE] = true;
	_G(spieler).PersonHide[P_HOWARD] = true;
	proc5(5);
	_G(det)->hide_static_spr(2);
	_G(det)->start_detail(5, 255, false);
	auto_scroll(160, 0);
	_G(det)->hide_static_spr(5);
	start_detail_wait(1, 1, ANI_VOR);
	_G(det)->start_detail(2, 255, false);
	_G(det)->stop_detail(5);
	_G(det)->show_static_spr(8);
	_G(atds)->set_steuer_bit(442, ATS_AKTIV_BIT, ATS_DATEI);
	_G(atds)->set_steuer_bit(446, ATS_AKTIV_BIT, ATS_DATEI);
	_G(spieler).PersonHide[P_HOWARD] = false;
	_G(spieler).PersonHide[P_NICHELLE] = false;
	_G(spieler).PersonHide[P_CHEWY] = false;
	_G(spieler).R71LeopardVined = true;
	_G(flags).NoScroll = false;
	_G(menu_item) = CUR_WALK;
	cursor_wahl(CUR_WALK);
	start_aad_wait(434, -1);
}

void Room71::proc3() {
	start_aad_wait(431, -1);
	_G(SetUpScreenFunc) = nullptr;
	go_auto_xy(510, 34, P_NICHELLE, ANI_WAIT);
	_G(SetUpScreenFunc) = setup_func;
	_G(spieler).PersonHide[P_CHEWY] = true;
	_G(spieler).PersonHide[P_NICHELLE] = true;
	proc5(6);
	_G(spieler).PersonHide[P_NICHELLE] = false;
	_G(spieler).PersonHide[P_CHEWY] = false;
}

void Room71::proc4() {
	start_aad_wait(430, -1);
	_G(SetUpScreenFunc) = nullptr;
	go_auto_xy(518, 35, P_HOWARD, ANI_WAIT);
	_G(SetUpScreenFunc) = setup_func;
	_G(spieler).PersonHide[P_CHEWY] = true;
	_G(spieler).PersonHide[P_HOWARD] = true;
	proc5(4);
	_G(spieler).PersonHide[P_HOWARD] = false;
	_G(spieler).PersonHide[P_CHEWY] = false;
}

void Room71::proc5(int16 val) {
	_state = 1 + (_G(spieler).flags28_4 ? 1 : 0);
	_G(det)->hide_static_spr(2);
	start_detail_wait(val, 5, ANI_VOR);
	_G(det)->show_static_spr(2);
	_state = 0;
}

int Room71::proc6() {
	if (_G(spieler).inv_cur)
		return 0;

	hide_cur();
	auto_move(3, P_CHEWY);
	start_spz_wait(13, 1, false, P_CHEWY);
	_G(det)->hide_static_spr(3);
	_G(det)->show_static_spr(4);
	_G(spieler_mi)[P_CHEWY].Mode = true;
	go_auto_xy(244, 44, P_CHEWY, ANI_WAIT);
	start_spz_wait(14, 1, false, P_CHEWY);
	_G(det)->hide_static_spr(4);
	_G(det)->show_static_spr(5);
	_G(spieler).flags28_4 = true;
	_G(room)->set_timer_status(0, TIMER_STOP);
	_G(det)->del_static_ani(0);
	_G(atds)->set_steuer_bit(443, ATS_AKTIV_BIT, ATS_DATEI);
	auto_move(3, P_CHEWY);
	_G(spieler_mi)[P_CHEWY].Mode = false;
	
	show_cur();
	return 1;
}

void Room71::proc7() {
	hide_cur();
	auto_move(4, P_CHEWY);
	start_aad_wait(429, -1);
	_G(SetUpScreenFunc) = nullptr;
	set_person_spr(P_LEFT, P_CHEWY);
	go_auto_xy(323, 28, P_NICHELLE, ANI_WAIT);
	_G(flags).NoScroll = true;
	auto_scroll(200, 0);
	_G(spieler).PersonHide[P_NICHELLE] = true;
	_G(det)->start_detail(7, 255, false);
	start_aad_wait(624, -1);
	_G(det)->stop_detail(7);
	_G(spieler).PersonHide[P_NICHELLE] = false;
	_G(SetUpScreenFunc) = setup_func;
	_G(flags).NoScroll = false;
	start_aad_wait(432, -1);

	show_cur();
}

} // namespace Rooms
} // namespace Chewy
