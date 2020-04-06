#ifndef LISTADOBLE_H
#define LISTADOBLE_H
#include <nodo_listadoble.h>
#include <cola.h>
#include <fstream>
#include <QDebug>
class ListaDoble{
public:
    void insertar_Nodo(int puntos,char ficha){
        nodo_listadoble *nuevo = new nodo_listadoble();
       if(vacio()== true){
           nuevo->ficha = ficha;
           nuevo->puntos= puntos;
           primero = nuevo;
           nuevo->siguiente = NULL;
           nuevo->anterior = NULL;
           ultimo = primero;
       }
       else{
           nuevo->ficha = ficha;
           nuevo->puntos = puntos;
           ultimo->siguiente = nuevo;
           nuevo->siguiente = NULL;
           nuevo->anterior =ultimo;
           ultimo=nuevo;
       }
       size++;
   }

    void vaciar(cola *lista){
        nodo_listadoble *aux = new nodo_listadoble();
        aux = primero;
        while(aux != NULL){
            lista->push(aux->puntos,aux->ficha);
            aux = aux->siguiente;
        }
    }
    void limpiar(){
        primero = NULL;
        ultimo = primero;
        size = 0;
    }
    int buscar(char letra){
        nodo_listadoble *aux = new nodo_listadoble();
        aux = primero;
        while(aux != NULL){
            if(letra == aux->ficha){
                return aux->puntos;
            }
            aux = aux->siguiente;
        }
        return 0;
    }

    bool buscar1(char letra){
        nodo_listadoble *aux = new nodo_listadoble();
        aux = primero;
        while(aux != NULL){
            if(letra == aux->ficha){
                return true;
            }
            aux = aux->siguiente;
        }
        return false;
    }

    nodo_listadoble *search(char letra){
        nodo_listadoble *aux = new nodo_listadoble();
        aux = primero;
       if(vacio()){
           cout<<"no hay fichas"<<endl;
       }else{
           while(aux != NULL){
            if(letra == aux->ficha){
                return aux;
            }
            aux = aux->siguiente;
           }
       }
        return NULL;
    }


    nodo_listadoble *sacar(char letra){
        nodo_listadoble *actual = new nodo_listadoble();
        nodo_listadoble *aux = search(letra);
        actual = primero;
        if(aux != NULL){
             if(aux == primero){
                 primero = actual->siguiente;
                 primero->anterior = NULL;
                 actual->siguiente = NULL;
                  size --;
                 return actual;
            }else{
                 while(actual != NULL){
                     if(aux == ultimo){
                         ultimo = actual->anterior;
                         ultimo->siguiente = NULL;
                         actual->anterior = NULL;
                         size --;
                         return actual;
                     }
                     else{
                         actual = aux->anterior;
                         actual->siguiente = aux->siguiente;
                         actual = aux->siguiente;
                         actual->anterior = aux->anterior;
                         actual = aux;
                         actual->siguiente = NULL;
                         actual->anterior = NULL;
                          size --;
                         return actual;
                     }
                     actual = actual->siguiente;
                 }
             }
        }else{
            cout<<"no existe"<<endl;
        }
        return NULL;
    }


    void graficar1(){
        int con = size;
        nodo_listadoble *actual = new nodo_listadoble();
        actual = primero;
        salida.open("palabras_Jugador1.txt");
        salida<<"digraph listadoble{  rankdir=LR  "<<endl;
        int cont=0;
        while(actual != NULL){
            salida<< actual->ficha <<cont++<<" [label = "<<'\"'<< actual->ficha << ","<<actual->puntos<<" \"];"<<endl;
            actual = actual->siguiente;
        }
        cont =0;
        actual = primero;
        while(actual != NULL){
            if(con > 1){
                salida<< actual->ficha << cont++<< "->" ;
                actual = actual->siguiente;
                con--;
            }else {
                salida<< actual->ficha<<cont++;
                 actual = actual->siguiente;
            }
        }
        salida <<";"<<endl;
        cont= cont-1;
        actual= ultimo;
        con = size;
        while(actual != NULL){
            if(con > 1){
                salida<< actual->ficha <<cont--<< "->" ;
                actual = actual->anterior;
                con--;
            }else {
                salida<< actual->ficha<<cont--;
                 actual = actual->anterior;
            }
        }
        salida <<";"<<endl;
        salida<<"}"<<endl;
        salida.close();
        qInfo()<<system("dot -Tpng palabras_Jugador1.txt -o palabras_Jugador1.png");
    }

    void graficar2(){
        int con = size;
        nodo_listadoble *actual = new nodo_listadoble();
        actual = primero;
        salida.open("palabras_Jugador2.txt");
        salida<<"digraph listadoble{  rankdir=LR  "<<endl;
        int cont=0;
        while(actual != NULL){
            salida<< actual->ficha <<cont++<<" [label = "<<'\"'<< actual->ficha << ","<<actual->puntos<<" \"];"<<endl;
            actual = actual->siguiente;
        }
        cont =0;
        actual = primero;
        while(actual != NULL){
            if(con > 1){
                salida<< actual->ficha << cont++<< "->" ;
                actual = actual->siguiente;
                con--;
            }else {
                salida<< actual->ficha<<cont++;
                 actual = actual->siguiente;
            }
        }
        salida <<";"<<endl;
        cont= cont-1;
        actual= ultimo;
        con = size;
        while(actual != NULL){
            if(con > 1){
                salida<< actual->ficha <<cont--<< "->" ;
                actual = actual->anterior;
                con--;
            }else {
                salida<< actual->ficha<<cont--;
                 actual = actual->anterior;
            }
        }
        salida <<";"<<endl;
        salida<<"}"<<endl;
        salida.close();
        qInfo()<<system("dot -Tpng palabras_Jugador2.txt -o palabras_Jugador2.png");
    }

private:
    nodo_listadoble *primero;
    nodo_listadoble *ultimo;
    int size;
    ofstream salida;
    bool vacio(){
        if(primero == NULL && ultimo == NULL){
           return true;
        }
        return false;
    }


};

#endif // LISTADOBLE_H
