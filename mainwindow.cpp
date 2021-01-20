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
}




void MainWindow::on_actionsol_triggered()
{
    if(bars.size()>1){
        qDebug()<<bars.at(0)->getEsf()->getPX()<<","<<bars.at(0)->getEsf()->getPY()<<","<<bars.at(0)->getEsf()->getVX()<<","<<bars.at(0)->getEsf()->getVY()<<endl;
    }
    else{
        ui->posix_3->setText("x= 0");
        ui->posiy_3->setText("y= 0");
        ui->velox_2->setText("0");
        ui->veloy_2->setText("0");
        ui->acele_x->setText("0");
        ui->acele_y->setText("0");
    }

}

void MainWindow::on_actionplaneta_1_triggered()
{

    if(bars.size()>2){
        qDebug()<<bars.at(1)->getEsf()->getPX()<<","<<bars.at(1)->getEsf()->getPY()<<","<<bars.at(1)->getEsf()->getVX()<<","<<bars.at(1)->getEsf()->getVY()<<endl;
    }
    else{
        ui->posix_3->setText("x= 0");
        ui->posiy_3->setText("y= 0");
        ui->velox_2->setText("0");
        ui->veloy_2->setText("0");
        ui->acele_x->setText("0");
        ui->acele_y->setText("0");
    }
}

void MainWindow::on_actionplaneta_2_triggered()
{
    if(bars.size()>3){
        qDebug()<<bars.at(2)->getEsf()->getPX()<<","<<bars.at(2)->getEsf()->getPY()<<","<<bars.at(2)->getEsf()->getVX()<<","<<bars.at(2)->getEsf()->getVY()<<endl;
    }
    else{
        ui->posix_3->setText("x= 0");
        ui->posiy_3->setText("y= 0");
        ui->velox_2->setText("0");
        ui->veloy_2->setText("0");
        ui->acele_x->setText("0");
        ui->acele_y->setText("0");
    }
}

void MainWindow::on_actionplaneta_3_triggered()
{
    if(bars.size()>4){
        qDebug()<<bars.at(3)->getEsf()->getPX()<<","<<bars.at(3)->getEsf()->getPY()<<","<<bars.at(3)->getEsf()->getVX()<<","<<bars.at(3)->getEsf()->getVY()<<endl;
    }
    else{
        ui->posix_3->setText("x= 0");
        ui->posiy_3->setText("y= 0");
        ui->velox_2->setText("0");
        ui->veloy_2->setText("0");
        ui->acele_x->setText("0");
        ui->acele_y->setText("0");
    }
}

void MainWindow::on_actionplaneta_4_triggered()
{
    if(bars.size()>5){
        qDebug()<<bars.at(4)->getEsf()->getPX()<<","<<bars.at(4)->getEsf()->getPY()<<","<<bars.at(4)->getEsf()->getVX()<<","<<bars.at(4)->getEsf()->getVY()<<endl;
    }
    else{
        ui->posix_3->setText("x= 0");
        ui->posiy_3->setText("y= 0");
        ui->velox_2->setText("0");
        ui->veloy_2->setText("0");
        ui->acele_x->setText("0");
        ui->acele_y->setText("0");
    }
}

void MainWindow::on_actionplaneta_5_triggered()
{
    if(bars.size()>6){
        qDebug()<<bars.at(5)->getEsf()->getPX()<<","<<bars.at(5)->getEsf()->getPY()<<","<<bars.at(5)->getEsf()->getVX()<<","<<bars.at(5)->getEsf()->getVY()<<endl;
    }
    else{
        ui->posix_3->setText("x= 0");
        ui->posiy_3->setText("y= 0");
        ui->velox_2->setText("0");
        ui->veloy_2->setText("0");
        ui->acele_x->setText("0");
        ui->acele_y->setText("0");
    }
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
        scene->addItem(bars.at(i));
    }


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
