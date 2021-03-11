#include "veterinaria.h"

using namespace std;

Animal::Animal()
{

}

Animal::Animal(string nombre, string especie)
{
    this->nombre = nombre;
    this->especie = especie;
}

string Animal::getNombre()
{
    return nombre;
}

void Animal::setNombre(string &data)
{
    nombre = data;
}

string Animal::getEspecie()
{
    return especie;
}

void Animal::setEspecie(int &data)
{
    especie = data;
}

veterinaria::veterinaria()
{
    int opcion;
    // Repetir el menu hasta salir
    while (true)
    {
       cout << "\n\t\t\tBienvenido al Menu de veterinaria.\n" << endl;
       cout << "\t\t0. Salir" << endl;
       cout << "\t\t1. Internar animal" << endl;
       cout << "\t\t2. Ingresar animal a la cola de espera" << endl;
       cout << "\t\t3. Dar de alta animal" << endl;
       cout << "\t\t4. Lista de animales internados" << endl;
       cout << "\t\t5. Cola de espera de animales" << endl;
       cout << "\t\t6. Lista de animales egresados" << endl;
       cout << "\n\tIngrese su opcion: ";
       cin >> opcion;

       if (opcion == 1)
       {
            cout << "\n\t\t\t1. Internar animal \n" << endl;
            animalInternado();
            continue;
       }

       else if (opcion == 2)
       {
            cout << "\n\t\t\t2. Ingresar animal a la cola de espera \n" << endl;
            animalEspera();
            continue;
       }

       else if (opcion == 3)
       {
            cout << "\n\t\t\t3. Dar de alta animal \n" << endl;
            animalEgresado();
            continue;
       }

       else if (opcion == 4)
       {
            cout << "\n\t\t\t4. Lista de animales internados \n" << endl;
            printInternados();
            continue;
       }

       else if (opcion == 5)
       {
            cout << "\n\t\t\t5. Cola de espera de animales \n" << endl;
            printCola();
            continue;
       }

       else if (opcion == 6)
       {
            cout << "\n\t\t\t6. Lista de animales egresados \n" << endl;
            printEgresados();
            continue;
       }

       else if (opcion > 6)
       {
           cout << "\n\t\t\tOpcion invalida." << endl;
           continue;
       }

       else if (opcion == 0)
       {
           cout << "\n\t\t\tAdios!\n" << endl;
           break;
       }
    }
}

void veterinaria::animalInternado()
{
    if (espera)
    {
        cout << "\n\tIngrese el nombre de su animal." << endl;
        cin >> nombre;
        num_int ++;
        num_esp --;
    }
    else
        cout << "\n\tNo hay animales en la cola de espera."<<endl;
    if (num_int > 0)
    {
        internado = true;
    }
}

void veterinaria::animalEspera()
{
    Animal a;
    Cola c;
    cout << "\tIngrese el nombre de su animal: ";
    cin >> nombre;
    esp = false;
    while (!esp)
    {
        cout << "\tIngrese la especie de su animal (perro -> 1 // gato  -> 2): ";
        cin >> especie;
        if (especie == 1 or especie == 2)
        {
            esp = true;
            num_esp ++;
            cout <<"\n\tEspecie valida." << endl;
        }
        else
            cout <<"\n\tEspecie invalida." << endl;
    }
    a.setNombre(nombre);
    a.setEspecie(especie);
    c.encolar(a);

    if (num_esp > 0)
    {
        espera = true;
    }

}

void veterinaria::animalEgresado()
{
    if (internado)
    {
        cout << "\n\tIngrese el nombre de su animal." << endl;
        cin >> nombre;
        num_int --;
        num_egr ++;
    }
    else
        cout << "\n\tNo hay animales internados."<<endl;
    if (num_egr > 0)
    {
        egresado = true;
    }
}

void veterinaria::printInternados()
{
    if (internado)
    {
        cout << "\n\tLista de animalesinternados:" << endl;
    }
    else
        cout << "\n\tNo hay animales internados."<<endl;
}

void veterinaria::printCola()
{
    if (espera)
    {
        cout << "\n\tLista de animales en cola de espera:" << endl;
    }
    else
        cout << "\n\tNo hay animales en la cola de espera."<<endl;
}

void veterinaria::printEgresados()
{
    if (egresado)
    {
        cout << "\n\tLista de animales dados de alta:" << endl;
    }
    else
        cout << "\n\tNo hay animales dados de alta."<<endl;
}


