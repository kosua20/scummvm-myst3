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

#include "xeen/worldofxeen/cutscenes.h"
#include "xeen/xeen.h"

namespace Xeen {

static const char *SUBTITLE_LINE = "\xC" "35\x3" "c\xB" "190\x9" "000%s";

void Cutscenes::resetSubtitles() {
	_subtitleLineNum = _subtitleSize = 0;
}

void Cutscenes::showSubtitles(uint windowIndex) {
	Screen &screen = *_vm->_screen;
	Sound &sound = *_vm->_sound;

	if (sound._soundOn) {
		// Sound is on, so subtitles aren't needed
		resetSubtitles();
	} else {
		if (timeElapsed() > 1) {
			++_subtitleSize;
			const Common::String &line = _subtitles[_subtitleLineNum];
			Common::String lineStr(line.c_str(), line.c_str() + _subtitleSize);
			_subtitleLine = Common::String::format(SUBTITLE_LINE, lineStr.c_str());

			// If displayed a full line, then move to the next line
			if (_subtitleSize == line.size()) {
				_subtitleSize = 0;
				if (++_subtitleLineNum == _subtitles.size())
					_subtitleLineNum = 0;
			}
		}

		// Draw the box sprite
		if (!_boxSprites)
			// Not already loaded, so load it
			_boxSprites = new SpriteResource("box.vga");
		_boxSprites->draw(screen, 0, Common::Point(36, 189));

		// Write the subtitle line
		screen._windows[windowIndex].writeString(_subtitleLine);
	}

	screen.update();
}

void Cutscenes::freeSubtitles() {
	delete _boxSprites;
	_boxSprites = nullptr;
	_subtitles.clear();
}

bool Cutscenes::subtitlesWait(uint minTime) {
	EventsManager &events = *_vm->_events;

	events.updateGameCounter();
	recordTime();
	while (events.timeElapsed() < minTime || _subtitleSize != 0) {
		events.pollEventsAndWait();
		if (events.isKeyMousePressed())
			return false;

		showSubtitles();
	}

	return true;
}

void Cutscenes::recordTime() {
	_vm->_events->timeMark1();
}

uint Cutscenes::timeElapsed() {
	return _vm->_events->timeElapsed1();
}


} // End of namespace Xeen
