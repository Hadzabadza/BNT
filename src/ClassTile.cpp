#include "GlobalFunctionMissiom.h"
using namespace std;
using namespace sf;

void Tile::GetTile(string Flag, int id, int j, int i, int X, int Y, int W, bool instantiate) //создания тайла	
{
	anspeed = 0.004;
	CurrentFrame = 0;
	StepUnit = false;
	_AttackON = false;
	InspectionTile = false;
	Instantiate = instantiate;
	Land = Flag;
	_X = X;
	_Y = Y;
	_WH = W;
	if (Land == '1' || Land == '2' || Land == '3' || Land == '4')
	{
		s_map.setTexture(TextureLoader::tex->tileSetAnimated);
		s_map.setScale(2, 2);
		animated = true;
		frames = 5;
		anim = &sprt->tileSetAnimated;
	}
	else
	{
		s_map.setTexture(TextureLoader::tex->tileSetGame);
		s_map.setScale(2, 2);
	}
	ID = id;
	s_map.setTextureRect(IntRect(_X, _Y, _WH, _WH));
	_Empty = false;
	AttackOn = false;
	I = i;
	J = j;

	spriteGreenTile.setTexture(TextureLoader::tex->cursor);
	spriteGreenTile.setTextureRect(IntRect(0, 0, 64, 64));
	spriteGreenTile.setScale(2, 2);

	SetDotX = (J * 128) + 64;
	SetDotY = (I * 128) + 64;
}

string Tile::GetLand() { return Land; }

int Tile::Get_ID() { return ID; }

int Tile::Get_I() { return I; }

int Tile::Get_J() { return J; }

float Tile::Get_Dotx() { return SetDotX; }

float Tile::Get_Doty() { return SetDotY; }

bool  Tile::Get_Empty() { return _Empty; }

void  Tile::Set_Empty(bool __Empty) { _Empty = __Empty; }

bool  Tile::Get_Instantiate() { return Instantiate; }

void  Tile::Set_Instantiate(bool __Empty) { Instantiate = __Empty; }

float Tile::Get__X() { return _X; }

float Tile::Get__Y() { return _Y; }

float Tile::Get__WH() { return _WH; }

float Tile::Get_anspeed() { return anspeed; }

bool  Tile::Get_AttackOn() { return _Empty; }

void  Tile::Set_AttackOn(bool __Empty) { AttackOn = __Empty; }