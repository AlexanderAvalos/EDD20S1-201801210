#include "datos_pila.h"
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
using namespace std;

class NodoP
{
public:
    datosP *ultimoP = NULL;
    datosP *primeroP = NULL;

    bool vacio(){
        if(primeroP == NULL){
            return true;
        }
        return false;
    }

    void push(string palabraB, string palabraR, string estado ){
        datosP *nuevo = new datosP();
        nuevo->setestado(estado);
        nuevo->setpalabraB(palabraB);
        nuevo->setpalabraR(palabraR);
        if(vacio() == true){
            primeroP = nuevo;
            ultimoP = primeroP;
            nuevo->setsiguiente(NULL);
        }else{
            nuevo->setsiguiente(ultimoP);
            ultimoP = nuevo;
        }
    }

    datosP *pop(){
         datosP *aux = new datosP();
         aux = ultimoP;
        if(aux == NULL){

        }else{
        ultimoP = aux->getsiguiente();
        return aux;
        delete aux;}
    }
};
