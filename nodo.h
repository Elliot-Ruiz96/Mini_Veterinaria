#ifndef NODO_H
#define NODO_H

#include <iostream>

using namespace std;

template <class T>

class Nodo
{
public:
    void purga();
    void imprime_n();
private:
    Nodo();
    Nodo(T);
    Nodo *next;
    T data;
};

#endif // NODO_H
