#include "game.h"

#include <QKeyEvent>
#include <QDebug>

Game::Game(QGraphicsScene &scene) : scene(scene)
{
	connect(&mainLoopTimer, &QTimer::timeout, this, &Game::mainLoop);
	mainLoopTimer.setSingleShot(false);
	mainLoopTimer.start(1000 / 30);

	init();
}

Game::~Game()
{
	// If you remove the graphics item from the scene, then the object have to be explicitly deleted.
//	scene->removeItem(player);
//	delete player;
//	player = nullptr;
}

void Game::init()
{
	player = new Player();
	scene.addItem(player);
}

bool Game::eventFilter(QObject *watched, QEvent *event)
{
	Q_UNUSED(watched);

	if (event->type() == QEvent::KeyPress)
	{
		keyPressEvent((QKeyEvent*) event);
		return true;
	}
	return false;
}

void Game::keyPressEvent(QKeyEvent *event)
{
	if (event->key() == Qt::Key_Left) {
		int xPos = player->x() - player->rect().width();
		int yPos = player->y();
		if (xPos >= 0) {
			player->setPos(xPos, yPos);
		}
	} else if (event->key() == Qt::Key_Right) {
		int xPos = player->x() + player->rect().width();
		int yPos = player->y();
		if (xPos <= scene.width() - player->rect().width()) {
			player->setPos(xPos, yPos);
		}
	} else if (event->key() == Qt::Key_Down) {
		int xPos = player->x();
		int yPos = player->y() + player->rect().height();
		if (yPos <= scene.height() - player->rect().height()) {
			player->setPos(xPos, yPos);
		}
	} else if (event->key() == Qt::Key_Up) {
		int xPos = player->x();
		int yPos = player->y() - player->rect().height();
		if (yPos >= 0) {
			player->setPos(xPos, yPos);
		}
	}
}

void Game::mainLoop()
{
	qDebug() << "mainLoop" << __FILE__ << __LINE__;
}
