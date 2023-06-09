#include <iostream>
#include <string>
#include <windows.h>

// Clases que se incluyen
#include "TDALista.h"
#include "ArrayList.h"
#include "LinkedList.h"

#include "TDAPila.h"
#include "ArrayStack.h"
#include "LinkedStack.h"

#include "TDACola.h"
#include "ArrayQueue.h"
#include "LinkedQueue.h"

#include "Alumno.h"
#include "Simbolo.h"

using namespace std;

bool isNumber(string recibido)
{
    bool valido = true;
    for (int i = 0; i < recibido.size(); i++)
    {
        if (!isdigit(recibido.at(i)))
        {
            valido = false;
            break;
        }
    }
    return valido;
}

int repetirCiclo()
{ // Ciclo "Seguir Ingresando" para Operación Insertar
    int opcionRepetirCiclo = 0;
    cout << endl
         << "1. Seguir Ingresando" << endl
         << "2. Volver al menu de Operaciones" << endl
         << "Ingrese una Opción: ";
    cin >> opcionRepetirCiclo;
    return opcionRepetirCiclo;
}

int menuOperacionesLista()
{ // Menu de operaciones de Listas(Array y Linked)
    string opcion = "";
    int num;
    cout << endl
         << " ---------- Operaciones de Listas ---------- " << endl
         << "1. Insertar Elemento" << endl
         << "2. Imprimir Elementos" << endl
         << "3. Buscar Elemento" << endl
         << "4. Borrar Elemento" << endl
         << "5. Ver Si Está Vacía" << endl
         << "6. Obtener Elemento por Posicion" << endl
         << "7. Obtener Siguiente" << endl
         << "8. Obtener Anterior" << endl
         << "9. Borrar Todos Los Elementos" << endl
         << "10. Regresar al Menu Anterior" << endl
         << "Ingrese una opcion: ";
    cin >> opcion;
    while (!isNumber(opcion))
    {
        cout << endl
             << "Porfavor ingrese un numero" << endl
             << "Ingrese una opcion: ";
        cin >> opcion;
    }

    num = stoi(opcion);

    return num;
}
int menuOperacionesPila()
{ // Menu de operaciones de Pila(Array y Linked)
    string opcion = "";
    int num;
    cout << endl
         << " ---------- Operaciones de Pilas ---------- " << endl
         << "1. Empujar (Push)" << endl
         << "2. Sacar (Pop)" << endl
         << "3. Ver Tope (Top)" << endl
         << "4. Vacia" << endl
         << "5. Imprimir Elementos" << endl
         << "6. Borrar todos los elementos" << endl
         << "7. Regresar al Menu Anterior" << endl
         << "Ingrese una opcion: ";
    cin >> opcion;
    while (!isNumber(opcion))
    {
        cout << endl
             << "Porfavor ingrese un numero" << endl
             << "Ingrese una opcion: ";
        cin >> opcion;
    }

    num = stoi(opcion);

    return num;
}
int menuOperacionesCola()
{ // Menu de operaciones de Cola(Array y Linked)
    string opcion = "";
    int num;
    cout << endl
         << " ---------- Operaciones de Colas ---------- " << endl
         << "1. Encolar (Queue)" << endl
         << "2. Desencolar (Dequeue)" << endl
         << "3. Ver Frente (Peek)" << endl
         << "4. Vacia" << endl
         << "5. Imprimir Elementos" << endl
         << "6. Borrar los Elementos" << endl
         << "7. Regresar al Menu Anterior" << endl
         << "Ingrese una opcion: ";
    cin >> opcion;
    while (!isNumber(opcion))
    {
        cout << endl
             << "Porfavor ingrese un numero" << endl
             << "Ingrese una opcion: ";
        cin >> opcion;
    }

    num = stoi(opcion);

    return num;
}

