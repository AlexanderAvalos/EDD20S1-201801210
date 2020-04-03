#ifndef NODO_MATRIZDISPERSA_H
#define NODO_MATRIZDISPERSA_H
#include "QString"
#include "datos_matrizdispersa.h"
using namespace std;


class nodoMatriz{
public:
    datosMatriz dato;
    QString numero;
    QString x,y;
    nodoMatriz *arriba,*abajo, *derecha, *izquierda;
    nodoMatriz *siguiente,*anterior;
    nodoMatriz(){

    }
    nodoMatriz(QString x, QString y){
        this->x = x;
        this->y = y;
        abajo = arriba = derecha = izquierda = siguiente = anterior = NULL;

    }
    QString getCorrelativo(){
        return this->x+this->y;
    }
    QString getX(){
        return this->x;
    }
    QString getY(){
        return this->y;
    }

};


class listahorizontal
{
public:
  nodoMatriz *primero;
  nodoMatriz *ultimo;
  int size;

  bool vacio(){
      if (primero == NULL){
      return true;
      }
      return false;
  }
  listahorizontal(){
      size = 0;
      this->primero = this->ultimo = NULL;
  }

  void imprimir(){
         nodoMatriz *temp = primero;
         while(temp!=nullptr){
            cout << temp->numero.toStdString()<<endl;
             temp = temp->derecha;
         }
     }
  void insertar(QString numero){
      nodoMatriz *nuevo = new nodoMatriz();
      nuevo->numero = numero;
      if (vacio()){
          primero= nuevo;
          ultimo = nuevo;
          size++;
          return;
      }else{
          agregar(nuevo);
          size++;
      }
  }

  void agregar(nodoMatriz *nodo){
      nodoMatriz *nodoaux = primero;
      bool existe = false;
      while(nodoaux != NULL){
          if(mayor(nodo,nodoaux)==true)
              nodoaux=nodoaux->derecha;
          else{
              if(nodoaux==primero){
                  nodo->derecha=nodoaux;
                   nodoaux->izquierda=nodo;
                  primero=nodo;
                  existe=true;
                  break;
              }else{
                  nodo->izquierda=nodoaux->izquierda;
                  nodoaux->izquierda->derecha=nodo;
                  nodo->derecha=nodoaux;
                  nodoaux->izquierda=nodo;
                  existe=true;
                  break;
              }
          }
      }
      if(existe==false){
          ultimo->derecha=nodo;
          nodo->izquierda=ultimo;
          ultimo=nodo;
      }
   }

  nodoMatriz *buscar(QString val){
      nodoMatriz *aux = primero;
      while(aux != NULL)
          if(aux->numero == val){
            return aux;
          }else{
              aux = aux->derecha;
          }
          return NULL;
      }

  int mayor(nodoMatriz *valor1, nodoMatriz*valor2){
      if(valor1->numero.compare(valor2->numero)>0){
          return true;
      }else
          return false;
  }

};

class listavertical
{
public:
  nodoMatriz *primero;
  nodoMatriz *ultimo;
  int size;

  bool vacio(){
      if (primero == NULL){
      return true;
      }
      return false;
  }
  listavertical(){
      size = 0;
      this->primero = this->ultimo = NULL;
  }

  void imprimir(){
         nodoMatriz *temp = primero;
         while(temp!=nullptr){
            cout << temp->numero.toStdString()<<endl;
             temp = temp->abajo;
         }
     }
  void insertar(QString numero){
      nodoMatriz *nuevo = new nodoMatriz();
      nuevo->numero = numero;
      if (vacio()){
          primero= nuevo;
          ultimo = nuevo;
          size++;
          return;
      }else{
          agregar(nuevo);
          size++;
      }
  }

  void agregar(nodoMatriz *nodo){
      nodoMatriz *nodoaux = primero;
      bool existe = false;
      while(nodoaux != NULL){
          if(mayor(nodo,nodoaux)==true)
              nodoaux=nodoaux->siguiente;
          else{
              if(nodoaux==primero){
                  nodo->abajo=nodoaux;
                   nodoaux->arriba=nodo;
                  primero=nodo;
                  existe=true;
                  break;
              }else{
                  nodo->arriba=nodoaux->arriba;
                  nodoaux->arriba->abajo=nodo;
                  nodo->abajo=nodoaux;
                  nodoaux->arriba=nodo;
                  existe=true;
                  break;
              }
          }
      }
      if(existe==false){
          ultimo->abajo=nodo;
          nodo->arriba=ultimo;
          ultimo=nodo;
      }
   }

  nodoMatriz *buscar(QString val){
      nodoMatriz *aux = primero;
      while(aux != NULL)
          if(aux->numero == val){
            return aux;
          }else{
              aux = aux->abajo;
          }
          return NULL;
      }

  int mayor(nodoMatriz *valor1, nodoMatriz*valor2){
      if(valor1->numero.compare(valor2->numero)>0){
          return true;
      }else
          return false;
  }

};





#endif // NODO_MATRIZDISPERSA_H
