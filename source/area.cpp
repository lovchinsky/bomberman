#include "area.h"

Area::Area()
{
	srand(time(NULL));

	board = new Board();

	for(int i=0; i<height; i++)
	{
		for(int j=0; j<width; j++)
		{
			area[i][j] = NULL;
		}
	}

	for(int i=0; i<height; i++)
	{
		for(int j=0; j<width; j++)
		{
			if(i==0 || i == height - 1)
			{
				setCell(new Wall(i,j));
			}
			else if(j == 0 || j == width - 1)
			{
				setCell(new Wall(i,j));
			}
			else if(i%2 == 0 && j%2 == 0)
			{
				setCell(new Wall(i,j));
			}
			else
			{
				setCell(new Empty(i,j));
			}
		}
	}
}
Area::~Area()
{

}
void Area::renderScreen(int t,int k)
{
	area[height][width+1]->draw(*render);
	board->setTime(t);
	board->setKills(k);
	board->draw(*render);

	for(int i=0; i<height; i++)
	{
		for(int j=0; j<width; j++)
		{
			area[i][j]->draw(*render);
        }
	}
}
bool Area::freeWay(DynamicObject * obj)
{
	if(getCell(obj->getPosition().i+obj->getDirection().i,obj->getPosition().j+obj->getDirection().j)->getId() == 0 && (area[height][width+1]->getPosition().i != obj->getPosition().i+obj->getDirection().i || area[height][width+1]->getPosition().j != obj->getPosition().j+obj->getDirection().j))
	{
		return true;
	}
	return false;
}
void Area::shiftCell(StaticObject* obj,int di, int dj)
{
	int i = obj->getPosition().i;
	int j = obj->getPosition().j;

	obj->setPosition(i+di,j+dj);
	area[i+di][j+dj]->setPosition(i,j);

	area[i][j] = area[i+di][j+dj];
	area[i+di][j+dj] = obj;
}
void Area::setCell(StaticObject* obj)
{
	if(area[obj->getPosition().i][obj->getPosition().j] != NULL)
	{
		delete area[obj->getPosition().i][obj->getPosition().j];
	}
	area[obj->getPosition().i][obj->getPosition().j] = obj;
}
StaticObject* Area::getCell(int i, int j)
{
	return area[i][j];
}
void Area::fillBlocks(int c)
{
	int n = 0;
	int pi;
	int pj;

	while(n != c)
	{
		pi = rand()%height;
		pj = rand()%width;
		while(area[pi][pj]->getId() == 0)
		{
			setCell(new Block(pi,pj));
			n++;
		}
	}
}
void Area::setBots(Bot* b[],int c)
{
	int n = 0;
	int pi;
	int pj;

	while(n != c)
	{
		pi = rand()%height;
		pj = rand()%width;
		while(area[pi][pj]->getId() == 0)
		{
			b[n] = new Bot(pi,pj);
			setCell(b[n]);
			n++;
		}
	}
}
void Area::setBomb(Bomb* b)
{
	area[height][width+1] = b;
}
void Area::setView(QGraphicsView &v)
{
	render = new GraphicsRender(v);
}