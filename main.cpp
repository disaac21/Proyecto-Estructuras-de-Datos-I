#include <iostream>
#include <string>
#include <windows.h>
//Clases que se incluyen
#include "TDALista.h"
#include "ArrayList.h"
#include "LinkedList.h"
#include "Alumno.h"

using namespace std;

int menuOperacionesLista(){
    int opcion = 0;
    cout << endl << "-------------------------"<< endl <<
    "1. Insertar Elemento " << endl <<
    "2. Imprimir Elemento " << endl <<
    "3. Buscar Elemento " << endl <<
    "4. Borrar Elemento " << endl <<
    "5. Vacia " << endl <<
    "6. Obtener Elemento por Posicion" << endl <<
    "7. Obtener Siguiente " << endl <<
    "8. Obtener Anterior " << endl <<
    "9. Anula " << endl <<
    "10. Regresar al Menu Anterior " << endl <<
    "Ingrese una opcion: ";
    cin >> opcion;
    return opcion;
}
int menuOperacionesPila(){
    int opcion = 0;
    cout << endl << "-------------------------"<< endl <<
    "1. Empujar (Push) " << endl <<
    "2. Sacar (pop) " << endl <<
    "3. Ver Tope (Top) " << endl <<
    "4. Vacia " << endl <<
    "5. Imprimir Elementos " << endl <<
    "6. Borrar todos los elementos " << endl <<
    "7. Regresar al Menu Anterior " << endl <<
    "Ingrese una opcion: ";
    cin >> opcion;
    return opcion; 
}
int menuOperacionesCola(){
    int opcion = 0;
    cout << endl << "-------------------------"<< endl <<
    "1. Encolar (Queue) " << endl <<
    "2. Desencolar (Dequeue) " << endl <<
    "3. Ver Frente (peek) " << endl <<
    "4. Vacia " << endl <<
    "5. Imprimir Elementos " << endl <<
    "6. Borrar los Elementos " << endl <<
    "7. Regresar al Menu Anterior " << endl <<
    "Ingrese una opcion: ";
    cin >> opcion;
    return opcion; 
}
void operacionesLista(TDALista* WorkingList){
    int opcion = 0;
    
    do{
        opcion = menuOperacionesLista();
        string Nombre = ""; int Cuenta;

        switch (opcion) {
            case 1: {
                int Pos;
                cin.ignore();
                cout << "Ingrese el Nombre del Alumno: ";
                getline(cin, Nombre);
                cout << "Ingrese el Número de Cuenta del Alumno: ";
                cin >> Cuenta;
                cout << "Ingrese la Posición a Insertar el Alumno: ";
                cin >> Pos;

                if (WorkingList->inserta(new Alumno(Nombre, Cuenta), Pos)) {
                    cout << "Alumno Insertado con Éxito!" << endl;
                } else {
                    cout << "Posición Fuera de Rango" << endl;
                }
                
                break;
            }
            case 2:{
                if (WorkingList->vacia()){
                    cout << "La Lista Está Vacía.";
                } else {
                    WorkingList->imprime();
                }
                break;
            }

            case 3:{
                if (WorkingList->vacia()){
                    cout << "La Lista Está Vacía. No Se Puede Buscar Alumnos.";
                } else {
                    cout << "Ingrese el Número de Cuenta del Alumno a Encontrar: ";
                    cin >> Cuenta;
                    int poscompare = WorkingList->localiza(new Alumno(Nombre, Cuenta));
                    if (poscompare >= 0)
                        cout << "Alumno Encontrado! Está en la Posición " << poscompare << "." << endl;
                    else
                        cout << "No Se Ha Encontrado el Alumno." << endl;
                }
                break;
            }

            case 4:{
                if (WorkingList->vacia()){
                    cout << "La Lista Está Vacía. No Se Puede Eliminar Alumnos.";
                } else {
                    int posdelete;
                    cout << "Ingrese la Posición del Alumno a Eliminar: ";
                    cin >> posdelete;
                    Object* AlumnoDelete = WorkingList->suprime(posdelete);
                    if (posdelete >= 0)
                        cout << "Alumno Eliminado!\nSus Datos Eran: " << AlumnoDelete->toString() << "." << endl;
                    else
                        cout << "No Se Ha Encontrado el Alumno." << endl;
                }
                break;
            }

            case 5:{
                if (WorkingList->vacia())
                    cout << "La Lista Está Vacía.";
                else
                    cout << "Ya Hay Elementos en la Lista.";
                break;
            }

            case 6:{
                if (WorkingList->vacia()){
                    cout << "La Lista Está Vacía, No Se Puede Buscar Alumnos.";
                } else {
                    int posfind;
                    cout << "Ingrese la Posición del Alumno a Encontrar: ";
                    cin >> posfind;
                    Object* AlumnoFind = WorkingList->recupera(posfind+1);
                    if (posfind >= 0)
                        cout << "Alumno Encontrado!\nSus Datos Son: " << AlumnoFind->toString() << "." << endl;
                    else
                        cout << "No Se Ha Encontrado el Alumno." << endl;
                }
                break;
            }

            default:
                break;
        }
    }while(opcion != 10);
}
void operacionesPila(){
    int opcion = 0;
    do{
        opcion = menuOperacionesPila();
    }while(opcion != 7);
}
void operacionesCola(){
    int opcion = 0;
    do{
        opcion = menuOperacionesCola();
    }while(opcion != 7);
}

