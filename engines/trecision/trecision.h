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

#ifndef TRECISION_TRECISION_H
#define TRECISION_TRECISION_H

#include "common/str-array.h"
#include "common/keyboard.h"
#include "common/str.h"
#include "engines/advancedDetector.h"
#include "engines/engine.h"
#include "graphics/surface.h"

#include "trecision/defines.h"
#include "trecision/fastfile.h"
#include "trecision/video.h"
#include "trecision/struct.h"

namespace Trecision {
class AnimManager;
class DialogManager;
class GraphicsManager;
class LogicManager;
class SoundManager;
class Actor;
class Renderer3D;
class PathFinding3D;
class TextManager;
class Scheduler;
class AnimTypeManager;

#define SAVE_VERSION_ORIGINAL 102
#define SAVE_VERSION_SCUMMVM  103

#define MAXROOMS         	  100            // Game rooms
#define MAXOBJ          	  1400           // Game objects
#define MAXINVENTORY    	  150            // Inventory Items
#define MAXSAVEFILE		12
#define MAXLIGHT 40

enum TrecisionMessageIds {
	kMessageSavePosition = 9,
	kMessageEmptySpot = 10,
	kMessageLoadPosition = 11,
	kMessageConfirmExit = 13,
	kMessageDemoOver = 17,
	kMessageError = 19,
	kMessageUse = 23,
	kMessageWith = 24,
	kMessageGoto = 25,
	kMessageGoto2 = 26
};

typedef Common::List<Common::Rect>::iterator DirtyRectsIterator;

struct SVertex {
	float _x, _y, _z;
	float _nx, _ny, _nz;

	void clear() {
		_x = _y = _z = 0.0f;
		_nx = _ny = _nz = 0.0f;
	}
};

struct SFace {
	uint16 _a, _b, _c;
	uint16 _mat;
};

struct SLight {
	float _x, _y, _z;
	float _dx, _dy, _dz;
	float _inr, _outr;
	uint8 _hotspot;
	uint8 _fallOff;
	int8 _inten;
	int8 _position;
};

struct SCamera {
	float _ex, _ey, _ez;
	float _e1[3];
	float _e2[3];
	float _e3[3];
	float _fovX, _fovY;
};

struct STexture {
	int16 _dx, _dy, _angle;
	uint8 *_texture;
	uint8 _flag;
};

class TrecisionEngine : public Engine {
	void initMain();
	void initMessageSystem();
	void openDataFiles();
	void loadAll();
	void loadSaveSlots(Common::StringArray &saveNames);
	void openSys();
	Graphics::Surface *convertScummVMThumbnail(Graphics::Surface *thumbnail);
	
	STexture FTexture[MAXMAT];
	SLight VLight[MAXLIGHT];
	SCamera FCamera;
	char *TextArea;

public:
	TrecisionEngine(OSystem *syst, const ADGameDescription *desc);
	~TrecisionEngine() override;

	// ScummVM
	Common::Error run() override;
	bool isDemo() const;
	void eventLoop();
	bool hasFeature(EngineFeature f) const override;
	bool canLoadGameStateCurrently() override { return canPlayerInteract(); }
	bool canSaveGameStateCurrently() override { return canPlayerInteract(); }
	Common::Error loadGameStream(Common::SeekableReadStream *stream) override;
	Common::Error saveGameStream(Common::WriteStream *stream, bool isAutosave = false) override;
	bool syncGameStream(Common::Serializer &ser);

	// Data files
	byte *readData(const Common::String &fileName);
	uint16 *readData16(const Common::String &fileName, int &size);
	void read3D(const Common::String &c);

	// Inventory
	void refreshInventory(uint8 startIcon, uint8 startLine);
	void moveInventoryLeft();
	void moveInventoryRight();
	void setInventoryStart(uint8 startIcon, uint8 startLine);
	void doInventory();
	void showInventoryName(uint16 obj, bool showhide);
	uint8 whatIcon(Common::Point pos);
	int8 iconPos(uint8 icon);
	void removeIcon(uint8 icon);
	void addIcon(uint8 icon);
	void replaceIcon(uint8 oldIcon, uint8 newIcon);
	void syncInventory(Common::Serializer &ser);
	void doInventoryUseWithInventory();
	void doInventoryUseWithScreen();
	void rollInventory(uint8 status);
	void doScrollInventory(Common::Point pos);

	// Script
	void endScript();
	void playScript(uint16 id);
	void evalScript();
	bool quitPrompt();
	void demoOver();
	void doAction();
	void doMouse();
	void startCharacterAction(uint16 Act, uint16 NewRoom, uint8 NewPos, uint16 sent);
	void doCharacter();
	void doSystem();
	void doIdle();
	void doRoomIn(uint16 curObj);
	void doRoomOut(uint16 curObj);
	void doMouseExamine(uint16 curObj);
	void doMouseOperate(uint16 curObj);
	void doMouseTake(uint16 curObj);
	void doMouseTalk(uint16 curObj);
	void doUseWith();
	void doScreenUseWithScreen();
	void doInvExamine();
	void doInvOperate();
	void doDoing();
	void doScript();
	void processCurrentMessage();

	// Utils
	char *getNextSentence();
	void setRoom(uint16 r, bool b);
	uint16 textLength(const Common::String &text, uint16 begin = 0, uint16 end = 0);
	char getKey();
	char waitKey();
	void waitDelay(uint32 val);
	void freeKey();
	uint32 readTime();
	bool checkMask(Common::Point pos);
	static float sinCosAngle(float sinus, float cosinus);
	void processTime();
	void processMouse();
	float dist2D(float x1, float y1, float x2, float y2);
	float dist3D(float x1, float y1, float z1, float x2, float y2, float z2);
	static bool isBetween(int a, int x, int b);
	static bool isGameArea(Common::Point pos);
	static bool isInventoryArea(Common::Point pos);
	static bool isIconArea(Common::Point pos);
	int getRoomObjectIndex(uint16 objectId);
	
