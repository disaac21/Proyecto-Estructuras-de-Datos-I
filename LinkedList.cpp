#include <iostream>
#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList() { //Constructor
	PrimerNodo = nullptr;
	UltimoNodo = nullptr;
	size = 0;
}

LinkedList::~LinkedList() { //Destructor
	do{
		delete PrimerNodo;
		PrimerNodo = nullptr; //Hace que pase al Siguiente Nodo No Nulo
	} while (PrimerNodo != nullptr);
	size = 0;
}

bool LinkedList::inserta(Object* dato, int pos){ //Inserta un Elemento en una Posición 
	if (pos >= 1 && pos <= size+1) { //Dentro de Rango
		if (!PrimerNodo && pos == 1) { //Primera Inserción
			PrimerNodo = new Node();
			PrimerNodo->setDato(dato); //Asignación
		} else { //Ya Se Ha Insertado Antes
			Node* temp = new Node();//Inicializar Nodos de Ayuda
			temp = PrimerNodo;
			Node* Inserting = new Node();
			Inserting->setDato(dato);
			if (pos == size+1) { //Última Posición
				while (temp->getSiguiente()){
					temp = temp->getSiguiente(); //Asignación
				}
				temp->setSiguiente(Inserting); //Enlaces Correctos
				Inserting->setAnterior(temp);
			} else { //Último Caso: Inserción en el Medio de la Lista
				int i = 0;
				while (temp) { //Mientras Exista == no sea null, no llegue al final
					i++;
					if (i == pos) {
						Inserting->setSiguiente(temp);
						if (i == 1) { //Inserción en 1ra con Más Nodos
							Inserting->setAnterior(NULL);
							PrimerNodo = Inserting;
						}
						if (temp->getAnterior()){ //Corrimiento
							temp->getAnterior()->setSiguiente(Inserting);
						}
						Inserting->setAnterior(temp->getAnterior()); //Enlaces Correctos
						temp->setAnterior(Inserting);
						break;
					}
					temp = temp->getSiguiente(); //Seguir con el Ciclo
				}
			}
		}
		size++;
	}
	return true;
}

bool LinkedList::append(Object* dato){ //Agregar a la Última Posición
	return this->inserta(dato, size+1);
}

int LinkedList::localiza(Object* dato){ //Encuentra la Posición de un Objeto Dado
	if (!vacia()) {	
		Node* temp = PrimerNodo; 
		int i = 1;
		while (temp) {
			if (dato->equals(temp->getDato())){  //Compara Datos y Retorna Iteración si Encuentra
				return i;
			}
			i++;
			temp = temp->getSiguiente(); //Seguir con el Ciclo
		}
	}
	return -1;
}

Object* LinkedList::recupera(int pos){ //Encuentra el Objeto de una Posición Dada
	if (!vacia()) {
		if (pos <= size){
			Node* temp = PrimerNodo; //Inicializar Nodo de Ayuda
			int i = 1;
			while (temp) {
				if (i == pos){ //Encuentra Iteración con Posición
					return temp->getDato();
				}
				temp = temp->getSiguiente(); //Seguir con el Ciclo
				i++;
			}
		}
	}
	return nullptr;
}

Object* LinkedList::suprime(int pos){ //Borra el Objeto de una Posición Dada

	if (pos >= 1 && pos <= size) { //Dentro de Rango
		Node* temp = PrimerNodo; //Inicializar Nodo de Ayuda
		for (int i = 0; i < pos-1; i++) {
			temp = temp->getSiguiente(); //Seguir con el Ciclo
		}
		if (temp == PrimerNodo) { //Borrar el Primer Nodo
			PrimerNodo = temp->getSiguiente();
			size--;
			return temp->getDato();
		}else if(temp == UltimoNodo){ //Borrar el Último Nodo
			UltimoNodo = temp->getAnterior();
			size--;
			return temp->getDato();
		}else{ //Borar un Nodo en el Medio de la Lista
			temp->getAnterior()->setSiguiente(temp->getSiguiente());
			size--;
			return temp->getDato();
		}
	}
	return nullptr;
}

void LinkedList::anula(){ //Borra Todos los Elementos de la Lista
	do{
		delete PrimerNodo;
		PrimerNodo = nullptr; //Hace que pase al Siguiente Nodo No Nulo
	} while (PrimerNodo != nullptr);
	size = 0;

}

Object* LinkedList::primero(){ //Devuelve el Primer Objeto de la Lista
	if(size == 0)
            return NULL;
        else
            return this->PrimerNodo->getDato();
}

Object* LinkedList::anterior(int pos){ //Devuelve el Objeto Anterior al Objeto de la Posición Indicada
	if (pos < 1 || pos > size) //Dentro de Rango
            return NULL;
	if (pos == 1) //Primero No Tiene Anterior
		return NULL;
	
	Node *temp = UltimoNodo; //Inicializar Nodo de Ayuda
	int index = size;
	while (index >= pos){ //Llega desde el Último Nodo de la Lista Hasta el Indicado
		temp = UltimoNodo->getAnterior(); //Extrae el Nodo Anterior
		index--;
	}
	return temp->getDato();
}

Object* LinkedList::siguiente(int pos){ //Devuelve el Objeto Siguiente al Objeto de la Posición Indicada
	if (pos < 0 || pos >= size){ //Dentro de Rango
		return NULL;
	}else{
		Node* temp = PrimerNodo; //Inicializar Nodo de Ayuda
		int index = 0;
		while(index <= pos){ //Llega desde el Primer Nodo de la Lista Hasta el Indicado
			temp = temp->getSiguiente(); //Extrae el Nodo Siguiente
			index++;
		}
		return temp->getDato();
	}
}

bool LinkedList::vacia(){ //Revisa si la Lista Está Vacía
	bool condicion = this->getSize() == 0;
    return condicion;
}

void LinkedList::imprime(){ //Imprime todos los Elementos de la Lista
	Node* current = PrimerNodo;
	int i = 0;
	while (current) {
		cout << i+1 << ") " << current->getDato()->toString() << endl; //Output con Formato
		current = current->getSiguiente();
		i++;
	}
	cout << endl;

}

int LinkedList::getSize(){ //Devuelve el Tamaño 
	return size;
}