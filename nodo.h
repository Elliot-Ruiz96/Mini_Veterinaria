#ifndef NODO_H
#define NODO_H

#include <iostream>

using namespace std;

template <class T>

class Nodo
{
public:
    Nodo();
    Nodo(T);
    Nodo *next;
    T data;
    void purga();
    void imprime_n();
};

#endif // NODO_H
