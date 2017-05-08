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

void FunctionPrintToMission_1(AllInterfaceMissiom&); //создание карты
const int HEIGHT_MAP_1 = 7; //размер карты строки 1 миссия
const int WIDTH_MAP_1 = 13;//размер карты столбцы 1 миссия

void FunctionPrintToMission_2(AllInterfaceMissiom&);
const int HEIGHT_MAP_2 = 12; //размер карты строки 1 миссия
const int WIDTH_MAP_2 = 12;//размер карты столбцы 1 миссия

bool TileIsEmpty(Tile & t);		//проверка на то занят тайл или нет

void ViewScroling(View&, Vector2i &, RenderWindow&);	//скроллинг до краев

bool InspectionToStep(Unit&, int, int);	//проверка как далеко может пойти юнит локальная функция*

void GreenTileOFF();		//функция отключения зеленого тайла шага ддя юнитов локальная функция*

void GreenToTheTile(Unit&);	//делаем проверку на дальность ходьбы и даем добро на рисования зеленых тайлов локальная функция*

void SelectUnitPlayer(Event&, Player&, AllInterfaceMissiom&); //локальная функция миссия для клика по юнитам игрока*

void AttackUnitPlayerToHostile(Event&, Player&, Enemy_1&); //рисуем курсор атаки если рядом стоит юнит противника и возможность атаковать локальная функция*

void OffSelectUnitToUnitPlayer(Player&); //функция отключение select, если повторно выделить юнита игрока

void TileGreenOn(Event&); //функция окрашивает курсор из зеленого в красный, локальная функция*

void LocalAreaInspectionClick(Event&); //для проверки тайла, локальная функция*

void AbordIsSelectToSelectUnit(Event&, Player&); //сбрасываем выделения юнита, если выделяем другого юнита, локальная функция*

void ClickToGOTile(Event&); //кликание в область которую нужно отправить юнита, локальная функция*

void IsSelectMouseMissiomStatic(Event&, Player &, Enemy_1 &, AllInterfaceMissiom&); //глобальна яфункция эвент мышки для миссии

void IsSelectMouseMissiomStaticNON(Event&, Player &, Enemy_1 &); //глобальна яфункция эвент мышки для миссии

void DrawSpriteUnit(Player&, Enemy_1&, RenderWindow&); //рисуем спрайты юнитов армии игрока

void UpdateUnitArmy(Player&, Enemy_1&);   //обновление юнитовна карте

void interactionWithMap(Unit&); //функция взаимодействия юнита с тайлом локальная функция*

void DrawToSpriteMission(RenderWindow&);	//вывод спрайтов миссии на экран

void DrawSpriteCursor(RenderWindow&);		//рисуем спрайты курсора

string Generation_Rand_name();	//рандомная генерация имен

void SelectHostileUnit(Event&, Enemy_1&, Player&, AllInterfaceMissiom&); //функция выделения юнита противника для вывода информации

void DrawInterfaceMission(AllInterfaceMissiom&, RenderWindow&); //рисует интерфейс на локальных миссиях

void IsSelectMouseMissiomInterace(AllInterfaceMissiom&, Event&, RenderWindow&, Player&); //обработчик нажатий на интерфейс

void UpdateInterface(AllInterfaceMissiom&, Player&, Enemy_1&, Event&);  //проверка на то выделен юнит или нет

void TileRedOnRedCursor(Event&, Enemy_1&, Player&);	//если юнит в радиусе атаки и мы мышкой попадаем на этого юнита

void BroadcastVariablesPlayer(AllInterfaceMissiom&, Unit&);		//локальная функция для передачи переменных в интерфейс

void OffSelectUnitToHostilePlayer(Enemy_1&);					//сбрасываем выделение если опять пытаемся выделить юнита противника

void BroadcastVariablesHostile(AllInterfaceMissiom&, Unit&);	//передача информации во вражеский интерфейс

void UpdateMissiom(Player&);				//тут проверяются условие на задачи для прохождения миссии, на пропуск ходов и тд

void PressPassStep(AllInterfaceMissiom&, Event&, Player&, RenderWindow&);	//проверка нажатии клавиши space для пропуска хода

void StepOnStep(Player&, AllInterfaceMissiom&);			//проверка, если мы нажали пропустить ход на интерфейсе IU3 то мы пропускаем ход