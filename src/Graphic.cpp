#include "GlobalFunctionMissiom.h"

Graphic::Graphic(Vector2f & _pos, Sprite & _sheet, Vector2i _carve, Vector2i _dim, Vector2f _scale):
	sheet(&_sheet), scale(_scale), carve(_carve), pos(&_pos), dim(_dim){
}

void Graphic::drawTo(RenderWindow & drawTo) {
	sheet->setTextureRect(IntRect(carve.x, carve.y, dim.x, dim.y));
	sheet->setPosition(pos->x * dim.x * scale.x,pos->y * dim.y * scale.y);
	sheet->setScale(scale.x, scale.y);
	drawTo.draw(*sheet);
};
void Graphic::drawTo(RenderWindow & drawTo, float time) {};

//--------------------------------------------------------------

Animated::Animated(Graphic & g, unsigned _frames):frames(_frames),Graphic(*g.pos,*g.sheet,g.carve,g.dim,g.scale){
	animated = true;
};

void Animated::drawTo(RenderWindow & drawTo, float time) {
	currentFrame +=anSpeed * time;
	if (currentFrame > frames) currentFrame -= frames; 
	sheet->setTextureRect(IntRect(dim.x*floor(currentFrame), carve.y, dim.x, dim.y));
	sheet->setPosition(pos->x * dim.x * scale.x, pos->y * dim.y * scale.y);
	sheet->setScale(scale.x, scale.y);
	drawTo.draw(*sheet);
};

