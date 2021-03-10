#include "cola.h"

template <typename T>
Cola<T>::Cola()
{
    m_num_nodos = 0;
    m_inicio = NULL;
    m_fin = NULL;
}

template <typename T>
Cola<T>::~Cola()
{
}

template<class T>
void Cola<T>::encolar(T data)
{
    Nodo<T> *nuevo_nodo = new Nodo<T>;
    nuevo_nodo->siguiente = NULL;
    nuevo_nodo->dato = data;
    if(cola_vacia(m_inicio))
    {
        m_inicio = nuevo_nodo;
    }
    else
    {
        m_fin -> siguiente = nuevo_nodo;
    }
    m_fin = nuevo_nodo;
}

template<class T>
bool Cola<T>::colaVacia()
{
    return (m_inicio== NULL)? true : false;
}

template<class T>
void Cola<T>::desencolar(T data)
{
    data = m_inicio->dato;
    Nodo<T> *aux = m_inicio;
    if (m_inicio == m_fin)
    {
        m_inicio = NULL;
        m_fin = NULL;
    }
    else
    {
        m_inicio = m_inicio->siguiente;
    }
    delete aux;
}

template<class T>
void Cola<T>::cimaCola(T data)
{
    Nodo<T> *muestraC = m_inicio;
    data = muestraC->dato;
}
