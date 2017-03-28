#pragma once
#include <vector>
#include <string>
#include "SFML\Graphics.hpp"

using namespace std;
using namespace sf;

class Tileset {
	string name;
	vector<TileDefinition*> tiles;
};

class TileDefinition {
	string spritePath;
	Vector2i carve;
	Vector2i dim;
	unsigned frames;
};