#include <fstream>
#include "GlobalFunctionMissiom.h"
#include "PrintMission.h"

using namespace std;
using namespace sf;

//////////////////////////////////////////////////////////////////////////////
void FunctionPrintToMission_1(AllInterfaceMissiom &In)		//создание карты 
{
	tnd->screen_lock = true;

	if (tnd->Start == true)
	{
		for (int i = 0; i < HEIGHT_MAP_1; i++)
		{
			for (int j = 0; j < WIDTH_MAP_1; j++)
			{
				if (tnd->Miss[i][j].Get_Instantiate() == false)
				{
					if (((HEIGHT_MAP_1 * WIDTH_MAP_1) > tnd->id_tile))
					{
						tnd->Miss[i][j].SetTile("a", true, (int)tnd->id_tile, j, i, 128, 0, 64);
						if ((TileMap2[i][j] == 'a')) tnd->Miss[i][j].SetTile("a", true, (int)tnd->id_tile, j, i, 128, 0, 64);	//травка
						if ((TileMap2[i][j] == ' ')) tnd->Miss[i][j].SetTile(" ", true, (int)tnd->id_tile, j, i, 64, 704, 64);	//камешки на травке
						if ((TileMap2[i][j] == ':')) tnd->Miss[i][j].SetTile(":", true, (int)tnd->id_tile, j, i, 64, 64, 64);	//дорога верх вниз
						if ((TileMap2[i][j] == 'W')) tnd->Miss[i][j].SetTile("W", true, (int)tnd->id_tile, j, i, 128, 128, 64);	//левый край леса
						if ((TileMap2[i][j] == 'e')) tnd->Miss[i][j].SetTile("e", true, (int)tnd->id_tile, j, i, 128, 64, 64);	//верхний левый угол леса
						if ((TileMap2[i][j] == 'R')) tnd->Miss[i][j].SetTile("R", true, (int)tnd->id_tile, j, i, 128, 576, 64);	//сплошной лес
						if ((TileMap2[i][j] == 'r')) tnd->Miss[i][j].SetTile("r", true, (int)tnd->id_tile, j, i, 128, 320, 64);	//верхний край леса
						if ((TileMap2[i][j] == '*')) tnd->Miss[i][j].SetTile("*", true, (int)tnd->id_tile, j, i, 64, 128, 64);	//дорога нижняя дуга поварачивает вправо
						if ((TileMap2[i][j] == '%')) tnd->Miss[i][j].SetTile("%", true, (int)tnd->id_tile, j, i, 64, 0, 64);	//дорога влево вправо
						if ((TileMap2[i][j] == '1')) tnd->Miss[i][j].SetTile("1", true, (int)tnd->id_tile, j, i, 0, 0, 64, 64, 5);	//болото
						if ((TileMap2[i][j] == '2')) tnd->Miss[i][j].SetTile("2", true, (int)tnd->id_tile, j, i, 0, 64, 64, 64, 5);	//болото
						if ((TileMap2[i][j] == '3')) tnd->Miss[i][j].SetTile("3", true, (int)tnd->id_tile, j, i, 0, 128, 64, 64, 5);	//болото
						if ((TileMap2[i][j] == '4')) tnd->Miss[i][j].SetTile("4", true, (int)tnd->id_tile, j, i, 0, 192, 64, 64, 5);	//болото
						if ((TileMap2[i][j] == 'H')) tnd->Miss[i][j].SetTile("H", true, (int)tnd->id_tile, j, i, 256, 256, 64);	//холм
						if ((TileMap2[i][j] == 'j')) tnd->Miss[i][j].SetTile("J", true, (int)tnd->id_tile, j, i, 256, 320, 64);	//холм
						if ((TileMap2[i][j] == 'J')) tnd->Miss[i][j].SetTile("j", true, (int)tnd->id_tile, j, i, 256, 384, 64);	//холм
						if ((TileMap2[i][j] == '!')) tnd->Miss[i][j].SetTile("!", true, (int)tnd->id_tile, j, i, 0, 576, 64);	//сожженая деревня
						if ((TileMap2[i][j] == '>')) tnd->Miss[i][j].SetTile(">", true, (int)tnd->id_tile, j, i, 385, 256, 64);	//сожженая каменная крепость
						tnd->id_tile++;
						tnd->Start = false;
						//break; //Замедляет загрузку
					}
				}
			}
		}
	}



	if (tnd->Start == false && tnd->DownloadArt == true)
	{
		tnd->sprite_DownloadStrips.setTextureRect(IntRect(113, 769, 14 * (tnd->id_tile / 2), 46));
	}


	if (((HEIGHT_MAP_1 * WIDTH_MAP_1) == tnd->id_tile))
	{
		tnd->DownloadArt = false;
		tnd->Start = false;
	}


	if (tnd->DownloadArt == false && tnd->OnSureHalt == false && tnd->OnIUO3 == false && In.IUP3._draw_SureStupe == false)
	{
		tnd->screen_lock = false;
	}

}
//////////////////////////////////////////////////////////////////////////////
void FunctionPrintToMission_2(AllInterfaceMissiom &In)		//создание карты 
{
	tnd->screen_lock = true;

	if (tnd->Start == true)
	{
		for (int i = 0; i < HEIGHT_MAP_2; i++)
		{
			for (int j = 0; j < WIDTH_MAP_2; j++)
			{
				if (tnd->Miss[i][j].Get_Instantiate() == false && ((HEIGHT_MAP_2 * WIDTH_MAP_2) > tnd->id_tile))
				{
					tnd->Miss[i][j].SetTile("a", true, (int)tnd->id_tile, j, i, 128, 0, 64);
					if ((TileMap2[i][j] == 'a')) tnd->Miss[i][j].SetTile("a", true, (int)tnd->id_tile, j, i, 128, 0, 64);	//травка
					if ((TileMap2[i][j] == ' ')) tnd->Miss[i][j].SetTile(" ", true, (int)tnd->id_tile, j, i, 64, 704, 64);	//камешки на травке
					if ((TileMap2[i][j] == ':')) tnd->Miss[i][j].SetTile(":", true, (int)tnd->id_tile, j, i, 64, 64, 64);	//дорога верх вниз
					if ((TileMap2[i][j] == 'W')) tnd->Miss[i][j].SetTile("W", true, (int)tnd->id_tile, j, i, 128, 128, 64);	//левый край леса
					if ((TileMap2[i][j] == 'e')) tnd->Miss[i][j].SetTile("e", true, (int)tnd->id_tile, j, i, 128, 64, 64);	//верхний левый угол леса
					if ((TileMap2[i][j] == 'R')) tnd->Miss[i][j].SetTile("R", true, (int)tnd->id_tile, j, i, 128, 576, 64);	//сплошной лес
					if ((TileMap2[i][j] == 'r')) tnd->Miss[i][j].SetTile("r", true, (int)tnd->id_tile, j, i, 128, 320, 64);	//верхний край леса
					if ((TileMap2[i][j] == '*')) tnd->Miss[i][j].SetTile("*", true, (int)tnd->id_tile, j, i, 64, 128, 64);	//дорога нижняя дуга поварачивает вправо
					if ((TileMap2[i][j] == '%')) tnd->Miss[i][j].SetTile("%", true, (int)tnd->id_tile, j, i, 64, 0, 64);	//дорога влево вправо
					if ((TileMap2[i][j] == '1')) tnd->Miss[i][j].SetTile("1", true, (int)tnd->id_tile, j, i, 0, 0, 64, 64, 5);	//болото
					if ((TileMap2[i][j] == '2')) tnd->Miss[i][j].SetTile("2", true, (int)tnd->id_tile, j, i, 0, 64, 64, 64, 5);	//болото
					if ((TileMap2[i][j] == '3')) tnd->Miss[i][j].SetTile("3", true, (int)tnd->id_tile, j, i, 0, 128, 64, 64, 5);	//болото
					if ((TileMap2[i][j] == '4')) tnd->Miss[i][j].SetTile("4", true, (int)tnd->id_tile, j, i, 0, 192, 64, 64, 5);	//болото
					if ((TileMap2[i][j] == 'H')) tnd->Miss[i][j].SetTile("H", true, (int)tnd->id_tile, j, i, 256, 256, 64);	//холм
					if ((TileMap2[i][j] == 'j')) tnd->Miss[i][j].SetTile("J", true, (int)tnd->id_tile, j, i, 256, 320, 64);	//холм
					if ((TileMap2[i][j] == 'J')) tnd->Miss[i][j].SetTile("j", true, (int)tnd->id_tile, j, i, 256, 384, 64);	//холм
					if ((TileMap2[i][j] == '!')) tnd->Miss[i][j].SetTile("!", true, (int)tnd->id_tile, j, i, 0, 576, 64);	//сожженая деревня
					if ((TileMap2[i][j] == '>')) tnd->Miss[i][j].SetTile(">", true, (int)tnd->id_tile, j, i, 385, 256, 64);	//сожженая каменная крепость
					tnd->id_tile++;
					tnd->Start = false;
					//break; //Замедляет загрузку
				}
			}
		}
	}

	if (tnd->Start == false && tnd->DownloadArt == true)
	{
		tnd->sprite_DownloadStrips.setTextureRect(IntRect(113, 769, 14 * (tnd->id_tile / 2), 46));
	}


	if (((HEIGHT_MAP_2 * WIDTH_MAP_2) == tnd->id_tile))
	{
		tnd->DownloadArt = false;
		tnd->Start = false;
	}

	if (tnd->DownloadArt == false && tnd->OnSureHalt == false && tnd->OnIUO3 == false && In.IUP3._draw_SureStupe == false)
	{
		tnd->screen_lock = false;
	}
}
//////////////////////////////////////////////////////////////////////////////
bool TileIsEmpty(Tile & t) //проверка на то занят тайл или нет
{
	return t.unit == Unit::NIL;
	/*
	for (int i = 0; i < _Mission.HEIGHT_MAP; i++) //проверка занятости из за ланшафта
		for (int j = 0; j < _Mission.WIDTH_MAP; j++)
		{
			if (_Mission.Miss[i][j].InspectionTile == false)
			{
				if (_Mission.Miss[i][j].GetLand() == 'V')
				{
					_Mission.Miss[i][j].Set_Empty(true);
					_Mission.Miss[i][j].InspectionTile = true;
				}
			}

			for (int ii(0); ii < MainCharacter.ArmyGamer.size(); ii++) //проверка занятости из за других юнитов
			{
				if (_Mission.Miss[i][j].InspectionTile == false)
				{
					if (MainCharacter.ArmyGamer[ii].pos->x == _Mission.Miss[i][j].Get_X() && MainCharacter.ArmyGamer[ii].pos->y == _Mission.Miss[i][j].Get_Y() && MainCharacter.ArmyGamer[ii].Life == true)
					{
						_Mission.Miss[i][j].Set_Empty(true);
						_Mission.Miss[i][j].InspectionTile = true;
					}
				}
			}


			if (hostile.ArmyEnemy_1.empty() == false)
			{
				for (int ii(0); ii < hostile.ArmyEnemy_1.size(); ii++) //проверка занятости из за других юнитов
				{
					if (_Mission.Miss[i][j].InspectionTile == false)
					{
						if (hostile.ArmyEnemy_1[ii].pos->x == _Mission.Miss[i][j].Get_X() && hostile.ArmyEnemy_1[ii].pos->y == _Mission.Miss[i][j].Get_Y() && hostile.ArmyEnemy_1[ii].Life == true)
						{
							_Mission.Miss[i][j].Set_Empty(true);
							_Mission.Miss[i][j].InspectionTile = true;
						}
					}
				}
			}
		}


	for (int i = 0; i < _Mission.HEIGHT_MAP; i++)							//проверка НЕзанятости тайла
		for (int j = 0; j < _Mission.WIDTH_MAP; j++)
		{
			for (int ii(0); ii < MainCharacter.ArmyGamer.size(); ii++)
			{
				if (_Mission.Miss[i][j].InspectionTile == false)
				{
					if (MainCharacter.ArmyGamer[ii].pos->x != _Mission.Miss[i][j].Get_X() || MainCharacter.ArmyGamer[ii].pos->y != _Mission.Miss[i][j].Get_Y())
					{
						_Mission.Miss[i][j].Set_Empty(false);
						_Mission.Miss[i][j].InspectionTile = true;
					}
				}
			}
		}


	for (int i = 0; i < _Mission.HEIGHT_MAP; i++)							//проверка НЕзанятости тайла
		for (int j = 0; j < _Mission.WIDTH_MAP; j++)
		{
			for (int ii(0); ii < hostile.ArmyEnemy_1.size(); ii++)
			{
				if (_Mission.Miss[i][j].InspectionTile == false)
				{
					if (hostile.ArmyEnemy_1[ii].pos->x != _Mission.Miss[i][j].Get_X() || hostile.ArmyEnemy_1[ii].pos->y != _Mission.Miss[i][j].Get_Y())
					{
						_Mission.Miss[i][j].Set_Empty(false);
						_Mission.Miss[i][j].InspectionTile = true;
					}
				}
			}
		}
	*/
}
//////////////////////////////////////////////////////////////////////////////
void ViewScroling(View &_view, Vector2i &_localPosition, RenderWindow &_window)	//скроллинг до краев
{
	if (tnd->screen_lock == false)
	{
		if (_localPosition.x > _window.getSize().x - 10)
		{
			_view.move(0.9*elapsed, 0);
			if (_view.getCenter().x > (128 * tnd->WIDTH_MAP) - 511) //разница в 510
			{
				_view.move(-0.9*elapsed, 0);
			}

		}


		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			_view.move(0.9*elapsed, 0);
			if (_view.getCenter().x > (128 * tnd->WIDTH_MAP) - 511) //разница в 510
			{
				_view.move(-0.9*elapsed, 0);
			}
		}


		if (_localPosition.y > _window.getSize().y - 10)
		{
			_view.move(0, 0.9*elapsed);
			if (_view.getCenter().y > (128 * tnd->HEIGHT_MAP) - 386)		//разница в 350
			{
				_view.move(0, -0.9*elapsed);
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			_view.move(0, 0.9*elapsed);
			if (_view.getCenter().y > (128 * tnd->HEIGHT_MAP) - 386)		//разница в 385
			{
				_view.move(0, -0.9*elapsed);
			}
		}

		if (_localPosition.x < 10)
		{
			_view.move(-0.9*elapsed, 0);
			if (_view.getCenter().x - 511 < 0)
			{
				_view.move(0.9*elapsed, 0);
			}

		}

		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			_view.move(-0.9*elapsed, 0);
			if (_view.getCenter().x - 511 < 0)
			{
				_view.move(0.9*elapsed, 0);
			}
		}

		if (_localPosition.y < 10)
		{
			_view.move(0, -0.9*elapsed);
			if (_view.getCenter().y - 386 < 0)
			{
				_view.move(0, 0.9*elapsed);
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			_view.move(0, -0.9*elapsed);
			if (_view.getCenter().y - 386 < 0)
			{
				_view.move(0, 0.9*elapsed);
			}
		}
	}
}
//////////////////////////////////////////////////////////////////////////////
bool InspectionToStep(Unit &Inspect, int i, int j)	//проверка как далеко может пойти юнит
{
	Inspect.calculation_distance_x_Step = Inspect.pos->x - i;
	Inspect.calculation_distance_y_Step = Inspect.pos->y - j;
	Inspect.calculation_distance_Step = sqrt((Inspect.calculation_distance_x_Step * Inspect.calculation_distance_x_Step) + (Inspect.calculation_distance_y_Step * Inspect.calculation_distance_y_Step));

	if (Inspect.calculation_distance_Step <= Inspect.step)
	{
		return true;
	}
	else { return false; }
}
//////////////////////////////////////////////////////////////////////////////
void GreenToTheTile(Unit &Teamp)	//даем добро на рисования зеленых тайлов
{
	float Pythagoras = 0;
	for (int i(0); i < tnd->HEIGHT_MAP; i++)
	{
		for (int j(0); j < tnd->WIDTH_MAP; j++)
		{
			Pythagoras = sqrt(pow((float)j - (float)Teamp.pos->x, 2) + pow((float)i - (float)Teamp.pos->y, 2));
			if (Pythagoras <= Teamp.step)
			{
				if ((i != Teamp.pos->x || j != Teamp.pos->y) && tnd->Miss[i][j].Get_Empty() == false)
				{
					tnd->Miss[i][j].StepUnit = true;
				}
			}
		}
	}
}
//////////////////////////////////////////////////////////////////////////////
void GreenTileOFF()
{
	for (int i(0); i < tnd->HEIGHT_MAP; i++)
	{
		for (int j(0); j < tnd->WIDTH_MAP; j++)
		{
			tnd->Miss[i][j].StepUnit = false;
			tnd->Miss[i][j].Set_AttackOn(false);
			tnd->Miss[i][j].spriteGreenTile.setTextureRect(IntRect(0, 0, 64, 64));
		}
	}

}
//////////////////////////////////////////////////////////////////////////////
void interactionWithMap(Unit  &Teamp, string _land)
{
	int DamageStaminaMorale, DamageStaminaMorale_2;
	int min, max;
	if (_land == 'a' || _land == ' ')		//травка
	{
		if (Teamp.fast_step_True == true)
		{
			min = 25;
			max = 70;
		}
		else
		{
			min = 15;
			max = 50;
		}

		DamageStaminaMorale = min + rand() % (max - min);
		if (Teamp.Stamina > 0)
		{
			Teamp.Stamina -= DamageStaminaMorale;
		}
		else
		{
			Teamp.Morale -= DamageStaminaMorale;
		}
	}

	if (_land == ':' || _land == '*' || _land == '%')	//дорога
	{
		if (Teamp.fast_step_True == true)
		{
			min = 20;
			max = 40;
		}
		else
		{
			min = 15;
			max = 35;
		}
		DamageStaminaMorale = min + rand() % (max - min);
		if (Teamp.Stamina > 0)
		{
			Teamp.Stamina -= DamageStaminaMorale;
		}
		else
		{
			Teamp.Morale -= DamageStaminaMorale;
		}
	}

	if (_land == 'H' || _land == 'J' || _land == 'j')	//холмы
	{
		if (Teamp.fast_step_True == true)
		{
			min = 60;
			max = 100;
		}
		else
		{
			min = 40;
			max = 85;
		}
		DamageStaminaMorale = min + rand() % (max - min);
		if (Teamp.Stamina > 0)
		{
			Teamp.Stamina -= DamageStaminaMorale;
		}
		else
		{
			Teamp.Morale -= DamageStaminaMorale;
		}
	}


	if (_land == '1' || _land == '2' || _land == '3' || _land == '4')	//болота
	{
		if (Teamp.fast_step_True == true)
		{
			min = 40;
			max = 75;
		}
		else
		{
			min = 30;
			max = 65;
		}

		DamageStaminaMorale = min + rand() % (max - min);
		DamageStaminaMorale_2 = min + rand() % (max - min);
		DamageStaminaMorale_2 /= 2;
		cout << DamageStaminaMorale_2 << endl;
		if (Teamp.Stamina > 0)
		{
			Teamp.Stamina -= DamageStaminaMorale;
			Teamp.Morale -= DamageStaminaMorale_2;
		}
		else
		{
			Teamp.Morale -= DamageStaminaMorale;
			Teamp.Morale -= DamageStaminaMorale_2;
		}
	}

	if (_land == 'W' || _land == 'e' || _land == 'r' || _land == 'R')	//лес
	{
		if (Teamp.fast_step_True == true)
		{
			min = 50;
			max = 80;
		}
		else
		{
			min = 30;
			max = 60;
		}

		DamageStaminaMorale = min + rand() % (max - min);

		if (Teamp.Stamina > 0)
		{
			Teamp.Stamina -= DamageStaminaMorale;
		}
		else
		{
			Teamp.Morale -= DamageStaminaMorale;
		}
	}


	if (_land == '!' || _land == '>')	//инфракструктура сожженая
	{
		if (Teamp.fast_step_True == true)
		{
			min = 40;
			max = 60;
		}
		else
		{
			min = 20;
			max = 40;
		}
		DamageStaminaMorale = min + rand() % (max - min);

		if (Teamp.Stamina > 0)
		{
			Teamp.Stamina -= DamageStaminaMorale;
		}
		else
		{
			Teamp.Morale -= DamageStaminaMorale;
		}
	}

}
//////////////////////////////////////////////////////////////////////////////
void SelectUnitPlayer(Event &_event, Player &MainCharacter, AllInterfaceMissiom &Inf)
{
	string teamp;
	if (_event.type == Event::MouseButtonPressed)//если нажата клавиша мыши
		if (_event.key.code == Mouse::Left)
		{//а именно левая
			for (int i(0); i < MainCharacter.ArmyGamer.size(); i++)
				if (MainCharacter.ArmyGamer[i].animation->hovered() && MainCharacter.ArmyGamer[i].isMove == false && MainCharacter.ArmyGamer[i]._Attack == false && MainCharacter.ArmyGamer[i].Life == true)//и при этом координата курсора попадает в спрайт
				{

					MainCharacter.ArmyGamer[i].isSelect = true;

					if (Inf.IUP.cross == true)
					{
						Inf.IUP.cross = false;
					}

					if (Inf.IUP2.cross2 == true)
					{
						Inf.IUP2.cross2 = false;
					}

					cout << "\nComander Name:" << MainCharacter.ArmyGamer[i].Test << endl;
					cout << "Stamina:" << MainCharacter.ArmyGamer[i].Stamina << endl;
					cout << "Unit id:" << MainCharacter.ArmyGamer[i].Id << endl;
					cout << "Land:" << MainCharacter.ArmyGamer[i]._Land << endl;
					cout << "Unit:" << MainCharacter.ArmyGamer[i].UnitToUnit << endl;
					cout << "Class Unit:" << MainCharacter.ArmyGamer[i].ClassUnit << endl;

					if (tnd->MovementPlayer == true && MainCharacter.ArmyGamer[i].CouterStep > 0)
					{
						GreenToTheTile(MainCharacter.ArmyGamer[i]);	//рисуем зеленый тайлы вокруг юнита
					}
				}
		}

}
//////////////////////////////////////////////////////////////////////////////

