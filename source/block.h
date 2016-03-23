#ifndef BLOCK_H
#define BLOCK_H

#include "staticobject.h"

class Block:public StaticObject
{
public:
	Block(int i,int j);
	~Block();

	void draw(Visitor &v);

private:
	static const int id = 3;
};

#endif