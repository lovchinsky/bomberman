#include "controller.h"

Controller::Controller(QWidget* parent):QWidget(parent)
{
	setWindowTitle("Bomberman");

	view = new QGraphicsView(this);

	QGraphicsScene* menu = new QGraphicsScene();
	menu->setSceneRect(0,0,544,462);

	view->setScene(menu);
	view->setRenderHint(QPainter::Antialiasing);
	view->setCacheMode(QGraphicsView::CacheBackground);
	view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
	view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	view->setFixedSize(544,462);
	view->show();

	QImage image("res/menu.png");
	menu->addItem(new QGraphicsPixmapItem(QPixmap::fromImage(image)));
}
Controller::~Controller()
{
	delete view;
	delete timer;
	delete world;
}
void Controller::newGame()
{
	world = new World();
	timer = new QTimer();

	key = 0;
	time = 0;
	paused = false;

	world->getArea()->setView(*view);

	connect(timer,SIGNAL(timeout()),this,SLOT(update()));
}
void Controller::restart()
{
	delete timer;
	delete world;

	newGame();

	timer->start(10);
}
void Controller::start()
{
	if(started)
	{
		newGame();
		started = false;
	}

	timer->start(10);

	paused = false;
}
void Controller::pause()
{
	if(paused)
	{
		timer->start(10);
		paused = false;
	}
	else
	{
		timer->stop();
		paused = true;
	}
}
void Controller::keyPressEvent(QKeyEvent *event)
{
	if(event->key() == Qt::Key_Space && !started && !paused)
	{
		world->setBomb(world->getPlayer()->getPosition());
	}
	else if(event->key() == Qt::Key_R && !started)
	{
		restart();
	}
	else if(event->key() == Qt::Key_Enter)
	{
		start();
	}
	else if(event->key() == Qt::Key_P && !started)
	{
		pause();
	}
	else if(!started)
	{
		key = event->key();
	}
}
void Controller::keyReleaseEvent(QKeyEvent *event)
{
	switch (event->key())
	{
	case Qt::Key_W:
		{
			key = 0;
		}
		break;
	case Qt::Key_A:
		{
			key = 0;
		}
		break;
	case Qt::Key_S:
		{
			key = 0;
		}
		break;
	case Qt::Key_D:
		{
			key = 0;
		}
		break;
	default:
		break;
	}
}
void Controller::update()
{
	time+=10;
	switch (key)
	{
	case Qt::Key_W:
		{
			if(world->getPlayer()->getPosition().i*32 == world->getPlayer()->getItem()->pos().x())
			{
				world->getPlayer()->setDirection(0,-1);

				if(!(world->getArea()->freeWay(world->getPlayer())) && world->getPlayer()->getDestination())
				{
					world->getPlayer()->setDirection(0,0);
				}


				if(world->getPlayer()->getPosition().j*32 - world->getPlayer()->getItem()->pos().y()==16)
				{
					world->getPlayer()->setMove(true);
				}
			}
			else
			{
				if(world->getPlayer()->getPosition().i*32 - world->getPlayer()->getItem()->pos().x()>0)
				{
					world->getPlayer()->setDirection(1,0);
				}
				else if(world->getPlayer()->getPosition().i*32 - world->getPlayer()->getItem()->pos().x()<0)
				{
					world->getPlayer()->setDirection(-1,0);
				}
			}
		}
		break;
	case Qt::Key_A:
		{
			if(world->getPlayer()->getPosition().j*32 == world->getPlayer()->getItem()->pos().y())
			{
				world->getPlayer()->setDirection(-1,0);

				if(!(world->getArea()->freeWay(world->getPlayer())) && world->getPlayer()->getDestination())
				{
					world->getPlayer()->setDirection(0,0);
				}

				if(world->getPlayer()->getPosition().i*32 - world->getPlayer()->getItem()->pos().x()==16)
				{
					world->getPlayer()->setMove(true);
				}
			}
			else
			{
				if(world->getPlayer()->getPosition().j*32 - world->getPlayer()->getItem()->pos().y()>0)
				{
					world->getPlayer()->setDirection(0,1);
				}
				else if(world->getPlayer()->getPosition().j*32 - world->getPlayer()->getItem()->pos().y()<0)
				{
					world->getPlayer()->setDirection(0,-1);
				}
			}
		}
		break;
	case Qt::Key_S:
		{
			if(world->getPlayer()->getPosition().i*32 == world->getPlayer()->getItem()->pos().x())
			{
				world->getPlayer()->setDirection(0,1);

				if(!(world->getArea()->freeWay(world->getPlayer())) && world->getPlayer()->getDestination())
				{
					world->getPlayer()->setDirection(0,0);
				}

				if(world->getPlayer()->getPosition().j*32 - world->getPlayer()->getItem()->pos().y()==-16)
				{
					world->getPlayer()->setMove(true);
				}
			}
			else
			{
				if(world->getPlayer()->getPosition().i*32 - world->getPlayer()->getItem()->pos().x()>0)
				{
					world->getPlayer()->setDirection(1,0);
				}
				else if(world->getPlayer()->getPosition().i*32 - world->getPlayer()->getItem()->pos().x()<0)
				{
					world->getPlayer()->setDirection(-1,0);
				}
			}
		}
		break;
	case Qt::Key_D:
		{
			if(world->getPlayer()->getPosition().j*32 == world->getPlayer()->getItem()->pos().y())
			{
				world->getPlayer()->setDirection(1,0);

				if(!(world->getArea()->freeWay(world->getPlayer())) && world->getPlayer()->getDestination())
				{
					world->getPlayer()->setDirection(0,0);
				}

				if(world->getPlayer()->getPosition().i*32 - world->getPlayer()->getItem()->pos().x()==-16)
				{
					world->getPlayer()->setMove(true);
				}
			}
			else
			{
				if(world->getPlayer()->getPosition().j*32 - world->getPlayer()->getItem()->pos().y()>0)
				{
					world->getPlayer()->setDirection(0,1);
				}
				else if(world->getPlayer()->getPosition().j*32 - world->getPlayer()->getItem()->pos().y()<0)
				{
					world->getPlayer()->setDirection(0,-1);
				}
			}
		}
		break;
	case 0:
		{
			world->getPlayer()->setDirection(0,0);
		}
		break;
	default:
		break;
	}

	world->update();
	
	if(!(world->getPlayer()->getAlive()))
	{
		world->getArea()->renderScreen(time/1000,-1);
		timer->stop();
	}
	else
	{
		world->getArea()->renderScreen(time/1000,world->killsCount());
	}
}
