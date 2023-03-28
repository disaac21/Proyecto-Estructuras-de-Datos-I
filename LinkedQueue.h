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
    LinkedQueue();
    ~LinkedQueue();
    virtual void encolar(Object*);
    virtual Object* desencolar();
    virtual Object* verfrente();
    virtual bool IsVacio();
    virtual void imprime();
    virtual void anula();
};
