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

#include "mm/mm1/views/cast_spell.h"
#include "mm/mm1/globals.h"
#include "mm/mm1/sound.h"

namespace MM {
namespace MM1 {
namespace Views {

CastSpell::CastSpell() : TextView("CastSpell") {
	_bounds = getLineBounds(20, 24);
}

bool CastSpell::msgValue(const ValueMessage &msg) {
	if (msg._value == 0) {
		// Ensure current character can cast spells
		if (g_globals->_currCharacter->_slvl != 0 &&
			g_globals->_currCharacter->_sp != 0) {
			addView();
			setState(SELECT_SPELL);
		}
	} else {
		// Spell bound to an item
		addView();
		setSpell(msg._value, 0, 0);

		if (!canCast()) {
			spellDone();
		} else if (hasCharTarget()) {
			setState(SELECT_CHAR);
		} else {
			setState(PRESS_ENTER);
		}
	}

	return true;
}

void CastSpell::setState(State state) {
	_state = state;

	MetaEngine::setKeybindingMode(
		_state == SELECT_CHAR ?
		KeybindingMode::KBMODE_PARTY_MENUS :
		KeybindingMode::KBMODE_MENUS
	);
	draw();
}

void CastSpell::draw() {
	switch (_state) {
	case SELECT_SPELL:
		clearSurface();
		escToGoBack(0);
		writeString(7, 0, STRING["dialogs.character.cast_spell"]);

		_textEntry.display(27, 20, 1, true,
			[]() {
				CastSpell *view =
					(CastSpell *)g_events->focusedView();
				view->close();
			},
			[](const Common::String &text) {
				CastSpell *view =
					(CastSpell *)g_events->focusedView();
				view->spellLevelEntered(atoi(text.c_str()));
			}
		);
		break;

	case SELECT_NUMBER:
		clearLines(1, 1);
		writeString(19, 1, STRING["dialogs.character.number"]);

		_textEntry.display(27, 21, 1, true,
			[]() {
				CastSpell *view =
					(CastSpell *)g_events->focusedView();
				view->close();
			},
			[](const Common::String &text) {
				CastSpell *view =
					(CastSpell *)g_events->focusedView();
				view->spellNumberEntered(atoi(text.c_str()));
			}
		);
		break;

	case SELECT_CHAR:
		writeString(22, 3, Common::String::format(
			STRING["dialogs.misc.cast_on"].c_str(),
			(int)g_globals->_party.size()
		));
		break;

	case PRESS_ENTER:
		clearSurface();
		writeString(24, 3, STRING["dialogs.misc.enter_to_cast"]);
		break;

	default:
		break;
	}
}

void CastSpell::spellLevelEntered(uint level) {
	// Ensure the spell level is valid
	if (level < 1 || level > 7 ||
		level > g_globals->_currCharacter->_slvl) {
		close();
		return;
	}

	setState(SELECT_NUMBER);
}

void CastSpell::spellNumberEntered(uint num) {
	if (num < 1 || num > 8 || (_spellLevel >= 5 && num >= 6)) {
		close();
		return;
	}

	setSpell(g_globals->_currCharacter, _spellLevel, num);
	if (!canCast())
		spellDone();
	else if (hasCharTarget())
		setState(SELECT_CHAR);
	else
		setState(PRESS_ENTER);

	draw();
}

bool CastSpell::msgKeypress(const KeypressMessage &msg) {
	if (msg.keycode == Common::KEYCODE_ESCAPE) {
		close();
	} else if (_state == PRESS_ENTER) {
		if (msg.keycode == Common::KEYCODE_RETURN) {
			// Time to execute the spell
			performSpell();
		}
	}

	return true;
}

bool CastSpell::msgAction(const ActionMessage &msg) {
	if (_state == SELECT_CHAR &&
			msg._action >= KEYBIND_VIEW_PARTY1 &&
			msg._action <= KEYBIND_VIEW_PARTY6) {
		uint charIndex = (int)(msg._action - KEYBIND_VIEW_PARTY1);
		if (charIndex < g_globals->_party.size())
			performSpell(&g_globals->_party[charIndex]);
	}

	return true;
}


void CastSpell::timeout() {
	close();
}

void CastSpell::performSpell(Character *chr) {
	Character &c = *g_globals->_currCharacter;
	c._sp._current = MAX(c._sp._current - _requiredSp, 0);
	c._gems = MAX(c._gems - _requiredGems, 0);

	c.castUnknown();

	if (!isMagicAllowed()) {
		spellDone(STRING["dialogs.misc.magic_doesnt_work"], 5);
	} else {
		// Cast the spell
		castSpell(chr);

		// Display spell done
		clearSurface();
		writeString(14, 2, STRING["dialogs.misc.done"]);
		Sound::sound(SOUND_2);

		g_globals->_party.updateAC();
		delaySeconds(3);
	}
}

void CastSpell::spellDone() {
	Common::String msg = getSpellError();
	int xp = 5;

	switch (getSpellState()) {
	case Game::SS_NOT_ENOUGH_GEMS: xp = 9; break;
	case Game::SS_COMBAT_ONLY: xp = 10; break;
	case Game::SS_OUTDOORS_ONLY: xp = 10; break;
	default: break;
	}

	spellDone(msg, xp);
}

void CastSpell::spellDone(const Common::String &msg, int xp) {
	_state = ENDING;
	Sound::sound(SOUND_2);
	clearSurface();
	writeString(xp, 1, msg);
	delaySeconds(3);
}

} // namespace Views
} // namespace MM1
} // namespace MM
