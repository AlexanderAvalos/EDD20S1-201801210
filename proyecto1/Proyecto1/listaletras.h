#ifndef LISTALETRAS_H
#define LISTALETRAS_H
#include "nodolista.h"
#include <random>

class listaletra{
private:
    nodoletra *primero;
    nodoletra *ultimo;

    bool vacio(){
        if(primero == NULL && ultimo == NULL){
            return true;
        }
        return false;
    }


    void llenar(char letra, int cant){
        for (int i = 1; i <= cant; i++) {
            agregarletra(letra);
        }

    }

public:
    int tama =1;
    void recorrer(){
        nodoletra *aux = new nodoletra();
        aux = primero;
        while(aux != NULL){
            cout<<aux->caracter<<endl;
            aux = aux->siguiente;
        }
    }
    void agregarletra(char letra){
        nodoletra *nuevo = new nodoletra();
        nuevo->caracter = letra;
        if(vacio()){
            primero = nuevo;
            nuevo->siguiente = NULL;
            ultimo = primero;
        }else{
            ultimo->siguiente = nuevo;
            ultimo = nuevo;
            nuevo->siguiente = NULL;
        }
        tama++;
    }
    nodoletra *buscar(int tam){
        nodoletra *aux = new  nodoletra();
        aux = primero;
        int contador = 1;
        if(tam == 1){
        return primero;
        }else{
            while (contador != (tam-1)) {

                aux = aux->siguiente;
                contador++;
            }
            return aux;
        }

    }

    char eliminar(nodoletra *nodo){
    nodoletra *aux = new nodoletra();
    char letra;
    aux = primero;
    if (nodo == primero){
        letra = primero->caracter;
        primero = primero->siguiente;
        nodo->siguiente = NULL;
    }else{
        while(aux != nodo){
            aux = aux->siguiente;
        }
        letra = aux->caracter;
        if(aux != ultimo){
            aux->siguiente = aux->siguiente->siguiente;
        }
        else {
            aux->siguiente = NULL;
        }
    }
    tama--;
    return letra;
    }
    void lista(){
        llenar('A',12);
        llenar('E',12);
        llenar('O',9);
        llenar('I',6);
        llenar('S',6);
        llenar('N',5);
        llenar('L',4);
        llenar('R',5);
        llenar('U',5);
        llenar('T',4);
        llenar('D',5);
        llenar('G',2);
        llenar('C',4);
        llenar('B',2);
        llenar('M',2);
        llenar('P',2);
        llenar('H',2);
        llenar('F',1);
        llenar('V',1);
        llenar('Y',1);
        llenar('Q',1);
        llenar('J',1);
        llenar('X',1);
        llenar('Z',1);
    }
};

#endif // LISTALETRAS_H
