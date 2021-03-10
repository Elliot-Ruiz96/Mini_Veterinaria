#ifndef FECHA_H
#define FECHA_H

#include <iostream>
using namespace std;


class FechaHora
{
public:
    FechaHora(int, int, int, int, int, int);
    void muestraFechaHora();
private:
    int dia;
    int mes;
    int anio;
    int hor;
    int min;
    int seg;
};


#endif // FECHA_H
