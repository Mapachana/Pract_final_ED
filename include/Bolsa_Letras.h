#ifndef __Bolsa_Letras_h__
#define __Bolsa_Letras_h__


#include <iostream>
#include <vector>
#include <Letra.h>
#include <Conjunto_Letras.h>
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
     * @brief : Construye una Bolsa_Letras a partir de un Conjunto_Letras
     * @param : c : Conjunto_Letras a partir del que se obtienen las cantidades y letras
     */
    Bolsa_Letras(const Conjunto_Letras & c);
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

    void aniadirficha(Letra l);

    Bolsa_Letras GenerarLetrasJugador(int num);

    bool PuedoFormar(string palabra);

    vector<string> PalabraMasLarga (const Diccionario & D);

    vector<string> PalabraMasPuntos (const Diccionario &D);

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
