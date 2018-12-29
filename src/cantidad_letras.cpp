#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <string>
#include <Diccionario.h>

using namespace std;

int main(int argc, char * argv[]){
    if (argc != 4){
        cout << "El primer argumento debe ser el diccionario a usar, el segundo el fichero de las letras y el tercero argumento el fichero de las frecuencias." << endl;
        return 0;
    }

    ifstream entrada;
    entrada.open(argv[1]);

    if (!entrada){
        cout << "Error abriendo el diccionario" << endl;
        return 0;
    }

    Diccionario D;

    cout << "Leyendo diccionario" << endl;
    entrada >> D;
    cout << "Diccionario leido" << endl;

    cout << "Generando ficheros" << endl;

    D.GenerarFicheros(argv[2],argv[3]);
}
