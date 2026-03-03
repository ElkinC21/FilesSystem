#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "directory.h"
#include "file.h"
#include "editortexto.h"
#include <QMenu>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->Kiki = new Controlador();


    estilizarBarraSuperior();

    aplicarTitulo("         FAVORITOS", ui->listWidget);
    aplicarTitulo("   EXPLORADOR", ui->listWidget_2);
    aplicarTitulo("   METADATA", ui->listWidget_3);


    ui->splitter->setStretchFactor(0, 1);
    ui->splitter->setStretchFactor(1, 4);
    ui->splitter->setStretchFactor(2, 2);


    ui->listWidget_2->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->listWidget_2, &QListWidget::customContextMenuRequested, this, &MainWindow::mostrarMenuContexto);
    connect(ui->listWidget_2, &QListWidget::itemDoubleClicked, this, &MainWindow::on_itemDoubleClicked);
    connect(ui->listWidget_2, &QListWidget::itemClicked, this, &MainWindow::on_itemClicked);

    connect(ui->pushButton_4, &QPushButton::clicked, this, &MainWindow::irAtras);
    connect(ui->pushButton_5, &QPushButton::clicked, this, &MainWindow::irAdelante);

    repintarExplorador();
}

MainWindow::~MainWindow() {
    delete ui; }

void MainWindow::estilizarBarraSuperior() {

    ui->lineEdit->setStyleSheet(
        "QLineEdit {"
        "  border: 2px solid #34495e;"
        "  border-radius: 12px;"
        "  padding: 3px 15px;"
        "  background: white;"
        "  color: #2c3e50;"
        "  font-weight: bold;"
        "}"
        );


    QString estiloBotones =
        "QPushButton {"
        "  background-color: #3498db;"
        "  color: white;"
        "  border-radius: 10px;"
        "  font-size: 18px;"
        "  font-weight: bold;"
        "  min-width: 35px;"
        "  min-height: 30px;"
        "}"
        "QPushButton:hover {"
        "  background-color: #2980b9;"
        "}"
        "QPushButton:pressed {"
        "  background-color: #1c5980;"
        "}";

    ui->pushButton_4->setStyleSheet(estiloBotones);


    ui->pushButton_5->setStyleSheet(estiloBotones);

}

void MainWindow::aplicarTitulo(QString texto, QWidget* widget) {

    QWidget* contenedor = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout(contenedor);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);

    QLabel* titulo = new QLabel(texto);
    titulo->setStyleSheet(
        "background-color: #2c3e50;"
        "color: white;"
        "font-weight: bold;"
        "padding: 8px;"
        "border: 1px solid #1a252f;"
        "border-top-left-radius: 4px;"
        "border-top-right-radius: 4px;"
        );


    int index = ui->splitter->indexOf(widget);

    layout->addWidget(titulo);
    layout->addWidget(widget);


    ui->splitter->insertWidget(index, contenedor);
}

void MainWindow::repintarExplorador() {
    ui->listWidget_2->clear();
    if (Kiki->actual) {
        ui->lineEdit->setText(QString::fromStdString(Kiki->actual->getpath()));
    }

    Directory* dir = dynamic_cast<Directory*>(Kiki->actual);
    if (dir) {
        for (OriginFile* hijo : dir->hijos) {
            QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(hijo->getName()));
            item->setData(Qt::UserRole, QVariant::fromValue((void*)hijo));


            if (hijo->getIsDir()) {
                item->setIcon(style()->standardIcon(QStyle::SP_DirIcon));
            } else {
                item->setIcon(style()->standardIcon(QStyle::SP_FileIcon));
            }
            ui->listWidget_2->addItem(item);
        }
    }
}

void MainWindow::on_itemClicked(QListWidgetItem *item) {
    OriginFile* seleccionado = (OriginFile*)item->data(Qt::UserRole).value<void*>();
    if (seleccionado) {

        ui->lineEdit->setText(QString::fromStdString(seleccionado->getpath()));


        ui->listWidget_3->clear();
        ui->listWidget_3->addItem("  " + QString::fromStdString(seleccionado->getName()));
        ui->listWidget_3->addItem("  " + seleccionado->getCreateDate().toString("dd/MM/yyyy HH:mm"));
        ui->listWidget_3->addItem("  " + QString(seleccionado->getIsDir() ? "Carpeta" : "Archivo"));
    }
}

void MainWindow::on_itemDoubleClicked(QListWidgetItem *item) {
    OriginFile* seleccionado = (OriginFile*)item->data(Qt::UserRole).value<void*>();
    if (seleccionado->getIsDir()) {
        Kiki->actual = Kiki->historial.controlarBusqueda(Kiki->actual, seleccionado);
        repintarExplorador();
    } else {
        File* archivo = dynamic_cast<File*>(seleccionado);
        if (archivo) {
            EditorTexto ventana(archivo, this);
            ventana.exec();
            repintarExplorador();
        }
    }
}

void MainWindow::mostrarMenuContexto(const QPoint &pos) {
    QListWidgetItem *item = ui->listWidget_2->itemAt(pos);
    if (!item) {
        QMenu menu(this);
        QAction *aFile = menu.addAction("Crear Archivo");
        QAction *aDir = menu.addAction("Crear Carpeta");
        QAction *res = menu.exec(ui->listWidget_2->mapToGlobal(pos));
        if (res) {
            bool ok;
            QString nom = QInputDialog::getText(this, "Nuevo", "Nombre:", QLineEdit::Normal, "", &ok);
            if (ok && !nom.isEmpty()) {
                Kiki->crearHijo(nom.toStdString(), (res == aDir));
                repintarExplorador();
            }
        }
    }
}

void MainWindow::irAtras() {
    Kiki->historial.irAtras(Kiki->actual);
    repintarExplorador();
}

void MainWindow::irAdelante() {
    Kiki->historial.irAdelante(Kiki->actual);
    repintarExplorador();
}
