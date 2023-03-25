#ifndef ALUMNO_H
#define ALUMNO_H

using std::string;
#include "Object.h"

class Alumno : public Object {
    
    private:
        string Nombre;
		int Cuenta;

    public:
        Alumno(string, int);
        ~Alumno();
        virtual string toString();
		virtual bool equals(Object*);

};

#endif