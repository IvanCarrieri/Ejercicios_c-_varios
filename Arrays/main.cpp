#include <iostream>
#include <cstdlib>

using namespace std;


#include "prototipos.h"
#include "funciones.h"


int main()
{

    int op, vecnum[5];


    mostrar_menu_de_opciones(op);



    while (op != 0)
    {


        switch(op)
        {
        case 1:
            cout << "Ha seleccionado la opci�n 1." << endl;
            cargarVector(vecnum, 5);
            mostrar_menu_de_opciones(op);
            break;
        case 2:
            cout << "Ha seleccionado la opci�n 2." << endl;
            mostrarVector(vecnum, 5);
            mostrar_menu_de_opciones(op);
            break;
        case 3:
            cout << "Ha seleccionado la opci�n 3." << endl;
            mostrarMayor(vecnum, 5);
            mostrar_menu_de_opciones(op);
            break;
        case 4:
            cout << "Ha seleccionado la opci�n 4." << endl;
            mostrarMenor(vecnum);
            mostrar_menu_de_opciones(op);
            break;
        case 0:
            cout << "Ha salido del programa." << endl;
            break;
        default:
            cout << "Opci�n no v�lida." << endl;
            mostrar_menu_de_opciones(op);
            break;
        }

    }


return 0;

}
