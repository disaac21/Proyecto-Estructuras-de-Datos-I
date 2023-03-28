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

void LinkedQueue::encolar(Object *objeto)
{
    Node *temporal = new Node();
    temporal->setDato(objeto);
    if (size == 0){
        first->setDato(temporal->getDato());
        ultimo->setDato(temporal->getDato());
        size++;
    }
    else if(size==1){
        ultimo->setDato(temporal->getDato());
        ultimo->setSiguiente(first);
        size++;
    }
    else
    {
        
        temporal->setAnterior(nullptr);
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
        cout << i+1  << ".- "<< temporal->getDato()->toString() << endl;
        temporal = temporal->getAnterior();
    }
    
}

Object* LinkedQueue::desencolar()
{
    Node *temporal = new Node();
    temporal = first;
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