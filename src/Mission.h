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
	Vector2f center_Mission;		//��� ��������� �� ������ 
	Vector2f size_Mission;			//��� ��������� �� ������ 

	int WIDTH_MAP, HEIGHT_MAP;		//������ ����� �������� ����
	float id_tile;
	bool MovementPlayer;			//��� ������
	bool screen_lock;				//��� ���������� ������
	bool PressedSpace;				//��� ������� ������� �����
	float FrameSpace;					//�������� ����� ��� ������� space
	bool StepPlayerInspection;
	int CouterS;					//����� ���� ��� �� �����
	bool OnIUO3;					//��� ��������� ������ � �������� � �������� ����
	bool OnSureHalt;				//��� ��������� ��������������
	bool Fast_2;					//��� ���������� �������
	float CouterClick_Frame;		//�������� ����� ��� ������� ������ ����
	bool Teamp_CouterClick_Frame;	//��� ��������� ������ ������ ����
	bool No_fast;					//��������� � ��� ��� ����� �� ����� ���������� ���
	bool DownloadArt;				//��� ������ ��������
	float FrameDownload;			//��� �������� ������� ������ �������� �������
	bool Start;						//��� ������ �������� �������

	Sprite sprite_DownloadArt;//��� ��� ��������

	Sprite sprite_DownloadStrips;	//������� ��������

	Tile **Miss;
	Mission(int, int, RenderWindow&);
	~Mission();
};