#include "lista_doble.h"
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int largo=0;
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
        primero->Anterior = nuevo;
        nuevo->Anterior = NULL;
        nuevo->Siguiente = primero;
        primero=nuevo;
    }
}
void lista_Doble::mostrar_Izquierda_a_Derecha(){
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
void lista_Doble::mostrar_Derecha_a_Izquierda(){
    Nodo *actual = new Nodo();
    actual = ultimo;
    if(vacio() != true){
        while (actual != NULL) {
            cout<<actual->caracter <<"<-";
            actual = actual->Anterior;
        }
        cout<< "\n";
    }
    else{cout <<"lista vacia";}
}
void lista_Doble::eliminar_Ultimo(){
    Nodo *auxB = new Nodo();
    auxB = ultimo->Anterior;
    auxB->Siguiente = NULL;
    ultimo = auxB;
}

void lista_Doble::buscar_Cadena(string cadenaE, int lar){
    Nodo *actual=new Nodo();
    Nodo *u_Caracter, *p_Caracter;
    actual = ultimo;
    while (actual != NULL){
        if(largo<lar){
            if(cadenaE[largo] == actual->caracter){
                if(largo==0){
                    p_Caracter = actual;
                }else if(largo == (lar-1)){
                    u_Caracter = actual;
                }
                largo ++;
            }else {
                largo = 0;
                u_Caracter = p_Caracter =NULL;
            }
        }
        actual = actual->Anterior;
    }
    if(p_Caracter != NULL && u_Caracter != NULL){
       cout<<"Caracter encontrado"<<"-> "<< p_Caracter->caracter<<endl;
    }else{
        cout<<"no se encontro coincidencia"<<endl;
    }
}
