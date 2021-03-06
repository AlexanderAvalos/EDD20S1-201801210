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
    void inOrden(){
        in(raiz);
        salida.open("InOrden.txt");
        salida << "digraph { rankdir=LR "<<endl;
        salida<<" node [shape=rectangle];  "<<endl;
         inOrden(raiz);
        salida<< "}"<<endl;
        salida.close();
        qInfo()<<system("dot -Tpng InOrden.txt -o InOrden.png");
    }
    void preOrden(){
        pre(raiz);
        salida.open("preOrden.txt");
        salida << "digraph { rankdir=LR "<<endl;
        salida<<" node [shape=rectangle];  "<<endl;
        preOrden(raiz);
        salida<< "}"<<endl;
        salida.close();
        qInfo()<<system("dot -Tpng preOrden.txt -o preOrden.png");
    }
    void postOrden(){
        post(raiz);
        salida.open("postOrden.txt");
        salida << "digraph { rankdir=LR "<<endl;
        salida<<" node [shape=rectangle];  "<<endl;
        postOrden(raiz);
        salida<< "}"<<endl;
        salida.close();
        qInfo()<<system("dot -Tpng postOrden.txt -o postOrden.png");
    }

private:
    nodoArbol *raiz;
    nodoArbol *aux;
    ofstream salida;

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

    void inOrden(nodoArbol *nodo){
        if(nodo->izquierda != nullptr){
           inOrden(nodo->izquierda);
           salida<< aux->datos.toStdString() << "->" << nodo->datos.toStdString()<< ";"<<endl;
           aux = nodo->izquierda;
        }
      salida << nodo->datos.toStdString()  <<";"<<endl;
        aux = nodo;
        if(nodo->derecha != nullptr){
            salida << aux->datos.toStdString() << "->" << nodo->derecha->datos.toStdString() << ";"<<endl;
            aux = nodo->derecha;
            inOrden(nodo->derecha);
        }
    }

    void preOrden(nodoArbol *nodo){
        salida<< nodo->datos.toStdString()  <<";"<<endl;
        aux = nodo;
        if(nodo->izquierda != nullptr){
          salida<< aux->datos.toStdString() << "->" << nodo->izquierda->datos.toStdString()<< ";"<<endl;
           aux = nodo->izquierda;
            preOrden(nodo->izquierda);
        }
        if(nodo->derecha != nullptr){
            salida << aux->datos.toStdString() << "->" << nodo->derecha->datos.toStdString() << ";"<<endl;
            preOrden(nodo->derecha);
            aux = nodo->derecha;
        }
    }

    void postOrden(nodoArbol *nodo){
        if(nodo->izquierda != nullptr){
           aux = nodo->izquierda;
            postOrden(nodo->izquierda);
        }
        if(nodo->derecha != nullptr){
            salida << aux->datos.toStdString() << "->" << nodo->derecha->datos.toStdString() << ";"<<endl;
            aux = nodo->derecha;
            postOrden(nodo->derecha);
            salida << aux->datos.toStdString() << "->" << nodo->datos.toStdString() << ";"<<endl;
        }
        salida<< nodo->datos.toStdString()  +";"<<endl;
        aux = nodo;
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

    void post(nodoArbol *nodo){
         if(nodo==nullptr)
             return;
         post(nodo->izquierda);
         post(nodo->derecha);
         cout<<'\t'<<nodo->datos.toStdString()<<endl;
     }
    void in(nodoArbol *nodo){
         if(nodo==nullptr)
             return;
         post(nodo->izquierda);
         cout<<'\t'<<nodo->datos.toStdString()<<endl;
         post(nodo->derecha);

     }
    void pre(nodoArbol *nodo){
         if(nodo==nullptr)
             return;
         cout<<'\t'<<nodo->datos.toStdString()<<endl;
         post(nodo->izquierda);
         post(nodo->derecha);

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
