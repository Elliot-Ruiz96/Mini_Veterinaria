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

template <typename T>

Nodo<T>::Nodo()
{
    data = NULL;
    next = NULL;
}

template <typename T>

Nodo<T>::Nodo(T data_)
{
    data = data_;
    next = NULL;
}

template <typename T>

void Nodo<T>::purga()
{
    if (next)
        next->purga();
    delete this;
}

template <typename T>

void Nodo<T>::imprime_n()
{
    cout << data << "-> ";
}

#endif // NODO_H
