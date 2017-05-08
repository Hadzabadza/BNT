#pragma warning(disable : 4996)	//отключить deprecate
#include <sstream>
#include "GlobalFunctionMissiom.h"
using namespace std;
using namespace sf;

To_Exit::To_Exit()
{
	sprite_exit.setTexture(TextureLoader::tex->exitBTN);
	sprite_exit.setTextureRect(IntRect(0, 0, 91, 40));
	sprite_exit.setScale(2, 2);
}

void To_Exit::DrawExit(RenderWindow &_window)
{
	center = _window.getView().getCenter();
	size = _window.getView().getSize();
	sprite_exit.setPosition(center.x - size.x / 2, center.y - size.y / 2);
	_window.draw(sprite_exit);
}

void To_Exit::IsSelectExit(Event &_event, RenderWindow &_window)
{
	NoExit = false;


	if (IntRect(0, 0, 182, 80).contains(Mouse::getPosition(_window)))
	{
		if (_event.type == Event::MouseButtonPressed)//если нажата клавиша мыши
			if (_event.key.code == Mouse::Left)
			{//а именно левая
				NoExit = true;
			}
	}
	

	if (NoExit)
	{
		exit(1);
	}
}




InformUnitPlayer::InformUnitPlayer()
{
	Color color(82, 17, 20); //цвет букв
	_draw = false;
	_hurt = false;
	selectionStamina = false;
	selectionMorale = false;
	cross = false;
	missingStep = false;
	Fast = false;

	sprite_infoUnitPlayer.setTexture(TextureLoader::tex->unitInterface);//само окно
	sprite_infoUnitPlayer.setTextureRect(IntRect(0, 0, 119, 165));
	sprite_infoUnitPlayer.setScale(2, 2);

	sprite_infoUnitPlayer_Fast.setTexture(TextureLoader::tex->unitInterface);//само окно
	sprite_infoUnitPlayer_Fast.setTextureRect(IntRect(0, 481, 16, 17));
	sprite_infoUnitPlayer_Fast.setScale(2, 2);

	sprite_Black.setTexture(TextureLoader::tex->unitInterface);//черная полоска
	sprite_Black.setScale(2, 2);

	sprite_Red.setTexture(TextureLoader::tex->unitInterface);//красная полоска
	sprite_Red.setScale(2, 2);

	sprite_Green.setTexture(TextureLoader::tex->unitInterface);//зеленая полоска
	sprite_Green.setScale(2, 2);

	fontText.loadFromFile(projectPath+fontsFolder+"3572.ttf");	//шрифт
	fontText2.loadFromFile(projectPath + fontsFolder + "acknowtt.ttf");

	textInfoLvl.setString("");				//уровень отряда
	textInfoLvl.setFont(fontText2);
	textInfoLvl.setCharacterSize(55);
	textInfoLvl.scale(0.3, 0.44);
	textInfoLvl.setColor(color);

	textInfoSquad.setString("");	//тип отряда
	textInfoSquad.setFont(fontText);
	textInfoSquad.setCharacterSize(45);
	textInfoSquad.scale(0.29, 0.29);
	textInfoSquad.setColor(color);

	textInfoStrength.setString(""); //числность отряда
	textInfoStrength.setFont(fontText2);
	textInfoStrength.setCharacterSize(45);
	textInfoStrength.scale(0.3, 0.44);
	textInfoStrength.setColor(Color(255, 255, 255, 160));

	textInfoComanderName.setString("");		//имя командира
	textInfoComanderName.setFont(fontText);
	textInfoComanderName.setCharacterSize(45);
	textInfoComanderName.scale(0.29, 0.29);
	textInfoComanderName.setColor(color);


	textInfoMorale.setString("");		//мораль
	textInfoMorale.setFont(fontText);
	textInfoMorale.setCharacterSize(45);
	textInfoMorale.scale(0.29, 0.29);
	
	textInfoStamina.setString("");		//выносливость
	textInfoStamina.setFont(fontText);
	textInfoStamina.setCharacterSize(45);
	textInfoStamina.scale(0.29, 0.29);

	textInfoStepCouter.setString(""); //количество шагов
	textInfoStepCouter.setFont(fontText2);
	textInfoStepCouter.setCharacterSize(45);
	textInfoStepCouter.scale(0.3, 0.44);
	textInfoStepCouter.setColor(Color(255, 255, 255, 160));
	
	textInfoAmmo.setString(""); //количество боеприпасов
	textInfoAmmo.setFont(fontText2);
	textInfoAmmo.setCharacterSize(45);
	textInfoAmmo.scale(0.3, 0.44);
	textInfoAmmo.setColor(Color(255, 255, 255, 160));

	textInfoAttackpCouter.setString(""); //количество боеприпасов
	textInfoAttackpCouter.setFont(fontText2);
	textInfoAttackpCouter.setCharacterSize(45);
	textInfoAttackpCouter.scale(0.3, 0.44);
	textInfoAttackpCouter.setColor(Color(255, 255, 255, 160));

	sprite_infoUnitPlayer2.setTexture(TextureLoader::tex->unitInterface);
	
}


