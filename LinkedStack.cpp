#include "LinkedStack.h"
LinkedStack::LinkedStack(){
    this->first = nullptr;
    top = 0;
}
LinkedStack::~LinkedStack(){
    if(first)
        delete first;
}
void LinkedStack::anula(){
    delete first;
}
void LinkedStack::push(Object* dato){
    if(vacia()){
        first->setDato(dato);
    }
    else{
        Node* temporal = first;
        first->setDato(dato);
        first->setSiguiente(temporal);
    }
    top++;
}
Object* LinkedStack::peek(){
    return first->getDato();
}
Object* LinkedStack::pop(){
    if(top == 1){
        Node* temporal = first;
        first = nullptr;
        top--;
        return temporal->getDato();
    }
    else{
        Node* temporal = first;
        first = first->getSiguiente();
        first->setAnterior(nullptr);
        top--;
        return temporal->getDato();
    }
}
void LinkedStack::imprime(){
    Node* temporal = first;
    for (int i = 0; i < top; i++){
        cout << i+1 << ".- " <<first->getDato()->toString() << endl;
        temporal = first->getSiguiente();
    }
    
}
bool LinkedStack::vacia(){
    return top = 0;
}