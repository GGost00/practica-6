#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


    ui->setupUi(this);
    h_limit=900;
    v_limit=600;
    dt=1;
    timer=new QTimer(this);
    ui->parar_2->setEnabled(false);
    ui->iniciar_2->setEnabled(false);
    scene =new QGraphicsScene(this);
    scene->setSceneRect(-h_limit/2,-v_limit/2,h_limit,v_limit);
    ui->graphicsView->setScene(scene);
    ui->centralwidget->adjustSize();
    PLANETA=0;
    timer->stop();
    //scene->setBackgroundBrush(QBrush(QImage(":/images/images/fondo.jpg")));
    connect(timer,SIGNAL(timeout()),this,SLOT(actualizar()));



}
MainWindow::~MainWindow()
{
    delete ui;
    delete timer;
    delete scene;
}

void MainWindow::actualizar()
{
    Guardar.open("coords.txt",ios::app);
    for (int i=0;i<bars.size() ;i++ ) {
        for (int j=0;j< bars.size() ;j++ ) {
            if(i!=j){
                bars.at(i)->getEsf()->acelerar(bars.at(j)->getEsf()->getPX(),bars.at(j)->getEsf()->getPY(),bars.at(j)->getEsf()->getMasa());
                bars.at(i)->actualizar(dt);
            }
        }
        Guardar<<bars.at(i)->getEsf()->getPX()<<"\t"<<bars.at(i)->getEsf()->getPY()<<"\t";

    }
    Guardar.close();
    if(c==1 && bars.size()>=1){
        ui->posix_3->setText(QString::number(bars.at(0)->getEsf()->getPX()));
        ui->posiy_3->setText(QString::number(bars.at(0)->getEsf()->getPY()));
        ui->velox_2->setText(QString::number(bars.at(0)->getEsf()->getVX()));
        ui->veloy_2->setText(QString::number(bars.at(0)->getEsf()->getVY()));
        ui->acele_x->setText(QString::number(bars.at(0)->getEsf()->getAX()));
        ui->acele_y->setText(QString::number(bars.at(0)->getEsf()->getAY()));
    }
    else if(c==2 && bars.size()>=2){
        ui->posix_3->setText(QString::number(bars.at(1)->getEsf()->getPX()));
        ui->posiy_3->setText(QString::number(bars.at(1)->getEsf()->getPY()));
        ui->velox_2->setText(QString::number(bars.at(1)->getEsf()->getVX()));
        ui->veloy_2->setText(QString::number(bars.at(1)->getEsf()->getVY()));
        ui->acele_x->setText(QString::number(bars.at(1)->getEsf()->getAX()));
        ui->acele_y->setText(QString::number(bars.at(1)->getEsf()->getAY()));
    }
    else if(c==3 && bars.size()>=3){
        ui->posix_3->setText(QString::number(bars.at(2)->getEsf()->getPX()));
        ui->posiy_3->setText(QString::number(bars.at(2)->getEsf()->getPY()));
        ui->velox_2->setText(QString::number(bars.at(2)->getEsf()->getVX()));
        ui->veloy_2->setText(QString::number(bars.at(2)->getEsf()->getVY()));
        ui->acele_x->setText(QString::number(bars.at(2)->getEsf()->getAX()));
        ui->acele_y->setText(QString::number(bars.at(2)->getEsf()->getAY()));
    }
    else if(c==4 && bars.size()>=4){
        ui->posix_3->setText(QString::number(bars.at(3)->getEsf()->getPX()));
        ui->posiy_3->setText(QString::number(bars.at(3)->getEsf()->getPY()));
        ui->velox_2->setText(QString::number(bars.at(3)->getEsf()->getVX()));
        ui->veloy_2->setText(QString::number(bars.at(3)->getEsf()->getVY()));
        ui->acele_x->setText(QString::number(bars.at(3)->getEsf()->getAX()));
        ui->acele_y->setText(QString::number(bars.at(3)->getEsf()->getAY()));
    }
    else if(c==5 && bars.size()>=5){
        ui->posix_3->setText(QString::number(bars.at(4)->getEsf()->getPX()));
        ui->posiy_3->setText(QString::number(bars.at(4)->getEsf()->getPY()));
        ui->velox_2->setText(QString::number(bars.at(4)->getEsf()->getVX()));
        ui->veloy_2->setText(QString::number(bars.at(4)->getEsf()->getVY()));
        ui->acele_x->setText(QString::number(bars.at(4)->getEsf()->getAX()));
        ui->acele_y->setText(QString::number(bars.at(4)->getEsf()->getAY()));
    }
    else if(c==6 && bars.size()>=6){
        ui->posix_3->setText(QString::number(bars.at(5)->getEsf()->getPX()));
        ui->posiy_3->setText(QString::number(bars.at(5)->getEsf()->getPY()));
        ui->velox_2->setText(QString::number(bars.at(5)->getEsf()->getVX()));
        ui->veloy_2->setText(QString::number(bars.at(5)->getEsf()->getVY()));
        ui->acele_x->setText(QString::number(bars.at(5)->getEsf()->getAX()));
        ui->acele_y->setText(QString::number(bars.at(5)->getEsf()->getAY()));
    }
}




void MainWindow::on_actionsol_triggered()
{
    c=1;
}



void MainWindow::on_actionplaneta1_triggered()
{

    c=2;
}

void MainWindow::on_actionplaneta2_triggered()
{
    c=3;
}

void MainWindow::on_actionplaneta3_triggered()
{
    c=4;
}

void MainWindow::on_actionplaneta4_triggered()
{
    c=5;
}

void MainWindow::on_actionplaneta5_triggered()
{
    c=6;
}

void MainWindow::on_actionAcerca_de_triggered()
{
    QString txt;
    txt="para poder ver las propiedades de los planetas \n"
        "las cuales son:\n"
        "- Posicion x,y\n"
        "- Velocidad\n"
        "- Aceleracion\n"
        "Seleccione la opcion de planetas y seleccione\n"
        "el planeta al cual le desea ver las propiedades,\n"
        "estas cualidades saldran en la parde abajo en la \n"
        "derecha las cuales podra ver de una manera facil \n"
        "y sencilla.";
    QMessageBox::about(this,"Instrucciones",txt);
}




void MainWindow::on_generar_2_clicked()
{
    bars.append(new planetagraf(int(ui->posicionx_2->value()),int(ui->posiciony_2->value()),int(ui->velocidadx_2->value()),int(ui->velocidady_2->value()),int(ui->masa_2->value()),int(ui->radio_2->value())));


    for(int i=0;i<bars.size();i++){
        bars.at(i)->actualizar(dt);
        if (i==PLANETA){
        bars.at(i)->setPintura(PLANETA);
        }
        scene->addItem(bars.at(i));
    }
    PLANETA+=1;

    ui->iniciar_2->setEnabled(true);
    ui->parar_2->setEnabled(true);
}

void MainWindow::on_iniciar_2_clicked()
{
    timer->start(dt);
}

void MainWindow::on_parar_2_clicked()
{
    timer->stop();
}


