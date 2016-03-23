#ifndef BOARD_H
#define BOARD_H

#include "staticobject.h"

class Board:public StaticObject
{
public:
	Board(int i=0,int j=0);
	~Board();
	QString getString();
	QGraphicsTextItem *getText();
	QGraphicsTextItem *getShade();
	void setTime(int);
	void setKills(int);

	void draw(Visitor &v);

private:
	static const int id = 0;

	int time;
	int kills;

	QGraphicsItem *board;
	QGraphicsTextItem *text;
	QGraphicsTextItem *shade;
};

#endif