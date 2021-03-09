#ifndef FECHA_H
#define FECHA_H

#include <iostream>
using namespace std;


class Fecha
{
public:
    Fecha(int dia, int mes, int anio);
    void muestra_fecha();
private:
    int dia;
    int mes;
    int anio;
};

#endif // FECHA_H
