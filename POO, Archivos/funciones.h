#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

//registrar, cargar los empleados en el archivo
void cargaEmpleados();

//cuenta la cantidad de registros en el archivo, y retorna la cant de registros
int contarRegistros();

void mostrarListaempleados();

void mostrarPorCargo();

int buscarRegistro(int dni);
Empleado leerRegistro(int pos);
void sobreEscribirRegistro(Empleado obj, int pos);
void bajaLogica();

void bajaFisica();

//similar  baja logica
void modificarDomicilio();




void cargaEmpleados(){
    Empleado obj;
    FILE *pEmpleado;

    //apertura de archivo, ab es para creacion y agrega recgistro, wb es escritura y rompe el que estaba.
    pEmpleado=fopen("empleados.dat", "ab");
    if(pEmpleado==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return;
    }

    obj.Cargar();
    //escribe en archivo
    fwrite(&obj, sizeof (Empleado), 1, pEmpleado);
    fclose(pEmpleado);
}

//como contar los registros en el archivo
int contarRegistros(){
    int cantReg;
    int tam;
    FILE *pEmpleado;

    //apertura de archivo, ab es para creacion y agrega recgistro, wb es escritura y rompe el que estaba.
    pEmpleado=fopen("empleados.dat", "rb");
    if(pEmpleado==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return -1;
    }

    //fseek establece la pocicion del indicador del archivo
    fseek(pEmpleado,0,2);
    //tam es la cantidad de bytes que tiene el archivo
    tam=ftell(pEmpleado);
    cantReg=tam/sizeof (Empleado);

    return cantReg;

}

void mostrarListaempleados(){
    Empleado obj;
    FILE *pEmpleado;
    int cantReg;

    cantReg=contarRegistros();
    if(cantReg==-1||cantReg==0){
        cout<<"No hay registros o no se pudo crear el archivo"<<endl;
        return;
    }
    cout<<"La cantidad de registros es: ";
    cout<<cantReg<<endl;

    //apertura de archivo, ab es para creacion y agrega recgistro, wb es escritura y rompe el que estaba.
    pEmpleado=fopen("empleados.dat", "rb");
    if(pEmpleado==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return;
    }

    //Asi se lee todos los registros del archivo

    while(fread(&obj, sizeof (Empleado), 1, pEmpleado)==1){
        obj.Mostrar();
        cout<<endl;
    }

    fclose(pEmpleado);
}

void mostrarPorCargo(){

    Empleado obj;
    FILE *pEmpleado;
    int cargo;
    bool encontro=false;


    //apertura de archivo, ab es para creacion y agrega recgistro, wb es escritura y rompe el que estaba.
    pEmpleado=fopen("empleados.dat", "rb");
    if(pEmpleado==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return;
    }

    cout<<"Ingrese el cargo a mostrar: ";
    cin>>cargo;

    //Asi se lee todos los registros del archivo

    while(fread(&obj, sizeof (Empleado), 1, pEmpleado)==1){
        if(obj.getCargo()==cargo){
            obj.Mostrar();
            encontro=true;
            cout<<endl;
        }
    }
    if(encontro==false){
        cout<<"No se encontro registro con ese numero de cargo"<<endl;
    }

    fclose(pEmpleado);

}

//BAJA LOGICA, O CAMBIO DE ALGUN ATRIBUTO, DATO DE UN REGISTRO A PARTIR DE UN DATO IDENTIFICATORIO. ESTE CASO DNI
//Para baja logica necesitamos:1 funcion para buscar registro que retorna una posicion y una funcion que devuelva un objeto tipo clase, donde recibe por parametro la posicion luego usamos la funcion sobreescribir registro
// 1
int buscarRegistro(int dni){
    Empleado obj;
    FILE *pEmpleado;
    int pos=0;
    pEmpleado=fopen("empleados.dat","rb");
    if(pEmpleado==NULL){
        return -2;
    }
    while(fread(&obj, sizeof (Empleado), 1, pEmpleado)==1){
        if(obj.getDni()==dni){
            fclose(pEmpleado);
            return pos;
        }
        pos++;
    }
    fclose(pEmpleado);
    return -1;
}

//2

Empleado leerRegistro(int pos){
    Empleado obj;
    FILE *pEmpleado;

    if (pos<0){
        obj.setDni(-3);
        return obj;
    }
    pEmpleado=fopen("empleados.dat", "rb");
    if(pEmpleado==NULL){
        return obj;
    }
    fseek(pEmpleado, sizeof (Empleado) * pos, 0);
    int aux=fread(&obj, sizeof (Empleado), 1, pEmpleado);
    fclose(pEmpleado);
    if(aux==0){
        obj.setDni(-1);
    }
    return obj;

}