void SelectHostileUnit(Event &_event, Enemy_1 &hostile, Player &MainCharacter, AllInterfaceMissiom &Inf)
{

	if (_event.type == Event::MouseButtonPressed)//если нажата клавиша мыши
		if (_event.key.code == Mouse::Left)
		{
			for (int i(0); i < hostile.ArmyEnemy_1.size(); i++)
			{
				if (hostile.ArmyEnemy_1[i].animation->hovered() && hostile.ArmyEnemy_1[i].isSelectHostile == false && hostile.ArmyEnemy_1[i]._Attack == false && hostile.ArmyEnemy_1[i].ReceivingCutting == false && hostile.ArmyEnemy_1[i].ReceivingPricking == false && hostile.ArmyEnemy_1[i].Life == true)
				{
					hostile.ArmyEnemy_1[i].isSelectHostile = true;

					if (Inf.IUP2.cross2 == true)
					{
						Inf.IUP2.cross2 = false;
					}

					cout << "\nИмя командира:" << hostile.ArmyEnemy_1[i].Test << endl;
					cout << "Выносливость:" << hostile.ArmyEnemy_1[i].Stamina << endl;
					cout << "Id отряд :" << hostile.ArmyEnemy_1[i].Id << endl;
					cout << "Земля на которой стоит отряд:" << hostile.ArmyEnemy_1[i]._Land << endl;
					cout << "Люди в отряде:" << hostile.ArmyEnemy_1[i].PeopleLive << endl;
					cout << "Целых людей в отряде:" << hostile.ArmyEnemy_1[i].PeopleHealth << endl;
				}


			}
		}


	for (int i(0); i < hostile.ArmyEnemy_1.size(); i++)
		if (_event.type == Event::MouseButtonPressed)//если нажата клавиша мыши
			if (_event.key.code == Mouse::Right)
				if (hostile.ArmyEnemy_1[i].isSelectHostile = true)
				{
					hostile.ArmyEnemy_1[i].isSelectHostile = false;
				}

}

