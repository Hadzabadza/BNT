#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include "GlobalFunctionMissiom.h"

using namespace std;
using namespace sf;

ImageLoader * ImageLoader::imgs = new ImageLoader();

ImageLoader::ImageLoader() {
	load(allebard, "image/allebard.png");
	load(allebard_1, "image/allebard_1.png");
	load(exitBTN, "image/exit.png");
	load(loadingSplashScreen, "image/DonwoldArt.png");
	load(unitInterface, "image/interfeysUnit.png");
	load(cursor, "image/kursor.png");
	load(steoNotHalt, "image/SteoNotHalt.png");
	load(steoNotIn, "image/SteoNotIn.png");
	load(tileSetGame, "image/TileSetGame.png");
	load(tileSetAnimated, "image/TileSetGameIsAnimation.png");
};

void ImageLoader::load(Image & which, String path) {
	which.loadFromFile(path);
}

TextureLoader * TextureLoader::tex = new TextureLoader();

TextureLoader::TextureLoader() {
	load(allebard, imgs->allebard);
	load(allebard_1, imgs->allebard_1);
	load(exitBTN, imgs->exitBTN);
	load(loadingSplashScreen, imgs->loadingSplashScreen);
	load(unitInterface, imgs->unitInterface);
	load(cursor, imgs->cursor);
	load(steoNotHalt, imgs->steoNotHalt);
	load(steoNotIn, imgs->steoNotIn);
	load(tileSetGame, imgs->tileSetGame);
	load(tileSetAnimated, imgs->tileSetAnimated);
};

void TextureLoader::load(Texture & which, Image & from) {
	which.loadFromImage(from);
}