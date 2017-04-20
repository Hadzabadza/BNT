#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>
#include <vector>

class Animator;
class Variant;

class Graphic { //Компонент со спрайтлистом и его данными
public:
	Sprite * sheet;
	Vector2i carve;         //Позиция на спрайтлисте
	Vector2f * pos;         //Указатель позиции объекта на сетке
	Vector2f * truePos;     //Указатель позиции объекта на экране
	Vector2i dim;           //Разрешение спрайта
	bool animated = false;  //Флажок анимации для быстрой проверки
	float currentFrame = 0; //Текущий кадр анимации. Применяется в анимированных вариантах графики
	float anSpeed = 0;      //Скорость анимации для анимированных вариантов
	Animator * ar;          //Пустышка для многовариантных анимаций

	Graphic();
	Graphic(Vector2f & _pos, Sprite & _sheet, Vector2i _carve, Vector2i _dim);
	void updateTruePosition();                              //Переводит сеточную позицию в позицию на экране
	virtual void drawTo(RenderWindow & drawTo);				//Нарисовать спрайт
	virtual void drawTo(RenderWindow & drawTo, float time); //Пустышка для анимированных спрайтов
};

class Animated :public Graphic {//Анимированное дополнение к графическому компоненту
public:
	unsigned frames;		//Количество кадров в анимации

	Animated(Graphic & g, unsigned _frames);
	virtual void drawTo(RenderWindow & drawTo, float time); //Нарисовать анимированный спрайт
};

class AnimExtended :public Graphic {//Расширение графического компонента в многовариантную анимацию
public:
	AnimExtended(Graphic & g, Animator & _ar);
	virtual void drawTo(RenderWindow & drawTo, float time); //Нарисовать анимированный спрайт
};


class Animation {//Пакет данных для аниматора
public:
	string name;			 //Название анимации
	unsigned line;			 //Которую линию из спрайтлиста занимает анимация
	unsigned frames;         //Сколько фреймов в анимации
	unsigned peak;           //Фрейм, после которого юнит освобождается для действий
	string cycleTo;          //На какую анимацию перейдет по окончании нынешней
	vector <Variant *> vars; //Применимые варианты

	Animation(string name, int line, int frames, int peak, string cycleTo);
};

class Variant {//Пакет данных для аниматора
public:
	string name;         //Название варианта
	bool active = false; //Активен ли вариант
	int modifier;        //На сколько линий перепрыгнуть, если вариант активен

	Variant(string name, int modifier);
};

class Animator {//Механический компонент расширенной анимации
private:	
	vector <Animation *> anims;
	vector <Variant *> vars;

public:
	unsigned currentAnim = 0;
	AnimExtended * pt; //Parent; Родительский класс анимации

	Animator();
	Animator(string path);
	void carveFrame(Sprite & sheet, Vector2i & dim); //Выставляет на спрайтлисте кадр в зависимости от его номера и размера
	
	Animation & addAnim(string name, int line, int frames, int peak, string cycleTo); //
	void addAnim(Animation & anim);                                                   //Добавляет новую анимацию

	Variant & addVariant(string name, int modifier); //
	void addVariant(Variant & var);					 //Добавляет новый вариант

	bool setAnim(string anim);                       //Проигрывает нужную анимацию по имени, если анимация не найдена, возвращает ложь
	string getCurrentAnim();						 //Возвращает название проигрываемой анимации
	bool isPastPeak();								 //Показывает прошла ли анимация пиковую точку
	
	bool setVariant(string variant, bool state);     //Включает/выключает вариант, возвращает ложь, если не найден вариант с заданным именем
	bool getVariantState(string variant);			 //Возвращает состояние выбранного варианта
	
	bool readFromFile(string path);                  //Считывает параметры из файла
	void stringToAnim(string data);                  //
	void stringToVariant(string data);               //Помощники, переводящие строку в параметры. TODO: можно улучшить, добавив возможность перевода строки в заданные неопределённые переменные
};