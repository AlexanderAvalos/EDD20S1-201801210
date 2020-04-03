#ifndef LISTADOBLE_H
#define LISTADOBLE_H
#include <nodo_listadoble.h>
#include <fstream>
#include <QDebug>
class ListaDoble{
public:
    void insertar_Nodo(char ficha){
        nodo_listadoble *nuevo = new nodo_listadoble();
       if(vacio()== true){
              nuevo->ficha = ficha;
           primero = nuevo;
           nuevo->siguiente = NULL;
           nuevo->anterior = NULL;
           ultimo = primero;
       }
       else{
           nuevo->ficha = ficha;
           ultimo->siguiente = nuevo;
           nuevo->siguiente = NULL;
           nuevo->anterior =ultimo;
           ultimo=nuevo;
       }
   }
    void graficar(){

        nodo_listadoble *actual = new nodo_listadoble();
        actual = primero;
        salida.open("palabras_Jugador.txt");
        salida<<"digraph listadoble{  rankdir=LR  "<<endl;
        while(actual->siguiente != NULL){
            salida<< actual->ficha << "->" << actual->siguiente->ficha << " ;" <<endl;
            actual = actual->siguiente;
        }
        while(actual->anterior != NULL){
            salida << actual->ficha << " -> " << actual->anterior->ficha << ";" <<endl;
            actual = actual->anterior;
        }
        salida<<"}"<<endl;
        salida.close();
        qInfo()<<system("dot -Tpng palabras_Jugador.txt -o palabras_Jugador.png");
    }

private:
    nodo_listadoble *primero;
    nodo_listadoble *ultimo;
     ofstream salida;
    bool vacio(){
        if(primero == NULL && ultimo == NULL){
           return true;
        }
        return false;
    }


};

#endif // LISTADOBLE_H
