#ifndef WALL_H
#define WALL_H

#include "staticobject.h"

class Wall:public StaticObject
{
public:
	Wall(int i,int j);
	~Wall();

	void draw(Visitor &v);

private:
	static const int id = 1;
};

#endif