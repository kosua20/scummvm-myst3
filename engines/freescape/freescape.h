#ifndef FREESCAPE_H
#define FREESCAPE_H

#include "common/random.h"
#include "common/serializer.h"
#include "engines/engine.h"
#include "graphics/palette.h"
#include "graphics/surface.h"
#include "graphics/tinygl/pixelbuffer.h"
#include "gui/debugger.h"

#include "freescape/area.h"
#include "freescape/objects/entrance.h"
#include "freescape/language/instruction.h"
#include "freescape/gfx.h"

namespace Freescape {

class Renderer;

// from shooter
// Defines several possible options for camera movement. Used as abstraction to stay away from window-system specific input methods
enum CameraMovement {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

typedef Common::HashMap<uint16, Area *> AreaMap;

typedef struct Binary {
	uint8 bits;
	uint16 startArea;
	AreaMap *areasByAreaID;
	Common::Array<uint8> *border;
	Common::Array<uint8> *palette;
	uint16 ncolors;
} Binary;

class Console;

// our engine debug channels
enum {
	kFreescapeDebug = 1 << 0,
	kFreescapeDebug2 = 1 << 1
};

class FreescapeEngine : public Engine {
private:
	// We need random numbers
	Common::RandomSource *_rnd;
	int _screenW, _screenH;

	Graphics::Surface *_border;

	uint32 _timeOfLastTick;
	bool _hasReceivedTime;

public:
	FreescapeEngine(OSystem *syst);
	~FreescapeEngine();

	Renderer *_gfx;
	Common::Error run() override;

	// Border
	void convertBorder();
	void drawBorder();
	Texture *_borderTexture;

	// Parsing
	uint8 _binaryBits;
	void loadAssets();
	void load16bitBinary(Common::SeekableReadStream *file);

	// 8-bits
	void load8bitBinary(Common::SeekableReadStream *file, int offset, int ncolors);
	Area *load8bitArea(Common::SeekableReadStream *file, uint16 ncolors);
	Object *load8bitObject(Common::SeekableReadStream *file);

	// Areas
	uint16 _startArea;
	AreaMap *_areasByAreaID;
	Area *_currentArea;
	Math::Vector3d _scale;

	void gotoArea(uint16 areaID, uint16 entranceID);
	// Entrance
	uint16 _startEntrance;

	// Input
	void processInput();
	void move(CameraMovement direction, uint8 scale, float deltaTime);
	void rotate(Common::Point lastMousePos, Common::Point mousePos);
	// Input state
	float _lastFrame;
	Common::Point _lastMousePos;

	// Interaction
	void shoot();

	// Eular Angles
	float _yaw;
	float _pitch;
	Math::Vector3d directionToVector(float pitch, float heading);

	// Camera options
	float _mouseSensitivity;
	float _movementSpeed;
	Math::Vector3d _cameraFront, _cameraUp, _cameraRight;
	// Spacial attributes
	Math::Vector3d _position, _rotation, _velocity;
	uint16 _playerHeight;
	uint16 _playerWidth;
	uint16 _playerDepth;

	// Effects
	bool checkCollisions();
	void executeCode(FCLInstructionVector &code, bool shot, bool collided);

	// Instructions
	void executeGoto(FCLInstruction &instruction);
	void executeIfThenElse(FCLInstruction &instruction);
	void executeMakeInvisible(FCLInstruction &instruction);
	void executeMakeVisible(FCLInstruction &instruction);
	void executeToggleVisibility(FCLInstruction &instruction);

	// Rendering
	Common::String _renderMode;
	Graphics::PixelBuffer *getPalette(uint8 areaNumber, uint8 c1, uint8 c2, uint8 c3, uint8 c4, uint16 ncolors);
	void drawFrame();
	uint8 _colorNumber;
	Math::Vector3d _scaleVector;
	float _nearClipPlane;
	float _farClipPlane;

	bool hasFeature(EngineFeature f) const override;
	bool canLoadGameStateCurrently() override { return true; }
	bool canSaveGameStateCurrently() override { return true; }
	Common::Error loadGameStream(Common::SeekableReadStream *stream) override;
	Common::Error saveGameStream(Common::WriteStream *stream, bool isAutosave = false) override;
	void syncGameStream(Common::Serializer &s);
};

// Example console class
class Console : public GUI::Debugger {
public:
	Console(FreescapeEngine *vm) {
	}
	virtual ~Console(void) {
	}
};

extern FreescapeEngine *g_freescape;

} // namespace Freescape

#endif
