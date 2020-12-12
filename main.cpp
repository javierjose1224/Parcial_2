#include <iostream>
#include "disparo.h"

using namespace std;

void generar_Disparo_Ofensivo(disparo Do,disparo Dd);

int main()
{
    float distancia,PXo0,PYo0,PYd0;
    cout<<"Ingrese la posicion en x del canion ofensivo: ";
    cin>>PXo0;
    cout<<"Ingrese la posicion en y del canion ofensivo: ";
    cin>>PYo0;
    cout<<"Ingrese la distancia del canion ofensivo con respecto al defensivo: ";
    cin>>distancia;
    cout<<"Ingrese la posicion en y del canion ofensivo: ";
    cin>>PYd0;

    disparo Do(PXo0,PYo0,distancia*0.05),Dd(distancia,PYd0,distancia*0.025);

    generar_Disparo_Ofensivo(Do,Dd);

    return 0;
}

void generar_Disparo_Ofensivo(disparo Do,disparo Dd)
{



}
