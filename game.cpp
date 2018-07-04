#include "game.h"

#include <QKeyEvent>
#include <QDebug>

Game::Game(QGraphicsScene &scene) : scene(scene)
{
	connect(&mainLoopTimer, &QTimer::timeout, this, &Game::mainLoop);
	mainLoopTimer.setSingleShot(false);
	mainLoopTimer.start(1000 / 60);

	init();
}

QVector2D* getRandomVector()
{
	QRandomGenerator *rand = new QRandomGenerator();

	QVector2D *temp = new QVector2D(rand->bounded(2.0),rand->bounded(2.0));
	qDebug() << "randomVector: " << temp->x() << " " << temp->y();
	return temp;
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
	ball = new Ball();
	scene.addItem(ball);
	ball->setPos(player->x()+15,player->y()-20);
	ball->setVector(getRandomVector());
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
		int xPos = player->x() - 5;//player->rect().width();
		int yPos = player->y();
		if (xPos >= 0) {
			player->setPos(xPos, yPos);
		}
	} else if (event->key() == Qt::Key_Right) {
		int xPos = player->x() + 5; //player->rect().width();
		int yPos = player->y();
		if (xPos <= scene.width() - player->rect().width()) {
			player->setPos(xPos, yPos);
		}
	}/* else if (event->key() == Qt::Key_Down) {
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
	}*/
}

void Game::mainLoop()
{
	//qDebug() << "mainLoop" << __FILE__ << __LINE__;
	if((ball->x() >= 0 && ball->x() <= 600) && (ball->y() >= 0 && ball->y() <= 600))
	{
		/**QVector2D tempVector = getRandomVector(ball);
		qDebug() << "valtoztatas" << tempVector.x() << " " << tempVector.y();
		if(ball->x() == 0 || ball->x() == 600)
		{
			tempVector.setX(tempVector.x()*-1);
		}*/
		int xPos = ball->x() - ball->getVelocity();// * tempVector.x() / 1000;
		int yPos = ball->y() - ball->getVelocity();// * tempVector.y() / 1000;

		//int xPos = ;
		//int yPos = ;
		qDebug() << "positions:" << xPos << " " << yPos;
		//QPointF()
		ball->setPos(xPos,yPos);
	}
}
