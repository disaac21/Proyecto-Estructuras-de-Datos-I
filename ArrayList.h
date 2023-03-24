#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include "TDALista.h"

using namespace std;

class ArrayList : public TDALista {

    private:
        Object** array;
        int capacidad;
        int size;

    public:
        ArrayList();
        ~ArrayList();
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