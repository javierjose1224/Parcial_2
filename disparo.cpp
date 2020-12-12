#include "disparo.h"

float disparo::getXo() const
{
    return Xo;
}

float disparo::getYo() const
{
    return Yo;
}


float disparo::getRad() const
{
    return rad;
}

disparo::disparo(float Xo_, float Yo_, float rad_)
{
    Xo=Xo_;
    Yo=Yo_;
    rad=rad_;
}
