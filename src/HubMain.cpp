#include <ctime>
#include "GlobalFunctionMissiom.h"

#ifdef RELEASE
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup") //��������� ��������� � ������
#endif

using namespace std;
using namespace sf;

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

	Unit first(448, 576, 64, 64, 4, 3, 0, 0, "a", 0, "defender");
	first.animation->ar->setVariant("wounded",true);
	Unit second(576, 576, 64, 64, 4, 4, 1, 0, "a", 0, "defender");
	Unit treti(320, 576, 64, 64, 4, 2, 2, 0, "a", 0, "defender");
	//Unit chetverti(704, 576, 64, 64, 4, 5, 3, 0, "a", 0, "defender");

	Unit enemy(448, 320, 64, 64, 2, 3, 3, 1, "a", 0, "defender");
	Unit enemy_1(448, 192, 64, 64, 1, 3, 4, 1, "a", 0, "defender");

	View view;	//������
	view.reset(sf::FloatRect(0, 0, 1024, 768));
	Mission _Missiom(HEIGHT_MAP_2, WIDTH_MAP_2, window);	//����� ������
	Clock clock;	//����� �����


	MainCharacter.ArmyGamer.push_back(first);
	//MainCharacter.ArmyGamer.push_back(second);
	//MainCharacter.ArmyGamer.push_back(treti);
	//MainCharacter.ArmyGamer.push_back(chetverti);
	hostile.ArmyEnemy_1.push_back(enemy);
	//hostile.ArmyEnemy_1.push_back(enemy_1);

	while (window.isOpen())
	{
		Vector2i pixelPos = Mouse::getPosition(window);
		Vector2f pos = window.mapPixelToCoords(pixelPos);	//���������� ����

		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;

		//cout << pixelPos.x << " " << pixelPos.y << endl;
		

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			IsSelectMouseMissiomStatic(event, pos, MainCharacter, hostile, _Missiom, time, in);	//������� ������� ����������� ��� ������� ������ ������
			IsSelectMouseMissiomInterace(in, event, window, _Missiom, MainCharacter, time);	//������ ���� � �����������
		}
		
		IsSelectMouseMissiomStaticNON(event, pos, MainCharacter, hostile, _Missiom);	//������ ���� � �����������

		UpdateUnitArmy(MainCharacter, hostile, _Missiom, time);	//������� ������� ����� �� �����, �������� � ��������
		UpdateInterface(in, MainCharacter, hostile, _Missiom, event, pos, time);			//������� ������� ����������
		UpdateMissiom(_Missiom, MainCharacter, time);					//��� ����������� ������� �� ������ ��� ����������� ������, �� ������� ����� � ��

		TileIsEmpty(_Missiom, MainCharacter, hostile);	//��������  �� ��������� �����

		ViewScroling(view, pixelPos, time, window, _Missiom);	//������ ������

		window.setView(view);	//�������� ������
		window.clear();

		
		FunctionPrintToMission_2(_Missiom, time, in);	//������� ������
		
		DrawToSpriteMission(window, time, _Missiom);	//������ ������� ������
		DrawSpriteUnit(MainCharacter, hostile, window, time);	//������ ������� ������
		DrawSpriteCursor(window, time, _Missiom);	//������ ������� ��������
		DrawInterfaceMission(in, window, _Missiom);	//������ ��������� ������
		window.display();
	}

	_Missiom.~Mission();
}