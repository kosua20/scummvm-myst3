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

/*
 * This code is based on the CRAB engine
 *
 * Copyright (c) Arvind Raja Yadav
 *
 * Licensed under MIT
 *
 */

#ifndef CRAB_GFXSETTINGMENU_H
#define CRAB_GFXSETTINGMENU_H

#include "crab/ui/ImageData.h"
#include "crab/ui/ResolutionMenu.h"
#include "crab/ui/StateButton.h"
#include "crab/ui/ToggleButton.h"
#include "crab/common_header.h"
#include "crab/ui/slider.h"

namespace Crab {

namespace pyrodactyl {
namespace ui {
class GfxSettingMenu {
	// The brightness slider
	Slider brightness;

	// The button to toggle between full and windowed, and turn vsync on/off, window borders or not, game quality
	ToggleButton fullscreen, vsync, border, quality;

	// The buttons and menus for changing resolution
	ResolutionMenu resolution;

	// Notice that quality setting can only be changed outside the game
	HoverInfo notice_quality;

public:
	GfxSettingMenu() {}
	~GfxSettingMenu() {}

	void Load(rapidxml::xml_node<char> *node);
	int HandleEvents(const SDL_Event &Event);
	void InternalEvents();

	void Draw();
	void SetUI();

	void SetInfo() { resolution.SetInfo(); }
};
} // End of namespace ui
} // End of namespace pyrodactyl

} // End of namespace Crab

#endif // CRAB_GFXSETTINGMENU_H
