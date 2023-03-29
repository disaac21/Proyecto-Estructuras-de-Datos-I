#include "LinkedQueue.h"

LinkedQueue::LinkedQueue()
{
    first = nullptr;
    ultimo = nullptr;
    size = 0;
}

LinkedQueue::~LinkedQueue()
{
    if (ultimo)
        delete ultimo;
}

void LinkedQueue::encolar(Object *objeto) // moli gadumd daniel
{
    Node *temporal = new Node();
    temporal->setDato(objeto);
    if (size == 0){
        first = temporal;
        ultimo = temporal;
        size++;
    }
    else if(size==1){
        first->setAnterior(temporal);
        ultimo = temporal;
        size++;
    }
    else
    {
        
        temporal->setSiguiente(ultimo);
        ultimo->setAnterior(temporal);
        ultimo = temporal;
        size++;
    }
}

void LinkedQueue::imprime()
{
    Node *temporal = first;
    for (int i = 0; i < size; i++)
    {
        cout << "Pos. "<< i+1 << " - " << temporal->getDato()->toString() << endl;
        temporal = temporal->getAnterior();
    }
    
}

Object* LinkedQueue::desencolar()
{
    Node *temporal = first;
    // temporal = first;
    // first = first->getAnterior(); 
    // size--;
    // return temporal->getDato();

    first = first->getAnterior();
    size--;
    return temporal->getDato();
}
Object* LinkedQueue::verfrente()
{
    return first->getDato();
}
bool LinkedQueue::IsVacio()
{
    return size==0;
}
void LinkedQueue::anula(){
    delete ultimo;

    first = nullptr;
    ultimo = nullptr;
    size = 0;
}