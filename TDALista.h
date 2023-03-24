#ifndef TDALISTA_H
#define TDALISTA_H

#include "Object.h"

class TDALista {

	private:
        Object** array;
        int capacidad;
        int size;

    public:
        TDALista();
        ~TDALista();
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