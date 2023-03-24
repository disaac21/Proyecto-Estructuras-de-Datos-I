#include <iostream>
using namespace std;

int main(int argc, char** argv) {
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
                    cout << "*********Menu Tipo de Lista*********" << endl <<
                    "1. Trabajar con ArrayList " << endl <<
                    "2. Trabajar con LinkedList " << endl <<
                    "3. Regresar al Menu Principal " << endl <<
                    "Ingrese una opcion: ";
                    cin >> opcionLista;
                    switch(opcionLista){
                        case 1:{
                            cout << "ArrayList" << endl;
                            break;
                        }
                        case 2:{
                            cout << "LinkedList" << endl;
                            break;
                        }
                        case 3:{
                            break;
                        }
                    }
                }
                break;
            }
            case 2:{
                while(opcionPila != 3){
                    cout << "+++++++++Menu Tipo de Pila+++++++++" << endl <<
                    "1. Trabajar con ArrayStack " << endl <<
                    "2. Trabajar con LinkedStack " << endl <<
                    "3. Regresar al Menu Principal " << endl <<
                    "Ingrese una opcion: ";
                    cin >> opcionPila;
                    switch(opcionPila){
                        case 1:{
                            cout << "ArrayStack" << endl;
                            break;
                        }
                        case 2:{
                            cout << "LinkedStack" << endl;
                            break;
                        }
                        case 3:{
                            break;
                        }
                    }
                }
                break;
            }
            case 3:{
                while(opcionCola != 3){
                    cout << "<<<<<<<<< Menu Tipo de Cola >>>>>>>>>" << endl <<
                    "1. Trabajar con ArrayQueue " << endl <<
                    "2. Trabajar con LinkedQueue " << endl <<
                    "3. Regresar al Menu Principal " << endl <<
                    "Ingrese una opcion: ";
                    cin >> opcionCola;
                    switch(opcionCola){
                        case 1:{
                            cout << "ArrayQueue" << endl;
                            break;
                        }
                        case 2:{
                            cout << "LinkedQueue" << endl;
                            break;
                        }
                        case 3:{
                            break;
                        }
                    }
                }
                break;
            }
            case 0:{
                break;
            }
        }
    }while(opcionPrincipal);

	
	return 0;
}