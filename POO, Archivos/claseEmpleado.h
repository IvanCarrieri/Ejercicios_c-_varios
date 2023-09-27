#ifndef CLASEEMPLEADO_H_INCLUDED
#define CLASEEMPLEADO_H_INCLUDED

void cargarCadena(char *pal, int tam);


void cargarCadena(char *pal,int tam){

    int i;
    fflush(stdin);
    for(i=0;i<tam;i++){
        pal[i]=cin.get();
        if(pal[i]=='\n') break;
    }
    pal[i]='\0';
    fflush(stdin);
}

class Empleado{
private:
    int dni;
    char nombre[30];
    char apellido[30];
    char domicilio[30];
    char email[30];
    Fecha fechaNacimiento;
    int cargo;
    bool estado;
public:

    //constructor con valores por omision
    Empleado(int d=0, int c=0, const char *n="ivan"){
        dni=d;
        cargo=c;
        strcpy(nombre, n);
    }

    void Cargar();
    void Mostrar();

    void setDni(int d){dni=d;}
    void setNombre(char *n){strcpy(nombre, n);}
    void setApellido(char *a){strcpy(apellido, a);}
    void setDomicilio(char *d){strcpy(domicilio, d);}
    void setEmail(char *e){strcpy(email, e);}
    void setFechaNacimiento(Fecha f){fechaNacimiento=f;}
    void setCargo(int c){
        while(c<1 || c>10){
            cout<<"Numero de cargo invalido, ingrese nuevamente: ";
            cin>>c;
        }
        cargo=c;}
    void setEstado(bool e){estado=e;}

    int getDni(){return dni;}
    char* getNombre(){return nombre;}
    char* getApellido(){return apellido;}
    char* getDomicilio(){return domicilio;}
    char* getEmail(){return email;}
    Fecha getFechaNacimiento(){return fechaNacimiento;}
    int getCargo(){return cargo;}
    bool getEstado(){return estado;}

};

void Empleado::Cargar(){
    cout<<"Ingrese los datos requeridos"<<endl;
    int aux;

    cout<<"DNI: ";
    cin>>aux;
    setDni(aux);
    cout<<"Nombre: ";
    cargarCadena(nombre, 29);
    cout<<"Apellido: ";
    cargarCadena(apellido, 29);
    cout<<"Domicilio: ";
    cargarCadena(domicilio, 29);
    cout<<"Email: ";
    cargarCadena(email, 29);
    cout<<"Fecha de nacimiento: ";
    fechaNacimiento.Cargar();
    cout<<"Cargo: ";
    cin>>aux;
    setCargo(aux);
    setEstado(true);
    system("cls");

}

void Empleado::Mostrar(){

    if(estado==true){
        cout<<"DNI: ";
        cout<<getDni()<<endl;
        cout<<"Nombre: ";
        cout<<getNombre()<<endl;
        cout<<"Apellido: ";
        cout<<getApellido()<<endl;
        cout<<"Domicilio: ";
        cout<<getDomicilio()<<endl;
        cout<<"Email: ";
        cout<<getEmail()<<endl;
        cout<<"Fecha de nacimiento: ";
        fechaNacimiento.Mostrar();
        cout<<"Cargo: ";
        cout<<getCargo()<<endl;
    }



}

#endif // CLASEEMPLEADO_H_INCLUDED
