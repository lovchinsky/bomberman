#ifndef AREA_H
#define AREA_H

#include <ctime>
#include <iostream>

#include "board.h"
#include "block.h"
#include "bomb.h"
#include "player.h"
#include "wall.h"
#include "empty.h"
#include "bot.h"
#include "graphicsrender.h"

const int width = 13;
const int height = 17;

class Area
{
public:
	Area();
	~Area();

	void renderScreen(int t,int k);
	void setCell(StaticObject* obj);
	bool freeWay(DynamicObject *obj);
	void shiftCell(StaticObject* obj,int di, int dj);
	StaticObject* getCell(int i, int j);
	void fillBlocks(int c);
	void setBots(Bot* b[],int c);
	void setBomb(Bomb* b);
	void setView(QGraphicsView &v);

private:
	StaticObject* area[height][width+1];
	Board* board;
    GraphicsRender* render;
};

#endif
