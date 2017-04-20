#pragma once
#include "SFML/Graphics.hpp"
#include <string>
#include "Settings.h"

using namespace std;
using namespace sf;

class Graphic;

string extractWord(int & position, string input);
bool hovered(Graphic & g, float x, float y);
bool hovered(Graphic & g, Vector2f & pos);