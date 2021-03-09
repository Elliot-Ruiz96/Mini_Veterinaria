#ifndef LISTA2_H
#define LISTA2_H

#include <iostream>
#include <stdexcept>
using namespace std;

template <class T>

class Nodo
{
    T dato;
    Nodo<T> *sig;

public:
    Nodo(const T &d, Nodo<T> *s = nullptr) //Tipo - Nombre,Direccion(&)
    {
        dato = d;
        sig = s;
    }

    template <class>
    friend class Lista;
};

template <class T>
class Lista2
{
    Nodo<T> *raiz2;
public:
    Lista2();
    ~Lista2();
    void insertarIn(const T &d);
    T findData(const string &s);
    bool posValida(const string &s);
    bool listaVacia();
    int tamano();
    T &operator [](int pos);
    string toString();
};

template <class T>
Lista2<T>::Lista2()
{
    //Raiz apunta a vacio
    raiz2 = nullptr;
}

template<class T>
Lista2<T>::~Lista2()
{
    Nodo<T> *temp = raiz2;
    while(temp != nullptr){
        raiz2 = raiz2->sig;
        delete temp;
        temp = raiz2;
    }
}

template<class T>
void Lista2<T>::insertarIn(const T &d)
{
    if (raiz2==nullptr) {
        //Crea un nuevo nodo si raiz apunta a vacio y apunta raiz a ese nodo
        Nodo<T> *nuevo = new Nodo<T>(d);
        raiz2 = nuevo;
    } else {
        //Crea nodo y apunta la raiz a ese nuevo nodo enlazado a el anterior
        Nodo<T> *nuevo = new Nodo<T>(d);
        nuevo->sig = raiz2;
        raiz2 = nuevo;
    }
}

template<class T>
T Lista2<T>::findData(const string &s)
{
    Nodo<T> *temp = raiz2;
    if (posValida(s)) {
        while (temp != nullptr){
            if(temp->dato->nombreC == s) {
                return temp->dato;
            }
            temp = temp->sig;
        }
    }
    return 0;
}

template<class T>
bool Lista2<T>::posValida(const string &s)
{
    Nodo<T>* temp = raiz2;
    while (temp != nullptr) {
        if(temp->dato->nombreC == s ){
            return true;
        }
        temp = temp->sig;
    }
    return false;
}

template<class T>
bool Lista2<T>::listaVacia()
{
    if (raiz2 == nullptr) {
        return true;
    }
    return false;
}

template<class T>
int Lista2<T>::tamano()
{
    Nodo<T> *temp = raiz2;
    int cont = 0;
    while (temp != nullptr) {
        cont++;
        temp = temp->sig;
    }
}

template<class T>
T &Lista2<T>::operator [](int pos)
{
    if (pos < 0 || pos >= tamano()) {
        throw out_of_range("Posicion invalida, operador [], lista");//Nunca sera invalida
    } else {
        Nodo<T> *temp = raiz2;
        int cont = 0;

        while (temp != nullptr and cont != pos) {
            temp = temp->sig;
            cont ++;
        }
        return temp->dato;
    }
}

template<class T>
string Lista2<T>::toString()
{
    Nodo<T> *temp = raiz2;//Direccion temporal
    string lista;//Inicia string lista

    while (temp != nullptr) {//Hasta que temp apunte a nullo
        //lista *= cout << temp->dato->getNombreC;
        lista += temp->dato;//Se le añade lo que hay
        temp = temp->sig; //Temp pasa a la direccion siguiente
    }
    return lista;
}

#endif // LISTA2_H
