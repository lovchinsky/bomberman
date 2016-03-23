#ifndef STATIC_OBJECT_H
#define STATIC_OBJECT_H

#include <QGraphicsItem>

#include "point.h"
#include "visitor.h"

class StaticObject
{
	const int id;
public:
	StaticObject(int i,int j, int id);
	~StaticObject();

	int getId();
	Point getPosition();
	QGraphicsItem *getItem();
	void setItem(QPixmap p);
	void setPosition(int i, int j);

	virtual void draw(Visitor &v) = 0;

private:
	Point position;
	QGraphicsItem *item;
};

#endif