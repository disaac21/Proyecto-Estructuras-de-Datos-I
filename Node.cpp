#include "Node.h"

//#define NULL 0

Node::Node(){
	siguiente=NULL;
	anterior=NULL;
	dato=NULL;
}

Node::~Node(){
	if(siguiente)	
		delete siguiente;
		
	if(dato)
		delete dato;
}


void Node::setSiguiente(Node* pNext){
	siguiente=pNext;
}

void Node::setAnterior(Node* pPrev){
	anterior = pPrev;
}

void Node::setDato(Object* pData){
	dato=pData;
}

Node* Node::getSiguiente(){
	return siguiente;
}

Node* Node::getAnterior(){
	return anterior;
}

Object* Node::getDato(){
	return dato;
}