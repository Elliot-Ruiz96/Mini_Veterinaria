#include "animali.h"

using namespace std;

AnimalI::AnimalI(){}

AnimalI::AnimalI(const AnimalI& a) : nombreA(a.nombreA),  especieA(a.especieA)
{
}

string AnimalI::getEspecieA() const
{
    return especieA;
}

void AnimalI::setEspecieA(const string &value)
{
    especieA = value;
}


string AnimalI::getNombreA() const
{
    return nombreA;
}

void AnimalI::setNombreA(const string &value)
{
    nombreA = value;
}

string AnimalI::toString()
{
    return "\t\t\t+ " + nombreA + " | " + especieA;
}

AnimalI &AnimalI::operator = (const AnimalI &a)
{
    //Ahora el compilador puede igualar
    nombreA = a.nombreA;
    especieA = a.especieA;
    return *this;
}

ostream &operator <<(ostream &o, AnimalI &a)
{
    o << "\t\t\t+ "
      << a.nombreA
      << " | " << a.especieA;
    return o;
}

istream &operator >> (istream &is, AnimalI &a)
{
    is >> a.nombreA;
    is >> a.especieA;
    return is;
}

bool AnimalI::operator == (const AnimalI &a){
    //Operador sobrecargado para poder comparar
    return nombreA == a.nombreA;
}

//Resto de operadores existentes
bool AnimalI::operator != (const AnimalI &a)
{
    return nombreA != a.nombreA;
}

bool AnimalI::operator <= (const AnimalI &a)
{
    return nombreA <= a.nombreA;
}

bool AnimalI::operator >= (const AnimalI &a)
{
    return nombreA >= a.nombreA;
}

bool AnimalI::operator < (const AnimalI &a)
{
    return nombreA < a.nombreA;
}

bool AnimalI::operator > (const AnimalI &a)
{
    return nombreA > a.nombreA;
}
