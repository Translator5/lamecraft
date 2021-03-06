#ifndef STATEPLAY_H_
#define STATEPLAY_H_

#include <Aurora/Utils/StateManager.h>
#include <Aurora/Utils/GameState.h>

#include <math.h>
#include <psptypes.h>

#include <Aurora/Graphics/RenderManager.h>
#include <Aurora/Utils/Logger.h>
#include <Aurora/Utils/Timer.h>
#include <Aurora/System/SystemManager.h>
#include <Aurora/Graphics/Models/ObjModel.h>
#include <Aurora/Graphics/Camera.h>
#include <Aurora/Graphics/Sprite.h>
#include <Aurora/Graphics/Effects/SkyDome.h>
#include <Aurora/Graphics/Effects/SkyLight.h>

#include "CraftWorld2.h"
#include "InputHelper.h"
#include "SoundManager.h"

using namespace Aurora::Graphics;
using namespace Aurora::Utils;
using namespace Aurora::System;
using namespace Aurora;


class StatePlay : public CGameState
{
public:
	StatePlay();
	virtual ~StatePlay();

	void Init();
	void InitParametric(int terrainType,bool makeFlat,bool makeTrees,bool makeWater,bool makeCaves);
	void Enter();
	void CleanUp();

	void Pause();
	void Resume();

	void LoadTextures();

	void HandleEvents(StateManager* sManager);
	void Update(StateManager* sManager);
	void Draw(StateManager* sManager);

	void LoadMap(std::string fileName,bool compressed);
	void SetWorldAndSaveName(std::string worldName,std::string fileName);
	void InitCamera();

	//keys helpers
	bool keyPressed(int currentKey);
	bool keyHold(int currentKey);

private:

	void advancedBlit(int sx, int sy, int sw, int sh, int dx, int dy, int slice);
	bool TryToMove(Vector3 moveVector,float dt);

	void SetDayTimeAfterLoad();

private:

	RenderManager *mRender;
	SystemManager *mSystemMgr;
	SoundManager *mSoundMgr;
	InputHelper *mIhelper;
	Camera *fppCam;

	std::string saveFileName;
	int freeMemory;
	float freeMemoryTimer;

	CraftWorld *mWorld;
	ObjModel *cubeModel;
	SkyDome *skyDome;
	SkyLight *skyLight;
	float sunTime;
	float sunTimeTick;
	bool sunMoonSwitch;

	Vector3 cubePos;
	bool showCube;

	//zmienne do poruszania
	float GRAVITY;
	float JUMPVELOCITY;
	float CLIMBVELOCITY;

	Vector3 playerVelocity;
	Vector3 playerPosition;
	Vector3 newPlayerPos;
	Vector3 oldPlayerPos;

	bool walkingOnGround;
	bool jumping;
	bool headInWater;
	bool footInWater;

	int allcubes;
	int cubesSets;
	int selectedCube;
	int selectedCubeSet;
	int selectedCubeStart;
	int selectedCubeEnd;

	int ram1;
	int ram2;

	Timer mTimer;
	float dt;

	//textures info
	std::string texture;
	std::string blue;
	Sprite *barSprite;
	Sprite *crossSprite;
	Sprite *selectSprite;

	float cameraSpeed;
	float cameraMoveSpeed;

	//menu sprites
	Sprite *buttonSprite;
	Sprite *sbuttonSprite;

	int menuState;//0 game,1 menu
	bool menuOptions;
	int optionsMenuPos;
	int selectPos;

	//some settings
	bool canFly;
	bool devMode;
	bool analogLeft,analogRight,analogUp,analogDown;

	//for sound of walkinng
	float walkSoundAccu;
	bool  isWalking;

	bool makeScreen;
};

#endif
