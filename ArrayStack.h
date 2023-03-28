#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include "TDAPila.h"

using namespace std;

class ArrayStack : public TDAPila {
        protected:
            int top;//int que nos dice en que posicion se encuentra la cima de la pila
            Object** stack;//arreglo puntero de punteros donde se guardaran los simbolos de la pila
        public:
            ArrayStack();//Constructor
            ~ArrayStack();//Destructor
            virtual void anula();//metodo para eliminar todos los simbolos de la pila
            virtual void push(Object*);//empuja elemento a la pila
            virtual Object* peek();//muestra el elemento al cima de la pila
            virtual Object* pop();//saca el elemento al cima de la pila
            virtual void imprime();//imprime los elementos de la pila
            virtual bool vacia();//nos dice si la pila esta vacia

};
#endif