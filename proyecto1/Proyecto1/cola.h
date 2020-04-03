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
           salida<<"<tr><td>" << aux->letra<< "</td></tr>"<<endl;
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
    int valor = rand() % max--;
    if(max == 0){
    }else if(valor !=0){
        push(lista->eliminar(lista->buscar(valor)));
        llenarcola();
    }else {
         push(lista->eliminar(lista->buscar(valor+1)));
        llenarcola();
    }
    recorrer();
}

    void push(char letra ){
        nodoCola *nuevo = new nodoCola();
        nuevo->letra = letra;
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
        char info =aux->letra;
        aux = raiz;
        if(vacio()){
            return 0;
        }else {
            raiz  = aux->siguiente ;
            delete aux;
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
