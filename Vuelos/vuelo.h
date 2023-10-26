#ifndef VUELO_H
#define VUELO_H

#include <QString>
class Vuelo
{
public:
    Vuelo();
    QString getId() const;
    void setId(const QString &value);

    QString getOrigen() const;
    void setOrigen(const QString &value);

    QString getDestino() const;
    void setDestino(const QString &value);

    double getDistancia() const;
    void setDistancia(double value);

    double getPasajeros() const;
    void setPasajeros(double value);

    double getCarga() const;
    void setCarga(double value);

private:
    QString Id;
    QString Origen;
    QString Destino;
    double Distancia;
    double Pasajeros;
    double Carga;

};

#endif // VUELO_H
