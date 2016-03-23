#include "bot.h"

Bot::Bot(int i,int j,int di,int dj):DynamicObject(i,j,di,dj,id)
{
	
}
Bot::~Bot()
{

}
void Bot::draw(Visitor &v)
{
	v.visit(*this);
}