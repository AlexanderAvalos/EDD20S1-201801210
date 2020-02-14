#include "lista_doble.h"
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
using namespace std;

struct Nodo{
    char caracter;
    Nodo *Siguiente;
    Nodo *Anterior;
};
Nodo *primero = NULL;
Nodo *ultimo =NULL;

bool lista_Doble::vacio(){
    if(primero == NULL){
       return true;
    }
    return false;
}

 void lista_Doble::insertar_Nodo(char dato){
    Nodo *nuevo = new Nodo();
    nuevo->caracter = dato;
    if(vacio()== true){
        primero = nuevo;
        nuevo->Anterior =NULL;
        nuevo->Siguiente =NULL;
        ultimo = primero;
    }
    else{
        ultimo->Siguiente = nuevo;
        nuevo->Siguiente = NULL;
        nuevo->Anterior = ultimo;
        ultimo=nuevo;
    }
}
void lista_Doble::mostrar_Derecha_a_Izquierda(){
    Nodo *actual = new Nodo();
    actual = primero;
    if(vacio() != true){
        while (actual != NULL) {
            cout<< actual->caracter <<"->";
            actual = actual->Siguiente;
        }
         cout<< "\n";
    }
    else{cout <<"lista vacia";}
}
void lista_Doble::mostrar_Izquierda_a_Derecha(){
    Nodo *actual = new Nodo();
    actual = ultimo;
    if(vacio() != true){
        while (actual != NULL) {
            cout<<actual->caracter <<"->";
            actual = actual->Anterior;
        }
        cout<< "\n";
    }
    else{cout <<"lista vacia";}
}

