/* ScummVM - Scumm Interpreter
 * Copyright (C) 2002-2004 The ScummVM project
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 * $Header$
 *
 */

#include "common/file.h"
#include "common/util.h"


Common::String File::_defaultDirectory;


FILE *File::fopenNoCase(const char *filename, const char *directory, const char *mode) {
	FILE *file;
	char buf[512];
	char *ptr;

	assert(directory);
	strcpy(buf, directory);

#ifdef WIN32
	// Fix for Win98 issue related with game directory pointing to root drive ex. "c:\"
	if ((buf[0] != 0) && (buf[1] == ':') && (buf[2] == '\\') && (buf[3] == 0)) {
		buf[2] = 0;
	}
#endif

	// Record the length of the dir name (so we can cut of anything trailing it
	// later, when we try with different file names).
	const int dirLen = strlen(buf);

	if (dirLen > 0) {
#ifdef __MORPHOS__
		if (buf[dirLen-1] != ':' && buf[dirLen-1] != '/')
#endif

#if !defined(__GP32__) && !defined(__PALM_OS__)
		strcat(buf, "/");	// prevent double /
#endif
	}
	strcat(buf, filename);

	file = fopen(buf, mode);
	if (file)
		return file;

	// FIXME this should probably be engine specific...
	const char *dirs[] = {
		"",
		"rooms/",
		"ROOMS/",
		"Rooms 1/",
		"Rooms 2/",
		"Rooms 3/",
		"video/",
		"VIDEO/",
		"data/",
		"DATA/",
		"resource/",
		"RESOURCE/",
		// Simon the Sorcerer 1 Acorn
		"execute/",
		"EXECUTE/",
		// Simon the Sorcerer 2 Amiga/Mac
		"../",
		"voices/",
		"VOICES/",
		// sword1/2 stuff if user just copied files without putting
		// them all into the same dir like original installer did
		"CLUSTERS/",
		"clusters/",
		"SPEECH/",
		"speech/",
		"SWORD2/",
		"sword2/"
	};

	for (int dirIdx = 0; dirIdx < ARRAYSIZE(dirs); dirIdx++) {
		buf[dirLen] = 0;
		if (buf[0] != 0) {
#ifdef __MORPHOS__
			if (buf[strlen(buf) - 1] != ':' && buf[strlen(buf) - 1] != '/')
#endif
#ifndef __PALM_OS__
			strcat(buf, "/");	// PALMOS
#endif
		}
		strcat(buf, dirs[dirIdx]);
		int8 len = strlen(buf);
		strcat(buf, filename);

		ptr = buf + len;
		do
			*ptr = toupper(*ptr);
		while (*ptr++);
		file = fopen(buf, mode);
		if (file)
			return file;

		ptr = buf + len;
		do
			*ptr = tolower(*ptr);
		while (*ptr++);
		file = fopen(buf, mode);
		if (file)
			return file;
	}

	return NULL;
}

void File::setDefaultDirectory(const Common::String &directory) {
	_defaultDirectory = directory;
}

File::File() {
	_handle = NULL;
	_ioFailed = false;
	_name = 0;
}

File::~File() {
	close();
	delete [] _name;
}

bool File::open(const char *filename, const char *directory, AccessMode mode) {
	if (_handle) {
		debug(2, "File %s already opened", filename);
		return false;
	}

	if (filename == NULL || *filename == 0)
		return false;
	
	// If no directory was specified, use the default directory (if any).
	if (directory == NULL)
		directory = _defaultDirectory.isEmpty() ? "" : _defaultDirectory.c_str();

	clearIOFailed();

	if (mode == kFileReadMode) {
		_handle = fopenNoCase(filename, directory, "rb");
		if (_handle == NULL) {
			debug(2, "File %s not found", filename);
			return false;
		}
	}
	else if (mode == kFileWriteMode) {
		_handle = fopenNoCase(filename, directory, "wb");
		if (_handle == NULL) {
			debug(2, "File %s not opened", filename);
			return false;
		}
	}	else {
		warning("Only read/write mode supported!");
		return false;
	}

	int len = strlen(filename);
	if (_name != 0)
		delete [] _name;
	_name = new char[len+1];
	memcpy(_name, filename, len+1);

	return true;
}

void File::close() {
	if (_handle)
		fclose(_handle);
	_handle = NULL;
}

bool File::isOpen() const {
	return _handle != NULL;
}

bool File::ioFailed() const {
	return _ioFailed != 0;
}

void File::clearIOFailed() {
	_ioFailed = false;
}

bool File::eof() {
	if (_handle == NULL) {
		error("File is not open!");
		return false;
	}

	return feof(_handle) != 0;
}

uint32 File::pos() {
	if (_handle == NULL) {
		error("File is not open!");
		return 0;
	}

	return ftell(_handle);
}

uint32 File::size() {
	if (_handle == NULL) {
		error("File is not open!");
		return 0;
	}

	uint32 oldPos = ftell(_handle);
	fseek(_handle, 0, SEEK_END);
	uint32 length = ftell(_handle);
	fseek(_handle, oldPos, SEEK_SET);

	return length;
}

void File::seek(int32 offs, int whence) {
	if (_handle == NULL) {
		error("File is not open!");
		return;
	}

	if (fseek(_handle, offs, whence) != 0)
		clearerr(_handle);
}

uint32 File::read(void *ptr, uint32 len) {
	byte *ptr2 = (byte *)ptr;
	uint32 real_len;

	if (_handle == NULL) {
		error("File is not open!");
		return 0;
	}

	if (len == 0)
		return 0;

	real_len = fread(ptr2, 1, len, _handle);
	if (real_len < len) {
		clearerr(_handle);
		_ioFailed = true;
	}

	return real_len;
}

uint32 File::write(const void *ptr, uint32 len) {
	if (_handle == NULL) {
		error("File is not open!");
		return 0;
	}

	if (len == 0)
		return 0;

	if ((uint32)fwrite(ptr, 1, len, _handle) != len) {
		clearerr(_handle);
		_ioFailed = true;
	}

	return len;
}
