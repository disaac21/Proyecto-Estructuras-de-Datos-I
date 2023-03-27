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
		if (pos == 1) { // Primera Inserción
			temp = new Node();
			temp->setDato(dato);
			// first->setAnterior(nullptr);
			if (size == 0)
			{
				ultimo = temp;
				first = temp;
			}else{
				temp->setSiguiente(first);
				first = temp;
			}
			
			size++;
		} else if (pos == size+1) { //Última Inserción
			// temp = first;
			nuevo->setDato(dato);
			ultimo->setSiguiente(nuevo);
			ultimo = nuevo;
			// while (temp->getSiguiente())
			// 	temp = temp->getSiguiente();
			// temp->setSiguiente(nuevo);
			// nuevo->setAnterior(temp);
			size++;
		} else { //Inserción en el Medio de la Lista
			nuevo->setDato(dato);

			temp = first;

			for (size_t i = 1; i < pos; i++)
			{
				temp = temp->getSiguiente();
			}// serlio daniel gadumd          

			nuevo->setAnterior(temp->getAnterior());
			nuevo->setSiguiente(temp); //nue:serlio daniel
			temp->setAnterior(nuevo);
			nuevo->getAnterior()->setSiguiente(nuevo);

			size++;
			

			// int i = 0;
			// while (temp) {
			// 	i++;
			// 	if (i == pos) {
			// 		nuevo->setSiguiente(temp);
			// 		if (i == 1) { //Exchange el Primero
			// 			nuevo->setAnterior(nullptr);
			// 			first = nuevo;
			// 		} else {
			// 			temp->getAnterior()->setSiguiente(nuevo);					
			// 			nuevo->setAnterior(temp->getAnterior());
			// 			temp->setAnterior(nuevo);
			// 			nuevo->setSiguiente(temp);
			// 		}
			// 		break;
			// 	}
			// 	temp = temp->getSiguiente(); //Después de Asignar y Correr
			// }
			// size++;
		}

	}
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
		Node* temp = first; // daniel serlio gadumd
		for (size_t i = 0; i < pos-1; i++)
		{
			temp = temp->getSiguiente();
		}

		if (temp == first)
		{
			first = temp->getSiguiente();
			size--;
			return temp->getDato();
		}else if(temp == ultimo){
			ultimo = temp->getAnterior();
			size--;
			return temp->getDato();
		}else{
			temp->getAnterior()->setSiguiente(temp->getSiguiente());
			size--;
			return temp->getDato();
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