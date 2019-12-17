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

#include "adplug_player.h"

class OriginFXAdLibDriver;

class CmidPlayer: public CPlayer {
public:
	static CPlayer *factory(Copl *newopl);

	CmidPlayer(Copl *newopl);
	~CmidPlayer();

	bool load(const std::string &filename);
	bool load(std::string &filename, int song_index);
	//bool load(const std::string &filename, const CFileProvider &fp);
	bool update();
	void rewind(int subsong);
	float getrefresh();

	std::string gettype();
	std::string gettitle() {
		return std::string(title);
	}
	std::string getauthor() {
		return std::string(author);
	}
	std::string getdesc() {
		return std::string(remarks);
	}
	unsigned int getinstruments() {
		return tins;
	}
	unsigned int getsubsongs() {
		return subsongs;
	}

protected:
	static const unsigned char adlib_opadd[];
	static const int ops[], map_chan[], fnums[], percussion_map[];

	struct midi_track {
		unsigned long tend;
		unsigned long spos;
		unsigned long pos;
		unsigned long iwait;
		int on;
		unsigned char pv;
	};

	char *author, *title, *remarks, emptystr;
	long flen;
	unsigned long pos;

	int subsongs;
	unsigned char *data;


	int adlib_style;
	int adlib_mode;

	int chp[18][3];

	long deltas;
	long msqtr;

	midi_track track[16];
	unsigned int curtrack;
	unsigned int track_count;

	float fwait;
	unsigned long iwait;
	int doing;

	int type, tins, stins;

	OriginFXAdLibDriver *origin_fx_driver;

private:

	void load_ultima_midi_tracks();
	void midiprintf(const char *format, ...);
	unsigned char datalook(long pos);
	unsigned long getnexti(unsigned long num);
	unsigned long getnext(unsigned long num);
	unsigned long getval();

public:
	void interrupt_vector();
};
