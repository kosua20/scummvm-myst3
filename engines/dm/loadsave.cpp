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

/*
* Based on the Reverse Engineering work of Christophe Fontanel,
* maintainer of the Dungeon Master Encyclopaedia (http://dmweb.free.fr/)
*/

#include "loadsave.h"
#include "dungeonman.h"
#include "champion.h"
#include "group.h"
#include "timeline.h"



namespace DM {

LoadsaveMan::LoadsaveMan(DMEngine *vm) : _vm(vm) {}


LoadgameResponse LoadsaveMan::loadgame() {
	bool newGame = _vm->_dungeonMan->_messages._newGame;
	ChampionMan &cm = *_vm->_championMan;

	if (newGame) {
		_vm->_restartGameAllowed = false;
		cm._g305_partyChampionCount = 0;
		cm._414_leaderHandObject = Thing::_none;
		_vm->_gameId = _vm->_rnd->getRandomNumber(65536) * _vm->_rnd->getRandomNumber(65536);
	} else {
		assert(false);
		// MISSING CODE: load game
	}
	_vm->_dungeonMan->loadDungeonFile();


	if (newGame) {
		_vm->_timeline->initTimeline();
		_vm->_groupMan->initActiveGroups();
	} else {
		assert(false);
		// MISSING CODE: load game
	}
	cm._303_partyDead = false;
	return kLoadgameSuccess;
}

}