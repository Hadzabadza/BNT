#include "HelperFunctions.h"
#include "Graphic.h"

string extractWord(int & position, string input) {
	string tempLine = "";
	for (position; position < input.length(); position++) {
		if (input[position] == ',') { position++; break; }
		{ if (input[position] != ' ') tempLine += input[position]; }
	}
	return tempLine;
}

bool hovered(Graphic & g, float x, float y) {
	if (g.truePos->x < x &&
		g.truePos->x + g.dim.x * scale.x> x &&
		g.truePos->y < y &&
		g.truePos->y + g.dim.y * scale.y> y)
		return true;
	else return false;
}

bool hovered(Graphic & g, Vector2f & pos) {
	if (g.truePos->x< pos.x &&
		g.truePos->x + g.dim.x * scale.x> pos.x &&
		g.truePos->y< pos.y &&
		g.truePos->y + g.dim.y * scale.y> pos.y)
		return true;
	else return false;
}