//////////////////////////////////////////////////////////////////////////////
void AttackUnitPlayerToHostile(Event &_event, Player &MainCharacter, Enemy_1 &hostile)
{

	for (int ii(0); ii < MainCharacter.ArmyGamer.size(); ii++)
	{
		if (tnd->MovementPlayer == true && MainCharacter.ArmyGamer[ii].CouterAttack > 0)
		{
			for (int i(0); i < hostile.ArmyEnemy_1.size(); i++)
			{
				hostile.ArmyEnemy_1[i].calculation_distance_x_Attack = MainCharacter.ArmyGamer[ii].pos->x - hostile.ArmyEnemy_1[i].pos->x;
				hostile.ArmyEnemy_1[i].calculation_distance_y_Attack = MainCharacter.ArmyGamer[ii].pos->y - hostile.ArmyEnemy_1[i].pos->y;
				hostile.ArmyEnemy_1[i].calculation_distance_Attack = sqrt((hostile.ArmyEnemy_1[i].calculation_distance_x_Attack * hostile.ArmyEnemy_1[i].calculation_distance_x_Attack) + (hostile.ArmyEnemy_1[i].calculation_distance_y_Attack * hostile.ArmyEnemy_1[i].calculation_distance_y_Attack));
				if (hostile.ArmyEnemy_1[i].Life == true)
				{
					if (hostile.ArmyEnemy_1[i].calculation_distance_Attack <= MainCharacter.ArmyGamer[ii].radius && MainCharacter.ArmyGamer[ii].isSelect == true && hostile.ArmyEnemy_1[i].Life == true)
					{
						tnd->Miss[int(hostile.ArmyEnemy_1[i].pos->x)][int(hostile.ArmyEnemy_1[i].pos->y)].Set_AttackOn(true);
						if (_event.type == Event::MouseButtonPressed)//если нажата клавиша мыши
							if (_event.key.code == Mouse::Right)
							{//а именно левая
								if (hostile.ArmyEnemy_1[i].animation->hovered() && MainCharacter.ArmyGamer[ii]._Attack == false && hostile.ArmyEnemy_1[i].ReceivingCutting == false && hostile.ArmyEnemy_1[i].ReceivingPricking == false)//и при этом координата курсора попадает в спрайт
								{

									cout << "\nAttack!" << endl;
									MainCharacter.ArmyGamer[ii].AttackToAttack(hostile.ArmyEnemy_1[i]);
									MainCharacter.orders--;
									MainCharacter.ArmyGamer[ii].CouterAttack--;
									cout << "Осталось приказов:" << MainCharacter.orders << endl;

								}
							}
					}
				}
			}
		}
	}

}
//////////////////////////////////////////////////////////////////////////////

