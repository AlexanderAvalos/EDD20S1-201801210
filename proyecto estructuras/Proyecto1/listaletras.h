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


    void llenar(char letra, int cant,int punteo){
        for (int i = 1; i <= cant; i++) {
            agregarletra(letra,punteo);
        }

    }

public:
    int tama =0;
    void recorrer(){
        nodoletra *aux = new nodoletra();
        aux = primero;
        while(aux != NULL){
            cout<<aux->caracter<<endl;
            aux = aux->siguiente;
        }
    }

    void agregarletra(char letra,int punteo){
        nodoletra *nuevo = new nodoletra();
        nuevo->caracter = letra;
        nuevo->punto = punteo;
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
    nodoletra *auxb = new nodoletra();
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
            auxb = aux->siguiente;
            aux->siguiente = auxb->siguiente;
            auxb->siguiente = NULL;
        }
        else {
            aux->siguiente = NULL;
        }
    }
    tama--;
    return letra;
    }

    void lista(){
        llenar('F',1,4);
        llenar('V',1,4);
        llenar('Y',1,4);
        llenar('Q',1,5);
        llenar('J',1,8);
        llenar('X',1,8);
        llenar('Z',1,10);
        llenar('A',12,1);
        llenar('E',12,1);
        llenar('O',9,1);
        llenar('I',6,1);
        llenar('S',6,1);
        llenar('N',5,1);
        llenar('L',4,1);
        llenar('R',5,1);
        llenar('U',5,1);
        llenar('D',5,2);
        llenar('G',2,2);
        llenar('C',4,3);
        llenar('B',2,3);
        llenar('M',2,3);
        llenar('P',2,3);
        llenar('H',2,4);
        llenar('T',4,1);

    }
};

#endif // LISTALETRAS_H
