#pragma once
#include <string>
#include "SFML\Graphics.hpp"

using namespace std;
using namespace sf;

//��������� ��������� ���������

const Vector2f scale = Vector2f(2.,2.);   //������ �� �������� �������� �� ���������

#ifdef RELEASE							  //����� ����, ��� �������� ������� ����� � ��������, 
const string projectPath = "../";         //���� ����� ��������� �� ���, ��� �� ���������, 
#else                                     //������� � ��������� ���� �� ������������ �����,
const string projectPath = "";		      //� ������� ������ ����� ���������� ����
#endif

const string imageFolder = "data/image/"; //���� � ����� � ����������

const string nameFileFolder = "data/";    //���� � ����� � ������� ��� ��� ������

const string mapsFolder = "data/maps/";   //���� � ����� � �������

const string fontsFolder = "data/";       //���� � ����� � ��������

const string unitsFolder = "data/units/";   //���� � ����� � ������� ������