void OffSelectUnitToUnitPlayer(Player &MainCharacter)
{

	for (int i(0); i < MainCharacter.ArmyGamer.size(); i++)
	{
		for (int ii(0); ii < MainCharacter.ArmyGamer.size(); ii++)
		{
			if (MainCharacter.ArmyGamer[i].Id != MainCharacter.ArmyGamer[ii].Id)
			{
				if ((MainCharacter.ArmyGamer[i].isSelect == true) && (MainCharacter.ArmyGamer[ii].isSelect == true))
				{
					MainCharacter.ArmyGamer[i].isSelect = false;
					MainCharacter.ArmyGamer[ii].isSelect = false;
					GreenTileOFF();
				}
			}
		}
	}

}

//////////////////////////////////////////////////////////////////////////////

void OffSelectUnitToHostilePlayer(Enemy_1 &hostile)
{
	for (int i(0); i < hostile.ArmyEnemy_1.size(); i++)
	{
		for (int ii(0); ii < hostile.ArmyEnemy_1.size(); ii++)
		{
			if (hostile.ArmyEnemy_1[i].Id != hostile.ArmyEnemy_1[ii].Id)
			{
				if (hostile.ArmyEnemy_1[i].isSelectHostile == true && hostile.ArmyEnemy_1[ii].isSelectHostile == true)
				{
					hostile.ArmyEnemy_1[i].isSelectHostile = false;
					hostile.ArmyEnemy_1[ii].isSelectHostile = false;
				}
			}
		}
	}
}

//////////////////////////////////////////////////////////////////////////////

void TileGreenOn(Event &_event)
{

	if (tnd->MovementPlayer == true)
	{
		if (_event.MouseMoved)
		{
			for (int i(0); i < tnd->HEIGHT_MAP; i++)
			{
				for (int j(0); j < tnd->WIDTH_MAP; j++)
				{
					if (tnd->Miss[i][j].g->hovered() && tnd->Miss[i][j].StepUnit == true)
					{
						tnd->Miss[i][j].spriteGreenTile.setTextureRect(IntRect(64, 0, 64, 64));
					}
					else { tnd->Miss[i][j].spriteGreenTile.setTextureRect(IntRect(0, 0, 64, 64)); }

				}
			}
		}
	}

}
//////////////////////////////////////////////////////////////////////////////

