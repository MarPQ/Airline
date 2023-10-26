#include "aerolinea.h"
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QVector>
Aerolinea::Aerolinea()
{

}

void Aerolinea::agregar(Vuelo &vuelo)
{
    vuelos.append(vuelo);
}

void Aerolinea::mostrar()
{
    foreach(Vuelo p, vuelos){
        qDebug()<< "ID:    "<< p.getId();
        qDebug()<< "Origen:    "<< p.getOrigen();
        qDebug()<< "Destino:    "<< p.getDestino();
        qDebug()<< "Distancia:    "<< p.getDistancia();
        qDebug()<< "Pasajeros:    "<< p.getPasajeros();
        qDebug()<< "Carga:    "<< p.getCarga();
    }
}

void Aerolinea::guardar(const QString &fileName)
{
    QFile archivo(fileName);

    if (archivo.open(QIODevice::WriteOnly|QIODevice::Text)){
        QTextStream out(&archivo);

        foreach(Vuelo p, vuelos){
            out<< "ID:    "<< p.getId()<< "\n";
            out<< "Origen:    "<< p.getOrigen()<< "\n";
            out<< "Destino:    "<< p.getDestino()<< "\n";
            out<< "Distancia:    "<< p.getDistancia()<< "\n";
            out<< "Pasajeros:    "<< p.getPasajeros()<< "\n";
            out<< "Carga:    "<< p.getCarga()<< "\n";
        }
    }

    archivo.close();

}

void Aerolinea::recuperar(const QString &fileName)
{
    QFile archivo(fileName);
    if(archivo.open(QIODevice::ReadOnly)){
      QTextStream in(&archivo);
      while(!in.atEnd()){
          QString id = in.readLine().split(":").at(1);
          QString origen = in.readLine().split(":").at(1);
          QString destino = in.readLine().split(":").at(1);
          QString distancia = in.readLine().split(":").at(1);
          QString pasajeros = in.readLine().split(":").at(1);
          QString carga = in.readLine().split(":").at(1);

          Vuelo vuelo;
          vuelo.setId(id.trimmed());
          vuelo.setOrigen(origen.trimmed());
          vuelo.setDestino(destino.trimmed());
          vuelo.setDistancia(distancia.trimmed().toDouble());
          vuelo.setPasajeros(pasajeros.trimmed().toDouble());
          vuelo.setCarga(carga.trimmed().toDouble());

          agregar(vuelo);

          qDebug() << id.trimmed()
                   << origen.trimmed()
                   << destino.trimmed()
                   << distancia.trimmed()
                   << pasajeros.trimmed()
                   << carga.trimmed();

      }
    }
}

QList<Vuelo> Aerolinea::buscarId(const QString &id)
{
    QList<Vuelo> encontrados;
    foreach (Vuelo p, vuelos) {
        if (p.getId()== id){
            encontrados << p;
        }
    }
    return encontrados;
}

QList<Vuelo> Aerolinea::buscarDestino(const QString &destino)
{
    QList<Vuelo> encontrados;
    foreach (Vuelo p, vuelos) {
        if (p.getDestino()== destino){
            encontrados << p;
        }
    }
    return encontrados;
}

QList<Vuelo> Aerolinea::buscarOrigen(const QString &origen)
{
    QList<Vuelo> encontrados;
    foreach (Vuelo p, vuelos) {
        if (p.getOrigen()== origen){
            encontrados << p;
        }
    }
    return encontrados;
}

QList<Vuelo> Aerolinea::buscarDistancia(const QString &distancia)
{
    QList<Vuelo> encontrados;
    foreach (Vuelo p, vuelos) {
        if (p.getDistancia()== distancia.toDouble()){
            encontrados << p;
        }
    }
    return encontrados;
}

QList<Vuelo> Aerolinea::buscarCapacidad(const QString &capacidad)
{
    QList<Vuelo> encontrados;
    foreach (Vuelo p, vuelos) {
        if (p.getPasajeros()== capacidad.toDouble()){
            encontrados << p;
        }
    }
    return encontrados;
}

QList<Vuelo> Aerolinea::buscarCarga(const QString &carga)
{
    QList<Vuelo> encontrados;
    foreach (Vuelo p, vuelos) {
        if (p.getCarga()== carga.toDouble()){
            encontrados << p;
        }
    }
    return encontrados;
}

QList<Vuelo> Aerolinea::ordenarBurbuja()
{
    QVector<Vuelo> A = vuelos.toVector();

    for (int i = 0; i <= A.size()-2; ++i) {
        for (int j = 0; j <= A.size()-2; ++j) {
            if (A[j+1].getOrigen()<A[j].getOrigen()) {
                std::swap(A[j+1], A[j]);
            }
        }
    }
    return A.toList();
}

QList<Vuelo> Aerolinea::ordenarInsercion()
{
    QVector<Vuelo> A = vuelos.toVector();

    for (int i = 1; i < A.size(); ++i) {
        Vuelo vuelo1 = A[i];
        int j=i-1;
        while(j>=0 && A[j].getId().toDouble() > vuelo1.getId().toDouble()){
            A[j+1] = A[j];
            j = j-1;
        }
     A[j+1] = vuelo1;
    }
    return A.toList();
}

QList<Vuelo> Aerolinea::ordenarShellSort()
{
    QVector<Vuelo> A = vuelos.toVector();

    int brecha = A.size()/2;
    while (brecha > 0){
        for (int i = brecha; i <= A.size()-1; ++i) {
          double temp = A[i].getDistancia();
          int j = i;
          while (j >= brecha && A[j-brecha].getDistancia() > temp) {
              A[j] = A[j-brecha];
              j = j-brecha;
          }
          A[j].setDistancia(temp);
        }
        brecha = brecha/2;
    }

    return A.toList();
}

QList<Vuelo> Aerolinea::ordenarSeleccion()
{
    QVector<Vuelo> A = vuelos.toVector();

    for (int i = 0; i <= A.size()-2; ++i) {
        int min = i;
        for (int j = i+1; j <= A.size()-1; ++j) {
            if (A[j].getDestino() < A[min].getDestino()){
                min = j;
            }
        }
        std::swap(A[i], A[min]);
    }

    return A.toList();
}

QList<Vuelo> Aerolinea::ordenarInsercion2()
{
    QVector<Vuelo> A = vuelos.toVector();

    for (int i = 1; i < A.size(); ++i) {
        Vuelo vuelo1 = A[i];
        int j=i-1;
        while(j>=0 && A[j].getPasajeros() > vuelo1.getPasajeros()){
            A[j+1] = A[j];
            j = j-1;
        }
     A[j+1] = vuelo1;
    }
    return A.toList();
}

QList<Vuelo> Aerolinea::ordenarSeleccion2()
{
    QVector<Vuelo> A = vuelos.toVector();

    for (int i = 0; i <= A.size()-2; ++i) {
        int min = i;
        for (int j = i+1; j <= A.size()-1; ++j) {
            if (A[j].getCarga() < A[min].getCarga()){
                min = j;
            }
        }
        std::swap(A[i], A[min]);
    }

    return A.toList();
}

