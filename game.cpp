#include "game.h"

#include <QKeyEvent>
#include <QDebug>
#include <QTime>

Game::Game(QGraphicsScene &scene) : scene(scene)
{
	connect(&mainLoopTimer, &QTimer::timeout, this, &Game::mainLoop);
	mainLoopTimer.setSingleShot(false);
	mainLoopTimer.start(1000 / 66);

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
	generateObjects();

	if(ball->getVector()->x() < 0)
	{
		directionX = 1;
	}

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
		int xPos = player->x() - 15;//player->rect().width();
		int yPos = player->y();
		if (xPos >= 0) {
			player->setPos(xPos, yPos);
		}
	} else if (event->key() == Qt::Key_Right) {
		int xPos = player->x() + 15; //player->rect().width();
		int yPos = player->y();
		if (xPos <= scene.width() - player->rect().width()) {
			player->setPos(xPos, yPos);
		}
	}
}

void Game::mainLoop()
{/*
	int tempval;
	for(auto it: objects)
	{
		if(it->isVisible() == false)
		{
			tempval++;
		}
	}
	if(objects.size() == tempval)
	{
		objects.clear();
		Level++;
		generateObjects();
	}*/
	//qDebug() << "mainLoop" << __FILE__ << __LINE__;
	QVector2D *tempVector = ball->getVector();
	for(auto it : objects)
	{
		if(ball->collidesWithItem(it))
		{
			it->setVisible(false);
		}
	}

	if(player->collidesWithItem(ball) && directionX > 0)
	{
		tempVector->setY(tempVector->y() * -1 + getRandomVector()->y());
		directionY = -1;
	}else if(player->collidesWithItem(ball) && directionX < 0)
	{
		tempVector->setY(tempVector->y() * -1 + getRandomVector()->y());
		directionY = -1;
	}

	if(ball->y() > 600)
	{
		delete player;
		scene.clear();
	}
	if(ball->x() <= 0 && (directionX > 0 && directionY < 0))
	{
		tempVector->setX(tempVector->x() * -1);
		directionY = -1;
		directionX = 1;

	}
	else if(ball->x() == 0 && (directionX < 0 && directionY > 0))
	{
		tempVector->setX(tempVector->x() * -1);
		directionY = 1;
		directionX = 1;
	}
	else if(ball->x() == 0 && (directionX > 0 && directionY > 0))
	{
		tempVector->setX(tempVector->x() * -1);
		directionX = 1;
	}
	if(ball->x() >= 590 && (directionX > 0 && directionY < 0))
	{
		tempVector->setX(tempVector->x() * -1);
		directionX = -1;
		directionY = -1;
	}
	else if(ball->x() >= 590 && (directionX > 0 && directionY > 0))
	{
		tempVector->setX(tempVector->x() * -1);
		directionX = 1;
	}
	if(ball->y() <= 5 && (directionX > 0 && directionY < 0))
	{
		tempVector->setY(tempVector->y() * -1);
		directionY = 1;
	}
	else if(ball->y() <= 5 && (directionX < 0 && directionY < 0))
	{
		tempVector->setY(tempVector->y() * -1);
		directionY = 1;
	}

	int xPos = ball->x() - (ball->getVelocity() * tempVector->x());
	int yPos = ball->y() - (ball->getVelocity() * tempVector->y());
	QPointF(xPos, yPos);
	ball->setPos(xPos,yPos);
	qDebug() << "Direction X:" << directionX << "Direction Y:" << directionY;
	//qDebug() << "tempvectors: x: " << tempVector->x() << "y: " << tempVector->y() << "szorzat: " << ball->getVelocity() * tempVector->x() << "xpos: " << xPos << "ypos: " << yPos;
}

void Game::generateObjects() {
	int difficulty = Level * 1.35;
	QRandomGenerator *rand = new QRandomGenerator();

	QTime time = QTime::currentTime();
	qsrand((uint)time.msec());
	rand->seed(qrand());
	for(int i = 0; i < difficulty * 5 ; i++)
	{

		int xPos = rand->bounded(20,580);
		int yPos = rand->bounded(20, 280);
		qDebug() << "generating!!" << xPos << yPos;
		QVector2D position(xPos,yPos);
		Object *temp = new Object(position);
		scene.addItem(temp);
		objects.push_back(temp);
	}
}
