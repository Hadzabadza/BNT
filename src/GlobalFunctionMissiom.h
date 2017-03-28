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

void FunctionPrintToMission_1(Mission&, float, AllInterfaceMissiom&); //создание карты
const int HEIGHT_MAP_1 = 7; //размер карты строки 1 миссия
const int WIDTH_MAP_1 = 13;//размер карты столбцы 1 миссия

void FunctionPrintToMission_2(Mission&, float, AllInterfaceMissiom&);
const int HEIGHT_MAP_2 = 12; //размер карты строки 1 миссия
const int WIDTH_MAP_2 = 12;//размер карты столбцы 1 миссия

void TileIsEmpty(Mission&, Player&, Enemy_1&);		//проверка на то занят тайл или нет

void ViewScroling(View&, Vector2i&, float&, RenderWindow&, Mission&);	//скроллинг до краев

bool InspectionToStep(Unit&, int, int);	//проверка как далеко может пойти юнит локальная функция*

void GreenTileOFF(Mission&);		//функция отключения зеленого тайла шага ддя юнитов локальная функция*

void GreenToTheTile(Unit&, Mission&);	//делаем проверку на дальность ходьбы и даем добро на рисования зеленых тайлов локальная функция*

void SelectUnitPlayer(Event&, Vector2f&, Player&, Mission&, AllInterfaceMissiom&); //локальная функция миссия для клика по юнитам игрока*

void AttackUnitPlayerToHostile(Event&, Vector2f&, Player&, Enemy_1&, Mission&); //рисуем курсор атаки если рядом стоит юнит противника и возможность атаковать локальная функция*

void OffSelectUnitToUnitPlayer(Player&, Mission&); //функция отключение select, если повторно выделить юнита игрока

void TileGreenOn(Event&, Vector2f&, Mission&); //функция окрашивает курсор из зеленого в красный, локальная функция*

void LocalAreaInspectionClick(Event&, Vector2f&, Mission&); //для проверки тайла, локальная функция*

void AbordIsSelectToSelectUnit(Event&, Vector2f&, Player&, Mission&); //сбрасываем выделения юнита, если выделяем другого юнита, локальная функция*

void ClickToGOTile(Event&, Vector2f&, Player&, Mission&); //кликание в область которую нужно отправить юнита, локальная функция*

void IsSelectMouseMissiomStatic(Event&, Vector2f&, Player &, Enemy_1 &, Mission&, float, AllInterfaceMissiom&); //глобальна яфункция эвент мышки для миссии

void IsSelectMouseMissiomStaticNON(Event&, Vector2f&, Player &, Enemy_1 &, Mission&); //глобальна яфункция эвент мышки для миссии

void DrawSpriteUnit(Player&, Enemy_1&, RenderWindow&, float); //рисуем спрайты юнитов армии игрока

void UpdateUnitArmy(Player&, Enemy_1&, Mission&, float);   //обновление юнитовна карте

void interactionWithMap(Unit&, Mission&); //функция взаимодействия юнита с тайлом локальная функция*

void DrawToSpriteMission(RenderWindow&, float, Mission&);	//вывод спрайтов миссии на экран

void DrawSpriteCursor(RenderWindow&, float, Mission&);		//рисуем спрайты курсора

string Generation_Rand_name();	//рандомная генерация имен

void SelectHostileUnit(Event&, Vector2f&, Enemy_1&, Mission&, Player&, AllInterfaceMissiom&); //функция выделения юнита противника для вывода информации

void DrawInterfaceMission(AllInterfaceMissiom&, RenderWindow&, Mission&); //рисует интерфейс на локальных миссиях

void IsSelectMouseMissiomInterace(AllInterfaceMissiom&, Event&, RenderWindow&, Mission&, Player&, float); //обработчик нажатий на интерфейс

void UpdateInterface(AllInterfaceMissiom&, Player&, Enemy_1&, Mission&, Event&, Vector2f&, float);  //проверка на то выделен юнит или нет

void TileRedOnRedCursor(Event&, Vector2f&, Mission&, Enemy_1&, Player&);	//если юнит в радиусе атаки и мы мышкой попадаем на этого юнита

void BroadcastVariablesPlayer(AllInterfaceMissiom&, Unit&);		//локальная функция для передачи переменных в интерфейс

void OffSelectUnitToHostilePlayer(Enemy_1&, Mission&);					//сбрасываем выделение если опять пытаемся выделить юнита противника

void BroadcastVariablesHostile(AllInterfaceMissiom&, Unit&);	//передача информации во вражеский интерфейс

void UpdateMissiom(Mission&, Player&, float);				//тут проверяются условие на задачи для прохождения миссии, на пропуск ходов и тд

void PressPassStep(AllInterfaceMissiom&, Event&, Player&, Mission&, RenderWindow&);	//проверка нажатии клавиши space для пропуска хода

void StepOnStep(Player&, AllInterfaceMissiom&);			//проверка, если мы нажали пропустить ход на интерфейсе IU3 то мы пропускаем ход