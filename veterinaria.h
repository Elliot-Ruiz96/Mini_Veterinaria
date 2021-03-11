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
    Animal();
    Animal(string nombre, string especie);
    string getNombre();
    void setNombre(string &data);
    string getEspecie();
    void setEspecie(int &data);

//    friend ostream &operator <<(ostream &os, const Animal* a);
private:
    string nombre;
    string especie;
};

class veterinaria
{
public:
    veterinaria();
    void animalInternado();
    void animalEspera();
    void animalEgresado();
    void printInternados();
    void printCola();
    void printEgresados();

private:
    // Declaracion de las dos listas y cola
//    Lista<Animal*> internados;
//    Lista<Animal*> egresados;
    //Cola<Animal*> aniEspera;
    string nombre;
    int especie, num_esp = 0, num_int = 0, num_egr = 0;
    bool esp = false, espera = false, internado = false, egresado = false;



};

#endif // MENU_H
