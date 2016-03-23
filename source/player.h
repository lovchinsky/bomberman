#ifndef PLAYER_H
#define PLAYER_H

#include "dynamicobject.h"

class Player:public DynamicObject
{
public:
	Player(int i=1,int j=1,int di=0,int dj=0);
	~Player();

	void setAlive(bool a);
	bool getAlive();

	void draw(Visitor &v);

private:
	static const int id = 2;

	bool alive;
};

#endif