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
    if (!output){
        cout << "Error abriendo el archivo frecuencias" << endl;
        return 0;
    }

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
        else if (abc[i] < mini && abc[i] > 0)
            mini = abc[i];

    //mini = max(mini, 1);

    vector<int> puntuaciones(26);

    // #revisar #error YA ESTA CORREGIDO ESTO FUNCIONA BIEN PWERO LO DEJO PARA VER QUE TENGO QUE LIMPIAR EL DESASTRE DE CODIGO Y COMENTARIOS
    // ---------------------------------------------------------------------------------------------------------------
    //------------ ATENCION TENGO QUE CAMBIAR LO DE LOS PUNTOS QUE ASI ME DA UNDERFLOW EN CIERTOS DICCIONARIOS -------
    // ---------------------------------------------------------------------------------------------------------------
    // Esta aproximacion se hace asi porque como la frecuencia de letras es una exponencial negativa para hacerlo lineal se usa log
    for (int i = 0; i < puntuaciones.size(); i++)
    {
        //cout << maxi << " " << mini << " " << abc[i] << " LOL" << endl;
        /*cout << char(i+97) << " " << -log(abc[i]/(1.0*contador)) << endl;
        puntuaciones[i] =  (1.0*maxi - abc[i]) / (50*mini) + 1;*/
        if (abc[i] == 0)
            puntuaciones[i] = 0;
        else
            puntuaciones[i] = -log(abc[i]/(1.0*contador)) +0.5;
    }

    vector<int> cantidad(26);

    int numpiezas = 74; // 100-26 para que todas las letras aparezcan al menos una vez
    int cont = 0;
    int maximo = 0;
    for (int i = 0; i < cantidad.size(); i++){
        if (abc[i] == 0)
            cantidad[i] = 0;
        else
            cantidad[i] = floor(abc[i]/(1.0*contador)*numpiezas + 0.5)+1;
        cont += cantidad[i];
        if (cantidad[i] > maximo)
            maximo = i;
    }

    // #revisar
    //Quiero que haya el numero de piezas que quiero si o si y como mucho se añaden 2 o 3 piezas  que no cambia mucho la estadistica
    while (cont < 100){
        //cout << "hola" << endl;
        cantidad[maximo]++;
        cont++;
    }
    // #revisar
    // QUITAR ESTO DEL CONT ANTES D ENTREGAAAAAAAAAAAAR
    cout << cont << endl;

    output.open(letras);

    if (!output){
        cout << "Error abriendo el archivo letras" << endl;
        return 0;
    }

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

