#ifndef DYNAMIC_OBJECT_H
#define DYNAMIC_OBJECT_H

#include "point.h"
#include "staticobject.h"

class DynamicObject : public StaticObject
{
public:
	DynamicObject(int i,int j,int di,int dj,int id);
	~DynamicObject();

	Point getDirection();
	void setDirection(int i, int j);

	void setMove(bool m);
	bool getMove();
	bool getDestination();

private:
	Point direction;
	
	bool move;
};

#endif