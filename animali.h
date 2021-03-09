#ifndef ANIMALI_H
#define ANIMALI_H

#include <iostream>
#include <cstdio>

using namespace std;

class AnimalI
{
private:
    string nombreA;
    string especieA;

public:
    AnimalI();
    AnimalI(const AnimalI&);
    ///Nombre
    string getNombreA() const;
    void setNombreA(const string &value);
    ///Especie
    string getEspecieA() const;
    void setEspecieA(const string &value);
    string toString();

    ///Operadoradores sobrecargados
    AnimalI& operator = (const AnimalI&a);
    friend std::ostream &operator << (std::ostream &o, AnimalI &a);
    friend std::istream& operator >> (std::istream &is, AnimalI&a);
    bool operator == (const AnimalI&);
    bool operator != (const AnimalI&);
    bool operator <= (const AnimalI&);
    bool operator >= (const AnimalI&);
    bool operator < (const AnimalI&);
    bool operator > (const AnimalI&);
};

#endif // ALDEANO_H
