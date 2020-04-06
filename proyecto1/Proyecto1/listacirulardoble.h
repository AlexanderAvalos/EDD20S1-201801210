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
    void insertar_Palabra(QString palabra){
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
        size++;
    }
      void graficar(){
        int con = size;

        nodocirular *aux = new nodocirular();
        aux = primero;
        salida.open("Diccionario.txt");
        salida<<"digraph listadoble{  rankdir=LR  "<<endl;
        do {
            if(con > 1){
            salida << aux->palabra.toStdString()<< "->" ;
            aux = aux->Siguiente;
            con--;}
            else{
                salida << aux->palabra.toStdString()<<"->"<<primero->palabra.toStdString() ;
                aux = primero;
            }
        } while (aux != primero);
        salida << ";"<<endl;
        con = size;
        aux = ultimo;
        do {
            if(con > 1){
            salida << aux->palabra.toStdString()<< "->";
            aux=aux->Anterior;
            con--;
            }else{
                salida << aux->palabra.toStdString()<<"->"<<ultimo->palabra.toStdString();
               aux=ultimo;
            }
        } while (aux != ultimo);
        salida<<";"<<endl;
        salida<<"}"<<endl;
        salida.close();

        qInfo()<<system("dot -Tpng Diccionario.txt -o Diccionario.png");
      }

      bool buscar(QString palabra){
          nodocirular *aux = new nodocirular();
          aux = primero;
          do{
              if(palabra == aux->palabra){
                  return true;
              }
              aux = aux->Siguiente;
          }while(aux!=primero);
          return false;
      }

private:
    nodocirular *primero;
    nodocirular *ultimo;
    int size = 0;
    ofstream salida;

    bool vacio(){
        if(primero == NULL && ultimo == NULL){
           return true;
        }
        return false;
    }

};

#endif // LISTACIRULARDOBLE_H
