#include <iostream>
#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList()
{
	first=nullptr;
	ultimo=nullptr;
	size=0;
}

LinkedList::~LinkedList() {
	do{
		delete first;
		first = nullptr;
	} while (first != nullptr);
	size = 0;
}

bool LinkedList::inserta(Object* dato, int pos){

	//Dentro de Rango
    if (pos >= 1 && pos <= size+1) {
		Node* temp = new Node(); //Nodos de Ayuda
		Node* nuevo = new Node();

		//first->getDato()->equals(nullptr) &&  (inside if condition)
		if (pos == 1 && size == 0) { // Primera Inserción
			first = new Node();
			first->setDato(dato);
			first->setAnterior(nullptr);
		} else if (pos == size+1) { //Última Inserción
			temp = first;
			nuevo->setDato(dato);
			while (temp->getSiguiente())
				temp = temp->getSiguiente();
			temp->setSiguiente(nuevo);
			nuevo->setAnterior(temp);
		} else { //Inserción en el Medio de la Lista
			temp = first;
			nuevo->setDato(dato);
			int i = 0;
			while (temp) {
				i++;
				if (i == pos) {
					nuevo->setSiguiente(temp);
					if (i == 1) { //Exchange el Primero
						nuevo->setAnterior(NULL);
						first = nuevo;
					}
					if (temp->getAnterior()) //Corrimiento
						temp->getAnterior()->setSiguiente(nuevo);					
						nuevo->setAnterior(temp->getAnterior());
					temp->setAnterior(nuevo);
					break;
				}
				temp = temp->getSiguiente(); //Después de Asignar y Correr
			}
		}

	}
	size++;
	return true;
}

bool LinkedList::append(Object* dato){
	return this->inserta(dato, size+1);
}

int LinkedList::localiza(Object* dato){
	if (!vacia()) {
		Node* temp = first;
		int i = 1;
		while (temp) {
			if (dato->equals(temp->getDato())){
				return i;
			}
			i++;
			temp = temp->getSiguiente();
		}
	}
	return -1;
}

Object* LinkedList::recupera(int pos){
	if (!vacia()) {
		if (pos <= size){
			Node* temp = first;
			int i = 1;
			while (temp) {
				if (i == pos){
					return temp->getDato();
				}
				temp = temp->getSiguiente();
				i++;
			}
		}
	}
	return nullptr;
}

Object* LinkedList::suprime(int pos){

	Object* ObjetoDelete; //Objeto Borrado (Retornar)
	if (pos >= 1 && pos <= size) {
		Node* temp = first;
		int i = 0;
		while (temp) {
			i++;
			if (i == pos) {
				if (pos == 1 && size == 1){
					temp = first;
					first = nullptr;
					return temp->getDato();
				} else if (i == size) {
					temp = ultimo;
					ultimo = ultimo->getAnterior();
					return temp->getDato();
				} else {
					//if (temp->getAnterior())
						temp->getAnterior()->setSiguiente(temp->getSiguiente());
					//if (temp->getSiguiente())
						temp->getSiguiente()->setAnterior(temp->getAnterior());
						return temp->getDato();
				}
				temp = nullptr;
				size--;
			}
			temp = temp->getSiguiente();
		}
	}
	return nullptr;
}

void LinkedList::anula(){
	do{
		delete first;
		first = nullptr;
	} while (first != nullptr);
	size = 0;

}

Object* LinkedList::primero(){
	if(size == 0)
            return NULL;
        else
            return this->first->getDato();
}

Object* LinkedList::anterior(int pos){
	if (pos < 1 && pos > size)
            return NULL;
        if (pos == 1)
        	return NULL;
        
        int index = size;
        Node *temp = ultimo;
        while (index >= pos){
            temp = ultimo->getAnterior();
            index--;
        }
        return temp->getDato();

}

Object* LinkedList::siguiente(int pos){
	if (vacia() || pos < 0 || pos+1>size){
		return NULL;
	}else{
		Node* guardar = first;
		int temp = 0;
		while(temp <= pos+1){
			guardar = guardar->getSiguiente();
			temp++;
		}
		return guardar->getDato();
	}
}

bool LinkedList::vacia(){	
	bool condicion = this->getSize() == 0;
    return condicion;
}

void LinkedList::imprime(){
	Node* current = first;
	int i = 0;
	while (current) {
		cout << i+1 << ") " << current->getDato()->toString() << endl;
		current = current->getSiguiente();
		i++;
	}
	cout << endl;

}

int LinkedList::getSize(){
	return size;
}