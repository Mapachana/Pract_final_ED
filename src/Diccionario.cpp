#include <Diccionario.h>
#include <string>
#include <set>
#include <vector>
#include <iostream>

using namespace std;


Diccionario::Diccionario(){}

int Diccionario::size() const{
    return datos.size();
}

vector<string> Diccionario::PalabrasLongitud(int longitud){
    vector<string> aux;
    for (auto it:datos)
        if (it.size() == longitud)
            aux.push_back(it);

    return aux;
}

bool Diccionario::Esta(string palabra){
    bool resultado = true;
    if ( datos.find(palabra) == datos.end() )
        resultado = false;

    return resultado;
}

istream & operator>>(istream & is, Diccionario & D){
    string aux;

    while ( getline(is, aux) )
        D.datos.insert(aux);

    return is;
}

ostream & operator<<(ostream & os, const Diccionario & D){
    for (auto it:D.datos){
        os << it << endl;
    }

    return os;
}

Diccionario::iter::iter(){}

string Diccionario::iter::operator*(){
    return *it;
}

Diccionario::iter& Diccionario::iter::operator++(){
    ++it;
    return (*this);
}

bool Diccionario::iter::operator==(const iter & i){
    bool resultado = false;
    if (i.it == (*this).it)
        resultado = true;
    return resultado;
}

bool Diccionario::iter::operator!=(const iter &i){
    bool resultado = true;
    if (i.it == (*this).it)
        resultado = false;
    return resultado;
}

Diccionario::iter Diccionario::begin(){
    iter mi_iterador;
    mi_iterador.it = datos.begin();
    return mi_iterador;
}

Diccionario::iter Diccionario::end(){
    iter mi_iterador;
    mi_iterador.it = datos.end();
    return mi_iterador;
}

