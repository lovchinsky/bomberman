#include "block.h"

Block::Block(int i,int j):StaticObject(i,j,id)
{

}
Block::~Block()
{

}
void Block::draw(Visitor &v)
{
	v.visit(*this);
}