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
    if (this->vacia())	{
        if(pos == 1) {
            array[0] = dato;
            size++;
            return true;
        }else{
            return false;
        }
    }else{
        if(pos >= 1 && pos <= size) {
            int RightLimit = pos;
            int Input = pos--;
            for(int i = RightLimit; i >= Input; i--){
                array[i] = array[i-1];
            }
            array[Input] = dato;
            size++;
            return true;  
        }else if(pos == size++) {
            array[pos] = dato;
            size++;
            return true;
        }else{
            return false;
        }
    }
}

bool ArrayList::append(Object* dato) {
    return inserta(dato, size++);
}

int ArrayList::localiza(Object* dato) {
    for(int i = 0; i < this->getSize(); i++) {
        if(this->recupera(i) == dato) {
            return i++;
        }
    }
    return -1;
}

Object* ArrayList::recupera(int pos) {
    for (int i = 0; i < this->getSize(); i++) {
        if (pos > this->getSize()) {
            return nullptr;
        } else {
            if (i == pos){
                return array[i];
            }
        }
    }
    return nullptr;
}

Object* ArrayList::suprime(int pos) {
    Object* returnValue = nullptr;

    if(pos >= 1 && pos <= this->getSize()) {
        returnValue = this->recupera(pos-1);
        for(int i = pos-1; i < this->getSize()-1; i++) {
            array[i] = array[i+1];
        }
        array[size-1] = nullptr;
        size--;
        return returnValue;
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
        cout << this->recupera(i);
    }
}

int ArrayList::getSize() {
    return size;
}