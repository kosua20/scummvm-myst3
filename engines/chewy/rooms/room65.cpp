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
#include "chewy/global.h"
#include "chewy/ani_dat.h"
#include "chewy/room.h"
#include "chewy/rooms/room65.h"

namespace Chewy {
namespace Rooms {

int16 Room65::_scrollX;
int16 Room65::_scrollY[2];

void Room65::entry() {
	hide_person();
	_G(r65tmp_scrollx) = _G(spieler).scrollx;
	_G(r65tmp_scrolly) = _G(spieler).scrolly;
	_G(spieler).scrollx = 0;
	_G(spieler).scrolly = 0;
	_G(r65tmp_ch_x) = spieler_vector[P_CHEWY].Xypos[0];;
	_G(r65tmp_ch_y) = spieler_vector[P_CHEWY].Xypos[1];;
	_G(r65tmp_ho_x) = spieler_vector[P_HOWARD].Xypos[0];;
	_G(r65tmp_ho_y) = spieler_vector[P_HOWARD].Xypos[1];;
	spieler_vector[P_CHEWY].Xypos[0] = 10;
	spieler_vector[P_CHEWY].Xypos[1] = 80;
	spieler_vector[P_HOWARD].Xypos[0] = 150;
	spieler_vector[P_HOWARD].Xypos[1] = 10;
	if (_G(spieler).PersonDia[P_HOWARD] < 10000) {
		_G(cur_hide_flag) = false;
		hide_cur();
		start_aad_wait(_G(spieler).PersonDia[P_HOWARD], -1);
		show_cur();
	} else {
		start_ads_wait(_G(spieler).PersonDia[P_HOWARD] - 10000);
	}
	flags.LoadGame = true;
	show_person();
	switch_room(_G(spieler).PersonDiaTmpRoom[P_HOWARD]);
}

void Room65::xit() {
	_G(spieler).scrollx = _G(r65tmp_scrollx);
	_G(spieler).scrolly = _G(r65tmp_scrolly);
	set_person_pos(_G(r65tmp_ch_x), _G(r65tmp_ch_y), P_CHEWY, -1);
	set_person_pos(_G(r65tmp_ho_x), _G(r65tmp_ho_y), P_HOWARD, -1);
	room_blk.AadLoad = true;
	room_blk.AtsLoad = true;
	_G(maus_links_click) = false;
	set_person_rnr();
}

void Room65::atds_string_start(int16 dia_nr, int16 str_nr,
	int16 person_nr, int16 mode) {
	int16 ani_nr;
	if (!_G(spieler).PersonDiaRoom[person_nr]) {
		switch (person_nr) {
		case 0:
			if (mode == AAD_STR_START) {
				switch (_G(spieler).ChewyAni) {
				case CHEWY_NORMAL:
					ani_nr = CH_TALK3;
					break;

				case CHEWY_PUMPKIN:
					ani_nr = CH_PUMP_TALK;
					break;

				case CHEWY_ROCKER:
					ani_nr = CH_ROCK_TALK1;
					break;

				case CHEWY_JMANS:
					ani_nr = CH_JM_TALK;
					break;

				default:
					ani_nr = -1;
					break;

				}
				if (ani_nr != -1)
					start_spz(ani_nr, 255, ANI_VOR, P_CHEWY);
			} else {
				stop_spz();
			}
			break;

		case 1:
			if (mode == AAD_STR_START) {
				start_spz(HO_TALK_L, 255, ANI_VOR, P_HOWARD);
			} else {
				stop_spz();
			}
			break;

		case 3:
			if (mode == AAD_STR_START) {
				start_spz(NI_TALK_L, 255, ANI_VOR, P_NICHELLE);
			} else {
				stop_spz();
			}
			break;

		}
	} else if (mode == AAD_STR_START) {
		det->start_detail(person_nr, 255, ANI_VOR);
	} else {
		det->stop_detail(person_nr);
	}
}

} // namespace Rooms
} // namespace Chewy