	// Others
	void checkSystem();
	bool dataSave();
	bool dataLoad();
	void performLoad(int slot, bool skipLoad);
	bool canPlayerInteract();
	void addDirtyRect(Common::Rect rect);
	void reEvent();

	// Objects
	void setObjectVisible(uint16 objectId, bool visible);
	bool isObjectVisible(uint16 objectId) const;
	void setObjectAnim(uint16 objectId, uint16 animId);

	void RedrawRoom();
	void ReadLoc();
	void TendIn();
	void readObj(Common::SeekableReadStream *stream);
	void readExtraObj2C();
	void readExtraObj41D();
	void readObject(Common::SeekableReadStream *stream, uint16 objIndex, uint16 objectId);
	
	const ADGameDescription *_gameDescription;

	Graphics::Surface _thumbnail;

	uint16 _curRoom;
	uint16 _oldRoom;
	SRoom _room[MAXROOMS];

	Common::List<SSortTable> _sortTable;
	uint16 _curScriptFrame[10];

	uint16 _curObj;
	SObject _obj[MAXOBJ];

	uint8 _actionLen[MAXACTION];

	char *_textPtr;
	SDText _drawText;
	char _drawTextLines[MAXDTEXTLINES][MAXDTEXTCHARS];
	Common::List<Common::Rect> _dirtyRects;
	Common::Rect *_actorRect;

	// Inventory
	uint16 _curInventory;
	SInvObject _inventoryObj[MAXINVENTORY];
	Common::Array<byte> _inventory;
	Common::Array<byte> _cyberInventory;
	uint8 _iconBase;
	uint8 _inventoryStatus;
	uint8 _lightIcon;
	uint8 _inventoryRefreshStartIcon;
	uint8 _inventoryRefreshStartLine;
	uint16 _lastCurInventory;
	uint16 _lastLightIcon;
	int16 _inventoryCounter;
	bool  _flagInventoryLocked;
	int16 _inventorySpeed[8];
	uint8 _inventorySpeedIndex;
	uint32 _inventoryScrollTime;
	uint16 _lastInv;
	uint16 _lastObj;

	bool _fastWalk;

	// Use With
	uint16 _useWith[2];
	bool _useWithInv[2];

	// Messages
	const char *_objName[MAXOBJNAME];
	const char *_sentence[MAXSENTENCE];
	const char *_sysText[MAXSYSTEXT];

	// Message system
	Message _gameMsg[MAXMESSAGE];
	Message _characterMsg[MAXMESSAGE];
	Message _animMsg[MAXMESSAGE];
	Message _idleMsg;
	Message *_curMessage;
	MessageQueue _gameQueue;
	MessageQueue _animQueue;
	MessageQueue _characterQueue;
	// Snake management
	Message _snake52;

	uint32 _nextRefresh;

	Common::Point _mousePos;
	bool _mouseLeftBtn, _mouseRightBtn;
	Common::KeyCode _curKey;
	uint16 _curAscii;
	bool _keybInput;

	bool _gamePaused = false;
	// CloseUp12 and 13
	uint16 _closeUpObj;

	bool _flagscriptactive;
	SScriptFrame _scriptFrame[MAXSCRIPTFRAME];
	SScript _script[MAXSCRIPT];
	uint8 _curStack;

	AnimManager *_animMgr;
	GraphicsManager *_graphicsMgr;
	DialogManager *_dialogMgr;
	LogicManager *_logicMgr;
	SoundManager *_soundMgr;
	Renderer3D *_renderer;
	PathFinding3D *_pathFind;
	TextManager *_textMgr;
	Scheduler *_scheduler;
	AnimTypeManager *_animTypeMgr;

	uint8 *_font;
	uint16 *_arrows;
	uint8 *_textureArea;
	uint16 *_icons;

	Actor *_actor;

	// Data files
	FastFile _dataFile;	// nldata.cd0

	bool _flagDialogActive;
	bool _flagDialogMenuActive;
	bool _flagSkipTalk;
	bool _flagPaintCharacter;
	bool _flagShowCharacter;
	bool _flagSomeoneSpeaks;
	bool _flagCharacterSpeak;
	bool _flagUseWithStarted;
	bool _flagCharacterExists;
	bool _flagNoPaintScreen;
	bool _flagWaitRegen;

	uint16 *_objPointers[MAXOBJINROOM];
	uint8 *_maskPointers[MAXOBJINROOM];

	uint16 _blinkLastDTextChar;
	uint32 _curTime;
	uint32 _characterSpeakTime;

	int _actorPos;
	int _cx, _cy;

	int _forcedActorPos;
	uint8 _textStatus;

	uint8 const _defActionLen[hLAST + 1] = {
		/* STAND */ 1,
		/* PARTE */ 1,
		/* WALK  */ 10,
		/* END   */ 1,
		/* STOP0 */ 3,
		/* STOP1 */ 4,
		/* STOP2 */ 3,
		/* STOP3 */ 2,
		/* STOP4 */ 3,
		/* STOP5 */ 4,
		/* STOP6 */ 3,
		/* STOP7 */ 3,
		/* STOP8 */ 2,
		/* STOP9 */ 3,
		/* WALKI */ 12,
		/* BOH   */ 9,
		/* UGG   */ 41,
		/* UTT   */ 35,
		/* WALKO */ 12,
		/* LAST  */ 15
	};
};

extern TrecisionEngine *g_vm;

} // End of namespace Trecision

#endif
