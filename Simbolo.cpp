#include "Simbolo.h"

Simbolo::Simbolo(char car){
    this->caracter = car;
}
Simbolo::~Simbolo(){}
string Simbolo::toString(){
    string toString_caracter = caracter + "";
    return toString_caracter;
}
bool Simbolo::equals(Object* simbolo){
    Simbolo* simboloComparacion = dynamic_cast<Simbolo*>(simbolo);
    if (simboloComparacion->caracter == this->caracter) {
        return true;
    }
    return false;
}