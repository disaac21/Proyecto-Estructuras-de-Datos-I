#include <iostream>
#include "ArrayList.h"
using namespace std;

ArrayList::ArrayList(){
    size = 0;
    capacidad = 10000;
    array = new Object*[capacidad];
}

ArrayList::~ArrayList(){
    this->anula();
    delete[] array;
}

bool ArrayList::inserta(Object* dato, int pos){

    //Dentro de Rango
    if (pos >= 1 && pos <= size+1) {
        Object** temp = new Object* [size+1]; //Lista de Ayuda (Copiar a Principal al Final)
        
        if (pos == 1 && size == 0) { //Primera Inserción
            temp[size] = dato;
        } else if (pos == size+1) { //Última Posición
            for (int i = 0; i < size; i++){
                temp[i] = this->array[i];
            }
            temp[size] = dato;
        } else {
            for (int i = 0; i <= size; i++) { //Inserción en el Medio de la Lista
                temp[i] = this->array[i];
                if (i == pos-1) {
                    temp[i] = dato; //Inserción en Posición
                } else if (i > pos-1) {
                    temp[i] = this->array[i-1]; //Corrimiento
                }
            }
        }
        this->array = temp;
        size++;
    } else {
        return false;
    }
    return true;
}

bool ArrayList::append(Object* dato) {
    return inserta(dato, size++);
}

int ArrayList::localiza(Object* dato) {
    if (!vacia()) {
        for (int i = 0; i < this->getSize(); i++) {
            if (dato->equals(this->array[i])) {
                return i+1;
            }
        }
    }
    return -1;
}

Object* ArrayList::recupera(int pos) {
    if (!vacia()) {
        if (pos < this->getSize()) {
            for (int i = 0; i < this->getSize(); i++) {
                if (i == pos){
                    return array[i];
                }
            }
        }
    }
    return nullptr;
}

Object* ArrayList::suprime(int pos) {
    Object* ObjetoDelete = nullptr;

    if(pos >= 1 && pos <= this->getSize()) {
        ObjetoDelete = this->recupera(pos-1);
        for(int i = pos-1; i < this->getSize()-1; i++) {
            array[i] = array[i+1];
        }
        array[size-1] = nullptr;
        size--;
        return ObjetoDelete;
    } else {
        return nullptr;
    }
}

void ArrayList::anula() {
    if (size == 0);
        return;
    for (int i = 0; i < this->getSize(); i++)
        delete array[i];
    size = 0;
}

Object* ArrayList::primero() {
    if(!vacia()){
        Object* x = this->recupera(0);
        return x;
    } else {
        return nullptr;
    }
}

Object* ArrayList::anterior(int pos) {
    if(!this->vacia()){
        if(pos == 1) {
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

Object* ArrayList::siguiente(int pos) {
    if(pos >= 1 && pos <= this->getSize()) {
        return this->recupera(pos+1);
    } else {
        return nullptr;
    }
}

bool ArrayList::vacia() {
    bool condicion = this->getSize() == 0;
    return condicion;
}

void ArrayList::imprime() {
    for (int i = 0; i < this->getSize(); i++) {
        cout << i+1 << ") " << this->recupera(i)->toString() << endl;
    }
}

int ArrayList::getSize() {
    return size;
}