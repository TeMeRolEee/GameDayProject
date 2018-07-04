#include "game.h"

#include <QKeyEvent>
#include <QDebug>
#include <QTime>

Game::Game(QGraphicsScene &scene) : scene(scene)
{
	connect(&mainLoopTimer, &QTimer::timeout, this, &Game::mainLoop);
	mainLoopTimer.setSingleShot(false);
	mainLoopTimer.start(1000 / 33);

	init();
}

QVector2D* getRandomVector()
{
	QRandomGenerator *rand = new QRandomGenerator();

    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
    rand->seed(qrand());
    int isNegative = qrand();
    qDebug() << "random:" << isNegative;
    QVector2D *temp;
    if(isNegative%2==0)
    {
        temp = new QVector2D(rand->bounded(1.0)*-1,rand->bounded(1.0));
    } else
    {
        temp = new QVector2D(rand->bounded(1.0),rand->bounded(1.0));
    }

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
	//QList<>
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
	QVector2D *tempVector = ball->getVector();
	if((ball->x() >= 0 && ball->x() <= 600) && (ball->y() >= 0 && ball->y() <= 600))
	{

		qDebug() << "valtoztatas" << tempVector->x() << " " << tempVector->y();

		int xPos = ball->x() - (ball->getVelocity() * tempVector->x());
		int yPos = ball->y() - (ball->getVelocity() * tempVector->y());
		if(xPos < 0)
		{
			xPos = 0;
		} else if(xPos > 600)
		{
			xPos = 600;
		}
		qDebug() << "tempvectors: x: " << tempVector->x() << "y: " << tempVector->y() << "szorzat: " << ball->getVelocity() * tempVector->x() << "xpos: " << xPos << "ypos: " << yPos;
		//int xPos = ;
		//int yPos = ;
		//qDebug() << "positions:" << xPos << " " << yPos;
		QPointF(xPos, yPos);
		ball->setPos(xPos,yPos);
	}
	if(ball->x() == 0)
	{
		tempVector->setX(tempVector->y() * -1);
		tempVector->setY(tempVector->x() * -1);
		qDebug() << "inverting: " << tempVector->x();
		int xPos = ball->x() - (ball->getVelocity() * tempVector->x());
		int yPos = ball->y() - (ball->getVelocity() * tempVector->y());
		QPointF(xPos, yPos);
		ball->setPos(xPos,yPos);
	}
	else if (ball->x() == 600)
    {
        tempVector->setX(tempVector->y());
        tempVector->setY(tempVector->x());
        qDebug() << "inverting: " << tempVector->x();
        int xPos = ball->x() - (ball->getVelocity() * tempVector->x());
        int yPos = ball->y() - (ball->getVelocity() * tempVector->y());
        QPointF(xPos, yPos);
        ball->setPos(xPos,yPos);
    }
}
