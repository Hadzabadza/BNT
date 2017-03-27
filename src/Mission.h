#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace sf;

class Mission
{
public:
	Vector2f center_Mission;		//для центровки по камере 
	Vector2f size_Mission;			//для центровки по камере 

	int WIDTH_MAP, HEIGHT_MAP;		//ширина длина игрового поля
	float id_tile;
	bool MovementPlayer;			//ход игрока
	bool screen_lock;				//для блокировки экрана
	bool PressedSpace;				//для нажатие клавиши спейс
	float FrameSpace;					//засикаем время для клавиши space
	bool StepPlayerInspection;
	int CouterS;					//какой идет ход по счету
	bool OnIUO3;					//для включение экрана о запрпосе о пропуске хода
	bool OnSureHalt;				//для включения предупреждения
	bool Fast_2;					//для повторного нажатия
	float CouterClick_Frame;		//засикаем время для нажатии кнопки шага
	bool Teamp_CouterClick_Frame;	//для включения фрейма кнопки шага
	bool No_fast;					//сообщение о том что отряд не может прибавитьь шаг
	bool DownloadArt;				//для экрана загрузки
	float FrameDownload;			//для подсчета времени начала загрузки текстур
	bool Start;						//для старта загрузки текстур

	Sprite sprite_DownloadArt;//арт для загрузки

	Sprite sprite_DownloadStrips;	//полоска загрузки

	Tile **Miss;
	Mission(int, int, RenderWindow&);
	~Mission();
};