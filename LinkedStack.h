#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#include "TDAPila.h"
#include "Node.h"
#include <iostream>
using namespace std;
class LinkedStack : public TDAPila{
	public:
		LinkedStack();//constructor
		~LinkedStack();//destructor
		virtual void anula();//metodo anula
        virtual void push(Object* dato);//metodo push
        virtual Object* peek();//metodo peek
        virtual Object* pop();//metodo pop
        virtual void imprime();//metodo imprimir
        virtual bool vacia();//metodo para verificar si estan vacios los nodos

	protected:
		Node* first;//nodo principal
		int top;//variable para demostrar la posicion de la cima de la pila
};
#endif