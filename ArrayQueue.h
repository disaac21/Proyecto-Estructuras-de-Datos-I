#pragma once

#include "TDACola.h"
#include "iostream"

using namespace std;

class ArrayQueue : public TDACola{
private:
    Object** cola;
    int capacidad;
    int size;
    int frente;
    int end;
public:
    ArrayQueue();
    ~ArrayQueue();
    virtual void encolar(Object*);
    virtual Object* desencolar();
    virtual Object* verfrente();
    virtual bool IsVacio();
    virtual void imprime();
    virtual void anula();
};

