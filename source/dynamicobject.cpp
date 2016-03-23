#include "dynamicobject.h"

DynamicObject::DynamicObject(int i,int j,int di,int dj,int id):StaticObject(i,j,id)
{
	direction.i = di;
	direction.j = dj;
}
DynamicObject::~DynamicObject()
{

}
Point DynamicObject::getDirection()
{
	return direction;
}
void DynamicObject::setDirection(int i, int j)
{
	direction.i = i;
	direction.j = j;
}
void DynamicObject::setMove(bool m)
{
	move = m;
}
bool DynamicObject::getMove()
{
	return move;
}
bool DynamicObject::getDestination()
{
	if(getItem() != NULL && getPosition().i*32 == getItem()->pos().x() && getPosition().j*32 == getItem()->pos().y())
	{
		return true;
	}
	return false;
}