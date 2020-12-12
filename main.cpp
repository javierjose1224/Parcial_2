#include <iostream>
#include "disparo.h"

using namespace std;

int main()
{
    float distancia,PXo,PYo,PYd;
    cout<<"Ingrese la posicion en x del canion ofensivo: ";
    cin>>PXo;
    cout<<"Ingrese la posicion en y del canion ofensivo: ";
    cin>>PXo;
    cout<<"Ingrese la distancia del canion ofensivo con respecto al defensivo: ";
    cin>>distancia;
    cout<<"Ingrese la posicion en y del canion ofensivo: ";
    cin>>PYd;
    disparo Do(PXo,PYo),Dd(distancia,PYd);



    return 0;
}
