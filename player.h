#pragma once

#include <QGraphicsRectItem>
#include <QObject>
#include <QWidget>
#include <QRandomGenerator>

class Player: public QGraphicsRectItem
{
public:
	Player();
	~Player();
	int getRandX();
};


