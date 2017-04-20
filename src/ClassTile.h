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
	string Land;	//��� �������������� ������ � �������
	int ID;	//���������� ID �����
	float SetDotX, SetDotY;	//����������� ���������� ����� ��� ����������� �����
	bool _Empty;			//��� ���� ���� �����, ���� ���� ���� ��������

	////***����������� �������� ����������� ***
	bool Instantiate = false;	//�� ����� �������� ����� ������������ ��� �������� ���������� ����, ��� ��
	bool AttackOn; //��� ��������� �������� ������� �����

public:

	Vector2f * pos;			//������������ ������� �����
	Graphic * g;            //����������� ���������
	
	bool _AttackON; //��� ��������� ������� ������� ����� ��� ��������� ������
	bool InspectionTile;	//������������ ��� ��������, ����� ���� ��� ���
	////***����������� �������� ����������� ***

	//***�������***
	bool StepUnit;	
	Sprite spriteGreenTile;
	//***�������***

	Tile();

	string GetLand();	//�������� �����, �� ����� ����� �� �����
	int Get_ID();		//���� �����
	float Get_X();		//������� ����� �� �������
	float Get_Y();		//������� ����� �� ��������
	float Get_Dotx();	//������� ��� �����
	float Get_Doty();	//������� ��� �����
	bool  Get_Empty();	//����� ���� ��� ���
	void  Set_Empty(bool);	
	bool  Get_Instantiate();		
	void  Set_Instantiate(bool);	

	int GetWidth();	
	int GetHeight();
	bool  Get_AttackOn();
	void  Set_AttackOn(bool);

	void SetTile(string Flag, bool instantiate, int id, float posX, float posY, int carveX, int carveY, int width,int height = 0, int frames=0);       //��������� ���������� �����
	virtual ~Tile() = default;
};