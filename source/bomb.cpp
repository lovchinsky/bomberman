#include "bomb.h"

Bomb::Bomb(int i,int j,int p):StaticObject(i,j,id)
{
	power = p;
	activ = false;
	explode = 0;
}
Bomb::~Bomb()
{

}
void Bomb::setTimeout(clock_t t)
{
	timeout = t;
}
void Bomb::setActiv(bool a)
{
	activ = a;
}
void Bomb::setExplodeAnimation(int i)
{
	explode = i;
}
int Bomb::getPower()
{
	return power;
}
clock_t Bomb::getTimeout()
{
	return timeout;
}
QGraphicsItem* Bomb::getItems(int i)
{
	return items[i];
}
void Bomb::setItems(int i,QPixmap p)
{
	items[i] = new QGraphicsPixmapItem(p);
}
int Bomb::getExplodeAnimation()
{
	return explode;
}
bool Bomb::getActiv()
{
	return activ;
}
void Bomb::draw(Visitor &v)
{
	v.visit(*this);
}