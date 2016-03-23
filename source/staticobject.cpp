#include "staticobject.h"

StaticObject::StaticObject(int i,int j,int id):id(id)
{
	position.i = i;
	position.j = j;

	item = NULL;
}
StaticObject::~StaticObject()
{
	delete item;
}
int StaticObject::getId()
{
	return id;
}
Point StaticObject::getPosition()
{
	return position;
}
QGraphicsItem* StaticObject::getItem()
{
	return item;
}
void StaticObject::setItem(QPixmap p)
{
	item = new QGraphicsPixmapItem(p);
}
void StaticObject::setPosition(int i, int j)
{
	position.i = i;
	position.j = j;
}