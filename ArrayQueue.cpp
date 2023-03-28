#include "ArrayQueue.h"

ArrayQueue::ArrayQueue()
{
    size = 0;
    capacidad = 4;
    cola = new Object *[capacidad];
    frente = 0;
    end = 0;
    for (int i = 0; i < capacidad; i++)
    {
       cola[i] = nullptr;
    }
    
}

ArrayQueue::~ArrayQueue()
{
    this->anula(); // hace cada uno de los espacios null
    delete[] cola; // elimina el arreglo
}
void ArrayQueue::encolar(Object *objeto)
{
    if(size==0){
        cola[frente] = objeto;
    }
    else if(size==capacidad){
        if(frente==0){
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
        else if(frente>0 && end<frente){
            cout << "Entra" << endl;
            int cont = 0;
            Object** temporal = new Object*[capacidad+1];
            for (int i = frente; i < capacidad; i++){
                temporal[cont] = cola[i];
                cont++;
            }
            for (int i = 0; i <= end; i++)
            {
                temporal[cont] = cola[i];
                cont++;
            }
            
            temporal[capacidad] = objeto;
            cola = new Object*[capacidad+1];
            cola = temporal;
            frente = 0;
            end = capacidad;
            capacidad++;
        }    
            
    }
    else if (size>=1 && (end+1)!=capacidad){
        end++;
        cola[end] = objeto;
    }
    else if(frente>0 && size>=1 && (end+1)==capacidad){
        end = 0;
        cola[end] = objeto;
    }
    
    size++;
    
    
}
Object* ArrayQueue::desencolar(){
    if(!IsVacio()){
        Object* temporal = cola[frente];
        cola[frente] = nullptr;
        size--;
        if(frente+1==capacidad)
            frente=0;
        else if(size==0){
            frente == end;
        }
        else
            frente++;
        return temporal;
    }
}

Object* ArrayQueue::verfrente(){
    if(!IsVacio()){
        return cola[frente];
    }
    else{
        cout << "La cola esta vacia" << endl;
    }
}
bool ArrayQueue::IsVacio(){
    return size == 0;
}

void ArrayQueue::imprime(){
    if(!IsVacio()){
        for (int i = 0; i < capacidad; i++){
            if(cola[i] == nullptr){
                cout << " [] ";
            }
            else
                cout << "[ " << cola[i]->toString() << " ] ";
        }
        cout << endl;
        if(frente==0){
            for (int i = 0; i < size; i++){
                cout << i << ".- " << cola[i]->toString() << endl;
            }
        }
        else if(frente > 0 && end >= frente){
            for (int i = frente; i <= end; i++){
                cout << i << ".- " << cola[i]->toString() << endl;
            }
            
        }
        else if(frente > 0 && end < frente){
            for (int i = frente; i < capacidad; i++){
                cout << i << ".- " << cola[i]->toString() << endl;
            }
            for (int i = 0; i <= end; i++)
            {
                cout << i << ".- " << cola[i]->toString() << endl;
            }
        }
    }
}

void ArrayQueue::anula()
{
    for (size_t i = 0; i < capacidad; i++){
        delete cola[i];
    }
    size = 0;
    capacidad = 4;
    cola = new Object *[capacidad];
    frente = 0;
    end = 0;
}