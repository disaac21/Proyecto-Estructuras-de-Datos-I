#include "ArrayQueue.h"

ArrayQueue::ArrayQueue()//constructor de ArrayQueue
{
    size = 0;
    capacidad = 10;
    cola = new Object *[capacidad];
    frente = 0;
    end = 0;
}

ArrayQueue::~ArrayQueue()//Destructor de ArrayQueue
{
    this->anula(); // hace cada uno de los espacios null
    delete[] cola; // elimina el arreglo
}
void ArrayQueue::encolar(Object *objeto){//metodo para agregar elementos para la cola
    //Hay varios casos donde se puede encolar un objeto, entonces se verifica cada caso

    if(size==0){//Si el size es 0, el objeto se encola en el valor que tiene frente.
        cola[frente] = objeto;
    }
    else if(size==capacidad){//Si la cola esta llena, se aumentara el tamano de la cola
        if(frente==0){//si frente es 0, se meteran los datos a una cola temporal, la cual se agregara el nuevo dato.
            capacidad++;
            Object** temporal = new Object*[capacidad];
            for (int i = 0; i < size; i++)
            {
                temporal[i] = cola[i];
            }
            temporal[size] = objeto;
            cola = temporal;
            end++;
        }
        else if(frente>0 && end<frente){//Si el frente no es 0, se agregan los elementos de frente hasta el ultimo elemento
            cout << "Entra" << endl;
            int cont = 0;
            Object** temporal = new Object*[capacidad+1];
            for (int i = frente; i < capacidad; i++){
                temporal[cont] = cola[i];
                cont++;
            }
            for (int i = 0; i <= end; i++)//Luego se agregan los valores que estan atras del frente
            {
                temporal[cont] = cola[i];
                cont++;
            }
            
            temporal[capacidad] = objeto;
            cola = new Object*[capacidad+1];
            cola = temporal;//La nueva cola pasa a ser la cola que se guardaba en temporal y el size aumenta
            frente = 0;
            end = capacidad;
            capacidad++;
        }    
            
    }
    else if (size>=1 && (end+1)!=capacidad){//Caso cuando se agregan datos a la derecha sin que pasen la capacidad del array
        end++;
        cola[end] = objeto;
    }
    else if(frente>0 && size>=1 && (end+1)==capacidad){//caso para agregar datos atras del valor frente, cuando la derecha de la cola esta llena.
        end = 0;
        cola[end] = objeto;
    }
    
    size++;
    
    
}
Object* ArrayQueue::desencolar(){//metodo para sacar objetos de la cola
    if(!IsVacio()){
        Object* temporal = cola[frente];
        cola[frente] = nullptr;
        size--;

        //Diferentes casos para ver donde queda el nuevo frente de la cola

        if(frente+1==capacidad)//Caso cuando el frente esta al final de la cola/
            frente=0;//Nuevo frente pasa a ser el elemento al comienzo de la cola
        
        else if(size==0){//Caso cuando se desencola el frente y queda vacia la cola
            frente == end;
        }
        
        else//Caso normal
            frente++;
        return temporal;
    }
}

Object* ArrayQueue::verfrente(){//metodo para ver el elemento al frente de la cola
    return cola[frente];
}
bool ArrayQueue::IsVacio(){//metodo para ver si la cola esta vacia o no
    return size == 0;
}

void ArrayQueue::imprime(){// metodo para imprimir los elementos de la cola
    if(!IsVacio()){
        //Hay varios casos

        if(frente==0){//Si frente es 0, se recorre de manera normal la cola y se imprime
            for (int i = 0; i < size; i++){
                cout << "Pos " << i << ".- " << cola[i]->toString() << endl;
            }
        }

        else if(frente > 0 && end >= frente){//Si frente no es 0, pero end es mayor que frente. Se recorre de frente a end y se imprime
            for (int i = frente; i <= end; i++){
                cout  << "Pos " << i << ".- " << cola[i]->toString() << endl;
            }
            
        }
        else if(frente > 0 && end < frente){//Si frente no es 0 y end esta atras de frente.
            
            for (int i = frente; i < capacidad; i++){//Recorre de frente hasta final de la cola
                cout << "Pos " << i << ".- " << cola[i]->toString() << endl;
            }
            for (int i = 0; i <= end; i++)//Luego imprime de 0 hasta el elemento final de la cola
            {
                cout << "Pos " << i << ".- " << cola[i]->toString() << endl;
            }
        }
    }
}
void ArrayQueue::anula()//metodo para borrar los elementos de la cola
{
    // for (int i = 0; i < capacidad; i++){//elimina elementos de la cola
    //     delete cola[i];
    // }
    delete this->cola;
    //Se vuelve a restaurar la cola a como estaba al comienzo
    size = 0;
    capacidad = 10;
    cola = new Object *[capacidad];
    frente = 0;
    end = 0;
}