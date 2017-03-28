#include "GlobalFunctionMissiom.h"

using namespace std;
using namespace sf;

ImageLoader * ImageLoader::imgs = new ImageLoader();

ImageLoader::ImageLoader() {
	load(allebard, imageFolder+"allebard.png");
	load(allebard_1, imageFolder + "allebard_1.png");
	load(exitBTN, imageFolder+"exit.png");
	load(loadingSplashScreen, imageFolder+"DonwoldArt.png");
	load(unitInterface, imageFolder+"interfeysUnit.png");
	load(cursor, imageFolder+"kursor.png");
	load(steoNotHalt, imageFolder+"SteoNotHalt.png");
	load(steoNotIn, imageFolder+"SteoNotIn.png");
	load(tileSetGame, imageFolder+"TileSetGame.png");
	load(tileSetAnimated, imageFolder+"TileSetGameIsAnimation.png");
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

SpriteLoader * SpriteLoader::sprt = new SpriteLoader();

SpriteLoader::SpriteLoader() {
	load(allebard, tex->allebard);
	load(allebard_1, tex->allebard_1);
	load(exitBTN, tex->exitBTN);
	load(loadingSplashScreen, tex->loadingSplashScreen);
	load(unitInterface, tex->unitInterface);
	load(cursor, tex->cursor);
	load(steoNotHalt, tex->steoNotHalt);
	load(steoNotIn, tex->steoNotIn);
	load(tileSetGame, tex->tileSetGame);
	load(tileSetAnimated, tex->tileSetAnimated);
};

void SpriteLoader::load(Sprite & which, Texture & from) {
	which.setTexture(from);
}