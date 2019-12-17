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

#ifndef ULTIMA6_GUI_GUI_TEXT_H
#define ULTIMA6_GUI_GUI_TEXT_H

#include "GUI_widget.h"

namespace Ultima {
namespace Ultima6 {

class GUI_Font;

class GUI_Text : public GUI_Widget {
protected:
	Uint8 R, G, B;
	char *text;
	GUI_Font *font;
	uint16 max_width; //max line width. No limit if set to 0

public:
	GUI_Text(int x, int y, Uint8 r, Uint8 g, Uint8 b, GUI_Font *gui_font, uint16 line_length);
	GUI_Text(int x, int y, Uint8 r, Uint8 g, Uint8 b, const char *str, GUI_Font *gui_font, uint16 line_length = 0);
	~GUI_Text();

	/* Show the widget  */
	virtual void Display(bool full_redraw);

};

} // End of namespace Ultima6
} // End of namespace Ultima

#endif
