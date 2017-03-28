#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>
#include <vector>

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
	int _WH; //��������� ������� �� ���� ���� � ������ �������
	bool AttackOn; //��� ��������� �������� ������� �����

public:

	Vector2f * pos;			//������������ ������� �����
	Sprite * sprite;        //��������� �� ������ ������
	Graphic * g;            //����������� ���������
	
	bool _AttackON; //��� ��������� ������� ������� ����� ��� ��������� ������
	bool InspectionTile;	//������������ ��� ��������, ����� ���� ��� ���
	////***����������� �������� ����������� ***

	//***�������***
	bool StepUnit;	
	Sprite spriteGreenTile;
	//***�������***

	Tile() = default;

	string GetLand();	//�������� �����, �� ����� ����� �� �����
	int Get_ID();		//���� �����
	int Get_I();		//������� ����� �� �������
	int Get_J();		//������� ����� �� ��������
	float Get_Dotx();	//������� ��� �����
	float Get_Doty();	//������� ��� �����
	bool  Get_Empty();	//����� ���� ��� ���
	void  Set_Empty(bool);	
	bool  Get_Instantiate();		
	void  Set_Instantiate(bool);	

	float Get__WH();	
	bool  Get_AttackOn();
	void  Set_AttackOn(bool);

	void SetTile(string Flag, int id, int i, int j, int X, int Y, int W, bool instantiate);		//�������� �����
	virtual ~Tile() = default;
};