void LocalAreaInspectionClick(Event &_event)
{

	if (_event.type == Event::MouseButtonPressed)//если нажата клавиша мыши
		if (_event.key.code == Mouse::Middle)
		{//а именно левая
			for (int i(0); i < tnd->HEIGHT_MAP; i++)
			{
				for (int j(0); j < tnd->WIDTH_MAP; j++)
				{
					if (tnd->Miss[i][j].g->hovered())
					{

						cout << "\nEmpty:" << tnd->Miss[i][j].Get_Empty() << endl;
						cout << "Land:" << tnd->Miss[i][j].GetLand() << endl;
						cout << "X:" << tnd->Miss[i][j].g->truePos->x << endl;
						cout << "Y:" << tnd->Miss[i][j].g->truePos->x << endl;
						cout << "Tile i:" << tnd->Miss[i][j].Get_X() << " Tile j:" << tnd->Miss[i][j].Get_Y() << endl;

					}
				}
			}
		}

}

//////////////////////////////////////////////////////////////////////////////

void ClickToGOTile(Event &_event, Player &MainCharacter)
{

	for (int ii(0); ii < MainCharacter.ArmyGamer.size(); ii++)
	{
		if (MainCharacter.ArmyGamer[ii].isSelect)
			if (_event.type == Event::MouseButtonPressed)
				if (_event.key.code == Mouse::Right)
				{
					for (int i(0); i < tnd->HEIGHT_MAP; i++)
						for (int j(0); j < tnd->WIDTH_MAP; j++)
						{
							if (tnd->Miss[i][j].Get_Empty() == false)
							{
								if (tnd->Miss[i][j].g->hovered())
								{
									if (InspectionToStep(MainCharacter.ArmyGamer[ii], i, j))
									{
										if (tnd->MovementPlayer == true && MainCharacter.ArmyGamer[ii].CouterStep > 0)
										{
											interactionWithMap(MainCharacter.ArmyGamer[ii], tnd->Miss[i][j].GetLand());
											MainCharacter.ArmyGamer[ii].moveTo = *tnd->Miss[i][j].g->pos;
											MainCharacter.ArmyGamer[ii].isMove = true;

											MainCharacter.ArmyGamer[ii].ground = &tnd->Miss[i][j];
											MainCharacter.orders--;
											MainCharacter.ArmyGamer[ii].CouterStep--;
											cout << "Осталось приказов:" << MainCharacter.orders << endl;
										}
									}
									else
									{
										MainCharacter.ArmyGamer[ii].isSelect = false;
										GreenTileOFF();
									}
								}

								else
								{
									MainCharacter.ArmyGamer[ii].isSelect = false;
									GreenTileOFF();
								}

							}
						}
				}
	}
}

//////////////////////////////////////////////////////////////////////////////

void TileRedOnRedCursor(Event &_event, Enemy_1 &hostile, Player &MainCharacter)	//если юнит в радиусе атаки и мы мышкой попадаем на этого юнита
{

	if (tnd->MovementPlayer == true)
	{
		for (int i(0); i < tnd->HEIGHT_MAP; i++)
		{
			for (int j(0); j < tnd->WIDTH_MAP; j++)
			{
				if (tnd->Miss[i][j].g->hovered() && tnd->Miss[i][j].Get_AttackOn() == true)
				{
					tnd->Miss[i][j]._AttackON = true;

					for (int ii(0); ii < hostile.ArmyEnemy_1.size(); ii++)
					{
						for (int iii(0); iii < MainCharacter.ArmyGamer.size(); iii++)
							if (i == hostile.ArmyEnemy_1[ii].pos->x && j == hostile.ArmyEnemy_1[ii].pos->y && MainCharacter.ArmyGamer[iii].isSelect == true)
							{
								hostile.ArmyEnemy_1[ii].isSelectHostile = true;
							}
					}
				}

				if (tnd->Miss[i][j].g->hovered() == false && tnd->Miss[i][j].Get_AttackOn() == true)
				{
					tnd->Miss[i][j]._AttackON = false;

					for (int ii(0); ii < hostile.ArmyEnemy_1.size(); ii++)
					{
						for (int iii(0); iii < MainCharacter.ArmyGamer.size(); iii++)
							if (i == hostile.ArmyEnemy_1[ii].pos->x && j == hostile.ArmyEnemy_1[ii].pos->y && MainCharacter.ArmyGamer[iii].isSelect == true)
							{
								hostile.ArmyEnemy_1[ii].isSelectHostile = false;
							}

					}
				}


				for (int ii(0); ii < hostile.ArmyEnemy_1.size(); ii++)
				{
					if (hostile.ArmyEnemy_1[ii]._Attack == true || hostile.ArmyEnemy_1[ii].ReceivingCutting == true || hostile.ArmyEnemy_1[ii].ReceivingPricking == true)
					{
						hostile.ArmyEnemy_1[ii].isSelectHostile = false;
						tnd->Miss[i][j]._AttackON = false;
					}

					if (hostile.ArmyEnemy_1[ii].Life == false && hostile.ArmyEnemy_1[ii].pos->x == i && hostile.ArmyEnemy_1[ii].pos->y == j == tnd->Miss[i][j]._AttackON == true)
					{
						tnd->Miss[int(hostile.ArmyEnemy_1[ii].pos->x)][int(hostile.ArmyEnemy_1[ii].pos->y)]._AttackON = false;
						tnd->Miss[int(hostile.ArmyEnemy_1[ii].pos->x)][int(hostile.ArmyEnemy_1[ii].pos->y)].Set_AttackOn(false);
					}
				}
			}
		}
	}

}

