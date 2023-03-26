#include "ArrayQueue.h"

ArrayQueue::ArrayQueue()
{
    size = 0;
    capacidad = 10000;
    array = new Object *[capacidad];
}

ArrayQueue::~ArrayQueue()
{
}

bool ArrayQueue::encolar(Object *objeto)
{
    array[size] = objeto;
    size++;
}

bool ArrayQueue::desencolar()
{
    // array[0] = nullptr;

    if (this->IsVacio())
    {
        cout << endl
             << "Cola vacia" << endl;
    }
    else
    {
        cout << endl;
        cout << array[0]->toString() << endl;

        for (size_t i = 0; i < size; i++)
        {
            array[i] = array[i + 1];
        }

        array[size] = nullptr;
        size--;
    }
}

void ArrayQueue::verfrente()
{
    if (this->IsVacio())
    {
        cout << endl
             << "Cola vacia" << endl;
    }
    else
    {
        cout << endl
             << array[0]->toString() << endl;
    }
}

bool ArrayQueue::IsVacio()
{
    if (size <= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void ArrayQueue::imprime()
{

    if (this->IsVacio())
    {
        cout << endl
             << "Cola vacia" << endl;
    }
    else
    {
        cout << endl;
        for (size_t i = 0; i < size; i++)
        {
            cout << i + 1 << ". " << array[i]->toString() << endl;
        }
    }
}

void ArrayQueue::anula()
{
    for (size_t i = 0; i < size; i++)
    {
        array[i] = nullptr;
    }

    size = 0;

    cout << endl << "Cola vacia" << endl;
}