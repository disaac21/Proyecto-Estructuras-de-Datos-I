#pragma once

#include "TDACola.h"
#include "Node.h"
#include "iostream"

using namespace std;

class LinkedQueue : public TDACola
{
private:
    Node *first;
    Node *ultimo;
    int size;

public:
    LinkedQueue(/* args */);
    ~LinkedQueue();
    virtual bool encolar(Object*);
    virtual bool desencolar();
    virtual void verfrente();
    virtual bool IsVacio();
    virtual void imprime();
    virtual void anula();
    virtual void getSize();//TODO eliminar esto
};
