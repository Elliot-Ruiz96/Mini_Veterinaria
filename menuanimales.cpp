#include "menuanimales.h"

using namespace std;

void respaldar(Lista<Animal<AnimalI>*> &animales)
{
    if (animales.tamano()==0)
    {//Si no se han creado animales se manda mensaje y se termina la accion
        cout << endl << "\t\tError: No existen datos para guardar" << endl;
        cout << "\t\t\tPulsa una tecla para continuar...";
        _getch();
        system("cls");
        return;
    }
    /*
     * Se crea el archivo para guardar los animales
     * 'for' hasta el numero total de animales
     * Se introduce en el archivo el nombre de cada animal.
     * Se crea el archivo con el nombre de cada animal y se guardan los atributos
     * Se cierra el archivo atributos
     * Se cierra el archivo de animal
     * Se manda mensaje de operacion realizada con exito
     */
    ofstream archivo("D:\\IECA\\Github\\CursoCC\\Mini_Veterinaria\\Animales.txt", ios::out);

    if(archivo.is_open())
    {
        for (int i = 0; i < animales.tamano(); ++i)
        {
            archivo << animales[i]->getNombreA() << endl;
            ofstream animalis("D:\\IECA\\Github\\CursoCC\\Mini_Veterinaria\\" + animales[i]->getNombreA() + ".txt", ios::out);

            if(animalis.is_open())
            {
                for (int j = 0; j < animales[i]->animalesT(); ++j)
                {
                    //Obtengo el puntero de animales
                    Animal<AnimalI> *c = animales[i];
                    //Salto al animal y obtengo la referencia
                    //del animal "j"
                    AnimalI &a = (*c)[j];
                    animalis << a.getNombreA() << endl;
                    animalis << a.getEspecieA() << endl;
                }
            }
            animalis.close();
        }
        archivo.close();
        cout << endl << "\t\tDatos guardados con exito" << endl << endl;
        cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
        return;
    }
}

void respaldar2(Lista<Animal<AnimalE>*> &animales)
{
    if (animales.tamano()==0)
    {//Si no se han creado animales se manda mensaje y se termina la accion
        cout << endl << "\t\tError: No existen datos para guardar" << endl;
        cout << "\t\t\tPulsa una tecla para continuar...";
        _getch();
        system("cls");
        return;
    }
    ofstream archivo2("D:\\IECA\\Github\\CursoCC\\Mini_Veterinaria\\Animales2.txt", ios::out);

    if(archivo2.is_open())
    {
        for (int i = 0; i < animales.tamano(); ++i)
        {
            archivo2 << animales[i]->getNombreA() << endl;
            ofstream animalis("D:\\IECA\\Github\\CursoCC\\Mini_Veterinaria\\" + animales[i]->getNombreA() + ".txt", ios::out);

            if(animalis.is_open())
            {
                for (int j = 0; j < animales[i]->animalesT(); ++j)
                {
                    //Obtengo el puntero de animales
                    Animal<AnimalE> *c = animales[i];
                    //Salto al animal y obtengo la referencia
                    //del animal "j"
                    AnimalE &a = (*c)[j];
                    animalis << a.getNombreA() << endl;
                    animalis << a.getEspecieA() << endl;
                }
            }
            animalis.close();
        }
        archivo2.close();
        cout << endl << "\t\tDatos guardados con exito" << endl << endl;
        cout << "\t\t\tPulsa una tecla para continuar...";_getch();system("cls");
        return;
    }
}

