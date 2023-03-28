#include "Node.h"

//#define NULL 0

Node::Node(){ // constructor al crear un nodo
	siguiente=NULL; // al crear un nodo vacio no tiene un nodo siguiente
	anterior=NULL; // al crear un nodo vacio no tiene un nodo anterior
	dato=NULL; // al crear un nodo vacio no tiene ningun dato dentro
}

Node::~Node(){
	if(siguiente)	
		delete siguiente;
		
	if(dato)
		delete dato;
}


void Node::setSiguiente(Node* pNext){
	siguiente=pNext; // asignamos el nodo siguiente a este nodo
}

void Node::setAnterior(Node* pPrev){
	anterior = pPrev; // asignamos el nodo anterior a este nodo
}

void Node::setDato(Object* pData){
	dato=pData; // le asignamos un dato a este nodo
}

Node* Node::getSiguiente(){
	return siguiente; //retornamos el nodo que continua, o que le sigue al nodo presente
}

Node* Node::getAnterior(){
	return anterior; //retornamos el nodo que esta detras de este nodo
}

Object* Node::getDato(){
	return dato; // retorna el dato que esta dento del nodo
}