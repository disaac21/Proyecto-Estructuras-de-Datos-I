#include "ArrayQueue.h"

ArrayQueue::ArrayQueue()
{
    size = 0;
    capacidad = 1;
    cola = new Object *[capacidad];
    frente = 0;
    end = -1;
}

ArrayQueue::~ArrayQueue()
{
    this->anula(); // hace cada uno de los espacios null
    delete[] cola; // elimina el arreglo
}

void ArrayQueue::getSize()
{
    cout << endl
         << "size: " << size << endl;
    cout << endl
         << "frente: " << frente << endl;
    cout << endl
         << "end: " << end << endl;
} // TODO eliminar esto

bool ArrayQueue::encolar(Object *objeto)
{
    if (end == size)
    {
        capacidad++;
        size++;
        if (end != 0)
        {
            cola[end + 1] = objeto;
            end++;
        }else{
            cola[end] = objeto;
        }
        cout << "encolar a " << endl;
    }
    else if ((frente != 0) && (end == capacidad - 1))
    {
        // size++;                 // se le agrega espacio al arreglo para una nueva insercion
        // cola[end + 1] = objeto; // coloca el puntero del objeto en en la posicion size
        // end++;
        end = 0;
        cola[end] = objeto;
        cout << "encolar b " << endl;
        size++;

        // size++;
    }
    else
    {
        size++;
        cola[end + 1] = objeto;
        end++;
        cout << "encolar c " << endl;
    }
}

bool ArrayQueue::desencolar()
{

    if (this->IsVacio()) // usa el metodo Is vacio, el cual retorna true si la cola esta vacia
    {
        cout << endl
             << "Cola vacia" << endl;
    }
    else
    {
        //! el nuevo
        cout << cola[frente]->toString() << endl;
        cola[frente] = nullptr;
        if (frente == end)
        {
            frente = 0;
            cout << "desencolar if" << endl;
            size--;
        }
        else
        {
            frente++;
            cout << "desencolar else" << endl;
            size--;
        }

        // ! el de antes
        // cout << endl;
        // cout << cola[0]->toString() << endl; // imprime el primer dato que se ingreso a la cola

        // for (size_t i = 0; i < size; i++)
        // {
        //     cola[i] = cola[i + 1]; // hace un corrimiento para cada espacio de la cola
        // }

        // cola[size] = nullptr;//el ultimo espacio de la cola lo liberamos
        // size--;// le restamos al tamaño de la cola
    }
}

void ArrayQueue::verfrente()
{
    if (this->IsVacio()) // usa el metodo Is vacio, el cual retorna true si la cola esta vacia
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
        for (size_t i = 0; i < size; i++) // frente y end
        {
            if (cola[i] != nullptr)
            {
                cout << i + 1 << ". " << cola[i]->toString() << endl;
            }
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
    capacidad = 6;
    frente = 0;
    end = -1;

    cout << endl
         << "Cola vacia" << endl;
}