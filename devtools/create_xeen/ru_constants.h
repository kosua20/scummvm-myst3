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

#pragma once

#include "constants.h"

class RU : public LangConstants {
public:
	const char *CLOUDS_CREDITS() {
		return "\v012\t000\x3"																								 // "\v012\t000\x3"  
			   "c\f35\x88\xA4\xA5\xEF \xA8 \xE0\xE3\xAA\xAE\xA2\xAE\xA4\xE1\xE2\xA2\xAE \xAF\xE0\xAE\xA5\xAA\xE2\xAE\xAC:\n" // "c\f35Идея и руководство проектом:\n"
			   "\f17\x84\xA6\xAE\xAD \x82\xA0\xAD \x8A\xA0\xAD\xA5\xA3\xA5\xAC\x3"                                           // "\f17Джон Ван Канегем\x3"
			   "l\n"                                                                                                         // "l\n"
			   "\n"                                                                                                          // "\n"
			   "\t025\f35\x8F\xE0\xAE\xA3\xE0\xA0\xAC\xAC\xA8\xE1\xE2\xEB:\n"                                                // "\t025\f35Программисты:\n"
			   "\t035\f17\x8C\xA0\xE0\xAA \x8A\xAE\xAB\xA4\xE3\xED\xAB\xAB\n"                                                // "\t035\f17Марк Колдуэлл\n"
			   "\t035\x84\xA5\xA9\xA2 \x95\xED\xE2\xED\xE3\xED\xA9\n"                                                        // "\t035Дейв Хэтэуэй\n"
			   "\n"                                                                                                          // "\n"
			   "\t025\f35\x80\xE3\xA4\xA8\xAE\xE1\xA8\xE1\xE2\xA5\xAC\xA0 \xA8 \xA7\xA2\xE3\xAA:\n"                          // "\t025\f35Аудиосистема и звук:\n"
			   "\t035\f17\x92\xAE\xA4\xA4 \x95\xA5\xAD\xA4\xE0\xA8\xAA\xE1\n"                                                // "\t035\f17Тодд Хендрикс\n"
			   "\n"                                                                                                          // "\n"
			   "\t025\f35\x8C\xE3\xA7\xEB\xAA\xA0 \xA8 \xE0\xA5\xE7\xEC:\n"                                                  // "\t025\f35Музыка и речь:\n"
			   "\t035\f17\x92\xA8\xAC \x92\xA0\xAB\xAB\xA8\n"                                                                // "\t035\f17Тим Талли\n"
			   "\n"                                                                                                          // "\n"
			   "\t025\f35\x91\xE6\xA5\xAD\xA0\xE0\xA8\xA9:\n"                                                                // "\t025\f35Сценарий:\n"
			   "\t035\f17\x8F\xAE\xAB \x90\xA0\xE2\xAD\xA5\xE0\n"                                                            // "\t035\f17Пол Ратнер\n"
			   "\t035\x84\xA5\xA1\xA1\xA8 \x8C\xF1\xE0\xE4\xA8\n"                                                            // "\t035Дебби Мёрфи\n"
			   "\t035\x84\xA6\xAE\xAD \x82\xA0\xAD \x8A\xA0\xAD\xA5\xA3\xA5\xAC\v012\n"                                      // "\t035Джон Ван Канегем\v012\n"
			   "\n"                                                                                                          // "\n"
			   "\n"                                                                                                          // "\n"
			   "\t180\f35\x95\xE3\xA4\xAE\xA6\xAD\xA8\xAA\xA8:\n"                                                            // "\t180\f35Художники:\n"
			   "\t190\f17\x8B\xE3\xA8 \x84\xA6\xAE\xAD\xE1\xAE\xAD\n"                                                        // "\t190\f17Луи Джонсон\n"
			   "\t190\x84\xA6\xAE\xAD\xA0\xE2\xA0\xAD \x8F. \x83\xA2\xA8\xAD\n"                                              // "\t190Джонатан П. Гвин\n"
			   "\t190\x81\xAE\xAD\xA8\xE2\xA0 \x8B\xAE\xAD\xA3-\x95\xA5\xAC\xE1\xA0\xE2\n"                                   // "\t190Бонита Лонг-Хемсат\n"
			   "\t190\x84\xA6\xE3\xAB\xA8\xEF \x93\xAB\xA0\xAD\xAE\n"                                                        // "\t190Джулия Улано\n"
			   "\t190\x90\xA8\xAA\xA0\xE0\xA4\xAE \x81\xA0\xE0\xE0\xA5\xE0\xA0\n"                                            // "\t190Рикардо Баррера\n"
			   "\n"                                                                                                          // "\n"
			   "\t180\f35\x92\xA5\xE1\xE2\xA5\xE0\xEB:\n"                                                                    // "\t180\f35Тестеры:\n"
			   "\t190\f17\x81\xA5\xAD\xA4\xA6\xA0\xAC\xA8\xAD \x81\xA5\xAD\xE2\n"                                            // "\t190\f17Бенджамин Бент\n"
			   "\t190\x8C\xA0\xE0\xA8\xAE \x9D\xE1\xAA\xA0\xAC\xA8\xAB\xAB\xA0\n"                                            // "\t190Марио Эскамилла\n"
			   "\t190\x90\xA8\xE7\xA0\xE0\xA4 \x9D\xE1\xAF\xA8\n"                                                            // "\t190Ричард Эспи\n"
			   "\t190\x91\xAA\xAE\xE2\xE2 \x8C\xA0\xAA\xA4\xED\xAD\xA8\xA5\xAB\n"                                            // "\t190Скотт Макдэниел\n"
			   "\t190\x8A\xAB\xA5\xA9\xE2\xAE\xAD \x90\xA5\xE2\xA7\xA5\xE0\n"                                                // "\t190Клейтон Ретзер\n"
			   "\t190\x8C\xA0\xA9\xAA\xAB \x91\xE3\xA0\xE0\xA5\xE1\x3"                                                       // "\t190Майкл Суарес\x3"
			   "c";                                                                                                          // "c"
	}

	const char *DARK_SIDE_CREDITS() {
		return "\v012\t000\x3"
			   "c\f35Designed and Directed By:\n"
			   "\f17Jon Van Caneghem\x3l\n"
			   "\n"
			   "\t025\f35Programming:\n"
			   "\t035\f17Mark Caldwell\n"
			   "\t035Dave Hathaway\n"
			   "\n"
			   "\t025\f35Sound System & FX:\n"
			   "\t035\f17Mike Heilemann\n"
			   "\n"
			   "\t025\f35Music & Speech:\n"
			   "\t035\f17Tim Tully\n"
			   "\n"
			   "\t025\f35Writing:\n"
			   "\t035\f17Paul Rattner\n"
			   "\t035Debbie Van Caneghem\n"
			   "\t035Jon Van Caneghem\v012\n"
			   "\n"
			   "\n"
			   "\t180\f35Graphics:\n"
			   "\t190\f17Jonathan P. Gwyn\n"
			   "\t190Bonita Long-Hemsath\n"
			   "\t190Julia Ulano\n"
			   "\t190Ricardo Barrera\n"
			   "\n"
			   "\t180\f35Testing:\n"
			   "\t190\f17Benjamin Bent\n"
			   "\t190Christian Dailey\n"
			   "\t190Mario Escamilla\n"
			   "\t190Marco Hunter\n"
			   "\t190Robert J. Lupo\n"
			   "\t190Clayton Retzer\n"
			   "\t190David Vela\x3"
			   "c";
	}

	const char *SWORDS_CREDITS1() {
		return "\v012\x3"
			   "c\f35Published By New World Computing, Inc.\f17\n"
			   "Developed By CATware, Inc.\x3l\n"
			   "\f01Design and Direction\t180Series Created by\n"
			   "\t020Bill Fawcett\t190John Van Caneghem\n"
			   "\n"
			   "\t010Story Contributions\t180Producer & Manual\n"
			   "\t020Ellen Guon\t190Dean Rettig\n"
			   "\n"
			   "\t010Programming & Ideas\t180Original Programming\n"
			   "\t020David Potter\t190Mark Caldwell\n"
			   "\t020Rod Retterath\t190Dave Hathaway\n"
			   "\n"
			   "\t010Manual Illustrations\t180Graphic Artists\n"
			   "\t020Todd Cameron Hamilton\t190Jonathan P. Gwyn\n"
			   "\t020James Clouse\t190Bonnie Long-Hemsath\n"
			   "\t190Julia Ulano\n"
			   "\t190Ricardo Barrera\n";
	}

	const char *SWORDS_CREDITS2() {
		return "\f05\v012\t000\x3l\n"
			   "\t100Sound Programming\n"
			   "\t110Todd Hendrix\n"
			   "\n"
			   "\t100Music\n"
			   "\t110Tim Tully\n"
			   "\t110Quality Assurance Manager\n"
			   "\t110Peter Ryu\n"
			   "\t100Testers\n"
			   "\t110Walter Johnson\n"
			   "\t110Bryan Farina\n"
			   "\t110David Baton\n"
			   "\t110Jack Nalls\n";
	}

	const char *OPTIONS_MENU() {
		return "\r\x1\x3"									  // "\r\x1\x3"
			   "c\fd\x8C\xA5\xE7 \xA8 \x8C\xA0\xA3\xA8\xEF\n" // "c\fdМеч и Магия\n"
			   "%s \x8A\xE1\xA8\xAD\xA0\x2\n"                 // "%s Ксина\x2\n"
			   "\v%.3dCopyright (c) %d NWC, Inc.\n"           // "\v%.3dCopyright (c) %d NWC, Inc.\n"
			   "All Rights Reserved\x1";                      // "All Rights Reserved\x1"
	}

	const char **GAME_NAMES() {
		delete[] _gameNames;
		_gameNames = new const char *[3] { "\x8E\xA1\xAB\xA0\xAA\xA0", "Darkside", "World" }; // "Облака", "Darkside", "World"
		return _gameNames;
	}

	const char *THE_PARTY_NEEDS_REST() {
		return "\v012\x8E\xE2\xE0\xEF\xA4 \xAD\xE3\xA6\xA4\xA0\xA5\xE2\xE1\xEF \xA2 \xAE\xE2\xA4\xEB\xE5\xA5!"; // "\v012Отряд нуждается в отдыхе!"
	}

	const char *WHO_WILL() {
		return "\x3"
			   "c\v000\t000%s\n\n%s?\n\v055F1 - F%d";
	}

	const char *HOW_MUCH() {
		return "\x3""c\x91\xAA\xAE\xAB\xEC\xAA\xAE\n\n"; // "\x3""cСколько\n\n"
	}

	const char *WHATS_THE_PASSWORD() {
		return "\x3"
			   "cWhat's the Password?\n"
			   "\n"
			   "Please turn to page %u, go to\n"
			   "line %u, and type in word %u.\v067\t000Spaces are not counted as words or lines.  "
			   "Hyphenated words are treated as one word.  Any line that has any text is considered a line."
			   "\x3"
			   "c\v040\t000\n";
	}

	const char *PASSWORD_INCORRECT() {
		return "\x3"
			   "c\v040\n"
			   "\f32Incorrect!\fd";
	}

	const char *IN_NO_CONDITION() {
		return "\v007%s \xAD\xA5 \xA2 \xE1\xAE\xE1\xE2\xAE\xEF\xAD\xA8\xA8 \xE7\xE2\xAE-\xAB\xA8\xA1\xAE \xE1\xA4\xA5\xAB\xA0\xE2\xEC!"; // "\v007%s не в состоянии что-либо сделать!"
	}

	const char *NOTHING_HERE() {
		return "\x3""c\v010\x87\xA4\xA5\xE1\xEC \xAD\xA8\xE7\xA5\xA3\xAE \xAD\xA5\xE2."; // "\x3""c\v010Здесь ничего нет."
	}

	const char **WHO_ACTIONS() {
		delete[] _whoActions;
		_whoActions = new const char *[32] {
			"\x8A\xE2\xAE \xAE\xA1\xEB\xE9\xA5\xE2",                              // "Кто обыщет",
			"\x8A\xE2\xAE \xAE\xE2\xAA\xE0\xAE\xA5\xE2",						  // "Кто откроет",
			"\x8A\xE2\xAE \xA2\xEB\xAF\xEC\xA5\xE2",							  // "Кто выпьет",
			"\x8A\xE2\xAE \xA1\xE3\xA4\xA5\xE2 \xAA\xAE\xAF\xA0\xE2\xEC",		  // "Кто будет копать",
			"\x8A\xE2\xAE \xAF\xAE\xE2\xE0\xAE\xA3\xA0\xA5\xE2",				  // "Кто потрогает",
			"\x8A\xE2\xAE \xAF\xE0\xAE\xE7\xE2\xF1\xE2",						  // "Кто прочтёт",
			"\x8A\xAE\xA3\xAE \xAD\xA0\xE3\xE7\xA8\xE2\xEC",					  // "Кого научить",
			"\x8A\xE2\xAE \xA2\xAE\xA7\xEC\xAC\xF1\xE2",						  // "Кто возьмёт",
			"\x8A\xE2\xAE \xE3\xA4\xA0\xE0\xA8\xE2",							  // "Кто ударит",
			"\x8A\xE2\xAE \xE3\xAA\xE0\xA0\xA4\xF1\xE2",						  // "Кто украдёт",
			"\x8A\xE2\xAE \xA4\xA0\xE1\xE2 \xA2\xA7\xEF\xE2\xAA\xE3",			  // "Кто даст взятку",
			"\x8A\xE2\xAE \xA7\xA0\xAF\xAB\xA0\xE2\xA8\xE2",					  // "Кто заплатит",
			"\x8A\xE2\xAE \xAF\xE0\xA8\xE1\xEF\xA4\xA5\xE2",					  // "Кто присядет",
			"\x8A\xE2\xAE \xAF\xAE\xAF\xE0\xAE\xA1\xE3\xA5\xE2",				  // "Кто попробует",
			"\x8A\xE2\xAE \xA5\xA3\xAE \xAF\xAE\xA2\xA5\xE0\xAD\xF1\xE2",		  // "Кто его повернёт",
			"\x8A\xE2\xAE \xA8\xE1\xAA\xE3\xAF\xAD\xF1\xE2\xE1\xEF",			  // "Кто искупнётся",
			"\x8A\xE2\xAE \xA5\xA3\xAE \xE3\xAD\xA8\xE7\xE2\xAE\xA6\xA8\xE2",	  // "Кто его уничтожит",
			"\x8A\xE2\xAE \xA2\xEB\xA4\xA5\xE0\xAD\xA5\xE2",					  // "Кто выдернет",
			"\x8A\xE2\xAE \xE1\xAF\xE3\xE1\xE2\xA8\xE2\xE1\xEF",				  // "Кто спустится",
			"\x8A\xE2\xAE \xA1\xE0\xAE\xE1\xA8\xE2 \xAC\xAE\xAD\xA5\xE2\xAA\xE3", // "Кто бросит монетку",
			"pray",																  // "pray",
			"\x8A\xE2\xAE \xE1\xE2\xA0\xAD\xA5\xE2 \xE7\xAB\xA5\xAD\xAE\xAC",	  // "Кто станет членом",
			"act",																  // "act",
			"\x8A\xE2\xAE \xE5\xAE\xE7\xA5\xE2 \xE1\xEB\xA3\xE0\xA0\xE2\xEC",	  // "Кто хочет сыграть",
			"\x8A\xE2\xAE \xAD\xA0\xA6\xAC\xF1\xE2",							  // "Кто нажмёт",
			"rub",																  // "rub",
			"pick",																  // "pick",
			"eat",																  // "eat",
			"sign",																  // "sign",
			"close",															  // "close",
			"look",																  // "look",
			"try"																  // "try"
		};
		return _whoActions;
	}

	const char **WHO_WILL_ACTIONS() {
		delete[] _whoWillActions;
		_whoWillActions = new const char *[4] {
			"\x8E\xE2\xAA\xE0\xEB\xE2\xEC \xE0\xA5\xE8\xF1\xE2\xAA\xE3",			// "Открыть решётку",
			"\x8E\xE2\xAA\xE0\xEB\xE2\xEC \xA4\xA2\xA5\xE0\xEC",                    // "Открыть дверь",
			"\x90\xA0\xE1\xAA\xE0\xEB\xE2\xEC \xE1\xA2\xA8\xE2\xAE\xAA",            // "Раскрыть свиток",
			"\x82\xEB\xA1\xA5\xE0\xA8\xE2\xA5 \xAF\xA5\xE0\xE1\xAE\xAD\xA0\xA6\xA0" // "Выберите персонажа"
		};
		return _whoWillActions;
	}

	const char **DIRECTION_TEXT_UPPER() {
		delete[] _directionTextUpper;
		_directionTextUpper = new const char *[4] { "NORTH", "EAST", "SOUTH", "WEST" };
		return _directionTextUpper;
	}

	const char **DIRECTION_TEXT() {
		delete[] _directionText;
		_directionText = new const char *[4] {
			"\x91\xA5\xA2\xA5\xE0",		// "Север",
			"\x82\xAE\xE1\xE2\xAE\xAA", // "Восток",
			"\x9E\xA3",                 // "Юг",
			"\x87\xA0\xAF\xA0\xA4"      // "Запад"
		};
		return _directionText;
	}

	const char **RACE_NAMES() {
		delete[] _raceNames;
		_raceNames = new const char *[5] {
			"\x97\xA5\xAB\xAE\xA2\xA5\xAA", // "Человек",
			"\x9D\xAB\xEC\xE4",				// "Эльф",
			"\x84\xA2\xAE\xE0\xE4",			// "Дворф",
			"\x83\xAD\xAE\xAC",				// "Гном",
			"\x8F\xAE\xAB\xE3\xAE\xE0\xAA"	// "Полуорк"
		};
		return _raceNames;
	}

	const char **ALIGNMENT_NAMES() {
		delete[] _alignmentNames;
		_alignmentNames = new const char *[3] {
			"\x95\xAE\xE0\xAE\xE8\xA8\xA9", // "Хороший",
			"\x8D\xA5\xA9\xE2\xE0\xA0\xAB",	// "Нейтрал",
			"\x87\xAB\xAE\xA9(-\xA0\xEF)"	// "Злой(-ая)"
		};
		return _alignmentNames;
	}

	const char **SEX_NAMES() {
		delete[] _sexNames;
		_sexNames = new const char *[2] {
			"\x8C\xE3\xA6\xE7\xA8\xAD\xA0", // "Мужчина",
			"\x86\xA5\xAD\xE9\xA8\xAD\xA0"  // "Женщина"
		};
		return _sexNames;
	}

	const char **SKILL_NAMES() {
		delete[] _skillNames;
		_skillNames = new const char *[18] {
			"\x82\xAE\xE0\xAE\xA2\xE1\xE2\xA2\xAE\t100",								// "Воровство\t100",
			"\x8E\xE0\xE3\xA6\xA5\xA9\xAD\xA8\xAA",                                      // "Оружейник",
			"\x80\xE1\xE2\xE0\xAE\xAB\xAE\xA3",                                          // "Астролог",
			"\x80\xE2\xAB\xA5\xE2",                                                      // "Атлет",
			"\x8A\xA0\xE0\xE2\xAE\xA3\xE0\xA0\xE4",                                      // "Картограф",
			"\x8A\xE0\xA5\xE1\xE2\xAE\xAD\xAE\xE1\xA5\xE6",                              // "Крестоносец",
			"\x97\xE3\xA2\xE1\xE2\xA2\xAE \xAD\xA0\xAF\xE0\xA0\xA2\xAB\xA5\xAD\xA8\xEF", // "Чувство направления",
			"\x9F\xA7\xEB\xAA\xAE\xA2\xA5\xA4",                                          // "Языковед",
			"\x8A\xE3\xAF\xA5\xE6",                                                      // "Купец",
			"\x91\xAA\xA0\xAB\xAE\xAB\xA0\xA7",                                          // "Скалолаз",
			"\x98\xE2\xE3\xE0\xAC\xA0\xAD",                                              // "Штурман",
			"\x91\xAB\xA5\xA4\xAE\xAF\xEB\xE2",                                          // "Следопыт",
			"\x8C\xA0\xA3\xA8\xE1\xE2\xE0 \xAC\xAE\xAB\xA8\xE2\xA2\xEB",                 // "Магистр молитвы",
			"\x8B\xAE\xA2\xAA\xAE\xE1\xE2\xEC \xAF\xA0\xAB\xEC\xE6\xA5\xA2",             // "Ловкость пальцев",
			"\x8F\xAB\xAE\xA2\xA5\xE6",                                                  // "Пловец",
			"\x8E\xE5\xAE\xE2\xAD\xA8\xAA",                                              // "Охотник",
			"\x82\xAE\xE1\xAF\xE0\xA8\xEF\xE2\xA8\xA5",                                  // "Восприятие",
			"\x97\xE3\xA2\xE1\xE2\xA2\xAE \xAE\xAF\xA0\xE1\xAD\xAE\xE1\xE2\xA8"          // "Чувство опасности"
		};
		return _skillNames;
	}

