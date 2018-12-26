#ifndef __Conjunto_Letras_h__
#define __Conjunto_Letras_h__


#include <iostream>
#include <vector>
#include <Letra.h>
#include <Diccionario.h>

using namespace std;

class Conjunto_Letras{
private:
    vector<Letra> abecedario;
public:
    Conjunto_Letras();
    Conjunto_Letras& operator= (const Conjunto_Letras & c);
    // No se si estas funciones tienen sentido o si deberia pasar el diccionario o que
    void CalcularCantidadLetras(const Diccionario & D);
    void CalcularPuntuacionLetras();
    friend istrea, & operator>> (istream & is, Conjunto_Letras & c);
    // Va a hacer algo tipo lo siguiente y asi escribe el fichero letras.txt:
    /*{
        os << #Letra     cantidad    Puntos
        os << abecedario[i]
        }*/
    // Para escribir el fichero frecuecias.txt lo hago directamente sobre la marcha o contra otra funcion y que sea
    // aparte antes de poner las cantidades fijas.
    friend ostream & operator<< (ostream & os, const Conjunto_Letras & c);
    friend bool Ordenador(const Letra & l1, const Letra & l2{ return l1-puntos < l2.puntos};
};


#endif // __Conjunto_Letras_h__
