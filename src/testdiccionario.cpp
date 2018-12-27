#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <string>
#include <Diccionario.h>

using namespace std;

int main(int argc, char * argv[]){
    if (argc != 2){
        cout << "El primer argumento debe ser el fichero con las palabras." << endl;
        return 0;
    }

    ifstream entrada;
    entrada.open(argv[1]);

    if (!entrada){
        cout << "Error abriendo el archivo" << endl;
        return 0;
    }

    Diccionario D;

    cout << "Leyendo diccionario" << endl;
    entrada >> D;
    cout << "Diccionario leido:" << endl;
    cout << D << endl;

    int longitud;
    cout << "Dime la longitud de palabras que quieres ver" << endl;
    cin >> longitud;

    vector<string> v = D.PalabrasLongitud(longitud);

    cout << "Palabras de longitud " << longitud << endl;
    for (unsigned int i = 0; i < v.size(); i++)
        cout << v[i] << endl;

    string palabra;

    cout << "Dime una palabra a buscar" << endl;
    cin >> palabra;

    if (D.Esta(palabra))
        cout << "La palabra esta" << endl;
    else
        cout << "La palabra no esta" << endl;

    D.GenerarFicheros("letras.txt","patatas");
}