	const char **CLASS_NAMES() {
		delete[] _classNames;
		_classNames = new const char *[11] {
			"\x90\xEB\xE6\xA0\xE0\xEC",			// "Рыцарь",
			"\x8F\xA0\xAB\xA0\xA4\xA8\xAD",     // "Паладин",
			"\x8B\xE3\xE7\xAD\xA8\xAA",         // "Лучник",
			"\x8A\xAB\xA8\xE0\xA8\xAA",         // "Клирик",
			"\x8C\xA0\xA3",                     // "Маг",
			"\x82\xAE\xE0",                     // "Вор",
			"\x8D\xA8\xAD\xA4\xA7\xEF",         // "Ниндзя",
			"\x82\xA0\xE0\xA2\xA0\xE0",         // "Варвар",
			"\x84\xE0\xE3\xA8\xA4",             // "Друид",
			"\x91\xAB\xA5\xA4\xAE\xAF\xEB\xE2", // "Следопыт",
			nullptr                             // nullptr
		};
		return _classNames;
	}

	const char **CONDITION_NAMES_M() {
		delete[] _conditionNamesM;
		_conditionNamesM = new const char *[17] {
			"\x8F\xE0\xAE\xAA\xAB\xEF\xE2\xA8\xA5",		// "Проклятие",
			"Heart Broken",                             // "Heart Broken",
			"\x91\xAB\xA0\xA1\xAE\xE1\xE2\xEC",         // "Слабость",
			"\x8E\xE2\xE0\xA0\xA2\xAB\xA5\xAD\xA8\xA5", // "Отравление",
			"\x81\xAE\xAB\xA5\xA7\xAD\xEC",             // "Болезнь",
			"\x81\xA5\xA7\xE3\xAC\xA8\xA5",             // "Безумие",
			"\x82\xAB\xEE\xA1\xAB\xF1\xAD",             // "Влюблён",
			"\x8D\xA0\xA2\xA5\xE1\xA5\xAB\xA5",         // "Навеселе",
			"\x91\xAE\xAD",                             // "Сон",
			"\x82 \xE3\xAD\xEB\xAD\xA8\xA8",            // "В унынии",
			"\x82 \xE1\xAC\xEF\xE2\xA5\xAD\xA8\xA8",    // "В смятении",
			"\x8F\xA0\xE0\xA0\xAB\xA8\xE7",             // "Паралич",
			"\x81.\xE1\xAE\xA7\xAD\xA0\xAD\xA8\xEF",    // "Б.сознания",
			"\x8C\xA5\xE0\xE2\xA2",                     // "Мертв",
			"\x8A\xA0\xAC\xA5\xAD\xEC",                 // "Камень",
			"\x93\xAD\xA8\xE7\xE2\xAE\xA6\xA5\xAD",     // "Уничтожен",
			"\x95\xAE\xE0\xAE\xE8\xA5\xA5"              // "Хорошее"
		};
		return _conditionNamesM;
	}

	const char **CONDITION_NAMES_F() {
		delete[] _conditionNamesF;
		_conditionNamesF = new const char *[17] {
			"\x8F\xE0\xAE\xAA\xAB\xEF\xE2\xA8\xA5",         // "Проклятие",
				"Heart Broken",                             // "Heart Broken",
				"\x91\xAB\xA0\xA1\xAE\xE1\xE2\xEC",         // "Слабость",
				"\x8E\xE2\xE0\xA0\xA2\xAB\xA5\xAD\xA8\xA5", // "Отравление",
				"\x81\xAE\xAB\xA5\xA7\xAD\xEC",             // "Болезнь",
				"\x81\xA5\xA7\xE3\xAC\xA8\xA5",             // "Безумие",
				"\x82\xAB\xEE\xA1\xAB\xF1\xAD\xA0",         // "Влюблёна",
				"\x8D\xA0\xA2\xA5\xE1\xA5\xAB\xA5",         // "Навеселе",
				"\x91\xAE\xAD",                             // "Сон",
				"\x82 \xE3\xAD\xEB\xAD\xA8\xA8",            // "В унынии",
				"\x82 \xE1\xAC\xEF\xE2\xA5\xAD\xA8\xA8",    // "В смятении",
				"\x8F\xA0\xE0\xA0\xAB\xA8\xE7",             // "Паралич",
				"\x81.\xE1\xAE\xA7\xAD\xA0\xAD\xA8\xEF",    // "Б.сознания",
				"\x8C\xA5\xE0\xE2\xA2\xA0",                 // "Мертва",
				"\x8A\xA0\xAC\xA5\xAD\xEC",                 // "Камень",
				"\x93\xAD\xA8\xE7\xE2\xAE\xA6\xA5\xAD\xA0", // "Уничтожена",
				"\x95\xAE\xE0\xAE\xE8\xA5\xA5"              // "Хорошее"
		};
		return _conditionNamesF;
	}

	const char *GOOD() {
		return "\x95\xAE\xE0\xAE\xE8\xA5\xA5"; // "Хорошее"
	}

	const char *BLESSED() {
		return "\n\t014\x81\xAB\xA0\xA3\xAE\xE1\xAB\xAE\xA2\xA5\xAD\xA8\xA5\t095%+d"; // "\n\t014Благословение\t095%+d"
	}

	const char *POWER_SHIELD() {
		return "\n\t014\x91\xA8\xAB\xAE\xA2\xAE\xA9 \xE9\xA8\xE2\t095%+d"; // "\n\t014Силовой щит\t095%+d";
	}

	const char *HOLY_BONUS() {
		return "\n\t014\x91\xA2\xEF\xE2\xAE\xA9 \xA4\xA0\xE0\t095%+d"; // "\n\t014Святой дар\t095%+d"
	}

	const char *HEROISM() {
		return "\n\t014\x8C\xE3\xA6\xA5\xE1\xE2\xA2\xAE\t095%+d"; // "\n\t014Мужество\t095%+d"
	}

	const char *IN_PARTY() {
		return "\f15\x82 \xAE\xE2\xE0\xEF\xA4\xA5\fd"; // "\f15В отряде\fd"
	}

	const char *PARTY_DETAILS() {
		return "\015\003l\002\014"
			   "00"
			   "\013"
			   "001"
			   "\011"
			   "035%s"
			   "\013"
			   "009"
			   "\011"
			   "035%s"
			   "\013"
			   "017"
			   "\011"
			   "035%s"
			   "\013"
			   "025"
			   "\011"
			   "035%s"
			   "\013"
			   "001"
			   "\011"
			   "136%s"
			   "\013"
			   "009"
			   "\011"
			   "136%s"
			   "\013"
			   "017"
			   "\011"
			   "136%s"
			   "\013"
			   "025"
			   "\011"
			   "136%s"
			   "\013"
			   "044"
			   "\011"
			   "035%s"
			   "\013"
			   "052"
			   "\011"
			   "035%s"
			   "\013"
			   "060"
			   "\011"
			   "035%s"
			   "\013"
			   "068"
			   "\011"
			   "035%s"
			   "\013"
			   "044"
			   "\011"
			   "136%s"
			   "\013"
			   "052"
			   "\011"
			   "136%s"
			   "\013"
			   "060"
			   "\011"
			   "136%s"
			   "\013"
			   "068"
			   "\011"
			   "136%s";
	}

	const char *PARTY_DIALOG_TEXT() {
		return "%s\x2\x3""c\v106\t013\x82\xA2\xA5\xE0\xE5\t048\x82\xAD\xA8\xA7\t083\f37\x93\fd\xA4\xA0\xAB\t118\f37\x82\fd\xEB\xA3\xAD" // "%s\x2\x3""c\v106\t013Вверх\t048Вниз\t083\f37У\fdдал\t118\f37В\fdыгн"
			   "\t153\f37\x91\fd\xAE\xA7\xA4\t188\x82\f37\xEB\fd\xE5\xAE\xA4\x1";                                                       // "\t153\f37С\fdозд\t188В\f37ы\fdход\x1";
	}

	const char *NO_ONE_TO_ADVENTURE_WITH() {
		return "\x82\xA0\xAC \xAD\xA5 \xE1 \xAA\xA5\xAC \xAF\xE3\xE2\xA5\xE8\xA5\xE1\xE2\xA2\xAE\xA2\xA0\xE2\xEC"; // "Вам не с кем путешествовать"
	}

	const char *YOUR_ROSTER_IS_FULL() {
		return "\x82\xA0\xE8 \xE1\xAF\xA8\xE1\xAE\xAA \xAF\xAE\xAB\xAE\xAD!"; // "Ваш список полон!"
	}

	const char *PLEASE_WAIT() {
		return "\fd\x3""c\t000\v002\x8F\xAE\xA4\xAE\xA6\xA4\xA8\xE2\xA5..."; // "\fd\x3""c\t000\v002Подождите..."
	}

	const char *OOPS() {
		return "\x3""c\t000\v002\x93\xAF\xE1..."; // "\x3""c\t000\v002Упс..."
	}

	const char *BANK_TEXT() {
		return "\r\x2\x3""c\v122\t013"									   // "\r\x2\x3""c\v122\t013"
			   "\f37\x82\fd\xAA\xAB\t040\f37\x91\fd\xAD\t067ESC"		   // "\f37В\fdкл\t040\f37С\fdн\t067ESC"
			   "\x1\t000\v000\x81\xA0\xAD\xAA \x8A\xE1\xA8\xAD\xA0\v015\n" // "\x1\t000\v000Банк Ксина\v015\n"
			   "\x81\xA0\xAD\xAA\x3""l\n"								   // "Банк\x3""l\n"
			   "\x87\xAE\xAB\x3""r\t000%s\x3""l\n"						   // "Зол\x3""r\t000%s\x3""l\n"
			   "\x80\xAB\xAC\xA7\x3""r\t000%s\x3""c\n"					   // "Алмз\x3""r\t000%s\x3""c\n"
			   "\n"														   // "\n"
			   "\x8E\xE2\xE0\xEF\xA4\x3""l\n"							   // "Отряд\x3""l\n"
			   "\x87\xAE\xAB\x3""r\t000%s\x3""l\n"						   // "Зол\x3""r\t000%s\x3""l\n"
			   "\x80\xAB\xAC\xA7\x3""r\t000%s";							   // "Алмз\x3""r\t000%s";
	}

	const char *BLACKSMITH_TEXT() {
		return "\x1\r\x3""c\v000\t000"							// "\x1\r\x3""c\v000\t000"
			   "\x8B\xA0\xA2\xAA\xA0\t039\v027%s\x3""l\v046\n"  // "Лавка\t039\v027%s\x3""l\v046\n"
			   "\t011\f37\x91\fd\xAC\xAE\xE2\xE0\xA5\xE2\xEC\n" // "\t011\f37С\fdмотреть\n"
			   "\t000\v090\x87\xAE\xAB\x3""r\t000%s"            // "\t000\v090Зол\x3""r\t000%s"
			   "\x2\x3""c\v122\t040ESC\x1";                     // "\x2\x3""c\v122\t040ESC\x1";
	}

	const char *GUILD_NOT_MEMBER_TEXT() {
		return "\n\x82\xEB \xA4\xAE\xAB\xA6\xAD\xEB \xA1\xEB\xE2\xEC \xE7\xAB\xA5\xAD\xAE\xAC \xA3\xA8\xAB\xEC\xA4\xA8\xA8, \xE7\xE2\xAE\xA1\xEB \xAF\xAE\xAA\xE3\xAF\xA0\xE2\xEC \xA7\xA0\xAA\xAB\xA8\xAD\xA0\xAD\xA8\xEF."; // "\nВы должны быть членом гильдии, чтобы покупать заклинания."
	}

	const char *GUILD_TEXT() {
		return "\x3""c\v027\t039%s"							   // "\x3""c\v027\t039%s"
			   "\x3""l\v046\n"                                 // "\x3""l\v046\n"
			   "\t012\f37\x8A\fd\xE3\xAF\xA8\xE2\xEC\n"        // "\t012\f37К\fdупить\n"
			   "\t012\f37\x8E\fd\xAF\xA8\xE1\xA0\xAD\xA8\xEF"; // "\t012\f37О\fdписания";
	}

	const char *TAVERN_TEXT() {
		return "\r\x3""c\v000\t000\x92\xA0\xA2\xA5\xE0\xAD\xA0\t039" // "\r\x3""c\v000\t000Таверна\t039"
			   "\v027%s%s\x3""l\t000"                                // "\v027%s%s\x3""l\t000"
			   "\v090\x87\xAE\xAB\x3""r\t000%s\x2\x3""c\v122"        // "\v090Зол\x3""r\t000%s\x2\x3""c\v122"
			   "\t021\f37\x8E\fd\xE2\xA4\xEB\xE5\t060ESC\x1";        // "\t021\f37О\fdтдых\t060ESC\x1";
	}

	const char *FOOD_AND_DRINK() {
		return "\x3""l\t017\v046\f37\x82\fd\xEB\xAF\xA8\xE2\xEC\n" // "\x3""l\t017\v046\f37В\fdыпить\n"
			   "\t017\f37\x85\fd\xA4\xA0\n"                        // "\t017\f37Е\fdда\n"
			   "\t017\f37\x97\fd\xA0\xA5\xA2\xEB\xA5\n"            // "\t017\f37Ч\fdаевые\n"
			   "\t017\f37\x91\fd\xAB\xE3\xE5\xA8";                 // "\t017\f37С\fdлухи";
	}

	const char *GOOD_STUFF() {
		return "\n"															 // "\n"
			   "\n"                                                          // "\n"
			   "\x8D\xA5\xA4\xE3\xE0\xAD\xAE\n"                              // "Недурно\n"
			   "\n"                                                          // "\n"
			   "\x8D\xA0\xA6\xAC\xA8\xE2\xA5 \xAA\xAB\xA0\xA2\xA8\xE8\xE3!"; // "Нажмите клавишу!";
	}

	const char *HAVE_A_DRINK() {
		return "\n\x91\xAF\xA5\xE0\xA2\xA0 \xA2\xEB\xAF\xA5\xA9\xE2\xA5\n\n\x8D\xA0\xA6\xAC\xA8\xE2\xA5 \xAA\xAB\xA0\xA2\xA8\xE8\xE3!"; // "\nСперва выпейте\n\nНажмите клавишу!"
	}

	const char *YOURE_DRUNK() {
		return "\n\n\x82\xEB \xAF\xEC\xEF\xAD\xEB\n\n\x8D\xA0\xA6\xAC\xA8\xE2\xA5 \xAA\xAB\xA0\xA2\xA8\xE8\xE3!"; // "\n\nВы пьяны\n\nНажмите клавишу!"
	}

	const char *TEMPLE_TEXT() {
		return "\r\x3""c\v000\t000\x95\xE0\xA0\xAC"					   // "\r\x3""c\v000\t000Храм"
			   "\t039\v027%s\x3""l\t000\v046"                          // "\t039\v027%s\x3""l\t000\v046"
			   "\f37\x8B\fd\xA5\xE7\xA8\xE2\xEC\x3""r\t000%lu\x3""l\n" // "\f37Л\fdечить\x3""r\t000%lu\x3""l\n"
			   "\f37\x84\fd\xA0\xE0\x3""r\t000%lu\x3""l\n"             // "\f37Д\fdар\x3""r\t000%lu\x3""l\n"
			   "\f37\x91\fd\xAD\x8F\xE0\xAE\xAA\xAB\x3""r\t000%s"      // "\f37С\fdнПрокл\x3""r\t000%s"
			   "\x3""l\t000\v090\x87\xAE\xAB\x3""r\t000%s"             // "\x3""l\t000\v090Зол\x3""r\t000%s"
			   "\x2\x3""c\v122\t040ESC\x1";                            // "\x2\x3""c\v122\t040ESC\x1";
	}

	const char *EXPERIENCE_FOR_LEVEL() {
		return "%s\n\x8D\xE3\xA6\xAD\xAE %lu \xAE\xE7\xAA\xAE\xA2 \xAE\xAF\xEB\xE2\xA0 \xA4\xAB\xEF \xE3\xE0\xAE\xA2\xAD\xEF %u."; // "%s\nНужно %lu очков опыта для уровня %u."
	}

	const char *TRAINING_LEARNED_ALL() {
		return "%s\n\x82\xEB \xE3\xA6\xA5 \xA7\xAD\xA0\xA5\xE2\xA5 \xA2\xE1\xF1, \xE7\xA5\xAC\xE3 \xAC\xEB \xAC\xAE\xA6\xA5\xAC \xA2\xA0\xE1 \xAD\xA0\xE3\xE7\xA8\xE2\xEC!"; // "%s\nВы уже знаете всё, чему мы можем вас научить!"
	}

	const char *ELIGIBLE_FOR_LEVEL() {
		return "%s \xAC\xAE\xA6\xA5\xE2 \xAE\xA1\xE3\xE7\xA0\xE2\xEC\xE1\xEF \xA4\xAE \xE3\xE0\xAE\xA2\xAD\xEF %d.\x3" // "%s может обучаться до уровня %d.\x3""l\n"
			   "l\n""\v081\x96\xA5\xAD\xA0\x3""r\t000%lu";                                                             // "\v081Цена\x3""r\t000%lu";
	}

	const char *TRAINING_TEXT() {
		return "\r\x3""c\x8E\xA1\xE3\xE7\xA5\xAD\xA8\xA5\n"						// "\r\x3""cОбучение\n"
			   "\n"                                                             // "\n"
			   "%s\x3""l\v090\t000\x87\xAE\xAB\x3""r\t000%s\x2\x3""c\v122\t021" // "%s\x3""l\v090\t000Зол\x3""r\t000%s\x2\x3""c\v122\t021"
			   "\f37\x8E\fd\xA1\xE3\xE7\xA5\xAD\xA8\xA5\t060ESC\x1";            // "\f37О\fdбучение\t060ESC\x1";
	}

	const char *GOLD_GEMS() {
		return "\x3""c\v000\t000%s\x3""l\n"																					 // "\x3""c\v000\t000%s\x3""l\n"
			   "\n"																											 // "\n"
			   "\x87\xAE\xAB\x3""r\t000%s\x3""l\n"																			 // "Зол\x3""r\t000%s\x3""l\n"
			   "\x80\xAB\xAC\xA7\x3""r\t000%s\x2\x3""c\v096\t007\f37\x80\fd\xAB\xAC\xA7\t035\f37\x87\fd\xAE\xAB\t067ESC\x1"; // "Алмз\x3""r\t000%s\x2\x3""c\v096\t007\f37А\fdлмз\t035\f37З\fdол\t067ESC\x1";
	}

	const char *GOLD_GEMS_2() {
		return "\t000\v000\x3""c%s\x3""l\n"										 // "\t000\v000\x3""c%s\x3""l\n"
			   "\n"                                                              // "\n"
			   "\x4""077\x87\xAE\xAB\x3""r\t000%s\x3""l\n"                       // "\x4""077Зол\x3""r\t000%s\x3""l\n"
			   "\x4""077\x80\xAB\xAC\xA7\x3""r\t000%s\x3""l\t000\v051\x4""077\n" // "\x4""077Алмз\x3""r\t000%s\x3""l\t000\v051\x4""077\n"
			   "\x4""077";                                                       // "\x4""077";
	}

	const char **DEPOSIT_WITHDRAWL() {
		delete[] _depositWithdrawl;
		_depositWithdrawl = new const char *[2] { "\x8F\xAE\xAB\xAE\xA6\xA8\xE2\xEC \xAD\xA0 \xE1\xE7\xF1\xE2", "\x91\xAD\xEF\xE2\xEC \xE1\xAE \xE1\xE7\xF1\xE2\xA0" }; // "Положить на счёт", "Снять со счёта"
		return _depositWithdrawl;
	}

	const char *NOT_ENOUGH_X_IN_THE_Y() {
		return "\x3""c\v012\x8D\xA5\xA4\xAE\xE1\xE2\xA0\xE2\xAE\xE7\xAD\xAE %s %s!\x3""l"; // "\x3""c\v012Недостаточно %s %s!\x3""l"
	}

	const char *NO_X_IN_THE_Y() {
		return "\x3""c\v012\x8D\xA5\xE2 %s %s!\x3""l"; // "\x3""c\v012Нет %s %s!\x3""l"
	}

