#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <string>
#include <Diccionario.h>
#include <Letra.h>
// #include <Conjunto_Letras.h>
#include <Bolsa_Letras.h>
#include <random>

using namespace std;

int main(int argc, char * argv[]){
    if (argc != 5){
        cout << "El primer argumento debe ser el diccionario, el segundo el fichero con las letras, el tercero el numero de fichas aleatorias a generar y el cuarto el tipo de juego." << endl;
        return 0;
    }

    srand(time(NULL));
    string seguirjugando = "S";
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

    while (seguirjugando == "S" || seguirjugando == "s"){
    jugador = juego.GenerarLetrasJugador(atoi(argv[3]));

    cout << jugador << endl;

    string solucion;

    cout << "Dime tu solución, introduzca no_hay si cree que no hay ninguna solucion" << endl;
    cin >> solucion;

    while ((solucion != "no_hay") && (!jugador.PuedoFormar(solucion) || !D.Esta(solucion))){
        cout << "Esa palabra no es valida, por favor introduzca su solucion de nuevo" << endl;
        cin >> solucion;
    }

    if ( (char) *argv[4] == 'L'){
        cout << "Mi solución es " << endl;
        vector <string> soljuego = jugador.PalabraMasLarga(D);
        for (int i = 0; i < soljuego.size(); i++)
            cout << soljuego[i] << endl;
    }

    else if ( (char) *argv[4] == 'P'){
        if (solucion != "no_hay");
            cout << "Tu solucion: " << solucion << "\t Puntuacion: " << jugador.CalcularPuntos(solucion) << endl;

        cout << "Mi solución es " << endl;
        vector <string> soljuego = jugador.PalabraMasPuntos(D);
        for (int i = 0; i < soljuego.size(); i++)
            cout << soljuego[i] << "\t Puntuacion: " << jugador.CalcularPuntos(soljuego[i]) << endl;
    }

    else{
        cout << "Error en el argumento, no existe ese modo de juego" << endl;
        return 0;
    }

    cout << "Quieres seguir jugando? [S/N]" << endl;
    cin >> seguirjugando;
    }

    cout << "Ha terminado el juego" << endl;
    return 0;





}
