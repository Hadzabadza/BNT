#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include "GlobalFunctionMissiom.h"

using namespace std;
using namespace sf;

Player::Player()
{
	orders = 5;
	ConstOrders = 5;
}

float Player::GetConstOrders()
{
	return ConstOrders;
}

void Player::SetConstOrders(float _ConstOrders)
{
	ConstOrders = _ConstOrders;
}