//////////////////////////////////////////////////////////////////////////////
void IsSelectMouseMissiomStatic(Event &_event, Player &MainCharacter, Enemy_1 &hostile, AllInterfaceMissiom &Inf) //двигаем мышкой
{
	if (tnd->screen_lock == false)
	{
		SelectUnitPlayer(_event, MainCharacter, Inf);	//выдиляем юнита

		SelectHostileUnit(_event, hostile, MainCharacter, Inf); //функция выделения юнита противника для вывода информации

		AttackUnitPlayerToHostile(_event, MainCharacter, hostile);

		OffSelectUnitToUnitPlayer(MainCharacter);	//сбрасываем курсор если нажимаем на другого юнита

		TileGreenOn(_event);	//окрашиваем тайл зеленый в красный

		LocalAreaInspectionClick(_event);	//проверяем тайл его внутренности

		ClickToGOTile(_event, MainCharacter);	//клик ходьба в нужный тайл
	}

}
//////////////////////////////////////////////////////////////////////////////
void DrawToSpriteMission(RenderWindow &_window)	//вывод спрайтов на экран
{
	for (int i(0); i < tnd->HEIGHT_MAP; i++)
		for (int j(0); j < tnd->WIDTH_MAP; j++)
		{
			if (!tnd->screen_lock) {
				if (tnd->Miss[i][j].g->animated)
				{
					tnd->Miss[i][j].g->drawTo(_window);
				}
				else
				{
					tnd->Miss[i][j].g->drawTo(_window);
				}
			}
			tnd->Miss[i][j].InspectionTile = false;		//все проверку сбарсываем
		}
}
//////////////////////////////////////////////////////////////////////////////
void DrawSpriteCursor(RenderWindow &_window)
{
	for (int i(0); i < tnd->HEIGHT_MAP; i++)
		for (int j(0); j < tnd->WIDTH_MAP; j++)
		{
			tnd->Miss[i][j].spriteGreenTile.setPosition(tnd->Miss[i][j].Get_X() * 128, tnd->Miss[i][j].Get_Y() * 128);
			if (tnd->Miss[i][j].StepUnit == true)
			{
				_window.draw(tnd->Miss[i][j].spriteGreenTile);
			}

			if (tnd->Miss[i][j].Get_AttackOn() == true)
			{
				tnd->Miss[i][j].spriteGreenTile.setTextureRect(IntRect(128, 0, 64, 64));
				_window.draw(tnd->Miss[i][j].spriteGreenTile);
			}

			if (tnd->Miss[i][j]._AttackON == true)
			{
				tnd->Miss[i][j].spriteGreenTile.setTextureRect(IntRect(192, 0, 64, 64));
				_window.draw(tnd->Miss[i][j].spriteGreenTile);
			}
		}
}
//////////////////////////////////////////////////////////////////////////////
void DrawSpriteUnit(Player &MainCharacter, Enemy_1 &hostile, RenderWindow &_window) //рисуем спрайты юнитов армии игрока
{
	/*
	for (int i(0); i < MainCharacter.ArmyGamer.size(); i++)
	{
		//анимация стояния
		if (MainCharacter.ArmyGamer[i].isMove == false && MainCharacter.ArmyGamer[i].isSelect == false && MainCharacter.ArmyGamer[i]._Attack == false && MainCharacter.ArmyGamer[i].ReceivingCutting == false && MainCharacter.ArmyGamer[i].ReceivingPricking == false && MainCharacter.ArmyGamer[i].Life == true)
		{
			MainCharacter.ArmyGamer[i].CurrentFrame += MainCharacter.ArmyGamer[i].anspeed * time;
			if (MainCharacter.ArmyGamer[i].CurrentFrame > 4) MainCharacter.ArmyGamer[i].CurrentFrame -= 4;

			if (MainCharacter.ArmyGamer[i].hurt == false)
			{
				MainCharacter.ArmyGamer[i].sprite->setTextureRect(IntRect(MainCharacter.ArmyGamer[i].Sprite_X * int(MainCharacter.ArmyGamer[i].CurrentFrame), (MainCharacter.ArmyGamer[i].Sprite_Y * 1), MainCharacter.ArmyGamer[i].w, MainCharacter.ArmyGamer[i].h));
			}
			else
			{
				MainCharacter.ArmyGamer[i].sprite->setTextureRect(IntRect(MainCharacter.ArmyGamer[i].Sprite_X * int(MainCharacter.ArmyGamer[i].CurrentFrame), (MainCharacter.ArmyGamer[i].Sprite_Y * 7), MainCharacter.ArmyGamer[i].w, MainCharacter.ArmyGamer[i].h));
			}
		}
		////////////////

		if (MainCharacter.ArmyGamer[i].Life == false)	//если отряд мертв, рисуем трупик
		{
			MainCharacter.ArmyGamer[i].sprite->setTextureRect(IntRect(MainCharacter.ArmyGamer[i].Sprite_X * 2, 0, MainCharacter.ArmyGamer[i].w, MainCharacter.ArmyGamer[i].h));
		}

		//если выделен отряд, то мы рисуем спрайт выделения
		if (MainCharacter.ArmyGamer[i].isSelect == true)
		{
			if (MainCharacter.ArmyGamer[i].hurt == false)
			{
				MainCharacter.ArmyGamer[i].sprite->setTextureRect(IntRect(MainCharacter.ArmyGamer[i].Sprite_X, 0, MainCharacter.ArmyGamer[i].w + 4, MainCharacter.ArmyGamer[i].h + 2));//красим спрайт в зеленый,тем самым говоря игроку,что он выбрал персонажа и может сделать ход
			}
			else
			{
				MainCharacter.ArmyGamer[i].sprite->setTextureRect(IntRect(MainCharacter.ArmyGamer[i].Sprite_X * 3, 0, MainCharacter.ArmyGamer[i].w + 4, MainCharacter.ArmyGamer[i].h + 2));
			}
		}
		///////////////////////////////////////////////////
	}


	if (hostile.ArmyEnemy_1.empty() == false)
	{
		for (int i(0); i < hostile.ArmyEnemy_1.size(); i++)
		{
			if (hostile.ArmyEnemy_1[i].isMove == false && hostile.ArmyEnemy_1[i].isSelect == false && hostile.ArmyEnemy_1[i]._Attack == false && hostile.ArmyEnemy_1[i].ReceivingCutting == false && hostile.ArmyEnemy_1[i].ReceivingPricking == false && hostile.ArmyEnemy_1[i].isSelectHostile == false && hostile.ArmyEnemy_1[i].Life == true)
			{
				hostile.ArmyEnemy_1[i].CurrentFrame += hostile.ArmyEnemy_1[i].anspeed * time;
				if (hostile.ArmyEnemy_1[i].CurrentFrame > 4) hostile.ArmyEnemy_1[i].CurrentFrame -= 4;

				if (hostile.ArmyEnemy_1[i].hurt == false)
				{
					hostile.ArmyEnemy_1[i].sprite->setTextureRect(IntRect(hostile.ArmyEnemy_1[i].Sprite_X * int(hostile.ArmyEnemy_1[i].CurrentFrame), (hostile.ArmyEnemy_1[i].Sprite_Y * 1), hostile.ArmyEnemy_1[i].w, hostile.ArmyEnemy_1[i].h));
				}
				else
				{
					hostile.ArmyEnemy_1[i].sprite->setTextureRect(IntRect(hostile.ArmyEnemy_1[i].Sprite_X * int(hostile.ArmyEnemy_1[i].CurrentFrame), (hostile.ArmyEnemy_1[i].Sprite_Y * 7), hostile.ArmyEnemy_1[i].w, hostile.ArmyEnemy_1[i].h));
				}
			}

			if (hostile.ArmyEnemy_1[i].Life == false)
			{
				hostile.ArmyEnemy_1[i].sprite->setTextureRect(IntRect(hostile.ArmyEnemy_1[i].Sprite_X * 2, 0, hostile.ArmyEnemy_1[i].w, hostile.ArmyEnemy_1[i].h));
			}


			if (hostile.ArmyEnemy_1[i].isMove == false && hostile.ArmyEnemy_1[i].isSelect == false && hostile.ArmyEnemy_1[i]._Attack == false && hostile.ArmyEnemy_1[i].ReceivingCutting == false && hostile.ArmyEnemy_1[i].ReceivingPricking == false && hostile.ArmyEnemy_1[i].isSelectHostile == true && hostile.ArmyEnemy_1[i].Life == true)
			{
				if (hostile.ArmyEnemy_1[i].hurt == false)
				{
					hostile.ArmyEnemy_1[i].sprite->setTextureRect(IntRect(hostile.ArmyEnemy_1[i].Sprite_X, 0, hostile.ArmyEnemy_1[i].w, hostile.ArmyEnemy_1[i].h));
				}
				else
				{
					hostile.ArmyEnemy_1[i].sprite->setTextureRect(IntRect(hostile.ArmyEnemy_1[i].Sprite_X * 3, 0, hostile.ArmyEnemy_1[i].w, hostile.ArmyEnemy_1[i].h));
				}
			}
		}

	}

	for (int i(0); i < MainCharacter.ArmyGamer.size(); i++)		//если отряд мертв, то он будет под остальными спрайтами отрядов противника
		if (MainCharacter.ArmyGamer[i].Life == false)
		{
			_window.draw(*MainCharacter.ArmyGamer[i].sprite);
		}

	if (hostile.ArmyEnemy_1.empty() == false)				//вывод спрайтов противника
	{
		for (int i(0); i < hostile.ArmyEnemy_1.size(); i++)
			_window.draw(*hostile.ArmyEnemy_1[i].sprite);
	}


	for (int i(0); i < MainCharacter.ArmyGamer.size(); i++)		//если отряд жив, то спрайты игрока оказываются поверх остальных спрайтов
		if (MainCharacter.ArmyGamer[i].Life == true)
		{
			_window.draw(*MainCharacter.ArmyGamer[i].sprite);
		}
		*/
	for (int i(0); i < MainCharacter.ArmyGamer.size(); i++) {
		MainCharacter.ArmyGamer[i].drawTo(_window);
	}
	for (int i(0); i < hostile.ArmyEnemy_1.size(); i++) {
		hostile.ArmyEnemy_1[i].drawTo(_window);
	}
}
//////////////////////////////////////////////////////////////////////////////
void UpdateUnitArmy(Player &MainCharacter, Enemy_1 &hostile)   //обновление юнитов на карте
{
	for (int i(0); i < MainCharacter.ArmyGamer.size(); i++)
		MainCharacter.ArmyGamer[i].Update();

	if (hostile.ArmyEnemy_1.empty() == false)
	{
		for (int i(0); i < hostile.ArmyEnemy_1.size(); i++)
			hostile.ArmyEnemy_1[i].Update();
	}
}
//////////////////////////////////////////////////////////////////////////////

