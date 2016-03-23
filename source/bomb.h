#ifndef BOMB_H
#define BOMB_H

#include <ctime>
#include "staticobject.h"

class Bomb:public StaticObject
{
public:
	Bomb(int i=0,int j=0,int p=2);
	~Bomb();

	void setTimeout(clock_t t);
	void setActiv(bool a);
	void setExplodeAnimation(int i);

	int getPower();
	clock_t getTimeout();
	bool getActiv();

	void setItems(int i,QPixmap p);
	QGraphicsItem *getItems(int i);
	int getExplodeAnimation();

	void draw(Visitor &v);

private:
	static const int id = 0;

	int power;
	clock_t timeout;
	bool activ;

	int explode;
	QGraphicsItem *items[4];
};

#endif