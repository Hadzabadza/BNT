#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>
#include <vector>

class Animator;

class Graphic { //Компонент со спрайтлистом и его данными
public:
	Sprite * sheet;
	//Vector2f scale;        //Фактор увеличения
	Vector2i carve;        //Позиция на спрайтлисте
	Vector2f * pos;        //Позиция на экране, указывает на позицию объекта
	Vector2i dim;          //Разрешение спрайта
	bool animated = false; //Флажок анимации для быстрой проверки
	Animator * ar;         //Пустышка для многовариантных анимаций

	Graphic(Vector2f & _pos, Sprite & _sheet, Vector2i _carve, Vector2i _dim);
	virtual void drawTo(RenderWindow & drawTo);				//Нарисовать спрайт
	virtual void drawTo(RenderWindow & drawTo, float time); //Пустышка для анимированных спрайтов
};

class Animated :public Graphic {//Анимированное дополнение к графическому компоненту
public:
	unsigned frames;		//Количество кадров в анимации
	float currentFrame = 0; //Текущий кадр анимации
	float anSpeed = 0.004;  //Скорость анимации

	Animated(Graphic & g, unsigned _frames);
	virtual void drawTo(RenderWindow & drawTo, float time); //Нарисовать анимированный спрайт
};

class AnimExtended :public Graphic {//Расширение графического компонента в многовариантную анимацию
public:
	float currentFrame = 0; //Текущий кадр анимации
	float anSpeed = 0.004;  //Скорость анимации
	Animator * ar;          //Компонент контроля анимации

	AnimExtended(Graphic & g, Animator & _ar);
	virtual void drawTo(RenderWindow & drawTo, float time); //Нарисовать анимированный спрайт
};


class Animation {//Пакет данных для аниматора
public:
	string name;      //Название анимации
	unsigned line;    //Которую линию из спрайтлиста занимает анимация
	unsigned frames;  //Сколько фреймов в анимации
	string cycleTo;   //На какую анимацию перейдет по окончании нынешней

	Animation(string name, int line, int frames, string cycleTo);
};

class Animator {//Механический компонент расширенной анимации
private:	
	vector <Animation *> anims;
public:
	unsigned currentAnim = 0;

	Animator();
	Animator(string path);
	void carveFrame(Sprite & sheet, float & currentFrame, Vector2i & dim);//Выставляет на спрайтлисте кадр в зависимости от его номера и размера
	bool setAnim(string anim);                                            //Проигрывает нужную анимацию по имени
	void addAnim(string name, int line, int frames, string cycleTo);      //
	void addAnim(Animation & anim);                                       //Добавляет новую анимацию
	bool readFromFile(string path);                                       //Считывает параметры из файла
	void stringToAnim(string data);                                       //Помощник, переводящий строку в параметры. TODO: можно улучшить, добавив возможность перевода строки в заданные неопределённые переменные
};