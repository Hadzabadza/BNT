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
	unsigned maxOrders;		//����������� �������� ��������

public:
	float orders;			//���������� ��������, ������� ����� ������� �����

	vector<Unit> ArmyGamer;	//����� ������ ������

	Player(unsigned max = 5);

	unsigned GetMaxOrders();		//������� ��������� ��������
	void SetMaxOrders(unsigned max);	//������ ��������� ��������
};

class Enemy_1
{
public:
	vector<Unit> ArmyEnemy_1;	//����� ���������� ������
};