#include "raylib.h"

#include "objects/player.h"
#include "objects/arrows.h"
#include "objects/enemies.h"
#include "screens/all_the_screens.h"

const int SCREENWIDTH = 1600;
const int SCREENHEIGHT = 500;

static void Initialize();
static void UnloadAssets();

int main()
{
	Initialize();
	
	Screens::screenControler();

	UnloadAssets();

	return 0;
}

// ----------------------------

static void Initialize()
{
	InitWindow(SCREENWIDTH, SCREENHEIGHT, "Super Submarino!! - Sumer Lab");
	HideCursor();

	SetExitKey(KEY_BACK);
	SetTargetFPS(60);

	Player::Initialize();
	Arrows::Initialize();
	Enemies::Initialize();
	Screens::Initialize();
}

static void UnloadAssets()
{
	CloseWindow();
	UnloadTexture(Player::player.texture);
}