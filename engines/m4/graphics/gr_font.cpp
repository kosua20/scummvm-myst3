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

#include "m4/graphics/gr_font.h"
#include "m4/graphics/gr_buff.h"
#include "m4/graphics/gr_pal.h"
#include "m4/mem/mem.h"
#include "m4/core/errors.h"
#include "m4/core/imath.h"
#include "m4/mem/memman.h"
#include "m4/vars.h"

namespace M4 {

#define font_width 2		/* offset to width array */
#define font_data 130		/* offset to data array	*/
#define STR_FONTSTRUCT "font struct"
#define STR_FONTWIDTH "font widths"
#define STR_FONTOFF "font offsets"
#define STR_FONTDATA "font data"

static byte font_colors[4] = { 0, 15, 0, 8 };
constexpr byte font_intr_w = 8;
constexpr byte font_intr_h = 8;

static byte fontintr_width[128] = {
	0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,0,		// 00-0f width (128 entries)
	0,0,0,0,0,0,0,0,	0,0,0,0,0,0,0,4,		// 10-1f
	2,3,4,5,4,6,6,3,	3,3,6,3,3,3,3,6,		// 20-2f [ !"#]$%&' ()*+,-./
	6,6,6,6,6,6,6,6,	6,6,2,2,3,3,3,6,		// 30-3f [01234567] [89:;]<=>?
	6,6,6,5,6,5,5,6,	6,3,5,5,6,7,6,6,		// 40-4f [@ABCDEFG] [HIJKLMNO]
	6,6,6,6,6,6,6,6,	6,6,6,3,3,3,4,6,		// 50-5f [PQRSTUVW] [XYZ[\]^_]
	5,5,5,5,5,5,5,5,	5,2,3,5,2,6,5,5,		// 60-6f ['abcdefg] [hijklmno]
	5,5,3,5,3,5,5,6,	5,5,5,4,2,4,4,4,		// 70-7f [pqrstuvw] []xyz{|}~^
};

static short fontintr_offsets[128] = {
	 784,  784,  784,  784,  784,  784,  784,  784,	// 00-07
	 784,  784,  784,  784,  784,  784,  784,  784, // 08-0f
	 784,  784,  784,  784,  784,  784,  784,  784, // 10-17
	 784,  784,  784,  784,  784,  784,  784,  784, // 18-1f
	   0,    8,   16,   24,   40,   48,   64,   80, // 20-27 [ !"#$%&']
	  88,   96,  104,  120,  128,  136,  144,  152,	// 28-2f [()*+,-./]
	 168, 1176,  192,  208,  224,  240,  256,  272,	// 30-37 [01234567]
	 288,  304,  320,  328,   88,  336,   96,  344,	// 38-3f [89:;]<=>?
	 360,  376,  392,  408,  424,  440,  456,  472,	// 40-47 [@ABCDEFG]
	 488,  504,  512,  528,  544,  560,  576,  592,	// 48-4f [HIJKLMNO]
	 608,  624,  640,  656,  672,  688,  704,  720,	// 50-57 [PQRSTUVW]
	 736,  752,  768, 1192, 1208, 1200,  784,  784,	// 58-5f [XYZ[\]^_]
	 784,  800,  816,  832,  848,  864,  880,  896,	// 60-67 [`abcdefg]
	 912,  928,  936,  944,  960,  968,  984, 1000,	// 68-6f [hijklmno]
	1016, 1032, 1048, 1056, 1072, 1080, 1096, 1112,	// 70-77 [pqrstuvw]
	1128, 1144, 1160,  784,  184, 1216,  784, 1224	// 78-7f []xyz{|}~^
};

static byte fontintr_data[] = {
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,													// 0 " "
	0x14,0x14,0x14,0x14,0x14,0x00,0x14,0x00,													// 8 "!"
	0x44,0x44,0x00,0x00,0x00,0x00,0x00,0x00,													// 16 "
	0x00,0x00,0x11,0x00,0x55,0x40,0x11,0x00,0x11,0x00,0x55,0x40,0x11,0x00,0x00,0x00,			// 24 "#"
	0x10,0x14,0x40,0x54,0x04,0x50,0x10,0x00,																// 40 "$"
	0x00,0x00,0x10,0x00,0x44,0x40,0x11,0x00,0x01,0x10,0x04,0x44,0x00,0x10,0x00,0x00,			// 48 "%"
	0x04,0x00,0x11,0x00,0x10,0x00,0x44,0x00,0x41,0x40,0x41,0x00,0x14,0x40,0x00,0x00,			// 64 "&"
	0x40,0x40,0x00,0x00,0x00,0x00,0x00,0x00,													// 80 "'"
	0x04,0x10,0x40,0x40,0x40,0x10,0x04,0x00,													// 88 "("
	0x40,0x10,0x04,0x04,0x04,0x10,0x40,0x00,													// 96 ")"
	0x00,0x00,0x04,0x00,0x44,0x40,0x15,0x00,0x44,0x40,0x04,0x00,0x00,0x00,0x00,0x00,			// 104 "*"
	0x00,0x00,0x00,0x10,0x54,0x10,0x00,0x00,													// 120 "+"
	0x00,0x00,0x00,0x00,0x00,0x10,0x10,0x40,													// 128 ","
	0x00,0x00,0x00,0x00,0x54,0x00,0x00,0x00,													// 136 "-"
	0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x00,													// 144 "."
	0x00,0x04,0x00,0x10,0x00,0x40,0x01,0x00,0x04,0x00,0x10,0x00,0x40,0x00,0x00,0x00,			// 152 "/"
	0x00,0x00,0x15,0x40,0x50,0x10,0x54,0x10,0x51,0x10,0x50,0x50,0x15,0x40,0x00,0x00,			// 168 "0"
	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,																// 184 "|"
	0x00,0x00,0x15,0x00,0x41,0x40,0x01,0x40,0x05,0x00,0x14,0x00,0x55,0x40,0x00,0x00,			// 192 "2"
	0x00,0x00,0x15,0x40,0x00,0x50,0x05,0x40,0x00,0x50,0x00,0x50,0x55,0x40,0x00,0x00,			// 208 "3"
	0x00,0x00,0x01,0x40,0x41,0x40,0x41,0x40,0x55,0x40,0x01,0x40,0x01,0x40,0x00,0x00,			// 224 "4"
	0x00,0x00,0x55,0x50,0x50,0x00,0x55,0x40,0x00,0x50,0x00,0x50,0x55,0x40,0x00,0x00,			// 240 "5"
	0x00,0x00,0x15,0x40,0x50,0x00,0x55,0x40,0x50,0x10,0x50,0x10,0x15,0x40,0x00,0x00,			// 256 "6"
	0x00,0x00,0x55,0x50,0x00,0x50,0x01,0x40,0x05,0x00,0x05,0x00,0x05,0x00,0x00,0x00,			// 272 "7"
	0x00,0x00,0x15,0x40,0x50,0x10,0x15,0x40,0x50,0x10,0x50,0x10,0x15,0x40,0x00,0x00,			// 288 "8"
	0x00,0x00,0x15,0x40,0x40,0x50,0x41,0x50,0x14,0x50,0x00,0x50,0x15,0x40,0x00,0x00,			// 304 "9"
	0x00,0x00,0x40,0x00,0x00,0x40,0x00,0x00,																// 320 ":"
	0x00,0x00,0x40,0x00,0x00,0x40,0x40,0x00,																// 328 ";"
	0x00,0x00,0x00,0x54,0x00,0x54,0x00,0x00,																// 336 "="
	0x14,0x00,0x41,0x00,0x01,0x00,0x04,0x00,0x10,0x00,0x00,0x00,0x10,0x00,0x00,0x00,			// 344 "?"											// 352
	0x15,0x00,0x40,0x40,0x41,0x00,0x44,0x40,0x41,0x00,0x40,0x00,0x15,0x00,0x00,0x00,			// 360 "@"
	0x15,0x40,0x50,0x10,0x50,0x10,0x55,0x50,0x50,0x10,0x50,0x10,0x50,0x10,0x00,0x00,			// 376 "A"
	0x55,0x40,0x50,0x10,0x50,0x10,0x55,0x40,0x50,0x10,0x50,0x10,0x55,0x40,0x00,0x00,			// 392 "B"
	0x15,0x00,0x50,0x40,0x50,0x00,0x50,0x00,0x50,0x00,0x50,0x40,0x15,0x00,0x00,0x00,			// 408 "C"
	0x55,0x40,0x14,0x40,0x14,0x10,0x14,0x10,0x14,0x10,0x14,0x10,0x55,0x40,0x00,0x00,			// 424 "D"
	0x55,0x40,0x50,0x00,0x50,0x00,0x55,0x00,0x50,0x00,0x50,0x00,0x55,0x40,0x00,0x00,			// 440 "E"
	0x55,0x40,0x50,0x00,0x50,0x00,0x55,0x00,0x50,0x00,0x50,0x00,0x50,0x00,0x00,0x00,			// 456 "F"
	0x15,0x40,0x50,0x10,0x50,0x00,0x51,0x50,0x50,0x10,0x50,0x10,0x15,0x40,0x00,0x00,			// 472 "G"
	0x50,0x10,0x50,0x10,0x50,0x10,0x55,0x50,0x50,0x10,0x50,0x10,0x50,0x10,0x00,0x00,			// 488 "H"
	0x55,0x14,0x14,0x14,0x14,0x14,0x55,0x00,																// 504 "I"
	0x05,0x50,0x01,0x40,0x01,0x40,0x01,0x40,0x01,0x40,0x41,0x40,0x15,0x00,0x00,0x00,			// 512 "J"
	0x50,0x40,0x51,0x00,0x54,0x00,0x50,0x00,0x54,0x00,0x51,0x00,0x50,0x40,0x00,0x00,			// 528 "K"
	0x50,0x00,0x50,0x00,0x50,0x00,0x50,0x00,0x50,0x00,0x50,0x00,0x55,0x50,0x00,0x00,			// 544 "L"
	0x50,0x10,0x54,0x50,0x51,0x10,0x50,0x10,0x50,0x10,0x50,0x10,0x50,0x10,0x00,0x00,			// 560 "M"
	0x50,0x10,0x50,0x10,0x54,0x10,0x51,0x10,0x50,0x50,0x50,0x10,0x50,0x10,0x00,0x00,			// 576 "N"
	0x15,0x40,0x50,0x10,0x50,0x10,0x50,0x10,0x50,0x10,0x50,0x10,0x15,0x40,0x00,0x00,			// 592 "O"
	0x55,0x00,0x50,0x40,0x50,0x40,0x55,0x00,0x50,0x00,0x50,0x00,0x50,0x00,0x00,0x00,			// 608 "P"
	0x15,0x00,0x50,0x40,0x50,0x40,0x50,0x40,0x50,0x40,0x51,0x00,0x14,0x40,0x00,0x00,			// 624 "Q"
	0x55,0x40,0x50,0x10,0x50,0x10,0x55,0x40,0x50,0x10,0x50,0x10,0x50,0x10,0x00,0x00,			// 640 "R"
	0x15,0x00,0x40,0x40,0x10,0x00,0x05,0x40,0x00,0x50,0x40,0x50,0x15,0x40,0x00,0x00,			// 656 "S"
	0x55,0x50,0x05,0x00,0x05,0x00,0x05,0x00,0x05,0x00,0x05,0x00,0x05,0x00,0x00,0x00,			// 672 "T"
	0x50,0x10,0x50,0x10,0x50,0x10,0x50,0x10,0x50,0x10,0x50,0x10,0x15,0x40,0x00,0x00,			// 688 "U"
	0x50,0x10,0x50,0x10,0x50,0x10,0x50,0x10,0x50,0x10,0x10,0x40,0x04,0x00,0x00,0x00,			// 704 "V"
	0x50,0x10,0x50,0x10,0x50,0x10,0x50,0x10,0x51,0x10,0x55,0x50,0x50,0x10,0x00,0x00,			// 720 "W"
	0x40,0x40,0x40,0x40,0x11,0x00,0x04,0x00,0x11,0x00,0x40,0x40,0x40,0x40,0x00,0x00,			// 736 "X"
	0x40,0x40,0x40,0x40,0x11,0x00,0x04,0x00,0x04,0x00,0x04,0x00,0x04,0x00,0x00,0x00,			// 752 "Y"
	0x55,0x40,0x00,0x40,0x01,0x00,0x04,0x00,0x10,0x00,0x40,0x00,0x55,0x40,0x00,0x00,			// 768 "Z"
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x55,0x40,0x00,0x00,			// 784 a little weirdo thing
	0x00,0x00,0x00,0x00,0x15,0x00,0x01,0x40,0x11,0x40,0x41,0x40,0x14,0x40,0x00,0x00,			// 800 "a"
	0x50,0x00,0x50,0x00,0x55,0x00,0x50,0x40,0x50,0x40,0x50,0x40,0x55,0x00,0x00,0x00,			// 816 "b"
	0x00,0x00,0x00,0x00,0x15,0x00,0x50,0x40,0x50,0x00,0x50,0x40,0x15,0x00,0x00,0x00,			// 832 "c"
	0x01,0x40,0x01,0x40,0x15,0x40,0x41,0x40,0x41,0x40,0x41,0x40,0x15,0x40,0x00,0x00,			// 848 "d"
	0x00,0x00,0x00,0x00,0x15,0x00,0x50,0x40,0x55,0x40,0x50,0x00,0x15,0x00,0x00,0x00,			// 864 "e"
	0x05,0x00,0x11,0x00,0x14,0x00,0x55,0x00,0x14,0x00,0x14,0x00,0x14,0x00,0x00,0x00,			// 880 "f"
	0x00,0x00,0x00,0x00,0x14,0x00,0x41,0x40,0x41,0x40,0x15,0x40,0x41,0x40,0x15,0x00,			// 896 "g"
	0x50,0x00,0x50,0x00,0x55,0x00,0x50,0x40,0x50,0x40,0x50,0x40,0x50,0x40,0x00,0x00,			// 912 "h"
	0x50,0x00,0x50,0x50,0x50,0x50,0x50,0x00,																// 928 "i"
	0x05,0x00,0x05,0x05,0x05,0x05,0x45,0x10,																// 936 "j"
	0x50,0x00,0x50,0x00,0x50,0x40,0x51,0x00,0x54,0x00,0x51,0x00,0x50,0x40,0x00,0x00,			// 944 "k"
	0x50,0x50,0x50,0x50,0x50,0x50,0x50,0x00,																// 960 "l"
	0x00,0x00,0x00,0x00,0x54,0x40,0x51,0x10,0x51,0x10,0x51,0x10,0x51,0x10,0x00,0x00,			// 968 "m"
	0x00,0x00,0x00,0x00,0x55,0x00,0x50,0x40,0x50,0x40,0x50,0x40,0x50,0x40,0x00,0x00,			// 984 "n"
	0x00,0x00,0x00,0x00,0x15,0x00,0x50,0x40,0x50,0x40,0x50,0x40,0x15,0x00,0x00,0x00,			// 1000 "o"
	0x00,0x00,0x00,0x00,0x55,0x00,0x50,0x40,0x50,0x40,0x55,0x00,0x50,0x00,0x50,0x00,			// 1016 "p"
	0x00,0x00,0x00,0x00,0x14,0x40,0x41,0x40,0x41,0x40,0x15,0x40,0x01,0x40,0x01,0x40,			// 1032 "q"
	0x00,0x00,0x51,0x54,0x50,0x50,0x50,0x00,																// 1048 "r"
	0x00,0x00,0x00,0x00,0x15,0x00,0x40,0x00,0x15,0x00,0x01,0x40,0x55,0x00,0x00,0x00,			// 1056 "s"
	0x10,0x14,0x55,0x14,0x14,0x14,0x05,0x00,																// 1072 "t"
	0x00,0x00,0x00,0x00,0x50,0x40,0x50,0x40,0x50,0x40,0x50,0x40,0x15,0x00,0x00,0x00,			// 1080 "u"
	0x00,0x00,0x00,0x00,0x50,0x40,0x50,0x40,0x50,0x40,0x11,0x10,0x05,0x00,0x00,0x00,			// 1096 "v"
	0x00,0x00,0x00,0x00,0x50,0x10,0x50,0x10,0x51,0x10,0x51,0x10,0x15,0x00,0x00,0x00,			// 1112 "w"
	0x00,0x00,0x00,0x00,0x50,0x40,0x50,0x40,0x15,0x00,0x50,0x40,0x50,0x40,0x00,0x00,			// 1128 "x"
	0x00,0x00,0x00,0x00,0x41,0x40,0x41,0x40,0x41,0x40,0x15,0x40,0x01,0x40,0x01,0x40,			// 1144 "y
	0x00,0x00,0x00,0x00,0x55,0x00,0x01,0x00,0x14,0x00,0x40,0x00,0x55,0x00,0x00,0x00,			// 1160 "z"
	0x00,0x00,0x05,0x00,0x15,0x00,0x05,0x00,0x05,0x00,0x05,0x00,0x15,0x40,0x00,0x00,			// 1176 thick "1"
	0x55,0x50,0x50,0x50,0x50,0x50,0x55,0x00,													// 1192 "["
	0x55,0x05,0x05,0x05,0x05,0x05,0x55,0x00,													// 1200 "]"
	0x00,0x40,0x10,0x10,0x04,0x04,0x01,0x00,													// 1208 "\"
	0x15,0x14,0x14,0x50,0x14,0x14,0x15,0x00,													// 1216 "{"
	0x54,0x14,0x14,0x05,0x14,0x14,0x54,0x00														// 1224 "}"
};

void font_set_colors(uint8 alt1, uint8 alt2, uint8 foreground) {
	if (_G(font) == _G(interfaceFont)) {
		font_colors[1] = foreground;
	} else {
		font_colors[1] = alt1;
		font_colors[2] = alt2;
		font_colors[3] = foreground;
	}
}

void gr_font_set_color(uint8 foreground) {
	if (_G(font) == _G(interfaceFont))
		font_colors[1] = foreground;
	else
		font_colors[3] = foreground;
}

Font *gr_font_create_system_font() {
	_G(interfaceFont) = (Font *)mem_alloc(sizeof(Font), "Font");
	if (!_G(interfaceFont))
		error("font struct");

	_G(interfaceFont)->max_y_size = font_intr_h;
	_G(interfaceFont)->max_x_size = font_intr_w;
	_G(interfaceFont)->width = fontintr_width;
	_G(interfaceFont)->offset = fontintr_offsets;
	_G(interfaceFont)->pixData = fontintr_data;

	return _G(interfaceFont);
}

void gr_font_system_shutdown() {
	if (_G(interfaceFont))
		mem_free(_G(interfaceFont));
}

void gr_font_dealloc(Font *killMe) {
	if (!killMe)
		return;
	if (killMe->width)
		mem_free(killMe->width);
	if (killMe->offset)
		mem_free(killMe->offset);
	if (killMe->pixData)
		mem_free(killMe->pixData);
	mem_free(killMe);
}

void gr_font_set(Font *newFont) {
	if (newFont)
		_G(font) = newFont;
}

Font *gr_font_get() {
	return _G(font);
}

int32 gr_font_string_width(char *out_string, int32 auto_spacing) {
	if (_G(custom_ascii_converter)) {			 // if there is a function to convert the extended ASCII characters
		_G(custom_ascii_converter)(out_string);	 // call it with the string
	}

	int32 width = 0;	// Add some spacing in between the characters
	byte *widthArray = _G(font)->width;

	while (*out_string) {
		width += widthArray[(byte)*out_string] + auto_spacing;
		out_string++;
	}

	return width;
}

int32 gr_font_string_width(const Common::String &str, int32 auto_spacing) {
	char *tmp = new char[str.size() + 1];
	Common::copy(str.c_str(), str.c_str() + str.size() + 1, tmp);
	int32 result = gr_font_string_width(tmp, auto_spacing);
	delete[] tmp;

	return result;
}


int32 gr_font_get_height() {
	if (!_G(font))
		return -1;

	return (int32)_G(font)->max_y_size;
}


int32 gr_font_write(Buffer *target, char *out_string, int32 x, int32 y, int32 w, int32 auto_spacing) {
	if (!target || !out_string)
		return x;

	if (_G(custom_ascii_converter)) {			 // if there is a function to convert the extended ASCII characters
		_G(custom_ascii_converter)(out_string);	 // call it with the string
	}

	int32 i, j;
	int32 target_w;
	if (w)
		target_w = imath_min(target->w, x + w);
	else
		target_w = target->w;

	x += 1; y += 1;
	int32 skipTop = 0;
	if (y < 0) {
		skipTop = -y;
		y = 0;
	}

	int32 height = imath_max(0, (int32)_G(font)->max_y_size - skipTop);
	if (!height)
		return x;

	int32 bottom = y + height - 1;
	if (bottom > (target->h - 1)) {
		height -= imath_min((int32)height, (bottom - (target->h - 1)));
	}

	if (height <= 0)
		return x;

	byte *target_ptr = gr_buffer_pointer(target, x, y);
	byte *prev_target_ptr = target_ptr;

	int32 cursX = x;
	Byte *widthArray = _G(font)->width;
	Byte *fontPixData = _G(font)->pixData;
	short *offsetArray = _G(font)->offset;

	while (*out_string) {
		byte c = (*out_string++) & 0x7f;
		int32 wdth = widthArray[c];

		// if width is zero, nothing to draw

		if (wdth) {
			if ((cursX + wdth) >= target_w) 			// if character doesn't fit in buffer, abort
				return cursX;

			int32 offset = offsetArray[c];
			Byte *charData = &fontPixData[offset];

			int32 bytesInChar = (_G(font)->width[c] >> 2) + 1; //bytesPer[wdth];	// 2 bits per pixel
			if (skipTop)
				charData += bytesInChar * skipTop;

			for (i = 0; i < height; i++) {
				for (j = 0; j < bytesInChar; j++) {
					Byte workByte = *charData++;
					if (workByte & 0xc0)
						*target_ptr = font_colors[(workByte & 0xc0) >> 6];
					target_ptr++;
					if (workByte & 0x30)
						*target_ptr = font_colors[(workByte & 0x30) >> 4];
					target_ptr++;
					if (workByte & 0xc)
						*target_ptr = font_colors[(workByte & 0xc) >> 2];
					target_ptr++;
					if (workByte & 0x3)
						*target_ptr = font_colors[workByte & 0x3];
					target_ptr++;

				} // end bytes per character line loop

				target_ptr += target->stride - (bytesInChar << 2);

			} // end for height loop

			target_ptr = prev_target_ptr + wdth + auto_spacing; // one pixel space
			prev_target_ptr = target_ptr;

		} // end if there was a drawable character

		cursX += w;
	} // end while there is a character to draw loop

	return(cursX);
}

int32 gr_font_write(Buffer *target, const char *out_string, int32 x, int32 y, int32 w, int32 auto_spacing) {
	char *tmp = mem_strdup(out_string);
	int32 result = gr_font_write(target, tmp, x, y, w, auto_spacing);
	free(tmp);

	return result;
}

Font *gr_font_load(const char *fontName) {
	uint8 buffer[10];
	uint32 tag;
	uint32 *bumpf;
	Font *newFont;
	void *bufferHandle = &buffer[0];

	SysFile fontFile(fontName, BINARY);
	if (!fontFile.exists())
		return nullptr;

	bufferHandle = &buffer[0];
	fontFile.read(&bufferHandle, 10);

	bumpf = (uint32 *)&buffer[0];
	tag = convert_intel32(*bumpf);
	if (tag != 'FONT')
		error_show(FL, 'FNTL', "font: %s chkpnt: %d", (const char *)fontName, 0);

	newFont = (Font *)mem_alloc(sizeof(Font), STR_FONTSTRUCT);
	if (!newFont)
		error_show(FL, 'OOM!', "_G(font) struct");

	newFont->max_y_size = buffer[4];
	newFont->max_x_size = buffer[5];
	newFont->dataSize = *((uint32 *)&buffer[6]);
	newFont->dataSize = convert_intel32(newFont->dataSize);

	// read 'WIDT' into tag
	bufferHandle = &buffer[0];
	fontFile.read(&bufferHandle, 4);
	bumpf = (uint32 *)&buffer[0];
	tag = convert_intel32(*bumpf);
	if (tag != 'WIDT')
		error_show(FL, 'FNTL', "font: %s chkpnt: %d", fontName, 1);

	// width table
	newFont->width = (byte *)mem_alloc(256, STR_FONTWIDTH);
	if (!newFont->width)
		error_show(FL, 'OOM!', "_G(font) width table");

	bufferHandle = newFont->width;
	fontFile.read(&bufferHandle, 256);

	// read 'OFFS' into tag
	bufferHandle = &buffer[0];
	fontFile.read(&bufferHandle, 4);
	bumpf = (uint32 *)&buffer[0];
	tag = convert_intel32(*bumpf);
	if (tag != 'OFFS')
		error_show(FL, 'FNTL', "font: %s chkpnt: %d", fontName, 2);

	// offset table
	newFont->offset = (short *)mem_alloc(256 * sizeof(int16), STR_FONTOFF);
	if (!newFont->offset)
		error_show(FL, 'OOM!', "font offset table");

	bufferHandle = newFont->offset;
	fontFile.read(&bufferHandle, 256 * sizeof(int16));

	for (int i = 0; i < 256; i++)
		newFont->offset[i] = convert_intel16(newFont->offset[i]);

	// read 'PIXS' into tag
	bufferHandle = &buffer[0];
	fontFile.read(&bufferHandle, 4);
	bumpf = (uint32 *)&buffer[0];
	tag = convert_intel32(*bumpf);
	if (tag != 'PIXS')
		error_show(FL, 'FNTL', "font: %s chkpnt: %d", fontName, 3);

	// pixData
	newFont->pixData = (byte *)mem_alloc(newFont->dataSize, STR_FONTDATA);
	if (!newFont->pixData)
		error_show(FL, 'OOM!', "font pix data");

	bufferHandle = newFont->pixData;
	fontFile.read(&bufferHandle, newFont->dataSize);

	// we don't need to close the file, because the destructor will close fontFile automagically
	return newFont;
}

} // namespace M4
