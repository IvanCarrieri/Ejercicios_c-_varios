#ifndef CLASEFECHA_H_INCLUDED
#define CLASEFECHA_H_INCLUDED

class Fecha
{
private:
    int dia, mes, anio;
public:
    void Cargar();
    void Mostrar();
    bool fechaActual(int d, int m, int a);
    bool fechaValida(int d, int m, int a);


    void setDia(int x)
    {

        while (x<1 || x>31)
        {
            cout<<"Dia no valido, ingrese nuevamente: ";
            cin>>x;
        }
        dia=x;
    }
    void setMes(int x)
    {
        while (x<1 || x>12)
        {
            cout<<"Mes no valido, ingrese nuevamente: ";
            cin>>x;
        }
        mes=x;
    }
    void setAnio(int x)
    {
        while (x<1900)
        {
            cout<<"Año no valido, ingrese nuevamente: ";
            cin>>x;
        }
        anio=x;
    }



    int getDia()
    {
        return dia;
    }
    int getMes()
    {
        return mes;
    }
    int getAnio()
    {
        return anio;
    }

};



bool Fecha::fechaActual(int d, int m, int a)
{
    time_t t = time(nullptr);
    tm* now = localtime(&t);


    if ((now->tm_year+1900) < a)
    {
        return false;
    }

    else if ((now->tm_year+1900) == a)
    {
        if ((now->tm_mon+1) < m)
        {
            return false;
        }
        else if ((now->tm_mon+1) == m)
        {
            if (now->tm_mday<d)
            {
                return false;
            }
        }
    }

    return true;

}

bool Fecha::fechaValida(int d, int m, int a)
{
    if (m==2)
    {
        if ((a%4==0 && a%100!=0) || a%400==0)
        {
            if (dia>29)
            {
                return false;
            }
        }
        else if(dia>28)
        {
            return false;
        }
    }
    else if (m==4 || m==6 || m==9 || m==11)
    {
        if (d>30)
        {
            return false;
        }
    }

    return true;

}

void Fecha::Cargar()
{
    bool valida=false;
    bool actual=false;
    while(valida==false || actual==false)
    {

        cout<<"Fecha:"<<endl;
        int d, m, a;
        cout<<"DIA: ";
        cin>>d;
        setDia(d);
        cout<<"MES: ";
        cin>>m;
        setMes(m);
        cout<<"AÑO: ";
        cin>>a;
        setAnio(a);

        valida=fechaValida(d, m, a);
        actual=fechaActual(d, m, a);

        if (valida==false)
        {
            cout<<"La fecha ingresada no es válida, por favor ingrese nuevamente la fecha"<<endl;

        }
        else {
            if (actual==false)
            {
            cout<<"La fecha ingresada es mayor a la actual, por favor ingrese nuevamente la fecha"<<endl;
            }
        }

    }


}
void Fecha::Mostrar()
{
    cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
}



#endif // CLASEFECHA_H_INCLUDED
