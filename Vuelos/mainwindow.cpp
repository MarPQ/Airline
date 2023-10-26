#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFileDialog>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->buscar_id, SIGNAL(clicked(bool)),this, SLOT(buscarId()));
    connect(ui->buscar_origen, SIGNAL(clicked(bool)),this, SLOT(buscarOrigen()));
    connect(ui->buscar_destino, SIGNAL(clicked(bool)),this, SLOT(buscarDestino()));
    connect(ui->buscar_distancia, SIGNAL(clicked(bool)),this, SLOT(buscarDistancia()));
    connect(ui->buscar_capacidad, SIGNAL(clicked(bool)),this, SLOT(buscarCapacidad()));
    connect(ui->buscar_carga, SIGNAL(clicked(bool)),this, SLOT(buscarCarga()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{   // Obteniendo informacion
    QString id = ui->lineEdit->text();
    QString origen = ui->lineEdit_2->text();
    QString destino = ui->lineEdit_3->text();
    QString distancia = ui->lineEdit_4->text();
    QString pasajeros = ui->lineEdit_5->text();
    QString carga = ui->lineEdit_6->text();

    //Objeto Vuelo
    Vuelo vuelo;
    vuelo.setId(id);
    vuelo.setOrigen(origen);
    vuelo.setDestino(destino);
    vuelo.setDistancia(distancia.toDouble());
    vuelo.setPasajeros(pasajeros.toDouble());
    vuelo.setCarga(carga.toDouble());
    //Agragar a la lista
    aerolinea.agregar(vuelo);

}

void MainWindow::on_pushButton_2_clicked()
{
    aerolinea.mostrar();
}

void MainWindow::on_pushButton_3_clicked()
{
    QString fileName =
            QFileDialog::getSaveFileName(
                this,
                tr("Guardar Vuelos"),
                "C:/",
                tr("Archivo TXT (*.txt)"));

    qDebug() << fileName;

    aerolinea.guardar(fileName);
}

void MainWindow::on_pushButton_4_clicked()
{
    QString fileName =
                QFileDialog::getOpenFileName(
                    this,
                    tr("Abrir Vuelos"),
                    "C:/",
                    tr("Archivo TXT (*.txt)"));

        qDebug() << fileName;
        aerolinea.recuperar(fileName);
}

void MainWindow::buscarId()
{
    qDebug() << "click buscar";
    QString id = ui->lineEdit_7->text();
    qDebug()<< id;

    QList<Vuelo> vuelos=aerolinea.buscarId(id);


    foreach (Vuelo p, vuelos) {
      /*  qDebug() << "ID: " << p.getId() << "\n";
        qDebug() << "Origen: " << p.getOrigen() << "\n";
        qDebug() << "Destino: " << p.getDestino() << "\n";
        qDebug() << "Peso: " << p.getPeso() << "\n";*/

        ui->plainTextEdit->insertPlainText(
                    "ID: "    + p.getId()+"\n"
                    "Origen:" + p.getOrigen()+"\n"+
                    "Destino:" + p.getDestino()+"\n"+
                    "Distancia:"   + QString::number(p.getDistancia())+"\n"
                    "Capacidad:"   + QString::number(p.getPasajeros())+"\n"
                    "Carga:"   + QString::number(p.getCarga())+"\n");

    }
}

void MainWindow::buscarOrigen()
{
    qDebug() << "click buscar";
    QString origen = ui->lineEdit_9->text();
    qDebug()<< origen;

    QList<Vuelo> vuelos=aerolinea.buscarOrigen(origen);


    foreach (Vuelo p, vuelos) {
      /*  qDebug() << "ID: " << p.getId() << "\n";
        qDebug() << "Origen: " << p.getOrigen() << "\n";
        qDebug() << "Destino: " << p.getDestino() << "\n";
        qDebug() << "Peso: " << p.getPeso() << "\n";*/

        ui->plainTextEdit->insertPlainText(
                    "ID: "    + p.getId()+"\n"
                    "Origen:" + p.getOrigen()+"\n"+
                    "Destino:" + p.getDestino()+"\n"+
                    "Distancia:"   + QString::number(p.getDistancia())+"\n"
                    "Capacidad:"   + QString::number(p.getPasajeros())+"\n"
                    "Carga:"   + QString::number(p.getCarga())+"\n");

    }
}

void MainWindow::buscarDestino()
{
    qDebug() << "click buscar";
    QString destino = ui->lineEdit_8->text();
    qDebug()<< destino;

    QList<Vuelo> vuelos=aerolinea.buscarDestino(destino);


    foreach (Vuelo p, vuelos) {
      /*  qDebug() << "ID: " << p.getId() << "\n";
        qDebug() << "Origen: " << p.getOrigen() << "\n";
        qDebug() << "Destino: " << p.getDestino() << "\n";
        qDebug() << "Peso: " << p.getPeso() << "\n";*/

        ui->plainTextEdit->insertPlainText(
                    "ID: "    + p.getId()+"\n"
                    "Origen:" + p.getOrigen()+"\n"+
                    "Destino:" + p.getDestino()+"\n"+
                    "Distancia:"   + QString::number(p.getDistancia())+"\n"
                    "Capacidad:"   + QString::number(p.getPasajeros())+"\n"
                    "Carga:"   + QString::number(p.getCarga())+"\n");

    }
}

void MainWindow::buscarDistancia()
{
    qDebug() << "click buscar";
    QString distancia = ui->lineEdit_10->text();
    qDebug()<< distancia;

    QList<Vuelo> vuelos=aerolinea.buscarDistancia(distancia);


    foreach (Vuelo p, vuelos) {
      /*  qDebug() << "ID: " << p.getId() << "\n";
        qDebug() << "Origen: " << p.getOrigen() << "\n";
        qDebug() << "Destino: " << p.getDestino() << "\n";
        qDebug() << "Peso: " << p.getPeso() << "\n";*/

        ui->plainTextEdit->insertPlainText(
                    "ID: "    + p.getId()+"\n"
                    "Origen:" + p.getOrigen()+"\n"+
                    "Destino:" + p.getDestino()+"\n"+
                    "Distancia:"   + QString::number(p.getDistancia())+"\n"
                    "Capacidad:"   + QString::number(p.getPasajeros())+"\n"
                    "Carga:"   + QString::number(p.getCarga())+"\n");

    }
}

void MainWindow::buscarCapacidad()
{
    qDebug() << "click buscar";
    QString capacidad = ui->lineEdit_11->text();
    qDebug()<< capacidad;

    QList<Vuelo> vuelos=aerolinea.buscarCapacidad(capacidad);


    foreach (Vuelo p, vuelos) {
      /*  qDebug() << "ID: " << p.getId() << "\n";
        qDebug() << "Origen: " << p.getOrigen() << "\n";
        qDebug() << "Destino: " << p.getDestino() << "\n";
        qDebug() << "Peso: " << p.getPeso() << "\n";*/

        ui->plainTextEdit->insertPlainText(
                    "ID: "    + p.getId()+"\n"
                    "Origen:" + p.getOrigen()+"\n"+
                    "Destino:" + p.getDestino()+"\n"+
                    "Distancia:"   + QString::number(p.getDistancia())+"\n"
                    "Capacidad:"   + QString::number(p.getPasajeros())+"\n"
                    "Carga:"   + QString::number(p.getCarga())+"\n");

    }
}

void MainWindow::buscarCarga()
{
    qDebug() << "click buscar";
    QString carga = ui->lineEdit_12->text();
    qDebug()<< carga;

    QList<Vuelo> vuelos=aerolinea.buscarCarga(carga);


    foreach (Vuelo p, vuelos) {
      /*  qDebug() << "ID: " << p.getId() << "\n";
        qDebug() << "Origen: " << p.getOrigen() << "\n";
        qDebug() << "Destino: " << p.getDestino() << "\n";
        qDebug() << "Peso: " << p.getPeso() << "\n";*/

        ui->plainTextEdit->insertPlainText(
                    "ID: "    + p.getId()+"\n"
                    "Origen:" + p.getOrigen()+"\n"+
                    "Destino:" + p.getDestino()+"\n"+
                    "Distancia:"   + QString::number(p.getDistancia())+"\n"
                    "Capacidad:"   + QString::number(p.getPasajeros())+"\n"
                    "Carga:"   + QString::number(p.getCarga())+"\n");

    }
}

void MainWindow::on_pushButton_5_clicked()
{
    QList<Vuelo> vuelos = aerolinea.ordenarBurbuja();
    ui->plainTextEdit_2->clear();
    foreach (Vuelo p, vuelos) {
        ui->plainTextEdit_2->insertPlainText(
                    "ID: "    + p.getId()+"\n"
                    "Origen:" + p.getOrigen()+"\n"+
                    "Destino:" + p.getDestino()+"\n"+
                    "Distancia:"   + QString::number(p.getDistancia())+"\n"
                    "Capacidad:"   + QString::number(p.getPasajeros())+"\n"
                    "Carga:"   + QString::number(p.getCarga())+"\n");
}
}

void MainWindow::on_pushButton_6_clicked()
{
    QList<Vuelo> vuelos = aerolinea.ordenarInsercion();
    ui->plainTextEdit_2->clear();
    foreach (Vuelo p, vuelos) {
        ui->plainTextEdit_2->insertPlainText(
                    "ID: "    + p.getId()+"\n"
                    "Origen:" + p.getOrigen()+"\n"+
                    "Destino:" + p.getDestino()+"\n"+
                    "Distancia:"   + QString::number(p.getDistancia())+"\n"
                    "Capacidad:"   + QString::number(p.getPasajeros())+"\n"
                    "Carga:"   + QString::number(p.getCarga())+"\n");
    }
}

void MainWindow::on_pushButton_7_clicked()
{
    QList<Vuelo> vuelos = aerolinea.ordenarShellSort();
    ui->plainTextEdit_2->clear();
    foreach (Vuelo p, vuelos) {
        ui->plainTextEdit_2->insertPlainText(
                    "ID: "    + p.getId()+"\n"
                    "Origen:" + p.getOrigen()+"\n"+
                    "Destino:" + p.getDestino()+"\n"+
                    "Distancia:"   + QString::number(p.getDistancia())+"\n"
                    "Capacidad:"   + QString::number(p.getPasajeros())+"\n"
                    "Carga:"   + QString::number(p.getCarga())+"\n");
    }
}

void MainWindow::on_pushButton_8_clicked()
{
    QList<Vuelo> vuelos = aerolinea.ordenarSeleccion();
    ui->plainTextEdit_2->clear();
    foreach (Vuelo p, vuelos) {
        ui->plainTextEdit_2->insertPlainText(
                    "ID: "    + p.getId()+"\n"
                    "Origen:" + p.getOrigen()+"\n"+
                    "Destino:" + p.getDestino()+"\n"+
                    "Distancia:"   + QString::number(p.getDistancia())+"\n"
                    "Capacidad:"   + QString::number(p.getPasajeros())+"\n"
                    "Carga:"   + QString::number(p.getCarga())+"\n");
    }
}

void MainWindow::on_pushButton_9_clicked()
{
    QList<Vuelo> vuelos = aerolinea.ordenarInsercion2();
    ui->plainTextEdit_2->clear();
    foreach (Vuelo p, vuelos) {
        ui->plainTextEdit_2->insertPlainText(
                    "ID: "    + p.getId()+"\n"
                    "Origen:" + p.getOrigen()+"\n"+
                    "Destino:" + p.getDestino()+"\n"+
                    "Distancia:"   + QString::number(p.getDistancia())+"\n"
                    "Capacidad:"   + QString::number(p.getPasajeros())+"\n"
                    "Carga:"   + QString::number(p.getCarga())+"\n");
    }
}

void MainWindow::on_pushButton_10_clicked()
{
    QList<Vuelo> vuelos = aerolinea.ordenarSeleccion2();
    ui->plainTextEdit_2->clear();
    foreach (Vuelo p, vuelos) {
        ui->plainTextEdit_2->insertPlainText(
                    "ID: "    + p.getId()+"\n"
                    "Origen:" + p.getOrigen()+"\n"+
                    "Destino:" + p.getDestino()+"\n"+
                    "Distancia:"   + QString::number(p.getDistancia())+"\n"
                    "Capacidad:"   + QString::number(p.getPasajeros())+"\n"
                    "Carga:"   + QString::number(p.getCarga())+"\n");
    }
}
