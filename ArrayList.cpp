#include <iostream>
#include "ArrayList.h"
using namespace std;

ArrayList::ArrayList(){ //Constructor
    size = 0;
    capacidad = 10000;
    array = new Object*[capacidad];
}

ArrayList::~ArrayList(){ //Destructor
    this->anula();
    delete[] array;
}

bool ArrayList::inserta(Object* dato, int pos){ //Inserta un Elemento en una Posición 

    //Dentro de Rango
    if (pos >= 1 && pos <= size+1) {
        Object** ListaTemp = new Object* [size+1]; //Lista de Ayuda (Copiar a Principal al Final)
        
        if (pos == 1 && size == 0) { //Primera Inserción
            ListaTemp[size] = dato;
        } else if (pos == size+1) { //Última Posición
            for (int i = 0; i < size; i++){
                ListaTemp[i] = this->array[i];
            }
            ListaTemp[size] = dato; //Inserta Dato en Última Posición
        } else {
            for (int i = 0; i <= size; i++) { //Inserción en el Medio de la Lista
                ListaTemp[i] = this->array[i];
                if (i == pos-1) {
                    ListaTemp[i] = dato; //Inserción en Posición
                } else if (i > pos-1) {
                    ListaTemp[i] = this->array[i-1]; //Corrimiento
                }
            }
        }
        this->array = ListaTemp; //Asignacion a Lista Original
        size++;
    } else {
        return false;
    }
    return true;
}

bool ArrayList::append(Object* dato) { //Agregar a la Última Posición
    return inserta(dato, size++);
}

int ArrayList::localiza(Object* dato) { //Encuentra la Posición de un Objeto Dado
    if (!vacia()) {
        for (int i = 0; i < size; i++)
            if (dato->equals(this->array[i])) //Compara Datos y Retorna Iteración si Encuentra
                return i+1;
    }
    return -1;
}

Object* ArrayList::recupera(int pos) { //Encuentra el Objeto de una Posición Dada
    if (!vacia()) {
        if (pos <= this->getSize()) { //Encuentra Iteración con Posición
            return this->array[pos-1];
        }
    }
    return nullptr;
}

Object* ArrayList::suprime(int pos) { //Borra y Retorna el Objeto de una Posición Dada

    Object* ObjetoDelete; //Objeto Borrado (Retornar)
    if (pos >= 1 && pos <= size) {
        Object **temp = new Object*[size-1]; //Lista de Ayuda (Copiar a Principal al Final)

        ObjetoDelete = this->array[pos-1]; //Objeto Borrado (Retornar)
        for (int i = 0; i < size-1; i++) { //Fixing Temp (Corriemientos)
            temp[i] = this->array[i];
            if (i >= pos-1)
                temp[i] = this->array[i+1]; //Asigna el Elemento
        }
        array = temp; //Asignacion a Lista Original
        size--;
    }
    return ObjetoDelete; //Retorna Objeto Eliminado para Mostrar su Información
}

void ArrayList::anula() { //Borra Todos los Elementos de la Lista
    if (size == 0)
        return;
    for (int i = 0; i < this->getSize(); i++) //Itera a lo Largo de la Lista
        delete this->array[i]; //Elimina el Objeto
    
    this->array = new Object*[capacidad]; //Reestablece la Lista
    this->size = 0;
}

Object* ArrayList::primero() { //Devuelve el Primer Objeto de la Lista
    if(!vacia()){
        Object* Send = this->recupera(0); //Captura el Primer Objeto en la Lista
        return Send;
    } else {
        return nullptr;
    }
}

Object* ArrayList::anterior(int pos) { //Devuelve el Objeto Anterior al Objeto de la Posición Indicada
    if(!this->vacia()){
        if(pos == 1) { //Primero No Tiene Anterior
            return nullptr; 
        } else if (pos < 1 || pos > this->getSize()){
            return nullptr;
        } else {
            return this->recupera(pos-1); 
        }
    } else {
        return nullptr;
    }
}

Object* ArrayList::siguiente(int pos) { //Devuelve el Objeto Siguiente al Objeto de la Posición Indicada
    if(pos >= 1 && pos <= this->getSize()) { //Último No Tiene Siguiente
        return this->recupera(pos+1);
    } else {
        return nullptr;
    }
}

bool ArrayList::vacia() { //Revisa si la Lista Está Vacía
    bool condicion = this->getSize() == 0;
    return condicion;
}

void ArrayList::imprime() { //Imprime todos los Elementos de la Lista
    for (int i = 0; i < this->getSize(); i++) {
        cout << i+1 << ") " << this->array[i]->toString() << endl; //Output con Formato
    }
}

int ArrayList::getSize() { //Devuelve el Tamaño 
    return size;
}