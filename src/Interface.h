#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;
using namespace sf;

class To_Exit		//������� ����������
{
private:
	Sprite sprite_exit;
	Vector2f center;
	Vector2f size;
	bool NoExit;

public:
	To_Exit();

	void DrawExit(RenderWindow&);

	void IsSelectExit(Event&, RenderWindow&);
};

class InformUnitPlayer
{
public:
	Sprite sprite_infoUnitPlayer; //������ ����������
	Vector2f center1;		//��� ��������� ������ �� ������ 
	Vector2f size1;			//��� ��������� ������ �� ������ 

	Text textInfoSquad;			//���������� � �������� ������
	Text textInfoMorale;		//���������� � ��������� ���������
	Text textInfoStamina;		//���������� � ������������

	Text textInfoComanderName;	//��� �������� ������

	Text textInfoStrength;		//���������� ��������� ������
	Text textInfoLvl;			//��� ������

	Text textInfoStepCouter;	//���������� �����
	Text textInfoAttackpCouter;	//���������� ����
	Text textInfoAmmo;			//���������� �����������

	Font fontText;				//�����
	Font fontText2;				//��� ���������� � ���������� ������ � ������

	ostringstream _String;		//������ ���������� ������� � ������ �������
	ostringstream _String2;		//������ ���������� ������� � ������ �� ��������
	ostringstream Teamp_1;		//��� ������ ��� � ������ ����������

	Sprite sprite_infoUnitPlayer2;//����� ����� �� ����������

	bool _draw;					//�������� ��������� ��� ���
	bool _hurt;					//���� ����� ����� �� ������� ������������ ����� 
	bool selectionStamina, selectionMorale;				//��� ������ ����� ����������� ������
	int _UnitToUnit;			//���������� ��� ������
	string nameComandor;		//��� ��������� ��������� �� ���������
	bool cross;					//��� ������� ��������
	bool missingStep;			//��� �������� ����
	bool Fast;					//������� � ���, ��� ������ ������� �������� ����
	
	int UnitId;					//ID ����� ��� �������� ������� ������
	int People, ConstPeople;					//��� ������ ������� �������
	int HurtPeople, ConstHurtPeople;				//��� ������ ������� �������
	int SelectLvl;								//��� ������
	int CouterS, CouterA, ConstCoterS, ConstCouterA;	//��� �������� ����� ����� � ����� ����� 

	int CouterStepUnit, CouterAttackUnit, CouterAmmo;		//����, �����, �������
	ostringstream _CouterStepUnit, _CouterAttackUnit, _CouterAmmo;	//��� ������

	Sprite sprite_Black;//������
	Sprite sprite_Red;//�������
	Sprite sprite_Green;//�������

	Sprite sprite_infoUnitPlayer_Fast;//������ ������� ����

	float StaminaUnit, MoraleUnit, ConstStaminaUnit, ConstMoraleUnit;			//������������ �� ��������� - ��������� ��������� �� ���������

	InformUnitPlayer();
	void IsSelectInformUnitPlayer(Event&, RenderWindow&, Mission&);
	void DrawStrips(RenderWindow&);
	void DrawInfo(RenderWindow&);	//������� �� �����
	int IntToInt(int, int);
};

class InformUnitHostile
{
public:
	bool _draw2;					//�������� ��������� ��� ���
	bool _hurt2;					//���� ����� ����� �� ������� ������������ ����� 
	bool selectionStamina2, selectionMorale2;				//��� ������ ����� ����������� ������
	int _UnitToUnit2;			//���������� ��� ������
	string nameComandor2;		//��� ��������� ��������� �� ���������
	bool cross2;					//��� ������� ��������
	Vector2f center2;		//��� ��������� ������ �� ������ 
	Vector2f size2;			//��� ��������� ������ �� ������ 

	float StaminaUnit2, MoraleUnit2, ConstStaminaUnit2, ConstMoraleUnit2;
	
	int People2, ConstPeople2;					//��� ������ ������� �������
	int HurtPeople2, ConstHurtPeople2;				//��� ������ ������� �������
	int SelectLvl2;

	Sprite sprite_infoUnitPlayer3;//������ ����������

	Sprite sprite_infoUnitPlayer4;//����� �����

	Text textInfoSquad2;			//���������� � �������� ������
	Text textInfoMorale2;		//���������� � ��������� ���������
	Text textInfoStamina2;		//���������� � ������������

	Text textInfoComanderName2;	//��� �������� ������

	Text textInfoStrength2;		//���������� ��������� ������
	Text textInfoLvl2;			//��� ������

	Font fontText4;				//�����
	Font fontText5;				//��� ���������� � ���������� ������ � ������

