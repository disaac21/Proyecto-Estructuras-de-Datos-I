#include "LinkedStack.h"
LinkedStack::LinkedStack(){//constructor
    first = new Node();//inicializa el nodo
    top = 0;//inicializa la cima de la pila en 0
}
LinkedStack::~LinkedStack(){//destructor
    if(first)
        delete first;//elimina el nodo First, el cual eliminara a todos
}
void LinkedStack::anula(){//metodo anula
    delete first;//elimina el nodo First, el cual eliminara a todos
}
void LinkedStack::push(Object* dato){//metodo que empuja los simbolos
    if(vacia()){//verifica si el nodo First esta vacio
        first->setDato(dato);//al nodo first se le asigna el dato
    }
    else{//Si no esta vacio
        Node* temporal = first;//se guarda el dato first en una variable temporal
        first->setDato(dato);//al nodo first se le asigna el valor que se empuja
        first->setSiguiente(temporal);//Al siguiente valor se asigna el dato que estaba antes en first
    }
    dato = nullptr;
    top++;
}
Object* LinkedStack::peek(){//metodo para ver el elemento al cima de la pila
    return first->getDato();//retorna el dato que esta en la nodo first
}
Object* LinkedStack::pop(){//metodo para sacar elementos de la pila
    if (this->first == nullptr) {
        cout << endl << "La Lista Está Vacía." << endl;
    } else {
        if(top == 1){//verifica si la cima de la pila esta en la primera posicion
            Node* temporal = first;//se guarda el elemento que se sacara en un nodo temporal
            first = nullptr;//el nodo first se vuelve nulo
            top--;//la cima de la pila queda en 0
            return temporal->getDato();//se retorna el dato que se saco
        } else{
            Node* temporal = first;//se guarda el elemento que se sacara en un nodo temporal
            first = first->getSiguiente();//el nuevo dato del nodo first pasa a ser el dato que estaba al siguiente de el
            first->setAnterior(nullptr);//valor anterior es nulo
            top--;//posicion donde esta la cima disminuye una posicion
            return temporal->getDato();//retorna el dato que se saco
        }
    }
}
void LinkedStack::imprime(){//metodo imprimir los simbolos
    Node* temporal = first;//nodo temporal donde se guardara el nodo siguiente para poder imprimir los otros datos
    for (int i = 0; i < top; i++){
        cout << i+1 << ".- " <<first->getDato()->toString() << endl;//imprime el dato que esta en el nodo first
        temporal = first->getSiguiente();//se asigna a temporal el nodo siguiente de first
    }
    
}
bool LinkedStack::vacia(){//metodo vacia
    return top == 0;//si esta en 0, el nodo first esta vacio
}