#ifndef AEROLINEA_H
#define AEROLINEA_H
#include "vuelo.h"
#include <QList>

class Aerolinea
{
public:
    Aerolinea();
    void agregar(Vuelo &vuelo);
    void mostrar();
    void guardar(const QString &fileName);
    void recuperar (const QString &fileName);

    QList<Vuelo> buscarId(const QString &Id);
    QList<Vuelo> buscarOrigen(const QString &Origen);
    QList<Vuelo> buscarDestino(const QString &destino);
    QList<Vuelo> buscarDistancia(const QString &Distancia);
    QList<Vuelo> buscarCapacidad(const QString &capacidad);
    QList<Vuelo> buscarCarga(const QString &Carga);

    QList<Vuelo> ordenarBurbuja();
    QList<Vuelo> ordenarInsercion();
    QList<Vuelo> ordenarShellSort();
    QList<Vuelo> ordenarSeleccion();
    QList<Vuelo> ordenarInsercion2();
    QList<Vuelo> ordenarSeleccion2();
private:
    QList<Vuelo> vuelos;

};

#endif // AEROLINEA_H
