#include "graphicsrender.h"

GraphicsRender::GraphicsRender(QGraphicsView &v)
{
	scene = new QGraphicsScene();
	scene->setSceneRect(0,0,544,462);
	scene->setBackgroundBrush(QBrush(QColor(1,144,0)));

	view = &v;
	view->setScene(scene);
}
void GraphicsRender::visit(Board &obj)
{
	if((obj.getItem()) == NULL)
	{
		QImage image("res/bord.png");
		obj.setItem(QPixmap::fromImage(image));
		obj.getItem()->setPos(0,416);
		scene->addItem(obj.getItem());

		QFont font("Fixedsys");
		font.setPointSize(20);
		font.setWeight(QFont::Bold);

		obj.getText()->setFont(font);
		obj.getText()->setPos(30,420);
		obj.getText()->setDefaultTextColor(Qt::white);

		obj.getShade()->setFont(font);
		obj.getShade()->setPos(32,422);
		obj.getShade()->setDefaultTextColor(Qt::black);

		scene->addItem(obj.getShade());
		scene->addItem(obj.getText());
	}

	obj.getText()->setPlainText(obj.getString());
	obj.getShade()->setPlainText(obj.getString());
}
void GraphicsRender::visit(Block &obj)
{
	if((obj.getItem()) == NULL)
	{
		QImage image("res/block.png");
		obj.setItem(QPixmap::fromImage(image));
		obj.getItem()->setPos(obj.getPosition().i*32,obj.getPosition().j*32);
		scene->addItem(obj.getItem());
	}
}
void GraphicsRender::visit(Bomb &obj)
{
	if((obj.getItem()) == NULL)
	{
		QImage image("res/bomb.png");
		obj.setItem(QPixmap::fromImage(image));
		obj.getItem()->setPos(obj.getPosition().i*32,obj.getPosition().j*32);
		scene->addItem(obj.getItem());

		QImage image0("res/bomb0.png");
		QImage image1("res/bomb1.png");
		QImage image2("res/bomb2.png");
		QImage image3("res/bomb3.png");

		obj.setItems(0,QPixmap::fromImage(image0));
		scene->addItem(obj.getItems(0));
		obj.getItems(0)->setVisible(false);

		obj.setItems(1,QPixmap::fromImage(image1));

		scene->addItem(obj.getItems(1));
		obj.getItems(1)->setVisible(false);

		obj.setItems(2,QPixmap::fromImage(image2));
		scene->addItem(obj.getItems(2));
		obj.getItems(2)->setVisible(false);

		obj.setItems(3,QPixmap::fromImage(image3));
		scene->addItem(obj.getItems(3));
		obj.getItems(3)->setVisible(false);
	}
	if(obj.getActiv())
	{
		if(!(obj.getItem()->isVisible()))
		{
			obj.getItem()->setPos(obj.getPosition().i*32,obj.getPosition().j*32);
			obj.getItem()->setVisible(true);
		}
	}
	else
	{
		if(obj.getItem()->isVisible())
		{
			obj.getItem()->setVisible(false);
		}
	}
	if(obj.getExplodeAnimation()!=0)
	{
		for(int i=0; i<4; i++)
		{
			obj.getItems(i)->setPos(obj.getPosition().i*32-32,obj.getPosition().j*32-32);
			obj.getItems(i)->setVisible(false);
		}

		if(obj.getExplodeAnimation()/2<4)
		{
			obj.getItems(obj.getExplodeAnimation()/2)->setVisible(true);
		}

		if(obj.getExplodeAnimation()+1 == 10)
		{
			obj.setExplodeAnimation(0);
			obj.setPosition(0,0);
		}
		else
		{
			obj.setExplodeAnimation(obj.getExplodeAnimation()+1);
		}
	}
}
void GraphicsRender::visit(Player &obj)
{
	if((obj.getItem()) == NULL)
	{
		QImage image("res/player.png");
		obj.setItem(QPixmap::fromImage(image));
		obj.getItem()->setPos(obj.getPosition().i*32,obj.getPosition().j*32);
		scene->addItem(obj.getItem());
	}
	if(!(obj.getMove()))
	{
		obj.getItem()->moveBy(obj.getDirection().i,obj.getDirection().j);
	}
}
void GraphicsRender::visit(Wall &obj)
{
	if((obj.getItem()) == NULL)
	{
		QImage image("res/wall.png");
		obj.setItem(QPixmap::fromImage(image));
		obj.getItem()->setPos(obj.getPosition().i*32,obj.getPosition().j*32);
		scene->addItem(obj.getItem());
	}
}
void GraphicsRender::visit(Empty &obj)
{

}
void GraphicsRender::visit(Bot &obj)
{
	if((obj.getItem()) == NULL)
	{
		QImage image("res/bot.png");
		obj.setItem(QPixmap::fromImage(image));
		obj.getItem()->setPos(obj.getPosition().i*32,obj.getPosition().j*32);
		scene->addItem(obj.getItem());
	}
	if(!(obj.getMove()))
	{
		obj.getItem()->moveBy(obj.getDirection().i,obj.getDirection().j);
	}
}