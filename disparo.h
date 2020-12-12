#ifndef CANION_H
#define CANION_H
#define G 9.8

class disparo
{
private:
    float posx;
    float posy;
    float Vo;
    float Vox;
    float Voy;
    float angulo;

public:
    disparo();
    disparo(float posx_,float posy_);
    void generarDisparo();

    float getPosx() const;
    void setPosx(float value);
    float getPosy() const;
    void setPosy(float value);

};

#endif // CANION_H
