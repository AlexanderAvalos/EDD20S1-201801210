#ifndef LISTATOP_H
#define LISTATOP_H
#include <nodo_listasimple_t.h>
class listaTop
{
private:
    nodot *primero;
    nodot *ultimo;
    ofstream salida;
    bool vacio(){
        if(primero == NULL && ultimo == NULL){
            return true;
        }
        return false;
    }
public:
    void grafica(){
        nodot *actual = new nodot();
        actual = primero;
        salida.open("top.txt");
        salida<<"digraph top{  rankdir=LR  "<<endl;
        salida<<" node [shape=rectangle];  "<<endl;
        while(actual != NULL){
            if(actual->siguiente != NULL){
            salida<<'\"' <<actual->dato.getjugadores().toStdString() << ","<< actual->dato.getpuntuacion() << "\" ->";
            actual = actual->siguiente;
            }else {
                salida<<'\"' <<actual->dato.getjugadores().toStdString() << ","<< actual->dato.getpuntuacion() <<"\";";
                actual = actual->siguiente;
            }
        }
        salida<<"}"<<endl;
        salida.close();
        qInfo()<<system("dot -Tpng top.txt -o top.png");
    }

    void recorrer(){
        nodot *aux = new nodot();
        aux = primero;
        while(aux != NULL){
            cout<<aux->dato.getpuntuacion()<<endl;
            aux = aux->siguiente;
        }
    }
    void agregarpunteo(int puntos,QString jugador){
        nodot *nuevo = new nodot();
        nuevo->dato.setpuntuacion(puntos);
        nuevo->dato.setjugadores(jugador);
        if (vacio())
        {
            primero = nuevo;
            ultimo = primero;
        }
        else
        {
            if(puntos > primero->dato.getpuntuacion()){
                nuevo->siguiente = primero;
                primero = nuevo;
            }
            else {
                nodot *aux = primero;
                nodot *auxb = primero;
                while (puntos <= aux->dato.getpuntuacion() && aux->siguiente != NULL)
                {
                    auxb = aux;
                    aux = aux->siguiente;
                }
                if (puntos <= aux->dato.getpuntuacion())
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

#endif // LISTATOP_H
