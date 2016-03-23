#ifndef WORLD_H
#define WORLD_H

#include "area.h"
#include "block.h"
#include "bomb.h"
#include "player.h"
#include "wall.h"
#include "empty.h"
#include "bot.h"

const int blockcount = 25;
const int botcount = 2;

class World
{
public:
	World();
	~World();

	void update();
	void setBomb(Point);
	bool freeDirection();

	Area* getArea();
	Player* getPlayer();
	int killsCount();

private:
	Area* area;
	Player* player;
	Bot* bots[botcount];
	Bomb* bomb;
};

#endif