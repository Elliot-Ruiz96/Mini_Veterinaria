#ifndef LISTA_H
#define LISTA_H

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
class Lista
{
    Nodo<T> *raiz;
public:
    Lista();
    ~Lista();
    void insertarIn(const T &d);
    void insertarFi(const T &d);
    void insertarPo(const T &d, int pos);

    T findData(const string &s);

    void eliminarI();
    void eliminarF();
    void eliminarAni(const string &s);

    bool posValida(const string &s);
    bool listaVacia();

    int tamano();

    T &operator [](int pos);

    string toString();
};

template <class T>
Lista<T>::Lista()
{
    //Raiz apunta a vacio
    raiz = nullptr;
}

template<class T>
Lista<T>::~Lista()
{
    Nodo<T> *temp = raiz;
    while(temp != nullptr){
        raiz = raiz->sig;
        delete temp;
        temp = raiz;
    }
}

template<class T>
void Lista<T>::insertarIn(const T &d)
{
    if (raiz==nullptr) {
        //Crea un nuevo nodo si raiz apunta a vacio y apunta raiz a ese nodo
        Nodo<T> *nuevo = new Nodo<T>(d);
        raiz = nuevo;
    } else {
        //Crea nodo y apunta la raiz a ese nuevo nodo enlazado a el anterior
        Nodo<T> *nuevo = new Nodo<T>(d);
        nuevo->sig = raiz;
        raiz = nuevo;
    }
}

template<class T>
void Lista<T>::insertarFi(const T &d)
{
    if (raiz==nullptr) {
        //Crea un nuevo nodo si raiz apunta a vacio y apunta raiz a ese nodo
        Nodo<T> *nuevo = new Nodo<T>(d);
        raiz = nuevo;
    } else {
        //Crea nodo y apunta la raiz a ese nuevo nodo enlazado a el anterior
        Nodo<T> *temp = raiz;

        while (temp->sig != nullptr) {//Busca una dirección nula para agregar al final
            temp = temp->sig;//Salto a siguiente nodo
        }

        Nodo<T> *nuevo = new Nodo<T>(d);//Nodo a agregar
        temp->sig = nuevo;//Temp apunta al nuevo nodo
    }
}

template<class T>
void Lista<T>::insertarPo(const T &d, int pos)
{
    if (pos < 0) {
        //Pos invalida
    }else{
        Nodo<T> *temp = raiz;
        int cont = 0;
        while (temp != nullptr) {
            if (cont++ == pos) {
                Nodo<T> *nuevo = new Nodo<T>(d);
                nuevo -> sig = temp->sig;
                temp->sig=nuevo;
                break;
            }
            temp = temp->sig;
        }
    }
}

template<class T>
T Lista<T>::findData(const string &s)
{
    Nodo<T> *temp = raiz;
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
void Lista<T>::eliminarI()
{
    if (raiz==nullptr) {
        cout << "Lista vacia";
    }else{
        Nodo<T> *temp = raiz;
        raiz = raiz->sig;
        delete temp;
    }
}

template<class T>
void Lista<T>::eliminarF()
{
    if(raiz == nullptr){
        throw out_of_range("Lista vacia, eliminar");
    }else if (raiz->sig==nullptr) {
        delete raiz;
        raiz = nullptr;
        //eliminarI();
    }else{
        Nodo<T> *temp = raiz;
        while (temp->sig->sig != nullptr) {
            temp = temp->sig;
        }
        delete temp->sig;
        temp->sig = nullptr;
    }
}

template<class T>
void Lista<T>::eliminarAni(const string &s)
{
    Nodo<T>* temp = raiz;
    Nodo<T>* temp2 = raiz;
    if (posValida(s)) {
        if(raiz->dato->nombreC == s){
            raiz = raiz->sig;
            delete temp;
        }else{
            int count = 0;
            while(temp->dato->nombreC != s){
                temp = temp->sig;
                count++;
            }

            temp = raiz;
            for (int i(1); i < count; ++i) {
                temp=temp->sig;
                temp2=temp2->sig;
            }
            temp2=temp2->sig->sig;
            delete temp->sig;
            temp->sig = temp2;
            //cout << "T " << temp << endl;
        }
    }
}

template<class T>
bool Lista<T>::posValida(const string &s)
{
    Nodo<T>* temp = raiz;
    while (temp != nullptr) {
        if(temp->dato->nombreC == s ){
            return true;
        }
        temp = temp->sig;
    }
    return false;
}

template<class T>
bool Lista<T>::listaVacia()
{
    if (raiz == nullptr) {
        return true;
    }
    return false;
}

template<class T>
int Lista<T>::tamano()
{
    Nodo<T> *temp = raiz;
    int cont = 0;
    while (temp != nullptr) {
        cont++;
        temp = temp->sig;
    }
    return cont;
}

template<class T>
T &Lista<T>::operator [](int pos)
{
    if (pos < 0 || pos >= tamano()) {
        throw out_of_range("Posicion invalida, operador [], lista");//Nunca sera invalida
    } else {
        Nodo<T> *temp = raiz;
        int cont = 0;

        while (temp != nullptr and cont != pos) {
            temp = temp->sig;
            cont ++;
        }
        return temp->dato;
    }
}

template<class T>
string Lista<T>::toString()
{
    Nodo<T> *temp = raiz;//Direccion temporal
    string lista;//Inicia string lista

    while (temp != nullptr) {//Hasta que temp apunte a nullo
        //lista *= cout << temp->dato->getNombreC;
        lista += temp->dato;//Se le añade lo que hay
        temp = temp->sig; //Temp pasa a la direccion siguiente
    }
    return lista;
}

// Herencia y uso de mismas funciones

template <class T>

class Lista2 : public Lista
{
    Nodo<T> *raiz2;
public:
    Lista2();
    ~Lista2();
    void insertarIn2(const T &d);
    T findData2(const string &s);
    bool posValida2(const string &s);
    bool listaVacia2();
    int tamano2();
    T &operator [](int pos);
    string toString2();
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
void Lista2<T>::insertarIn2(const T &d)
{
    insertarIn(&d);
}

template<class T>
T Lista2<T>::findData2(const string &s)
{
    findData(&s);
}

template<class T>
bool Lista2<T>::posValida2(const string &s)
{
    posValida2(&s);
}

template<class T>
bool Lista2<T>::listaVacia2()
{
    listaVacia();
}

template<class T>
int Lista2<T>::tamano2()
{
    tamano();
}

template<class T>
T &Lista2<T>::operator [](int pos)
{
    operator [](pos);
}

template<class T>
string Lista2<T>::toString2()
{
    toString();
}

#endif // LISTA_H
