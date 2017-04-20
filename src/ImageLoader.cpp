#include "GlobalFunctionMissiom.h"

using namespace std;
using namespace sf;

ImageLoader * ImageLoader::imgs = new ImageLoader();

ImageLoader::ImageLoader() {
	//Загрузка файлов
	load(halberdier, projectPath + unitsFolder +"Halberdier/halberdier.png");
	load(halberdierGray, projectPath + unitsFolder + "Halberdier/halberdierGray.png");
	load(exitBTN, projectPath + imageFolder +"exit.png");
	load(loadingSplashScreen, projectPath + imageFolder +"DonwoldArt.png");
	load(unitInterface, projectPath + imageFolder +"interfeysUnit.png");
	load(cursor, projectPath + imageFolder +"kursor.png");
	load(steoNotHalt, projectPath + imageFolder +"SteoNotHalt.png");
	load(steoNotIn, projectPath + imageFolder +"SteoNotIn.png");
	load(tileSetGame, projectPath + imageFolder +"TileSetGame.png");
	load(tileSetAnimated, projectPath + imageFolder +"TileSetGameIsAnimation.png");
};

ImageLoader::~ImageLoader() {}

void ImageLoader::load(Image & which, String path) {
	which.loadFromFile(path);
}

TextureLoader * TextureLoader::tex = new TextureLoader();

TextureLoader::TextureLoader() {
	load(halberdier, ImageLoader::imgs->halberdier);
	load(halberdierGray, ImageLoader::imgs->halberdierGray);
	load(exitBTN, ImageLoader::imgs->exitBTN);
	load(loadingSplashScreen, ImageLoader::imgs->loadingSplashScreen);
	load(unitInterface, ImageLoader::imgs->unitInterface);
	load(cursor, ImageLoader::imgs->cursor);
	load(steoNotHalt, ImageLoader::imgs->steoNotHalt);
	load(steoNotIn, ImageLoader::imgs->steoNotIn);
	load(tileSetGame, ImageLoader::imgs->tileSetGame);
	load(tileSetAnimated, ImageLoader::imgs->tileSetAnimated);
	delete ImageLoader::imgs;
	ImageLoader::imgs = nullptr;
};

TextureLoader::~TextureLoader() {}

void TextureLoader::load(Texture & which, Image & from) {
	which.loadFromImage(from);
}

SpriteLoader * SpriteLoader::sprt = new SpriteLoader();

SpriteLoader::SpriteLoader() {
	load(halberdier, TextureLoader::tex->halberdier);
	load(halberdierGray, TextureLoader::tex->halberdierGray);
	load(exitBTN, TextureLoader::tex->exitBTN);
	load(loadingSplashScreen, TextureLoader::tex->loadingSplashScreen);
	load(unitInterface, TextureLoader::tex->unitInterface);
	load(cursor, TextureLoader::tex->cursor);
	load(steoNotHalt, TextureLoader::tex->steoNotHalt);
	load(steoNotIn, TextureLoader::tex->steoNotIn);
	load(tileSetGame, TextureLoader::tex->tileSetGame);
	load(tileSetAnimated, TextureLoader::tex->tileSetAnimated);
};

SpriteLoader::~SpriteLoader() {}

void SpriteLoader::load(Sprite & which, Texture & from) {
	which.setTexture(from);
}