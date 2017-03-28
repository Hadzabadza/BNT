#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>
#include <vector>

class Graphic { //Контейнер для спрайтлиста и его данных
public:
	Sprite * sheet;
	Vector2f scale;        //Фактор увеличения
	Vector2f carve;        //Позиция на спрайтлисте
	Vector2f pos;          //Позиция на экране
	Vector2f dim;          //Ширина и высота спрайта
	bool animated = false; //Флажок анимации для быстрой проверки

	Graphic(Sprite & _sheet, Vector2f _scale, Vector2f _carve, Vector2f _pos, Vector2f _dim);
	virtual void drawTo(RenderWindow & drawTo); //Нарисовать спрайт
	virtual void drawTo(RenderWindow & drawTo, float time); //Пустышка для анимированных тайлов
};

class Animated :public Graphic {
public:
	unsigned frames;
	float currentFrame = 0;
	float anspeed = 0.004;

	Animated(Graphic & g, unsigned _frames);
	void drawTo(RenderWindow & drawTo, float time); //Нарисовать спрайт
};