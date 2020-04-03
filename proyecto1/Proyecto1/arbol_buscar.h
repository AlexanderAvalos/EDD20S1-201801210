#ifndef ARBOL_BUSCAR_H
#define ARBOL_BUSCAR_H
#include <QString>
#include <fstream>
#include <QDebug>
#include <nodo_arbol_busqueda.h>
class arbol_busqueda{
public:
arbol_busqueda(){}
    void insertarDato(QString nombre){

        insertar(raiz,nombre);
    }
    void graficar(){
    graficar(raiz);
    }
    void graphviz(){
        graphviz(raiz,nullptr);
    }
    nodoArbol *buscar(QString valor){
         return buscar(valor, raiz);
     }

private:
    nodoArbol *raiz;
    ofstream salida;
    string prueba;
    void graphviz(nodoArbol *nodo, nodoArbol *padre ){

        if(nodo != nullptr){
            if(padre == nullptr){
                salida.open("ArbolBinario.txt");
                salida << "digraph { rankdir=UD "<<endl;
                salida << '\"' << nodo->datos.toStdString() << "\" ;"<<endl;
                graphviz(nodo->izquierda,nodo);
                graphviz(nodo->derecha,nodo);
                salida<< "}";
                salida.close();
                qInfo()<<system("dot -Tpng ArbolBinario.txt -o ArbolBinario.png");
            }
            else{
               salida << '\"'<< padre->datos.toStdString()<< '\"'<< "->" << '\"'<< nodo->datos.toStdString()<<"\" ;"<<endl;
               graphviz(nodo->izquierda,nodo);
               graphviz(nodo->derecha,nodo);
            }
        }
    }



    void graficar(nodoArbol *nodo){
        cout<<nodo->datos.toStdString()<<endl;
        if(nodo->izquierda != NULL){
            graficar(nodo->izquierda);
        }if (nodo->derecha != NULL){
            graficar(nodo->derecha);
        }
    }

    void insertar(nodoArbol *&arbol ,QString nombre){
        if (arbol == NULL) {
            arbol = new nodoArbol(nombre);
        }else{
            if (nombre.compare(arbol->datos)<0) {
                insertar(arbol->izquierda, nombre);
            }else if (nombre.compare(arbol->datos)>0){
                insertar(arbol->derecha, nombre);
            }else {
                printf("Error,nombre ya existe");
            }
        }
    }

    nodoArbol * buscar(QString valor, nodoArbol *nodo){
           if(valor.compare(nodo->datos)==0)
               return nodo;
           else{
               if(valor.compare(nodo->datos)<0)
               return buscar(valor,nodo->izquierda);
               else if(valor.compare(nodo->datos)>0)
               return buscar(valor,nodo->derecha);
           }
       }

};
#endif // ARBOL_BUSCAR_H
