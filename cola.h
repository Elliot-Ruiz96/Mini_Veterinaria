#ifndef COLA_H
#define COLA_H

#include <iostream>
#include "nodo.h"
#include "nodo.cpp"

using namespace std;

template <class T>

class Cola
{
public:
    Cola();
    ~Cola();
    void encolar(T);
    bool colaVacia();
    void desencolar(T);
    void cimaCola(T);
private:
    Nodo<T> *m_inicio;
    Nodo<T> *m_fin;
    int m_num_nodos;
    T dato;
};


#endif // COLA_H
void apilar();
void desapilar();