#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "ClassTile.h"
#include "Mission.h"
#include "ClassUnit.h"
#include "ClassPlayers.h"
#include "Interface.h"
#include "ImageLoader.h"
#include "Graphic.h"
#include "Settings.h"
#include "HelperFunctions.h"

using namespace std;
using namespace sf;

extern Vector2f mouse;
extern Mission * tnd;
extern float elapsed;

void FunctionPrintToMission_1(AllInterfaceMissiom&); //�������� �����
const int HEIGHT_MAP_1 = 7; //������ ����� ������ 1 ������
const int WIDTH_MAP_1 = 13;//������ ����� ������� 1 ������

void FunctionPrintToMission_2(AllInterfaceMissiom&);
const int HEIGHT_MAP_2 = 12; //������ ����� ������ 1 ������
const int WIDTH_MAP_2 = 12;//������ ����� ������� 1 ������

bool TileIsEmpty(Tile & t);		//�������� �� �� ����� ���� ��� ���

void ViewScroling(View&, Vector2i &, RenderWindow&);	//��������� �� �����

bool InspectionToStep(Unit&, int, int);	//�������� ��� ������ ����� ����� ���� ��������� �������*

void GreenTileOFF();		//������� ���������� �������� ����� ���� ��� ������ ��������� �������*

void GreenToTheTile(Unit&);	//������ �������� �� ��������� ������ � ���� ����� �� ��������� ������� ������ ��������� �������*

void SelectUnitPlayer(Event&, Player&, AllInterfaceMissiom&); //��������� ������� ������ ��� ����� �� ������ ������*

void AttackUnitPlayerToHostile(Event&, Player&, Enemy_1&); //������ ������ ����� ���� ����� ����� ���� ���������� � ����������� ��������� ��������� �������*

void OffSelectUnitToUnitPlayer(Player&); //������� ���������� select, ���� �������� �������� ����� ������

void TileGreenOn(Event&); //������� ���������� ������ �� �������� � �������, ��������� �������*

void LocalAreaInspectionClick(Event&); //��� �������� �����, ��������� �������*

void AbordIsSelectToSelectUnit(Event&, Player&); //���������� ��������� �����, ���� �������� ������� �����, ��������� �������*

void ClickToGOTile(Event&); //�������� � ������� ������� ����� ��������� �����, ��������� �������*

void IsSelectMouseMissiomStatic(Event&, Player &, Enemy_1 &, AllInterfaceMissiom&); //��������� �������� ����� ����� ��� ������

void IsSelectMouseMissiomStaticNON(Event&, Player &, Enemy_1 &); //��������� �������� ����� ����� ��� ������

void DrawSpriteUnit(Player&, Enemy_1&, RenderWindow&); //������ ������� ������ ����� ������

void UpdateUnitArmy(Player&, Enemy_1&);   //���������� �������� �����

void interactionWithMap(Unit&); //������� �������������� ����� � ������ ��������� �������*

void DrawToSpriteMission(RenderWindow&);	//����� �������� ������ �� �����

void DrawSpriteCursor(RenderWindow&);		//������ ������� �������

string Generation_Rand_name();	//��������� ��������� ����

void SelectHostileUnit(Event&, Enemy_1&, Player&, AllInterfaceMissiom&); //������� ��������� ����� ���������� ��� ������ ����������

void DrawInterfaceMission(AllInterfaceMissiom&, RenderWindow&); //������ ��������� �� ��������� �������

void IsSelectMouseMissiomInterace(AllInterfaceMissiom&, Event&, RenderWindow&, Player&); //���������� ������� �� ���������

void UpdateInterface(AllInterfaceMissiom&, Player&, Enemy_1&, Event&);  //�������� �� �� ������� ���� ��� ���

void TileRedOnRedCursor(Event&, Enemy_1&, Player&);	//���� ���� � ������� ����� � �� ������ �������� �� ����� �����

void BroadcastVariablesPlayer(AllInterfaceMissiom&, Unit&);		//��������� ������� ��� �������� ���������� � ���������

void OffSelectUnitToHostilePlayer(Enemy_1&);					//���������� ��������� ���� ����� �������� �������� ����� ����������

void BroadcastVariablesHostile(AllInterfaceMissiom&, Unit&);	//�������� ���������� �� ��������� ���������

void UpdateMissiom(Player&);				//��� ����������� ������� �� ������ ��� ����������� ������, �� ������� ����� � ��

void PressPassStep(AllInterfaceMissiom&, Event&, Player&, RenderWindow&);	//�������� ������� ������� space ��� �������� ����

void StepOnStep(Player&, AllInterfaceMissiom&);			//��������, ���� �� ������ ���������� ��� �� ���������� IU3 �� �� ���������� ���