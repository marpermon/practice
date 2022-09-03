#include <iostream>
#include <stdlib.h>

using namespace std;

float evaluar_costos_llamda(int t, float* costo)
{
    if (t<2) *costo = 0.45;
    else *costo = 0.4+(((float)t-1)/4);
    }

int menor(int a, int b)
    {
        int x = a>b ? b:a;
        return x ;
    }

int menor_de_tres(int a, int b, int c)
    {
        if ((b >= a) && (c >= a)) return a;
        else if ((a >= b) && (c >= b))return a;
        else return c;
    }

int sumatoria (int a)
{
    int x=0;
    for (int i = 0; i <=a; i++)  x += i;
    return x;
}

int sumatoria_5 (int a)
{
    int x=0;
    for (int i = 0; i <=a; i++)
    { if (i%5==0) x += i;}
    return x;
}

typedef struct Seguro_social
{
string nombre;
int cedula;
string direccion;
bool asegurado_directo;

    Seguro_social(string Nombre, int Cedula,string Direccion,bool Asegurado_directo):
    nombre{Nombre},cedula{Cedula},direccion{Direccion}, asegurado_directo{Asegurado_directo}{}
}Seguro_social;

void inic(Seguro_social* a)
{
    cout << "Nombre: ";
    getline(cin,a -> nombre);
    cout << "Cedula: ";
    cin>>a -> cedula;
    cout << "Direccion: ";
    cin.clear(); cin.sync(); //tiene algo que ver con limpiar el buffer para usar la funcion getline y la funcion cin, no sé a qué se refería
    getline(cin, a -> direccion);
    cout << "Asegurado directo: ";
    string dic;
    cin>>dic;
    if (dic == "si") a -> asegurado_directo = true;
    else if (dic=="no") a -> asegurado_directo = false;
}

void print(Seguro_social a)
{
    cout << "Nombre: "<< a.nombre << endl;
    cout << "Cedula: "<< a.cedula << endl;
    cout << "Direccion: "<< a.direccion << endl;
    cout << "Asegurado directo: ";
    string dic;
    dic =a.asegurado_directo==true? "si":"no";
    cout << dic<< endl;
}
#define LLAMADA
int main()
{
    #ifdef NUMEROS
    cout << menor (100,5) << endl;
    cout << menor_de_tres (3,5,5) << endl;
    cout << sumatoria (0) << endl;
    cout << sumatoria_5 (10) << endl;
    #endif // NUMEROS

    #ifdef LLAMADA
    int t;
    float costo;
    float *pcosto=&costo;
    cout << "Ingrese la duracion de su llamada en minutos: ";
    cin>>t;
    evaluar_costos_llamda(t,pcosto);
    cout << "El costo de su llamada es de $"<<costo << endl;
    #endif // LLAMADA

    #ifdef SEGURO
    Seguro_social Aseg1("Tim LaFleur",18371434,"en mi casa",true);
    Seguro_social Aseg2("Panshio",583457,"en su casa",false);
    Seguro_social Aseg3("Justo Bolsa",348378,"ningun lugar",true);
    print(Aseg1);
    Seguro_social* P=&Aseg3;
    inic(P);
    print(Aseg3);
    #endif // SEGURO
        return 0;
}




