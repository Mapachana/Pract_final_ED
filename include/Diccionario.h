#ifndef __Diccionario_h__
#define __Diccionario_h__


#include <set>
#include <vector>
#include <string>

using namespace std;

class Diccionario{
private:
    set<string> datos;

public:
    /**
     * @brief : Construye un diccionario vacío.
     */
    Diccionario();
    /**
     * @brief : Devuelve el numero de palabras en el diccionario.
     * @return : Numero de palabras en el diccionario.
     */
    int size() const;
    /**
     * @brief : Obtiene todas las palabras en el diccionario de una longitud dada.
     * @param : longitud : La longitud de las palabras de salida.
     * @return : Vector con las palabras de la longitud especificada por el parametro.
     */
    vector<string> PalabrasLongitud (int longitud);
    /**
     * @brief : Indica si una palabra esta en el diccionario o no.
     * @param : palabra : La palabra que se quiere buscar.
     * @return : True si la palabra esta en el diccionario y false en caso contrario.
     */
    bool Esta (string palabra);
    /**
     * @brief Genera los ficheros letras.txt y frecuencias.txt
     * @param letras: Fichero letras.txt
     * @param frecuencias: Fichero frecuencias.txt
     * @return Devuelve true si se han generado correctamente y flase de lo contrario
     */
    bool GenerarFicheros (string letras, string frecuencias);
    /**
     * @brief : Lee de un flujo de entrada un diccionario.
     * @param : is : Flujo de entrada.
     * @param : D : El objeto donde se realiza la lectura.
     * @return : Flujo de entrada.
     */
    friend istream& operator>> (istream & is, Diccionario & D);
    /**
     * @brief : Escribe en un flujo de salida un diccionario.
     * @param : os : Flujo de salida.
     * @param : D : El objeto diccionario que se escribe.
     * @return : Flujo de salida.
     */
    friend ostream& operator<< (ostream & os, const Diccionario & D);


    class iterator{
    private:
        set<string>::iterator it;
    public:
        /**
         * @brief : Construye un diccionario vacío.
         */
        iterator();
        /**
         * @brief : Devuelve a que esta apuntando el iterador.
         * @return : Palabra a la que apunta el iterador.
         */
        string operator* ();
        /**
         * @brief : Incrementa en una unidad el iterador.
         * @return : Iterador siguiente.
         */
        iterator & operator++ ();
        /**
         * @brief : Commpara si dos iteradores son iguales.
         * @param i : Iterador con el que se compara.
         * @return : Devuelve true si son iguales y false en caso contrario.
         */
        bool operator== (const iterator &i);
        /**
         * @brief : Commpara si dos iteradores son distintos.
         * @param i : Iterador con el que se compara.
         * @return : Devuelve true si son diferentes y false si son iguales.
         */
        bool operator!= (const iterator &i);
        friend class Diccionario;
    };

    /**
     * @brief : Apunta al comienzo del objeto.
     * @return : Devuelve un iterador apuntando al principio del objeto.
     */
    iterator begin() const;
    /**
     * @brief : Apunta al final del objeto.
     * @return : Devuelve un iterador apuntando al final del objeto.
     */
    iterator end() const;


};


#endif // __Diccionario_h__
