#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using namespace sf;

class Tile
{
private:
	string Land;	//для взаимодействия юнитов с тайлами
	int ID, I, J;	//уникальный ID тайла, позиция тайла по координате
	float SetDotX, SetDotY;	//привязанные координаты тайла для перемещения юнита
	bool _Empty;			//тру если тайл занят, фолс если тайл свободен

	////***графическая механика перемещения ***
	bool Instantiate = false;	//во время создания карты используется для проверки установлен тайл, или не
	int _X, _Y, _WH; //поцизиция спрайта на тейл сете и размер спрайта
	float anspeed;			//скорость анимации
	bool AttackOn; //для рисования обычного курсора атаки
public:
	float CurrentFrame;		//количесвто кадров в секунду*
	Sprite s_map;			//*

	
	bool _AttackON; //для рисования жирного курсора атаки при наведение мышкой
	bool InspectionTile;	//используется для проверки, занят тайл или нет
	////***графическая механика перемещения ***

	//***курсоры***
	bool StepUnit;	
	Sprite spriteGreenTile;
	//***курсоры***
public:
	Tile() = default;

	string GetLand();	//сообщаем юниту, на какой тайле он стоит
	int Get_ID();		//айди тайла
	int Get_I();		//позиции тайла по строкам
	int Get_J();		//позиции тайла по стоблцам
	float Get_Dotx();	//позиции для юнита
	float Get_Doty();	//позиции для юнита
	bool  Get_Empty();	//занят тайл или нет
	void  Set_Empty(bool);	
	bool  Get_Instantiate();		
	void  Set_Instantiate(bool);	

	float Get__X();	
	float Get__Y();	
	float Get__WH();	
	float Get_anspeed();
	bool  Get_AttackOn();
	void  Set_AttackOn(bool);

	void GetTile(string,int,int,int,int,int,int,bool);		//создания тайла
	virtual ~Tile() = default;
};