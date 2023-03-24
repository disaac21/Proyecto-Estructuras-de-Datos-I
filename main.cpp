#include <iostream>
#include <string>
//Clases que se incluyen
#include "LinkedList.h"

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
void operacionesLista(){
    int opcion = 0;
    do{
        opcion = menuOperacionesLista();
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
    int opcionPrincipal = 0, opcionLista = 0, opcionPila = 0, opcionCola = 0;
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
                            operacionesLista();
                            break;
                        }
                        case 2:{
                            operacionesLista();
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
};