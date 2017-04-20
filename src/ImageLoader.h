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
	static ImageLoader * ImageLoader::imgs; //�������� ��� ��������

	Image halberdier; //�������� �����������
	Image halberdierGray; //�������� ������ �����������
	Image exitBTN; //�������� ������ ������
	Image loadingSplashScreen; //�������� ������������ ������
	Image unitInterface; //�������� ���������� ������
	Image cursor; //�������� ���������� ��������
	Image steoNotHalt; //�������� ������ � �����������
	Image steoNotIn; //�������� ������ � �������
	Image tileSetGame; //�������� ������
	Image tileSetAnimated; //�������� ������ � ���������

	void load(Image & which, String path); //�������� �������� �� �����
};

class TextureLoader {
protected:
	TextureLoader();
public:
	~TextureLoader();
	static TextureLoader * TextureLoader::tex; //�������� ��� �������

	Texture halberdier; //�������� �����������
	Texture halberdierGray; //�������� ������ �����������
	Texture exitBTN; //�������� ������ ������
	Texture loadingSplashScreen; //�������� ������������ ������
	Texture unitInterface; //�������� ���������� ������
	Texture cursor; //�������� ���������� ��������
	Texture steoNotHalt; //�������� ������ � �����������
	Texture steoNotIn; //�������� ������ � �������
	Texture tileSetGame; //�������� ������
	Texture tileSetAnimated; //�������� ������ � ���������

	void load(Texture & which, Image & from); //�������� �������� �� ��������
};

class SpriteLoader {
protected:
	SpriteLoader();
public:
	~SpriteLoader();
	static SpriteLoader * SpriteLoader::sprt; //�������� ��� ��������

	Sprite halberdier; //������ �����������
	Sprite halberdierGray; //������ ������ �����������
	Sprite exitBTN; //������ ������ ������
	Sprite loadingSplashScreen; //������ ������������ ������
	Sprite unitInterface; //������ ���������� ������
	Sprite cursor; //������ ���������� ��������
	Sprite steoNotHalt; //������ ������ � �����������
	Sprite steoNotIn; //������ ������ � �������
	Sprite tileSetGame; //������ ������
	Sprite tileSetAnimated; //������ ������ � ���������

	void load(Sprite & which, Texture & from); //�������� ������� �� ��������
};