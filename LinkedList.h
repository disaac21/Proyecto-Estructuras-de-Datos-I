#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "TDALista.h"
#include "Node.h"

class LinkedList : public TDALista {

	private:
		Node* PrimerNodo;
		Node* UltimoNodo;
		int size;

	public:
		LinkedList();
		~LinkedList();	
		virtual bool inserta(Object*, int);
		virtual bool append(Object*);
		virtual int localiza(Object*);
		virtual Object* recupera(int);
		virtual Object* suprime(int);
		virtual void anula();
		virtual Object* primero();
		virtual Object* anterior(int);
		virtual Object* siguiente(int);
		virtual bool vacia();
		virtual void imprime();
		virtual int getSize();
		
};

#endif