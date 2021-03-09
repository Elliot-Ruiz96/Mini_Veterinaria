#include "animale.h"

using namespace std;

AnimalE::AnimalE()
{
}

AnimalE::AnimalE(const AnimalE& a) : nombreA(a.nombreA),  especieA(a.especieA)
{
}

string AnimalE::getEspecieA() const
{
    return especieA;
}

void AnimalE::setEspecieA(const string &value)
{
    especieA = value;
}

string AnimalE::getNombreA() const
{
    return nombreA;
}

void AnimalE::setNombreA(const string &value)
{
    nombreA = value;
}

string AnimalE::toString()
{
    return "\t\t\t+ " + nombreA + " | " + especieA;
}

AnimalE &AnimalE::operator = (const AnimalE &a)
{
    //Ahora el compilador puede igualar
    nombreA = a.nombreA;
    especieA = a.especieA;
    return *this;
}

ostream &operator <<(ostream &o, AnimalE &a)
{
    o << "\t\t\t+ "
      << a.nombreA
      << " | " << a.especieA;
    return o;
}

istream &operator >> (istream &is, AnimalE &a)
{
    is >> a.nombreA;
    is >> a.especieA;
    return is;
}

bool AnimalE::operator == (const AnimalE &a)
{
    //Operador sobrecargado para poder comparar
    return nombreA == a.nombreA;
}

//Resto de operadores existentes
bool AnimalE::operator != (const AnimalE &a)
{
    return nombreA != a.nombreA;
}

bool AnimalE::operator <= (const AnimalE &a)
{
    return nombreA <= a.nombreA;
}

bool AnimalE::operator >= (const AnimalE &a)
{
    return nombreA >= a.nombreA;
}

bool AnimalE::operator < (const AnimalE &a)
{
    return nombreA < a.nombreA;
}

bool AnimalE::operator > (const AnimalE &a)
{
    return nombreA > a.nombreA;
}
