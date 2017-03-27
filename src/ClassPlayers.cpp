#include "GlobalFunctionMissiom.h"

using namespace std;
using namespace sf;

Player::Player(unsigned max) :maxOrders(max), orders(maxOrders) {}

unsigned Player::GetMaxOrders() { return maxOrders; }

void Player::SetMaxOrders(unsigned max) { maxOrders = max; }