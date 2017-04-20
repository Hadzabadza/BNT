#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>
#include <vector>

class Animator;
class Variant;

class Graphic { //��������� �� ������������ � ��� �������
public:
	Sprite * sheet;
	Vector2i carve;         //������� �� �����������
	Vector2f * pos;         //��������� ������� ������� �� �����
	Vector2f * truePos;     //��������� ������� ������� �� ������
	Vector2i dim;           //���������� �������
	bool animated = false;  //������ �������� ��� ������� ��������
	float currentFrame = 0; //������� ���� ��������. ����������� � ������������� ��������� �������
	float anSpeed = 0;      //�������� �������� ��� ������������� ���������
	Animator * ar;          //�������� ��� ��������������� ��������

	Graphic();
	Graphic(Vector2f & _pos, Sprite & _sheet, Vector2i _carve, Vector2i _dim);
	void updateTruePosition();                              //��������� �������� ������� � ������� �� ������
	virtual void drawTo(RenderWindow & drawTo);				//���������� ������
	virtual void drawTo(RenderWindow & drawTo, float time); //�������� ��� ������������� ��������
};

class Animated :public Graphic {//������������� ���������� � ������������ ����������
public:
	unsigned frames;		//���������� ������ � ��������

	Animated(Graphic & g, unsigned _frames);
	virtual void drawTo(RenderWindow & drawTo, float time); //���������� ������������� ������
};

class AnimExtended :public Graphic {//���������� ������������ ���������� � ��������������� ��������
public:
	AnimExtended(Graphic & g, Animator & _ar);
	virtual void drawTo(RenderWindow & drawTo, float time); //���������� ������������� ������
};


class Animation {//����� ������ ��� ���������
public:
	string name;			 //�������� ��������
	unsigned line;			 //������� ����� �� ����������� �������� ��������
	unsigned frames;         //������� ������� � ��������
	unsigned peak;           //�����, ����� �������� ���� ������������� ��� ��������
	string cycleTo;          //�� ����� �������� �������� �� ��������� ��������
	vector <Variant *> vars; //���������� ��������

	Animation(string name, int line, int frames, int peak, string cycleTo);
};

class Variant {//����� ������ ��� ���������
public:
	string name;         //�������� ��������
	bool active = false; //������� �� �������
	int modifier;        //�� ������� ����� ������������, ���� ������� �������

	Variant(string name, int modifier);
};

class Animator {//������������ ��������� ����������� ��������
private:	
	vector <Animation *> anims;
	vector <Variant *> vars;

public:
	unsigned currentAnim = 0;
	AnimExtended * pt; //Parent; ������������ ����� ��������

	Animator();
	Animator(string path);
	void carveFrame(Sprite & sheet, Vector2i & dim); //���������� �� ����������� ���� � ����������� �� ��� ������ � �������
	
	Animation & addAnim(string name, int line, int frames, int peak, string cycleTo); //
	void addAnim(Animation & anim);                                                   //��������� ����� ��������

	Variant & addVariant(string name, int modifier); //
	void addVariant(Variant & var);					 //��������� ����� �������

	bool setAnim(string anim);                       //����������� ������ �������� �� �����, ���� �������� �� �������, ���������� ����
	string getCurrentAnim();						 //���������� �������� ������������� ��������
	bool isPastPeak();								 //���������� ������ �� �������� ������� �����
	
	bool setVariant(string variant, bool state);     //��������/��������� �������, ���������� ����, ���� �� ������ ������� � �������� ������
	bool getVariantState(string variant);			 //���������� ��������� ���������� ��������
	
	bool readFromFile(string path);                  //��������� ��������� �� �����
	void stringToAnim(string data);                  //
	void stringToVariant(string data);               //���������, ����������� ������ � ���������. TODO: ����� ��������, ������� ����������� �������� ������ � �������� ������������� ����������
};