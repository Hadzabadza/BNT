#include "GlobalFunctionMissiom.h"

Graphic::Graphic(Vector2f & _pos, Sprite & _sheet, Vector2i _carve, Vector2i _dim):
	sheet(&_sheet), carve(_carve), pos(&_pos), dim(_dim){
}

void Graphic::drawTo(RenderWindow & drawTo) {
	sheet->setTextureRect(IntRect(carve.x, carve.y, dim.x, dim.y));
	sheet->setPosition(pos->x * dim.x * scale.x,pos->y * dim.y * scale.y);
	sheet->setScale(scale.x, scale.y);
	drawTo.draw(*sheet);
};

void Graphic::drawTo(RenderWindow & drawTo, float time) {};

//--------------------------------------------------------------

Animated::Animated(Graphic & g, unsigned _frames):frames(_frames),Graphic(g){
	animated = true;
};

void Animated::drawTo(RenderWindow & drawTo, float time) {
	currentFrame +=anSpeed * time;
	if (currentFrame >= frames) currentFrame -= frames; 
	sheet->setTextureRect(IntRect(dim.x*floor(currentFrame), carve.y, dim.x, dim.y));
	sheet->setPosition(pos->x * dim.x * scale.x, pos->y * dim.y * scale.y);
	sheet->setScale(scale.x, scale.y);
	drawTo.draw(*sheet);
};

//--------------------------------------------------------------

AnimExtended::AnimExtended(Graphic & g, Animator & _ar):Graphic(g),ar(&_ar) {
	animated = true;
	delete &g;
}

void AnimExtended::drawTo(RenderWindow & drawTo, float time) {
	currentFrame += anSpeed*time;
	ar->carveFrame(*sheet, currentFrame, dim);
	sheet->setPosition(pos->x * dim.x * scale.x, pos->y * dim.y * scale.y);
	sheet->setScale(scale.x, scale.y);
	drawTo.draw(*sheet);
}

//--------------------------------------------------------------

Animation::Animation(string _name, int _line, int _frames, string _cycleTo) :
	name(_name), line(_line), frames(_frames), cycleTo(_cycleTo) {};

//--------------------------------------------------------------

Animator::Animator() {};

Animator::Animator(string path) {
	string inLine;
	ifstream animFile;

	animFile.open(path+"Animator.txt");

	if (!animFile.is_open()) { cout << "Animator file failed to open.";}
	else
	{
		while (!animFile.eof())
		{
			getline(animFile, inLine);
			stringToAnim(inLine);
		}
		animFile.close();
	}
}

void Animator::carveFrame(Sprite & sheet, float & currentFrame, Vector2i & dim) {
	if (floor(currentFrame) >= anims[currentAnim]->frames)
	{
		currentFrame -= anims[currentAnim]->frames;
		setAnim(anims[currentAnim]->cycleTo);
	}
	sheet.setTextureRect(IntRect(dim.x*floor(currentFrame), dim.y*anims[currentAnim]->line, dim.x, dim.y));
}

bool Animator::setAnim(string anim) {
	currentAnim = 0;
	for (int i=0; i<anims.size(); i++) 
		if (anim == anims[i]->name) {
			currentAnim = i;
			return true;
		}
	return false;
}

void Animator::addAnim(string name, int line, int frames, string cycleTo) { anims.push_back(new Animation(name, line, frames, cycleTo)); }

void Animator::addAnim(Animation & anim) { anims.push_back(&anim); }

bool Animator::readFromFile(string path) {
	string inLine;
	ifstream animFile;

	animFile.open(path+"Animator.txt");

	if (!animFile.is_open()) { cout << "Animator file failed to open."; return false; }
	else
	{
		while (!animFile.eof())			
		{
			getline(animFile, inLine);
			stringToAnim(inLine);
		}
		animFile.close();
		return true;
	}
}

void Animator::stringToAnim(string data) {
	string name = "";
	int line = 0;
	int frames = 0;
	string cycleTo = "";
	int c = 0;
	for (c; c<data.length(); c++) {
		if (data[c] != ',') { if (data[c] != ' ') name += data[c]; }
		else { c++; break; }
	}
	string tempLine = "";
	for (c; c < data.length(); c++) {
		if (data[c] != ',') { if (data[c] != ' ') tempLine += data[c]; }
		else { c++; break; }
	}
	line = stoi(tempLine);

	string tempFrames = "";
	for (c; c < data.length(); c++) {
		if (data[c] != ',') { if (data[c] != ' ') tempFrames += data[c]; }
		else { c++; break; }
	}
	frames = stoi(tempFrames);

	for (c; c<data.length(); c++) {
		if (data[c] != ',') { if (data[c] != ' ') cycleTo += data[c]; }
		else { break; }
	}
	anims.push_back(new Animation(name, line, frames, cycleTo));
}