void recuperar(Lista<Animal<AnimalI>*> &animales)
{
    //Se lee el archivo
    ifstream archivo("D:\\IECA\\Github\\CursoCC\\Mini_Veterinaria\\Animales.txt", ios::in);
    if(!archivo.is_open())
    {
        cout << endl << "\t\t\tError: No existen datos para cargar" << endl << endl;
        cout << "\t\t\tPulsa una tecla para continuar...";
        _getch();
        system("cls");
        return;
    }
    /*
     * Si el archivo se abrio
     * Declaro variables a usar (Posible exceso)
     * 'while' hasta que el archivo termine, consigo primer linea
     * Si el archivo termino rompo el ciclo
     * Creo punteros para añadir nuevas civilizaciones y añado con el nombre que viene en el archivo y se inserta en la lista ligada
     */
    if(archivo.is_open())
    {
        string animalS;
        string animalN;
        string animalIS;

        while (!archivo.eof())
        {
            getline(archivo, animalN);

            if (archivo.eof())
                break;

            Animal<AnimalI> *c = new Animal<AnimalI>;
            c->setNombreA(animalN);
            animales.insertarIn(c);

            /*
             * Leo el archivo con el nombre del animal
             * Existe, dado que arriba comprobe eso
             * 'while' hasta el final del archivo
             * Creo objeto 'animali'
             * Consigo la primer linea, miro si el archivo termino, si es así, cierro ese ciclo
             * si no, añado los atributos a mi aldeano (nombre,especie) y lo añado a su nimal
             * Cierro el archivo animali
             * Regreso al ciclo, si he terminado cierro el archivo de animal y mando mensaje de carga exitosa
             */

            ifstream animalis("D:\\IECA\\Github\\CursoCC\\Mini_Veterinaria\\" + animalN + ".txt", ios::in);
            if (animalis.is_open())
            {
                while (!animalis.eof())
                {

                    AnimalI animal;

                    getline(animalis, animalIS);
                    if (animalis.eof())
                        break;
                    animal.setNombreA(animalS);// Añado directamente el string a un dato string, en este caso el nombre

                    getline(animalis, animalIS);
                    animal.setEspecieA(animalS);

                    c->agregarA(animal);
                }
            }
            animalis.close();
        }
    }
    archivo.close();
    cout << endl << "\t\tLos datos han sido cargados con exito" << endl;
    cout << "\t\t\tPulsa una tecla para continuar...";
    _getch();
    system("cls");
    return;
}

void recuperar2(Lista<Animal<AnimalE>*> &animales)
{
    //Se lee el archivo
    ifstream archivo2("D:\\IECA\\Github\\CursoCC\\Mini_Veterinaria\\Animales2.txt", ios::in);
    if(!archivo2.is_open())
    {
        cout << endl << "\t\t\tError: No existen datos para cargar" << endl << endl;
        cout << "\t\t\tPulsa una tecla para continuar...";
        _getch();
        system("cls");
        return;
    }

    if(archivo2.is_open())
    {
        string animalS;
        string animalN;
        string animalIS;

        while (!archivo2.eof())
        {
            getline(archivo2, animalN);

            if (archivo2.eof())
                break;

            Animal<AnimalE> *c = new Animal<AnimalE>;
            c->setNombreA(animalN);
            animales.insertarIn(c);

            ifstream animalees("D:\\IECA\\Github\\CursoCC\\Mini_Veterinaria\\" + animalN + ".txt", ios::in);
            if (animalees.is_open())
            {
                while (!animalees.eof())
                {

                    AnimalE animal;

                    getline(animalees, animalIS);
                    if (animalees.eof())
                        break;
                    animal.setNombreA(animalS);
                    getline(animalees, animalIS);
                    animal.setEspecieA(animalS);

                    c->agregarA(animal);
                }
            }
            animalees.close();
        }
    }
    archivo2.close();
    cout << endl << "\t\tLos datos han sido cargados con exito" << endl;
    cout << "\t\t\tPulsa una tecla para continuar...";
    _getch();
    system("cls");
    return;
}