	const char **STAT_NAMES() {
		delete[] _statNames;
		_statNames = new const char *[16] {
			"\x91\xA8\xAB\xA0", "\x88\xAD\xE2\xA5\xAB\xAB\xA5\xAA\xE2", "\x91\xA8\xAB\xA0 \xA4\xE3\xE5\xA0", "\x91\xAB\xAE\xA6\xA5\xAD\xA8\xA5", "\x91\xAA\xAE\xE0\xAE\xE1\xE2\xEC",	 // "Сила", "Интеллект", "Сила духа", "Сложение", "Скорость",
			"\x8C\xA5\xE2\xAA\xAE\xE1\xE2\xEC", "\x93\xA4\xA0\xE7\xA0", "\x82\xAE\xA7\xE0\xA0\xE1\xE2", "\x93\xE0\xAE\xA2\xA5\xAD\xEC", "\x8A\xAB\xA0\xE1\xE1 \xA7\xA0\xE9\xA8\xE2\xEB", // "Меткость", "Удача", "Возраст", "Уровень", "Класс защиты", "Здоровье", "\x87\xA4\xAE\xE0\xAE\xA2\xEC\xA5",
			"\x8E\xE7\xAA\xA8 \xAC\xA0\xA3\xA8\xA8", "\x93\xE1\xE2\xAE\xA9\xE7\xA8\xA2\xAE\xE1\xE2\xA8", "\x8D\xA0\xA2\xEB\xAA\xA8", "\x8D\xA0\xA3\xE0\xA0\xA4\xEB", "\x8E\xAF\xEB\xE2"  // "Очки магии", "Устойчивости", "Навыки", "Награды", "Опыт"
		};
		return _statNames;
	}

	const char **CONSUMABLE_NAMES() {
		delete[] _consumableNames;
		_consumableNames = new const char *[6] { "\x87\xAE\xAB\xAE\xE2\xAE", "\x80\xAB\xAC\xA0\xA7\xEB", "\x8F\xA8\xE9\xA0", "\x91\xAE\xE1\xE2\xAE\xEF\xAD\xA8\xA5", "\x87\xAE\xAB\xAE\xE2\xA0", "\x80\xAB\xAC\xA0\xA7\xAE\xA2" }; // "Золото", "Алмазы", "Пища", "Состояние", "Золота", "Алмазов"
		return _consumableNames;
	}

	const char **WHERE_NAMES() {
		delete[] _whereNames;
		_whereNames = new const char *[2] { "\xE3 \xAE\xE2\xE0\xEF\xA4\xA0", "\xA2 \xA1\xA0\xAD\xAA\xA5" }; // "у отряда", "в банке"
		return _whereNames;
	}

	const char *AMOUNT() {
		return "\x3""c\t000\v051\x91\xAA\xAE\xAB\xEC\xAA\xAE\x3""l\n"; // "\x3""c\t000\v051Сколько\x3""l\n"
	}

	const char *FOOD_PACKS_FULL() {
		return "\v007\x82\xA0\xE8\xA8 \xE0\xEE\xAA\xA7\xA0\xAA\xA8 \xE3\xA6\xA5 \xAD\xA0\xAF\xAE\xAB\xAD\xA5\xAD\xEB!"; // "\v007Ваши рюкзаки уже наполнены!"
	}

	const char *BUY_SPELLS() {
		return "\x3""c\v027\t039%s\x3""l\v046\n"			   // "\x3""c\v027\t039%s\x3""l\v046\n"
			   "\t012\f37\x8A\fd\xE3\xAF\xA8\xE2\xEC\n"        // "\t012\f37К\fdупить\n"
			   "\t012\f37\x8E\fd\xAF\xA8\xE1\xA0\xAD\xA8\xEF"; // "\t012\f37О\fdписания";
	}

	const char *GUILD_OPTIONS() {
		return "\x1\r\f00\x3""c\v000\t000\x83\xA8\xAB\xEC\xA4\xA8\xEF\n" // "\x1\r\f00\x3""c\v000\t000Гильдия\n"
			   "%s\x3""l\t000\v090\x87\xAE\xAB"							 // "%s\x3""l\t000\v090Зол"
			   "\x3""r\t000%s\x2\x3""c\v122\t040ESC\x1";				 // "\x3""r\t000%s\x2\x3""c\v122\t040ESC\x1";
	}

	const char *NOT_A_SPELL_CASTER() {
		return "\x82\xEB \xAD\xA5 \xA7\xA0\xAA\xAB\xA8\xAD\xA0\xE2\xA5\xAB\xEC..."; // "Вы не заклинатель..."
	}

	const char *SPELLS_LEARNED_ALL() {
		return "\x82\xEB \xE3\xA6\xA5 \xA7\xAD\xA0\xA5\xE2\xA5 \xA2\xE1\xF1,\n"		// "Вы уже знаете всё,\n"
			   "\t010\xE7\xA5\xAC\xE3 \xAC\xEB \xAC\xAE\xA6\xA5\xAC \xA2\xA0\xE1\n" // "\t010чему мы можем вас\n"
			   "\t010\xAD\xA0\xE3\xE7\xA8\xE2\xEC!\n"                               // "\t010научить!\n"
			   "\n"                                                                 // "\n"
			   "\n"                                                                 // "\n"
			   "\n"                                                                 // "\n"
			   "\n"                                                                 // "\n"
			   "\n"                                                                 // "\n"
			   "\n"                                                                 // "\n"
			   "\n"                                                                 // "\n"
			   "\n"                                                                 // "\n"
			   "\n";                                                                // "\n";
	}

	const char *SPELLS_FOR() {
		return "\r\fd%s\x2\x3""c\t000\v002\x87\xA0\xAA\xAB\xA8\xAD\xA0\xAD\xA8\xEF"; // "\r\fd%s\x2\x3""c\t000\v002Заклинания"
	}

	const char *SPELL_LINES_0_TO_9() {
		return "\x2\x3l\v015\t0011\n2\n3\n4\n5\n6\n7\n8\n9\n0";
	}

	const char *SPELLS_DIALOG_SPELLS() {
		return "\x3l\v015"
			   "\t010\f%2u%s\fd\x3l\n"
			   "\t010\f%2u%s\fd\x3l\n"
			   "\t010\f%2u%s\fd\x3l\n"
			   "\t010\f%2u%s\fd\x3l\n"
			   "\t010\f%2u%s\fd\x3l\n"
			   "\t010\f%2u%s\fd\x3l\n"
			   "\t010\f%2u%s\fd\x3l\n"
			   "\t010\f%2u%s\fd\x3l\n"
			   "\t010\f%2u%s\fd\x3l\n"
			   "\t010\f%2u%s\fd\x3l"
			   "\t004\v110%s - %u\x1";
	}

	const char *SPELL_PTS() {
		return "\x8C\xA0\xAD\xA0"; // "Мана"
	}

	const char *GOLD() {
		return "\x87\xAE\xAB"; // "Зол"
	}

	const char *SPELL_INFO() {
		return "\x3""c\f09%s\fd\x3""l\n"								// "\x3""c\f09%s\fd\x3""l\n"
			   "\n"                                                     // "\n"
			   "%s\x3""c\t000\v110\x8D. \xAA\xAB\xA0\xA2\xA8\xE8\xE3!"; // "%s\x3""c\t000\v110Н. клавишу!";
	}

	const char *SPELL_PURCHASE() {
		return "\x3""l\v000\t000\fd%s  \x86\xA5\xAB\xA0\xA5\xE2\xA5 \xAF\xE0\xA8\xAE\xA1\xE0\xA5\xE1\xE2\xA8 " // "\x3""l\v000\t000\fd%s  Желаете приобрести "
			   "\f09%s\fd \xA7\xA0 %u?";                                                                       // "\f09%s\fd за %u?";
	}

	const char *MAP_TEXT() {
		return "\x3""c\v000\t000%s\x3l\v139"			  // "\x3""c\v000\t000%s\x3l\v139"
			   "\t000X = %d\x3r\t000Y = %d\x3""c\t000%s"; // "\t000X = %d\x3r\t000Y = %d\x3""c\t000%s";
	}

	const char *LIGHT_COUNT_TEXT() {
		return "\x3""l\n\n\t024\x91\xA2\xA5\xE2\x3""r\t124%u"; // "\x3""l\n\n\t024Свет\x3""r\t124%u";
	}

	const char *FIRE_RESISTENCE_TEXT() {
		return "%c%s\x8E\xA3\xAE\xAD\xEC%s%u"; // "%c%sОгонь%s%u"
	}

	const char *ELECRICITY_RESISTENCE_TEXT() {
		return "%c%s\x83\xE0\xAE\xAC%s%u"; // "%c%sГром%s%u"
	}

	const char *COLD_RESISTENCE_TEXT() {
		return "%c%s\x95\xAE\xAB\xAE\xA4%s%u"; // "%c%sХолод%s%u"
	}

	const char *POISON_RESISTENCE_TEXT() {
		return "%c%s\x9F\xA4/\x8A\xA8\xE1\xAB\xAE\xE2\xA0%s%u"; // "%c%sЯд/Кислота%s%u"
	}

	const char *CLAIRVOYANCE_TEXT() {
		return "%c%s\x9F\xE1\xAD\xAE\xA2\xA8\xA4\xA5\xAD\xA8\xA5%s"; // "%c%sЯсновидение%s"
	}

	const char *LEVITATE_TEXT() {
		return "%c%s\x8B\xA5\xA2\xA8\xE2\xA0\xE6\xA8\xEF%s"; // "%c%sЛевитация%s"
	}

	const char *WALK_ON_WATER_TEXT() {
		return "%c%s\x95\xAE\xA6\xA4\xA5\xAD\xA8\xA5 \xAF\xAE \xA2\xAE\xA4\xA5"; // "%c%sХождение по воде"
	}

	const char *GAME_INFORMATION() {
		return "\r\x3""c\t000\v001\f37%s \x8A\xE1\xA8\xAD\xA0\fd\n"						 // "\r\x3""c\t000\v001\f37%s Ксина\fd\n"
			   "\x88\xA3\xE0\xAE\xA2\xA0\xEF \xA8\xAD\xE4\xAE\xE0\xAC\xA0\xE6\xA8\xEF\n" // "Игровая информация\n"
			   "\n"                                                                      // "\n"
			   "\x91\xA5\xA3\xAE\xA4\xAD\xEF \f37%s\fd\n"                                // "Сегодня \f37%s\fd\n"
			   "\n"                                                                      // "\n"
			   "\t032\x82\xE0\xA5\xAC\xEF\t072\x84\xA5\xAD\xEC\t112\x83\xAE\xA4\n"       // "\t032Время\t072День\t112Год\n"
			   "\t032\f37%d:%02d%c\t072%u\t112%u\fd%s";                                  // "\t032\f37%d:%02d%c\t072%u\t112%u\fd%s";
	}

	const char *WORLD_GAME_TEXT() {
		return "World";
	}

	const char *DARKSIDE_GAME_TEXT() {
		return "Darkside";
	}

	const char *CLOUDS_GAME_TEXT() {
		return "\x8E\xA1\xAB\xA0\xAA\xA0"; // "Облака"
	}

	const char *SWORDS_GAME_TEXT() {
		return "Swords";
	}

	const char **WEEK_DAY_STRINGS() {
		delete[] _weekDayStrings;
		_weekDayStrings = new const char *[10] {
			"\xA4\xA5\xE1\xEF\xE2\xA8\xA4\xA5\xAD\xEC", "\xAF\xA5\xE0\xA2\xAE\xA4\xA5\xAD\xEC", "\xA2\xE2\xAE\xE0\xAE\xA4\xA5\xAD\xEC", "\xE2\xE0\xA5\xE2\xEC\xA5\xA4\xA5\xAD\xEC", "\xE7\xA5\xE2\xA2\xA5\xE0\xAE\xA4\xA5\xAD\xEC", // "десятидень", "перводень", "втородень", "третьедень", "четверодень",
			"\xAF\xEF\xE2\xA8\xA4\xA5\xAD\xEC", "\xE8\xA5\xE1\xE2\xA8\xA4\xA5\xAD\xEC", "\xE1\xA5\xAC\xA8\xA4\xA5\xAD\xEC", "\xA2\xAE\xE1\xEC\xAC\xA8\xA4\xA5\xAD\xEC", "\xA4\xA5\xA2\xEF\xE2\xA8\xA4\xA5\xAD\xEC"                  // "пятидень",   "шестидень", "семидень",  "восьмидень", "девятидень"
		};
		return _weekDayStrings;
	}

	const char *CHARACTER_DETAILS() {
		return "\x3"
			   "l\v041\t196%s\t000\v002%s : %s %s %s"
			   "\x3"
			   "r\t053\v028\f%02u%u\fd\t103\f%02u%u\fd"
			   "\x3"
			   "l\t131\f%02u%d\fd\t196\f15%lu\fd\x3"
			   "r"
			   "\t053\v051\f%02u%u\fd\t103\f%02u%u\fd"
			   "\x3"
			   "l\t131\f%02u%u\fd\t196\f15%lu\fd"
			   "\x3"
			   "r\t053\v074\f%02u%u\fd\t103\f%02u%u\fd"
			   "\x3"
			   "l\t131\f15%u\fd\t196\f15%lu\fd"
			   "\x3"
			   "r\t053\v097\f%02u%u\fd\t103\f%02u%u\fd"
			   "\x3"
			   "l\t131\f15%u\fd\t196\f15%u %s\fd"
			   "\x3"
			   "r\t053\v120\f%02u%u\fd\t103\f%02u%u\fd"
			   "\x3"
			   "l\t131\f15%u\fd\t196\f%02u%s\fd"
			   "\t245%s%s%s%s\fd";
	}

	const char **DAYS() {
		delete[] _days;
		_days = new const char *[3] { "\xA4\xA5\xAD\xEC", "\xA4\xAD\xEF", "\xA4\xAD\xA5\xA9" }; // "день", "дня", "дней"
		return _days;
	}

	const char *PARTY_GOLD() {
		return "\x87\xAE\xAB\xAE\xE2\xAE"; // "Золото"
	}

	const char *PLUS_14() {
		return "\f14+";
	}

	const char *CHARACTER_TEMPLATE() {
		return "\x1\f00\r\x3""l\t029\v018\x91\xA8\xAB\t080\x8C\xE2\xAA\t131\x87\xA4\xAE\xE0\t196\x8E\xAF\xEB\xE2"						// "\x1\f00\r\x3""l\t029\v018Сил\t080Мтк\t131Здор\t196Опыт"
			   "\t029\v041\x88\xAD\xE2\t080\x93\xA4\xE7\t131\x8E\x8C\t029\v064\x84\xE3\xE5\t080\x82\xA7\xE0"                            // "\t029\v041Инт\t080Удч\t131ОМ\t029\v064Дух\t080Взр"
			   "\t131\x93\xE1\xE2\t196\x80\xAB\xAC\xA0\xA7\xEB\t029\v087\x91\xAB\xA6\t080\x93\xE0\xA2\t131\x8D\xA2\xAA"                 // "\t131Уст\t196Алмазы\t029\v087Слж\t080Урв\t131Нвк"
			   "\t196\x8F\xA8\xE9\xA0\t029\v110\x91\xAA\xE0\t080\x8A\x87\t131\x8D\xA0\xA3\xE0\t196\x91\xAE\xE1\xE2\xAE\xEF\xAD\xA8\xA5" // "\t196Пища\t029\v110Скр\t080КЗ\t131Нагр\t196Состояние"
			   "\x3""c\t290\v025\f37\x82\fd\xA5\xE9\xA8\t290\v057\f37\x81"                                                              // "\x3""c\t290\v025\f37В\fdещи\t290\v057\f37Б"
			   "\fd\xE1\xE2\xE0\t290\v089\f37\x91\fd\xAC\xA5\xAD\t290\v121\x82\xEB\xE5\xAE\xA4\x3""l%s";                                // "\fdстр\t290\v089\f37С\fdмен\t290\v121Выход\x3""l%s";
	}

	const char *EXCHANGING_IN_COMBAT() {
		return "\x3""c\v007\t000\x82\xAE \xA2\xE0\xA5\xAC\xEF \xA1\xA8\xE2\xA2\xEB \xA7\xA0\xAF\xE0\xA5\xE9\xA5\xAD\xAE \xAC\xA5\xAD\xEF\xE2\xEC\xE1\xEF \xAC\xA5\xE1\xE2\xA0\xAC\xA8!"; // "\x3""c\v007\t000Во время битвы запрещено меняться местами!"
	}

	const char *CURRENT_MAXIMUM_RATING_TEXT() {
		return "\x2\x3""c%s\n"												   // "\x2\x3""c%s\n"
			   "\x91\xA5\xA9\xE7\xA0\xE1 / \x8C\xA0\xAA\xE1\xA8\xAC\xE3\xAC\n" // "Сейчас / Максимум\n"
			   "\x3" "r\t054%lu\x3""l\t058/ %lu\n"                             // "\x3""r\t054%lu\x3""l\t058/ %lu\n"
			   "\x3""c\x90\xA0\xAD\xA3: %s\x1";                                // "\x3""cРанг: %s\x1";
	}

	const char *CURRENT_MAXIMUM_TEXT() {
		return "\x2\x3""c%s\n"                                                 // "\x2\x3""c%s\n"
			   "\x91\xA5\xA9\xE7\xA0\xE1 / \x8C\xA0\xAA\xE1\xA8\xAC\xE3\xAC\n" // "Сейчас / Максимум\n"
			   "\x3""r\t054%d\x3""l\t058/ %lu";                                // "\x3""r\t054%d\x3""l\t058/ %lu";
	}

	const char **RATING_TEXT() {
		delete[] _ratingText;
		_ratingText = new const char *[24] {
			"\x8D\xA5\xE2", "\x8C\xA8\xA7\xA5\xE0\xAD\xEB\xA9", "\x86\xA0\xAB\xAA\xA8\xA9", "\x8E\xE7.\xAD\xA8\xA7\xAA\xA8\xA9", "\x8D\xA8\xA7\xAA\xA8\xA9", "\x91\xE0\xA5\xA4\xAD\xA8\xA9", "\x95\xAE\xE0\xAE\xE8\xA8\xA9",											// "Нет", "Мизерный", "Жалкий", "Оч.низкий", "Низкий", "Средний", "Хороший",
			"\x8E\xE2\xAB\xA8\xE7\xAD\xEB\xA9", "\x82\xEB\xE1\xAE\xAA\xA8\xA9", "\x82\xEB\xE1\xAE\xE7\xA5\xAD\xAD\xEB\xA9", "\x81\xAE\xAB\xEC\xE8\xAE\xA9", "\x8E\xA3\xE0\xAE\xAC\xAD\xEB\xA9", "\x93\xA4\xA8\xA2\xA8\xE2\xA5\xAB\xEC\xAD\xEB\xA9",                     // "Отличный", "Высокий", "Высоченный", "Большой", "Огромный", "Удивительный",
			"\x8D\xA5\xA2\xA5\xE0\xAE\xEF\xE2\xAD\xEB\xA9", "\x83\xA8\xA3\xA0\xAD\xE2\xE1\xAA\xA8\xA9", "\x94\xA0\xAD\xE2\xA0\xE1\xE2\xA8\xE7\xAD\xEB\xA9", "\x88\xA7\xE3\xAC\xA8\xE2\xA5\xAB\xEC\xAD\xEB\xA9", "\x8F\xAE\xE0\xA0\xA7\xA8\xE2\xA5\xAB\xEC\xAD\xEB\xA9", // "Невероятный", "Гигантский", "Фантастичный", "Изумительный", "Поразительный",
			"\x83\xE0\xA0\xAD\xA4\xA8\xAE\xA7\xAD\xEB\xA9", "\x83\xE0\xAE\xAC\xA0\xA4\xAD\xEB\xA9", "\x8A\xAE\xAB\xAE\xE1\xE1\xA0\xAB\xEC\xAD\xEB\xA9", "\x8F\xAE\xE2\xE0\xEF\xE1\xA0\xEE\xE9\xA8\xA9", "\x97\xE3\xA4\xAE\xA2\xA8\xE9\xAD\xEB\xA9",                     // "Грандиозный", "Громадный", "Колоссальный", "Потрясающий", "Чудовищный",
			"\x82\xEB\xE1\xAE\xE7\xA0\xA9\xE8\xA8\xA9"                                                                                                                                                                                                                  // "Высочайший"
		};
		return _ratingText;
	}

	const char *AGE_TEXT() {
		return "\x2\x3""c%s\n"														   // "\x2\x3""c%s\n"
			   "\x92\xA5\xAA\xE3\xE9\xA8\xA9 / \x8D\xA0\xE1\xE2\xAE\xEF\xE9\xA8\xA9\n" // "Текущий / Настоящий\n"
			   "\x3""r\t057%u\x3""l\t061/ %u\n"                                        // "\x3""r\t057%u\x3""l\t061/ %u\n"
			   "\x3""c\x90\xAE\xA4\xA8\xAB%s: %u / %u\x1";                             // "\x3""cРодил%s: %u / %u\x1";
	}

