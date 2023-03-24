#ifndef TDALISTA_H
#define TDALISTA_H

#include "Object.h"

class TDALista {

	public:
	protected:
		virtual bool inserta(Object*, int)=0;
		virtual bool append(Object*)=0;
		virtual int localiza(Object*)=0;
		virtual Object* recupera(int)=0;
		virtual Object* suprime(int)=0;
		virtual void anula()=0;
		virtual Object* primero()=0;
		virtual Object* anterior(int)=0;
		virtual Object* siguiente(int)=0;
		virtual bool vacia()=0;
		virtual void imprime()=0;
		virtual int getSize()=0;

};

#endif