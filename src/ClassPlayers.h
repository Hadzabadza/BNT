#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace sf;

class Player
{
private:
	float ConstOrders;		//константное значение приказов

public:
	float orders;			//количество приказов, которые может сделать игрок

	vector<Unit> ArmyGamer;	//армия игрока список

	Player();



	float GetConstOrders();		//достаем константу приказов
	void SetConstOrders(float);	//меняем константу приказов
};

class Enemy_1
{
public:
	vector<Unit> ArmyEnemy_1;	//армия противника список
};