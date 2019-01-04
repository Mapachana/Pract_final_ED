#include <iostream>
#include <vector>
#include <Letra.h>
#include <Diccionario.h>
#include <string>
#include <Bolsa_Letras.h>
#include <random>
#include <algorithm>

using namespace std;


Bolsa_Letras::Bolsa_Letras(){}

Bolsa_Letras& Bolsa_Letras::operator=(const Bolsa_Letras & b){
    bolsa = b.bolsa;
}

void Bolsa_Letras::aniadir (const Letra& l){
    bool existe = false;
    for (int i = 0; i < bolsa.size(); i++)
        if (bolsa[i] == l)
            existe = true;
    if (!existe)
        bolsa.push_back(l);
}

void Bolsa_Letras::aniadirficha(Letra l){
    bool existe = false;
    for (int i = 0; i < bolsa.size(); i++)
        if (bolsa[i] == l)
            existe = true;
        if (!existe){
            l.setcantidad(1);
            bolsa.push_back(l);
        }
        else{

            int pos = distance(bolsa.begin(), find(bolsa.begin(), bolsa.end(), l));
            bolsa[pos].setcantidad(bolsa[pos].getcantidad()+1);
        }
}

Bolsa_Letras Bolsa_Letras::GenerarLetrasJugador(int num){
    Bolsa_Letras copia = *this;
    Bolsa_Letras jugador;
    int numfichas = 100;

    int contador = 0;
    bool terminado = false;

    for (int j = 0; j < num; j++){
        contador = 0;
        terminado = false;
        int randnum = rand() % (numfichas-j) + 1;

        for (int i = 0; i < copia.bolsa.size() && !terminado; i++){
            contador += copia.bolsa[i].getcantidad();
            if (randnum <= contador){
                jugador.aniadirficha(copia.bolsa[i]);
                copia.bolsa[i].setcantidad(copia.bolsa[i].getcantidad()-1);
                terminado = true;
            }
        }
    }

    return jugador;
}

bool Bolsa_Letras::PuedoFormar(string palabra){
    vector<char> letras;
    bool resultado = true;
    int pos;

    if (bolsa.size() < palabra.size())
        resultado = false;
    else{
        for (int i = 0; i < bolsa.size(); i++)
            for (int j = 0; j < bolsa[i].getcantidad(); j++)
                letras.push_back(bolsa[i].getletra());

        for (int i = 0; i < palabra.length() && resultado; i++) {
            pos = distance(letras.begin(), find(letras.begin(), letras.end(), palabra[i]) );

            if (pos != letras.size())
                letras.erase(letras.begin() + pos);
            else
                resultado = false;
        }
    }

    return resultado;
}

vector<string> Bolsa_Letras::PalabraMasLarga (const Diccionario & D){
    vector<string> resultado;
    int maxlong = 0;

    for (auto palabra:D){
            if (PuedoFormar(palabra))
                if (palabra.size() > maxlong){
                    maxlong = palabra.size();
                    resultado.clear();
                    resultado.push_back(palabra);
                }
                else if (palabra.size() == maxlong)
                    resultado.push_back(palabra);
    }

    return resultado;
}

vector<string> Bolsa_Letras::PalabraMasPuntos (const Diccionario &D){
    vector<string> resultado;
    int maxpuntos = 0;
    int contpuntos = 0;
    Letra aux;

    for(auto palabra:D){
        if (PuedoFormar(palabra)){
            contpuntos = CalcularPuntos(palabra);
            if (contpuntos > maxpuntos){
                maxpuntos = contpuntos;
                resultado.clear();
                resultado.push_back(palabra);
            }
            else if (contpuntos == maxpuntos)
                resultado.push_back(palabra);
        }
    }

    return resultado;
}

int Bolsa_Letras::CalcularPuntos (string palabra){
    int puntos = 0;
    Letra aux;
    int pos;

    for (int i = 0; i < palabra.length(); i++){
        aux.setletra(palabra[i]);
        pos = distance(bolsa.begin(), find(bolsa.begin(), bolsa.end(), aux));
        puntos += bolsa[pos].getpuntos();
    }

    return puntos;
}


istream & operator>> (istream & is, Bolsa_Letras & b){
    string cabecera;
    getline(is, cabecera);
    Letra aux;

    while(is >> aux)
        b.aniadir(aux);

    return is;
}
ostream & operator<< (ostream & os, const Bolsa_Letras & b){
    os << "Las letras son:   ";
    for (int i = 0; i < b.bolsa.size(); i++)
        for (int j = 0; j < b.bolsa[i].getcantidad(); j++)
            os << b.bolsa[i].getletra() << " ";

    return os;
}
