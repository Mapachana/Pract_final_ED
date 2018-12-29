#ifndef __Letra_h__
#define __Letra_h__

// #revisar los includes si desscomento lo que hay no funciona y ya no recuerdo para que queria hacerlo friend

#include <iostream>
//#include <Conjunto_Letras.h>

using namespace std;

class Letra{
private:
    char letra;
    int cantidad;
    int puntos;
public:
    Letra();
    char getletra() const;
    int getcantidad() const;
    int getpuntos() const;
    bool setletra(char l);
    bool setcantidad(int c);
    bool setpuntos(int p);
    bool operator==(const Letra& l);
    Letra& operator=(const Letra & l);
    friend istream & operator>>(istream & is, Letra & l);
    friend ostream & operator<<(ostream & os, const Letra & l);
    //friend class Conjunto_Letras;
};

#endif // __Letra_h__
