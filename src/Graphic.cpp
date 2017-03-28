#include "GlobalFunctionMissiom.h"

Graphic::Graphic(Sprite & _sheet, Vector2f _scale, Vector2f _carve, Vector2f _pos, Vector2f _dim):
	sheet(&_sheet), scale(_scale), carve(_carve), pos(_pos), dim(_dim){}

void Graphic::drawTo(RenderWindow & drawTo) {
	sheet->setTextureRect(IntRect(carve.x, carve.y, dim.x, dim.y));
	sheet->setPosition(pos.x * 128,pos.y * 128);
	sheet->setScale(scale.x, scale.y);
	drawTo.draw(*sheet);
};
void Graphic::drawTo(RenderWindow & drawTo,float time) {};

Animated::Animated(Graphic & g, unsigned _frames):frames(_frames),Graphic(*g.sheet,g.scale,g.carve,g.pos,g.dim){
	animated = true;
};

void Animated::drawTo(RenderWindow & drawTo, float time) {

	currentFrame +=anspeed * time;
	if (currentFrame > frames) currentFrame -= frames;
	sheet->setTextureRect(IntRect(carve.x*currentFrame, carve.y, dim.x, dim.y));
	sheet->setPosition(pos.x * 128, pos.y * 128);
	sheet->setScale(scale.x, scale.y);
	drawTo.draw(*sheet);
};
