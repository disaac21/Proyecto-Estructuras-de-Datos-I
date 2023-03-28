#include "Simbolo.h"

Simbolo::Simbolo(char car){
    this->caracter = car;
}
Simbolo::~Simbolo(){}
string Simbolo::toString(){

    string toString_caracter; //creamos una variable de tipo string
    toString_caracter += caracter; // a esta cadena le agregamos nuesrto char (simbolo)
    return toString_caracter; // retornamos la cadena con el simbolo incluido

}
bool Simbolo::equals(Object* simbolo){

    // Este metodo compara dos objetos de tipo Simbolo para ver si son iguales

    Simbolo* simboloComparacion = dynamic_cast<Simbolo*>(simbolo); // Ya que el parametro que 
    //recbibimos es un object, casteamos el objeto a Simbolo para podes acceder 
    //a todas las caracteristicas de la clase Simbolo

    if (simboloComparacion->caracter == this->caracter) { // comparamos los dos caracteres
        return true; //  retornamos true si son iguales
    }
    return false; // retornamos false si son distintos

}