#include "TDACola.h"
#include "iostream"

using namespace std;


TDACola::TDACola(/* args */)
{
    size = 0;
    capacidad = 10000;
    array = new Object*[capacidad];
}

TDACola::~TDACola()
{
    
}


bool TDACola:: encolar(Object* objeto){
    array[size] = objeto;
    size++;
}

bool TDACola:: desencolar(){
    array[0] = nullptr;
    size--;
}

void TDACola:: verfrente(){
    cout << array[0];
}

bool TDACola:: IsVacio(){
    if (size <= 0)
    {
        return true;
    } else{
        return false;
    }
    
}

void TDACola:: imprime(){
    for (size_t i = 0; i < size; i++)
    {
        cout << array[i] << endl;
    }
    
}

void TDACola:: anula(){
    for (size_t i = 0; i < size; i++)
    {
        array[i] = nullptr;
    }

    size = 0;
    
}