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
	int ID, I, J;	//���������� ID �����, ������� ����� �� ����������
	float SetDotX, SetDotY;	//����������� ���������� ����� ��� ����������� �����
	bool _Empty;			//��� ���� ���� �����, ���� ���� ���� ��������

	////***����������� �������� ����������� ***
	bool Instantiate = false;	//�� ����� �������� ����� ������������ ��� �������� ���������� ����, ��� ��
	int _X, _Y, _WH; //��������� ������� �� ���� ���� � ������ �������
	//float anspeed;			//�������� ��������
	bool AttackOn; //��� ��������� �������� ������� �����
public:
	unsigned frames; //����� ���������� ������
	float CurrentFrame;		//���������� ������ � �������*
	float scale;            //������ ����������

	Sprite * sprite;        //��������� �� ������ ������
	Graphic * g;            //����������� ���������

	//bool animated=false; //��� ������������� ������
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

	float Get__X();	
	float Get__Y();	
	float Get__WH();	
	//float Get_anspeed();
	bool  Get_AttackOn();
	void  Set_AttackOn(bool);

	void SetTile(string Flag, int id, int j, int i, int X, int Y, int W, bool instantiate);		//�������� �����
	virtual ~Tile() = default;
};