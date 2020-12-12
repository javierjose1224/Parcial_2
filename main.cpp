#include <iostream>
#include "disparo.h"
#define G 9.81
#define pi 3.141617

using namespace std;

void generar_Disparo_Ofensivo(disparo Do,disparo Dd);
void ImprimirResultados1(int angle,int V0o,float x,float y,int t);

void imprimir(disparo Do,disparo Dd);

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

    disparo Do(PXo0,PYo0,distancia*0.05),Dd(distancia+Do.getXo(),PYd0,distancia*0.025);
    generar_Disparo_Ofensivo(Do,Dd);

    return 0;
}

void generar_Disparo_Ofensivo(disparo Do,disparo Dd)
{
    float x,y;
    float V0x,V0y;
    bool ban=false;
    for(float Vo=0;;Vo++)
    {
        for(int angle=0;angle<90;angle++)
        {
            V0x = Vo*cos(angle*pi/180);
            V0y = Vo*sin(angle*pi/180);
            y=0;
            x=0;
            for(int t=0;;t++)
            {
                y=Do.getYo()+V0y*t-(0.5*G*t*t);
                x=Do.getXo()+V0x*t;
                if(sqrt(pow((Dd.getXo() - x),2)+pow((Dd.getYo() - y),2)) < Do.getRad())
                {
//                    if(y<0)
//                    {
//                        y = 0;
//                    }
                    ImprimirResultados1(angle,Vo,x,y,t);
                    ban=true;
                    break;
                }
                if(y<0)
                {
                    break;
                }
            }
            if(ban==true)
            {
                break;
            }
        }
        if(ban==true)
        {
            break;
        }
    }
    cout<<"salio";
}

void ImprimirResultados1(int angle,int V0o,float x,float y,int t)
{
    cout << "Impacto con un angulo de " << angle << " grados" << endl;
    cout << "Impacto con velocidad incial " << V0o << endl;
    cout << "Impacto con posicion x: " << x << endl;
    cout << "Impacto con posicion y: " << y << endl;
    cout << "Con tiempo: " << t << endl;
    cout << endl;
}





