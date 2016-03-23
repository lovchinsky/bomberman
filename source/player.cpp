#include "player.h"

Player::Player(int i,int j,int di,int dj):DynamicObject(i,j,di,dj,id)
{
	alive = true;
}
Player::~Player()
{

}
void Player::setAlive(bool a)
{
	alive = a;
}
bool Player::getAlive()
{
	return alive;
}
void Player::draw(Visitor &v)
{
	v.visit(*this);
}