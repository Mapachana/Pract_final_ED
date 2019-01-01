#include <iostream>
#include <vector>
#include <Letra.h>
#include <Diccionario.h>
#include <Conjunto_Letras.h>
#include <string>
#include <Bolsa_Letras.h>
#include <random>
#include <algorithm>

using namespace std;

Bolsa_Letras::Bolsa_Letras(){}

/*Bolsa_Letras::Bolsa_Letras(const Conjunto_Letras & c){
    for (int i = 0, i < c.)
}*/

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
    Bolsa_Letras jugador;

    int contador = 0;
    bool terminado = false;

    for (int j = 0; j < num; j++){
        contador = 0;
        terminado = false;
        int randnum = rand() % (100-j) + 1;
        //cout << randnum << endl;
        for (int i = 0; i < bolsa.size() && !terminado; i++){
            contador += bolsa[i].getcantidad();
            if (randnum <= contador){
                jugador.aniadirficha(bolsa[i]);
                bolsa[i].setcantidad(bolsa[i].getcantidad()-1);
                terminado = true;
            }
        }
    }

    return jugador;
}

bool Bolsa_Letras::PuedoFormar(string palabra){
    vector<char> letras;
    bool resultado = true;

    for (int i = 0; i < bolsa.size(); i++)
        for (int j = 0; j < bolsa[i].getcantidad(); j++)
            letras.push_back(bolsa[i].getletra());

    for (int i = 0; i < palabra.length() && resultado; i++)
        if (find(letras.begin(), letras.end(), palabra[i]) != letras.end()){
            //cout << letras[i] << endl;
            letras.erase(letras.begin()+i);
        }
            //letras[i] = '2';
        else{
            resultado = false;
            //cout << "ENTRO AQUI CON LA PALABRA " << palabra << endl;
        }


    /*for (int i = 0; i < palabra.length(); i++)
        if (bolsa.find(palabra[i]) !0 bolsa.end())
            bolsa.erase(palabra[i]);*/

    return resultado;

}

vector<string> Bolsa_Letras::PalabraMasLarga (const Diccionario & D){
    vector<string> resultado;
    int maxlong = 0;

    for (auto palabra:D){
            if (palabra.size() <= bolsa.size() && PuedoFormar(palabra))
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
    int maxlong = bolsa.size();
    int cont = 0;
    Letra aux;

    for(auto palabra:D){
        if (palabra.size() <= maxlong && PuedoFormar(palabra)){
            cont = 0;
            for (auto letra:palabra){
                aux.setletra(letra);
                int pos = distance(bolsa.begin(), find(bolsa.begin(), bolsa.end(), aux));
                cont += bolsa[pos].getpuntos();
            }
            if (cont > maxpuntos){
                maxpuntos = cont;
                resultado.clear();
                resultado.push_back(palabra);
            }
            else if (cont == maxpuntos)
                resultado.push_back(palabra);
        }

    }

    return resultado;
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
    /*os << "#Letra\t Cant\t Puntuacion" << endl;
    for (int i = 0; i < b.bolsa.size(); i++)
        os << b.bolsa[i] << endl;

    return os;*/

    os << "Las letras son ";
    for (int i = 0; i < b.bolsa.size(); i++)
        for (int j = 0; j < b.bolsa[i].getcantidad(); j++)
            os << b.bolsa[i].getletra() << " ";

    return os;
}