void InformUnitPlayer::DrawInfo(RenderWindow& _window)		//вывод интерфейса игрока
{
	if (_draw == true)
	{
		center1 = _window.getView().getCenter();
		size1 = _window.getView().getSize();

		if (Fast == false)
		{
			sprite_infoUnitPlayer.setTextureRect(IntRect(0, 0, 119, 165));
		}

		sprite_infoUnitPlayer.setPosition(center1.x - size1.x / 2, center1.y - size1.y / 3);
		_window.draw(sprite_infoUnitPlayer);

		if (Fast == true)
		{
			sprite_infoUnitPlayer_Fast.setPosition(center1.x - size1.x / 2.379, center1.y - size1.y / 3.65);
			_window.draw(sprite_infoUnitPlayer_Fast);
		}

		if (_UnitToUnit == 0)
		{

			if (_hurt == false)
			{
				sprite_infoUnitPlayer2.setTextureRect(IntRect(120, 0, 25, 33));
				sprite_infoUnitPlayer2.setScale(2, 2);
				sprite_infoUnitPlayer2.setPosition(center1.x - size1.x / 2.880, center1.y - size1.y / 3.15);
				_window.draw(sprite_infoUnitPlayer2);
			}

			if (_hurt == true)
			{
				sprite_infoUnitPlayer2.setTextureRect(IntRect(146, 0, 22, 33));
				sprite_infoUnitPlayer2.setScale(2, 2);
				sprite_infoUnitPlayer2.setPosition(center1.x - size1.x / 2.91, center1.y - size1.y / 3.15);
				_window.draw(sprite_infoUnitPlayer2);
			}

			textInfoSquad.setString("Отряд Пикейщиков");
			textInfoSquad.setPosition(center1.x - size1.x / 2.028, center1.y - size1.y / 5.1);		//размещаем текст center1.x - size1.x / 2.04, center1.y - size1.y / 4.9
			_window.draw(textInfoSquad);

		}

		
		if (StaminaUnit >= ((ConstStaminaUnit / 100) * 80) && selectionStamina == false)	//1250
		{
			Color color_1(56, 233, 21);
			textInfoStamina.setColor(color_1);
			textInfoStamina.setString("Свежи");
			selectionStamina = true;
		}


		if (StaminaUnit >= ((ConstStaminaUnit / 100) * 60) && selectionStamina == false)	//1000
		{
			Color color_1(88, 159, 91);
			textInfoStamina.setColor(color_1);
			textInfoStamina.setString("Бодры");
			selectionStamina = true;
		}


		if (StaminaUnit >= ((ConstStaminaUnit / 100) * 40) && selectionStamina == false)	//789
		{
			Color color_1(233, 222, 21);
			textInfoStamina.setColor(color_1);
			textInfoStamina.setString("Утомлены");
			selectionStamina = true;
		}


		if (StaminaUnit >= ((ConstStaminaUnit / 100) * 20) && selectionStamina == false)	//517
		{
			Color color_1(233, 135, 21);
			textInfoStamina.setColor(color_1);
			textInfoStamina.setString("Измотаны");
			selectionStamina = true;
		}


		if (StaminaUnit >= ((ConstStaminaUnit / 100) * 5) && selectionStamina == false || StaminaUnit < 0)	//250
		{
			Color color_1(233, 21, 21);
			textInfoStamina.setColor(color_1);
			textInfoStamina.setString("Истощены");
			selectionStamina = true;
		}
		



		if (MoraleUnit >= ((ConstMoraleUnit / 100) * 80) && selectionMorale == false)	//1250
		{
			Color color_1(56, 233, 21);
			textInfoMorale.setColor(color_1);
			textInfoMorale.setString("Жаждут боя");
			selectionMorale = true;
		}


		if (MoraleUnit >= ((ConstMoraleUnit / 100) * 60) && selectionMorale == false)	//1000
		{
			Color color_1(88, 159, 91);
			textInfoMorale.setColor(color_1);
			textInfoMorale.setString("Готовы сражаться");
			selectionMorale = true;
		}


		if (MoraleUnit >= ((ConstMoraleUnit / 100) * 40) && selectionMorale == false)	//789
		{
			Color color_1(233, 222, 21);
			textInfoMorale.setColor(color_1);
			textInfoMorale.setString("Колеблются");
			selectionMorale = true;
		}


		if (MoraleUnit >= ((ConstMoraleUnit / 100) * 20) && selectionMorale == false)	//517
		{
			Color color_1(233, 135, 21);
			textInfoMorale.setColor(color_1);
			textInfoMorale.setString("Подавлены");
			selectionMorale = true;
		}


		if (MoraleUnit >= ((ConstMoraleUnit / 100) * 5) && selectionMorale == false || MoraleUnit < 0)	//250
		{
			Color color_1(233, 21, 21);
			textInfoMorale.setColor(color_1);
			textInfoMorale.setString("Бегство");
			selectionMorale = true;
		}

		Teamp_1.str("");																	//лвл отряда
		Teamp_1 << SelectLvl;
		textInfoLvl.setString("lvl " + Teamp_1.str());
		textInfoLvl.setPosition(center1.x - size1.x / 2.07, center1.y - size1.y / 15);
		
		_CouterStepUnit.str("");															//количество оставшихся шагов
		_CouterStepUnit << CouterStepUnit;
		textInfoStepCouter.setString(_CouterStepUnit.str());
		textInfoStepCouter.setPosition(center1.x - size1.x / 2.62, center1.y - size1.y / 14);
		
		_CouterAmmo.str("");															//количество оставшихся боеприпасов
		_CouterAmmo << CouterAmmo;
		textInfoAmmo.setString(_CouterAmmo.str());
		textInfoAmmo.setPosition(center1.x - size1.x / 3.24, center1.y - size1.y / 14);

		_CouterAttackUnit.str("");															//количество оставшихся атак
		_CouterAttackUnit << CouterAttackUnit;
		textInfoAttackpCouter.setString(_CouterAttackUnit.str());
		textInfoAttackpCouter.setPosition(center1.x - size1.x / 2.92, center1.y - size1.y / 14);


		textInfoComanderName.setString("Командир:" + nameComandor);
		textInfoComanderName.setPosition(center1.x - size1.x / 2.028, center1.y - size1.y / 6.35);	//размещаем текст center1.x - size1.x / 2.04, center1.y - size1.y / 6.7
		
		textInfoStamina.setPosition(center1.x - size1.x / 2.07, center1.y - size1.y / 8);
		textInfoMorale.setPosition(center1.x - size1.x / 2.07, center1.y - size1.y / 10);
		



		_window.draw(textInfoAttackpCouter);
		_window.draw(textInfoAmmo);
		_window.draw(textInfoStepCouter);
		_window.draw(textInfoComanderName);
		_window.draw(textInfoStamina);
		_window.draw(textInfoMorale);
		_window.draw(textInfoLvl);
		DrawStrips(_window);
	}
}

int InformUnitPlayer::IntToInt(int a, int b)
{
	float z;
	z = (((float)30 / (float)a)*(float)b);
	return (int)z;
}

void InformUnitPlayer::DrawStrips(RenderWindow &_window)
{
	sprite_Black.setPosition(center1.x - size1.x / 2.04, center1.y - size1.y / 4.57);
	sprite_Black.setTextureRect(IntRect(120, 44, 30, 5));
	_window.draw(sprite_Black);

	sprite_Red.setPosition(center1.x - size1.x / 2.04, center1.y - size1.y / 4.57);
	sprite_Red.setTextureRect(IntRect(120, 39, IntToInt(ConstPeople, People), 5));
	_window.draw(sprite_Red);

	sprite_Green.setPosition(center1.x - size1.x / 2.04, center1.y - size1.y / 4.57);
	sprite_Green.setTextureRect(IntRect(120, 34, IntToInt(ConstHurtPeople, HurtPeople), 5));
	_window.draw(sprite_Green);

	_String.str("");
	_String2.str("");

	_String << People;
	_String2 << HurtPeople;

	textInfoStrength.setString(_String2.str() + "/" + _String.str());
	textInfoStrength.setPosition(center1.x - size1.x / 2.08, center1.y - size1.y / 4.29);
	_window.draw(textInfoStrength);

}


void InformUnitPlayer::IsSelectInformUnitPlayer(Event& _event, RenderWindow& _window)
{
	if (_draw == true)
	{
		if (IntRect(0, 148, 20, 18).contains(Mouse::getPosition(_window)))	//закрыть информационное окно
		{
			if (_event.type == Event::MouseButtonPressed)
				if (_event.key.code == Mouse::Left)
				{
					_draw = false;
					cross = true;
				}
		}


		
		if (IntRect(8, 177, 29, 29).contains(Mouse::getPosition(_window)))	//отдохнуть
		{

			if (_event.type == Event::MouseButtonPressed)
				if (_event.key.code == Mouse::Left)
				{
					if (ConstCoterS == CouterS && ConstCouterA == CouterA)
					{
						_draw = false;
						missingStep = true;
						if (tnd->No_fast == true)
						{
							tnd->No_fast = false;
						}
					}
					else
					{
						cout << "Srabotalo" << endl;
						tnd->OnSureHalt = true;
						tnd->screen_lock = true;

						if (tnd->No_fast == true)
						{
							tnd->No_fast = false;
						}
					}
				}
		}
		

		

		if (IntRect(85, 178, 29, 29).contains(Mouse::getPosition(_window)))	//перети в бег
		{
			if (_event.type == Event::MouseButtonPressed)
				if (_event.key.code == Mouse::Left)
				{

					if (tnd->Fast_2 == true)
					{
						Fast = false;
						tnd->Teamp_CouterClick_Frame = true;
						if (tnd->No_fast == true)
						{
							tnd->No_fast = false;
						}
					}

					if (StaminaUnit > (ConstStaminaUnit / 4) && tnd->Fast_2 == false)
					{
						tnd->Fast_2 = true;
						Fast = true;
						if (tnd->No_fast == true)
						{
							tnd->No_fast = false;
						}
					}

					if (StaminaUnit < (ConstStaminaUnit / 4))
					{
						tnd->OnSureHalt = true;
						tnd->screen_lock = true;
						tnd->No_fast = true;
					}

				}
		}

	}
}