	const char *LEVEL_TEXT() {
		return "\x2\x3""c%s\n"													   // "\x2\x3""c%s\n"
			   "\x92\xA5\xAA\xE3\xE9\xA8\xA9 / \x8C\xA0\xAA\xE1\xA8\xAC\xE3\xAC\n" // "Текущий / Максимум\n"
			   "\x3""r\t054%u\x3""l\t058/ %u\n"                                    // "\x3""r\t054%u\x3""l\t058/ %u\n"
			   "\x3""c%u \x80\xE2\xA0\xAA%s/\x90\xA0\xE3\xAD\xA4\x1";              // "\x3""c%u Атак%s/Раунд\x1";
	}

	const char *RESISTENCES_TEXT() {
		return "\x2\x3""c%s\x3""l\n"						// "\x2\x3""c%s\x3""l\n"
			   "\t020\x8E\xA3\xAE\xAD\xEC\t100%u\n"         // "\t020Огонь\t100%u\n"
			   "\t020\x95\xAE\xAB\xAE\xA4\t100%u\n"         // "\t020Холод\t100%u\n"
			   "\t020\x83\xE0\xAE\xAC\t100%u\n"             // "\t020Гром\t100%u\n"
			   "\t020\x9F\xA4\t100%u\n"                     // "\t020Яд\t100%u\n"
			   "\t020\x9D\xAD\xA5\xE0\xA3\xA8\xEF\t100%u\n" // "\t020Энергия\t100%u\n"
			   "\t020\x8C\xA0\xA3\xA8\xEF\t100%u";          // "\t020Магия\t100%u";
	}

	const char *NONE() {
		return "\n\t012\x8D\xA5\xE2"; // "\n\t012Нет"
	}

	const char *EXPERIENCE_TEXT() {
		return "\x2\x3""c%s\x3""l\n"									 // "\x2\x3""c%s\x3""l\n"
			   "\t005\x92\xA5\xAA\xE3\xE9\xA8\xA9:\t070%lu\n"            // "\t005Текущий:\t070%lu\n"
			   "\t005\x91\xAB. \xE3\xE0\xAE\xA2\xA5\xAD\xEC:\t070%s\x1"; // "\t005Сл. уровень:\t070%s\x1";
	}

	const char *ELIGIBLE() {
		return "\f12\x84\xAE\xE1\xE2\xE3\xAF\xA5\xAD\fd"; // "\f12Доступен\fd"
	}

	const char *IN_PARTY_IN_BANK() {
		return "\x2\x3""c%s\n"							 // "\x2\x3""c%s\n"
			   "%lu \xE1 \xE1\xAE\xA1\xAE\xA9\n"         // "%lu с собой\n"
			   "%lu \xA2 \xA1\xA0\xAD\xAA\xA5\x1\x3""l"; // "%lu в банке\x1\x3""l";
	}

	const char *FOOD_TEXT() {
		return "\x2\x3""c%s\n"									   // "\x2\x3""c%s\n"
			   "%u \xAF\xAE\xE0\xE6\xA8%c\n"                       // "%u порци%c\n"
			   "\x95\xA2\xA0\xE2\xA8\xE2 \xAD\xA0 %u %s\x1\x3""l"; // "Хватит на %u %s\x1\x3""l";
	}

	const char *EXCHANGE_WITH_WHOM() {
		return "\t010\v005\x8F\xAE\xAC\xA5\xAD\xEF\xE2\xEC\xE1\xEF \xE1 \xAA\xA5\xAC?"; // "\t010\v005Поменяться с кем?"
	}

	const char *QUICK_REF_LINE() {
		return "\v%3d\t007%u)\t027%s\t110%c%c%c\x3r\t160\f%02u%u\fd"
			   "\x3l\t170\f%02u%d\fd\t208\f%02u%u\fd\t247\f"
			   "%02u%u\fd\t270\f%02u%c%c%c%c\fd";
	}

	const char *QUICK_REFERENCE() {
		return "\r\x3""c\x81\xEB\xE1\xE2\xE0\xA0\xEF c\xAF\xE0\xA0\xA2\xAA\xA0\v012\x3""l"						 // "\r\x3""cБыстрая cправка\v012\x3""l"
			   "\t007#\t027\x88\xAC\xEF\t110\x8A\xAB\xE1\t147\x93\xE0\xA2\t174\x87\xA4\xAE\xE0"                  // "\t007#\t027Имя\t110Клс\t147Урв\t174Здор"
			   "\t214\x8E\x8C\t242\x8A\x87\t270\x91\xAE\xE1\xE2"                                                 // "\t214ОМ\t242КЗ\t270Сост"
			   "%s%s%s%s%s%s%s%s"                                                                                // "%s%s%s%s%s%s%s%s"
			   "\v110\t064\x3""c\x87\xAE\xAB\xAE\xE2\xAE\t144\x80\xAB\xAC\xA0\xA7\xEB\t224\x8F\xA8\xE9\xA0\v119" // "\v110\t064\x3""cЗолото\t144Алмазы\t224Пища\v119"
			   "\t064\f15%lu\t144%lu\t224%u %s\fd";                                                              //"\t064\f15%lu\t144%lu\t224%u %s\fd";
	}

	const char *ITEMS_DIALOG_TEXT1() {
		return "\r\x2\x3""c\v021\t017\x8E\xE0\xE3\f37\xA6\fd\t051\f37\x81\fd\xE0\xAE\xAD\xEF\t085"							   // "\r\x2\x3""c\v021\t017Ору\f37ж\fd\t051\f37Б\fdроня\t085"
			   "\f37\x93\fd\xAA\xE0\xA0\xE8\t119\f37\x90\fd\xA0\xA7\xAD\t153%s\t187%s\t221%s\t255%s\t289\x82\xEB\xE5\xAE\xA4"; // "\f37У\fdкраш\t119\f37Р\fdазн\t153%s\t187%s\t221%s\t255%s\t289Выход";
	}

	const char *ITEMS_DIALOG_TEXT2() {
		return "\r\x2\x3""c\v021\t017\x8E\xE0\xE3\f37\xA6\fd\t051\f37\x81\fd\xE0\xAE\xAD\xEF\t085"			  // "\r\x2\x3""c\v021\t017Ору\f37ж\fd\t051\f37Б\fdроня\t085"
			   "\f37\x93\fd\xAA\xE0\xA0\xE8\t119\f37\x90\fd\xA0\xA7\xAD\t153\f37%s\t289\x82\xEB\xE5\xAE\xA4"; // "\f37У\fdкраш\t119\f37Р\fdазн\t153\f37%s\t289Выход";
	}

	const char *ITEMS_DIALOG_LINE1() {
		return "\x3r\f%02u\t023%2d)\x3l\t028%s\n"; // "\x3r\f%02u\t023%2d)\x3l\t028%s\n"
	}

	const char *ITEMS_DIALOG_LINE2() {
		return "\x3r\f%02u\t023%2d)\x3l\t028%s\x3r\t000%u\n"; // "\x3r\f%02u\t023%2d)\x3l\t028%s\x3r\t000%u\n"
	}

	const char *BTN_BUY() {
		return "\f37\x8A\fd\xE3\xAF"; // "\f37К\fdуп"
	}

	const char *BTN_SELL() {
		return "\f37\x8F\fd\xE0\xAE\xA4"; // "\f37П\fdрод"
	}

	const char *BTN_IDENTIFY() {
		return "\f37\x8E\fd\xAF\xAE\xA7\xAD"; // "\f37О\fdпозн"
	}

	const char *BTN_FIX() {
		return "\f37\x97\fd\xA8\xAD\xA8\xE2\xEC"; // "\f37Ч\fdинить"
	}

	const char *BTN_USE() {
		return "\f37\x88\fd\xE1\xAF"; // "\f37И\fdсп"
	}

	const char *BTN_EQUIP() {
		return "\f37\x8D\fd\xA0\xA4"; // "\f37Н\fdад"
	}

	const char *BTN_REMOVE() {
		return "\f37\x91\fd\xAD\xEF\xE2\xEC"; // "\f37С\fdнять"
	}

	const char *BTN_DISCARD() {
		return "\f37\x82\fd\xEB\xA1\xE0"; // "\f37В\fdыбр"
	}

	const char *BTN_QUEST() {
		return "\f37\x87\fd\xA0\xA4\xA0\xAD"; // "\f37З\fdадан"
	}

	const char *BTN_ENCHANT() {
		return "\x87\fd\xA0\xE7\xA0\xE0"; // "З\fdачар"
	}

	const char *BTN_RECHARGE() {
		return "\x8F\fd\xA5\xE0\xA5\xA7\xE0"; // "П\fdерезр"
	}

	const char *BTN_GOLD() {
		return "\x87\fd\xAE\xAB\xAE\xE2\xAE"; // "З\fdолото"
	}

	const char *ITEM_BROKEN() {
		return "\f32\xE1\xAB\xAE\xAC\xA0\xAD\xAE "; // "\f32сломано "
	}

	const char *ITEM_CURSED() {
		return "\f09\xAF\xE0\xAE\xAA\xAB\xEF\xE2\xAE "; // "\f09проклято "
	}

	const char *ITEM_OF() {
		return "";
	}

	const char **BONUS_NAMES() {
		delete[] _bonusNames;
		_bonusNames = new const char *[7] {
			"", "\x93\xA1\xA8\xA9\xE6\xEB \xA4\xE0\xA0\xAA\xAE\xAD\xAE\xA2", "\x88\xA7\xA3\xAE\xAD\xEF\xEE\xE9\xA5\xA3\xAE \xAC\xF1\xE0\xE2\xA2\xEB\xE5", "\x8A\xE0\xE3\xE8\xA8\xE2\xA5\xAB\xEF \xA3\xAE\xAB\xA5\xAC\xAE\xA2", // "", "Убийцы драконов", "Изгоняющего мёртвых", "Крушителя големов",
			"\x84\xA0\xA2\xA8\xE2\xA5\xAB\xEF \xAD\xA0\xE1\xA5\xAA\xAE\xAC\xEB\xE5", "\x93\xA1\xA8\xA9\xE6\xEB \xAC\xAE\xAD\xE1\xE2\xE0\xAE\xA2", "\x93\xA1\xA8\xA9\xE6\xEB \xA7\xA2\xA5\xE0\xA5\xA9"                          // "Давителя насекомых", "Убийцы монстров", "Убийцы зверей"
		};
		return _bonusNames;
	}

	const char **WEAPON_NAMES() {
		delete[] _weaponNames;
		_weaponNames = new const char *[41] {
			nullptr, "\xAC\xA5\xE7 ", "\xA3\xAB\xA0\xA4\xA8\xE3\xE1 ", "\xAF\xA0\xAB\xA0\xE8 ", "\xEF\xE2\xA0\xA3\xA0\xAD ",																			   // nullptr, "меч ", "гладиус ", "палаш ", "ятаган ",
			"\xAA\xAE\xE0\xE2\xA8\xAA ", "\xE1\xA0\xA1\xAB\xEF ", "\xA4\xE3\xA1\xA8\xAD\xA0 ", "\xE2\xAE\xAF\xAE\xE0 ", "\xAA\xA0\xE2\xA0\xAD\xA0 ", "\xAD\xE3\xAD\xE7\xA0\xAA\xA8 ",                      // "кортик ", "сабля ", "дубина ", "топор ", "катана ", "нунчаки ",
			"\xA2\xA0\xAA\xA8\xA4\xA7\xA0\xE1\xA8 ", "\xAA\xA8\xAD\xA6\xA0\xAB ", "\xA1\xE3\xAB\xA0\xA2\xA0 ", "\xE6\xA5\xAF ", "\xA6\xA5\xA7\xAB ", "\xAC\xAE\xAB\xAE\xE2 ", "\xAA\xAE\xAF\xEC\xF1 ",     // "вакидзаси ", "кинжал ", "булава ", "цеп ", "жезл ", "молот ", "копьё ",
			"\xA1\xA5\xE0\xA4\xEB\xE8 ", "\xA3\xAB\xA5\xE4\xA0 ", "\xA0\xAB\xA5\xA1\xA0\xE0\xA4\xA0 ", "\xAF\xA8\xAA\xA0 ", "\xE4\xAB\xA0\xAC\xA1\xA5\xE0\xA3 ", "\xE2\xE0\xA5\xA7\xE3\xA1\xA5\xE6 ",      // "бердыш ", "глефа ", "алебарда ", "пика ", "фламберг ", "трезубец ",
			"\xAF\xAE\xE1\xAE\xE5 ", "\xA1\xAE\xA5\xA2\xAE\xA9 \xAC\xAE\xAB\xAE\xE2 ", "\xAD\xA0\xA3\xA8\xAD\xA0\xE2\xA0 ", "\xA1\xAE\xA5\xA2\xAE\xA9 \xE2\xAE\xAF\xAE\xE0 ", "\xE1\xA5\xAA\xA8\xE0\xA0 ", // "посох ", "боевой молот ", "нагината ", "боевой топор ", "секира ",
			"\xE2\xAE\xAF\xAE\xE0 \xAF\xA0\xAB\xA0\xE7\xA0 ", "\xAB\xE3\xAA ", "\xA1\xAE\xAB\xEC\xE8\xAE\xA9 \xAB\xE3\xAA ", "\xA0\xE0\xA1\xA0\xAB\xA5\xE2 ", "\xAF\xE0\xA0\xE9\xA0 ",                     // "топор палача ", "лук ", "большой лук ", "арбалет ", "праща ",
			"\x8C\xA5\xE7 - \xE3\xA1\xA8\xA9\xE6\xA0 \x8A\xE1\xA8\xAD\xA0 ",                                                                                                                               // "Меч - убийца Ксина ",
			"Elder LongSword ", "Elder Dagger ", "Elder Mace ", "Elder Spear ",                                                                                                                            // "Elder LongSword ", "Elder Dagger ", "Elder Mace ", "Elder Spear ",
			"Elder Staff ", "Elder LongBow "                                                                                                                                                               // "Elder Staff ", "Elder LongBow "
		};
		return _weaponNames;
	}

	const char **ARMOR_NAMES() {
		delete[] _armorNames;
		_armorNames = new const char *[14] {
			nullptr, "\xAC\xA0\xAD\xE2\xA8\xEF ", "\xE7\xA5\xE8\xE3\xEF ", "\xAF\xA0\xAD\xE6\xA8\xE0\xEC ", "\xAA\xAE\xAB\xEC\xE7\xE3\xA3\xA0 ",		// nullptr, "мантия ", "чешуя ", "панцирь ", "кольчуга ",
			"\xEE\xE8\xAC\xA0\xAD ", "\xA1\xA5\xE5\xE2\xA5\xE0\xA5\xE6 ", "\xAB\xA0\xE2\xEB ", "\xE9\xA8\xE2 ",                                         // "юшман ", "бехтерец ", "латы ", "щит ",
			"\xE8\xAB\xA5\xAC ", "\xE1\xA0\xAF\xAE\xA3\xA8 ", "\xAF\xAB\xA0\xE9 ", "\xAD\xA0\xAA\xA8\xA4\xAA\xA0 ", "\xAF\xA5\xE0\xE7\xA0\xE2\xAA\xA8 " // "шлем ", "сапоги ", "плащ ", "накидка ", "перчатки "
		};
		return _armorNames;
	}

	const char **ACCESSORY_NAMES() {
		delete[] _accessoryNames;
		_accessoryNames = new const char *[11] {
			nullptr, "\xAA\xAE\xAB\xEC\xE6\xAE ", "\xAF\xAE\xEF\xE1 ", "\xA1\xE0\xAE\xE8\xEC ", "\xAC\xA5\xA4\xA0\xAB\xEC ", "\xE2\xA0\xAB\xA8\xE1\xAC\xA0\xAD ", "\xAA\xA0\xAC\xA5\xEF ", // nullptr, "кольцо ", "пояс ", "брошь ", "медаль ", "талисман ", "камея ",
			"\xE1\xAA\xA0\xE0\xA0\xA1\xA5\xA9 ", "\xAA\xE3\xAB\xAE\xAD ", "\xAE\xA6\xA5\xE0\xA5\xAB\xEC\xA5 ", "\xA0\xAC\xE3\xAB\xA5\xE2 "                                                 // "скарабей ", "кулон ", "ожерелье ", "амулет "
		};
		return _accessoryNames;
	}

	const char **MISC_NAMES() {
		delete[] _miscNames;
		_miscNames = new const char *[22] {
			nullptr, "\xE1\xAA\xA8\xAF\xA5\xE2\xE0 ", "\xE1\xA0\xAC\xAE\xE6\xA2\xA5\xE2 ", "\xAA\xA0\xAC\xA5\xAD\xEC ", "\xE8\xAA\xA0\xE2\xE3\xAB\xAA\xA0 ", "\xE1\xE4\xA5\xE0\xA0 ", "\xE0\xAE\xA3 ",								// nullptr, "скипетр ", "самоцвет ", "камень ", "шкатулка ", "сфера ", "рог ",
			"\xAC\xAE\xAD\xA5\xE2\xAA\xA0 ", "\xA6\xA5\xA7\xAB ", "\xE1\xA2\xA8\xE1\xE2\xAE\xAA ", "\xA7\xA5\xAB\xEC\xA5 ", "\xE1\xA2\xA8\xE2\xAE\xAA ", "\xAF\xAE\xA4\xA4\xA5\xAB\xAA\xA0", "\xAF\xAE\xA4\xA4\xA5\xAB\xAA\xA0",    // "монетка ", "жезл ", "свисток ", "зелье ", "свиток ", "подделка", "подделка",
			"\xAF\xAE\xA4\xA4\xA5\xAB\xAA\xA0", "\xAF\xAE\xA4\xA4\xA5\xAB\xAA\xA0", "\xAF\xAE\xA4\xA4\xA5\xAB\xAA\xA0", "\xAF\xAE\xA4\xA4\xA5\xAB\xAA\xA0", "\xAF\xAE\xA4\xA4\xA5\xAB\xAA\xA0", "\xAF\xAE\xA4\xA4\xA5\xAB\xAA\xA0", // "подделка", "подделка", "подделка", "подделка", "подделка", "подделка",
			"\xAF\xAE\xA4\xA4\xA5\xAB\xAA\xA0", "\xAF\xAE\xA4\xA4\xA5\xAB\xAA\xA0"                                                                                                                                                  // "подделка", "подделка"
		};
		return _miscNames;
	}

