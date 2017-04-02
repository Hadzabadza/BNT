#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>
#include <vector>

class Animator;

class Graphic { //��������� �� ������������ � ��� �������
public:
	Sprite * sheet;
	//Vector2f scale;        //������ ����������
	Vector2i carve;        //������� �� �����������
	Vector2f * pos;        //������� �� ������, ��������� �� ������� �������
	Vector2i dim;          //���������� �������
	bool animated = false; //������ �������� ��� ������� ��������
	Animator * ar;         //�������� ��� ��������������� ��������

	Graphic(Vector2f & _pos, Sprite & _sheet, Vector2i _carve, Vector2i _dim);
	virtual void drawTo(RenderWindow & drawTo);				//���������� ������
	virtual void drawTo(RenderWindow & drawTo, float time); //�������� ��� ������������� ��������
};

class Animated :public Graphic {//������������� ���������� � ������������ ����������
public:
	unsigned frames;		//���������� ������ � ��������
	float currentFrame = 0; //������� ���� ��������
	float anSpeed = 0.004;  //�������� ��������

	Animated(Graphic & g, unsigned _frames);
	virtual void drawTo(RenderWindow & drawTo, float time); //���������� ������������� ������
};

class AnimExtended :public Graphic {//���������� ������������ ���������� � ��������������� ��������
public:
	float currentFrame = 0; //������� ���� ��������
	float anSpeed = 0.004;  //�������� ��������
	Animator * ar;          //��������� �������� ��������

	AnimExtended(Graphic & g, Animator & _ar);
	virtual void drawTo(RenderWindow & drawTo, float time); //���������� ������������� ������
};


class Animation {//����� ������ ��� ���������
public:
	string name;      //�������� ��������
	unsigned line;    //������� ����� �� ����������� �������� ��������
	unsigned frames;  //������� ������� � ��������
	string cycleTo;   //�� ����� �������� �������� �� ��������� ��������

	Animation(string name, int line, int frames, string cycleTo);
};

class Animator {//������������ ��������� ����������� ��������
private:	
	vector <Animation *> anims;
public:
	unsigned currentAnim = 0;

	Animator();
	Animator(string path);
	void carveFrame(Sprite & sheet, float & currentFrame, Vector2i & dim);//���������� �� ����������� ���� � ����������� �� ��� ������ � �������
	bool setAnim(string anim);                                            //����������� ������ �������� �� �����
	void addAnim(string name, int line, int frames, string cycleTo);      //
	void addAnim(Animation & anim);                                       //��������� ����� ��������
	bool readFromFile(string path);                                       //��������� ��������� �� �����
	void stringToAnim(string data);                                       //��������, ����������� ������ � ���������. TODO: ����� ��������, ������� ����������� �������� ������ � �������� ������������� ����������
};