MenuAnimales::MenuAnimales()
{
    bool dataLoaded = false; //Para no poder sobrecargar los datos dos veces
    string opcion; // Para reusar variable

    Lista<Animal<AnimalI>*> list;
    Lista<Animal<AnimalI>*> list2;

    Animal<AnimalI>* pos;
    Animal<AnimalE>* pos2;

    while (true) {
        system("cls");
        cout << "\t\t1. Agregar nuevo animal" << endl;
        cout << "\t\t2. Buscar animal internado" << endl;
        cout << "\t\t3. Buscar animal internado" << endl;
        cout << "\t\t4. Dar de alta a animal" << endl;
        cout << "\t\t5. Mostrar animales" << endl;
        cout << "\t\t6. Guardar veterinaria" << endl;
        cout << "\t\t7. Cargar veterinaria" << endl;
        cout << "\t\t0. Cerrar veterinaria" << endl;
        cout << "\t\tOpcion: ";
        getline(cin, opcion);
        system("cls");

        if (opcion=="1")
        {
            cout << "\t\t> Ingresa el nombre de la nueva civilizacion: ";
            getline(cin, opcion);
            if (list.posValida(opcion))
            {
                cout <<  "\t\tError: el animal ya esta en la veterinaria" << endl;
                cout << "\t\t\tPulsa una tecla para continuar...";
                _getch();
                system("cls");
                continue;
            }
                cout << endl << "\t\t\tAnimal ingresado" << endl << endl;
                cout << "\t\t\tPulsa una tecla para continuar...";
                _getch();
                system("cls");
                continue;
        }

        else if(opcion=="2")
        {
            if(!list.listaVacia())
            {
                cout << "\t\t> Nombre del animal a buscar: ";
                getline(cin, opcion);
                if (list.posValida(opcion))
                {
                    pos = list.findData(opcion);
                    system("cls");
                    Menu m(pos);
                }
                else
                {
                    cout << endl << "\t\t\tEl animal no esta internado." << endl << endl;
                    cout << "\t\t\tPulsa una tecla para continuar...";
                    _getch();
                    system("cls");
                    continue;
                }
            }
            else
            {
                cout << endl << "\t\t\tError: no hay animales"<< endl << endl;
                cout << "\t\t\tPulsa una tecla para continuar...";
                _getch();
                system("cls");
                continue;
            }
        }

        else if(opcion=="3")
        {
            if(!list2.listaVacia())
            {
                cout << "\t\t> Nombre del animal a buscar: ";
                getline(cin, opcion);
                if (list2.posValida(opcion))
                {
                    pos = list2.findData(opcion);
                    system("cls");
                    Menu m(pos);
                }
                else
                {
                    cout << endl << "\t\t\tEl animal no esta internado." << endl << endl;
                    cout << "\t\t\tPulsa una tecla para continuar...";
                    _getch();
                    system("cls");
                    continue;
                }
            }
            else
            {
                cout << endl << "\t\t\tError: no hay animales"<< endl << endl;
                cout << "\t\t\tPulsa una tecla para continuar...";
                _getch();
                system("cls");
                continue;
            }
        }

        else if (opcion=="4") {
            string op;
            if (!list.listaVacia())
            {
                cout << "\t\t> Nombre del animal a dar de alta: ";
                getline(cin, opcion);
                if (list.posValida(opcion))
                {
                    cout << "\t\t> Estas seguro de dar de alta al animal? '" << opcion << "' ? S|N: ";
                    getline(cin, op);
                    if (op == "S" or op == "s")
                    {
                        // Como ingresar animal ingreso a lista de egreso?
                        list.eliminarAni(opcion);
                        cout <<"\t\t\tAnimal dado de alta" << endl;
                        cout <<"\t\t\tAnimales internados restantes: " << list.tamano() << endl;
                        cout << "\t\t\tPulsa una tecla para continuar...";
                        _getch();
                        system("cls");
                        continue;
                    }
                    else
                    {
                        cout <<"\t\tAnimal no dado de alta" << endl;
                        cout << "\t\t\tPulsa una tecla para continuar...";
                        _getch();
                        system("cls");
                        continue;
                    }
                }
                else
                {
                    cout << endl << "\t\t\tEl animal no esta internado"<< endl;
                    cout << "\t\t\tPulsa una tecla para continuar...";
                    _getch();
                    system("cls");
                    continue;
                }
            }
            else
            {
                cout << endl << "\t\t\tError: no hay animales" << endl;
                cout << "\t\t\tPulsa una tecla para continuar...";
                _getch();
                system("cls");
                continue;
            }

        }

        else if (opcion=="5")
        {
            if(!list.listaVacia())
            {
                cout <<"\t\t\t\tAnimales internados:"<< endl;
                for(int i (0); i < list.tamano(); ++i)
                {
                    list[i]->toString();
                }
                cout << '\n';
                cout << "\t\t\tPulsa una tecla para continuar...";
                _getch();
                system("cls");
                continue;
            }
            else if(!list2.listaVacia())
            {
                cout <<"\t\t\t\tAnimales dados de alta:"<< endl;
                for(int i (0); i < list2.tamano(); ++i)
                {
                    list2[i]->toString();
                }
                cout << '\n';
                cout << "\t\t\tPulsa una tecla para continuar...";
                _getch();
                system("cls");
                continue;
            }
            else
            {
                cout << "\t\t\tError no hay animales"<< endl;
                cout << "\t\t\tPulsa una tecla para continuar...";
                _getch();
                system("cls");
                continue;
            }

        }

        else if(opcion == "6")
        {
            respaldar(list);
            respaldar2(list2);
        }

        else if(opcion == "7")
        {
            if (dataLoaded == false)
            {
                recuperar(list);
                recuperar2(list2)
                dataLoaded = true;
                continue;
            }
            cout << endl << "\t\tLos animales ya han sido cargados anteriormente" << endl;
            cout << "\t\t\tPulsa una tecla para continuar...";
            _getch();
            system("cls");
            continue;
        }
        else if(opcion == "0")
        {
            cout << endl <<"\t\t\t\tAdios!"<< endl << endl;
            break;
        }
        else if (opcion == "5")
        {
        }///To debug
    }
}
