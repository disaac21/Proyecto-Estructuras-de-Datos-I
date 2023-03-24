#include <iostream>
#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList()
{
	first=0;
	ultimo=0;
	size=0;
}

LinkedList::~LinkedList()
{
	if(first)
		delete first;
}

bool LinkedList::inserta(Object* pData, int pos){
	if(pos >= 1 && pos <= size + 1){ 
		Node* nuevoNodo = new Node();
		nuevoNodo->setDato(pData);
		
		if(vacia()){
			first = nuevoNodo;
			ultimo = nuevoNodo;
			size++;
			return true;
		}else{
			//el rango es válido
			Node* temp = first;
			int i = 1;
			while(i<pos){
				temp = temp->getSiguiente();
				i++;
			}
			//actualizar los enlaces
			if(temp->getAnterior())
				temp->getAnterior()->setSiguiente(nuevoNodo);
				
			nuevoNodo->setSiguiente(temp);
			nuevoNodo->setAnterior(temp->getAnterior());
			temp->setAnterior(nuevoNodo);
			if (pos == size+1){
				ultimo = nuevoNodo;
			}
			if (pos == 1){
				first = nuevoNodo;
			}
			size++;
			return true;			
		}	
	} else {
		return false;
	}
}

bool LinkedList::append(Object* dato){
	return this->inserta(dato, size+1);
}

int LinkedList::localiza(Object* dato){
	Node* temp = first;
	int cont = 1;
	if (this->vacia()) {
		return -1;
	} else {
		do {
			if (temp->getDato() == dato) {
				return cont;
			} else {
				cont++;
				temp = temp->getSiguiente();
			}
		} while (temp!= nullptr);
	}
	return -1;
}

Object* LinkedList::recupera(int pos){
	int num = 1;
	Node* temp = new Node();
	temp->setDato(this->primero());
	if(pos > size){
			return nullptr;
	}else{
		while(num == pos){
			temp->setDato(temp->getSiguiente()->getDato());
			num++;
		}
		return temp->getDato();
	}
}

Object* LinkedList::suprime(int pos){
	if (pos < 0 && pos > size){
            return NULL;
	} else {
		int index = 0;
        Node* nodoRecuperado;
        Node* anterior;
        Node* siguiente;

        if(pos < size - pos){
			nodoRecuperado->setDato(this->primero());
            while(index < pos){
				nodoRecuperado->setDato(nodoRecuperado->getSiguiente()->getDato());
                index++;
            }
        } else {
            nodoRecuperado = ultimo;
            index = size;
            while(index > pos){
				nodoRecuperado->setDato(nodoRecuperado->getAnterior()->getDato());
                index--;
            }
        }
		Object* returnDato;
		Node* eliminar;
        if(pos == 1 && size == 1){
            anula();
            size--;
            return this->primero();
        } else if (pos == 1 && size > 1) {
            returnDato = this->primero();
            eliminar->setDato(this->primero());
			first->setDato(first->getSiguiente()->getDato());
			first->getSiguiente()->setDato(nullptr);
            delete eliminar;
            first->getAnterior()->setDato(nullptr);
            size--;
			return returnDato;
        }else if (pos == this->getSize()) {
            eliminar->setDato(this->ultimo->getDato());
            this->ultimo->setDato(this->ultimo->getAnterior()->getDato());
            delete eliminar;
			this->ultimo->getSiguiente()->setDato(nullptr);
            size--;
            return this->ultimo->getDato();
        } else {
			nodoRecuperado->getAnterior()->getSiguiente()->setDato(nodoRecuperado->getSiguiente()->getDato());
			nodoRecuperado->getSiguiente()->getAnterior()->setDato(nodoRecuperado->getAnterior()->getDato());
            returnDato = nodoRecuperado->getDato();
            delete nodoRecuperado;
            size--;
            return returnDato;
        }
	}
}

void LinkedList::anula(){
	do{
		Node* temp = this->first->getSiguiente();
		delete[] this->first;
		this->first->setDato(temp->getDato());
	} while (&primero != nullptr);

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
	if (size >= 0) {
		return false;
	} else {
		return true;
	}
}

void LinkedList::imprime(){
	Node* current = first;
		while (current) {
			cout << current->getDato();
			current = current->getSiguiente();
		}
		cout << endl;

}

int LinkedList::getSize(){
	return size;
}