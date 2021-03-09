#include "fecha.h"

#include <iostream>

Fecha::Fecha(int dia, int mes, int anio)
{
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
}

Fecha::Fecha()
{
    this->dia = 0;
    this->mes = 0;
    this->anio = 0;
}

void Fecha::muestraFecha()
{
    muestraFecha(this->dia,this->mes,this->anio);
}

void Fecha::muestraFecha(int dia, int mes, int anio)
{
    std::cout << dia << "-" << mes << "-" << anio << std::endl;
}

void Fecha::muestraFecha(int dia, int mes, int anio, char separador)
{
    std::cout << dia << separador << mes << separador << anio << std::endl;
}

void Fecha::setFecha(int dia, int mes, int anio)
{
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
}
