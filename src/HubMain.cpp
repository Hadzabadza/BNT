#include <ctime>
#include "GlobalFunctionMissiom.h"

#ifdef RELEASE
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup") //Выключает консольку в релизе
#endif

using namespace std;
using namespace sf;

Vector2f mouse = Vector2f(0, 0);
Mission * tnd;
float elapsed = 0;

const int w = 1024;
const int h = 740;

int main()
{
	VideoMode _videoMode;
	_videoMode.width = w;
	_videoMode.height = h;

	srand(time(NULL));	//для рандомной генерации
	setlocale(LC_ALL, "Russian");
	sf::RenderWindow window(_videoMode, "Blood and Tears", Style::Titlebar | Style::Close);
	AllInterfaceMissiom in;	//весь интерфейс
	Player MainCharacter;	//класс игрока
	Enemy_1 hostile;		//класс противника

	View view;	//камера
	view.reset(sf::FloatRect(0, 0, 1024, 768));
	tnd=new Mission(HEIGHT_MAP_2, WIDTH_MAP_2, window);	//класс миссии
	Clock clock;	//класс время


	Unit first(448, 576, 64, 64, 4, 3, 0, 0, "a", 0, "defender");
	first.animation->ar->setVariant("wounded", true);
	Unit second(576, 576, 64, 64, 4, 4, 1, 0, "a", 0, "defender");
	Unit treti(320, 576, 64, 64, 4, 2, 2, 0, "a", 0, "defender");
	//Unit chetverti(704, 576, 64, 64, 4, 5, 3, 0, "a", 0, "defender");

	Unit enemy(448, 320, 64, 64, 2, 3, 3, 1, "a", 0, "defender");
	Unit enemy_1(448, 192, 64, 64, 1, 3, 4, 1, "a", 0, "defender");

	MainCharacter.ArmyGamer.push_back(first);
	MainCharacter.ArmyGamer.push_back(second);
	MainCharacter.ArmyGamer.push_back(treti);
	//MainCharacter.ArmyGamer.push_back(chetverti);
	hostile.ArmyEnemy_1.push_back(enemy);
	hostile.ArmyEnemy_1.push_back(enemy_1);

	while (window.isOpen())
	{
		Vector2i pixelPos = Mouse::getPosition(window);
		mouse = window.mapPixelToCoords(pixelPos);	//координаты мыши

		//float time = clock.getElapsedTime().asMicroseconds();
		elapsed = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		elapsed /= 800;

		//cout << pixelPos.x << " " << pixelPos.y << endl;
		

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			IsSelectMouseMissiomStatic(event, MainCharacter, hostile, in);	//большая функция выполняется при условии эвента мышкой
			IsSelectMouseMissiomInterace(in, event, window, MainCharacter);	//эвенты мыши с интерфейсом
		}
		
		IsSelectMouseMissiomStaticNON(event, MainCharacter, hostile);	//эвенты мыши с интерфейсом

		UpdateUnitArmy(MainCharacter, hostile);	//функция апдейта юнита на карте, движения и анимация
		UpdateInterface(in, MainCharacter, hostile, event);			//функция апдейта интерфейса
		UpdateMissiom(MainCharacter);					//тут проверяются условие на задачи для прохождения миссии, на пропуск ходов и тд

		//TileIsEmpty(_Missiom, MainCharacter, hostile);	//проверка  на занятость тайла

		ViewScroling(view, pixelPos, window);	//курсор камеры

		window.setView(view);	//оживляем камеру
		window.clear();

		
		FunctionPrintToMission_2(in);	//создаем миссию
		
		DrawToSpriteMission(window);	//рисуем спрайты миссии
		DrawSpriteUnit(MainCharacter, hostile, window);	//рискем спрайты юнитов
		DrawSpriteCursor(window);	//рисуем спрайты курсоров
		DrawInterfaceMission(in, window);	//рисуем интерфейс миссии
		window.display();
	}

	delete tnd;
}