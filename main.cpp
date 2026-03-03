#include "mainwindow.h"
#include "controlador.h"
#include <QApplication>
#include <QDebug>



int main(int argc, char *argv[])
{



 Controlador admin;



    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
