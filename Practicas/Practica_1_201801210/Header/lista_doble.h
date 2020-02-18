#include "caracter.h"
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

class Nodo{
public:
    Caracter *primero = NULL;
    Caracter *ultimo =NULL;

    bool vacio(){
        if(primero == NULL){
           return true;
        }
        return false;
    }
    void borrar_ultimo(){
        Caracter *auxB = ultimo->getanterior();
        auxB->setsiguiente(NULL);
        ultimo = auxB;
    }
     void insertar_Nodo(char dato){
        Caracter *nuevo = new Caracter();
        nuevo->setcaracter(dato);
        if(vacio()== true){
            primero = nuevo;
            nuevo->setsiguiente(NULL);
            nuevo->setanterior(NULL);
            ultimo = primero;
        }
        else{
            ultimo->setsiguiente(nuevo);
            nuevo->setsiguiente(NULL);
            nuevo->setanterior(ultimo);
            ultimo=nuevo;
        }
    }

    void borrar_lista(){
        primero = NULL;
        ultimo = NULL;
    }


    void mostrar_Derecha_a_Izquierda(){
        Caracter *actual = new Caracter();
        actual = primero;
        if(vacio() != true){
            while (actual != NULL) {
                cout<< actual->getcaracter() <<"->";
                actual = actual->getsiguiente();
            }
             cout<< "\n";
        }
        else{cout <<"lista vacia";}
    }
    void mostrar_Izquierda_a_Derecha(){
        Caracter *actual = new Caracter();
        actual = ultimo;
        if(vacio() != true){
            while (actual != NULL) {
                cout<<actual->getcaracter()<<"->";
                actual = actual->getanterior();
            }
            cout<< "\n";
        }
        else{cout <<"lista vacia";}
    }
};
