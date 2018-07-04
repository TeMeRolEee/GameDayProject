//
// Created by temerole on 2018.07.04..
//

#include "Ball.h"

Ball::Ball() :
        QGraphicsRectItem()
{
    setRect(10, 10, 10, 10);
    setPos(40, 40);

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    setBrush(brush);
}

float Ball::getVelocity() {
    return velocity;
}

void Ball::setVelocity(float newVelocity) {
    this->velocity = newVelocity;
}

void Ball::setVector(QVector2D *newVector){
    this->vector = newVector;
}



QVector2D Ball::getVector() {
    return *vector;
}