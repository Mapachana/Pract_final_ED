#include <iostream>
#include <vector>
#include <Letra.h>
#include <Diccionario.h>
#include <Conjunto_Letras.h>
#include <string>

using namespace std;

Conjunto_Letras::Conjunto_Letras(){}

Conjunto_Letras& Conjunto_Letras::operator=(const Conjunto_Letras & c){
    abecedario = c.abecedario;
}

void Conjunto_Letras::aniadir (const Letra& l){
    bool existe = false;
    for (int i = 0; i < abecedario.size(); i++)
        if (abecedario[i] == l)
            existe = true;
    if (!existe)
        abecedario.push_back(l);
}

istream & operator>> (istream & is, Conjunto_Letras & c){
    string cabecera;
    getline(is, cabecera);
    Letra aux;

    while(is >> aux)
        c.aniadir(aux);

    return is;
}
ostream & operator<< (ostream & os, const Conjunto_Letras & c){
    os << "#Letra\t Cant\t Puntuacion" << endl;
    for (int i = 0; i < c.abecedario.size(); i++)
        os << c.abecedario[i] << endl;

    return os;
}
