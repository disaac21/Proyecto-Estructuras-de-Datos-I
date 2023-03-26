#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include "TDAPila.h"

using namespace std;

class ArrayStack : public TDAPila {
        protected:
            int top;
            Object** stack;
        public:
            ArrayStack();
            ~ArrayStack();
            virtual void anula();
            virtual void push(Object*);
            virtual Object* peek();
            virtual Object* pop();
            virtual void imprime();
            virtual bool vacia();

};
#endif