	const char **SPECIAL_NAMES() {
		delete[] _specialNames;
		_specialNames = new const char *[74] {
			nullptr, "\xE1\xA2\xA5\xE2\xA0", "\xAF\xE0\xAE\xA1\xE3\xA6\xA4\xA5\xAD\xA8\xEF", "\xA2\xAE\xAB\xE8\xA5\xA1\xAD\xEB\xE5 \xE1\xE2\xE0\xA5\xAB", "\xAF\xA5\xE0\xA2\xAE\xA9 \xAF\xAE\xAC\xAE\xE9\xA8",														  // nullptr, "света", "пробуждения", "волшебных стрел", "первой помощи",
			"\xAA\xE3\xAB\xA0\xAA\xAE\xA2", "\xED\xAD\xA5\xE0\xA3\xA5\xE2\xA8\xE7\xA5\xE1\xAA\xAE\xA3\xAE \xA2\xA7\xE0\xEB\xA2\xA0", "\xE3\xE1\xEB\xAF\xAB\xA5\xAD\xA8\xEF", "\xAB\xA5\xE7\xA5\xAD\xA8\xEF \xE1\xAB\xA0\xA1\xAE\xE1\xE2\xA8",                         // "кулаков", "энергетического взрыва", "усыпления", "лечения слабости",
			"\xAB\xA5\xE7\xA5\xAD\xA8\xEF", "\xA8\xE1\xAA\xE0", "\xE8\xE0\xA0\xAF\xAD\xA5\xAB\xA8", "\xE0\xA5\xAF\xA5\xAB\xAB\xA5\xAD\xE2\xA0", "\xEF\xA4\xAE\xA2\xA8\xE2\xEB\xE5 \xAE\xA1\xAB\xA0\xAA\xAE\xA2",                                                      // "лечения", "искр", "шрапнели", "репеллента", "ядовитых облаков",
			"\xA7\xA0\xE9\xA8\xE2\xEB \xAE\xE2 \xE1\xE2\xA8\xE5\xA8\xA9", "\xA1\xAE\xAB\xA8", "\xAF\xE0\xEB\xA6\xAA\xAE\xA2", "\xAA\xAE\xAD\xE2\xE0\xAE\xAB\xEF \xAD\xA0\xA4 \xAC\xAE\xAD\xE1\xE2\xE0\xA0\xAC\xA8",                                                   // "защиты от стихий", "боли", "прыжков", "контроля над монстрами",
			"\xEF\xE1\xAD\xAE\xA2\xA8\xA4\xA5\xAD\xA8\xEF", "\xA8\xA7\xA3\xAD\xA0\xAD\xA8\xEF \xAD\xA5\xA6\xA8\xE2\xA8", "\xAB\xA5\xA2\xA8\xE2\xA0\xE6\xA8\xA8", "\xA2\xAE\xAB\xE8\xA5\xA1\xAD\xAE\xA3\xAE \xA3\xAB\xA0\xA7\xA0",                                     // "ясновидения", "изгнания нежити", "левитации", "волшебного глаза",
			"\xA1\xAB\xA0\xA3\xAE\xE1\xAB\xAE\xA2\xA5\xAD\xA8\xEF", "\xAE\xAF\xAE\xA7\xAD\xA0\xAD\xA8\xEF \xAC\xAE\xAD\xE1\xE2\xE0\xAE\xA2", "\xAC\xAE\xAB\xAD\xA8\xA9", "\xE1\xA2\xEF\xE2\xEB\xE5 \xA4\xA0\xE0\xAE\xA2", "\xA8\xE1\xE6\xA5\xAB\xA5\xAD\xA8\xEF",     // "благословения", "опознания монстров", "молний", "святых даров", "исцеления",
			"\xAF\xE0\xA8\xE0\xAE\xA4\xAD\xAE\xA3\xAE \xAB\xA5\xE7\xA5\xAD\xA8\xEF", "\xAC\xA0\xEF\xAA\xAE\xA2", "\xE9\xA8\xE2\xA0", "\xAC\xE3\xA6\xA5\xE1\xE2\xA2\xA0", "\xA3\xA8\xAF\xAD\xAE\xA7\xA0",                                                              // "природного лечения", "маяков", "щита", "мужества", "гипноза",
			"\xE5\xAE\xA6\xA4\xA5\xAD\xA8\xEF \xAF\xAE \xA2\xAE\xA4\xA5", "\xAE\xA1\xA6\xA8\xA3\xA0\xEE\xE9\xA5\xA3\xAE \xE5\xAE\xAB\xAE\xA4\xA0", "\xAF\xAE\xA8\xE1\xAA\xA0 \xAC\xAE\xAD\xE1\xE2\xE0\xAE\xA2",                                                       // "хождения по воде", "обжигающего холода", "поиска монстров",
			"\xAE\xA3\xAD\xA5\xAD\xAD\xEB\xE5 \xE8\xA0\xE0\xAE\xA2", "\xAB\xE3\xE7\xA5\xA9 \xE5\xAE\xAB\xAE\xA4\xA0", "\xAF\xE0\xAE\xE2\xA8\xA2\xAE\xEF\xA4\xA8\xEF", "\xE0\xA0\xE1\xAF\xEB\xAB\xA5\xAD\xA8\xEF \xAA\xA8\xE1\xAB\xAE\xE2\xEB",                        // "огненных шаров", "лучей холода", "противоядия", "распыления кислоты",
			"\xA2\xE0\xA5\xAC\xA5\xAD\xAD\xAE\xA3\xAE \xA8\xE1\xAA\xA0\xA6\xA5\xAD\xA8\xEF", "\xE3\xE1\xEB\xAF\xAB\xA5\xAD\xA8\xEF \xA4\xE0\xA0\xAA\xAE\xAD\xAE\xA2", "\xA2\xA0\xAA\xE6\xA8\xAD\xA0\xE6\xA8\xA8", "\xE2\xA5\xAB\xA5\xAF\xAE\xE0\xE2\xA0\xE6\xA8\xA8", // "временного искажения", "усыпления драконов", "вакцинации", "телепортации",
			"\xE1\xAC\xA5\xE0\xE2\xA8", "\xE1\xA2\xAE\xA1\xAE\xA4\xAD\xAE\xA3\xAE \xA4\xA2\xA8\xA6\xA5\xAD\xA8\xEF", "\xAE\xE1\xE2\xA0\xAD\xAE\xA2\xAA\xA8 \xA3\xAE\xAB\xA5\xAC\xA0", "\xEF\xA4\xAE\xA2\xA8\xE2\xEB\xE5 \xA7\xA0\xAB\xAF\xAE\xA2",                    // "смерти", "свободного движения", "остановки голема", "ядовитых залпов",
			"\xE1\xAC\xA5\xE0\xE2\xA5\xAB\xEC\xAD\xAE\xA3\xAE \xE0\xAE\xEF", "\xE3\xA1\xA5\xA6\xA8\xE9\xA0", "\xA4\xAD\xEF \xA7\xA0\xE9\xA8\xE2\xEB", "\xA4\xAD\xEF \xAC\xA0\xA3\xA8\xA8", "\xAF\xA8\xE0\xA0",                                                        // "смертельного роя", "убежища", "дня защиты", "дня магии", "пира",
			"\xAE\xA3\xAD\xA5\xAD\xAD\xAE\xA3\xAE \xE6\xA5\xAF\xA0", "\xAF\xA5\xE0\xA5\xA7\xA0\xE0\xEF\xA4\xAA\xA8", "\xAC\xAE\xE0\xAE\xA7\xA0", "\xA3\xAE\xE0\xAE\xA4\xE1\xAA\xA8\xE5 \xAF\xAE\xE0\xE2\xA0\xAB\xAE\xA2",                                             // "огненного цепа", "перезарядки", "мороза", "городских порталов",
			"\xE1\xAD\xEF\xE2\xA8\xEF \xAE\xAA\xA0\xAC\xA5\xAD\xA5\xAD\xA8\xEF", "\xAE\xA6\xA8\xA2\xAB\xA5\xAD\xA8\xEF \xAC\xF1\xE0\xE2\xA2\xEB\xE5", "\xA4\xA5\xAC\xA0\xE2\xA5\xE0\xA8\xA0\xAB\xA8\xA7\xA0\xE6\xA8\xA8",                                             // "снятия окаменения", "оживления мёртвых", "дематериализации",
			"\xE2\xA0\xAD\xE6\xE3\xEE\xE9\xA8\xE5 \xAA\xAB\xA8\xAD\xAA\xAE\xA2", "\xAB\xE3\xAD\xAD\xEB\xE5 \xAB\xE3\xE7\xA5\xA9", "\xA8\xA7\xAC\xA5\xAD\xA5\xAD\xA8\xEF \xA2\xA5\xE1\xA0",                                                                            // "танцующих клинков", "лунных лучей", "изменения веса",
			"\xAF\xE0\xA8\xA7\xAC\xA0\xE2\xA8\xE7\xA5\xE1\xAA\xAE\xA3\xAE \xE1\xA2\xA5\xE2\xA0", "\xE7\xA0\xE0", "\xA8\xE1\xAF\xA5\xAF\xA5\xAB\xA5\xAD\xA8\xEF", "\xE1\xA2\xEF\xE2\xEB\xE5 \xE1\xAB\xAE\xA2", "\xA2\xAE\xE1\xAA\xE0\xA5\xE8\xA5\xAD\xA8\xEF",         // "призматического света", "чар", "испепеления", "святых слов", "воскрешения",
			"\xA1\xE3\xE0\xEC", "\xAC\xA5\xA3\xA0\xA2\xAE\xAB\xEC\xE2", "\xA8\xAD\xE4\xA5\xE0\xAD\xAE", "\xE1\xAE\xAB\xAD\xA5\xE7\xAD\xEB\xE5 \xAB\xE3\xE7\xA5\xA9", "\xA8\xAC\xAF\xAB\xAE\xA7\xA8\xA9",                                                              // "бурь", "мегавольт", "инферно", "солнечных лучей", "имплозий",
			"\xA2\xA7\xE0\xEB\xA2\xA0 \xA7\xA2\xA5\xA7\xA4\xEB", "\x81\x8E\x83\x8E\x82!"                                                                                                                                                                              // "взрыва звезды", "БОГОВ!"
		};
		return _specialNames;
	}

	const char **ELEMENTAL_NAMES() {
		delete[] _elementalNames;
		_elementalNames = new const char *[6] {
			"\x8E\xA3\xAD\xEF", "\x83\xE0\xAE\xAC\xA0", "\x95\xAE\xAB\xAE\xA4\xA0", "\x8A\xA8\xE1\xAB\xAE\xE2\xEB/\x9F\xA4\xA0", "\x9D\xAD\xA5\xE0\xA3\xA8\xA8", "\x8C\xA0\xA3\xA8\xA8" // "Огня", "Грома", "Холода", "Кислоты/Яда", "Энергии", "Магии"
		};
		return _elementalNames;
	}

	const char **ATTRIBUTE_NAMES() {
		delete[] _attributeNames;
		_attributeNames = new const char *[10] {
			"\x91\xA8\xAB\xA0", "\x88\xAD\xE2\xA5\xAB\xAB\xA5\xAA\xE2", "\x91\xA8\xAB\xA0 \xA4\xE3\xE5\xA0", "\x91\xAA\xAE\xE0\xAE\xE1\xE2\xEC", "\x8C\xA5\xE2\xAA\xAE\xE1\xE2\xEC", "\x93\xA4\xA0\xE7\xA0", // "Сила", "Интеллект", "Сила духа", "Скорость", "Меткость", "Удача",
			"\x87\xA4\xAE\xE0\xAE\xA2\xEC\xA5", "\x8E\xE7\xAA\xA8 \xAC\xA0\xA3\xA8\xA8", "\x8A\xAB\xA0\xE1\xE1 \xA7\xA0\xE9\xA8\xE2\xEB", "\x82\xAE\xE0\xAE\xA2\xE1\xE2\xA2\xAE"                             // "Здоровье", "Очки магии", "Класс защиты", "Воровство"
		};
		return _attributeNames;
	}

	const char **EFFECTIVENESS_NAMES() {
		delete[] _effectivenessNames;
		_effectivenessNames = new const char *[7] {
			nullptr, "\x84\xE0\xA0\xAA\xAE\xAD\xAE\xA2", "\x8C\xF1\xE0\xE2\xA2\xEB\xE5", "\x83\xAE\xAB\xA5\xAC\xAE\xA2", "\x8D\xA0\xE1\xA5\xAA\xAE\xAC\xEB\xE5", "\x8C\xAE\xAD\xE1\xE2\xE0\xAE\xA2", "\x87\xA2\xA5\xE0\xA5\xA9" // nullptr, "Драконов", "Мёртвых", "Големов", "Насекомых", "Монстров", "Зверей"
		};
		return _effectivenessNames;
	}

	const char **QUEST_ITEM_NAMES() {
		delete[] _questItemNames;
		_questItemNames = new const char *[85] {
			"\x8F\xE0\xA0\xA2\xAE \xA2\xAB\xA0\xA4\xA5\xAD\xA8\xEF \x8D\xEC\xEE\xAA\xA0\xE1\xAB\xAE\xAC",											   // "Право владения Ньюкаслом",
			"\x95\xE0\xE3\xE1\xE2\xA0\xAB\xEC\xAD\xEB\xA9 \xAA\xAB\xEE\xE7 \xAE\xE2 \x82\xA5\xA4\xEC\xAC\xA8\xAD\xAE\xA9 \xA1\xA0\xE8\xAD\xA8",        // "Хрустальный ключ от Ведьминой башни",
			"\x8E\xE2\xAC\xEB\xE7\xAA\xA0 \xA4\xAB\xEF \xA1\xA0\xE8\xAD\xA8 \x84\xA0\xE0\xA7\xAE\xA3\xA0",                                             // "Отмычка для башни Дарзога",
			"\x8A\xAB\xEE\xE7 \xAE\xE2 \x81\xA0\xE8\xAD\xA8 \xA2\xEB\xE1\xE8\xA5\xA9 \xAC\xA0\xA3\xA8\xA8",                                            // "Ключ от Башни высшей магии",
			"\x84\xE0\xA0\xA3\xAE\xE6\xA5\xAD\xAD\xEB\xA9 \xA0\xAC\xE3\xAB\xA5\xE2 \x91\xA5\xA2\xA5\xE0\xAD\xAE\xA3\xAE \x91\xE4\xA8\xAD\xAA\xE1\xA0", // "Драгоценный амулет Северного Сфинкса",
			"\x8A\xA0\xAC\xA5\xAD\xEC \x92\xEB\xE1\xEF\xE7\xA8 \x93\xA6\xA0\xE1\xAE\xA2",                                                              // "Камень Тысячи Ужасов",
			"\x8E\xE2\xAF\xA8\xE0\xA0\xEE\xE9\xA8\xA9 \xAA\xA0\xAC\xA5\xAD\xEC \xA3\xAE\xAB\xA5\xAC\xAE\xA2",                                          // "Отпирающий камень големов",
			"\x8E\xE2\xAF\xA8\xE0\xA0\xEE\xE9\xA8\xA9 \xAA\xA0\xAC\xA5\xAD\xEC \x9F\xAA\xA0",                                                          // "Отпирающий камень Яка",
			"\x91\xAA\xA8\xAF\xA5\xE2\xE0 \x82\xE0\xA5\xAC\xA5\xAD\xAD\xAE\xA3\xAE \x88\xE1\xAA\xA0\xA6\xA5\xAD\xA8\xEF",                              // "Скипетр Временного Искажения",
			"\x90\xAE\xA3 \x94\xA0\xAB\xA8\xE1\xE2\xEB",                                                                                               // "Рог Фалисты",
			"\x9D\xAB\xA8\xAA\xE1\xA8\xE0 \x82\xAE\xE1\xE1\xE2\xA0\xAD\xAE\xA2\xAB\xA5\xAD\xA8\xEF",                                                   // "Эликсир Восстановления",
			"\x82\xAE\xAB\xE8\xA5\xA1\xAD\xEB\xA9 \xA6\xA5\xA7\xAB \xE4\xA5\xA9",                                                                      // "Волшебный жезл фей",
			"\x84\xA8\xA0\xA4\xA5\xAC\xA0 \xAF\xE0\xA8\xAD\xE6\xA5\xE1\xE1\xEB \x90\xAE\xAA\xE1\xA0\xAD\xEB",                                          // "Диадема принцессы Роксаны",
			"\x91\xA2\xEF\xE9\xA5\xAD\xAD\xA0\xEF \x8A\xAD\xA8\xA3\xA0 \x9D\xAB\xEC\xE4\xAE\xA2",                                                      // "Священная Книга Эльфов",
			"\x91\xAA\xA0\xE0\xA0\xA1\xA5\xA9 \x82\xAE\xAF\xAB\xAE\xE9\xA5\xAD\xA8\xEF",                                                               // "Скарабей Воплощения",
			"\x8A\xE0\xA8\xE1\xE2\xA0\xAB\xAB\xEB \x8F\xEC\xA5\xA7\xAE\xED\xAB\xA5\xAA\xE2\xE0\xA8\xE7\xA5\xE1\xE2\xA2\xA0",                           // "Кристаллы Пьезоэлектричества",
			"\x91\xA2\xA8\xE2\xAE\xAA \x8C\xE3\xA4\xE0\xAE\xE1\xE2\xA8",                                                                               // "Свиток Мудрости",
			"\x8A\xAE\xE0\xA5\xAD\xEC \xE4\xA8\xE0\xAD\xEB",                                                                                           // "Корень фирны",
			"\x8A\xAE\xE1\xE2\xEF\xAD\xAE\xA9 \xE1\xA2\xA8\xE1\xE2\xAE\xAA \x8E\xE0\xAE\xE4\xA8\xAD\xA0",                                              // "Костяной свисток Орофина",
			"\x82\xAE\xAB\xE8\xA5\xA1\xAD\xEB\xA9 \xAA\xE3\xAB\xAE\xAD \x81\xA0\xE0\xAE\xAA\xA0",                                                      // "Волшебный кулон Барока",
			"\x8F\xE0\xAE\xAF\xA0\xA2\xE8\xA8\xA9 \xE7\xA5\xE0\xA5\xAF \x8B\xA8\xA3\xAE\xAD\xAE",                                                      // "Пропавший череп Лигоно",
			"\x8F\xAE\xE1\xAB\xA5\xA4\xAD\xA8\xA9 \xE6\xA2\xA5\xE2\xAE\xAA \xAB\xA5\xE2\xA0",                                                          // "Последний цветок лета",
			"\x8F\xAE\xE1\xAB\xA5\xA4\xAD\xEF\xEF \xA4\xAE\xA6\xA4\xA5\xA2\xA0\xEF \xAA\xA0\xAF\xA5\xAB\xEC\xAA\xA0 \xA2\xA5\xE1\xAD\xEB",             // "Последняя дождевая капелька весны",
			"\x8F\xAE\xE1\xAB\xA5\xA4\xAD\xEF\xEF \xE1\xAD\xA5\xA6\xA8\xAD\xAA\xA0 \xA7\xA8\xAC\xEB",                                                  // "Последняя снежинка зимы",
			"\x8F\xAE\xE1\xAB\xA5\xA4\xAD\xA8\xA9 \xAB\xA8\xE1\xE2 \xAE\xE1\xA5\xAD\xA8",                                                              // "Последний лист осени",
			"\x82\xA5\xE7\xAD\xAE \xA3\xAE\xE0\xEF\xE7\xA8\xA9 \xAA\xE3\xE1\xAE\xAA \xAF\xA5\xAC\xA7\xEB",                                             // "Вечно горячий кусок пемзы",
			"\x8C\xA5\xA3\xA0\xAA\xE0\xA5\xA4\xA8\xE2 \xAA\xAE\xE0\xAE\xAB\xEF",                                                                       // "Мегакредит короля",
			"\x90\xA0\xA7\xE0\xA5\xE8\xA5\xAD\xA8\xA5 \xAD\xA0 \xE0\xA0\xE1\xAA\xAE\xAF\xAA\xA8",                                                      // "Разрешение на раскопки",
			"\x8A\xE3\xAA\xAE\xAB\xAA\xA0",                                                                                                            // "Куколка",
			"\x8A\xE3\xAA\xAB\xA0 \x91\xA8\xAB\xEB",                                                                                                   // "Кукла Силы",
			"\x8A\xE3\xAA\xAB\xA0 \x91\xAA\xAE\xE0\xAE\xE1\xE2\xA8",                                                                                   // "Кукла Скорости",
			"\x8A\xE3\xAA\xAB\xA0 \x91\xAB\xAE\xA6\xA5\xAD\xA8\xEF",                                                                                   // "Кукла Сложения",
			"\x8A\xE3\xAA\xAB\xA0 \x8C\xA5\xE2\xAA\xAE\xE1\xE2\xA8",                                                                                   // "Кукла Меткости",
			"\x8A\xE3\xAA\xAB\xA0 \x93\xA4\xA0\xE7\xA8",                                                                                               // "Кукла Удачи",
			"\x93\xE1\xE2\xE0\xAE\xA9\xE1\xE2\xA2\xAE",                                                                                                // "Устройство",
			"Pass to Castleview",                                                                                                                      // "Pass to Castleview",
			"Pass to Sandcaster",                                                                                                                      // "Pass to Sandcaster",
			"Pass to Lakeside",                                                                                                                        // "Pass to Lakeside",
			"Pass to Necropolis",                                                                                                                      // "Pass to Necropolis",
			"Pass to Olympus",                                                                                                                         // "Pass to Olympus",
			"Key to Great Western Tower",                                                                                                              // "Key to Great Western Tower",
			"Key to Great Southern Tower",                                                                                                             // "Key to Great Southern Tower",
			"Key to Great Eastern Tower",                                                                                                              // "Key to Great Eastern Tower",
			"Key to Great Northern Tower",                                                                                                             // "Key to Great Northern Tower",
			"Key to Ellinger's Tower",                                                                                                                 // "Key to Ellinger's Tower",
			"Key to Dragon Tower",                                                                                                                     // "Key to Dragon Tower",
			"Key to Darkstone Tower",                                                                                                                  // "Key to Darkstone Tower",
			"Key to Temple of Bark",                                                                                                                   // "Key to Temple of Bark",
			"Key to Dungeon of Lost Souls",                                                                                                            // "Key to Dungeon of Lost Souls",
			"Key to Ancient Pyramid",                                                                                                                  // "Key to Ancient Pyramid",
			"Key to Dungeon of Death",                                                                                                                 // "Key to Dungeon of Death",
			"Amulet of the Southern Sphinx",                                                                                                           // "Amulet of the Southern Sphinx",
			"Dragon Pharoah's Orb",                                                                                                                    // "Dragon Pharoah's Orb",
			"Cube of Power",                                                                                                                           // "Cube of Power",
			"Chime of Opening",                                                                                                                        // "Chime of Opening",
			"Gold ID Card",                                                                                                                            // "Gold ID Card",
			"Silver ID Card",                                                                                                                          // "Silver ID Card",
			"Vulture Repellant",                                                                                                                       // "Vulture Repellant",
			"Bridle",                                                                                                                                  // "Bridle",
			"Enchanted Bridle",                                                                                                                        // "Enchanted Bridle",
			"Treasure Map (Goto E1 x1, y11)",                                                                                                          // "Treasure Map (Goto E1 x1, y11)",
			"",                                                                                                                                        // "",
			"Fake Map",                                                                                                                                // "Fake Map",
			"Onyx Necklace",                                                                                                                           // "Onyx Necklace",
			"Dragon Egg",                                                                                                                              // "Dragon Egg",
			"Tribble",                                                                                                                                 // "Tribble",
			"Golden Pegasus Statuette",                                                                                                                // "Golden Pegasus Statuette",
			"Golden Dragon Statuette",                                                                                                                 // "Golden Dragon Statuette",
			"Golden Griffin Statuette",                                                                                                                // "Golden Griffin Statuette",
			"Chalice of Protection",                                                                                                                   // "Chalice of Protection",
			"Jewel of Ages",                                                                                                                           // "Jewel of Ages",
			"Songbird of Serenity",                                                                                                                    // "Songbird of Serenity",
			"Sandro's Heart",                                                                                                                          // "Sandro's Heart",
			"Ector's Ring",                                                                                                                            // "Ector's Ring",
			"Vespar's Emerald Handle",                                                                                                                 // "Vespar's Emerald Handle",
			"Queen Kalindra's Crown",                                                                                                                  // "Queen Kalindra's Crown",
			"Caleb's Magnifying Glass",                                                                                                                // "Caleb's Magnifying Glass",
			"Soul Box",                                                                                                                                // "Soul Box",
			"Soul Box with Corak inside",                                                                                                              // "Soul Box with Corak inside",
			"Ruby Rock",                                                                                                                               // "Ruby Rock",
			"Emerald Rock",                                                                                                                            // "Emerald Rock",
			"Sapphire Rock",                                                                                                                           // "Sapphire Rock",
			"Diamond Rock",                                                                                                                            // "Diamond Rock",
			"Monga Melon",                                                                                                                             // "Monga Melon",
			"Energy Disk"                                                                                                                              // "Energy Disk"
		};
		return _questItemNames;
	}