void operacionesLista(TDALista *WorkingList)
{ // Operaciones de Listas
    int opcion = 0;

    do
    {
        opcion = menuOperacionesLista();

        string Nombre = "";
        string Cuenta; // Atributos Generales

        switch (opcion)
        {

        case 1:
        { // Insertar Elemento (Inserta)
            int repetirInserta = 1;
            while (repetirInserta == 1)
            {
                string Pos;
                cin.ignore(); // Solicitar Datos
                cout << endl
                     << "Ingrese el Nombre del Alumno: ";
                getline(cin, Nombre);
                cout << "Ingrese el Número de Cuenta del Alumno: ";
                cin >> Cuenta;
                while (!isNumber(Cuenta))
                {
                    cout << endl << "Ingrese un Número de Cuenta Válido." << endl;
                    cout << "Ingrese el Número de Cuenta del Alumno: ";
                    cin >> Cuenta;
                }
                cout << "Ingrese la Posición a Insertar el Alumno: ";
                cin >> Pos;
                while (!isNumber(Pos))
                {
                    cout << endl << "Ingrese una Posición Válida." << endl;
                    cout << "Ingrese la Posición a Insertar el Alumno: ";
                    cin >> Pos;
                }
                

                if (WorkingList->inserta(new Alumno(Nombre, stoi(Cuenta)), stoi(Pos)) && stoi(Pos) <= WorkingList->getSize())
                { // Crea Objeto e Inserta en Lista
                    cout << endl
                         << "Alumno Insertado con Éxito!" << endl;
                }
                else
                {
                    cout << endl
                         << "Posición Fuera de Rango" << endl;
                }
                repetirInserta = repetirCiclo();
            }
            break;
        }

        case 2:
        { // Imprimir Elementos (Imprime)
            if (WorkingList->vacia())
            {
                cout << endl
                     << "La Lista Está Vacía." << endl;
            }
            else
            {
                cout << endl
                     << " ---------- Lista ---------- " << endl;
                WorkingList->imprime();
            }
            break;
        }

        case 3:
        { // Buscar Elemento (localiza)
            if (WorkingList->vacia())
            {
                cout << endl
                     << "La Lista Está Vacía. No Se Puede Buscar Alumnos." << endl;
            }
            else
            {
                cout << endl
                     << "Ingrese el Número de Cuenta del Alumno a Encontrar: "; // Método de Busqueda: Número de Cuenta
                cin >> Cuenta;
                while (!isNumber(Cuenta))
                {
                    cout << endl << "Ingrese un Número de Cuenta Válido." << endl;
                    cout << "Ingrese el Número de Cuenta del Alumno: ";
                    cin >> Cuenta;
                }
                int poscompare = WorkingList->localiza(new Alumno(Nombre, stoi(Cuenta))); // Recibe Posición del Objeto
                if (poscompare > 0 && poscompare <= WorkingList->getSize())
                {
                    cout << endl
                         << "Alumno Encontrado! " << WorkingList->recupera(poscompare)->toString() << " Está en la Posición " << poscompare << "." << endl; // Muestra Datos de Objeto
                }
                else
                {
                    cout << endl
                         << "No Se Ha Encontrado el Alumno." << endl;
                }
            }
            break;
        }

        case 4:
        { // Borrar Elemento (Suprime)
            if (WorkingList->vacia())
            {
                cout << endl
                     << "La Lista Está Vacía. No Se Puede Eliminar Alumnos." << endl;
            }
            else
            {
                string posdelete;
                cout << endl
                     << "Ingrese la Posición del Alumno a Eliminar: "; // Solicita Posición del Objeto a Eliminar
                cin >> posdelete;
                while (!isNumber(posdelete))
                {
                    cout << endl << "Ingrese una Posición Válida." << endl;
                    cout << "Ingrese la Posición a Insertar el Alumno: ";
                    cin >> posdelete;
                }
                if (stoi(posdelete) > 0 && stoi(posdelete) <= WorkingList->getSize()){
                    Object *AlumnoDelete = WorkingList->suprime(stoi(posdelete)); // Crea Objeto (Placeholder)
                    cout << endl
                         << "Alumno Eliminado!\nSus Datos Eran: " << AlumnoDelete->toString() << "." << endl; // Muestra Datos del Objeto Eliminado
                }else
                    cout << endl
                         << "No Se Ha Encontrado el Alumno." << endl;
            }
            break;
        }

        case 5:
        { // Ver Si Está Vacía (Vacia)
            if (WorkingList->vacia())
            {
                cout << endl
                     << "La Lista Está Vacía." << endl;
            }
            else
            {
                if (WorkingList->getSize() == 1)
                    cout << endl
                         << "Hay " << WorkingList->getSize() << " Elemento en la Lista." << endl;
                else
                    cout << endl
                         << "Hay " << WorkingList->getSize() << " Elementos en la Lista." << endl;
            }
            break;
        }

        case 6:
        { // Obtener Elemento Por Posición (Recupera)
            if (WorkingList->vacia())
            {
                cout << endl
                     << "La Lista Está Vacía, No Se Puede Buscar Alumnos." << endl;
            }
            else
            {
                string posfind;
                cout << endl
                     << "Ingrese la Posición del Alumno a Encontrar: "; // Pide la Posición del Objeto a Buscar
                cin >> posfind;
                while (!isNumber(posfind))
                {
                    cout << endl << "Ingrese una Posición Válida." << endl;
                    cout << "Ingrese la Posición a Insertar el Alumno: ";
                    cin >> posfind;
                }
                Object *AlumnoFind = WorkingList->recupera(stoi(posfind)); // Obtiene el Objeto en la Posición
                if (stoi(posfind) > 0 && stoi(posfind) <= WorkingList->getSize())
                    cout << endl
                         << "Alumno Encontrado!\nSus Datos Son: " << AlumnoFind->toString() << "." << endl; // Muestra Datos del Objeto Encontrado
                else
                    cout << endl
                         << "No Se Ha Encontrado el Alumno." << endl;
            }
            break;
        }

        case 7:
        { // Obtener Siguiente (Siguiente)
            if (WorkingList->vacia())
            {
                cout << endl
                     << "La Lista Está Vacía." << endl;
            }
            else
            {
                string posfindnext;
                cout << endl
                     << "Ingrese la Posición del Alumno a Encontrar su Siguiente: "; // Pide la Posición del Objeto para Obtener el Próximo
                cin >> posfindnext;
                while (!isNumber(posfindnext))
                {
                    cout << endl << "Ingrese una Posición Válida." << endl;
                    cout << "Ingrese la Posición a Insertar el Alumno: ";
                    cin >> posfindnext;
                }
                Object *AlumnoFindNext = WorkingList->recupera(stoi(posfindnext) + 1); // Crea el Objeto con el Siguiente de la Posición
                if (stoi(posfindnext) > 0 && stoi(posfindnext) <= WorkingList->getSize() - 1)
                    cout << endl
                         << "Alumno Encontrado!\nSus Datos Son: " << AlumnoFindNext->toString() << "." << endl; // Muestra Datos del Objeto
                else if (stoi(posfindnext) == WorkingList->getSize())
                    cout << endl
                         << "Este Alumno es el Último de la Lista." << endl; // Valida Sí Está al Borde Final de la Lista
                else
                    cout << endl
                         << "Posición Fuera de Rango." << endl; // Valida Sí La Posición es Parte de la Lista
            }
            break;
        }

        case 8:
        { // Obtener Anterior (Anterior)
            if (WorkingList->vacia())
            {
                cout << endl
                     << "La Lista Está Vacía." << endl;
            }
            else
            {
                string posfindprev;
                cout << endl
                     << "Ingrese la Posición del Alumno a Encontrar su Anterior: "; // Pide la Posición del Objeto para Obtener el Previo
                cin >> posfindprev;
                while (!isNumber(posfindprev))
                {
                    cout << endl << "Ingrese una Posición Válida." << endl;
                    cout << "Ingrese la Posición a Insertar el Alumno: ";
                    cin >> posfindprev;
                }
                Object *AlumnoFindPrev = WorkingList->recupera(stoi(posfindprev) - 1); // Crea el Objeto con el Anterior de la Posición
                if (stoi(posfindprev) > 1 && stoi(posfindprev) <= WorkingList->getSize())
                    cout << endl
                         << "Alumno Encontrado!\nSus Datos Son: " << AlumnoFindPrev->toString() << "." << endl; // Muestra Datos del Objeto
                else if (stoi(posfindprev) == 1)
                    cout << endl
                         << "Este Alumno es el Primero de la Lista." << endl; // Valida Sí Está al Comienzo de la Lista
                else
                    cout << endl
                         << "Posición Fuera de Rango." << endl; // Valida Sí la Posición es Parte de la Lista
            }
            break;
        }

        case 9:
        { // Borrar Todos Los Elementos (Anula)
            if (WorkingList->vacia())
            {
                cout << endl
                     << "La Lista Está Vacía." << endl;
            }
            else
            {
                WorkingList->anula();
                cout << endl
                     << "Lista Vaciada." << endl;
            }
            break;
        }

        default:
        {
            cout << endl
                 << "Ingrese una Opción Válida." << endl;
            break;
        }
        }
    } while (opcion != 10);
}
void operacionesPila(TDAPila *stack)
{ // Operaciones de Pilas
    int opcion = 0;
    do
    {
        opcion = menuOperacionesPila(); // se llama el Menu de Operaciones para ingresar la opcion que desean
        char caracter;                  // variable donde se guardaran los simbolos que desean los usuarios y luego se creara el objeto.

        switch (opcion)
        {
        case 1:
        {
            int repetirInserta = 1;
            while (repetirInserta == 1)
            { // metodo push
                cout << "Ingrese un simbolo: ";
                cin >> caracter;
                stack->push(new Simbolo(caracter)); // se agrega el simbolo a la arraystack
                cout << "Simbolo empujado correctamente" << endl;
                repetirInserta = repetirCiclo();
            }
            break;
        }
        case 2:
        { // metodo pop
            if (stack->vacia())
            {
                cout << "La pila esta vacia" << endl;
            }
            else
            {
                cout << "El elemento sacado de la Pila es: " << stack->pop()->toString() << endl;
            }
            break;
        }
        case 3:
        { // metodo peek
            if (!(stack->vacia()))
                cout << "El elemento al tope de la pila es: " << stack->peek()->toString() << endl;
            else
                cout << "La Pila esta vacia" << endl;
            break;
        }
        case 4:
        { // metodo vacia
            if (stack->vacia())
                cout << "La Pila esta vacia" << endl;
            else
                cout << "La Pila no esta vacia" << endl;
            break;
        }
        case 5:
        { // metodo imprimir pila
            if (stack->vacia())
                cout << "La Pila no contiene elementos" << endl;
            else
                cout << endl
                     << " ---------- Cola ---------- " << endl;
                stack->imprime();
            break;
        }
        case 6:
        { // metodo anula
            if (stack->vacia())
            {
                cout << "La Pila no contiene elementos" << endl;
            }
            else
            {
                stack->anula();
                cout << "Pila vaciada exitosamente" << endl;
            }

            break;
        }
        case 7:
        {
            cout << endl;
            break;
        }
        }
    } while (opcion != 7);
}
void operacionesCola(TDACola *Cola)
{ // Operaciones de Colas
    int opcion = 0;
    do
    {
        opcion = menuOperacionesCola();
        string Nombre = "";
        string Cuenta;

        switch (opcion)
        {
        case 1:
        { // case para empujar alumnos a la cola
            int repetirInserta = 1;
            while (repetirInserta == 1)
            { // metodo
                cin.ignore();
                cout << "Ingrese el nombre del alumno: ";
                getline(cin, Nombre);
                cout << "Ingrese el numero de cuenta del alumno: ";
                cin >> Cuenta;
                while (!isNumber(Cuenta))
                {
                    cout << endl << "Ingrese un Número de Cuenta Válido." << endl;
                    cout << "Ingrese el Número de Cuenta del Alumno: ";
                    cin >> Cuenta;
                }
                Cola->encolar(new Alumno(Nombre, stoi(Cuenta)));
                cout << "Alumno encolado correctamente" << endl;
                repetirInserta = repetirCiclo();
            }
            break;
        }
        case 2:
        { // case para desencolar alumno de la cola
            if (Cola->IsVacio())
            {
                cout << "La Cola esta vacia" << endl;
            }
            else
            {
                cout << "El Alumno sacado de la cola es : " << Cola->desencolar()->toString() << endl;
            }

            break;
        }
        case 3:
        { // case para ver el alumno al frente de la cola
            if (Cola->IsVacio())
            {
                cout << "La Cola esta vacia" << endl;
            }
            else
            {
                cout << "El elemento al frente de la cola es: " << Cola->verfrente()->toString() << endl;
            }
            break;
        }
        case 4:
        { // case para verificar si la cola esta vacia o no
            if (Cola->IsVacio())
            {
                cout << "La Cola Está Vacía" << endl;
            }
            else
            {
                cout << "La Cola No Está Vacía" << endl;
            }
            break;
        }
        case 5:
        { // case para imprimir los elementos de la cola
            if (Cola->IsVacio())
            {
                cout << "La cola no tiene elementos" << endl;
            }
            else
            {
                cout << endl
                     << " ---------- Pila ---------- " << endl;
                Cola->imprime();
            }
            break;
        }
        case 6:
        { // case para borrar los elementos de la cola
            if (Cola->IsVacio())
            {
                cout << "La Cola esta vacia" << endl;
            }
            else
            {
                Cola->anula();
                cout << "Elementos eliminados de la cola exitosamente" << endl;
            }

            break;
        }
        case 7:
        {
            cout << endl;
            break;
        }
        default:
            break;
        }
    } while (opcion != 7);
}

