#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <fstream>
#include<QGraphicsScene>
#include <QTimer>
#include <QGraphicsItem>
#include<QGraphicsView>
#include<QDesktopWidget>
#include <QPainter>
#include <QtDebug>
#include <math.h>
#include "planeta.h"
#include "planetagraf.h"
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();
private slots:
    void actualizar();

    void on_actionsol_triggered();

    void on_actionplaneta1_triggered();

    void on_actionplaneta2_triggered();

    void on_actionplaneta3_triggered();

    void on_actionplaneta4_triggered();

    void on_actionplaneta5_triggered();

    void on_actionAcerca_de_triggered();

    void on_generar_2_clicked();

    void on_iniciar_2_clicked();

    void on_parar_2_clicked();



private:
    ofstream Guardar;
    Ui::MainWindow *ui;
    QTimer *timer;
    QGraphicsScene *scene;
    float dt,PLANETA,POSX,POSY,RADIO,MASA,VELOX,VELOY;
    int h_limit,v_limit,variable=0,c;
    QList<planetagraf*>bars;


};
#endif // MAINWINDOW_H
