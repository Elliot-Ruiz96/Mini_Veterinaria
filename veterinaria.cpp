#include "veterinaria.h"

using namespace std;

menu::menu()
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

       else if (opcion == 0)
       {
           cout << "\n\t\t\tAdios!\n" << endl;
           break;
       }
    }
}
