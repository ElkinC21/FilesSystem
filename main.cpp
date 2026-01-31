#include "mainwindow.h"
#include "linkedlist.h"
#include <QApplication>
#include <QDebug>

using std::cout;

int main(int argc, char *argv[])
{
 //Para imprimir cout=qDebug()
    LinkedList lista;

    lista.Print();

    delete lista.Head;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
