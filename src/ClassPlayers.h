#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace sf;

class Player
{
private:
	unsigned maxOrders;		//константное значение приказов

public:
	float orders;			//количество приказов, которые может сделать игрок

	vector<Unit> ArmyGamer;	//армия игрока список

	Player(unsigned max = 5);

	unsigned GetMaxOrders();		//достаем константу приказов
	void SetMaxOrders(unsigned max);	//меняем константу приказов
};

class Enemy_1
{
public:
	vector<Unit> ArmyEnemy_1;	//армия противника список
};