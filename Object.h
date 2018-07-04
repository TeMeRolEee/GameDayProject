//
// Created by temerole on 2018.07.04..
//

#ifndef OPSWATACADEMYQTEXAMPLE_OBJECT_H
#define OPSWATACADEMYQTEXAMPLE_OBJECT_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QBrush>
#include <QRandomGenerator>
#include <QVector2D>

class Object: public QGraphicsRectItem {
public:
    Object(QVector2D &position);
    ~Object();
};


#endif //OPSWATACADEMYQTEXAMPLE_OBJECT_H