	const char **QUEST_ITEM_NAMES_SWORDS() {
		delete[] _questItemNamesSwords;
		_questItemNamesSwords = new const char *[51] {
			"Pass to Hart", "Pass to Impery", "Pass to town3", "Pass to town4", "Pass to town5",
				"Key to Hart Sewers", "Key to Rettig's Pyramid", "Key to the Old Temple",
				"Key to Canegtut's Pyramid", "Key to Ascihep's Pyramid", "Key to Dragon Tower",
				"Key to Darkstone Tower", "Key to Temple of Bark", "Key to Dungeon of Lost Souls",
				"Key to Ancient Pyramid", "Key to Dungeon of Death", "Red Magic Hammer",
				"Green Magic Hammer", "Golden Magic Wand", "Silver Magic Hammer", "Magic Coin",
				"Ruby", "Diamond Mineral", "Emerald", "Sapphire", "Treasure Map (Goto E1 x1, y11)",
				"NOTUSED", "Melon", "Princess Crown", "Emerald Wand", "Druid Carving", "High Sign",
				"Holy Wheel", "Double Cross", "Sky Hook", "Sacred Cow", "Staff of the Mountain",
				"Hard Rock", "Soft Rock", "Rock Candy", "Ivy Plant", "Spirit Gem", "Temple of Sun holy lamp oil",
				"Noams Hammer", "Positive Orb", "Negative Orb", "FireBane Staff", "Diamond Edged Pick",
				"Monga Melon", "Energy Disk", "Old XEEN Quest Item"
		};
		return _questItemNamesSwords;
	}

	const char *NOT_PROFICIENT() {
		return "\t000\v007\x3""c%s \xAD\xA5 \xAC\xAE\xA6\xA5\xE2 \xA8\xE1\xAF\xAE\xAB\xEC\xA7\xAE\xA2\xA0\xE2\xEC %s!"; // "\t000\v007\x3""c%s не может использовать %s!"
	}

	const char *NO_ITEMS_AVAILABLE() {
		return "\x3""c\n\t000\x8D\xA5\xE2 \xA2\xA5\xE9\xA5\xA9."; // "\x3""c\n\t000Нет вещей."
	}

	const char **CATEGORY_NAMES() {
		delete[] _categoryNames;
		_categoryNames = new const char *[4] { "\x8E\xE0\xE3\xA6\xA8\xA5", "\x81\xE0\xAE\xAD\xEF", "\x93\xAA\xE0\xA0\xE8\xA5\xAD\xA8\xEF", "\x90\xA0\xA7\xAD\xAE\xA5" }; // "Оружие", "Броня", "Украшения", "Разное"
		return _categoryNames;
	}

	const char *X_FOR_THE_Y() {
		return "\x1\fd\r%s\v000\t000%s - %s %s%s\v011\x2%s%s%s%s%s%s%s%s%s\x1\fd";
	}

	const char *X_FOR_Y() {
		return "\x1\fd\r\x3"
			   "l\v000\t000%s - %s\x3"
			   "r\t000%s\x3"
			   "l\v011"
			   "\x2%s%s%s%s%s%s%s%s%s\x1\fd";
	}

	const char *X_FOR_Y_GOLD() {
		return "\x1\fd\r\x3""l\v000\t000%s - %s\t150\x87\xAE\xAB\xAE\xE2\xAE - %lu%s\x3""l\v011" // "\x1\fd\r\x3""l\v000\t000%s - %s\t150Золото - %lu%s\x3""l\v011"
			   "\x2%s%s%s%s%s%s%s%s%s\x1\fd";                                                    // "\x2%s%s%s%s%s%s%s%s%s\x1\fd";
	}

	const char *FMT_CHARGES() {
		return "\x3""r\t000\x87\xA0\xE0\xEF\xA4\xAE\xA2\x3""l"; // "\x3""r\t000Зарядов\x3""l"
	}

	const char *AVAILABLE_GOLD_COST() {
		return "\x1\fd\r\x3""l\v000\t000%s\t150\x87\xAE\xAB\xAE\xE2\xAE - %lu\x3""r\t000\x96\xA5\xAD\xA0" // "\x1\fd\r\x3""l\v000\t000%s\t150Золото - %lu\x3""r\t000Цена"
			   "\x3""l\v011\x2%s%s%s%s%s%s%s%s%s\x1\fd";												  // "\x3""l\v011\x2%s%s%s%s%s%s%s%s%s\x1\fd";
	}

	const char *CHARGES() {
		return "\x87\xA0\xE0\xEF\xA4\xAE\xA2"; // "Зарядов"
	}

	const char *COST() {
		return "\x96\xA5\xAD\xA0"; // "Цена"
	}

	const char **ITEM_ACTIONS() {
		delete[] _itemActions;
		_itemActions = new const char *[7] {
			"\xAD\xA0\xA4\xA5\xE2\xEC", "\xE1\xAD\xEF\xE2\xEC", "\xA8\xE1\xAF\xAE\xAB\xEC\xA7\xAE\xA2\xA0\xE2\xEC", "\xA2\xEB\xAA\xA8\xAD\xE3\xE2\xEC", "\xA7\xA0\xE7\xA0\xE0\xAE\xA2\xA0\xE2\xEC", "\xAF\xA5\xE0\xA5\xA7\xA0\xE0\xEF\xA4\xA8\xE2\xEC", // "надеть", "снять", "использовать", "выкинуть", "зачаровать", "перезарядить",
			"\x8F\xE0\xA5\xA2\xE0\xA0\xE2\xA8\xE2\xEC \xA2 \xA7\xAE\xAB\xAE\xE2\xAE"                                                                                                                                                                    // "Превратить в золото"
		};
		return _itemActions;
	}

	const char *WHICH_ITEM() {
		return "\v000\x8A\xA0\xAA\xAE\xA9 \xAF\xE0\xA5\xA4\xAC\xA5\xE2 \xA2\xEB \xA6\xA5\xAB\xA0\xA5\xE2\xA5 %s?"; // "\v000Какой предмет вы желаете %s?"
	}

	const char *WHATS_YOUR_HURRY() {
		return "\v007\x97\xA5\xA3\xAE \xE2\xAE\xE0\xAE\xAF\xA8\xE8\xEC\xE1\xEF?\n"															 // "\v007Чего торопишься?\n"
			   "\x8F\xAE\xA4\xAE\xA6\xA4\xA8, \xAF\xAE\xAA\xA0 \xAD\xA5 \xA2\xEB\xA1\xA5\xE0\xA5\xE8\xEC\xE1\xEF \xA2\xE2\xE1\xEE\xA4\xA0!"; // "Подожди, пока не выберешься отсюда!";
	}

	const char *USE_ITEM_IN_COMBAT() {
		return "\v007\x97\xE2\xAE\xA1\xEB \xA8\xE1\xAF\xAE\xAB\xEC\xA7\xAE\xA2\xA0\xE2\xEC \xAF\xE0\xA5\xA4\xAC\xA5\xE2 \xA2 \xA1\xA8\xE2\xA2\xA5, \xAD\xA0\xA6\xAC\xA8\xE2\xA5 \xAD\xA0 \xAA\xAD\xAE\xAF\xAA\xE3 '\x88\xE1\xAF' \xAD\xA0 \xA1\xAE\xAA\xAE\xA2\xAE\xA9 \xAF\xA0\xAD\xA5\xAB\xA8."; // "\v007Чтобы использовать предмет в битве, нажмите на кнопку 'Исп' на боковой панели."
	}

	const char *NO_SPECIAL_ABILITIES() {
		return "\v005\x3""c%s\fd\xAD\xA5 \xA8\xAC\xA5\xA5\xE2 \xAE\xE1\xAE\xA1\xEB\xE5 \xE1\xA2\xAE\xA9\xE1\xE2\xA2!"; // "\v005\x3""c%s\fdне имеет особых свойств!"
	}

	const char *CANT_CAST_WHILE_ENGAGED() {
		return "\x3""c\v007\x87\xA0\xAA\xAB\xA8\xAD\xA0\xAD\xA8\xA5 %s \xAD\xA5\xAB\xEC\xA7\xEF \xA8\xE1\xAF\xAE\xAB\xEC\xA7\xAE\xA2\xA0\xE2\xEC \xA2 \xA1\xA8\xE2\xA2\xA5!"; // "\x3""c\v007Заклинание %s нельзя использовать в битве!"
	}

	const char *EQUIPPED_ALL_YOU_CAN() {
		return "\x3""c\v007\x82\xEB \xAD\xA5 \xAC\xAE\xA6\xA5\xE2\xA5 \xAD\xA0\xA4\xA5\xE2\xEC \xA1\xAE\xAB\xEC\xE8\xA5 \xA4\xA2\xE3\xE5 %s!"; // "\x3""c\v007Вы не можете надеть больше двух %s!"
	}

	const char *REMOVE_X_TO_EQUIP_Y() {
		return "\x3""c\v007\x82\xA0\xAC \xAD\xE3\xA6\xAD\xAE \xE1\xAD\xEF\xE2\xEC %s\xE7\xE2\xAE\xA1\xEB \xAD\xA0\xA4\xA5\xE2\xEC %s\b!"; // "\x3""c\v007Вам нужно снять %sчтобы надеть %s\b!"
	}

	const char *RING() {
		return "\xAA\xAE\xAB\xA5\xE6"; // "колец"
	}

	const char *MEDAL() {
		return "\xAC\xA5\xA4\xA0\xAB\xA5\xA9"; // "медалей"
	}

	const char *CANNOT_REMOVE_CURSED_ITEM() {
		return "\x3""c\x82\xEB \xAD\xA5 \xAC\xAE\xA6\xA5\xE2\xA5 \xE1\xAD\xEF\xE2\xEC \xAF\xE0\xAE\xAA\xAB\xEF\xE2\xE3\xEE \xA2\xA5\xE9\xEC!"; // "\x3""cВы не можете снять проклятую вещь!"
	}

	const char *CANNOT_DISCARD_CURSED_ITEM() {
		return "\x3""c\x82\xEB \xAD\xA5 \xAC\xAE\xA6\xA5\xE2\xA5 \xA2\xEB\xAA\xA8\xAD\xE3\xE2\xEC \xAF\xE0\xAE\xAA\xAB\xEF\xE2\xE3\xEE \xA2\xA5\xE9\xEC!"; // "\x3""cВы не можете выкинуть проклятую вещь!"
	}

	const char *PERMANENTLY_DISCARD() {
		return "\v000\t000\x3""l\x82\xEB\xAA\xA8\xAD\xE3\xE2\xEC \xAD\xA0\xA2\xE1\xA5\xA3\xA4\xA0? %s"; // "\v000\t000\x3""lВыкинуть навсегда? %s"
	}

	const char *BACKPACK_IS_FULL() {
		return "\v005\x3""c\fd%s! \x82\xA0\xE8 \xE0\xEE\xAA\xA7\xA0\xAA \xAF\xAE\xAB\xAE\xAD."; // "\v005\x3""c\fd%s! Ваш рюкзак полон."
	}

	const char **CATEGORY_BACKPACK_IS_FULL() {
		delete[] _categoryBackpackIsFull;
		_categoryBackpackIsFull = new const char *[4] {
			"\v010\t000\x3""c%s! \x82\xA0\xE8 \xE0\xEE\xAA\xA7\xA0\xAA \xAF\xAE\xAB\xAE\xAD.", // "\v010\t000\x3""c%s! Ваш рюкзак полон.",
			"\v010\t000\x3""c%s! \x82\xA0\xE8 \xE0\xEE\xAA\xA7\xA0\xAA \xAF\xAE\xAB\xAE\xAD.", // "\v010\t000\x3""c%s! Ваш рюкзак полон.",
			"\v010\t000\x3""c%s! \x82\xA0\xE8 \xE0\xEE\xAA\xA7\xA0\xAA \xAF\xAE\xAB\xAE\xAD.", // "\v010\t000\x3""c%s! Ваш рюкзак полон.",
			"\v010\t000\x3""c%s! \x82\xA0\xE8 \xE0\xEE\xAA\xA7\xA0\xAA \xAF\xAE\xAB\xAE\xAD."  // "\v010\t000\x3""c%s! Ваш рюкзак полон."
		};
		return _categoryBackpackIsFull;
	}

	const char *BUY_X_FOR_Y_GOLD() {
		return "\x3""l\v000\t000\fd\x8A\xE3\xAF\xA8\xE2\xEC %s\fd\n\xA7\xA0 %lu %s?"; // "\x3""l\v000\t000\fdКупить %s\fd\nза %lu %s?"
	}

	const char *SELL_X_FOR_Y_GOLD() {
		return "\x3""l\v000\t000\fd\x8F\xE0\xAE\xA4\xA0\xE2\xEC %s\fd\n\xA7\xA0 %lu %s?"; // "\x3""l\v000\t000\fdПродать %s\fd\nза %lu %s?"
	}

	const char **GOLDS() {
		delete[] _sellXForYGoldEndings;
		_sellXForYGoldEndings = new const char *[2] { "\xA7\xAE\xAB\xAE\xE2\xAE\xA9", "\xA7\xAE\xAB\xAE\xE2\xEB\xE5" }; // "золотой", "золотых"
		return _sellXForYGoldEndings;
	}

	const char *NO_NEED_OF_THIS() {
		return "\v005\x3""c\fd\x8D\xA0\xE1 \xAD\xA5 \xA8\xAD\xE2\xA5\xE0\xA5\xE1\xE3\xA5\xE2 %s\fd!"; // "\v005\x3""c\fdНас не интересует %s\fd!"
	}

	const char *NOT_RECHARGABLE() {
		return "\v007\x3""c\fd\x8D\xA5\xA2\xAE\xA7\xAC\xAE\xA6\xAD\xAE \xAF\xA5\xE0\xA5\xA7\xA0\xE0\xEF\xA4\xA8\xE2\xEC.\n%s"; // "\v007\x3""c\fdНевозможно перезарядить.\n%s"
	}

	const char *NOT_ENCHANTABLE() {
		return "\v007\t000\x3""c\x8D\xA5\xA2\xAE\xA7\xAC\xAE\xA6\xAD\xAE \xA7\xA0\xE7\xA0\xE0\xAE\xA2\xA0\xE2\xEC.\n%s"; // "\v007\t000\x3""cНевозможно зачаровать.\n%s"
	}

	const char *SPELL_FAILED() {
		return "\x87\xA0\xAA\xAB\xA8\xAD\xA0\xAD\xA8\xA5 \xAD\xA5 \xE1\xE0\xA0\xA1\xAE\xE2\xA0\xAB\xAE!"; // "Заклинание не сработало!"
	}

	const char *ITEM_NOT_BROKEN() {
		return "\fd\x9D\xE2\xAE\xE2 \xAF\xE0\xA5\xA4\xAC\xA5\xE2 \xAD\xA5 \xE1\xAB\xAE\xAC\xA0\xAD!"; // "\fdЭтот предмет не сломан!"
	}

	const char **FIX_IDENTIFY() {
		delete[] _fixIdentify;
		_fixIdentify = new const char *[2] { "\x8F\xAE\xE7\xA8\xAD\xA8\xE2\xEC", "\x8E\xAF\xAE\xA7\xAD\xA0\xE2\xEC" }; // "Починить", "Опознать"
		return _fixIdentify;
	}

	const char *FIX_IDENTIFY_GOLD() {
		return "\x3""l\v000\t000%s %s\fd \xA7\xA0 %lu \xA7\xAE\xAB\xAE\xE2%s?"; // "\x3""l\v000\t000%s %s\fd за %lu золот%s?"
	}

	const char *IDENTIFY_ITEM_MSG() {
		return "\fd\v000\t000\x3""c\x8E\xAF\xAE\xA7\xAD\xA0\xE2\xEC \xAF\xE0\xA5\xA4\xAC\xA5\xE2\x3""l\n" // "\fd\v000\t000\x3""cОпознать предмет\x3""l\n"
			   "\n"                                                                                       // "\n"
			   "\v012%s\fd\n"                                                                             // "\v012%s\fd\n"
			   "\n"                                                                                       // "\n"
			   "%s";                                                                                      // "%s";
	}

	const char *ITEM_DETAILS() {
		return "\x88\xE1\xAF\xAE\xAB\xEC\xA7\xE3\xEE\xE2 \xAA\xAB\xA0\xE1\xE1\xEB\t132:\t140%s\n" // "Используют классы\t132:\t140%s\n"
			   "\x8C\xAE\xA4\xA8\xE4\xA8\xAA\xA0\xE2\xAE\xE0 \xE3\xE0\xAE\xAD\xA0\t132:\t140%s\n" // "Модификатор урона\t132:\t140%s\n"
			   "\x94\xA8\xA7\xA8\xE7\xA5\xE1\xAA\xA8\xA9 \xE3\xE0\xAE\xAD\t132:\t140%s\n"         // "Физический урон\t132:\t140%s\n"
			   "\x93\xE0\xAE\xAD \xAE\xE2 \x91\xE2\xA8\xE5\xA8\xA9\t132:\t140%s\n"                // "Урон от Стихий\t132:\t140%s\n"
			   "\x87\xA0\xE9\xA8\xE2\xA0 \xAE\xE2 \x91\xE2\xA8\xE5\xA8\xA9\t132:\t140%s\n"        // "Защита от Стихий\t132:\t140%s\n"
			   "\x8A\xAB\xA0\xE1\xE1 \xA7\xA0\xE9\xA8\xE2\xEB\t132:\t140%s\n"                     // "Класс защиты\t132:\t140%s\n"
			   "\x81\xAE\xAD\xE3\xE1 \xE1\xA2\xAE\xA9\xE1\xE2\xA2\xA0\t132:\t140%s\n"             // "Бонус свойства\t132:\t140%s\n"
			   "\x8E\xE1\xAE\xA1\xAE\xA5 \xE1\xA2\xAE\xA9\xE1\xE2\xA2\xAE\t132:\t140%s";          // "Особое свойство\t132:\t140%s";
	}

	const char *ALL() {
		return "\x82\xE1\xA5"; // "Все"
	}

	const char *FIELD_NONE() {
		return "\x8D\xA5\xE2"; // "Нет"
	}

	const char *DAMAGE_X_TO_Y() {
		return "%d-%d";
	}

