#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include "nodo.h"
#include "nodo.cpp"

using namespace std;

template <class T>

class Lista
{
public:
    Lista();
    ~Lista();
    // Iniciar todos los metodos requeridos para las opciones de la lista
    void insertar_inicio(T);
    void insertar_en(int);
    void tomar(int);
    void buscar(T);
    void eliminar(int);
    void modificar();
    void vacio();
    void purgar();
    void tamanio();
    void tomar1();
    void imprime();
    void teclado(int);
    void teclado2(int);
    void insertar_final(T);
private:
    Nodo<T> *m_inicio;
    int m_num_nodos;

};

#endif // LISTA_H
