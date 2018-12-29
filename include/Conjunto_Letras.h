#ifndef __Conjunto_Letras_h__
#define __Conjunto_Letras_h__


#include <iostream>
#include <vector>
#include <Letra.h>
//#include <Diccionario.h>

using namespace std;

class Conjunto_Letras{
private:
    vector<Letra> abecedario;
public:
    Conjunto_Letras();
    Conjunto_Letras& operator= (const Conjunto_Letras & c);
    void aniadir (const Letra& l);
    friend istream & operator>> (istream & is, Conjunto_Letras & c);
    friend ostream & operator<< (ostream & os, const Conjunto_Letras & c);
    //friend bool Ordenador(const Letra & l1, const Letra & l2{ return l1-puntos < l2.puntos};
    //friend class Diccionario;
};


#endif // __Conjunto_Letras_h__
