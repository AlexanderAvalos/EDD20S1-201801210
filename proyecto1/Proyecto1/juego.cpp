#include <listadoble.h>
#include <listacirulardoble.h>
#include <listaletras.h>
#include <listasimplejp.h>
#include <arbol_buscar.h>
#include <matrizdispersa.h>
#include <cola.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <QString>
#include <stdio.h>
#include<random>
#include <juego.h>
using namespace std;

arbol_busqueda *arbol = new arbol_busqueda();

void juego::crearJugador(){
    string aux;
    QString nombre;
    cout<<"ingrese nombre jugador"<<endl;
    cin>>aux;
    nombre = QString::fromStdString(aux);
    arbol->insertarDato(nombre);
    arbol->graphviz();
}

void juego::elegirJugadores(){
    string aux;
    QString nombre;
    cout<<"ingrese nombre jugador"<<endl;
    cin>>aux;
    nombre = QString::fromStdString(aux);
    nodoArbol *auxi = arbol->buscar(nombre);
    auxi->fichas->insertar_Nodo('a');
    auxi->fichas->graficar();
}
