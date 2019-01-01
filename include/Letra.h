#ifndef __Letra_h__
#define __Letra_h__

// #revisar los includes si desscomento lo que hay no funciona y ya no recuerdo para que queria hacerlo friend

#include <iostream>
//#include <Conjunto_Letras.h>

using namespace std;

class Letra{
private:
    char letra;
    int cantidad;
    int puntos;
public:
    /**
     * @brief : Construye una Letra vacía
     */
    Letra();
    /**
     * @brief : Método observador de la letra.
     * @return : Devuelve la letra que se representa en Letra.
     */
    char getletra() const;
    /**
     * @brief : Método observador de la cantidad.
     * @return : Devuelve la cantidad de veces que está la Letra en la Bolsa.
     */
    int getcantidad() const;
    /**
     * @brief : Método observador de los puntos.
     * @return : Devuelve los puntos que vale la letra.
     */
    int getpuntos() const;
    /**
     * @brief : Asigna un valor de letra a Letra si es posible.
     * @param : l : letra que se quiere asignar (para ello debe ir de la a ... z).
     * @return : Devuelve true si la letra se ha asignado y false de lo contrario.
     */
    bool setletra(char l);
    /**
     * @brief : Asigna la cantidad de veces que aparece esta letra en la bolsa.
     * @param : c : Numero de veces que se quiere quqe aparezca (debe ser mayor o igual a 1).
     * @return : Devuelve true si la cantidad se ha asignado y false de lo contrario.
     */
    bool setcantidad(int c);
    /**
     * @brief : Asigna los puntos que vale la letra.
     * @param : p : Puntos que se quiere que valga (debe ser mayor o igual a 1).
     * @return : Devuelve true si los puntos se han asignado y false de lo contrario.
     */
    bool setpuntos(int p);
    /**
     * @brief : Comprueba si dos Letras son iguales, esto es, representan la misma letra.
     * @param : l : Letra que se quiere comparar.
     * @return : Devuelve true son iguales y false si no.
     */
    bool operator==(const Letra& l);
    /**
     * @brief : Comprueba si dos Letras son distintas, esto es, representan distintas letras.
     * @param : l : Letra que se quiere comparar.
     * @return : Devuelve true son distintas y false si no.
     */
    bool operator!=(const Letra& l);
    /**
     * @brief : Operador de asignacion.
     * @param :  l : Letra que se quiere asignar.
     * @return : Devuelve una referencia al objeto.
     */
    Letra& operator=(const Letra & l);
    /**
     * @brief : Lee de un flujo de entrada una Letra.
     * @param : is : Flujo de entrada.
     * @param : l : El objeto donde se realiza la lectura.
     * @return : Flujo de entrada.
     */
    friend istream & operator>>(istream & is, Letra & l);
    /**
     * @brief : Escribe en un flujo de salida una Letra.
     * @param : os : Flujo de salida.
     * @param : D : El objeto Letra que se escribe.
     * @return : Flujo de salida.
     */
    friend ostream & operator<<(ostream & os, const Letra & l);
    //friend class Conjunto_Letras;
};

#endif // __Letra_h__
