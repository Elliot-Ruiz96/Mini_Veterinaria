#ifndef ANIMALE_H
#define ANIMALE_H

#include <iostream>
#include <cstdio>

using namespace std;

class AnimalE
{
private:
    string nombreA;
    string especieA;

public:
    AnimalE();
    AnimalE(const AnimalE&);
    ///Nombre
    string getNombreA() const;
    void setNombreA(const string &value);
    ///Especie
    string getEspecieA() const;
    void setEspecieA(const string &value);
    string toString();

    ///Operadoradores sobrecargados
    AnimalE& operator = (const AnimalE&a);
    friend ostream &operator << (ostream &o, AnimalE &a);
    friend istream& operator >> (istream &is, AnimalE&a);
    bool operator == (const AnimalE&);
    bool operator != (const AnimalE&);
    bool operator <= (const AnimalE&);
    bool operator >= (const AnimalE&);
    bool operator < (const AnimalE&);
    bool operator > (const AnimalE&);
};

#endif // ANIMALE_H
