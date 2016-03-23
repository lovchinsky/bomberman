#include "board.h"

Board::Board(int i,int j):StaticObject(i,j,id)
{
	text = new QGraphicsTextItem();
	shade = new QGraphicsTextItem();
}
Board::~Board()
{

}
QString Board::getString()
{
	QString s;

	if(kills==-1)
	{
		s = "\t\tGAME OVER";
	}
	else
	{
		s = "TIME: ";
		s+=QString::number(time);
		s+= "\t\t\t KILLS: ";
		s+=QString::number(kills);
	}

	return s;
}
QGraphicsTextItem* Board::getText()
{
	return text;
}
QGraphicsTextItem* Board::getShade()
{
	return shade;
}
void Board::setTime(int t)
{
	time = t;
}
void Board::setKills(int k)
{
	kills = k;
}
void Board::draw(Visitor &v)
{
	v.visit(*this);
}