string Generation_Rand_name()
{
	//генерация рандомногой имени, считывающегося из файла .txt и
	//перелающиеся в тело программы
	vector<string>Rand_Name_Array;
	vector<string>Rand_Last_Name_Array;
	vector<string>::iterator it_Name;
	string word_to_array;
	ifstream ifile_name;
	ifstream ifile_last_name;
	int temp_name;

	ifile_name.open(projectPath + nameFileFolder + "Name_Commander.txt");
	ifile_last_name.open(projectPath + nameFileFolder + "Last_Name_Commander.txt");

	if (!ifile_name.is_open() || !ifile_last_name.is_open())
	{
		cout << "FileEROR...";
	}
	else
	{

		while (!ifile_name.eof())			//имена
		{
			getline(ifile_name, word_to_array);
			Rand_Name_Array.push_back(word_to_array);
		}

		while (!ifile_last_name.eof())
		{
			getline(ifile_last_name, word_to_array);
			Rand_Last_Name_Array.push_back(word_to_array);
		}


		temp_name = rand() % Rand_Name_Array.size();

		it_Name = Rand_Name_Array.begin() + temp_name;
		word_to_array = *it_Name;
		word_to_array += " ";


		temp_name = rand() % Rand_Last_Name_Array.size();

		it_Name = Rand_Last_Name_Array.begin() + temp_name;
		word_to_array += *it_Name;

		return word_to_array;
	}
}
//////////////////////////////////////////////////////////////////////////////

void PressPassStep(AllInterfaceMissiom &In, Event &_event, Player &MainCharacter, RenderWindow &windows)
{

	if (Keyboard::isKeyPressed(Keyboard::Space) && MainCharacter.orders > 0 && tnd->PressedSpace == false)
	{
		tnd->PressedSpace = true;
		if (tnd->PressedSpace == true)
		{
			cout << "Нажат space" << endl;
			tnd->screen_lock = true;
			In.IUP3._draw_SureStupe = true;
		}

	}


	if (Keyboard::isKeyPressed(Keyboard::Space) && MainCharacter.orders <= 0)
	{
		tnd->PressedSpace = true;
		if (tnd->PressedSpace == true)
		{
			tnd->StepPlayerInspection = true;
		}
	}

}
//////////////////////////////////////////////////////////////////////////////

void StepOnStep(Player &MainCharacter)
{
	if (tnd->StepPlayerInspection == true)
	{
		for (int i(0); i < MainCharacter.ArmyGamer.size(); i++)
		{
			MainCharacter.ArmyGamer[i].CouterAttack = MainCharacter.ArmyGamer[i].ConstCouterAttack;
			MainCharacter.ArmyGamer[i].CouterStep = MainCharacter.ArmyGamer[i].ConstCouterStep;
			if (MainCharacter.ArmyGamer[i].isSelect == true)
			{
				MainCharacter.ArmyGamer[i].isSelect = false;
			}
		}
		MainCharacter.orders = MainCharacter.GetMaxOrders();
		tnd->StepPlayerInspection = false;
		tnd->CouterS++;
		GreenTileOFF();
	}
}


//////////////////////////////////////////////////////////////////////////////

void IsSelectMouseMissiomInterace(AllInterfaceMissiom &In, Event &_event, RenderWindow &windows, Player &MainCharacter)
{
	if (tnd->screen_lock == false)
	{
		In.Ex.IsSelectExit(_event, windows);
		In.IUP.IsSelectInformUnitPlayer(_event, windows);
		In.IUP2.IsSelectInformUnitHostile(_event, windows);
		In._map.IsSelectInterfaceMap(_event, windows, MainCharacter);
		PressPassStep(In, _event, MainCharacter, windows);

	}
	In.IUP3.IsSelectSureStupee(_event, windows);
	In.HaltNo.IsSelectSureHalt(_event, windows);


}

//////////////////////////////////////////////////////////////////////////////

void DrawInterfaceMission(AllInterfaceMissiom &In, RenderWindow &window)
{
	In.Ex.DrawExit(window);
	In.IUP.DrawInfo(window);
	In.IUP2.DrawInfoHostile(window);
	In.IUP3.IsDrawSureStupee(window);
	In._map.IsDrawInterfaceMap(window);
	In.HaltNo.IsDrawSureHalt(window);
	In.Tray.DrawTrayUnit(window);

	if (tnd->DownloadArt == true)
	{
		window.draw(tnd->sprite_DownloadArt);
		window.draw(tnd->sprite_DownloadStrips);
	}
}


//////////////////////////////////////////////////////////////////////////////

void BroadcastVariablesPlayer(AllInterfaceMissiom &In, Unit &Teamp)
{
	In.IUP.nameComandor = Teamp.Test;	//имя командира

	In.IUP.SelectLvl = Teamp.lvl;		//лвл

	In.IUP.StaminaUnit = Teamp.Stamina;	//выносливость
	In.IUP.MoraleUnit = Teamp.Morale;		//мораль

	In.IUP.ConstStaminaUnit = Teamp.ConstStamina;	//выносливость
	In.IUP.ConstMoraleUnit = Teamp.ConstMorale;	//мораль

	In.IUP.People = Teamp.PeopleLive;			//количество людей
	In.IUP.HurtPeople = Teamp.PeopleHealth;	//количесво не раненных

	In.IUP.ConstPeople = Teamp.ConstPeopleLive;		//количество людей
	In.IUP.ConstHurtPeople = Teamp.ConstPeopleHealth;	// количесво не раненных

	In.IUP.CouterStepUnit = Teamp.CouterStep;			//количество отсавшихся шагов
	In.IUP.CouterAmmo = Teamp.Ammo;					//количество боеприпасов
	In.IUP.CouterAttackUnit = Teamp.CouterAttack;		//количество оставшихся атак
	In.IUP.UnitId = Teamp.Id;						//айди юнита

	In.IUP.ConstCoterS = Teamp.ConstCouterStep;
	In.IUP.CouterS = Teamp.CouterStep;
	In.IUP.ConstCouterA = Teamp.ConstCouterAttack;
	In.IUP.CouterA = Teamp.CouterAttack;
}

//////////////////////////////////////////////////////////////////////////////

