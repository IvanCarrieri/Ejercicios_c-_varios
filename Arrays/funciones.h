#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


void mostrar_menu_de_opciones(int &op)
{



    cout<<endl;
    cout << "MENU:" << endl;
    cout << "1- Cargar vector" << endl;
    cout << "2- Mostrar vector" << endl;
    cout << "3- Mostrar maximo" << endl;
    cout << "4- Mostrar minimo" << endl;
    cout << "0- Salir" << endl;
    cout << "Ingrese una opcion: "<<endl;
    cin >> op;
    cout<<endl;
    system("cls");
}


void cargarVector(int *v, int tam)
{
    for (int i=0; i<tam; i++)
    {
        cout<<"cargue un numero: ";
        cin>>v[i];
        cout<<endl;
    }
}

void mostrarVector(int *v, int tam)
{
    for(int i = 0; i < tam; i++)
    {
        cout<<v[i]<<endl;
    }
}

void mostrarMayor(int *v, int tam)
{
    int mayor;
    mayor=v[0];

    for(int i = 0; i <tam; i++)
    {
        if(v[i]>mayor)
        {
            mayor=v[i];
        }

    }

    cout<<"El mayor es: "<<mayor<<endl;
}


void mostrarMenor(int v[])
{
    int menor;
    menor=v[0];

    for(int i = 0; i <5; i++)
    {
        if(v[i]<menor)
        {
            menor=v[i];
        }

    }
    cout<<"El menor es: "<<menor<<endl;

}


#endif // FUNCIONES_H_INCLUDED
