#ifndef COLA_H
#define COLA_H
#include <nodocola.h>
#include <fstream>
#include <QDebug>
#include <listaletras.h>
#include<random>

using namespace std;

class cola{
private:
    nodoCola *cima;
    nodoCola *raiz;
    ofstream salida;
    listaletra *lista = new listaletra();

    bool vacio(){
        if (raiz == NULL){
            return true;
        }
        return false;
    }


public:
int max=95;
void graficar(){
       nodoCola *aux = new nodoCola();
       aux = raiz;
       salida.open("fichas.txt");
       salida<<"digraph fichas{"<<endl;
       salida<< "node [shape=plaintext]"<<endl;
       salida<<"some_node  ["<<endl;
       salida <<"label=<"<<endl;
       salida <<"<table border=\"0\" cellborder=\"1\" cellspacing=\"0\">"<<endl;
       while (aux->siguiente!=NULL) {
           salida<<"<tr><td>" << aux->letra<<" x " <<aux->punteo<<"</td></tr>"<<endl;
           aux = aux->siguiente;
       }
       salida << "</table>> "<<endl;
       salida<<"];"<<endl;
       salida<<"}" <<endl;
       salida.close();
       qInfo()<<system("dot -Tpng fichas.txt -o fichas.png");
}

void listaa(){
    lista->lista();
    llenarcola();
}
void llenarcola(){
    srand(time(NULL));
    int valor = 1 + rand() % max--;
    if(max == 0){

    }
    else if(valor !=0){
        push(lista->buscar(valor)->punto,lista->eliminar(lista->buscar(valor)));
        llenarcola();
    }else {
           push(lista->buscar(valor)->punto, lista->eliminar(lista->buscar(valor)) );
           llenarcola();
       }
}

    void push(int puntos,char letra){
        nodoCola *nuevo = new nodoCola();
        nuevo->letra = letra;
        nuevo->punteo = puntos;
        if (vacio()){
            raiz = nuevo;
            nuevo->siguiente = NULL;
            cima = raiz;
        }else {
            cima->siguiente = nuevo;
            nuevo->siguiente = NULL;
            cima = nuevo;
        }
    }

    char pop(){
        nodoCola *aux = new nodoCola();
        aux = this->raiz;
        char info =aux->letra;
        if(vacio()){
            return 0;
        }else {
            raiz  = aux->siguiente ;
            delete aux;
            return info;
        }
    }
    int top(){
        nodoCola *aux = new nodoCola();
        aux = this->raiz;
        int info =aux->punteo;
        if(vacio()){
            return 0;
        }else {
            raiz  = aux->siguiente ;
            return info;
        }
    }

    void recorrer(){
        nodoCola *actual = raiz;
        while (actual!=NULL) {
            cout<< actual->letra<<endl;
            actual = actual->siguiente;
        }
    }

};
#endif // COLA_H
