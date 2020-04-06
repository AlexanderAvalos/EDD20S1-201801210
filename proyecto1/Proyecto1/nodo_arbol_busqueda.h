#ifndef NODO_ARBOL_BUSQUEDA_H
#define NODO_ARBOL_BUSQUEDA_H
#include <QString>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <listadoble.h>
#include <listasimplejp.h>
using namespace std;

class nodoArbol
{

public:
    QString datos;
    ListaDoble *lista;
    listasimpleJP *top;
    nodoArbol *derecha;
    nodoArbol *izquierda;
    nodoArbol(QString nombre){
        this->lista = new ListaDoble();
        this->top = new listasimpleJP();
        datos = nombre;
        izquierda = derecha = NULL;
    }
};


#endif // NODO_ARBOL_BUSQUEDA_H
