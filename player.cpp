#include "player.h"

#include <QBrush>

Player::Player() :
	QGraphicsRectItem()
{
	setRect(0, 0, 30, 30);
	setPos(30, 30);

	QBrush brush;
	brush.setStyle(Qt::SolidPattern);
	brush.setColor(Qt::blue);
	setBrush(brush);
}
