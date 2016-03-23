#ifndef BOT_H
#define BOT_H

#include "dynamicobject.h"

class Bot:public DynamicObject
{
public:
	Bot(int i,int j,int di=0,int dj=0);
	~Bot();

	void draw(Visitor &v);

private:
	static const int id = 4;
};

#endif