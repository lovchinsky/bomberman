#ifndef GRAPHICS_RENDER_H
#define GRAPHICS_RENDER_H

#include <QGraphicsScene.h>
#include <QGraphicsView.>

#include "board.h"
#include "block.h"
#include "bomb.h"
#include "player.h"
#include "wall.h"
#include "empty.h"
#include "bot.h"
#include "visitor.h"
#include <qfont.h>

class GraphicsRender:public Visitor
{
public:
	GraphicsRender(QGraphicsView &v);
	void visit(Board &obj);
	void visit(Block &obj);
    void visit(Bomb &obj);
    void visit(Player &obj);
    void visit(Wall &obj);
    void visit(Empty &obj);
    void visit(Bot &obj);
private:
	QGraphicsScene* scene;
	QGraphicsView* view;
};

#endif
