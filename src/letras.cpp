#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <string>
#include <Diccionario.h>
#include <Letra.h>
#include <Conjunto_Letras.h>
#include <Bolsa_Letras.h>
#include <random>

using namespace std;

int main(int argc, char * argv[]){
    if (argc != 5){
        cout << "El primer argumento debe ser el diccionario, el segundo el fichero con las letras, el tercero el numero de fichas aleatorias a generar y el cuarto el tipo de juego." << endl;
        return 0;
    }

    //srand(time(NULL));
    srand(12352452);
    ifstream diccionario;
    diccionario.open(argv[1]);

    if (!diccionario){
        cout << "Error abriendo el archivo de diccionario" << endl;
        return 0;
    }

    Diccionario D;

    cout << "Leyendo diccionario" << endl;
    diccionario >> D;

    cout << "Generando ficheros" << endl;
    D.GenerarFicheros(argv[2],"./data/frecuencias.txt");

    Bolsa_Letras juego;

    ifstream letras;
    letras.open(argv[2]);

    if (!letras){
        cout << "Error abriendo el archivo de letras" << endl;
        return 0;
    }

    cout << "Leyendo fichero de letras" << endl;
    letras >> juego;

    Bolsa_Letras jugador;

    jugador = juego.GenerarLetrasJugador(atoi(argv[3]));

    cout << jugador << endl;

    string solucion;

    cout << "Dime tu solución" << endl;
    cin >> solucion;
    // #revisar DEBERIA COMPROBAR QUE LO QUE METE LA PERSONA ES VALIDO

    if ( (char) *argv[4] == 'L'){
        cout << "Mi solución es " << endl;
        vector <string> soljuego = jugador.PalabraMasLarga(D);
        for (int i = 0; i < soljuego.size(); i++)
            cout << soljuego[i] << endl;
    }

    else if ( (char) *argv[4] == 'P'){
        cout << "Mi solución es " << endl;
        vector <string> soljuego = jugador.PalabraMasPuntos(D);
        for (int i = 0; i < soljuego.size(); i++)
            cout << soljuego[i] << endl;
    }

    else{
        cout << "Error en el argumento, no existe ese modo de juego" << endl;
        return 0;
    }

    cout << endl << argv[4] << endl;

    cout << "Ha terminado el juego" << endl;
    return 0;





}
