//
// Created by temerole on 2018.07.04..
//

#ifndef OPSWATACADEMYQTEXAMPLE_BALL_H
#define OPSWATACADEMYQTEXAMPLE_BALL_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QBrush>
#include <QRandomGenerator>
#include <QVector2D>

class Ball: public QGraphicsRectItem
{
private:
    float velocity = 5;
    QVector2D *vector;
public:
    Ball();
    ~Ball();
    float getVelocity();
    QVector2D* getVector();
    void setVelocity(float newVelocity);
    void setVector(QVector2D *newVector);
};


#endif //OPSWATACADEMYQTEXAMPLE_BALL_H
