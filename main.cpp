#include <iostream>
#include "disparo.h"
#define G 9.81
#define pi 3.141617

using namespace std;

void generar_Disparo_Ofensivo(disparo Do,disparo Dd);
void generar_Disparo_Defensivo(disparo Do,disparo Dd);

void ImprimirResultados(int angle,int V0o,float x,float y,int t);

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
    cout<<"Ingrese la posicion en y del canion defensivo: ";
    cin>>PYd0;

    disparo Do(PXo0,PYo0,distancia*0.05),Dd(distancia+Do.getXo(),PYd0,distancia*0.025);
    //generar_Disparo_Ofensivo(Do,Dd);
    generar_Disparo_Defensivo(Do,Dd);
    return 0;
}

void generar_Disparo_Ofensivo(disparo Do,disparo Dd)
{
    float x,y;
    float V0x,V0y;
    int ban=0;
    for(float Vo=0;;Vo=Vo+0.5)
    {
        for(float angle=0;angle<90;angle=angle+0.5)
        {
            V0x = Vo*cos(angle*pi/180);
            V0y = Vo*sin(angle*pi/180);
            y=0;
            x=0;
            for(float t=0;;t=t+0.5)
            {
                y=Do.getYo()+V0y*t-(0.5*G*t*t);
                x=Do.getXo()+V0x*t;
                if(sqrt(pow((Dd.getXo() - x),2)+pow((Dd.getYo() - y),2)) <= Do.getRad())
                {
                    cout<<sqrt(pow((Dd.getXo() - x),2)+pow((Dd.getYo() - y),2));
                    ImprimirResultados(angle,Vo,x,y,t);                  
                    ban += 1;
                    Vo += 50;
                    break;
                }
                if(y<0)
                {
                    break;
                }

            }
            if(ban==3)
            {
                break;
            }
        }
        if(ban==3)
        {
            break;
        }
    }
    if(ban != 3){
        cout << "No impacto en los disparos esperados"<< endl;
    }
}

void generar_Disparo_Defensivo(disparo Do,disparo Dd)
{
    int ban=0;
    float x,y;
    float Vxd,Vyd;
    for(float Vdo=0;;Vdo=Vdo+0.5)
    {
        for(float angle=0;angle<90;angle=angle+0.5)
        {
            Vxd = Vdo*cos((angle+90)*pi/180);
            Vyd = Vdo*sin((angle+90)*pi/180);
            x = 0.0;
            y = 0.0;
            for(float t=0; ;t=t+0.5)
            {
                x = Dd.getXo()+Vxd*t;
                y = Dd.getYo()+Vyd*t-(0.5*G*t*t);
                if(sqrt(pow((Do.getXo()-x),2)+pow((Do.getYo()-y),2))<Dd.getRad())
                {
                    //if(y<0)y=0;
                    ImprimirResultados(angle,Vdo,x,y,t);
                    ban += 1;
                    Vdo += 50;
                    break;
                }
                if(y<0)
                {
                    break;
                }
            }
            if(ban==3) break;

        }
        if(ban==3) break;
    }
    if(ban!=3){
        cout << "No impacto en los disparos esperados"<< endl;
    }
}

void ImprimirResultados(int angle,int V0o,float x,float y,int t)
{
    cout << "Impacto con un angulo de " << angle << " grados" << endl;
    cout << "Impacto con velocidad incial " << V0o << endl;
    cout << "Impacto con posicion x: " << x << endl;
    cout << "Impacto con posicion y: " << y << endl;
    cout << "Con tiempo: " << t << endl;
    cout << endl;
}





