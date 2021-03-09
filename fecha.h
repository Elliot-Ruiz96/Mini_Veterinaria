#ifndef FECHA_H
#define FECHA_H


class Fecha
{
public:
    Fecha(int dia, int mes, int anio);
    Fecha();
    virtual void muestraFecha();
    static void muestraFecha(int dia, int mes, int anio);
    static void muestraFecha(int dia, int mes, int anio, char separador);
    void setFecha(int dia, int mes, int anio);
private:
    int dia;
    int mes;
    int anio;
};

#endif // FECHA_H
