#include "ArrayQueue.h"

ArrayQueue::ArrayQueue()
{
    size = 0;
    capacidad = 10000;
    cola = new Object *[capacidad];
}

ArrayQueue::~ArrayQueue()
{
    this->anula(); // hace cada uno de los espacios null
    delete[] cola; // elimina el arreglo
}

bool ArrayQueue::encolar(Object *objeto)
{
    cola[size] = objeto;  // coloca el puntero del objeto en en la posicion size
    size++; // se le agrega espacio al arreglo para una nueva insercion
}

bool ArrayQueue::desencolar()
{

    if (this->IsVacio()) //usa el metodo Is vacio, el cual retorna true si la cola esta vacia
    {
        cout << endl
             << "Cola vacia" << endl;
    }
    else
    {
        cout << endl;
        cout << cola[0]->toString() << endl; // imprime el primer dato que se ingreso a la cola

        for (size_t i = 0; i < size; i++)
        {
            cola[i] = cola[i + 1]; // hace un corrimiento para cada espacio de la cola
        }

        cola[size] = nullptr;//el ultimo espacio de la cola lo liberamos
        size--;// le restamos al tamaño de la cola
    }
}

void ArrayQueue::verfrente()
{
    if (this->IsVacio()) //usa el metodo Is vacio, el cual retorna true si la cola esta vacia
    {
        cout << endl
             << "Cola vacia" << endl;
    }
    else
    {
        cout << endl
             << cola[0]->toString() << endl;
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
            cout << i + 1 << ". " << cola[i]->toString() << endl;
        }
    }
}

void ArrayQueue::anula()
{
    for (size_t i = 0; i < size; i++)
    {
        cola[i] = nullptr;
    }

    size = 0;

    cout << endl << "Cola vacia" << endl;
}