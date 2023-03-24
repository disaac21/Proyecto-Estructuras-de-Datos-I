#ifndef NODE_H
#define NODE_H

#include "Object.h"

class Node
{
	public:
		Node();
		~Node();
		
		void setSiguiente(Node*);
		void setAnterior(Node*);
		void setDato(Object*);
		
		Node* getSiguiente();
		Node* getAnterior();
		Object* getDato();
		
	private:
		Node* siguiente;
		Object* dato;
		Node* anterior;
};

#endif