InformUnitHostile::InformUnitHostile()
{
	Color color(82, 17, 20); //цвет букв
	_draw2 = false;
	_hurt2 = false;
	selectionStamina2 = false;
	selectionMorale2 = false;
	cross2 = false;

	sprite_infoUnitPlayer3.setTexture(TextureLoader::tex->unitInterface);//само окно
	sprite_infoUnitPlayer3.setTextureRect(IntRect(0, 166, 119, 162));
	sprite_infoUnitPlayer3.setScale(2, 2);

	sprite_infoUnitPlayer4.setTexture(TextureLoader::tex->unitInterface);//бошка
	sprite_infoUnitPlayer4.setScale(2, 2);

	sprite_Black2.setTexture(TextureLoader::tex->unitInterface);//черная полоска
	sprite_Black2.setScale(2, 2);

	sprite_Red2.setTexture(TextureLoader::tex->unitInterface);//красная полоска
	sprite_Red2.setScale(2, 2);

	sprite_Green2.setTexture(TextureLoader::tex->unitInterface);//зеленая полоска
	sprite_Green2.setScale(2, 2);

	fontText4.loadFromFile(projectPath + fontsFolder+"3572.ttf");	//шрифт
	fontText5.loadFromFile(projectPath + fontsFolder+"acknowtt.ttf");

	textInfoLvl2.setString("");				//уровень отряда
	textInfoLvl2.setFont(fontText5);
	textInfoLvl2.setCharacterSize(55);
	textInfoLvl2.scale(0.3, 0.44);
	textInfoLvl2.setColor(color);

	textInfoSquad2.setString("");	//тип отряда
	textInfoSquad2.setFont(fontText4);
	textInfoSquad2.setCharacterSize(45);
	textInfoSquad2.scale(0.29, 0.29);
	textInfoSquad2.setColor(color);

	textInfoStrength2.setString(""); //числность отряда
	textInfoStrength2.setFont(fontText5);
	textInfoStrength2.setCharacterSize(45);
	textInfoStrength2.scale(0.3, 0.44);
	textInfoStrength2.setColor(Color(255, 255, 255, 160));

	textInfoComanderName2.setString("");		//имя командира
	textInfoComanderName2.setFont(fontText4);
	textInfoComanderName2.setCharacterSize(45);
	textInfoComanderName2.scale(0.29, 0.29);
	textInfoComanderName2.setColor(color);


	textInfoMorale2.setString("");		//мораль
	textInfoMorale2.setFont(fontText4);
	textInfoMorale2.setCharacterSize(45);
	textInfoMorale2.scale(0.29, 0.29);

	textInfoStamina2.setString("");		//выносливость
	textInfoStamina2.setFont(fontText4);
	textInfoStamina2.setCharacterSize(45);
	textInfoStamina2.scale(0.29, 0.29);
}


void InformUnitHostile::DrawInfoHostile(RenderWindow& _window)
{
	if (_draw2 == true)
	{
		center2 = _window.getView().getCenter();
		size2 = _window.getView().getSize();
		sprite_infoUnitPlayer3.setPosition(center2.x + size2.x / 3.74, center2.y - size2.y / 3);
		_window.draw(sprite_infoUnitPlayer3);

		if (_UnitToUnit2 == 0)
		{

			if (_hurt2 == false)
			{
				sprite_infoUnitPlayer4.setTextureRect(IntRect(120, 0, 25, 33));
				sprite_infoUnitPlayer4.setPosition(center2.x + size2.x / 3.35, center2.y - size2.y / 3.15);
				_window.draw(sprite_infoUnitPlayer4);
			}

			if (_hurt2 == true)
			{
				sprite_infoUnitPlayer4.setTextureRect(IntRect(146, 0, 22, 33));
				sprite_infoUnitPlayer4.setPosition(center2.x + size2.x / 3.298, center2.y - size2.y / 3.15);
				_window.draw(sprite_infoUnitPlayer4);
			}


			textInfoSquad2.setString("Отряд Пикейщиков");
			textInfoSquad2.setPosition(center2.x + size2.x / 3.4, center2.y - size2.y / 4.8);		//размещаем текст center1.x - size1.x / 2.04, center1.y - size1.y / 4.9
			_window.draw(textInfoSquad2);
		}

		if (StaminaUnit2 >= ((ConstStaminaUnit2 / 100) * 80) && selectionStamina2 == false)	//1250
		{
			Color color_1(56, 233, 21);
			textInfoStamina2.setColor(color_1);
			textInfoStamina2.setString("Свежи");
			selectionStamina2 = true;
		}


		if (StaminaUnit2 >= ((ConstStaminaUnit2 / 100) * 60) && selectionStamina2 == false)	//1000
		{
			Color color_1(88, 159, 91);
			textInfoStamina2.setColor(color_1);
			textInfoStamina2.setString("Бодры");
			selectionStamina2 = true;
		}


		if (StaminaUnit2 >= ((ConstStaminaUnit2 / 100) * 40) && selectionStamina2 == false)	//789
		{
			Color color_1(233, 222, 21);
			textInfoStamina2.setColor(color_1);
			textInfoStamina2.setString("Утомлены");
			selectionStamina2 = true;
		}


		if (StaminaUnit2 >= ((ConstStaminaUnit2 / 100) * 20) && selectionStamina2 == false)	//517
		{
			Color color_1(233, 135, 21);
			textInfoStamina2.setColor(color_1);
			textInfoStamina2.setString("Измотаны");
			selectionStamina2 = true;
		}


		if (StaminaUnit2 >= ((ConstStaminaUnit2 / 100) * 5) && selectionStamina2 == false || StaminaUnit2 < 0)	//250
		{
			Color color_1(233, 21, 21);
			textInfoStamina2.setColor(color_1);
			textInfoStamina2.setString("Истощены");
			selectionStamina2 = true;
		}




		if (MoraleUnit2 >= ((ConstMoraleUnit2 / 100) * 80) && selectionMorale2 == false)	//1250
		{
			Color color_1(56, 233, 21);
			textInfoMorale2.setColor(color_1);
			textInfoMorale2.setString("Жаждут боя");
			selectionMorale2 = true;
		}


		if (MoraleUnit2 >= ((ConstMoraleUnit2 / 100) * 60) && selectionMorale2 == false)	//1000
		{
			Color color_1(88, 159, 91);
			textInfoMorale2.setColor(color_1);
			textInfoMorale2.setString("Готовы сражаться");
			selectionMorale2 = true;
		}


		if (MoraleUnit2 >= ((ConstMoraleUnit2 / 100) * 40) && selectionMorale2 == false)	//789
		{
			Color color_1(233, 222, 21);
			textInfoMorale2.setColor(color_1);
			textInfoMorale2.setString("Колеблются");
			selectionMorale2 = true;
		}


		if (MoraleUnit2 >= ((ConstMoraleUnit2 / 100) * 20) && selectionMorale2 == false)	//517
		{
			Color color_1(233, 135, 21);
			textInfoMorale2.setColor(color_1);
			textInfoMorale2.setString("Подавлены");
			selectionMorale2 = true;
		}


		if (MoraleUnit2 >= ((ConstMoraleUnit2 / 100) * 5) && selectionMorale2 == false || MoraleUnit2 < 0)	//250
		{
			Color color_1(233, 21, 21);
			textInfoMorale2.setColor(color_1);
			textInfoMorale2.setString("Бегство");
			selectionMorale2 = true;
		}



		Teamp_2.str("");																	//лвл отряда
		Teamp_2 << SelectLvl2;
		textInfoLvl2.setString("lvl " + Teamp_2.str());
		textInfoLvl2.setPosition(center2.x + size2.x / 3.298, center2.y - size2.y / 14);

		textInfoComanderName2.setString("Командир:" + nameComandor2);
		textInfoComanderName2.setPosition(center2.x + size2.x / 3.4, center2.y - size2.y / 6);	

		textInfoStamina2.setPosition(center2.x + size2.x / 3.3, center2.y - size2.y / 8);
		textInfoMorale2.setPosition(center2.x + size2.x / 3.3, center2.y - size2.y / 10);
		
		

		_window.draw(textInfoComanderName2);
		_window.draw(textInfoStamina2);
		_window.draw(textInfoMorale2);
		_window.draw(textInfoLvl2);
		DrawStripsHostile(_window);
	}
}

