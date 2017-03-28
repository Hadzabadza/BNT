#include "GlobalFunctionMissiom.h"

using namespace std;
using namespace sf;

void Tile::SetTile(string Flag, int id, int i, int j, int carveX, int carveY, int W, bool instantiate) //создания тайла	
{
	StepUnit = false;
	_AttackON = false;
	InspectionTile = false;
	Instantiate = instantiate;
	Land = Flag;
	_WH = W;
	pos = new Vector2f(i, j);
	//pos.x = i;
	//pos.y = j;

	if (Land == '1' || Land == '2' || Land == '3' || Land == '4') //TODO: Улучши!
	{
		sprite = &SpriteLoader::sprt->tileSetAnimated;
		g = new Animated(Graphic(SpriteLoader::sprt->tileSetAnimated, Vector2f(2.0, 2.0), Vector2f(carveX, carveY), Vector2f(*pos), Vector2f(_WH, _WH)),5);

	}
	else
	{ 
		g = new Graphic(SpriteLoader::sprt->tileSetGame, Vector2f(2.0, 2.0), Vector2f(carveX, carveY), Vector2f(*pos), Vector2f(_WH, _WH));
		sprite = &SpriteLoader::sprt->tileSetGame; 
	}

	ID = id;
	_Empty = false;
	AttackOn = false;

	spriteGreenTile.setTexture(TextureLoader::tex->cursor);
	spriteGreenTile.setTextureRect(IntRect(0, 0, 64, 64));
	spriteGreenTile.setScale(2, 2);

	SetDotX = (pos->x * 128) + 64;
	SetDotY = (pos->y * 128) + 64;
}

string Tile::GetLand() { return Land; }

int Tile::Get_ID() { return ID; }

int Tile::Get_I() { return pos->x; }

int Tile::Get_J() { return pos->y; }

float Tile::Get_Dotx() { return SetDotX; }

float Tile::Get_Doty() { return SetDotY; }

bool  Tile::Get_Empty() { return _Empty; }

void  Tile::Set_Empty(bool __Empty) { _Empty = __Empty; }

bool  Tile::Get_Instantiate() { return Instantiate; }

void  Tile::Set_Instantiate(bool __Empty) { Instantiate = __Empty; }

//float Tile::Get__X() { return _X; }

//float Tile::Get__Y() { return _Y; }

float Tile::Get__WH() { return _WH; }

//float Tile::Get_anspeed() { return anspeed; }

bool  Tile::Get_AttackOn() { return _Empty; }

void  Tile::Set_AttackOn(bool __Empty) { AttackOn = __Empty; }