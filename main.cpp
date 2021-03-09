// Para que sea vea mamalon al menos el inicio :(
#include <iostream>
#include <conio.h>      // Perdon por estas libreria, solo se usa para esta parte.
#include <veterinaria.h>

using namespace std;

int main()
{
    cout << R"(
          .--------.--------------------------------------------------.
          |    `  __)__________________________________________       |
          |  )   |.-------------------------------------------.|      |
          |,`._,-||                                           ||      |
          |      ||       Modulo 3A: Programacion en C        ||      |
          |      ||                                           ||,'`.  |
          |      ||            Elliot Ruiz Sanchez            ||    `'|
          |      ||                                           ||`--'`-|
          |      ||                                           ||      |
          |      ||                                           ||      |
          |,.    ||  _______________________________________  ||      |
          | \`._,|| |            MINI VETERINARIA           | ||      |
          |.__`\_|| '------------------' '------------------' ||,-' ,'|
          |::::::||             __________________            || ,'  ;|
          |::::::||            |     PROYECTO     |           ||-._,._|
          |:::::_||            '------------------'           ||::::::|
          |:,-'' ||_____________________o_____________________||::::::|
          |     ,`-------,----------.-------.------------------'::::::|
          |  ,        [1] INICIAR|       |::::: [0] SALIR ::::::::::::|
          '-'---------'-------------'-------'-------------------------'
            )";

    char key = ' ';
    key = _getch();
    if (key == '1')
    {
        // Ingresa al constructor de la clase Menu
        menu c;
    }
    else if (key == '0')
    {
        return 0;
    }
}