int InformUnitHostile::IntToInt2(int a, int b)
{
	float z;
	z = (((float)30 / (float)a)*(float)b);
	return (int)z;
}


void InformUnitHostile::DrawStripsHostile(RenderWindow &_window)
{
	
	sprite_Black2.setPosition(center2.x + size2.x / 2.305, center2.y - size2.y / 4.925);
	sprite_Black2.setTextureRect(IntRect(120, 44, 30, 5));
	_window.draw(sprite_Black2);

	sprite_Red2.setPosition(center2.x + size2.x / 2.305, center2.y - size2.y / 4.925);
	sprite_Red2.setTextureRect(IntRect(120, 39, IntToInt2(ConstPeople2, People2), 5));
	_window.draw(sprite_Red2);

	sprite_Green2.setPosition(center2.x + size2.x / 2.305, center2.y - size2.y / 4.925);
	sprite_Green2.setTextureRect(IntRect(120, 34, IntToInt2(ConstHurtPeople2, HurtPeople2), 5));
	_window.draw(sprite_Green2);

	_String3.str("");
	_String4.str("");

	_String3 << People2;
	_String4 << HurtPeople2;

	textInfoStrength2.setString(_String3.str() + "/" + _String4.str());
	textInfoStrength2.setPosition(center2.x + size2.x / 2.25, center2.y - size2.y / 4.6);
	_window.draw(textInfoStrength2);
}


void InformUnitHostile::IsSelectInformUnitHostile(Event& _event, RenderWindow& _window)
{
	if (_draw2 == true)
	{
		if (IntRect(1010, 147, 20, 18).contains(Mouse::getPosition(_window)))
		{
			if (_event.type == Event::MouseButtonPressed)
				if (_event.key.code == Mouse::Left)
				{
					_draw2 = false;
					cross2 = true;
				}
		}
	}
}

SureStupe::SureStupe()
{
	Color color(82, 17, 20); //цвет букв
	_draw_SureStupe = false;
	cross_SureStupe = false;

	fontText5.loadFromFile(projectPath + fontsFolder+"3572.ttf");	//шрифт

	sprite_infoUnitPlayer_SureStupe.setTexture(TextureLoader::tex->steoNotIn);//само окно
	sprite_infoUnitPlayer_SureStupe.setTextureRect(IntRect(0, 0, 512, 384));
	sprite_infoUnitPlayer_SureStupe.setScale(2, 2);

	textInfoSureStupe.setString("");	//тип отряда
	textInfoSureStupe.setFont(fontText5);
	textInfoSureStupe.setCharacterSize(55);
	textInfoSureStupe.scale(0.29, 0.29);
	textInfoSureStupe.setColor(color);
}

void SureStupe::IsSelectSureStupee(Event& _event, RenderWindow& _window)
{
	if (_draw_SureStupe == true || tnd->OnIUO3 == true)
	{
		
		if (IntRect(460, 396, 41, 30).contains(Mouse::getPosition(_window)))
		{
			if (_event.type == Event::MouseButtonPressed)
				if (_event.key.code == Mouse::Left)
				{
					tnd->StepPlayerInspection = true;
					tnd->screen_lock = false;
					_draw_SureStupe = false;
					tnd->OnIUO3 = false;
					cout << "Ход пропущен!" << endl;
				}
		}


		if (IntRect(525, 397, 41, 30).contains(Mouse::getPosition(_window)))
		{
			if (_event.type == Event::MouseButtonPressed)
				if (_event.key.code == Mouse::Left)
				{
					tnd->StepPlayerInspection = false;
					tnd->screen_lock = false;
					_draw_SureStupe = false;
					tnd->OnIUO3 = false;
					cout << "Вы не стали пропускать ход!" << endl;
				}
		}
	}


}

void SureStupe::IsDrawSureStupee(RenderWindow& _window)
{
	if (_draw_SureStupe == true || tnd->OnIUO3 == true)
	{
		center_SureStupe = _window.getView().getCenter();
		size_SureStupe = _window.getView().getSize();


		sprite_infoUnitPlayer_SureStupe.setPosition(center_SureStupe.x - size_SureStupe.x / 2, center_SureStupe.y - size_SureStupe.y / 2);
		_window.draw(sprite_infoUnitPlayer_SureStupe);


		textInfoSureStupe.setString("\tИспользована не вся инициатива,\n\n    вы точно желаете завершить ход?");
		textInfoSureStupe.setPosition(center_SureStupe.x - size_SureStupe.x / 5.6, center_SureStupe.y - size_SureStupe.y / 10);
		_window.draw(textInfoSureStupe);
	}
}

InterfaceMap::InterfaceMap()
{
	Color color(82, 17, 20); //цвет букв

	sprite_InterfaceMap.setTexture(TextureLoader::tex->unitInterface);//само окно
	sprite_InterfaceMap.setTextureRect(IntRect(0, 328, 169, 152));
	sprite_InterfaceMap.setScale(2, 2);


	fontText_InterfaceMap1.loadFromFile(projectPath + fontsFolder+"3572.ttf");	//шрифт
	fontText_InterfaceMap2.loadFromFile(projectPath + fontsFolder + "acknowtt.ttf");

	StepCouter_InterfaceMap.setString("");				//ход цифра
	StepCouter_InterfaceMap.setFont(fontText_InterfaceMap2);
	StepCouter_InterfaceMap.setCharacterSize(60);
	StepCouter_InterfaceMap.scale(0.3, 0.44);
	StepCouter_InterfaceMap.setColor(color);

	OrderCouter_InterfaceMap.setString("");				//количество оставшихся приказов
	OrderCouter_InterfaceMap.setFont(fontText_InterfaceMap2);
	OrderCouter_InterfaceMap.setCharacterSize(60);
	OrderCouter_InterfaceMap.scale(0.3, 0.44);
	OrderCouter_InterfaceMap.setColor(color);

	OrderText_InterfaceMap.setString("");				//приказы текст
	OrderText_InterfaceMap.setFont(fontText_InterfaceMap1);
	OrderText_InterfaceMap.setCharacterSize(40);
	OrderText_InterfaceMap.scale(0.4, 0.4);
	OrderText_InterfaceMap.setColor(color);

	StepText_InterfaceMap.setString("");				//ход текст
	StepText_InterfaceMap.setFont(fontText_InterfaceMap1);
	StepText_InterfaceMap.setCharacterSize(40);
	StepText_InterfaceMap.scale(0.4, 0.4);
	StepText_InterfaceMap.setColor(color);
}