	const char *ELEMENTAL_XY_DAMAGE() {
		return "%+d \xE3\xE0\xAE\xAD\xA0 \xAE\xE2 %s"; // %+d урона от %s"
	}

	const char *ATTR_XY_BONUS() {
		return "%+d %s";
	}

	const char *EFFECTIVE_AGAINST() {
		return "x3 \xAF\xE0\xAE\xE2\xA8\xA2 %s"; // "x3 против %s"
	}

	const char *QUESTS_DIALOG_TEXT() {
		return "\r\x2\x3""c\v021\t017\f37\x82\fd\xA5\xE9\xA8\t085\f37\x87\fd\xA0\xA4\xA0\xAD\xA8\xEF\t153" // "\r\x2\x3""c\v021\t017\f37В\fdещи\t085\f37З\fdадания\t153"
			   "\x87\f37\xA0\fd\xAC\xA5\xE2\xAA\xA8\t221\x82\xA2\xA5\xE0\xE5\t255\x82\xAD\xA8\xA7"         // "З\f37а\fdметки\t221Вверх\t255Вниз"
			   "\t289\x82\xEB\xE5\xAE\xA4";                                                                // "\t289Выход";
	}

	const char *CLOUDS_OF_XEEN_LINE() {
		return "\b \b*-- \f04\x8E\xA1\xAB\xA0\xAA\xA0 \x8A\xE1\xA8\xAD\xA0\fd --"; // "\b \b*-- \f04Облака Ксина\fd --"
	}

	const char *DARKSIDE_OF_XEEN_LINE() {
		return "\b \b*-- \f04Darkside of Xeen\fd --";
	}

	const char *SWORDS_OF_XEEN_LINE() {
		return "\b \b*-- \f04Swords of Xeen\fd --";
	}

	const char *NO_QUEST_ITEMS() {
		return "\r\x1\fd\x3""c\v000\t000\x8F\xE0\xA5\xA4\xAC\xA5\xE2\xEB \xA7\xA0\xA4\xA0\xAD\xA8\xA9\x3""l\x2\n" // "\r\x1\fd\x3""c\v000\t000Предметы заданий\x3""l\x2\n"
			   "\n"                                                                                               // "\n"
			   "\x3""c\x8D\xA5\xE2 \xAF\xE0\xA5\xA4\xAC\xA5\xE2\xAE\xA2";                                         // "\x3""cНет предметов";
	}

	const char *NO_CURRENT_QUESTS() {
		return "\x3""c\v000\t000\n"							// "\x3""c\v000\t000\n"
			   "\n"                                         // "\n"
			   "\x8D\xA5\xE2 \xA7\xA0\xA4\xA0\xAD\xA8\xA9"; // "Нет заданий";
	}

	const char *NO_AUTO_NOTES() {
		return "\x3""c\x87\xA0\xAC\xA5\xE2\xAE\xAA \xAD\xA5\xE2"; // "\x3""cЗаметок нет"
	}

	const char *QUEST_ITEMS_DATA() {
		return "\r\x1\fd\x3""c\v000\t000\x8F\xE0\xA5\xA4\xAC\xA5\xE2\xEB \xA7\xA0\xA4\xA0\xAD\xA8\xA9\x3""l\x2\n" // "\r\x1\fd\x3""c\v000\t000Предметы заданий\x3""l\x2\n"
			   "\f04 * \fd%s\n"                                                                                   // "\f04 * \fd%s\n"
			   "\f04 * \fd%s\n"                                                                                   // "\f04 * \fd%s\n"
			   "\f04 * \fd%s\n"                                                                                   // "\f04 * \fd%s\n"
			   "\f04 * \fd%s\n"                                                                                   // "\f04 * \fd%s\n"
			   "\f04 * \fd%s\n"                                                                                   // "\f04 * \fd%s\n"
			   "\f04 * \fd%s\n"                                                                                   // "\f04 * \fd%s\n"
			   "\f04 * \fd%s\n"                                                                                   // "\f04 * \fd%s\n"
			   "\f04 * \fd%s\n"                                                                                   // "\f04 * \fd%s\n"
			   "\f04 * \fd%s";                                                                                    // "\f04 * \fd%s";
	}

	const char *CURRENT_QUESTS_DATA() {
		return "\r\x1\fd\x3""c\t000\v000\x87\xA0\xA4\xA0\xAD\xA8\xEF\x3""l\x2\n" // "\r\x1\fd\x3""c\t000\v000Задания\x3""l\x2\n"
			   "%s\n"                                                            // "%s\n"
			   "\n"                                                              // "\n"
			   "%s\n"                                                            // "%s\n"
			   "\n"                                                              // "\n"
			   "%s";                                                             // "%s";
	}

	const char *AUTO_NOTES_DATA() {
		return "\r\x1\fd\x3""c\t000\v000\x87\xA0\xAC\xA5\xE2\xAA\xA8\x3""l\x2\n" // "\r\x1\fd\x3""c\t000\v000Заметки\x3""l\x2\n"
			   "%s\x3""l\n"														 // "%s\x3""l\n"
			   "%s\x3""l\n"														 // "%s\x3""l\n"
			   "%s\x3""l\n"														 // "%s\x3""l\n"
			   "%s\x3""l\n"														 // "%s\x3""l\n"
			   "%s\x3""l\n"														 // "%s\x3""l\n"
			   "%s\x3""l\n"														 // "%s\x3""l\n"
			   "%s\x3""l\n"														 // "%s\x3""l\n"
			   "%s\x3""l\n"														 // "%s\x3""l\n"
			   "%s\x3""l";														 // "%s\x3""l";
	}

	const char *REST_COMPLETE() {
		return "\v000\t000\x8F\xE0\xAE\xE8\xAB\xAE 8 \xE7\xA0\xE1\xAE\xA2. \x8E\xE2\xA4\xEB\xE5 \xA7\xA0\xAA\xAE\xAD\xE7\xA5\xAD\n" // "\v000\t000Прошло 8 часов. Отдых закончен\n"
			   "%s\n"                                                                                                               // "%s\n"
			   "\x81\xEB\xAB\xAE \xE1\xEA\xA5\xA4\xA5\xAD\xAE %d \xAF\xA8\xE9\xA8.";                                                // "Было съедено %d пищи.";
	}

	const char *PARTY_IS_STARVING() {
		return "\f07\x8E\xE2\xE0\xEF\xA4 \xA3\xAE\xAB\xAE\xA4\xA0\xA5\xE2!\fd"; // "\f07Отряд голодает!\fd"
	}

	const char *HIT_SPELL_POINTS_RESTORED() {
		return "\x87\xA4\xAE\xE0\xAE\xA2\xEC\xA5 \xA8 \xAC\xA0\xAD\xA0 \xA2\xAE\xE1\xE1\xE2\xA0\xAD\xAE\xA2\xAB\xA5\xAD\xEB"; // "Здоровье и мана восстановлены"
	}

	const char *TOO_DANGEROUS_TO_REST() {
		return "\x87\xA4\xA5\xE1\xEC \xE1\xAB\xA8\xE8\xAA\xAE\xAC \xAE\xAF\xA0\xE1\xAD\xAE \xAE\xE2\xA4\xEB\xE5\xA0\xE2\xEC!"; // "Здесь слишком опасно отдыхать!"
	}

	const char *SOME_CHARS_MAY_DIE() {
		return "\x8A\xE2\xAE-\xE2\xAE \xA8\xA7 \xAE\xE2\xE0\xEF\xA4\xA0 \xAC\xAE\xA6\xA5\xE2 \xE3\xAC\xA5\xE0\xA5\xE2\xEC. \x82\xEB \xA2\xE1\xF1 \xE0\xA0\xA2\xAD\xAE \xA6\xA5\xAB\xA0\xA5\xE2\xA5 \xAE\xE2\xA4\xAE\xE5\xAD\xE3\xE2\xEC?"; // "Кто-то из отряда может умереть. Вы всё равно желаете отдохнуть?"
	}

	const char *DISMISS_WHOM() {
		return "\r\t010\v005\x8A\xAE\xA3\xAE \xA2\xEB\xA3\xAD\xA0\xE2\xEC?"; // "\r\t010\v005Кого выгнать?"
	}

	const char *CANT_DISMISS_LAST_CHAR() {
		return "\x82\xEB \xAD\xA5 \xAC\xAE\xA6\xA5\xE2\xA5 \xA2\xEB\xA3\xAD\xA0\xE2\xEC \xE1\xA2\xAE\xA5\xA3\xAE \xAF\xAE\xE1\xAB\xA5\xA4\xAD\xA5\xA3\xAE \xAF\xA5\xE0\xE1\xAE\xAD\xA0\xA6\xA0!"; // "Вы не можете выгнать своего последнего персонажа!"
	}

	const char *DELETE_CHAR_WITH_ELDER_WEAPON() {
		return "\v000\t000This character has an Elder Weapon and cannot be deleted!";
	}

	const char **REMOVE_DELETE() {
		delete[] _removeDelete;
		_removeDelete = new const char *[2] { "\x82\xEB\xA3\xAD\xA0\xE2\xEC", "\xE3\xA4\xA0\xAB\xA8\xE2\xEC" }; // "Выгнать", "удалить"
		return _removeDelete;
	}

	const char *REMOVE_OR_DELETE_WHICH() {
		return "\x3""l\t010\v005\x8A\xAE\xA3\xAE %s?"; // "\x3""l\t010\v005Кого %s?"
	}

	const char *YOUR_PARTY_IS_FULL() {
		return "\v007\x82\xA0\xE8 \xAE\xE2\xE0\xEF\xA4 \xAF\xAE\xAB\xAE\xAD!"; // "\v007Ваш отряд полон!"
	}

	const char *HAS_SLAYER_SWORD() {
		return "\v000\t000\x9D\xE2\xAE\xE2 \xAF\xA5\xE0\xE1\xAE\xAD\xA0\xA6 \xAD\xA5 \xAC\xAE\xA6\xA5\xE2 \xA1\xEB\xE2\xEC \xE3\xA4\xA0\xAB\xF1\xAD, \xE2\xA0\xAA \xAA\xA0\xAA \xE3 \xAD\xA5\xA3\xAE \x8C\xA5\xE7-\xE3\xA1\xA8\xA9\xE6\xA0 \x8A\xE1\xA8\xAD\xA0!"; // "\v000\t000Этот персонаж не может быть удалён, так как у него Меч-убийца Ксина!"
	}

	const char *SURE_TO_DELETE_CHAR() {
		return "%s %s. \x82\xEB \xE3\xA2\xA5\xE0\xA5\xAD\xEB, \xE7\xE2\xAE \xE5\xAE\xE2\xA8\xE2\xA5 \xE3\xA4\xA0\xAB\xA8\xE2\xEC \xED\xE2\xAE\xA3\xAE \xA3\xA5\xE0\xAE\xEF?"; // "%s %s. Вы уверены, что хотите удалить этого героя?"
	}

	const char *CREATE_CHAR_DETAILS() {
		return "\f04\x3""c\x2\t144\v119\f37\x81\f04\xE0\xAE\xE1\xAE\xAA\t144\v149\f37\x91\f04\xAE\xA7\xA4"		// "\f04\x3""c\x2\t144\v119\f37Б\f04росок\t144\v149\f37С\f04озд"
			   "\t144\v179\f37ESC\f04\x3""l\x1\t195\v021\x91\xA8\f37\xAB\f04"									// "\t144\v179\f37ESC\f04\x3""l\x1\t195\v021Си\f37л\f04"
			   "\t195\v045\f37\x88\f04\xAD\xE2\t195\v069\f37\x84\f04\xE3\xE5\t195\v093\x91\xAB\f37\xA6\f04"		// "\t195\v045\f37И\f04нт\t195\v069\f37Д\f04ух\t195\v093Сл\f37ж\f04"
			   "\t195\v116\x91\f37\xAA\f04\xE0\t195\v140\f37\x8C\f04\xE2\xAA\t195\v164\f37\x93\f04\xA4\xE7%s";	// "\t195\v116С\f37к\f04р\t195\v140\f37М\f04тк\t195\v164\f37У\f04дч%s";
	}

	const char *NEW_CHAR_STATS() {
		return "\f04\x3""l\t017\v148\x90\xA0\xE1\xA0\t055: %s\n"																			// "\f04\x3""l\t017\v148Раса\t055: %s\n"
			   "\t017\x8F\xAE\xAB\t055: %s\n"																								// "\t017Пол\t055: %s\n"
			   "\t017\x8A\xAB\xA0\xE1\xE1\t055:\n"																							// "\t017Класс\t055:\n"
			   "\x3""r\t215\v031%d\t215\v055%d\t215\v079%d\t215\v103%d\t215\v127%d"															// "\x3""r\t215\v031%d\t215\v055%d\t215\v079%d\t215\v103%d\t215\v127%d"
			   "\t215\v151%d\t215\v175%d\x3""l\t242\v020\f%2d\x90\xEB\xE6\xA0\xE0\xEC\t242\v031\f%2d"										// "\t215\v151%d\t215\v175%d\x3""l\t242\v020\f%2dРыцарь\t242\v031\f%2d"
			   "\x8F\xA0\xAB\xA0\xA4\xA8\xAD\t242\v042\f%2d\x8B\xE3\xE7\xAD\xA8\xAA\t242\v053\f%2d\x8A\xAB\xA8\xE0\xA8\xAA\t242\v064\f%2d"	// "Паладин\t242\v042\f%2dЛучник\t242\v053\f%2dКлирик\t242\v064\f%2d"
			   "\x8C\xA0\xA3\t242\v075\f%2d\x82\xAE\xE0\t242\v086\f%2d\x8D\xA8\xAD\xA4\xA7\xEF\t242\v097\f%2d"								// "Маг\t242\v075\f%2dВор\t242\v086\f%2dНиндзя\t242\v097\f%2d"
			   "\x82\xA0\xE0\xA2\xA0\xE0\t242\v108\f%2d\x84\xE0\xE3\xA8\xA4\t242\v119\f%2d\x91\xAB\xA5\xA4\xAE\xAF\xEB\xE2\f04\x3""c"		// "Варвар\t242\v108\f%2dДруид\t242\v119\f%2dСледопыт\f04\x3""c"
			   "\t265\v142\x8D\xA0\xA2\xEB\xAA\xA8\x2\x3""l\t223\v155%s\t223\v170%s%s\x1";													// "\t265\v142Навыки\x2\x3""l\t223\v155%s\t223\v170%s%s\x1";
	}

	const char *NAME_FOR_NEW_CHARACTER() {
		return "\x3""c\x82\xA2\xA5\xA4\xA8\xE2\xA5 \xA8\xAC\xEF \xAF\xA5\xE0\xE1\xAE\xAD\xA0\xA6\xA0\n\n"; // "\x3""cВведите имя персонажа\n\n"
	}

	const char *SELECT_CLASS_BEFORE_SAVING() {
		return "\v003\x3""c\x8F\xA5\xE0\xA5\xA4 \xE1\xAE\xE5\xE0\xA0\xAD\xA5\xAD\xA8\xA5\xAC \xA2\xEB\xA1\xA5\xE0\xA8\xE2\xA5 \xAA\xAB\xA0\xE1\xE1.\x3""l"; // "\v003\x3""cПеред сохранением выберите класс.\x3""l"
	}

	const char *EXCHANGE_ATTR_WITH() {
		return "\x8F\xAE\xAC\xA5\xAD\xEF\xE2\xEC %s \xE1..."; // "Поменять %s с..."
	}

	const char *COMBAT_DETAILS() {
		return "\r\f00\x3""c\v000\t000\x2%s%s%s\x1"; // "\r\f00\x3""c\v000\t000\x2%s%s%s\x1"
	}

	const char *NOT_ENOUGH_TO_CAST() {
		return "\x3""c\v000\x8D\xA5\xA4\xAE\xE1\xE2\xA0\xE2\xAE\xE7\xAD\xAE %s, \xE7\xE2\xAE\xA1\xEB \xA7\xA0\xAA\xAB\xA8\xAD\xA0\xE2\xEC %s"; // "\x3""c\v000Недостаточно %s, чтобы заклинать %s"
	}

	const char **SPELL_CAST_COMPONENTS() {
		delete[] _spellCastComponents;
		_spellCastComponents = new const char *[2] { "\xAE\xE7\xAA\xAE\xA2 \xAC\xA0\xA3\xA8\xA8", "\xA0\xAB\xAC\xA0\xA7\xAE\xA2" }; // "очков магии", "алмазов"
		return _spellCastComponents;
	}

	const char *CAST_SPELL_DETAILS() {
		return "\r\x2\x3""c\v122\t013\f37\x87\fd\xA0\xAA\xAB\t040\f37\x8D\fd\xAE\xA2"  // "\r\x2\x3""c\v122\t013\f37З\fdакл\t040\f37Н\fdов"
			   "\t067ESC\x1\t000\v000\x3""c\x87\xA0\xAA\xAB\xA8\xAD\xA0\xAD\xA8\xA5\n" // "\t067ESC\x1\t000\v000\x3""cЗаклинание\n"
			   "\n"																	   // "\n"
			   "%s\x3""c\n"															   // "%s\x3""c\n"
			   "\n"																	   // "\n"
			   "     \x83\xAE\xE2\xAE\xA2\xAE\xA5:\x3""c\n"							   // "     Готовое:\x3""c\n"
			   "\n"																	   // "\n"
			   "\f09%s\fd\x2\x3""l\n"												   // "\f09%s\fd\x2\x3""l\n"
			   "\v082\x96\xA5\xAD\xA0\x3""r\t000%u/%u\x3""l\n"						   // "\v082Цена\x3""r\t000%u/%u\x3""l\n"
			   "\x92\xA5\xAA \x8E\x8C\x3""r\t000%u\x1";								   // "Тек ОМ\x3""r\t000%u\x1";
	}

	const char *PARTY_FOUND() {
		return "\x3""c\x8D\xA0\xA9\xA4\xA5\xAD\xAE:\n" // "\x3""cНайдено:\n"
			   "\n"									   // "\n"
			   "\x3""r\t000%lu \x87\xAE\xAB\n"		   // "\x3""r\t000%lu Зол\n"
			   "%lu \x80\xAB\xAC\xA7";				   // "%lu Алмз";
	}

	const char *BACKPACKS_FULL_PRESS_KEY() {
		return "\v007\f12\x82\xAD\xA8\xAC\xA0\xAD\xA8\xA5! \x90\xEE\xAA\xA7\xA0\xAA\xA8 \xAF\xA5\xE0\xA5\xAF\xAE\xAB\xAD\xA5\xAD\xEB!\fd\n" // "\v007\f12Внимание! Рюкзаки переполнены!\fd\n"
			   "\x8D\xA0\xA6\xAC\xA8\xE2\xA5 \xAA\xAB\xA0\xA2\xA8\xE8\xE3";                                                                 // "Нажмите клавишу";
	}

	const char *HIT_A_KEY() {
		return "\x3""l\v120\t000\x4""077\x3""c\f37\x8D. \xAA\xAB\xA0\xA2\xA8\xE8\xE3\fd"; // "\x3""l\v120\t000\x4""077\x3""c\f37Н. клавишу\fd"
	}

	const char *GIVE_TREASURE_FORMATTING() {
		return "\x3l\v060\t000\x4"
			   "077\n"
			   "\x4"
			   "077\n"
			   "\x4"
			   "077\n"
			   "\x4"
			   "077\n"
			   "\x4"
			   "077\n"
			   "\x4"
			   "077";
	}

	const char *X_FOUND_Y() {
		return "\v060\t000\x3""c%s \xAD\xA0\xE8%s: %s"; // "\v060\t000\x3""c%s наш%s: %s"
	}

	const char *ON_WHO() {
		return "\x3""c\v009\x8A\xAE\xA3\xAE?"; // "\x3""c\v009Кого?"
	}

	const char *WHICH_ELEMENT1() {
		return "\r\x3""c\x1\x8A\xA0\xAA\xA0\xEF \x91\xE2\xA8\xE5\xA8\xEF?\x2\v034\t014\f15\x8E\fd\xA3\xAE\xAD\xEC\t044" // "\r\x3""c\x1Какая Стихия?\x2\v034\t014\f15О\fdгонь\t044"
			   "\f15\x83\fd\xE0\xAE\xAC\t074\f15\x95\fd\xAE\xAB\xAE\xA4\t104\f15\x9F\fd\xA4\x1";					    // "\f15Г\fdром\t074\f15Х\fdолод\t104\f15Я\fdд\x1";
	}

