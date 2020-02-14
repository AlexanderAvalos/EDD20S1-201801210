#include "lista_circular.h"
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
using namespace std;


struct Nodo{
    char dato;
    Nodo *siguiente;
};
Nodo *primeroC = NULL;
Nodo *ultimoC = NULL;

bool lista_circular::vacio(){
    if(primeroC == NULL){
       return true;
    }
    return false;
}

void lista_circular::insertar_NodoC(char data){
    Nodo *nuevo = new Nodo();
    nuevo->dato = data;
    if(vacio()==true){
        primeroC = nuevo;
        nuevo->siguiente = ultimoC;
        ultimoC = primeroC;
    }else{
        ultimoC->siguiente =nuevo;
        nuevo->siguiente = primeroC;
        ultimoC = nuevo;
    }
}

void lista_circular::mostrar_Lista(){
    Nodo *actual = new Nodo();
    actual = primeroC;
    if (vacio()!=true){
        do{
            cout<< actual->dato <<"->";
            actual = actual->siguiente;
       }while(actual != primeroC);
         cout<<"\n";
    }
}