void InterfaceMap::IsDrawInterfaceMap(RenderWindow &_window)
{
	center_SureStupe_InterfaceMap = _window.getView().getCenter();
	size_SureStupe_InterfaceMap = _window.getView().getSize();
	/////////////////////////////////////////////////////////////////////вывод хода
	_StepCouter_InterfaceMap.str("");
	_StepCouter_InterfaceMap << _CouterS;

	StepText_InterfaceMap.setString("ход");
	StepText_InterfaceMap.setPosition(center_SureStupe_InterfaceMap.x - size_SureStupe_InterfaceMap.x / 3.125, center_SureStupe_InterfaceMap.y + size_SureStupe_InterfaceMap.y / 2.166);


	if (_CouterS == 1)
	{
		StepCouter_InterfaceMap.setString(_StepCouter_InterfaceMap.str());
		StepCouter_InterfaceMap.setPosition(center_SureStupe_InterfaceMap.x - size_SureStupe_InterfaceMap.x / 2.96, center_SureStupe_InterfaceMap.y + size_SureStupe_InterfaceMap.y / 2.235);
	}

	if (_CouterS >= 2 && _CouterS <= 9)
	{
		StepCouter_InterfaceMap.setString(_StepCouter_InterfaceMap.str());
		StepCouter_InterfaceMap.setPosition(center_SureStupe_InterfaceMap.x - size_SureStupe_InterfaceMap.x / 2.94, center_SureStupe_InterfaceMap.y + size_SureStupe_InterfaceMap.y / 2.235);
	}

	if (_CouterS >= 10)
	{
		StepCouter_InterfaceMap.setString(_StepCouter_InterfaceMap.str());
		StepCouter_InterfaceMap.setPosition(center_SureStupe_InterfaceMap.x - size_SureStupe_InterfaceMap.x / 2.925, center_SureStupe_InterfaceMap.y + size_SureStupe_InterfaceMap.y / 2.235);
	}

	if (_CouterS == 11)
	{
		StepCouter_InterfaceMap.setString(_StepCouter_InterfaceMap.str());
		StepCouter_InterfaceMap.setPosition(center_SureStupe_InterfaceMap.x - size_SureStupe_InterfaceMap.x / 2.94, center_SureStupe_InterfaceMap.y + size_SureStupe_InterfaceMap.y / 2.235);
	}

	if (_CouterS >= 20)
	{
		StepCouter_InterfaceMap.setCharacterSize(50);
		StepCouter_InterfaceMap.setString(_StepCouter_InterfaceMap.str());
		StepCouter_InterfaceMap.setPosition(center_SureStupe_InterfaceMap.x - size_SureStupe_InterfaceMap.x / 2.92, center_SureStupe_InterfaceMap.y + size_SureStupe_InterfaceMap.y / 2.214);
	}

	if (_CouterS >= 100)
	{
		StepCouter_InterfaceMap.setCharacterSize(50);
		StepCouter_InterfaceMap.setString(_StepCouter_InterfaceMap.str());
		StepCouter_InterfaceMap.setPosition(center_SureStupe_InterfaceMap.x - size_SureStupe_InterfaceMap.x / 2.91, center_SureStupe_InterfaceMap.y + size_SureStupe_InterfaceMap.y / 2.214);
	}


	/////////////////////////////////////////////////////////////////////вывод приказов
	_OrderCouter_InterfaceMap.str("");
	_OrderCouter_InterfaceMap << Order;

	if (Order >= 5 || Order == 0)
	{
		OrderText_InterfaceMap.setString("приказов");
		OrderText_InterfaceMap.setPosition(center_SureStupe_InterfaceMap.x - size_SureStupe_InterfaceMap.x / 3.925, center_SureStupe_InterfaceMap.y + size_SureStupe_InterfaceMap.y / 2.543);

		OrderCouter_InterfaceMap.setString(_OrderCouter_InterfaceMap.str());
		OrderCouter_InterfaceMap.setPosition(center_SureStupe_InterfaceMap.x - size_SureStupe_InterfaceMap.x / 3.725, center_SureStupe_InterfaceMap.y + size_SureStupe_InterfaceMap.y / 2.638);
	}

	if (Order == 2 || Order == 4 || Order == 3)
	{
		OrderText_InterfaceMap.setString("приказа");
		OrderText_InterfaceMap.setPosition(center_SureStupe_InterfaceMap.x - size_SureStupe_InterfaceMap.x / 4.1, center_SureStupe_InterfaceMap.y + size_SureStupe_InterfaceMap.y / 2.543);

		OrderCouter_InterfaceMap.setString(_OrderCouter_InterfaceMap.str());
		OrderCouter_InterfaceMap.setPosition(center_SureStupe_InterfaceMap.x - size_SureStupe_InterfaceMap.x / 3.725, center_SureStupe_InterfaceMap.y + size_SureStupe_InterfaceMap.y / 2.638);
	}

	if (Order == 1)
	{
		OrderText_InterfaceMap.setString("приказ");
		OrderText_InterfaceMap.setPosition(center_SureStupe_InterfaceMap.x - size_SureStupe_InterfaceMap.x / 4.25, center_SureStupe_InterfaceMap.y + size_SureStupe_InterfaceMap.y / 2.543);
		
		OrderCouter_InterfaceMap.setString(_OrderCouter_InterfaceMap.str());
		OrderCouter_InterfaceMap.setPosition(center_SureStupe_InterfaceMap.x - size_SureStupe_InterfaceMap.x / 3.855, center_SureStupe_InterfaceMap.y + size_SureStupe_InterfaceMap.y / 2.638);
	}
	/////////////////////////////////////////////////////////////////////

	sprite_InterfaceMap.setPosition(center_SureStupe_InterfaceMap.x - size_SureStupe_InterfaceMap.x / 2, center_SureStupe_InterfaceMap.y + size_SureStupe_InterfaceMap.y / 9.65);
	_window.draw(sprite_InterfaceMap);
	_window.draw(StepText_InterfaceMap);
	_window.draw(StepCouter_InterfaceMap);
	_window.draw(OrderText_InterfaceMap);
	_window.draw(OrderCouter_InterfaceMap);
}


void InterfaceMap::IsSelectInterfaceMap(Event &_event, RenderWindow &window, Player &MainCharacter)
{

	if (IntRect(7, 735, 25, 33).contains(Mouse::getPosition(window)))	//нажимая пропуск худа на интерфейсе
	{
		if (_event.type == Event::MouseButtonPressed)
			if (_event.key.code == Mouse::Left)
			{
				if (MainCharacter.orders == 0)
				{
					tnd->StepPlayerInspection = true;
				}

				if (MainCharacter.orders > 0)
				{
					tnd->OnIUO3 = true;
				}
			}
	}

}

SureHalt::SureHalt()
{
	Color color(82, 17, 20); //цвет букв
	_draw_SureHalt = false;
	cross_SureHalt = false;

	fontText_SureHalt.loadFromFile(projectPath + fontsFolder + "3572.ttf");	//шрифт
	
	sprite_infoUnitPlayer_SureHalt.setTexture(TextureLoader::tex->steoNotHalt);//само окно
	sprite_infoUnitPlayer_SureHalt.setTextureRect(IntRect(0, 0, 512, 384));
	sprite_infoUnitPlayer_SureHalt.setScale(2, 2);

	textInfoSureHalt.setString("");	//тип отряда
	textInfoSureHalt.setFont(fontText_SureHalt);
	textInfoSureHalt.setCharacterSize(55);
	textInfoSureHalt.scale(0.29, 0.29);
	textInfoSureHalt.setColor(color);
}

void SureHalt::IsSelectSureHalt(Event& _event, RenderWindow& _window)
{
	if (_draw_SureHalt == true || tnd->OnSureHalt == true)
	{

		if (IntRect(496, 398, 42, 26).contains(Mouse::getPosition(_window)))
		{
			if (_event.type == Event::MouseButtonPressed)
				if (_event.key.code == Mouse::Left)
				{
					_draw_SureHalt = false;
					tnd->OnSureHalt = false;
					tnd->screen_lock = false;
				}
		}


	}


}

TrayUnit::TrayUnit()
{
	sprite_TrayUnit_end.setTexture(TextureLoader::tex->unitInterface);//спрайт окончания свитка
	sprite_TrayUnit_end.setTextureRect(IntRect(0, 528, 13, 32));
	sprite_TrayUnit_end.setScale(2, 2);
}

