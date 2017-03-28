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

using namespace std;
using namespace sf;

void FunctionPrintToMission_1(Mission&, float, AllInterfaceMissiom&); //�������� �����
const int HEIGHT_MAP_1 = 7; //������ ����� ������ 1 ������
const int WIDTH_MAP_1 = 13;//������ ����� ������� 1 ������

void FunctionPrintToMission_2(Mission&, float, AllInterfaceMissiom&);
const int HEIGHT_MAP_2 = 12; //������ ����� ������ 1 ������
const int WIDTH_MAP_2 = 12;//������ ����� ������� 1 ������

void TileIsEmpty(Mission&, Player&, Enemy_1&);		//�������� �� �� ����� ���� ��� ���

void ViewScroling(View&, Vector2i&, float&, RenderWindow&, Mission&);	//��������� �� �����

bool InspectionToStep(Unit&, int, int);	//�������� ��� ������ ����� ����� ���� ��������� �������*

void GreenTileOFF(Mission&);		//������� ���������� �������� ����� ���� ��� ������ ��������� �������*

void GreenToTheTile(Unit&, Mission&);	//������ �������� �� ��������� ������ � ���� ����� �� ��������� ������� ������ ��������� �������*

void SelectUnitPlayer(Event&, Vector2f&, Player&, Mission&, AllInterfaceMissiom&); //��������� ������� ������ ��� ����� �� ������ ������*

void AttackUnitPlayerToHostile(Event&, Vector2f&, Player&, Enemy_1&, Mission&); //������ ������ ����� ���� ����� ����� ���� ���������� � ����������� ��������� ��������� �������*

void OffSelectUnitToUnitPlayer(Player&, Mission&); //������� ���������� select, ���� �������� �������� ����� ������

void TileGreenOn(Event&, Vector2f&, Mission&); //������� ���������� ������ �� �������� � �������, ��������� �������*

void LocalAreaInspectionClick(Event&, Vector2f&, Mission&); //��� �������� �����, ��������� �������*

void AbordIsSelectToSelectUnit(Event&, Vector2f&, Player&, Mission&); //���������� ��������� �����, ���� �������� ������� �����, ��������� �������*

void ClickToGOTile(Event&, Vector2f&, Player&, Mission&); //�������� � ������� ������� ����� ��������� �����, ��������� �������*

void IsSelectMouseMissiomStatic(Event&, Vector2f&, Player &, Enemy_1 &, Mission&, float, AllInterfaceMissiom&); //��������� �������� ����� ����� ��� ������

void IsSelectMouseMissiomStaticNON(Event&, Vector2f&, Player &, Enemy_1 &, Mission&); //��������� �������� ����� ����� ��� ������

void DrawSpriteUnit(Player&, Enemy_1&, RenderWindow&, float); //������ ������� ������ ����� ������

void UpdateUnitArmy(Player&, Enemy_1&, Mission&, float);   //���������� �������� �����

void interactionWithMap(Unit&, Mission&); //������� �������������� ����� � ������ ��������� �������*

void DrawToSpriteMission(RenderWindow&, float, Mission&);	//����� �������� ������ �� �����

void DrawSpriteCursor(RenderWindow&, float, Mission&);		//������ ������� �������

string Generation_Rand_name();	//��������� ��������� ����

void SelectHostileUnit(Event&, Vector2f&, Enemy_1&, Mission&, Player&, AllInterfaceMissiom&); //������� ��������� ����� ���������� ��� ������ ����������

void DrawInterfaceMission(AllInterfaceMissiom&, RenderWindow&, Mission&); //������ ��������� �� ��������� �������

void IsSelectMouseMissiomInterace(AllInterfaceMissiom&, Event&, RenderWindow&, Mission&, Player&, float); //���������� ������� �� ���������

void UpdateInterface(AllInterfaceMissiom&, Player&, Enemy_1&, Mission&, Event&, Vector2f&, float);  //�������� �� �� ������� ���� ��� ���

void TileRedOnRedCursor(Event&, Vector2f&, Mission&, Enemy_1&, Player&);	//���� ���� � ������� ����� � �� ������ �������� �� ����� �����

void BroadcastVariablesPlayer(AllInterfaceMissiom&, Unit&);		//��������� ������� ��� �������� ���������� � ���������

void OffSelectUnitToHostilePlayer(Enemy_1&, Mission&);					//���������� ��������� ���� ����� �������� �������� ����� ����������

void BroadcastVariablesHostile(AllInterfaceMissiom&, Unit&);	//�������� ���������� �� ��������� ���������

void UpdateMissiom(Mission&, Player&, float);				//��� ����������� ������� �� ������ ��� ����������� ������, �� ������� ����� � ��

void PressPassStep(AllInterfaceMissiom&, Event&, Player&, Mission&, RenderWindow&);	//�������� ������� ������� space ��� �������� ����

void StepOnStep(Player&, AllInterfaceMissiom&);			//��������, ���� �� ������ ���������� ��� �� ���������� IU3 �� �� ���������� ���