#ifndef NODO_ARBOL_BUSQUEDA_H
#define NODO_ARBOL_BUSQUEDA_H
#include <QString>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <listadoble.h>
using namespace std;

class nodoArbol
{

public:
    QString datos;
    ListaDoble *fichas;
    nodoArbol *derecha;
    nodoArbol *izquierda;
    nodoArbol(QString nombre){
        this->fichas = new ListaDoble();
        datos = nombre;
        izquierda = derecha = NULL;
    }
};


#endif // NODO_ARBOL_BUSQUEDA_H
