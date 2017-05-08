#include "GlobalFunctionMissiom.h"

Graphic::Graphic() {};

Graphic::Graphic(Vector2f & _pos, Sprite & _sheet, Vector2i _carve, Vector2i _dim):
	sheet(&_sheet), carve(_carve), pos(&_pos), dim(_dim){
	truePos = new Vector2f(0, 0);
}

void Graphic::updateTruePosition() {
	truePos->x = pos->x * dim.x * scale.x;
	truePos->y = pos->y * dim.y * scale.y;
	sheet->setPosition(*truePos);
}

void Graphic::drawTo(RenderWindow & drawTo) {
	updateTruePosition();
	sheet->setTextureRect(IntRect(carve.x, carve.y, dim.x, dim.y));
	sheet->setScale(scale.x, scale.y);
	drawTo.draw(*sheet);
};

bool Graphic::hovered() {
	if (truePos->x < mouse.x &&
		truePos->x + dim.x * scale.x> mouse.x &&
		truePos->y <mouse.y &&
		truePos->y + dim.y * scale.y> mouse.y)
		return true;
	else return false;
}

//--------------------------------------------------------------

Animated::Animated(Graphic & g, unsigned _frames):frames(_frames),Graphic(g){
	animated = true;
	truePos = new Vector2f(0, 0);
	anSpeed = 0.004;
};

void Animated::drawTo(RenderWindow & drawTo) {
	updateTruePosition();
	currentFrame += anSpeed * elapsed;
	if (currentFrame >= frames) currentFrame -= frames; 
	sheet->setTextureRect(IntRect(dim.x*floor(currentFrame), carve.y, dim.x, dim.y));
	sheet->setScale(scale.x, scale.y);
	drawTo.draw(*sheet);
};

//--------------------------------------------------------------

AnimExtended::AnimExtended(Graphic & g, Animator & _ar):Graphic(g) {
	ar = &_ar;
	ar->pt = this;
	animated = true;
	truePos = new Vector2f(0, 0);
	anSpeed = 0.004;
	delete &g;
}

void AnimExtended::drawTo(RenderWindow & drawTo) {
	updateTruePosition();
	currentFrame += anSpeed*elapsed;
	ar->carveFrame(*sheet,  dim);
	sheet->setScale(scale.x, scale.y);
	drawTo.draw(*sheet);
}

//--------------------------------------------------------------

Animation::Animation(string n, int l, int f, int p, string cT) :
	name(n), line(l), frames(f), peak(p), cycleTo(cT) {};

//--------------------------------------------------------------

Variant::Variant(string n, int m) :
	name(n), modifier(m) {};

//--------------------------------------------------------------

Animator::Animator() {};

Animator::Animator(string path) { readFromFile(path); }

void Animator::carveFrame(Sprite & sheet, Vector2i & dim) {
	if (floor(pt->currentFrame) >= anims[currentAnim]->frames)
	{
		pt->currentFrame -= anims[currentAnim]->frames;
		setAnim(anims[currentAnim]->cycleTo);
	}
	int variantShift = 0;
	for (Variant * v : anims[currentAnim]->vars)
		if (v->active) variantShift += v->modifier;
	sheet.setTextureRect(IntRect(dim.x*floor(pt->currentFrame), dim.y*(anims[currentAnim]->line+variantShift), dim.x, dim.y));
}

Animation & Animator::addAnim(string name, int line, int frames, int peak, string cycleTo) {
	Animation * a = new Animation(name, line, frames, peak, cycleTo);
	anims.push_back(a);
	return *a;
}

void Animator::addAnim(Animation & a) { anims.push_back(&a); }


Variant & Animator::addVariant(string name, int modifier) {
	Variant * v = new Variant(name, modifier);
	vars.push_back(v);
	return *v;
}

void Animator::addVariant(Variant & v) { vars.push_back(&v); }

bool Animator::setAnim(string anim) {
	currentAnim = 0;
	pt->currentFrame = 0;
	for (int i=0; i<anims.size(); i++) 
		if (anim == anims[i]->name) { currentAnim = i; return true;}
	return false;
}

string Animator::getCurrentAnim() { return anims[currentAnim]->name; }

bool Animator::isPastPeak() { return anims[currentAnim]->peak <= pt->currentFrame; }

bool Animator::setVariant(string name, bool state) {
	for (Variant * v:vars) if (name == v->name) { v->active = state; return true; }
	return false;
}

bool Animator::getVariantState(string name) {
	for (Variant * v : vars) if (name == v->name) { return v->active; }
	return false;
}

//--------Достаём данные из файла-------------------------------

bool Animator::readFromFile(string path) {
	string inLine;     //Читаемая строка
	ifstream animFile; //Файл с данными аниматора
	bool vars = false; //Показывает считывать ли строку как анимацию или вариант

	animFile.open(path + "Animator.txt");

	if (!animFile.is_open()) { cout << "Animator file failed to open."; return false; }
	else
	{
		while (!animFile.eof())
		{
			getline(animFile, inLine);
			if (inLine != "" && inLine.length()>2 && inLine[0] != '/' && inLine[1]!='/') {
				if (!vars) { if (inLine == "VARIANTS:") { vars = true; } else { stringToAnim(inLine); } }
				else { stringToVariant(inLine); }
			}
		}
		animFile.close();
		return true;
	}
}

void Animator::stringToAnim(string data) {
	string name = "";
	int line = 0;
	int frames = 0;
	int peak = 0;
	string cycleTo = "";
	int c = 0;
	name = extractWord(c, data);
	line = stoi(extractWord(c,data));
	frames = stoi(extractWord(c, data));
	peak = stoi(extractWord(c, data));
	cycleTo = extractWord(c, data);

	addAnim(name, line, frames, peak, cycleTo);
}

void Animator::stringToVariant(string data) {
	string name = "";
	int modifier = 0;
	int c = 0;
	name = extractWord(c, data);
	modifier = stoi(extractWord(c,data));

	Variant * addToAnims= &addVariant(name, modifier);

	while (c < data.length()) {
		string currentApplication = extractWord(c,data); //Анимации, которые имеют рассматриваемый вариант
		if (currentApplication == "all") { for (Animation * a : anims) { a->vars.push_back(addToAnims); } }
		else {for (Animation * a : anims) if (a->name==currentApplication) a->vars.push_back(addToAnims);}
	}
}