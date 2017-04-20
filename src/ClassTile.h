#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>
#include <vector>
#include "Settings.h"

class Graphic;

using namespace std;
using namespace sf;

class Tile
{
private:
	string Land;	//для взаимодействия юнитов с тайлами
	int ID;	//уникальный ID тайла
	float SetDotX, SetDotY;	//привязанные координаты тайла для перемещения юнита
	bool _Empty;			//тру если тайл занят, фолс если тайл свободен

	////***графическая механика перемещения ***
	bool Instantiate = false;	//во время создания карты используется для проверки установлен тайл, или не
	bool AttackOn; //для рисования обычного курсора атаки

public:

	Vector2f * pos;			//Координатная позиция тайла
	Graphic * g;            //Графический компонент
	
	bool _AttackON; //для рисования жирного курсора атаки при наведение мышкой
	bool InspectionTile;	//используется для проверки, занят тайл или нет
	////***графическая механика перемещения ***

	//***курсоры***
	bool StepUnit;	
	Sprite spriteGreenTile;
	//***курсоры***

	Tile();

	string GetLand();	//сообщаем юниту, на какой тайле он стоит
	int Get_ID();		//айди тайла
	float Get_X();		//позиции тайла по строкам
	float Get_Y();		//позиции тайла по стоблцам
	float Get_Dotx();	//позиции для юнита
	float Get_Doty();	//позиции для юнита
	bool  Get_Empty();	//занят тайл или нет
	void  Set_Empty(bool);	
	bool  Get_Instantiate();		
	void  Set_Instantiate(bool);	

	int GetWidth();	
	int GetHeight();
	bool  Get_AttackOn();
	void  Set_AttackOn(bool);

	void SetTile(string Flag, bool instantiate, int id, float posX, float posY, int carveX, int carveY, int width,int height = 0, int frames=0);       //Установка параметров тайла
	virtual ~Tile() = default;
};