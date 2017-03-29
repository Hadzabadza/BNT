#pragma once
#include <string>
using namespace std;

//��������� ��������� ���������

const float defaultScale = 2.0;           //������ �� �������� �������� �� ���������

#ifdef RELEASE							  //����� ����, ��� �������� ������� ����� � ��������, 
const string projectPath = "../";         //���� ����� ��������� �� ���, ��� �� ���������, 
#else                                     //������� � ��������� ���� �� ������������ �����
const string projectPath = "";
#endif

const string imageFolder = "data/image/"; //���� � ����� � ����������

const string nameFileFolder = "data/";    //���� � ����� � ������� ��� ��� ������

const string mapsFolder = "data/maps/";   //���� � ����� � �������

const string fontsFolder = "data/";   //���� � ����� � ��������