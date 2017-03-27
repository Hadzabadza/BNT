#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace sf;

class Unit
{	
public:
	////***Графическая механика юнитов***
	string Test;	//имя командира
	float w, h, x, y, CurrentFrame, anspeed, speed, distance, teampX, teampY; //w, h- размеры спрайта рект, x,y координаты где находится спрайт, CurrentFrame номер кадра, anspeed - скорость анимации, speed - скорость движения, distance рассчет расстояния которое нужно пройти,teampX teampY - для рассчета дистанции до определенной точки
	int Sprite_X, Sprite_Y; //создания спрайта по имеджу, Sprite_Y используется для рандомной анимации
	int _I, _J;		//i j юнита в клетки которой он находится
	int Id, faction_choice;			//уникальный id юнита faction_choice - выбор фракции для тайлсета юнита
	bool isMove, isSelect;		//ismove юнит идет, isselect юнит выделен
	bool _Attack;				//для проигрываания анимации атаки
	bool ReceivingPricking;            //для проигрывания анимации получение люлей от колючего
	bool ReceivingCutting;				//для проигрывания анимации получение люлей от режущего
	int Receiving_int;			//для переключения между анимациями получения урона
	float CurrentFrameToAttackReceiving; //кадры для нанесение урона и для получения урона
	float calculation_distance_x_Attack, calculation_distance_y_Attack, calculation_distance_Attack; //рассчет дистанции загорания кнопочки возможной атаки
	float calculation_distance_x_Step, calculation_distance_y_Step, calculation_distance_Step;	//для расчета дальности движения
	bool Pricking;			//колющие оружие или ударное
	bool Cutting;			//режущие оружие
	bool isSelectHostile;	//для выделения вражеского юнита
	bool hurt;				//если отрял ранен, то мы переключаемся на раненный дизайн отрядов
	int lvl;				//лвл отряда

	Sprite sprite;
	////***Графическая механика юнитов***

	////***Техническая механика юнитов***
	int UnitToUnit;			//индитификатор по которому будет определяться какого юнита мы создаем
	string _Land;			//земля на которой стоит юнит
	float Morale, Stamina, ConstMorale, ConstStamina;	//мораль отряда и выносливость отряда 
	int PeopleLive, PeopleHealth;	//раненые и сколько человек вообщем в отряде
	int ConstPeopleLive, ConstPeopleHealth; //константное значение, раненые и сколько человек вообщем в отряде
	bool Life;				//жив отряд, или мертв
	string ClassUnit;		//класс юнита, к примеру стрелковый
	int Hp, HpHurt, Attack; //хп, хп для ранения, атака, защита
	float radius, Defense;			//радиус атаки юнита
	int CouterAttack, ConstCouterAttack;	//количество атак, которые может сделать юнит за ход
	int CouterStep, ConstCouterStep;	//количество шагов, которые юнит может сделать за ход
	int Ammo;			//количество боеприпасов у стрелковых отрядов
	float const_step, step, fast_step;					//дальность ходьбы юнита
	bool fast_step_True;	//включена быстрая ходьба
	////***Техническая механика юнитов***

	Unit(float, float, float, float, int, int, int, int, string, int, string);		//создания юнита

	Unit(void) {};

	void To_Move(Mission&, float);				//функция движения,

	void Update(Mission&, float);		//функция апдейт юнита

	void AttackToAttack(Unit&, float); //атака юнита

	void AnimationToAttack(float);	//анимация атаки

	void ReceivingFace(float);		//анимация получения урона

	void Halt();
};
