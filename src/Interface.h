#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;
using namespace sf;

class To_Exit		//элемент интерфейса
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
	Sprite sprite_infoUnitPlayer; //окошко интерфейса
	Vector2f center1;		//для центровки текста по камере 
	Vector2f size1;			//для центровки текста по камере 

	Text textInfoSquad;			//информация о название отряда
	Text textInfoMorale;		//информация о моральном состояние
	Text textInfoStamina;		//информация о выносливости

	Text textInfoComanderName;	//имя коандира отряда

	Text textInfoStrength;		//отображает числность отряда
	Text textInfoLvl;			//лвл отряда

	Text textInfoStepCouter;	//количество шагов
	Text textInfoAttackpCouter;	//количество атак
	Text textInfoAmmo;			//количество боеприпасов

	Font fontText;				//шрифт
	Font fontText2;				//для информации о количестве солдат в отряде

	ostringstream _String;		//строка количества человек в отряде раненые
	ostringstream _String2;		//строка количества человек в отряде не раненные
	ostringstream Teamp_1;		//для вывода лвл и прочей информации

	Sprite sprite_infoUnitPlayer2;//бошка юнита на интерфейсе

	bool _draw;					//рисовать интерфейс или нет
	bool _hurt;					//если отряд ранен то выводим покалеченную бошку 
	bool selectionStamina, selectionMorale;				//для выбора между состояниеми отряда
	int _UnitToUnit;			//определяем тип отряда
	string nameComandor;		//имя командира выводимая на интерфейс
	bool cross;					//для нажатие крестика
	bool missingStep;			//для пропуска хода
	bool Fast;					//говорим о том, что нажали клавишу быстрого бега
	
	int UnitId;					//ID юнита для проверки нажатия кнопок
	int People, ConstPeople;					//для вывода красной полоски
	int HurtPeople, ConstHurtPeople;				//для вывода зеленой полоски
	int SelectLvl;								//лвл отряда
	int CouterS, CouterA, ConstCoterS, ConstCouterA;	//для хранения очков атаки и шагов юнита 

	int CouterStepUnit, CouterAttackUnit, CouterAmmo;		//шаги, атака, потроны
	ostringstream _CouterStepUnit, _CouterAttackUnit, _CouterAmmo;	//для вывода

	Sprite sprite_Black;//черная
	Sprite sprite_Red;//красная
	Sprite sprite_Green;//зеленая

	Sprite sprite_infoUnitPlayer_Fast;//кнопка нажатия бега

	float StaminaUnit, MoraleUnit, ConstStaminaUnit, ConstMoraleUnit;			//выносливость на интерфейс - моральное состояние на интерфейс

	InformUnitPlayer();
	void IsSelectInformUnitPlayer(Event&, RenderWindow&, Mission&);
	void DrawStrips(RenderWindow&);
	void DrawInfo(RenderWindow&);	//выводим на экран
	int IntToInt(int, int);
};

class InformUnitHostile
{
public:
	bool _draw2;					//рисовать интерфейс или нет
	bool _hurt2;					//если отряд ранен то выводим покалеченную бошку 
	bool selectionStamina2, selectionMorale2;				//для выбора между состояниеми отряда
	int _UnitToUnit2;			//определяем тип отряда
	string nameComandor2;		//имя командира выводимая на интерфейс
	bool cross2;					//для нажатие крестика
	Vector2f center2;		//для центровки текста по камере 
	Vector2f size2;			//для центровки текста по камере 

	float StaminaUnit2, MoraleUnit2, ConstStaminaUnit2, ConstMoraleUnit2;
	
	int People2, ConstPeople2;					//для вывода красной полоски
	int HurtPeople2, ConstHurtPeople2;				//для вывода зеленой полоски
	int SelectLvl2;

	Sprite sprite_infoUnitPlayer3;//окошко интерфейса

	Sprite sprite_infoUnitPlayer4;//бошка юнита

	Text textInfoSquad2;			//информация о название отряда
	Text textInfoMorale2;		//информация о моральном состояние
	Text textInfoStamina2;		//информация о выносливости

	Text textInfoComanderName2;	//имя коандира отряда

	Text textInfoStrength2;		//отображает числность отряда
	Text textInfoLvl2;			//лвл отряда

