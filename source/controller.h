#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QWidget>
#include <QTimer>
#include <QKeyEvent>
#include <QApplication>

#include "world.h"

class Controller : public QWidget
{
	Q_OBJECT

public:
	Controller(QWidget* parent = 0);
	~Controller();

	void start();
	void stop();
	void restart();
	void pause();
	void newGame();

protected:
	void keyPressEvent(QKeyEvent *);
	void keyReleaseEvent(QKeyEvent*);

public slots:
	void update();

private:
	bool paused;
	bool started;

	int key;
	int time;

	World* world;
	QTimer* timer;
	QGraphicsView* view;
};

#endif