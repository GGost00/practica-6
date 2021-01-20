#include "planetagraf.h"


planetagraf::planetagraf(float x, float y, float vx, float vy, float m, float r):escala(0.05)
{
    esf = new planeta(x,y,vx,vy,m,r);
}

QRectF planetagraf::boundingRect() const
{
    return QRectF(-1*escala*esf->getR(),-1*escala*esf->getR(),2*escala*esf->getR(),2*escala*esf->getR());
}

void planetagraf::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::darkGreen);
    painter->drawEllipse(boundingRect());

//    if(pintura==0){
//        pixmap1.load(":/images/images/sol.png");
//        painter->drawPixmap(boundingRect(),pixmap1,pixmap1.rect());
//    }
//    else if(pintura==2){
//        pixmap2.load(":/images/images/planeta4.png");
//        painter->drawPixmap(boundingRect(),pixmap2,pixmap2.rect());
//    }
//    else if(pintura==3){
//        pixmap3.load(":/images/images/planeta3.png");
//        painter->drawPixmap(boundingRect(),pixmap3,pixmap3.rect());
//    }
//    else if(pintura==4){
//        pixmap4.load(":/images/images/planeta2.png");
//        painter->drawPixmap(boundingRect(),pixmap4,pixmap4.rect());
//    }
//    else if(pintura==5){
//        pixmap5.load(":/images/images/planeta1.png");
//        painter->drawPixmap(boundingRect(),pixmap5,pixmap5.rect());
//    }


}

void planetagraf::setEscala(float s)
{
    escala = s;
}

void planetagraf::actualizar(float dt)
{
    esf->actualizar(dt);
    setPos(esf->getPX()*escala,esf->getPY()*escala);
}

planeta *planetagraf::getEsf()
{
    return esf;
}

void planetagraf::setPintura(int value)
{
    pintura = value;
}

