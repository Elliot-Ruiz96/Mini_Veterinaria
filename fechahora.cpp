#include "fechahora.h"

using namespace std;

FechaHora::FechaHora(int dia, int mes, int anio, int hor, int min, int seg)
{
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
    this->hor = hor;
    this->min = min;
    this-> seg = seg;
}

void FechaHora::muestraFechaHora()
{
    cout << " " << this->dia << " " << this->mes << " " << this->anio << endl;
    cout << " " << this->hor << " " << this->min << " " << this->seg << endl;
}
