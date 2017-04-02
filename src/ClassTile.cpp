#include "GlobalFunctionMissiom.h"

using namespace std;
using namespace sf;

Tile::Tile() {
	pos = new Vector2f(0, 0);
}

void Tile::SetTile(string Flag, bool instantiate, int id, float posX, float posY, int carveX, int carveY, int width, int height, int frames) //создания тайла	
{
	if (height==0) height = width;
	StepUnit = false;
	_AttackON = false;
	InspectionTile = false;
	Instantiate = instantiate;
	Land = Flag;
	pos->x = posX;
	pos->y = posY;

	if (frames>0)
	{ g = new Animated(Graphic(*pos, SpriteLoader::sprt->tileSetAnimated, Vector2i(carveX, carveY), Vector2i(width, height)),frames); }
	else
	{ g = new Graphic(*pos, SpriteLoader::sprt->tileSetGame, Vector2i(carveX, carveY), Vector2i(width, height)); }

	ID = id;
	_Empty = false;
	AttackOn = false;

	spriteGreenTile.setTexture(TextureLoader::tex->cursor);
	spriteGreenTile.setTextureRect(IntRect(0, 0, 64, 64));
	spriteGreenTile.setScale(2, 2);

	SetDotX = (pos->x * g->dim.x*scale.x) + g->dim.x*scale.x/2;
	SetDotY = (pos->y * g->dim.y*scale.y) + g->dim.y*scale.y/2;
}

string Tile::GetLand() { return Land; }

int Tile::Get_ID() { return ID; }

float Tile::Get_X() { return pos->x; }

float Tile::Get_Y() { return pos->y; }

float Tile::Get_Dotx() { return SetDotX; }

float Tile::Get_Doty() { return SetDotY; }

bool  Tile::Get_Empty() { return _Empty; }

void  Tile::Set_Empty(bool __Empty) { _Empty = __Empty; }

bool  Tile::Get_Instantiate() { return Instantiate; }

void  Tile::Set_Instantiate(bool __Empty) { Instantiate = __Empty; }

int Tile::GetWidth() { return g->dim.x; }

int Tile::GetHeight() { return g->dim.y; }

bool  Tile::Get_AttackOn() { return _Empty; }

void  Tile::Set_AttackOn(bool __Empty) { AttackOn = __Empty; }