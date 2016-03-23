#include "empty.h"

Empty::Empty(int i,int j):StaticObject(i,j,id)
{

}
Empty::~Empty()
{

}
void Empty::draw(Visitor &v)
{
	v.visit(*this);
}