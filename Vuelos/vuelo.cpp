#include "vuelo.h"

Vuelo::Vuelo()
{

}

QString Vuelo::getId() const
{
    return Id;
}

void Vuelo::setId(const QString &value)
{
    Id = value;
}

QString Vuelo::getOrigen() const
{
    return Origen;
}

void Vuelo::setOrigen(const QString &value)
{
    Origen = value;
}

QString Vuelo::getDestino() const
{
    return Destino;
}

void Vuelo::setDestino(const QString &value)
{
    Destino = value;
}

double Vuelo::getDistancia() const
{
    return Distancia;
}

void Vuelo::setDistancia(double value)
{
    Distancia = value;
}

double Vuelo::getPasajeros() const
{
    return Pasajeros;
}

void Vuelo::setPasajeros(double value)
{
    Pasajeros = value;
}

double Vuelo::getCarga() const
{
    return Carga;
}

void Vuelo::setCarga(double value)
{
    Carga = value;
}
