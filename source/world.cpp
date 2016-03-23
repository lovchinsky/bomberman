#include "world.h"

World::World()
{
	area = new Area();
	player = new Player();
	bomb = new Bomb();

	player->setMove(false);

	area->setCell(player);
	area->fillBlocks(blockcount);
	area->setBots(bots,botcount);
	area->setBomb(bomb);
}
World::~World()
{
	delete area;
	delete player;
}
int World::killsCount()
{
	int b = 0;
	for(int i=0; i<botcount; i++)
	{
		if(bots[i]==NULL)
		{
			b++;
		}
	}
	return b;
}
void World::update()
{
	int di = player->getDirection().i;
	int dj = player->getDirection().j;
	int pi = player->getPosition().i;
	int pj = player->getPosition().j;

	int power;

	if(player->getMove() && area->freeWay(player))
	{
		area->shiftCell(player,di,dj);
		player->setMove(false);
	}

	if(bomb->getActiv())
	{
		if(clock() - bomb->getTimeout() >= 1200)
		{
			bomb->setExplodeAnimation(1);

			power = bomb->getPower();

			pi = bomb->getPosition().i;
			pj = bomb->getPosition().j;

			for(int d = 0; d<4; d++)
			{
				di = ((d<2)? 1 : 0) * pow(-1,d);
				dj = ((d<2)? 0 : 1) * pow(-1,d);

				for(int j=0; j<power; j++)
				{
					if(area->getCell(pi+di*j,pj+dj*j)->getId() != 1)
					{
						if(area->getCell(pi+di*j,pj+dj*j)->getId() == 2)
						{
							player->setAlive(false);
						}
						else if(area->getCell(pi+di*j,pj+dj*j)->getId() == 4)
						{
							for(int i=0; i<botcount; i++)
							{
								if(bots[i] != NULL)
								{
									if(bots[i]->getPosition().i == pi+di*j && bots[i]->getPosition().j == pj+dj*j)
									{
										bots[i] = NULL;
									}
								}
							}
							area->setCell(new Empty(pi+di*j,pj+dj*j));
						}
						else
						{
							area->setCell(new Empty(pi+di*j,pj+dj*j));
						}
					}
					else
					{
						break;
					}
				}
			}
			bomb->setActiv(false);
		}
	}
	for(int i=0; i<botcount; i++)
	{
		if(bots[i] != NULL && bots[i]->getItem()!=NULL)
		{
			pi = bots[i]->getPosition().i;
			pj = bots[i]->getPosition().j;
			di = bots[i]->getDirection().i;
			dj = bots[i]->getDirection().j;

			if(area->freeWay(bots[i]))
			{
				if(bots[i]->getMove())
				{
					area->shiftCell(bots[i],di,dj);
					bots[i]->setMove(false);
				}
				if(bots[i]->getDirection().i != 0)
				{
					if(bots[i]->getPosition().i*32 - bots[i]->getItem()->pos().x()==-16*di)
					{
						bots[i]->setMove(true);
					}
				}
				else if(bots[i]->getDirection().j != 0)
				{
					if(bots[i]->getPosition().j*32 - bots[i]->getItem()->pos().y()==-16*dj)
					{
						bots[i]->setMove(true);
					}

				}
			}
			else if(area->getCell(pi+di,pj+dj)->getId() == 2)
			{
				if(abs(bots[i]->getItem()->pos().x() - player->getPosition().i*32) < 16 && abs(bots[i]->getItem()->pos().y() - player->getPosition().j*32) < 16)
				{
					player->setAlive(false);
				}
			}
			else
			{
				int free = 0;
				for(int j=0; j<4; j++)
				{
					di = ((j<2)? 1 : 0) * pow(-1,j);
					dj = ((j<2)? 0 : 1) * pow(-1,j);

					if(area->getCell(pi+di,pj+dj)->getId() == 0  && (bomb->getPosition().i != pi+di || bomb->getPosition().j != pj+dj))
					{
						free = 1;
						break;
					}
				}
				if(free)
				{
					do
					{
						int r = rand()%4;
						di = ((r<2)? 1 : 0) * pow(-1,r);
						dj = ((r<2)? 0 : 1) * pow(-1,r);
					}
					while(area->getCell(pi+di,pj+dj)->getId() != 0  && (bomb->getPosition().i != pi+di || bomb->getPosition().j != pj+dj));

					if(bots[i]->getDestination())
					{
						bots[i]->setDirection(di,dj);
					}

					if(bomb->getActiv() && (abs(bots[i]->getItem()->pos().x() - bomb->getPosition().i*32) < 32 && abs(bots[i]->getItem()->pos().y() - bomb->getPosition().j*32) < 32))
					{
						bots[i]->setDirection(bots[i]->getDirection().i*(-1),bots[i]->getDirection().j*(-1));
					}
				}
				else
				{
					bots[i]->setDirection(0,0);
				}
			}
		}
	}
}
void World::setBomb(Point p)
{
	if(!(bomb->getActiv()))
	{
		bomb->setPosition(p.i,p.j);
		bomb->setTimeout(clock());
		bomb->setActiv(true);
	}
}
Area* World::getArea()
{
	return area;
}
Player* World::getPlayer()
{
	return player;
}