void SureHalt::IsDrawSureHalt(RenderWindow& _window)
{
	if (_draw_SureHalt == true || tnd->OnSureHalt == true)
	{
		center_SureHalt = _window.getView().getCenter();
		size_SureHalt = _window.getView().getSize();


		sprite_infoUnitPlayer_SureHalt.setPosition(center_SureHalt.x - size_SureHalt.x / 2, center_SureHalt.y - size_SureHalt.y / 2);
		_window.draw(sprite_infoUnitPlayer_SureHalt);

		if (tnd->OnSureHalt == true && tnd->No_fast == false)
		{
			textInfoSureHalt.setString("Отряд не может отдохнуть");
			textInfoSureHalt.setPosition(center_SureHalt.x - size_SureHalt.x / 9, center_SureHalt.y - size_SureHalt.y / 16);
		}

		if (tnd->No_fast == true)
		{
			textInfoSureHalt.setString("Отряд слишком устал для бега");
			textInfoSureHalt.setPosition(center_SureHalt.x - size_SureHalt.x / 8, center_SureHalt.y - size_SureHalt.y / 16);
		}

		_window.draw(textInfoSureHalt);
	}
}

TrayUnit_index::TrayUnit_index()
{
	ID_Unit = 0;			//айди юнита
	UnitToUnit_ID = 0;		//определяет какого юнита мы выбрали
	Life - false;				//жив юнит, или мертв
	Couter_Step_Unit = 0, Const_Couter_Step = 0;	//счетчик шагов
	Couter_Attack = 0, Const_Couter_Attack = 0;	//счетчик атак
	X_Position = 0, Y_Position = 0;				//мировые координаты позици
	IsSelectUnit = false;

	sprite_TrayUnit.setTexture(TextureLoader::tex->unitInterface);//спрайт свикта
	sprite_TrayUnit.setTextureRect(IntRect(0, 498, 33, 29));
	sprite_TrayUnit.setScale(2, 2);
	
	sprite_TrayUnit_Head.setTexture(TextureLoader::tex->unitInterface);//спрайт бошки
	sprite_TrayUnit_Head.setScale(2, 2);

	sprite_TrayUnit_Dot.setTexture(TextureLoader::tex->unitInterface);//спрайт точки
	sprite_TrayUnit_Dot.setScale(2, 2);
}

void TrayUnit::UpdateTrayUnit(vector<Unit> &ArmyGamer)
{
	SizeArmyGamer = ArmyGamer.size();
	ListUnit.resize(SizeArmyGamer);

	
	for (int i(0); i < ArmyGamer.size(); i++)
	{
		ListUnit[i].ID_Unit = ArmyGamer[i].Id;
		ListUnit[i].Const_Couter_Attack = ArmyGamer[i].ConstCouterAttack;
		ListUnit[i].Const_Couter_Step = ArmyGamer[i].ConstCouterStep;
		ListUnit[i].Couter_Attack = ArmyGamer[i].CouterAttack;
		ListUnit[i].Couter_Step_Unit = ArmyGamer[i].CouterStep;
		ListUnit[i].Life = ArmyGamer[i].Life;
		ListUnit[i].X_Position = ArmyGamer[i].x;
		ListUnit[i].Y_Position = ArmyGamer[i].y;
		ListUnit[i].UnitToUnit_ID = ArmyGamer[i].UnitToUnit;
		ListUnit[i].IsSelectUnit = ArmyGamer[i].isSelect;
	}
	
}

