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
    ArrayQueue(/* args */);
    ~ArrayQueue();
    virtual bool encolar(Object*);
    virtual bool desencolar();
    virtual void verfrente();
    virtual bool IsVacio();
    virtual void imprime();
    virtual void anula();
    virtual void getSize();//TODO eliminar esto
};

