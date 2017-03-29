#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace sf;

class ImageLoader {
protected:
	ImageLoader();
public:
	~ImageLoader();
	static ImageLoader * ImageLoader::imgs; //Синглтон для картинок

	Image allebard; //Картинка алебардиста
	Image allebard_1; //Картинка белого алебардиста
	Image exitBTN; //Картинка кнопки выхода
	Image loadingSplashScreen; //Картинка загрузочного экрана
	Image unitInterface; //Картинка интерфейса юнитов
	Image cursor; //Картинка индикатора движения
	Image steoNotHalt; //Картинка свитка с информацией
	Image steoNotIn; //Картинка свитка с выбором
	Image tileSetGame; //Картинка тайлов
	Image tileSetAnimated; //Картинка тайлов с анимацией

	void load(Image & which, String path); //Загрузка картинки из файла
};

class TextureLoader {
protected:
	TextureLoader();
public:
	~TextureLoader();
	static TextureLoader * TextureLoader::tex; //Синглтон для текстур

	Texture allebard; //Текстура алебардиста
	Texture allebard_1; //Текстура белого алебардиста
	Texture exitBTN; //Текстура кнопки выхода
	Texture loadingSplashScreen; //Текстура загрузочного экрана
	Texture unitInterface; //Текстура интерфейса юнитов
	Texture cursor; //Текстура индикатора движения
	Texture steoNotHalt; //Текстура свитка с информацией
	Texture steoNotIn; //Текстура свитка с выбором
	Texture tileSetGame; //Текстура тайлов
	Texture tileSetAnimated; //Текстура тайлов с анимацией

	void load(Texture & which, Image & from); //Загрузка текстуры из картинки
};

class SpriteLoader {
protected:
	SpriteLoader();
public:
	~SpriteLoader();
	static SpriteLoader * SpriteLoader::sprt; //Синглтон для спрайтов

	Sprite allebard; //Спрайт алебардиста
	Sprite allebard_1; //Спрайт белого алебардиста
	Sprite exitBTN; //Спрайт кнопки выхода
	Sprite loadingSplashScreen; //Спрайт загрузочного экрана
	Sprite unitInterface; //Спрайт интерфейса юнитов
	Sprite cursor; //Спрайт индикатора движения
	Sprite steoNotHalt; //Спрайт свитка с информацией
	Sprite steoNotIn; //Спрайт свитка с выбором
	Sprite tileSetGame; //Спрайт тайлов
	Sprite tileSetAnimated; //Спрайт тайлов с анимацией

	void load(Sprite & which, Texture & from); //Загрузка спрайта из текстуры
};