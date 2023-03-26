#include "LinkedQueue.h"

LinkedQueue::LinkedQueue(/* args */)
{
    first = 0;
    ultimo = 0;
    size = 0;
}

LinkedQueue::~LinkedQueue()
{
    if (first)
        delete first;
}

bool LinkedQueue::encolar(Object *objeto)
{
    Node *nodo = new Node();
    nodo->setDato(objeto);
    if (size == 0)
    {
        first = nodo;
        ultimo = nodo;
        size++;
    }
    else
    {
        nodo->setAnterior(ultimo);
        ultimo->setSiguiente(nodo);
        ultimo = nodo;
        size++;
    }
}

void LinkedQueue::imprime()
{
    if (first == nullptr || first == 0)
    {
        cout << endl
             << "Esta vacia" << endl;
    }
    else
    {
        Node *nodo = first;
        cout << endl;
        do
        {
            cout << nodo->getDato()->toString() << endl;
            nodo = nodo->getSiguiente();
        } while (nodo != NULL);
    }
}

bool LinkedQueue::desencolar()
{

    if (size <= 0)
    {
        cout << endl
             << "Esta vacia" << endl;
    }
    else
    {
        cout << endl
             << first->getDato()->toString() << endl; // 1 2 3 4
        first = first->getSiguiente();                // 1 2 3 4
        // first->getAnterior()->~Node();
        size--;
    }
}
void LinkedQueue::verfrente()
{
    if (size <= 0)
    {
        cout << endl
             << "Esta vacia" << endl;
    }
    else
    {
        cout << endl
             << first->getDato()->toString() << endl;
    }
}
bool LinkedQueue::IsVacio()
{
    if (first == NULL && ultimo == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void LinkedQueue::anula()
{
    if (size <= 0)
    {
        cout << endl
             << "Esta vacia" << endl;
    }
    else
    {
        Node *nodo = new Node();
        do
        {
            ultimo->setSiguiente(NULL);
            ultimo = ultimo->getAnterior();
        } while (ultimo == first);

        first = NULL;
        ultimo = NULL;
        size = 0;
    }
}