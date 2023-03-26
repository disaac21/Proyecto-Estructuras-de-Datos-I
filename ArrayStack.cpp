#include <iostream>
#include "ArrayStack.h"
using namespace std;

ArrayStack::ArrayStack(){
    this->top = 0;
    stack = new Object*[100];
}
ArrayStack::~ArrayStack(){
    this->anula();
    delete[] stack;
}
void ArrayStack::anula(){
    if(!vacia()){
        for (int i = 0; i < top; i++)
            delete stack[i];
    }
    
}
void ArrayStack::push(Object* simbolo){
    Object** temp_stack = new Object*[top+1];
    if(!vacia()){
        for (int i = 0; i < top; i++){
            temp_stack[i] = stack[i];
        }
    }
    temp_stack[top] = simbolo;
    stack = temp_stack;
    top++;
}
Object* ArrayStack::peek(){
    return stack[top-1];
}
Object* ArrayStack::pop(){
    Object* popped_symbol = stack[top-1];
    Object** temp_stack = new Object*[top-1];
    for (int i = 0; i < top-1; i++)
    {
        temp_stack[i] = stack[i];
    }
    stack = temp_stack;
    top--;
    return popped_symbol;
    

}
void ArrayStack::imprime(){
    for (int i = top-1; i >= top; i--){
        cout << i+1 << ".- " << this->stack[i]->toString() << endl;
    }
    
}
bool ArrayStack::vacia(){
    return top == 0;
}