#ifndef DISPARO_H
#define DISPARO_H
#define G 9.8

class disparo
{
private:
    float Xo;
    float Yo;
    float Vo;
    float Vox;
    float Voy;
    float angulo;
    float rad;

public:

    disparo(float Xo_,float Yo_,float rad_);

    float getXo() const;
    float getYo() const;
    float getRad() const;

};

#endif // CANION_H
