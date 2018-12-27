#include <Diccionario.h>
#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

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

bool Diccionario::GenerarFicheros(string letras, string frecuencias){
    ofstream output;

    vector<int> abc(26,0);
    int contador = 0;

    for(auto palabra:datos){
        for(auto letra:palabra){
          abc[int(letra) - 97]++;
        }
        contador += palabra.size();
    }

    output.open(frecuencias);

    output << "#Letra\t F abs\t F rel" << endl;

    for(int i = 0; i < abc.size(); i++){
        output << char(i+97) << "\t" << abc[i] << "\t" << abc[i]/(1.0*contador) << endl;
    }

    output.close();

    int maxi = 0;
    int mini = 999999;
    for(int i = 0; i < abc.size(); i++)
        if (abc[i] > maxi)
            maxi = abc[i];
        else if (abc[i] < mini)
            mini = abc[i];

    vector<int> puntuaciones = abc;

    for (int i = 0; i < puntuaciones.size(); i++)
        puntuaciones[i] = (1.0*maxi - abc[i]) / (50*mini) + 1;

    vector<int> cantidad = abc;

    int numpiezas = 74; // 100-26 para que todas las letras aparezcan al menos una vez
    int cont = 0;
    int maximo = 0;
    for (int i = 0; i < cantidad.size(); i++){
        cantidad[i] = floor(cantidad[i]/(1.0*contador)*numpiezas + 0.5)+1;
        cont += cantidad[i];
        if (cantidad[i] > maximo)
            maximo = i;
    }

    if (cont < 100){
        cantidad[maximo]++;
        cont++;
    }
    // QUITAR ESTO DEL CONT ANTES D ENTREGAAAAAAAAAAAAR
    cout << cont << endl;

    output.open(letras);

    output << "#Letra\t Cant\t Puntuacion" << endl;

    for(int i = 0; i < abc.size(); i++){
        output << char(i+97) << "\t" << cantidad[i] << "\t" << puntuaciones[i] << endl;
    }

    output.close();
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

