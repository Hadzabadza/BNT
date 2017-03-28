#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>
#include <vector>

class Graphic { //Компонент со спрайтлистом и его данными
public:
	Sprite * sheet;
	Vector2f scale;        //Фактор увеличения
	Vector2i carve;        //Позиция на спрайтлисте
	Vector2f * pos;        //Позиция на экране, указывает на позицию объекта
	Vector2i dim;          //Разрешение спрайта
	bool animated = false; //Флажок анимации для быстрой проверки

	Graphic(Vector2f & _pos, Sprite & _sheet, Vector2i _carve, Vector2i _dim, Vector2f _scale);
	virtual void drawTo(RenderWindow & drawTo); //Нарисовать спрайт
	virtual void drawTo(RenderWindow & drawTo, float time); //Пустышка для анимированных тайлов
};

class Animated :public Graphic {//Анимированное дополнение к графическому компоненту
public:
	unsigned frames; //Количество кадров в анимации
	float currentFrame = 0; //Текущий кадр анимации
	float anSpeed = 0.004; //Скорость анимации

	Animated(Graphic & g, unsigned _frames);
	virtual void drawTo(RenderWindow & drawTo, float time); //Нарисовать анимированный спрайт
};