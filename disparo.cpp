#include "disparo.h"

float disparo::getPosx() const
{
    return posx;
}

void disparo::setPosx(float value)
{
    posx = value;
}

float disparo::getPosy() const
{
    return posy;
}

void disparo::setPosy(float value)
{
    posy = value;
}

disparo::disparo()
{

}

disparo::disparo(float posx_, float posy_)
{
    posx=posx_;
    posy=posy_;
}
