#ifndef EMPTY_H
#define EMPTY_H

#include "staticobject.h"

class Empty:public StaticObject
{
public:
	Empty(int i,int j);
	~Empty();

	void draw(Visitor &v);

private:
	static const int id = 0;
};

#endif