#ifndef LISTASIMPLEJP_H
#define LISTASIMPLEJP_H
#include <nodo_listasimple_jp.h>
#include <iostream>
#include <fstream>
#include <QDebug>
using namespace std;

class listasimpleJP
{
private:
    nodo *primero;
    nodo *ultimo;
    ofstream salida;
    bool vacio(){
        if(primero == NULL && ultimo == NULL){
            return true;
        }
        return false;
    }

public:

    void graficaj1(){
        nodo *actual = new nodo();
        actual = primero;
        salida.open("puntajeJP1.txt");
        salida<<"digraph top{  rankdir=LR  "<<endl;
        salida<<" node [shape=rectangle];  "<<endl;
        while(actual != NULL){
            if(actual->siguiente != NULL){
            salida<< actual->puntuacion << "->";
            actual = actual->siguiente;
            }
            else{
                salida<< actual->puntuacion << ";";
                actual = actual->siguiente;
            }
        }
        salida<<"}"<<endl;
        salida.close();
        qInfo()<<system("dot -Tpng puntajeJP1.txt -o puntajeJP1.png");
    }


    void graficaj2(){
        nodo *actual = new nodo();
        actual = primero;
        salida.open("puntajeJP2.txt");
        salida<<"digraph top{  rankdir=LR  "<<endl;
        salida<<" node [shape=rectangle];  "<<endl;
        while(actual != NULL){
            if(actual->siguiente != NULL){
            salida<< actual->puntuacion << "->";
            actual = actual->siguiente;}
            else{
                salida<< actual->puntuacion << ";";
                actual = actual->siguiente;
            }
        }
        salida<<"}"<<endl;
        salida.close();
        qInfo()<<system("dot -Tpng puntajeJP2.txt -o puntajeJP2.png");
    }

    int  recorrer(){
        int total;
        nodo *aux = new nodo();
        aux = primero;
        while(aux != NULL){
           total = total + aux->puntuacion;
           aux = aux->siguiente;
        }
        return total;
    }
    void agregarpunteo(int puntos){
        nodo *nuevo = new nodo();
            nuevo->puntuacion = puntos;
            if (vacio())
            {
                primero = nuevo;
                ultimo = primero;
            }
            else
            {
                if(puntos > primero->puntuacion){
                    nuevo->siguiente = primero;
                    primero = nuevo;
                }
                else {
                    nodo *aux = primero;
                    nodo *auxb = primero;
                    while (puntos <= aux->puntuacion && aux->siguiente != NULL)
                    {
                        auxb = aux;
                        aux = aux->siguiente;
                        ultimo = aux;
                    }
                    if (puntos <= aux->puntuacion)
                    {
                        nuevo->siguiente = aux->siguiente;
                         aux->siguiente = nuevo;
                    }
                    else
                    {
                        nuevo->siguiente = aux;
                        auxb->siguiente = nuevo;
                    }

                }
            }
}

};
#endif // LISTASIMPLEJP_H
