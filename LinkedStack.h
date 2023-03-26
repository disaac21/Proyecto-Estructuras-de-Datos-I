#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#include "TDAPila.h"
#include "Node.h"
#include <iostream>
using namespace std;
class LinkedStack : public TDAPila{
	public:
		LinkedStack();
		~LinkedStack();
		virtual void anula();
        virtual void push(Object* dato);
        virtual Object* peek();
        virtual Object* pop();
        virtual void imprime();
        virtual bool vacia();

	protected:
		Node* first;
		int top;
};
#endif