int main(){
    
    SetConsoleCP(CP_UTF8); SetConsoleOutputCP(CP_UTF8);
    int opcionPrincipal = 0, opcionLista = 0, opcionPila = 0, opcionCola = 0;
    TDALista* WorkArrayList = new ArrayList();

    do{
        cout << "-------------MENU PRINCIPAL-----------------" << endl <<
        "1. Trabajar con Lista " <<  endl <<
        "2. Trabajar con Pilas " << endl <<
        "3. Trabajar con Colas " << endl <<
        "0. Salir " << endl <<
        "Ingrese una opcion: ";
        cin >> opcionPrincipal;
        switch(opcionPrincipal){
            case 1:{
                while(opcionLista!=3){
                    cout << endl << "*********Menu Tipo de Lista*********" << endl <<
                    "1. Trabajar con ArrayList " << endl <<
                    "2. Trabajar con LinkedList " << endl <<
                    "3. Regresar al Menu Principal " << endl <<
                    "Ingrese una opcion: ";
                    cin >> opcionLista;
                    switch(opcionLista){
                        case 1:{
                            operacionesLista(WorkArrayList);
                            break;
                        }
                        case 2:{
                            operacionesLista(nullptr);
                            break;
                        }
                        case 3:{
                            cout << endl;
                            break;
                        }
                    }
                }
                break;
            }
            case 2:{
                while(opcionPila != 3){
                    cout << endl << "+++++++++Menu Tipo de Pila+++++++++" << endl <<
                    "1. Trabajar con ArrayStack " << endl <<
                    "2. Trabajar con LinkedStack " << endl <<
                    "3. Regresar al Menu Principal " << endl <<
                    "Ingrese una opcion: ";
                    cin >> opcionPila;
                    switch(opcionPila){
                        case 1:{
                            operacionesPila();
                            break;
                        }
                        case 2:{
                            operacionesPila();
                            break;
                        }
                        case 3:{
                            cout << endl;
                            break;
                        }
                    }
                }
                break;
            }
            case 3:{
                while(opcionCola != 3){
                    cout << endl << "<<<<<<<<< Menu Tipo de Cola >>>>>>>>>" << endl <<
                    "1. Trabajar con ArrayQueue " << endl <<
                    "2. Trabajar con LinkedQueue " << endl <<
                    "3. Regresar al Menu Principal " << endl <<
                    "Ingrese una opcion: ";
                    cin >> opcionCola;
                    switch(opcionCola){
                        case 1:{
                            operacionesCola();
                            break;
                        }
                        case 2:{
                            operacionesCola();
                            break;
                        }
                        case 3:{
                            cout << endl;
                            break;
                        }
                    }
                }
                break;
            }
            case 0:{
                cout << endl;
                break;
            }
        }
    }while(opcionPrincipal);
    getchar();
};