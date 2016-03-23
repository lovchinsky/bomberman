#ifndef VISITOR_H
#define VISITOR_H

class Board;
class Block;
class Bomb;
class Player;
class Wall;
class Empty;
class Bot;

class  Visitor
{
public:
	virtual void visit(Board &obj) = 0;
	virtual void visit(Block &obj) = 0;
	virtual void visit(Bomb &obj) = 0;
	virtual void visit(Player &obj) = 0;
	virtual void visit(Wall &obj) = 0;
	virtual void visit(Empty &obj) = 0;
	virtual void visit(Bot &obj) = 0;
};

#endif