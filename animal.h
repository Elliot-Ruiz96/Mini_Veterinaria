#ifndef ANIMAL_H
#define ANIMAL_H

/*#include <iostream>

using namespace std;

enum TIPO {
    PERRO,
    GATO
};

class Animal
{
public:
    Animal(const char* nombre, int dia, int mes, int anio, int hr, int min, int seg);
    Animal();
    friend ostream & operator << (ostream &os, const Animal &a);
private:
    char nombre[50];
    int tipo = PERRO;
    int dia, mes, anio, hr, min, seg;
}; */


#include <stdexcept>
#include <iostream>
#include "listadoble.h"
#include "colaprioridad.h"


using namespace std;

template <class T>

class Animal
{
private:
    T *arreglo;
    int tam;
    int indice;
    const static int MAX = 20;

    // Los atributos de animal son Fecha/hora y si son internados o dados de alta
    ListaDoble<Guerrero> guerreros;     // M
    ColaPrioridad<Recurso> recursos;    // Mandar a la cola a los animales internados

public:
    string nombreA = "SIN NOMBRE";
    Animal();
    ~Animal();
    string getNombreA();
    // Animales ingresados
    void setNombreA(string s);      // Nombre Animal
    void agregarA(const T &dato);   // Agregar animal
    void eliminarA(int pos);        // Eliminar animal
    int linearFindData(const T &name);
    int animalesT();
    int tamanio();

    bool isEmpty();
    T &operator[](int posicion);
    void toString();

};

// Animales internados

template <class T>
Animal<T>::Animal()
{
    arreglo = new T[MAX];       // Empieza en 0 y tendra un max de tan animales
    indice = 0;
    tam = MAX;
}

template <class T>
Animal<T>::~Animal()
{
    delete[]arreglo;            // Destructor
}

template<class T>
std::string Animal<T>::getNombreA()
{
    return nombreA;             //Nombre del animal
}

template<class T>
void Animal<T>::setNombreA(std::string s)
{
    nombreA = s;
}

template<class T>
void Animal<T>::agregarA(const T &dato)
{
    if(indice < tam)
    {
        ///Si el indice es menor al tam total se agrega el animal
        arreglo[indice++] = dato;
    }
    else
    {
        ///Si no se aumenta el tam y se crea un nuevo arreglo y se agrega el animal
        T *nuevo = new T[tam+5];
        for (int i = 0; i < indice; ++i)
        {
            nuevo[i]=arreglo[i];
        }
        delete []arreglo;
        arreglo = nuevo;
        arreglo[indice++] = dato;
        tam = tam + 5;
    }
}

template <class T>
int Animal<T>::linearFindData(const T& name)
{
    ///Busca el nombre del animal si lo encuentra regresa su posicion
    int i(0);
    while( i <= indice)
    {
        if(arreglo[i] == name)
        {
            return i;
        }
        i++;
    }
    ///Si no lo encuentra regresa -1 (Inexistente)
    return -1;
}

template<class T>
void Animal<T>::eliminarA(int pos)
{
    if (pos >= indice or pos < 0)
    {
        ///Revisa si hay espacio para eliminar(Obsoleto por 'isEmpty()')
        cout << "Posicion invalida";
    }
    for (int i = pos; i < indice - 1; ++i)
    {
        ///Recorre el arreglo para sobreescribir la posicion
        arreglo[i] = arreglo[i+1];
    }
    ///Reduce el indice diciendo que hay un animal menos
    indice--;
}

template<class T>
int Animal<T>::animalesT()
{
    return indice;
}

template<class T>
int Animal<T>::tamanio()
{
    return tam;
}

template<class T>
bool Animal<T>::isEmpty()
{
    ///Si el indice es igual a '0' no hay nada en el arreglo
    int result = indice;
    //int result = indice + guerreros.getSize();    // Cambiar guerreros a egresados
    return result == 0;
}

template<class T>
void Animal<T>::toString()
{
    cout << endl << "\t\t\t-Nombre animal: " << nombreA<< endl;         // animalesT()+guerreros.getSize()
    cout << "\t\t\t-Animales totales: " << animalesT() << endl;         //cambiar guerreros a egresados
    cout << "\t\t\t-Animales: " << endl;
    for (int i = 0; i < animalesT(); ++i)
    {
        cout << arreglo[i] << endl;
    }
    cout << "\t\t\t-Dados de alta: " << endl;
    for (int i = 0; i < guerreros.getSize(); ++i)                       //cambiar guerreros a egresados
    {
        cout << guerreros[i] << endl;
    }
    std::cout << "\t\t\t-Recursos: " << std::endl;
    for (int i = 0; i < recursos.colaSize(); ++i) {
        std::cout << recursos[i] << std::endl;
    }
}

template<class T>
T &Animal<T>::operator[](int posicion)
{
    ///Operador sobrecargado para poder imprimir el arreglo tipo T
    if (posicion < 0 or posicion >= indice){
        cout << "Posicion invalida";
    }
    return arreglo[posicion];
}

#endif // ANIMAL_H
