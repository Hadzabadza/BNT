#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>
#include <vector>

class Graphic { //��������� �� ������������ � ��� �������
public:
	Sprite * sheet;
	Vector2f scale;        //������ ����������
	Vector2f carve;        //������� �� �����������
	Vector2f pos;          //������� �� ������, ��������� �� ������� �������
	Vector2f dim;          //���������� �������
	bool animated = false; //������ �������� ��� ������� ��������

	Graphic(Sprite & _sheet, Vector2f _scale, Vector2f _carve, Vector2f _pos, Vector2f _dim);
	virtual void drawTo(RenderWindow & drawTo); //���������� ������
	virtual void drawTo(RenderWindow & drawTo, float time); //�������� ��� ������������� ������
};

class Animated :public Graphic {//������������� ���������� � ������������ ����������
public:
	unsigned frames; //���������� ������ � ��������
	float currentFrame = 0; //������� ���� ��������
	float anSpeed = 0.004; //�������� ��������

	Animated(Graphic & g, unsigned _frames);
	virtual void drawTo(RenderWindow & drawTo, float time); //���������� ������
};