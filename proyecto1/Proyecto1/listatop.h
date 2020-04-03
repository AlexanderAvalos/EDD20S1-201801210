#ifndef LISTATOP_H
#define LISTATOP_H
#include <nodo_listasimple_t.h>
class listaTop
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
        salida.open("top.txt");
        salida<<"digraph top{  rankdir=LR  "<<endl;
        salida<<" node [shape=rectangle];  "<<endl;
        while(actual->siguiente != NULL){
            salida<< actual->puntuacion.getjugadores()<< ","<< actual->puntuacion.getpuntuacion() << "->" <<actual->puntuacion.getjugadores()<< ","<< actual->siguiente->puntuacion.getpuntuacion() << " ;" <<endl;
            actual = actual->siguiente;
        }
        salida<<"}"<<endl;
        salida.close();
        qInfo()<<system("dot -Tpng top.txt -o top.png");
    }

    void recorrer(){
        nodo *aux = new nodo();
        aux = primero;
        while(aux != NULL){
            cout<<aux->puntuacion.getpuntuacion()<<endl;
            aux = aux->siguiente;
        }
    }
    void agregarpunteo(int puntos,string jugador){
        nodo *nuevo = new nodo();
            nuevo->puntuacion.setpuntuacion(puntos) = ;
            nuevo->puntuacion.setjugadores(jugador);
            if (vacio())
            {
                primero = nuevo;
                ultimo = primero;
            }
            else
            {
                if(puntos > primero->puntuacion.getpuntuacion()){
                    nuevo->siguiente = primero;
                    primero = nuevo;
                }
                else {
                    nodo *aux = primero;
                    nodo *auxb = primero;
                    while (puntos <= aux->puntuacion.getpuntuacion() && aux->siguiente != NULL)
                    {
                        auxb = aux;
                        aux = aux->siguiente;
                    }
                    if (puntos <= aux->puntuacion.getpuntuacion())
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