	ostringstream _String3;		//������ ���������� ������� � ������ �������
	ostringstream _String4;		//������ ���������� ������� � ������ �� ��������
	ostringstream Teamp_2;		//��� ������ ��� � ������ ����������

	Sprite sprite_Black2;//������
	Sprite sprite_Red2;//�������
	Sprite sprite_Green2;//�������

	InformUnitHostile();
	void DrawInfoHostile(RenderWindow&);	//������� �� �����
	void DrawStripsHostile(RenderWindow&);
	int IntToInt2(int, int);
	void IsSelectInformUnitHostile(Event&, RenderWindow&);
};

class SureStupe
{
public:
	Font fontText5;				//�����

	Vector2f center_SureStupe;		//��� ��������� ������ �� ������ 
	Vector2f size_SureStupe;			//��� ��������� ������ �� ������

	Sprite sprite_infoUnitPlayer_SureStupe;//������ ����������
	Text textInfoSureStupe;
	bool _draw_SureStupe;
	bool cross_SureStupe;

	void IsSelectSureStupee(Event&, RenderWindow&, Mission&);
	void IsDrawSureStupee(RenderWindow&, Mission&);
	SureStupe();
};

class SureHalt
{
public:
	Font fontText_SureHalt;				//�����

	Vector2f center_SureHalt;		//��� ��������� ������ �� ������ 
	Vector2f size_SureHalt;			//��� ��������� ������ �� ������

	Sprite sprite_infoUnitPlayer_SureHalt;//������ ����������
	Text textInfoSureHalt;
	bool _draw_SureHalt;
	bool cross_SureHalt;

	void IsSelectSureHalt(Event&, RenderWindow&, Mission&);
	void IsDrawSureHalt(RenderWindow&, Mission&);
	SureHalt();
};

class InterfaceMap
{
public:
	int Order, _CouterS; //������� � ����� ���

	Vector2f center_SureStupe_InterfaceMap;		//��� ��������� ������ �� ������ 
	Vector2f size_SureStupe_InterfaceMap;			//��� ��������� ������ �� ������

	Sprite sprite_InterfaceMap;//������ ����������

	Text StepCouter_InterfaceMap;			//���� � ������
	Text StepText_InterfaceMap;		//����� ���

	Text OrderCouter_InterfaceMap;			//������� � ������
	Text OrderText_InterfaceMap;		//����� ��������

	ostringstream _StepCouter_InterfaceMap;		//������ ���������� ������� � ������ �������
	ostringstream _OrderCouter_InterfaceMap;		//������ ���������� ������� � ������ �� ��������

	Font fontText_InterfaceMap1;				//�����
	Font fontText_InterfaceMap2;				//��� ���������� � ���������� ������ � ������

	InterfaceMap();
	void IsDrawInterfaceMap(RenderWindow&);
	void IsSelectInterfaceMap(Event&, RenderWindow&, Mission&, Player&);
};

class TrayUnit_index
{
public:
	int ID_Unit;			//���� �����
	int UnitToUnit_ID;		//���������� ������ ����� �� �������
	bool Life;				//��� ����, ��� �����
	float Couter_Step_Unit, Const_Couter_Step;	//������� �����
	float Couter_Attack, Const_Couter_Attack;	//������� ����
	float X_Position, Y_Position;				//������� ���������� �������
	bool IsSelectUnit;

	Sprite sprite_TrayUnit;		//������ ������

	Sprite sprite_TrayUnit_Head;	//������ ����� �����

	Sprite sprite_TrayUnit_Dot;	//�����

	TrayUnit_index();
};

class TrayUnit
{
public:
	int SizeArmyGamer;
	Vector2f center_SureStupe_TrayUnit;		//��� ��������� �� ������ 
	Vector2f size_SureStupe_TrayUnit;			//��� ��������� �� ������

	Sprite sprite_TrayUnit_end;	//������ ��������� �����

	vector<TrayUnit_index> ListUnit;	//���������� ������ ������

	TrayUnit();
	void UpdateTrayUnit(vector<Unit>&);
	void DrawTrayUnit(RenderWindow&);
	void IsSelecThisTray();
};

class AllInterfaceMissiom
{
public:
	To_Exit Ex;				//������ ������
	InformUnitPlayer IUP;	//���������� � ������ ������ � ������������� ������
	InformUnitHostile IUP2;	//���������� � ������ ����������
	SureStupe IUP3;		//���� ����� ����� �������� ��� ����� ���� ���������� ��� �� ���������
	InterfaceMap _map;	//��������� �����
	SureHalt HaltNo;	//��� ������ � ���, ��� ���� �� ����� ���������
	TrayUnit Tray;		//������� ������ ������
};