	const char *WHICH_ELEMENT2() {
		return "\r\x3""c\x8A\xA0\xAA\xA0\xEF \x91\xE2\xA8\xE5\xA8\xEF?\x2\v034\t014\f15\x8E\fd\xA3\xAE\xAD\xEC\t044" // "\r\x3""cКакая Стихия?\x2\v034\t014\f15О\fdгонь\t044"
			   "\f15\x83\fd\xE0\xAE\xAC\t074\f15\x95\fd\xAE\xAB\xAE\xA4\t104\f15\x9F\fd\xA4\x1";					 // "\f15Г\fdром\t074\f15Х\fdолод\t104\f15Я\fdд\x1";
	}

	const char *DETECT_MONSTERS() {
		return "\x3""c\x8F\xAE\xA8\xE1\xAA \xAC\xAE\xAD\xE1\xE2\xE0\xAE\xA2"; // "\x3""cПоиск монстров"
	}

	const char *LLOYDS_BEACON() {
		return "\r\x3""c\v000\t000\x1\x8C\xA0\xEF\xAA \x8B\xAB\xAE\xA9\xA4\xA0\n"									   // "\r\x3""c\v000\t000\x1Маяк Ллойда\n"
			   "\n"																									   // "\n"
			   "\x8F\xAE\xE1\xAB\xA5\xA4\xAD\xA5\xA5 \xAC\xA5\xE1\xE2\xAE\n"										   // "Последнее место\n"
			   "\n"																									   // "\n"
			   "%s\x3""l\n"																							   // "%s\x3""l\n"
			   "x = %d\x3""r\t000y = %d\x3""c\x2\v122\t021\f15\x93\fd\xE1\xE2\xA0\xAD\t060\f15\x82\fd\xA5\xE0\xAD\x1"; // "x = %d\x3""r\t000y = %d\x3""c\x2\v122\t021\f15У\fdстан\t060\f15В\fdерн\x1";
	}

	const char *HOW_MANY_SQUARES() {
		return "\x3""c\x92\xA5\xAB\xA5\xAF\xAE\xE0\xE2\n\x91\xAA\xAE\xAB\xEC\xAA\xAE \xAA\xAB\xA5\xE2\xAE\xAA \xAD\xA0 %s (1-9)\n"; // "\x3""cТелепорт\nСколько клеток на %s (1-9)\n"
	}

	const char *TOWN_PORTAL() {
		return "\x3""c\x83\xAE\xE0\xAE\xA4\xE1\xAA\xAE\xA9 \xAF\xAE\xE0\xE2\xA0\xAB\x3""l\n" // "\x3""cГородской портал\x3""l\n"
			   "\n"																			 // "\n"
			   "\t0101. %s\n"																 // "\t0101. %s\n"
			   "\t0102. %s\n"																 // "\t0102. %s\n"
			   "\t0103. %s\n"																 // "\t0103. %s\n"
			   "\t0104. %s\n"																 // "\t0104. %s\n"
			   "\t0105. %s\x3"																 // "\t0105. %s\x3""c\n"
			   "c\n"																		 // "\n"
			   "\n"																			 // "В какой город (1-5)\n"
			   "\x82 \xAA\xA0\xAA\xAE\xA9 \xA3\xAE\xE0\xAE\xA4 (1-5)\n"						 // "\n";
			   "\n";																		 // 
	}

	const char *TOWN_PORTAL_SWORDS() {
		return "\x3"
			   "cTown Portal\x3l\n"
			   "\n"
			   "\t0101. %s\n"
			   "\t0102. %s\n"
			   "\t0103. %s\x3"
			   "c\n"
			   "\n"
			   "To which Town (1-3)\n"
			   "\n";
	}

	const char *MONSTER_DETAILS() {
		return "\x3l\n"
			   "%s\x3"
			   "c\t100%s\t140%u\t180%u\x3r\t000%s";
	}

	const char **MONSTER_SPECIAL_ATTACKS() {
		delete[] _monsterSpecialAttacks;
		_monsterSpecialAttacks = new const char *[23] {
			"\x8D\xA5\xE2", "\x8C\xA0\xA3\xA8\xEF", "\x8E\xA3\xAD\xEF", "\x83\xE0\xAE\xAC\xA0", "\x95\xAE\xAB\xAE\xA4\xA0", "\x8E\xE2\xE0\xA0\xA2\xAB\xA5\xAD\xA8\xA5", "\x9D\xAD\xA5\xE0\xA3\xA8\xA8",								// "Нет", "Магия", "Огня", "Грома", "Холода", "Отравление", "Энергии",
			"\x81\xAE\xAB\xA5\xA7\xAD\xEC", "\x81\xA5\xA7\xE3\xAC\xA8\xA5", "\x91\xAE\xAD", "\x8F\xE0\xAA\xAB\x8F\xE0\xA4\xAC", "\x82\xAB\xEE\xA1\xAB", "\x8E\xE1\xE3\xE8\x87\xA4\xAE\xE0", "\x8F\xE0\xAE\xAA\xAB\xEF\xE2\xA8\xA5",	// "Болезнь", "Безумие", "Сон", "ПрклПрдм", "Влюбл", "ОсушЗдор", "Проклятие",
			"\x8F\xA0\xE0\xA0\xAB\xA8\xE7", "\x81\xA5\xE1\xE1\xAE\xA7\xAD", "\x91\xAC\xEF\xE2\xA5\xAD\xA8\xA5", "\x8B\xAE\xAC\x81\xE0\xAE\xAD", "\x91\xAB\xA0\xA1\xAE\xE1\xE2\xEC", "\x93\xAD\xA8\xE7\xE2\xAE\xA6",					// "Паралич", "Бессозн", "Смятение", "ЛомБрон", "Слабость", "Уничтож",
			"\x82\xAE\xA7\xE0\xA0\xE1\xE2+5", "\x8C\xA5\xE0\xE2\xA2", "\x8A\xA0\xAC\xA5\xAD\xEC"																																	// "Возраст+5", "Мертв", "Камень"
		};
		return _monsterSpecialAttacks;
	}

	const char *IDENTIFY_MONSTERS() {
		return "\x8C\xAE\xAD\xE1\xE2\xE0\x3""c\t155\x8E\x87\t195\x8A\x87\t233#\x80\xE2\xA0\xAA\x3""r\t000\x8E\xE1\xAE\xA1\xAE\xA5%s%s%s"; // "Монстр\x3""c\t155ОЗ\t195КЗ\t233#Атак\x3""r\t000Особое%s%s%s"
	}

	const char *MOONS_NOT_ALIGNED() {
		return "\x3""c\v012\t000\x8F\xAE\xAA\xA0 \xAB\xE3\xAD\xEB \xAD\xA5 \xA2\xE1\xE2\xA0\xAD\xE3\xE2 \xA2 \xE0\xEF\xA4, \xA2\xEB \xAD\xA5 \xE1\xAC\xAE\xA6\xA5\xE2\xA5 \xAF\xA5\xE0\xA5\xA9\xE2\xA8 \xAD\xA0 \x92\xF1\xAC\xAD\xE3\xEE \xE1\xE2\xAE\xE0\xAE\xAD\xE3 \x8A\xE1\xA8\xAD\xA0"; // "\x3""c\v012\t000Пока луны не встанут в ряд, вы не сможете перейти на Тёмную сторону Ксина"
	}

	const char *AWARDS_FOR() {
		return "\r\x1\fd\x3""c\v000\t000%s %s: \x8D\xA0\xA3\xE0\xA0\xA4\xEB \x3""l\x2\n" // "\r\x1\fd\x3""c\v000\t000%s %s: Награды \x3""l\x2\n"
			   "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\x1";									 // "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\x1";
	}

	const char *AWARDS_TEXT() {
		return "\r\x2\x3""c\v021\t221\x82\xA2\xA5\xE0\xE5\t255\x82\xAD\xA8\xA7\t289\x82\xEB\xE5\xAE\xA4"; // "\r\x2\x3""c\v021\t221Вверх\t255Вниз\t289Выход"
	}

	const char *NO_AWARDS() {
		return "\x3""c\x93 \xAF\xA5\xE0\xE1\xAE\xAD\xA0\xA6\xA0 \xAD\xA5\xE2 \xAD\xA0\xA3\xE0\xA0\xA4"; // "\x3""cУ персонажа нет наград"
	}

	const char *WARZONE_BATTLE_MASTER() {
		return "\x80\xE0\xA5\xAD\xA0\n\t125\x8C\xA0\xE1\xE2\xA5\xE0 \xA1\xA8\xE2\xA2\xEB"; // "Арена\n\t125Мастер битвы"
	}

	const char *WARZONE_MAXED() {
		return "\x97\xE2\xAE!  \x8E\xAF\xEF\xE2\xEC \xA2\xEB?  \x8D\xA5 \xAF\xE0\xA8\xE1\xE2\xA0\xA2\xA0\xA9\xE2\xA5 \xAA \xE2\xA5\xAC, \xAA\xE2\xAE \xAD\xA5 \xAC\xAE\xA6\xA5\xE2 \xA4\xA0\xE2\xEC \xE1\xA4\xA0\xE7\xA8!"; // "Что!  Опять вы?  Не приставайте к тем, кто не может дать сдачи!"
	}

	const char *WARZONE_LEVEL() {
		return "\x8A\xA0\xAA\xAE\xA9 \xE3\xE0\xAE\xA2\xA5\xAD\xEC \xAC\xAE\xAD\xE1\xE2\xE0\xAE\xA2? (1-10)\n"; // "Какой уровень монстров? (1-10)\n"
	}

	const char *WARZONE_HOW_MANY() {
		return "\x91\xAA\xAE\xAB\xEC\xAA\xAE \xAC\xAE\xAD\xE1\xE2\xE0\xAE\xA2? (1-20)\n"; // "Сколько монстров? (1-20)\n"
	}

	const char *PICKS_THE_LOCK() {
		return "\x3""c\v010%s \xA2\xA7\xAB\xAE\xAC\xA0\xAB%s \xA7\xA0\xAC\xAE\xAA!\n\x8D\xA0\xA6\xAC\xA8\xE2\xA5 \xAA\xAB\xA0\xA2\xA8\xE8\xE3."; // "\x3""c\v010%s взломал%s замок!\nНажмите клавишу."
	}

	const char *UNABLE_TO_PICK_LOCK() {
		return "\x3""c\v010%s \xAD\xA5 \xE1\xAC\xAE\xA3%s \xA2\xA7\xAB\xAE\xAC\xA0\xE2\xEC \xA7\xA0\xAC\xAE\xAA!\n\x8D\xA0\xA6\xAC\xA8\xE2\xA5 \xAA\xAB\xA0\xA2\xA8\xE8\xE3."; // "\x3""c\v010%s не смог%s взломать замок!\nНажмите клавишу."
	}

	const char *CONTROL_PANEL_TEXT() {
		return "\x1\f00\x3""c\v000\t000\x8F\xA0\xAD\xA5\xAB\xEC \xE3\xAF\xE0\xA0\xA2\xAB\xA5\xAD\xA8\xEF\x3""r" // "\x1\f00\x3""c\v000\t000Панель управления\x3""r"
			   "\v022\t045\f06\x87\fd\xA0\xA3\xE0:\t124\x87\xA2\f06\xE3\fd\xAA:"                                // "\v022\t045\f06З\fdагр:\t124Зв\f06у\fdк:"
			   "\v041\t045\f06\x91\fd\xAE\xE5\xE0:\t124\f06\x8C\fd\xE3\xA7.:"									// "\v041\t045\f06С\fdохр:\t124М\fdуз.:
			   "\v060\t045\f06\x82\fd\xEB\xE5\xAE\xA4"                                                          // "\v060\t045\f06В\fdыход"
			   "\v080\t084\f06\x8F\fd\xAE\xAC\xAE\xE9\xEC %s\t137\x8C\xA0\xA3\xA0\t000\x1";                     // "\v080\t084\f06П\fdомощь %s\t137Мага\t000\x1";
	}

	const char *CONTROL_PANEL_BUTTONS() {
		return "\x3""c\f11"			               // "\x3""c\f11"
			   "\v022\t062\xA8\xA3\xE0\xE3\t141%s" // "\v022\t062игру\t141%s"
			   "\v041\t062\xA8\xA3\xE0\xE3\t141%s" // "\v041\t062игру\t141%s"
			   "\v060\t062DOS"                     // "\v060\t062DOS"
			   "\v079\t102\x8C\xE0.\fd";           // "\v079\t102Мр.\fd";
	}

	const char *ON() {
		return "\f15\xA2\xAA\xAB\f11"; // "\f15вкл\f11"
	}

	const char *OFF() {
		return "\f32\xA2\xEB\xAA\f11"; // "\f32вык\f11"
	}

	const char *CONFIRM_QUIT() {
		return "\x82\xEB \xE3\xA2\xA5\xE0\xA5\xAD\xEB, \xE7\xE2\xAE \xE5\xAE\xE2\xA8\xE2\xA5 \xA2\xEB\xA9\xE2\xA8?"; // "Вы уверены, что хотите выйти?"
	}

	const char *MR_WIZARD() {
		return "\x82\xEB \xE2\xAE\xE7\xAD\xAE \xE5\xAE\xE2\xA8\xE2\xA5 \xA2\xAE\xE1\xAF\xAE\xAB\xEC\xA7\xAE\xA2\xA0\xE2\xEC\xE1\xEF \xAF\xAE\xAC\xAE\xE9\xEC\xEE \x8C\xE0. \x8C\xA0\xA3\xA0?"; // "Вы точно хотите воспользоваться помощью Мр. Мага?"
	}

	const char *NO_LOADING_IN_COMBAT() {
		return "\x8D\xA8\xAA\xA0\xAA\xA8\xE5 \xA7\xA0\xA3\xE0\xE3\xA7\xAE\xAA \xA2\xAE \xA2\xE0\xA5\xAC\xEF \xA1\xA8\xE2\xA2\xEB!"; // "Никаких загрузок во время битвы!"
	}

	const char *NO_SAVING_IN_COMBAT() {
		return "\x8D\xA8\xAA\xA0\xAA\xA8\xE5 \xE1\xAE\xE5\xE0\xA0\xAD\xA5\xAD\xA8\xA9 \xA2\xAE \xA2\xE0\xA5\xAC\xEF \xA1\xA8\xE2\xA2\xEB!"; // "Никаких сохранений во время битвы!"
	}

	const char *QUICK_FIGHT_TEXT() {
		return "\r\fd\x3""c\v000\t000\x81\xEB\xE1\xE2\xE0\xAE\xA5 \xA4\xA5\xA9\xE1\xE2\xA2\xA8\xA5\n\n" // "\r\fd\x3""c\v000\t000Быстрое действие\n\n"
			   "%s\x3""l\n\n"																		    // "%s\x3""l\n\n"
			   "\x92\xA5\xAA\xE3\xE9\xA5\xA5\x3""r\n"												    // "Текущее\x3""r\n"
			   "\t000%s\x2\x3""c\v122\t019\f37\x91\f04\xAB\xA5\xA4\t055\x82\xEB\xE5\xAE\xA4\x1";	    // "\t000%s\x2\x3""c\v122\t019\f37С\f04лед\t055Выход\x1";
	}

	const char **QUICK_FIGHT_OPTIONS() {
		delete[] _quickFightOptions;
		_quickFightOptions = new const char *[4] { "\x80\xE2\xA0\xAA\xA0", "\x87\xA0\xAA\xAB\xA8\xAD\xA0\xAD\xA8\xA5", "\x81\xAB\xAE\xAA", "\x81\xA5\xA3\xE1\xE2\xA2\xAE" }; // "Атака", "Заклинание", "Блок", "Бегство"
		return _quickFightOptions;
	}

	const char **WORLD_END_TEXT() {
		delete[] _worldEndText;
		_worldEndText = new const char *[9] {
			"\n\n\n\n\n\n\n"
			"Congratulations Adventurers!\n\n"
			"Let the unification ceremony begin!",
				"And so the call went out to the people throughout the lands of Xeen"
				" that the prophecy was nearing completion.",
				"They came in great numbers to witness the momentous occasion.",
				"\v026The Dragon Pharoah presided over the ceremony.",
				"\v026Queen Kalindra presented the Cube of Power.",
				"\v026Prince Roland presented the Xeen Sceptre.",
				"\v026Together, they placed the Cube of Power...",
				"\v026and the Sceptre, onto the Altar of Joining.",
				"With the prophecy complete, the two sides of Xeen were united as one",
		};
		return _worldEndText;
	}

	const char *WORLD_CONGRATULATIONS() {
		return "\x3"
			   "cCongratulations\n\n"
			   "Your Final Score is:\n\n"
			   "%010lu\n"
			   "\x3l\n"
			   "Please send this score to the Ancient's Headquarters where "
			   "you'll be added to the Hall of Legends!\n\n"
			   "Ancient's Headquarters\n"
			   "New World Computing, Inc.\n"
			   "P.O. Box 4302\n"
			   "Hollywood, CA 90078";
	}

	const char *WORLD_CONGRATULATIONS2() {
		return "\n\n\n\n\n\n"
			   "But wait... there's more!\n"
			   "\n\n"
			   "Include the message\n"
			   "\"%s\"\n"
			   "with your final score and receive a special bonus.";
	}

	const char *CLOUDS_CONGRATULATIONS1() {
		return "\f23\x3l"
			   "\v000\t000Please send this score to the Ancient's Headquarters "
			   "where you'll be added to the Hall of Legends!\f33\x3"
			   "c"
			   "\v070\t000Press a Key";
	}

	const char *CLOUDS_CONGRATULATIONS2() {
		return "\f23\x3l"
			   "\v000\t000Ancient's Headquarters\n"
			   "New World Computing, Inc.\n"
			   "P.O. Box 4302\n"
			   "Hollywood, CA 90078-4302\f33\x3"
			   "c"
			   "\v070\t000Press a Key";
	}

	const char **GOOBER() {
		delete[] _goober;
		_goober = new const char *[3] {
			"", "I am a Goober!", "I am a Super Goober!"
		};
		return _goober;
	}

	const char *DIFFICULTY_TEXT() {
		return "\v000\t000\x3""c\x82\xEB\xA1\xA5\xE0\xA8\xE2\xA5 \xA8\xA3\xE0\xAE\xA2\xAE\xA9 \xE0\xA5\xA6\xA8\xAC"; // "\v000\t000\x3""cВыберите игровой режим"
	}

	const char *SAVE_OFF_LIMITS() {
		return "\x3""c\v002\t000\x81\xAE\xA3\xA8 \x82\xAE\xE1\xE1\xE2\xA0\xAD\xAE\xA2\xAB\xA5\xAD\xA8\xEF \x88\xA3\xE0 \xE1\xE7\xA8\xE2\xA0\xEE\xE2 \xED\xE2\xAE \xAC\xA5\xE1\xE2\xAE \xA7\xA0\xAF\xE0\xA5\xE2\xAD\xEB\xAC!\n" // "\x3""c\v002\t000Боги Восстановления Игр считают это место запретным!\n"
			   "\x93\xA2\xEB, \xA7\xA4\xA5\xE1\xEC \xAD\xA5\xAB\xEC\xA7\xEF \xE1\xAE\xE5\xE0\xA0\xAD\xEF\xE2\xEC\xE1\xEF";																									   // "Увы, здесь нельзя сохраняться";
	}

	const char *CLOUDS_INTRO1() {
		return "\f00\v082\t040\x3"
			   "cKing Burlock\v190\t040Peasants\v082\t247"
			   "Lord Xeen\v190\t258Xeen's Pet\v179\t150Crodo";
	}

	const char *DARKSIDE_ENDING1() {
		return "\n\x3"
			   "cCongratulations\n"
			   "\n"
			   "Your Final Score is:\n"
			   "\n"
			   "%010lu\n"
			   "\x3"
			   "l\n"
			   "Please send this score to the Ancient's Headquarters "
			   "where you'll be added to the Hall of Legends!\n"
			   "\n"
			   "Ancient's Headquarters\n"
			   "New World Computing, Inc.\n"
			   "P.O. Box 4302\n"
			   "Hollywood, CA 90078";
	}

	const char *DARKSIDE_ENDING2() {
		return "\n"
			   "Adventurers,\n"
			   "\n"
			   "I will save your game in Castleview.\n"
			   "\n"
			   "The World of Xeen still needs you!\n"
			   "\n"
			   "Load your game afterwards and come visit me in the "
			   "Great Pyramid for further instructions";
	}

	const char *PHAROAH_ENDING_TEXT1() {
		return "\fd\v001\t001%s\x3"
			   "c\t000\v180Press a Key!\x3"
			   "l";
	}

	const char *PHAROAH_ENDING_TEXT2() {
		return "\f04\v000\t000%s\x3"
			   "c\t000\v180Press a Key!\x3"
			   "l\fd";
	}
};
