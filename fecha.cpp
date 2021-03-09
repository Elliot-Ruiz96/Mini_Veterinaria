#include "fecha.h"

using namespace std;

Fecha::Fecha(int dia, int mes, int anio)
{
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
}

void Fecha::muestra_fecha()
{
    cout << " " << this->dia << " " << this->mes << " " << this->anio << endl;
}
