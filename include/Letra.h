#ifndef __Letra_h__
#define __Letra_h__


#include <iostream>
#include <Conjunto_Letras.h>

using namespace std;

class Letra{
private:
    char letra;
    int cantidad;
    int puntos;
public:
    Letra();
    getletra() const;
    getcantidad() const;
    getpuntos() const;
    setletra(char l);
    setcantidad(int c);
    setpuntos(int p);
    Letra& operator=(const Letra & l);
    friend istream & operator>>(istream & is, Letra & l);

    // Va a hacer algo tipo la funcion siguiente:
    /*
    {
    os << letra    cantidad     puntos
    }*/

    friend ostream & operator<<(ostream & os, const Letra & l);
    friend class Conjunto_Letras;
};

#endif // __Letra_h__
