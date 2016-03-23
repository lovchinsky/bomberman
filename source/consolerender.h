#ifndef CONSOLE_RENDER_H
#define CONSOLE_RENDER_H

#include "visitor.h"

#include <iostream>

class ConsoleRender:public Visitor
{
public:
	void visit(Block &obj){std::cout<<3;}
	void visit(Bomb &obj){}
	void visit(Player &obj){std::cout<<2;}
	void visit(Wall &obj){std::cout<<1;}
	void visit(Empty &obj){std::cout<<0;}
	void visit(Bot &obj){std::cout<<4;}
};

#endif