#pragma once

#include <QGraphicsScene>
#include <QTimer>

#include "player.h"

class Game: public QObject
{
	Q_OBJECT

public:
	Game(QGraphicsScene &scene);
	~Game();

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
};
