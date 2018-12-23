#include <Diccionario.h>

using namespace std;

#include <string>
#include <set>
#include <vector>

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

/*istream & operator>>(istream & is, const Diccionario & D){
    string aux;
    while (is >> aux){
        D.datos.insert(aux);
    }

    return is;
}*/

ostream & operator<<(ostream & os, const Diccionario & D){
    for (auto it:D.datos){
        os << it;
    }

    return os;
}
