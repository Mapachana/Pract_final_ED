#ifndef __Bolsa_Letras_h__
#define __Bolsa_Letras_h__


#include <iostream>
#include <vector>
#include <Letra.h>
#include <string>
#include <Diccionario.h>

class Bolsa_Letras{
private:
    vector<Letra> bolsa;
public:
    /**
     * @brief : Construye una Bolsa_Letras vacía
     */
    Bolsa_Letras();
    /**
     * @brief : Añade una Letra al Conjunto_Letras.
     * @param :  l : Letra que se quiere añadir.
     */
    void aniadir (const Letra& l);
     /**
     * @brief : Operador de asignacion.
     * @param :  b : Bolsa_Letras que se quiere asignar.
     * @return : Devuelve una referencia al objeto.
     */
    Bolsa_Letras& operator= (const Bolsa_Letras & b);
    /**
     * @brief : Añade una ficha a la bolsa (Aumenta la cantidad de esa letra en una unidad).
     * @param :  l : Letra que se añade.
     */
    void aniadirficha(Letra l);
    /**
     * @brief : Genera una bolsa de letras aleatoria.
     * @param :  num : Numero de letras que tendrá la bolsa.
     * @return : Bolsa_Letras aleatoria.
     */
    Bolsa_Letras GenerarLetrasJugador(int num);
    /**
     * @brief : Comprueba si se puede formar una palabra con el conjunto de letras actual.
     * @param :  palabra : Palabra que se quiere comprobar si puede ser formada.
     * @return : Devuelve true si puede formarse y false de lo contrario.
     */
    bool PuedoFormar(string palabra);
    /**
     * @brief : Busca la palabra mas larga que se puede formar con la Bolsa_Letras dado un diccionario.
     * @param :  D : Diccionario que recoge qué palabras son validas para formar.
     * @return : Devuelve un vector con las palabras mas largas que se pueden formar.
     */
    vector<string> PalabraMasLarga (const Diccionario & D);
    /**
     * @brief : Busca la palabra con mas puntos que se puede formar con la Bolsa_Letras dado un diccionario.
     * @param :  D : Diccionario que recoge qué palabras son validas para formar.
     * @return : Devuelve un vector con las palabras con mas puntos que se pueden formar.
     */
    vector<string> PalabraMasPuntos (const Diccionario &D);
    /**
     * @brief : Calcula los puntos de la palabra de acuerdo a la Bolsa_Letras actual.
     * @param :  palabra : Palabra a la que se quieren calcular los puntos.
     * @return : Devuelve el numero de puntos de esa palabra.
     */
    int CalcularPuntos (string palabra);
    /**
     * @brief : Lee de un flujo de entrada una Bolsa_Letras.
     * @param : is : Flujo de entrada.
     * @param : b : El objeto donde se realiza la lectura.
     * @return : Flujo de entrada.
     */
    friend istream & operator>> (istream & is, Bolsa_Letras & b);
     /**
     * @brief : Escribe en un flujo de salida una Bolsa_Letras.
     * @param : os : Flujo de salida.
     * @param : b : El objeto Bolsa_Letras que se escribe.
     * @return : Flujo de salida.
     */
    friend ostream & operator<< (ostream & os, const Bolsa_Letras & c);
};



#endif // __Bolsa_Letras_h__
