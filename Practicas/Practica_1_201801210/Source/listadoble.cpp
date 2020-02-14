#include "listadoble.h"
#include <stdlib.h>
#include <iostream>
#include <stdio.h>

struct Nodo{
    char caracter;
    Nodo *Siguiente;
    Nodo *Anterior;
};
Nodo *primero = NULL;
Nodo *ultimo = NULL;

    bool Vacio(){
        if(primero == NULL){
           return true;
        }
        return false;
    }

     void insertar_Nodo(char dato){
        Nodo *nuevo = new Nodo();
        nuevo->caracter = dato;
        if(Vacio == true){
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
    void mostrar_Derecha_a_Izquierda(){
        Nodo *actual = new Nodo();
        actual = primero;
        if(Vacio() != True){
            while (actual != NULL) {
                cout<< actual->caracter ;
                actual = actual->Siguiente;
            }
        }
        else{cout <<"lista vacia";}
    }
    void mostrar_Izquierda_a_Derecha(){
        Nodo *actual = new Nodo();
        actual = ultimo;
        if(Vacio() != True){
            while (actual != NULL) {
                cout<< actual->caracter ;
                actual = actual->Anterior;
            }
        }
        else{cout <<"lista vacia";}
    }


