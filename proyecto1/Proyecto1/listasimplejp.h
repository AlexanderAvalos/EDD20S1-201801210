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

    void grafica(){
        nodo *actual = new nodo();
        actual = primero;
        salida.open("/home/alex/Escritorio/puntaje.txt");
        salida<<"digraph top{  rankdir=LR  "<<endl;
        salida<<" node [shape=rectangle];  "<<endl;
        while(actual->siguiente != NULL){
            salida<< actual->puntuacion << "->" << actual->siguiente->puntuacion << " ;" <<endl;
            actual = actual->siguiente;
        }
        salida<<"}"<<endl;
        salida.close();
        qInfo()<<system("dot -Tpng /home/alex/Escritorio/puntaje.txt -o /home/alex/Escritorio/puntaje.png");
    }

    void recorrer(){
        nodo *aux = new nodo();
        aux = primero;
        while(aux != NULL){
            cout<<aux->puntuacion<<endl;
            aux = aux->siguiente;
        }
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
                    }
                    if (puntos <= aux->puntuacion)
                    { nuevo->siguiente = aux->siguiente;
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
