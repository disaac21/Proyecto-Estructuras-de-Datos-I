#ifndef SIMBOLO_H
#define SIMBOLO_H
#include <string>
#include <iostream>
using namespace std;
#include "Object.h"

class Simbolo : public Object {
    
    private:
        char caracter;

    public:
        Simbolo(char);
        ~Simbolo();
        virtual string toString();
		virtual bool equals(Object*);

};

#endif