#include "wall.h"

Wall::Wall(int i,int j):StaticObject(i,j,id)
{

}
Wall::~Wall()
{

}
void Wall::draw(Visitor &v)
{
	v.visit(*this);
}