	Font fontText4;				//шрифт
	Font fontText5;				//для информации о количестве солдат в отряде

	ostringstream _String3;		//строка количества человек в отряде раненые
	ostringstream _String4;		//строка количества человек в отряде не раненные
	ostringstream Teamp_2;		//для вывода лвл и прочей информации

	Sprite sprite_Black2;//черная
	Sprite sprite_Red2;//красная
	Sprite sprite_Green2;//зеленая

	InformUnitHostile();
	void DrawInfoHostile(RenderWindow&);	//выводим на экран
	void DrawStripsHostile(RenderWindow&);
	int IntToInt2(int, int);
	void IsSelectInformUnitHostile(Event&, RenderWindow&);
};

class SureStupe
{
public:
	Font fontText5;				//шрифт

	Vector2f center_SureStupe;		//для центровки текста по камере 
	Vector2f size_SureStupe;			//для центровки текста по камере

	Sprite sprite_infoUnitPlayer_SureStupe;//окошко интерфейса
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
	Font fontText_SureHalt;				//шрифт

	Vector2f center_SureHalt;		//для центровки текста по камере 
	Vector2f size_SureHalt;			//для центровки текста по камере

	Sprite sprite_infoUnitPlayer_SureHalt;//окошко интерфейса
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
	int Order, _CouterS; //приказы и какой ход

	Vector2f center_SureStupe_InterfaceMap;		//для центровки текста по камере 
	Vector2f size_SureStupe_InterfaceMap;			//для центровки текста по камере

	Sprite sprite_InterfaceMap;//окошко интерфейса

	Text StepCouter_InterfaceMap;			//ходы в числах
	Text StepText_InterfaceMap;		//текст ход

	Text OrderCouter_InterfaceMap;			//приказы в числах
	Text OrderText_InterfaceMap;		//текст приказов

	ostringstream _StepCouter_InterfaceMap;		//строка количества человек в отряде раненые
	ostringstream _OrderCouter_InterfaceMap;		//строка количества человек в отряде не раненные

	Font fontText_InterfaceMap1;				//шрифт
	Font fontText_InterfaceMap2;				//для информации о количестве солдат в отряде

	InterfaceMap();
	void IsDrawInterfaceMap(RenderWindow&);
	void IsSelectInterfaceMap(Event&, RenderWindow&, Mission&, Player&);
};

class TrayUnit_index
{
public:
	int ID_Unit;			//айди юнита
	int UnitToUnit_ID;		//определяет какого юнита мы выбрали
	bool Life;				//жив юнит, или мертв
	float Couter_Step_Unit, Const_Couter_Step;	//счетчик шагов
	float Couter_Attack, Const_Couter_Attack;	//счетчик атак
	float X_Position, Y_Position;				//мировые координаты позиции
	bool IsSelectUnit;

	Sprite sprite_TrayUnit;		//спрайт свитка

	Sprite sprite_TrayUnit_Head;	//спрайт бошки юнита

	Sprite sprite_TrayUnit_Dot;	//точки

	TrayUnit_index();
};

class TrayUnit
{
public:
	int SizeArmyGamer;
	Vector2f center_SureStupe_TrayUnit;		//для центровки по камере 
	Vector2f size_SureStupe_TrayUnit;			//для центровки по камере

	Sprite sprite_TrayUnit_end;	//спрайт окончания свика

	vector<TrayUnit_index> ListUnit;	//хранящиеся данные юнитов

	TrayUnit();
	void UpdateTrayUnit(vector<Unit>&);
	void DrawTrayUnit(RenderWindow&);
	void IsSelecThisTray();
};

class AllInterfaceMissiom
{
public:
	To_Exit Ex;				//кнопка выхода
	InformUnitPlayer IUP;	//информация о отряде игрока и дружественном отряде
	InformUnitHostile IUP2;	//информация о отряде противника
	SureStupe IUP3;		//если игрок хочет пропусть ход когда очки инициативы еще не потрачены
	InterfaceMap _map;	//интерфейс карты
	SureHalt HaltNo;	//для вывода о том, что юнит не может отдохнуть
	TrayUnit Tray;		//полоска списка юнитов
};