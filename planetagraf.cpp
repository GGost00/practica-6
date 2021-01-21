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
//    painter->setBrush(Qt::darkGreen);
//    painter->drawEllipse(boundingRect());

    if(pintura==0){
        painter->setBrush(Qt::yellow);
    painter->drawEllipse(boundingRect());
    }
    else if(pintura==1){
        painter->setBrush(Qt::darkCyan);
    painter->drawEllipse(boundingRect());
    }
    else if(pintura==2){
        painter->setBrush(Qt::red);
    painter->drawEllipse(boundingRect());
    }
    else if(pintura==3){
        painter->setBrush(Qt::darkGray);
    painter->drawEllipse(boundingRect());
    }
   else if(pintura==4){
        painter->setBrush(Qt::darkBlue);
    painter->drawEllipse(boundingRect());
    }
    else if(pintura==5){
         painter->setBrush(Qt::darkRed);
     painter->drawEllipse(boundingRect());
     }
    else{
         painter->setBrush(Qt::green);
     painter->drawEllipse(boundingRect());
     }


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

