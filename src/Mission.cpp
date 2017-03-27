#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include "GlobalFunctionMissiom.h"

using namespace std;
using namespace sf;

Mission::Mission(int _H, int _W, RenderWindow &_window)
{
	HEIGHT_MAP = _H;
	WIDTH_MAP = _W;
	id_tile = 0;

	center_Mission = _window.getView().getCenter();
	size_Mission = _window.getView().getSize();

	MovementPlayer = true; //игрок еще не сделал свой ход
	screen_lock = true;
	PressedSpace = false;
	StepPlayerInspection = false;
	FrameSpace = 0;
	CouterS = 1;
	OnIUO3 = false;
	OnSureHalt = false;
	Fast_2 = false;
	CouterClick_Frame = 0;
	Teamp_CouterClick_Frame = false;
	No_fast = false;
	DownloadArt = true;
	FrameDownload = 0;
	Start = false;

	Miss = new Tile *[HEIGHT_MAP];
	for (int i(0); i < HEIGHT_MAP; i++)
	{
		Miss[i] = new Tile[WIDTH_MAP];
	}


	//texture_DownloadArt.loadFromFile("image/DonwoldArt.png");	//арт
	sprite_DownloadArt.setTexture(TextureLoader::tex->loadingSplashScreen);
	sprite_DownloadArt.setTextureRect(IntRect(0, 0, 1024, 768));
	sprite_DownloadArt.setPosition(center_Mission.x - size_Mission.x / 2, center_Mission.y - size_Mission.y / 2);

	//texture_DownloadStrips.loadFromFile("image/DonwoldArt.png");	//полоска
	sprite_DownloadStrips.setTexture(TextureLoader::tex->loadingSplashScreen);
	sprite_DownloadStrips.setTextureRect(IntRect(113, 769, 14, 46));
	sprite_DownloadStrips.setPosition(center_Mission.x - size_Mission.x / 2.585, center_Mission.y + size_Mission.y / 2.76);
}

Mission::~Mission()
{
	for (int i = 0; i < HEIGHT_MAP; i++)
	{
		delete [] Miss[i];
	}
	delete [] Miss;
}