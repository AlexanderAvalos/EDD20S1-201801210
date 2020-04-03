#ifndef LISTACIRULARDOBLE_H
#define LISTACIRULARDOBLE_H
#include <nodo_lista_circular.h>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <QDebug>
using namespace std;

class listaciruclardoble{

public:
    void insertar_Palabra(string palabra){
        nodocirular *nuevo = new nodocirular();

        if(vacio() == true){
            nuevo->palabra = palabra;
            primero = nuevo;
            nuevo->Siguiente = ultimo;
            nuevo->Anterior = primero;
            ultimo = primero;
        }else{
            nuevo->palabra = palabra;
            ultimo->Siguiente = nuevo;
            nuevo->Siguiente = primero;
            nuevo->Anterior = ultimo;
            ultimo = nuevo;
            primero->Anterior = ultimo;
        }
    }
      void graficar(){
          ofstream salida;
        nodocirular *aux = new nodocirular();
        aux = primero;
        salida.open("Diccionario.txt");
        salida<<"digraph listadoble{  rankdir=LR  "<<endl;
        do {
            salida << aux->palabra<< "->" << aux->Siguiente->palabra << ";"<< endl;
            aux = aux->Siguiente;
        } while (aux != primero);
        aux = ultimo;
        do {
            salida << aux->palabra<< "->" << aux->Anterior->palabra << ";"<< endl;
            aux=aux->Anterior;
        } while (aux != ultimo);
        salida<<"}"<<endl;
        salida.close();
        qInfo()<<system("dot -Tpng Diccionario.txt -o Diccionario.png");
      }

private:
    nodocirular *primero;
    nodocirular *ultimo;

    bool vacio(){
        if(primero == NULL && ultimo == NULL){
           return true;
        }
        return false;
    }

};

#endif // LISTACIRULARDOBLE_H
