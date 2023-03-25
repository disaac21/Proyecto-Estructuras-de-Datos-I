//al insertar elemento, asignar al to string el nombre y la cuenta al objeto, o sea al ser creado

#include <iostream>
#include "Alumno.h"
#include "Object.h"
#include <string>
using namespace std;

Alumno::Alumno(string nombre, int cuenta){
    this->Nombre = nombre;
    this->Cuenta = cuenta;
}

Alumno::~Alumno(){
    // delete Alumno;
}

string Alumno::toString(){
    string infoalumno = "Nombre: " + this->Nombre + ", No. Cuenta: " + to_string(Cuenta);
    return infoalumno;
}

bool Alumno::equals(Object*){
    return NULL;
}