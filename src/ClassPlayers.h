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
	float ConstOrders;		//����������� �������� ��������

public:
	float orders;			//���������� ��������, ������� ����� ������� �����

	vector<Unit> ArmyGamer;	//����� ������ ������

	Player();



	float GetConstOrders();		//������� ��������� ��������
	void SetConstOrders(float);	//������ ��������� ��������
};

class Enemy_1
{
public:
	vector<Unit> ArmyEnemy_1;	//����� ���������� ������
};