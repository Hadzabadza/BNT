#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace sf;

class AnimExtended;
class Mission;

class Unit
{	
public:
	////***����������� �������� ������***
	string Test;	//��� ���������
	float w, h, x, y, CurrentFrame, anspeed, speed, distance; //w, h- ������� ������� ����, x,y ���������� ��� ��������� ������, CurrentFrame ����� �����, anspeed - �������� ��������, speed - �������� ��������, distance ������� ���������� ������� ����� ������
	Vector2f moveTo;  //���������� �����, � ������� ��� ����� ������ ���������
	//float spriteScale=2;
	int Sprite_X, Sprite_Y; //�������� ������� �� ������, Sprite_Y ������������ ��� ��������� ��������
	//int _I, _J;		//i j ����� � ������ ������� �� ���������
	Vector2f * pos;   //������� �� �������� �����������
	int Id, faction_choice;			//���������� id ����� faction_choice - ����� ������� ��� �������� �����
	bool isMove, isSelect;		//ismove ���� ����, isselect ���� �������
	bool _Attack;				//��� ������������� �������� �����
	bool ReceivingPricking;            //��� ������������ �������� ��������� ����� �� ��������
	bool ReceivingCutting;				//��� ������������ �������� ��������� ����� �� ��������
	int Receiving_int;			//��� ������������ ����� ���������� ��������� �����
	float CurrentFrameToAttackReceiving; //����� ��� ��������� ����� � ��� ��������� �����
	float calculation_distance_x_Attack, calculation_distance_y_Attack, calculation_distance_Attack; //������� ��������� ��������� �������� ��������� �����
	float calculation_distance_x_Step, calculation_distance_y_Step, calculation_distance_Step;	//��� ������� ��������� ��������
	bool Pricking;			//������� ������ ��� �������
	bool Cutting;			//������� ������
	bool isSelectHostile;	//��� ��������� ���������� �����
	bool hurt;				//���� ����� �����, �� �� ������������� �� �������� ������ �������
	int lvl;				//��� ������

	Graphic * animation;
	////***����������� �������� ������***

	////***����������� �������� ������***
	static Unit * Unit::NIL;//�������� ��� ��������
	Tile * ground;          //����, �� ������� �����
	int UnitToUnit;			//������������� �� �������� ����� ������������ ������ ����� �� �������
	Unit * gets_lyuley;     //���� ������� �����
	string _Land;			//����� �� ������� ����� ����
	float Morale, Stamina, ConstMorale, ConstStamina;	//������ ������ � ������������ ������ 
	int PeopleLive, PeopleHealth;	//������� � ������� ������� ������� � ������
	int ConstPeopleLive, ConstPeopleHealth; //����������� ��������, ������� � ������� ������� ������� � ������
	bool Life;				//��� �����, ��� �����
	string ClassUnit;		//����� �����, � ������� ����������
	int Hp, HpHurt, Attack; //��, �� ��� �������, �����, ������
	float radius, Defense;			//������ ����� �����
	int CouterAttack, ConstCouterAttack;	//���������� ����, ������� ����� ������� ���� �� ���
	int CouterStep, ConstCouterStep;	//���������� �����, ������� ���� ����� ������� �� ���
	int Ammo;			//���������� ����������� � ���������� �������
	float const_step, step, fast_step;					//��������� ������ �����
	bool fast_step_True;	//�������� ������� ������
	////***����������� �������� ������***

protected:
	Unit();
public:

	Unit(float, float, float, float, int, int, int, int, string, int, string);		//�������� �����

	void To_Move();	   //������� ��������,
	void Update();	   //������� ������ �����
	void AttackToAttack(Unit&); //������ ���������
	void damageTarget();               //��������� ������
	void AnimationToAttack();	   //�������� �����
	void ReceivingFace();		   //�������� ��������� �����
	void Halt();
	void drawTo(RenderWindow & window);
};