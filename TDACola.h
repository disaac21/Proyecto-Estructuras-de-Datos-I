#pragma once

#include "Object.h"

class TDACola {

	private:
    Object** array;
    int capacidad;
    int size;

	protected:
		// virtual bool inserta(Object*, int)=0;
		// virtual bool append(Object*)=0;
		// virtual int localiza(Object*)=0;
		// virtual Object* recupera(int)=0;
		// virtual Object* suprime(int)=0;
		// virtual Object* primero()=0;
		// virtual Object* anterior(int)=0;
		// virtual Object* siguiente(int)=0;
		// virtual bool vacia()=0;
		// virtual int getSize()=0;

        TDACola(/* args */);
        ~TDACola();
        virtual bool encolar(Object*) = 0;
        virtual bool desencolar() = 0;
        virtual void verfrente() = 0;
		virtual bool IsVacio()=0;
		virtual void imprime()=0;
		virtual void anula()=0;

};