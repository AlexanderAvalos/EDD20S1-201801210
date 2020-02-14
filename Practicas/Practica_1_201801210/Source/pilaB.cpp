#include "pilaB.h"
#include <stdlib.h>
#include <iostream>
#include <stdio.h>

struct Nodo{
    char dato;
    Nodo *Siguiente;
};
Nodo *npila = NULL;

bool pilaB::vacio(){
    if(npila == NULL){
        return true;
    }
    return false;
}
void pilaB::push(char data){
    Nodo *nuevo = new Nodo();
    nuevo->dato = data;
    if(vacio() == true){
        npila = nuevo;
        nuevo->Siguiente = NULL;
    }else{
        nuevo->Siguiente = npila;
        npila = nuevo;
    }
}

char pilaB::pop(){
    Nodo *aux = npila;
    npila = aux->Siguiente;
    return aux->dato;
    delete aux;
}
