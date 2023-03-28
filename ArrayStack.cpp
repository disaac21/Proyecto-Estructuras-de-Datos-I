#include <iostream>
#include "ArrayStack.h"
using namespace std;

ArrayStack::ArrayStack(){//constructor
    this->top = 0;//se inicializa la posicion donde se encuentra la cima de la pila. Inicia en 0 siempre
    stack = new Object*[100];//se inicializa la pila con un tamaño de 100
}
ArrayStack::~ArrayStack(){//destructor
    this->anula();//elimina los elementos que esta dentro de la pila
    delete[] stack;//elimina el espacio en memoria de la pila
}
void ArrayStack::anula(){//metodo anula
    if(!vacia()){// verifica si esta o no esta vacia la pila. Si no esta, elimina los elementos de la pila
        for (int i = 0; i < top; i++)
            delete stack[i];
        stack = new Object*[100];//Inicializa la pila y restaura la posicion de la cima de la pila a 0
        this->top = 0;
    }
    
}
void ArrayStack::push(Object* simbolo){//metodo push
    Object** temp_stack = new Object*[top+1];// se crea una pila temporal con tamaño de la pila + 1. 
    if(!vacia()){
        for (int i = 0; i < top; i++){
            temp_stack[i] = stack[i];//Se guardaran los elementos de la pila en esta nueva pila
        }
    }
    temp_stack[top] = simbolo;//Se inserta el nuevo simbolo
    stack = temp_stack;//se asigna la pila temporal a la pila principal
    top++;//se suma 1 para demostrar que la cima de la pila ha cambiado.
}
Object* ArrayStack::peek(){//metodo peek
    return stack[top-1];//retorna el elemento al cima de la pila
}
Object* ArrayStack::pop(){//metodo pop
    Object* popped_symbol = stack[top-1];//se guarda el elemento que se sacara de la pila
    Object** temp_stack = new Object*[top-1];//se crea una pila temporal con el tamamo original - 1
    for (int i = 0; i < top-1; i++)
    {
        temp_stack[i] = stack[i];//Se guardan los valores de la pila en la temporal ignorando el elemento sacado
    }
    stack = temp_stack;//se asigna la pila temporal a la pila original
    top--;//se resta 1 a la cima para demostrar que la cima ha cambiado
    return popped_symbol;//retorna el elemento sacado
    

}
void ArrayStack::imprime(){//metodo imprimir
    for (int i = top-1; i >= 0; i--){
        cout << i+1 << ".- " << this->stack[i]->toString() << endl;//imprime los elementos de la cima para abajo
    }
    
}
bool ArrayStack::vacia(){//metodo vacia
    return top == 0;//retorna booleano para verificar si la pila esta vacia o no
}