#include <iostream>
#include <Letra.h>

using namespace std;


Letra::Letra(){}

char Letra::getletra() const{
    return letra;
}

int Letra::getcantidad() const{
    return cantidad;
}

int Letra::getpuntos() const{
    return puntos;
}

bool Letra::setletra(char l){
    if ( 'a' <= l && l <= 'z'){
        letra = l;
        return true;
    }
    else
        return false;
}

bool Letra::setcantidad(int c){
    if (c >= 0){
        cantidad = c;
        return true;
    }
    else
        return false;
}

bool Letra::setpuntos(int p){
    if (p >= 0){
        puntos = p;
        return true;
    }
    else
        return false;
}

bool Letra::operator==(const Letra& l){
    if (letra == l.letra)
        return true;
    else
        return false;
}

bool Letra::operator!=(const Letra& l){
    if (letra != l.letra)
        return true;
    else
        return false;
}

Letra& Letra::operator=(const Letra & l){
    letra = l.letra;
    cantidad = l.cantidad;
    puntos = l.puntos;

    return *this;
}

istream & operator>>(istream & is, Letra & l){
    is >> l.letra;
    is >> l.cantidad;
    is >> l.puntos;

    return is;
}

ostream & operator<<(ostream & os, const Letra & l){
    os << l.letra << "\t" << l.cantidad << "\t" << l.puntos;

    return os;
}
