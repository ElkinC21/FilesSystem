#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QPoint>
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>
#include "controlador.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void repintarExplorador();
    void on_itemClicked(QListWidgetItem *item);
    void on_itemDoubleClicked(QListWidgetItem *item);
    void mostrarMenuContexto(const QPoint &pos);
    void irAtras();
    void irAdelante();

private:
    Ui::MainWindow *ui;
    Controlador *Kiki;


    void aplicarTitulo(QString texto, QWidget* widgetDestino);
    void estilizarBarraSuperior();
};

#endif
