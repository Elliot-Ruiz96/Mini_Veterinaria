#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include "lista.h"
#include "cola.h"
#include "fechahora.h"

using namespace std;

class Animal
{
public:
    bool internado();
    bool egresado();
    bool esperando();
    friend ostream &operator <<(ostream &os, const Animal* a);
private:
    string nombre;
    string especie;
};

class menu
{
public:
    menu();
    void animalInternado()
    {
        cout << "\t\tPrueba";
    }
    void animalEspera()
    {
        cout << "\t\tPrueba";
    }
    void animalEgresado()
    {
        cout << "\t\tPrueba";
    }
    void printInternados()
    {
        cout << "\t\tPrueba";
    }
    void printCola()
    {
        cout << "\t\tPrueba";
    }
    void printEgresados()
    {
        cout << "\t\tPrueba";
    }
private:
    // Declaracion de las dos listas y cola
    Lista<Animal*> internados;
    Lista<Animal*> egresados;
    Cola<Animal*> espera;

};

#endif // MENU_H
