#ifndef TDAPILA_H
#define TDAPILA_H
#include <iostream>
#include "Object.h"

class TDAPila{
    public:
        virtual void anula() = 0;//metodo para eliminar los elementos de la pila
        virtual void push(Object*) = 0;//metodo para empujar elementos a la pila
        virtual Object* peek() = 0;//metodo para ver que elemento se encuentra en la cima de la pila
        virtual Object* pop() = 0;//metodo para sacar el elemento en la cima de la pila 
        virtual void imprime() = 0;//metodo para imprimir los elementos de la pila
        virtual bool vacia() = 0;//metodo para verificar si la pila esta vacia o no
};
#endif