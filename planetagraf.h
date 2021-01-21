#ifndef PLANETAGRAF_H
#define PLANETAGRAF_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include "planeta.h"
#include <QPixmap>

class planetagraf:public QGraphicsItem
{
private:
    QPixmap pixmap1,pixmap2,pixmap3,pixmap4,pixmap5;
    planeta *esf;
    float escala;

public:
    planetagraf(float x, float y, float vx, float vy, float m, float r);
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setEscala(float s);
    void actualizar(float dt);
    planeta* getEsf();
    int pintura;
    void setPintura(int value);
};

#endif // PLANETAGRAF_H
