#pragma once

#include <QGraphicsScene>
#include <QTimer>

#include "player.h"
#include "Ball.h"
#include <Object.h>

class Game: public QObject
{
	Q_OBJECT

public:
	Game(QGraphicsScene &scene);
	~Game();

    void generateObjects();

protected:
	void init();

	void keyPressEvent(QKeyEvent *event);

	virtual bool eventFilter(QObject *watched, QEvent* ev) override;

protected slots:
	void mainLoop();

private:
	QGraphicsScene &scene;
	Player *player = nullptr;
	QTimer mainLoopTimer;
	Ball *ball = nullptr;
	QList<Object*> objects;
	int Level = 1;
    int directionX = -1;
    int directionY = -1;
};