int main()
{ // Main

    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    string opcionPrincipal = "0";
    string opcionLista = "0", opcionPila = "0", opcionCola = "0"; // variables para tomar las opciones de los usuarios
    ArrayList *WorkArrayList = new ArrayList();
    LinkedList *WorkLinkedList = new LinkedList();
    ArrayStack *workArrayStack = new ArrayStack();
    LinkedStack *workLinkedStack = new LinkedStack();
    ArrayQueue *ColaArreglo = new ArrayQueue();
    LinkedQueue *ColaNodos = new LinkedQueue();

    do
    {
        // Menu Principal
        cout << " ---------- MENU PRINCIPAL ---------- " << endl
             << "1. Trabajar con Lista " << endl
             << "2. Trabajar con Pilas " << endl
             << "3. Trabajar con Colas " << endl
             << "4. Salir " << endl
             << "Ingrese una Opción: ";
        cin >> opcionPrincipal;
        while (!isNumber(opcionPrincipal))
        {
            cout << endl
                 << "Porfavor ingrese un numero" << endl
                 << "Ingrese una opcion: ";
            cin >> opcionPrincipal;
        }

        switch (stoi(opcionPrincipal))
        {
        case 1:
        {
            while (stoi(opcionLista) != 3)
            {
                // Menu para escoger con que tipo de Lista trabajar (Array o Linked)
                cout << endl
                     << " ---------- Menu Tipo de Lista ---------- " << endl
                     << "1. Trabajar con ArrayList " << endl
                     << "2. Trabajar con LinkedList " << endl
                     << "3. Regresar al Menu Principal " << endl
                     << "Ingrese una Opción: ";
                cin >> opcionLista;
                while (!isNumber(opcionLista))
                {
                    cout << endl
                         << "Porfavor ingrese un numero" << endl
                         << "Ingrese una opcion: ";
                    cin >> opcionLista;
                }
                switch (stoi(opcionLista))
                {
                case 1:
                {
                    operacionesLista(WorkArrayList); // se llama el metodo donde se desplagaran las operaciones de la Lista
                    break;
                }
                case 2:
                {
                    operacionesLista(WorkLinkedList); // se llama el metodo donde se desplagaran las operaciones de la Lista
                    break;
                }
                case 3: // regresar al menu principal
                {
                    cout << endl;
                    break;
                }
                default:
                {
                    cout << "Ingrese una Opción Válida.\n";
                    break;
                }
                }
            }
            opcionLista = "0";
            break;
        }

        case 2:
        {
            while (stoi(opcionPila) != 3)
            {
                // Menu para escoger con que tipo de Pila trabajar (Array o Linked)
                cout << endl
                     << " ---------- Menu Tipo de Pila ---------- " << endl
                     << "1. Trabajar con ArrayStack " << endl
                     << "2. Trabajar con LinkedStack " << endl
                     << "3. Regresar al Menu Principal " << endl
                     << "Ingrese una Opción: ";
                cin >> opcionPila;
                while (!isNumber(opcionPila))
                {
                    cout << endl
                         << "Porfavor ingrese un numero" << endl
                         << "Ingrese una opcion: ";
                    cin >> opcionPila;
                }
                switch (stoi(opcionPila))
                {
                case 1:
                {
                    operacionesPila(workArrayStack); // se llama el metodo donde se desplagaran las operaciones de la Pila
                    break;
                }
                case 2:
                {
                    operacionesPila(workLinkedStack); // se llama el metodo donde se desplagaran las operaciones de la Pila
                    break;
                }
                case 3: // regresar al menu principal
                {
                    cout << endl;
                    break;
                }
                default:
                {
                    cout << "Ingrese una Opción Válida.\n";
                    break;
                }
                }
            }
            opcionPila = "0";
            break;
        }

        case 3:
        {
            while (stoi(opcionCola) != 3)
            {
                // Menu para escoger con que tipo de Cola trabajar (Array o Linked)
                cout << endl
                     << " ---------- Menu Tipo de Cola ---------- " << endl
                     << "1. Trabajar con ArrayQueue " << endl
                     << "2. Trabajar con LinkedQueue " << endl
                     << "3. Regresar al Menu Principal " << endl
                     << "Ingrese una Opción: ";
                cin >> opcionCola;
                while (!isNumber(opcionCola))
                {
                    cout << endl
                         << "Porfavor ingrese un numero" << endl
                         << "Ingrese una opcion: ";
                    cin >> opcionCola;
                }
                switch (stoi(opcionCola))
                {
                case 1:
                {
                    operacionesCola(ColaArreglo); // se llama el metodo donde se desplagaran las operaciones de la Cola
                    break;
                }
                case 2:
                {
                    operacionesCola(ColaNodos); // se llama el metodo donde se desplagaran las operaciones de la Cola
                    break;
                }
                case 3: // regresar al menu principal
                {
                    cout << endl;
                    break;
                }
                default:
                {
                    cout << "Ingrese una Opción Válida.\n";
                    break;
                }
                }
            }
            opcionCola = "0";
            break;
        }

        case 4:
        {
            cout << endl;
            break;
        }

        default:
        {
            cout << "Ingrese una Opción Válida.\n"
                 << endl;
            break;
        }
        }
    } while (stoi(opcionPrincipal) != 4);
    // destructores
    WorkArrayList->~ArrayList();
    WorkLinkedList->~LinkedList();
    workArrayStack->~ArrayStack();
    workLinkedStack->~LinkedStack();
    ColaArreglo->~ArrayQueue();
    ColaNodos->~LinkedQueue();
    getchar();
};