void sobreEscribirRegistro(Empleado obj, int pos){
    FILE *pEmpleado;

    pEmpleado=fopen("empleados.dat", "rb+");
    if(pEmpleado==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return;
    }
    fseek(pEmpleado, sizeof (Empleado) * pos, 0);


    fwrite(&obj,sizeof (Empleado),1,pEmpleado);

    fclose(pEmpleado);



}





void bajaLogica(){
    int dni;
    int pos;
    Empleado obj;


    cout<<"Ingrese el DNI del empleado a eliminar ";
    cin>>dni;

    //1- a la variable pos, le asigno lo que retorne (variable pos)la primera funcion que necesitamos: buscarRegistro(dni) , por parametro va la propiedad que usamos para buscar.

    pos=buscarRegistro(dni);
    if(pos==-1){
        cout<<"No existe empleado con ese DNI"<<endl;
        return;
    }
    if(pos==-2){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return;
    }

   //2- a la variable obj, le asigno lo que me retorne (variable clase) la funcion segunda que necesitamos: leerRegistro(pos) por parametro va lo que retorna la primera funcion que es la pocicion
    obj=leerRegistro(pos);

    if(obj.getDni()==-3||obj.getDni()==-1)
        cout<<"DNI no encontrado"<<endl;

    if(obj.getEstado()==false){
        cout<<"EL empleado ya esta dado de baja"<<endl;
        return;
    }

    //cambiamos ese atributo que queremos cambiar, en este caso el estado.
    obj.setEstado(false);

    //3- luego usamos la funcion sobreEscribirRegistro(obj, pos), recibe el objeto con el atributo cambiado y la posicion.
    sobreEscribirRegistro(obj,pos);
    cout<<"Baja realizada"<<endl;
}


void bajaFisica(){
    Empleado obj;
    FILE *pE, *pB;
    int dni;

    cout<<"Ingrese DNI a eliminar definitivamente: ";
    cin>>dni;

    //hago copia de seguridad
    pE=fopen("empleados.dat", "rb");
    if(pE==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return;
    }
    pB=fopen("empleados.bak", "wb");
    if(pB==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        fclose(pE);
        return;
    }
    while(fread(&obj, sizeof obj, 1, pE)==1){
        fwrite(&obj, sizeof obj, 1, pB);
	}
	fclose(pB);
	fclose(pE);
	// FIN DE COPIA DE SEGURIDAD

	//cosntruccion del archivo sin los registros que quiero borrar
	pB=fopen("empleados.bak", "rb");
    if(pB==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return;
    }
    pE=fopen("empleados.dat", "wb");
    if(pB==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        fclose(pB);
        return;
    }



	while(fread(&obj, sizeof obj, 1, pB)==1){
        if(obj.getDni()==dni){
           fwrite(&obj, sizeof obj, 1, pE);
        }
	}

fclose(pE);
fclose(pB);
}

void modificarDomicilio(){

    int dni;
    int pos;
    Empleado obj;


    cout<<"Ingrese el DNI del empleado a cambiar el domicilio ";
    cin>>dni;

    //1- a la variable pos, le asigno lo que retorne (variable pos)la primera funcion que necesitamos: buscarRegistro(dni) , por parametro va la propiedad que usamos para buscar.

    pos=buscarRegistro(dni);
    if(pos==-1){
        cout<<"No existe empleado con ese DNI"<<endl;
        return;
    }
    if(pos==-2){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return;
    }

   //2- a la variable obj, le asigno lo que me retorne (variable clase) la funcion segunda que necesitamos: leerRegistro(pos) por parametro va lo que retorna la primera funcion que es la pocicion
    obj=leerRegistro(pos);

    if(obj.getDni()==-3||obj.getDni()==-1)
        cout<<"DNI no encontrado"<<endl;

    if(obj.getEstado()==false){
        cout<<"EL empleado ya esta dado de baja"<<endl;
        return;
    }

    //cambiamos ese atributo que queremos cambiar, en este caso el domicilio

    cout<<"Ingrese la nueva direccion: ";
    char pal[30];
    cargarCadena(pal, 29);

    obj.setDomicilio(pal);




    //3- luego usamos la funcion sobreEscribirRegistro(obj, pos), recibe el objeto con el atributo cambiado y la posicion.
    sobreEscribirRegistro(obj,pos);
    cout<<"Cambio de domicilio realizado"<<endl;
}

#endif // FUNCIONES_H_INCLUDED
