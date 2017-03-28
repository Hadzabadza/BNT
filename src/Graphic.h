#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>
#include <vector>

class Graphic { //��������� �� ������������ � ��� �������
public:
	Sprite * sheet;
	Vector2f scale;        //������ ����������
	Vector2i carve;        //������� �� �����������
	Vector2f * pos;        //������� �� ������, ��������� �� ������� �������
	Vector2i dim;          //���������� �������
	bool animated = false; //������ �������� ��� ������� ��������

	Graphic(Vector2f & _pos, Sprite & _sheet, Vector2i _carve, Vector2i _dim, Vector2f _scale);
	virtual void drawTo(RenderWindow & drawTo); //���������� ������
	virtual void drawTo(RenderWindow & drawTo, float time); //�������� ��� ������������� ������
};

class Animated :public Graphic {//������������� ���������� � ������������ ����������
public:
	unsigned frames; //���������� ������ � ��������
	float currentFrame = 0; //������� ���� ��������
	float anSpeed = 0.004; //�������� ��������

	Animated(Graphic & g, unsigned _frames);
	virtual void drawTo(RenderWindow & drawTo, float time); //���������� ������������� ������
};