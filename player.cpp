#include "player.h"

#include <QBrush>

Player::Player() :
	QGraphicsRectItem()
{
	setRect(0, 0, 60, 15);
	setPos(300, 570);

	QBrush brush;
	brush.setStyle(Qt::SolidPattern);
	brush.setColor(Qt::blue);
	setBrush(brush);
}
int Player::getRandX() {
	QRandomGenerator *rand = new QRandomGenerator();
	int xpos = rand->bounded(0,600);
	return xpos;
}

Player::~Player() {

}
