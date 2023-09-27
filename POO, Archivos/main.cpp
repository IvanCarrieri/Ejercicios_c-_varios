
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

#include "claseFecha.h"
#include "claseEmpleado.h"
#include "funciones.h"


int main(){



  int opc;
    while(true){
        system("cls");
        cout<<"MENU PRINCIPAL"<<endl;
        cout<<"-----------------------"<<endl;
        cout<<"1. REGISTRO ARCHIVO DE EMPLEADOS"<<endl;
        cout<<"2. MOSTRAR TODOS LOS REGISTROS EMPLEADOS"<<endl;
        cout<<"3. MOSTRAR REGISTROS POR CARGO"<<endl;
        cout<<"4. ELIMINAR REGISTRO DE EMPLEADO MEDIANTE DNI (baja logica)"<<endl;
        cout<<"5. ELIMINAR REGISTRO MEDIANTE DNI CON BAJA FISICA"<<endl;
        cout<<"6. MODIFICAR DOMICILIO MEDIANTE DNI "<<endl;
        cout<<"0. FIN DEL PROGRAMA"<<endl;
        cout<<"------------------------"<<endl;
        cout<<"OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: cargaEmpleados();
                    break;
            case 2: mostrarListaempleados();
                    break;
            case 3: mostrarPorCargo();
                    break;
            case 4: bajaLogica();
                    break;
            case 5: bajaFisica();
                    break;
            case 6: modificarDomicilio();
                    break;
            case 0: return 0;
                    break;
            default: cout<<"OPCION INCORRECTA"<<endl;
        }
        system("pause");
    }

	cout<<endl;
	system("pause");
	return 0;
}



