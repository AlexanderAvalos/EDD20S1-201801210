#include "datos_ruta.h"
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
using namespace std;

class NodoC
{
private:
    Rutas *rutas;
public:
  Rutas *primeroC;
  Rutas *ultimoC;

  bool vacio(){
      if(primeroC == NULL){
         return true;
      }
      return false;
  }

  void insertar_NodoC(string nombre,string direccion){
      Rutas *nuevo = new Rutas();
      nuevo->setnombre(nombre);
      nuevo->setdireccion(direccion);
      if(vacio()==true){
          primeroC = nuevo;
          nuevo->setsiguiente(ultimoC);
          ultimoC = primeroC;
      }else{
          ultimoC->setsiguiente(nuevo);
          nuevo->setsiguiente(primeroC);
          ultimoC = nuevo;
      }
  }

  void imprimir(){
      Rutas *aux = new Rutas();
          aux=primeroC;
          int i=1;

          if(primeroC!=NULL)
           {
                do
                {    cout<<"  "<<aux->getnombre();
                    cout<<" "<<aux->getdireccion();
                     aux = aux->getsiguiente();
                     i++;
                }while(aux!=primeroC);
            }
           else
               cout<<"\n\n\tLista vacia...!"<<endl;
  }
};