void BroadcastVariablesHostile(AllInterfaceMissiom &In, Unit &Teamp)
{
	In.IUP2.nameComandor2 = Teamp.Test;	//имя командира
	In.IUP2.SelectLvl2 = Teamp.lvl;		//лвл

	In.IUP2.StaminaUnit2 = Teamp.Stamina;	//выносливость
	In.IUP2.MoraleUnit2 = Teamp.Morale;		//мораль

	In.IUP2.ConstStaminaUnit2 = Teamp.ConstStamina;	//выносливость
	In.IUP2.ConstMoraleUnit2 = Teamp.ConstMorale;	//мораль

	In.IUP2.People2 = Teamp.PeopleLive;			//количество людей
	In.IUP2.HurtPeople2 = Teamp.PeopleHealth;	//количесво не раненных

	In.IUP2.ConstPeople2 = Teamp.ConstPeopleLive;		//количество людей
	In.IUP2.ConstHurtPeople2 = Teamp.ConstPeopleHealth;	// количесво не раненных
}


/////////////////////////////////////////////////////////////////////////////////////////

void UpdateInterface(AllInterfaceMissiom &In, Player &MainCharacter, Enemy_1 &hostile,  Event &_event)	//передача данных в простые окна информации о юнитах
{
	for (int i(0); i < MainCharacter.ArmyGamer.size(); i++)
	{
		if (MainCharacter.ArmyGamer[i].isSelect == true)
		{
			if (In.IUP.missingStep == true && MainCharacter.ArmyGamer[i].Id == In.IUP.UnitId && MainCharacter.ArmyGamer[i].CouterAttack == MainCharacter.ArmyGamer[i].ConstCouterAttack && MainCharacter.ArmyGamer[i].CouterStep == MainCharacter.ArmyGamer[i].ConstCouterStep && MainCharacter.orders > 0)
			{
				MainCharacter.ArmyGamer[i].Halt();
				In.IUP.missingStep = false;
				MainCharacter.orders -= 1;
				GreenTileOFF();
				MainCharacter.ArmyGamer[i].isSelect = false;

				//cout << "Sraborala knopka otdiha" << endl;

				break;
			}	//пропускаем ход если нажата клавиша


			if (In.IUP.cross == false)
			{
				In.IUP._draw = true;

				if (MainCharacter.ArmyGamer[i].UnitToUnit == 0)
				{
					In.IUP._UnitToUnit = 0;
				}

				if (MainCharacter.ArmyGamer[i].hurt == true)
				{
					In.IUP._hurt = true;
				}
				else { In.IUP._hurt = false; }

				BroadcastVariablesPlayer(In, MainCharacter.ArmyGamer[i]);

				In.IUP.selectionStamina = false;
				In.IUP.selectionMorale = false;
				break;
			}


		}
		else
		{
			In.IUP._draw = false;
		}
	}

	for (int i(0); i < MainCharacter.ArmyGamer.size(); i++)
	{
		if (In.IUP.Fast == true && (In.IUP.UnitId == MainCharacter.ArmyGamer[i].Id) && MainCharacter.ArmyGamer[i].isSelect == true && MainCharacter.orders > 0 && MainCharacter.ArmyGamer[i].CouterStep > 0)
		{
			MainCharacter.ArmyGamer[i].fast_step_True = true;
			GreenToTheTile(MainCharacter.ArmyGamer[i]);

			break;
		}


		if (In.IUP.Fast == false && In.IUP.UnitId == MainCharacter.ArmyGamer[i].Id && MainCharacter.ArmyGamer[i].isSelect == true && MainCharacter.orders > 0 && MainCharacter.ArmyGamer[i].CouterStep > 0)
		{
			MainCharacter.ArmyGamer[i].fast_step_True = false;
			GreenTileOFF();
			GreenToTheTile(MainCharacter.ArmyGamer[i]);
			if (tnd->screen_lock == false)
			{
				TileGreenOn(_event);
				AttackUnitPlayerToHostile(_event, MainCharacter, hostile);
			}
			break;
		}
	}



	for (int i(0); i < MainCharacter.ArmyGamer.size(); i++)
	{
		if (MainCharacter.ArmyGamer[i].Stamina < (MainCharacter.ArmyGamer[i].ConstStamina / 4) && In.IUP.UnitId == MainCharacter.ArmyGamer[i].Id&& MainCharacter.ArmyGamer[i].isSelect == true && MainCharacter.orders > 0 && MainCharacter.ArmyGamer[i].CouterStep > 0)
		{
			MainCharacter.ArmyGamer[i].fast_step_True = false;
			In.IUP.Fast = false;
			break;
		}
	}

	In.Tray.UpdateTrayUnit(MainCharacter.ArmyGamer);				//для треи внизу возле карты, передаем данные

	///////////////////////////////////////////////////////////////////////////вражеский
	for (int i(0); i < hostile.ArmyEnemy_1.size(); i++)
	{
		if (hostile.ArmyEnemy_1[i].isSelectHostile == true)
		{
			if (In.IUP2.cross2 == false)
			{
				In.IUP2._draw2 = true;


				if (hostile.ArmyEnemy_1[i].UnitToUnit == 0)
				{
					In.IUP2._UnitToUnit2 = 0;
				}

				if (hostile.ArmyEnemy_1[i].hurt == true)
				{
					In.IUP2._hurt2 = true;
				}

				else { In.IUP2._hurt2 = false; }

				BroadcastVariablesHostile(In, hostile.ArmyEnemy_1[i]);
				In.IUP2.selectionStamina2 = false;
				In.IUP2.selectionMorale2 = false;

				break;
			}
		}
		else
		{
			In.IUP2._draw2 = false;
		}
	}

	In._map.Order = (int)MainCharacter.orders;
	In._map._CouterS = tnd->CouterS;

}

//////////////////////////////////////////////////////////////////////////////

void IsSelectMouseMissiomStaticNON(Event &event, Player &MainCharacter, Enemy_1 & hostile)
{
	if (tnd->screen_lock == false)
	{
		TileRedOnRedCursor(event, hostile, MainCharacter);	//окрашиваем тайл атаки если попадаем в спрайт мышью
		OffSelectUnitToHostilePlayer(hostile);	//сбрасываем курсор с вражеского если выделяем другого вражеского юнита
	}
}

//////////////////////////////////////////////////////////////////////////////

void UpdateMissiom(Player& MainCharacter)
{
	tnd->FrameSpace += elapsed;	//засикаем время для промежутку между нажатием клавиши space
	tnd->CouterClick_Frame += elapsed;	//запускае время, для промежутку между нажатием на кнопку ускорить шаг
	tnd->FrameDownload += elapsed;

	if (tnd->CouterClick_Frame > 1000 && tnd->Teamp_CouterClick_Frame == true)
	{
		tnd->CouterClick_Frame = 0;

		if (tnd->Fast_2 == true)
		{
			tnd->Fast_2 = false;
		}

		tnd->Teamp_CouterClick_Frame = false;
	}

	if (tnd->FrameDownload > 500 && tnd->DownloadArt == true)
	{
		tnd->FrameDownload = 0;
		tnd->Start = true;
	}

	if (tnd->FrameSpace > 2000)	//для промежутка нажатие клавиши space
	{
		tnd->FrameSpace = 0;
		tnd->PressedSpace = false;
	}

	if (MainCharacter.orders <= 0)	//если у игрока не осталось ходов, то мы отбираем возможность ходить
	{
		tnd->MovementPlayer = false;
	}

	if (MainCharacter.orders > 0)
	{
		tnd->MovementPlayer = true;
	}
	StepOnStep(MainCharacter);
}