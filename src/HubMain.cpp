#include <ctime>
#include "GlobalFunctionMissiom.h"

#ifdef RELEASE
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup") //��������� ��������� � ������
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

	srand(time(NULL));	//��� ��������� ���������
	setlocale(LC_ALL, "Russian");
	sf::RenderWindow window(_videoMode, "Blood and Tears", Style::Titlebar | Style::Close);
	AllInterfaceMissiom in;	//���� ���������
	Player MainCharacter;	//����� ������
	Enemy_1 hostile;		//����� ����������

	View view;	//������
	view.reset(sf::FloatRect(0, 0, 1024, 768));
	tnd=new Mission(HEIGHT_MAP_2, WIDTH_MAP_2, window);	//����� ������
	Clock clock;	//����� �����


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
		mouse = window.mapPixelToCoords(pixelPos);	//���������� ����

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
			IsSelectMouseMissiomStatic(event, MainCharacter, hostile, in);	//������� ������� ����������� ��� ������� ������ ������
			IsSelectMouseMissiomInterace(in, event, window, MainCharacter);	//������ ���� � �����������
		}
		
		IsSelectMouseMissiomStaticNON(event, MainCharacter, hostile);	//������ ���� � �����������

		UpdateUnitArmy(MainCharacter, hostile);	//������� ������� ����� �� �����, �������� � ��������
		UpdateInterface(in, MainCharacter, hostile, event);			//������� ������� ����������
		UpdateMissiom(MainCharacter);					//��� ����������� ������� �� ������ ��� ����������� ������, �� ������� ����� � ��

		//TileIsEmpty(_Missiom, MainCharacter, hostile);	//��������  �� ��������� �����

		ViewScroling(view, pixelPos, window);	//������ ������

		window.setView(view);	//�������� ������
		window.clear();

		
		FunctionPrintToMission_2(in);	//������� ������
		
		DrawToSpriteMission(window);	//������ ������� ������
		DrawSpriteUnit(MainCharacter, hostile, window);	//������ ������� ������
		DrawSpriteCursor(window);	//������ ������� ��������
		DrawInterfaceMission(in, window);	//������ ��������� ������
		window.display();
	}

	delete tnd;
}