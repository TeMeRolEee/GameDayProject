//
// Created by temerole on 2018.07.04..
//

#include "Object.h"

Object::Object(QVector2D &position) :
        QGraphicsRectItem()
{
    setRect(0, 0, 20, 7);
    setPos(position.x(), position.y());

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkYellow);
    setBrush(brush);
}

Object::~Object() {
}
