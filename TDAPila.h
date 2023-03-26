#ifndef TDAPILA_H
#define TDAPILA_H
#include <iostream>
#include "Object.h"

class TDAPila{
    public:
        virtual void anula() = 0;
        virtual void push(Object*) = 0;
        virtual Object* peek() = 0;
        virtual Object* pop() = 0;
        virtual void imprime() = 0;
        virtual bool vacia() = 0;
};
#endif