void TrayUnit::DrawTrayUnit(RenderWindow& _window)
{
	center_SureStupe_TrayUnit = _window.getView().getCenter();
	size_SureStupe_TrayUnit = _window.getView().getSize();

	for (int i(0); i < ListUnit.size(); i++)
	{
		
		if (i == 0)		//первый юнит
		{
			ListUnit[i].sprite_TrayUnit.setPosition(center_SureStupe_TrayUnit.x - size_SureStupe_TrayUnit.x / 3.65, center_SureStupe_TrayUnit.y + size_SureStupe_TrayUnit.y / 2.35);
			_window.draw(ListUnit[i].sprite_TrayUnit);
			
			//определяем айди типа юнита и выводим портрет по айди
			if (ListUnit[i].UnitToUnit_ID == 0 && ListUnit[i].Life == true)
			{
				if (ListUnit[i].IsSelectUnit == false)
				{
					ListUnit[i].sprite_TrayUnit_Head.setTextureRect(IntRect(134, 49, 13, 18));
					ListUnit[i].sprite_TrayUnit_Head.setPosition(center_SureStupe_TrayUnit.x - size_SureStupe_TrayUnit.x / 3.92, center_SureStupe_TrayUnit.y + size_SureStupe_TrayUnit.y / 2.27);
				}
				else
				{
					ListUnit[i].sprite_TrayUnit_Head.setTextureRect(IntRect(119, 49, 15, 19));
					ListUnit[i].sprite_TrayUnit_Head.setPosition(center_SureStupe_TrayUnit.x - size_SureStupe_TrayUnit.x / 3.9, center_SureStupe_TrayUnit.y + size_SureStupe_TrayUnit.y / 2.27);
				}
				
				_window.draw(ListUnit[i].sprite_TrayUnit_Head);
			}

			//рисуем черепок, если отряд убит
			if (ListUnit[i].Life == false)
			{
				ListUnit[i].sprite_TrayUnit_Head.setTextureRect(IntRect(147, 52, 11, 14));
				ListUnit[i].sprite_TrayUnit_Head.setPosition(center_SureStupe_TrayUnit.x - size_SureStupe_TrayUnit.x / 3.94, center_SureStupe_TrayUnit.y + size_SureStupe_TrayUnit.y / 2.24);
				_window.draw(ListUnit[i].sprite_TrayUnit_Head);
			}

			//отображение точки
			if (ListUnit[i].Couter_Step_Unit > 0 && ListUnit[i].Couter_Attack > 0 && ListUnit[i].Life == true)
			{
				ListUnit[i].sprite_TrayUnit_Dot.setTextureRect(IntRect(119, 68, 5, 4));
				ListUnit[i].sprite_TrayUnit_Dot.setPosition(center_SureStupe_TrayUnit.x - size_SureStupe_TrayUnit.x / 3.9, center_SureStupe_TrayUnit.y + size_SureStupe_TrayUnit.y / 2.3);
				_window.draw(ListUnit[i].sprite_TrayUnit_Dot);
			}

			if (ListUnit[i].Couter_Step_Unit == 0 && ListUnit[i].Couter_Attack > 0 && ListUnit[i].Life == true)
			{
				ListUnit[i].sprite_TrayUnit_Dot.setTextureRect(IntRect(124, 68, 5, 4));
				ListUnit[i].sprite_TrayUnit_Dot.setPosition(center_SureStupe_TrayUnit.x - size_SureStupe_TrayUnit.x / 3.9, center_SureStupe_TrayUnit.y + size_SureStupe_TrayUnit.y / 2.3);
				_window.draw(ListUnit[i].sprite_TrayUnit_Dot);
			}

			if (ListUnit[i].Couter_Step_Unit > 0 && ListUnit[i].Couter_Attack == 0 && ListUnit[i].Life == true)
			{
				ListUnit[i].sprite_TrayUnit_Dot.setTextureRect(IntRect(129, 68, 5, 4));
				ListUnit[i].sprite_TrayUnit_Dot.setPosition(center_SureStupe_TrayUnit.x - size_SureStupe_TrayUnit.x / 3.9, center_SureStupe_TrayUnit.y + size_SureStupe_TrayUnit.y / 2.3);
				_window.draw(ListUnit[i].sprite_TrayUnit_Dot);
			}

			if ((ListUnit[i].Couter_Step_Unit == 0 && ListUnit[i].Couter_Attack == 0 && ListUnit[i].Life == true) || ListUnit[i].Life == false)
			{
				ListUnit[i].sprite_TrayUnit_Dot.setTextureRect(IntRect(134, 68, 5, 4));
				ListUnit[i].sprite_TrayUnit_Dot.setPosition(center_SureStupe_TrayUnit.x - size_SureStupe_TrayUnit.x / 3.9, center_SureStupe_TrayUnit.y + size_SureStupe_TrayUnit.y / 2.3);
				_window.draw(ListUnit[i].sprite_TrayUnit_Dot);
			}
		}

		//////////////////////
		
		if (i == 1)		//второй юнит
		{
			ListUnit[i].sprite_TrayUnit.setPosition(center_SureStupe_TrayUnit.x - size_SureStupe_TrayUnit.x / 4.75, center_SureStupe_TrayUnit.y + size_SureStupe_TrayUnit.y / 2.35);
			_window.draw(ListUnit[i].sprite_TrayUnit);

			//определяем айди типа юнита и выводим портрет по айди
			if (ListUnit[i].UnitToUnit_ID == 0 && ListUnit[i].Life == true)//x 0.27 
			{
				if (ListUnit[i].IsSelectUnit == false)
				{
					ListUnit[i].sprite_TrayUnit_Head.setTextureRect(IntRect(134, 49, 13, 18));
					ListUnit[i].sprite_TrayUnit_Head.setPosition(center_SureStupe_TrayUnit.x - size_SureStupe_TrayUnit.x / 5.23, center_SureStupe_TrayUnit.y + size_SureStupe_TrayUnit.y / 2.27);
				}
				else
				{
					ListUnit[i].sprite_TrayUnit_Head.setTextureRect(IntRect(119, 49, 15, 19));
					ListUnit[i].sprite_TrayUnit_Head.setPosition(center_SureStupe_TrayUnit.x - size_SureStupe_TrayUnit.x / 5.18, center_SureStupe_TrayUnit.y + size_SureStupe_TrayUnit.y / 2.27);
				}

				_window.draw(ListUnit[i].sprite_TrayUnit_Head);
			}

			//рисуем черепок, если отряд убит
			if (ListUnit[i].Life == false)
			{
				ListUnit[i].sprite_TrayUnit_Head.setTextureRect(IntRect(147, 52, 11, 14));
				ListUnit[i].sprite_TrayUnit_Head.setPosition(center_SureStupe_TrayUnit.x - size_SureStupe_TrayUnit.x / 5.25, center_SureStupe_TrayUnit.y + size_SureStupe_TrayUnit.y / 2.24);
				_window.draw(ListUnit[i].sprite_TrayUnit_Head);
			}

			//отображение точки
			if (ListUnit[i].Couter_Step_Unit > 0 && ListUnit[i].Couter_Attack > 0 && ListUnit[i].Life == true)
			{
				ListUnit[i].sprite_TrayUnit_Dot.setTextureRect(IntRect(119, 68, 5, 4));
				ListUnit[i].sprite_TrayUnit_Dot.setPosition(center_SureStupe_TrayUnit.x - size_SureStupe_TrayUnit.x / 5.18, center_SureStupe_TrayUnit.y + size_SureStupe_TrayUnit.y / 2.3);
				_window.draw(ListUnit[i].sprite_TrayUnit_Dot);
			}

			if (ListUnit[i].Couter_Step_Unit == 0 && ListUnit[i].Couter_Attack > 0 && ListUnit[i].Life == true)
			{
				ListUnit[i].sprite_TrayUnit_Dot.setTextureRect(IntRect(124, 68, 5, 4));
				ListUnit[i].sprite_TrayUnit_Dot.setPosition(center_SureStupe_TrayUnit.x - size_SureStupe_TrayUnit.x / 5.18, center_SureStupe_TrayUnit.y + size_SureStupe_TrayUnit.y / 2.3);
				_window.draw(ListUnit[i].sprite_TrayUnit_Dot);
			}

			if (ListUnit[i].Couter_Step_Unit > 0 && ListUnit[i].Couter_Attack == 0 && ListUnit[i].Life == true)
			{
				ListUnit[i].sprite_TrayUnit_Dot.setTextureRect(IntRect(129, 68, 5, 4));
				ListUnit[i].sprite_TrayUnit_Dot.setPosition(center_SureStupe_TrayUnit.x - size_SureStupe_TrayUnit.x / 5.18, center_SureStupe_TrayUnit.y + size_SureStupe_TrayUnit.y / 2.3);
				_window.draw(ListUnit[i].sprite_TrayUnit_Dot);
			}

			if ((ListUnit[i].Couter_Step_Unit == 0 && ListUnit[i].Couter_Attack == 0 && ListUnit[i].Life == true) || ListUnit[i].Life == false)
			{
				ListUnit[i].sprite_TrayUnit_Dot.setTextureRect(IntRect(134, 68, 5, 4));
				ListUnit[i].sprite_TrayUnit_Dot.setPosition(center_SureStupe_TrayUnit.x - size_SureStupe_TrayUnit.x / 5.18, center_SureStupe_TrayUnit.y + size_SureStupe_TrayUnit.y / 2.3);
				_window.draw(ListUnit[i].sprite_TrayUnit_Dot);
			}
		}

		//////////////////////

		if (i == 2)		//третий юнит
		{
			ListUnit[i].sprite_TrayUnit.setPosition(center_SureStupe_TrayUnit.x - size_SureStupe_TrayUnit.x / 6.75, center_SureStupe_TrayUnit.y + size_SureStupe_TrayUnit.y / 2.35);
			_window.draw(ListUnit[i].sprite_TrayUnit);

			//определяем айди типа юнита и выводим портрет по айди
			if (ListUnit[i].UnitToUnit_ID == 0 && ListUnit[i].Life == true)
			{
				if (ListUnit[i].IsSelectUnit == false)
				{
					ListUnit[i].sprite_TrayUnit_Head.setTextureRect(IntRect(134, 49, 13, 18));
					ListUnit[i].sprite_TrayUnit_Head.setPosition(center_SureStupe_TrayUnit.x - size_SureStupe_TrayUnit.x / 7.73, center_SureStupe_TrayUnit.y + size_SureStupe_TrayUnit.y / 2.27);
				}
				else
				{
					ListUnit[i].sprite_TrayUnit_Head.setTextureRect(IntRect(119, 49, 15, 19));
					ListUnit[i].sprite_TrayUnit_Head.setPosition(center_SureStupe_TrayUnit.x - size_SureStupe_TrayUnit.x / 7.65, center_SureStupe_TrayUnit.y + size_SureStupe_TrayUnit.y / 2.27);
				}
				_window.draw(ListUnit[i].sprite_TrayUnit_Head);
			}

			//рисуем черепок, если отряд убит
			if (ListUnit[i].Life == false)
			{
				ListUnit[i].sprite_TrayUnit_Head.setTextureRect(IntRect(147, 52, 11, 14));
				ListUnit[i].sprite_TrayUnit_Head.setPosition(center_SureStupe_TrayUnit.x - size_SureStupe_TrayUnit.x / 7.79, center_SureStupe_TrayUnit.y + size_SureStupe_TrayUnit.y / 2.24);
				_window.draw(ListUnit[i].sprite_TrayUnit_Head);
			}

			//отображение точки
			if (ListUnit[i].Couter_Step_Unit > 0 && ListUnit[i].Couter_Attack > 0 && ListUnit[i].Life == true)
			{
				ListUnit[i].sprite_TrayUnit_Dot.setTextureRect(IntRect(119, 68, 5, 4));
				ListUnit[i].sprite_TrayUnit_Dot.setPosition(center_SureStupe_TrayUnit.x - size_SureStupe_TrayUnit.x / 7.65, center_SureStupe_TrayUnit.y + size_SureStupe_TrayUnit.y / 2.3);
				_window.draw(ListUnit[i].sprite_TrayUnit_Dot);
			}

			if (ListUnit[i].Couter_Step_Unit == 0 && ListUnit[i].Couter_Attack > 0 && ListUnit[i].Life == true)
			{
				ListUnit[i].sprite_TrayUnit_Dot.setTextureRect(IntRect(124, 68, 5, 4));
				ListUnit[i].sprite_TrayUnit_Dot.setPosition(center_SureStupe_TrayUnit.x - size_SureStupe_TrayUnit.x / 7.79, center_SureStupe_TrayUnit.y + size_SureStupe_TrayUnit.y / 2.3);
				_window.draw(ListUnit[i].sprite_TrayUnit_Dot);
			}

			if (ListUnit[i].Couter_Step_Unit > 0 && ListUnit[i].Couter_Attack == 0 && ListUnit[i].Life == true)
			{
				ListUnit[i].sprite_TrayUnit_Dot.setTextureRect(IntRect(129, 68, 5, 4));
				ListUnit[i].sprite_TrayUnit_Dot.setPosition(center_SureStupe_TrayUnit.x - size_SureStupe_TrayUnit.x / 7.79, center_SureStupe_TrayUnit.y + size_SureStupe_TrayUnit.y / 2.3);
				_window.draw(ListUnit[i].sprite_TrayUnit_Dot);
			}

			if ((ListUnit[i].Couter_Step_Unit == 0 && ListUnit[i].Couter_Attack == 0 && ListUnit[i].Life == true) || ListUnit[i].Life == false)
			{
				ListUnit[i].sprite_TrayUnit_Dot.setTextureRect(IntRect(134, 68, 5, 4));
				ListUnit[i].sprite_TrayUnit_Dot.setPosition(center_SureStupe_TrayUnit.x - size_SureStupe_TrayUnit.x / 7.79, center_SureStupe_TrayUnit.y + size_SureStupe_TrayUnit.y / 2.3);
				_window.draw(ListUnit[i].sprite_TrayUnit_Dot);
			}
			
		}
		
		//////////////////////

		if (i == 3)		//четвертый юнит
		{
			ListUnit[i].sprite_TrayUnit.setPosition(center_SureStupe_TrayUnit.x - size_SureStupe_TrayUnit.x / 11.95, center_SureStupe_TrayUnit.y + size_SureStupe_TrayUnit.y / 2.35);
			_window.draw(ListUnit[i].sprite_TrayUnit);

			//определяем айди типа юнита и выводим портрет по айди
			if (ListUnit[i].UnitToUnit_ID == 0 && ListUnit[i].Life == true)
			{
				if (ListUnit[i].IsSelectUnit == false)
				{
					ListUnit[i].sprite_TrayUnit_Head.setTextureRect(IntRect(134, 49, 13, 18));
					ListUnit[i].sprite_TrayUnit_Head.setPosition(center_SureStupe_TrayUnit.x - size_SureStupe_TrayUnit.x / 15.55, center_SureStupe_TrayUnit.y + size_SureStupe_TrayUnit.y / 2.27);
				}
				else
				{
					ListUnit[i].sprite_TrayUnit_Head.setTextureRect(IntRect(119, 49, 15, 19));
					ListUnit[i].sprite_TrayUnit_Head.setPosition(center_SureStupe_TrayUnit.x - size_SureStupe_TrayUnit.x / 15, center_SureStupe_TrayUnit.y + size_SureStupe_TrayUnit.y / 2.27);
				}
				_window.draw(ListUnit[i].sprite_TrayUnit_Head);
			}

			//рисуем черепок, если отряд убит
			if (ListUnit[i].Life == false)
			{
				ListUnit[i].sprite_TrayUnit_Head.setTextureRect(IntRect(147, 52, 11, 14));
				ListUnit[i].sprite_TrayUnit_Head.setPosition(center_SureStupe_TrayUnit.x - size_SureStupe_TrayUnit.x / 15.65, center_SureStupe_TrayUnit.y + size_SureStupe_TrayUnit.y / 2.24);
				_window.draw(ListUnit[i].sprite_TrayUnit_Head);
			}

			//отображение точки
			if (ListUnit[i].Couter_Step_Unit > 0 && ListUnit[i].Couter_Attack > 0 && ListUnit[i].Life == true)
			{
				ListUnit[i].sprite_TrayUnit_Dot.setTextureRect(IntRect(119, 68, 5, 4));
				ListUnit[i].sprite_TrayUnit_Dot.setPosition(center_SureStupe_TrayUnit.x - size_SureStupe_TrayUnit.x / 15, center_SureStupe_TrayUnit.y + size_SureStupe_TrayUnit.y / 2.3);
				_window.draw(ListUnit[i].sprite_TrayUnit_Dot);
			}

			if (ListUnit[i].Couter_Step_Unit == 0 && ListUnit[i].Couter_Attack > 0 && ListUnit[i].Life == true)
			{
				ListUnit[i].sprite_TrayUnit_Dot.setTextureRect(IntRect(124, 68, 5, 4));
				ListUnit[i].sprite_TrayUnit_Dot.setPosition(center_SureStupe_TrayUnit.x - size_SureStupe_TrayUnit.x / 15, center_SureStupe_TrayUnit.y + size_SureStupe_TrayUnit.y / 2.3);
				_window.draw(ListUnit[i].sprite_TrayUnit_Dot);
			}

			if (ListUnit[i].Couter_Step_Unit > 0 && ListUnit[i].Couter_Attack == 0 && ListUnit[i].Life == true)
			{
				ListUnit[i].sprite_TrayUnit_Dot.setTextureRect(IntRect(129, 68, 5, 4));
				ListUnit[i].sprite_TrayUnit_Dot.setPosition(center_SureStupe_TrayUnit.x - size_SureStupe_TrayUnit.x / 15, center_SureStupe_TrayUnit.y + size_SureStupe_TrayUnit.y / 2.3);
				_window.draw(ListUnit[i].sprite_TrayUnit_Dot);
			}

			if ((ListUnit[i].Couter_Step_Unit == 0 && ListUnit[i].Couter_Attack == 0 && ListUnit[i].Life == true) || ListUnit[i].Life == false)
			{
				ListUnit[i].sprite_TrayUnit_Dot.setTextureRect(IntRect(134, 68, 5, 4));
				ListUnit[i].sprite_TrayUnit_Dot.setPosition(center_SureStupe_TrayUnit.x - size_SureStupe_TrayUnit.x / 15, center_SureStupe_TrayUnit.y + size_SureStupe_TrayUnit.y / 2.3);
				_window.draw(ListUnit[i].sprite_TrayUnit_Dot);
			}
		}
		//////////////////////


	}


	//выводим окончание свитка
	if (ListUnit.size() == 1)
	{
		sprite_TrayUnit_end.setPosition(center_SureStupe_TrayUnit.x - size_SureStupe_TrayUnit.x / 4.75, center_SureStupe_TrayUnit.y + size_SureStupe_TrayUnit.y / 2.395);
		_window.draw(sprite_TrayUnit_end);
	}
	
	if (ListUnit.size() == 2)
	{
		sprite_TrayUnit_end.setPosition(center_SureStupe_TrayUnit.x - size_SureStupe_TrayUnit.x / 6.75, center_SureStupe_TrayUnit.y + size_SureStupe_TrayUnit.y / 2.395);
		_window.draw(sprite_TrayUnit_end);
	}

	if (ListUnit.size() == 3)
	{
		sprite_TrayUnit_end.setPosition(center_SureStupe_TrayUnit.x - size_SureStupe_TrayUnit.x / 11.95, center_SureStupe_TrayUnit.y + size_SureStupe_TrayUnit.y / 2.395);
		_window.draw(sprite_TrayUnit_end);
	}

	if (ListUnit.size() == 4)
	{
		sprite_TrayUnit_end.setPosition(center_SureStupe_TrayUnit.x - size_SureStupe_TrayUnit.x / 50, center_SureStupe_TrayUnit.y + size_SureStupe_TrayUnit.y / 2.395);
		_window.draw(sprite_TrayUnit_end);
	}
}