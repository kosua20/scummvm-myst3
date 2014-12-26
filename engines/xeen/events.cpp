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

#include "common/scummsys.h"
#include "graphics/cursorman.h"
#include "common/events.h"
#include "common/endian.h"
#include "engines/util.h"
#include "xeen/xeen.h"
#include "xeen/events.h"
#include "xeen/screen.h"

namespace Xeen {

/**
 * Constructor
 */
EventsManager::EventsManager(XeenEngine *vm) : _vm(vm) {
	_frameCounter = 0;
	_priorFrameCounterTime = 0;
	_gameCounter = 0;
	_priorGameCounterTime = 0;
	_keyCode = Common::KEYCODE_INVALID;
	_leftButton = _rightButton = false;
}

/**
 * Destructor
 */
EventsManager::~EventsManager() {
}

/**
 * Show the mouse cursor
 */
void EventsManager::showCursor() {
	CursorMan.showMouse(true);
}

/**
 * Hide the mouse cursor
 */
void EventsManager::hideCursor() {
	CursorMan.showMouse(false);
}

/**
 * Returns if the mouse cursor is visible
 */
bool EventsManager::isCursorVisible() {
	return CursorMan.isVisible();
}

void EventsManager::pollEvents() {
	uint32 timer = g_system->getMillis();
	if (timer >= (_priorFrameCounterTime + GAME_FRAME_TIME)) {
		_priorFrameCounterTime = timer;
		nextFrame();
	}

	Common::Event event;
	while (g_system->getEventManager()->pollEvent(event)) {
		switch (event.type) {
		case Common::EVENT_QUIT:
		case Common::EVENT_RTL:
			return;
		case Common::EVENT_KEYDOWN:
			_keyCode = event.kbd.keycode;
			break;
		default:
 			break;
		}
	}
}

void EventsManager::pollEventsAndWait() {
	pollEvents();
	g_system->delayMillis(10);
}

void EventsManager::clearEvents() {
	_keyCode = Common::KEYCODE_INVALID;
	_leftButton = _rightButton = false;

}


bool EventsManager::getKey(Common::KeyState &key) {
	if (_keyCode == Common::KEYCODE_INVALID) {
		return false;
	} else {
		key = _keyCode;
		_keyCode = Common::KEYCODE_INVALID;
		return true;
	}
}

/**
 * Updates the game counter to match the current frame counter
 */
void EventsManager::updateGameCounter() {
	_gameCounter = _frameCounter;
}

/**
 * Returns the number of frames elapsed since the last call to
 * updateGameCounter()
 */
uint32 EventsManager::timeElapsed() {
	return _frameCounter - _gameCounter;
}

/**
 * Handles moving to the next game frame
 */
void EventsManager::nextFrame() {
	++_frameCounter;
	_vm->_screen->update();
}

} // End of namespace Xeen
