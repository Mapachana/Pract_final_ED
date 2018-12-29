#ifndef __Conjunto_Letras_h__
#define __Conjunto_Letras_h__


#include <iostream>
#include <vector>
#include <Letra.h>
//#include <Diccionario.h>

using namespace std;

class Conjunto_Letras{
private:
    vector<Letra> abecedario;
public:
    /**
     * @brief : Construye un Conjunto_Letras vacío
     */
    Conjunto_Letras();
     /**
     * @brief : Operador de asignacion.
     * @param :  c : Conjunto_Letras que se quiere asignar.
     * @return : Devuelve una referencia al objeto.
     */
    Conjunto_Letras& operator= (const Conjunto_Letras & c);
     /**
     * @brief : Añade una Letra al Conjunto_Letras.
     * @param :  l : Letra que se quiere añadir.
     */
    void aniadir (const Letra& l);
    /**
     * @brief : Lee de un flujo de entrada un Conjunto_Letras.
     * @param : is : Flujo de entrada.
     * @param : c : El objeto donde se realiza la lectura.
     * @return : Flujo de entrada.
     */
    friend istream & operator>> (istream & is, Conjunto_Letras & c);
     /**
     * @brief : Escribe en un flujo de salida un Conjunto_Letras.
     * @param : os : Flujo de salida.
     * @param : c : El objeto Conjunto_Letras que se escribe.
     * @return : Flujo de salida.
     */
    friend ostream & operator<< (ostream & os, const Conjunto_Letras & c);
    //friend bool Ordenador(const Letra & l1, const Letra & l2{ return l1-puntos < l2.puntos};
    //friend class Diccionario;
};


#endif // __Conjunto_Letras_h__
