#ifndef MATRIZDISPERSA_H
#define MATRIZDISPERSA_H
#include <nodo_matrizdispersa.h>
#include <fstream>
#include <iostream>
using namespace std;


class matrizDisperza{
   public:
    int max;
    ofstream ficheroSalida;
    listahorizontal *lst_horizontal;
    listavertical *lst_vertical;
    int size;

    matrizDisperza(){
        this->lst_horizontal = new listahorizontal();
        this->lst_vertical = new listavertical();
        size = 0;
    }

    void maxmatriz(int maximo){
        this->max = maximo;
    }

    void insertar(QString letra,int punteo, QString x,QString y){
        nodoMatriz *horizontal =  lst_horizontal->buscar(x);
        nodoMatriz *vertical =  lst_vertical->buscar(y);
        if(horizontal == NULL && vertical == NULL){
        }else{
            agregar(letra,punteo,horizontal,vertical);
        }
    }

    void agregar(QString val,int punteo, nodoMatriz *horizontal, nodoMatriz *vertical){



        if(this->size==0){

            nodoMatriz * nuevo = new nodoMatriz(horizontal->numero,vertical->numero);
            nuevo->dato.setpalabra(val);
            nuevo->dato.setpunteo(punteo);

            horizontal->abajo=nuevo;//enlazamos la cabecera con el nodo
            vertical->derecha=nuevo;//enlazamos cabecera con el nodo

            nuevo->arriba=horizontal;//enlazamos nodo con cabecera
            nuevo->izquierda=vertical;//enlazamos nodo con cabecera

            this->size++;

       }else if( this->size>0){
            if(comparar(horizontal->numero,vertical->numero)==true){
                nodoMatriz *nodoAuxiliarHorizontal = lst_horizontal->buscar(horizontal->numero);
                nodoMatriz *nodoAux = nodoAuxiliarHorizontal;
                while(nodoAux!=nullptr){
                    if(nodoAux->getY()==vertical->numero){
                        nodoAuxiliarHorizontal=nodoAux;
                        break;
                    }else
                        nodoAux=nodoAux->abajo;
                }
                nodoAuxiliarHorizontal->dato.setpalabra(val);
                return;

            }else{

                nodoMatriz *nodoAuxiliarHorizontal = lst_horizontal->buscar(horizontal->numero);
                nodoMatriz *nodoAux = nodoAuxiliarHorizontal->abajo;

                nodoMatriz *nodo = new nodoMatriz(horizontal->numero,vertical->numero);
                nodo->dato.setpalabra(val);
                nodo->dato.setpunteo(punteo);

                nodoMatriz *nodoAuxiliarVertical =lst_vertical->buscar(vertical->numero);
                nodoMatriz *nodoAux2 = nodoAuxiliarVertical->derecha;

                bool agregado=false;
                if(nodoAuxiliarVertical->derecha!=nullptr){
                while(nodoAux2!=nullptr){
                    if(horizontal->numero==nodoAux2->getX())
                        nodoAux2= nodoAux2->derecha;
                    else{
                        nodo->derecha=nodoAux2;
                        nodo->izquierda=nodoAux2->izquierda;
                        nodoAux2->izquierda->derecha=nodo;
                        nodoAux2->izquierda=nodo;
                        agregado=true;
                        break;
                    }
                }

                if(agregado==false){
                    nodoAux2=nodoAuxiliarVertical->derecha;
                    while(nodoAux2->derecha!=nullptr){
                        nodoAux2=nodoAux2->derecha;
                    }
                    nodo->izquierda=nodoAux2;
                    nodoAux2->derecha=nodo;
                }

               }else{
                   nodoAuxiliarVertical->derecha=nodo;
                   nodo->izquierda=nodoAuxiliarVertical;
                }
                agregado = false;
                if(nodoAuxiliarHorizontal->abajo!=nullptr){
                while(nodoAux!=nullptr){
                    if(vertical->numero.compare(nodoAux->getY())>=0)
                        nodoAux=nodoAux->abajo;
                    else{
                        nodo->abajo=nodoAux;
                        nodo->arriba=nodoAux->arriba;
                        nodoAux->arriba->abajo=nodo;
                        nodoAux->arriba=nodo;
                        agregado=true;
                        break;
                    }
                }
                if(agregado==false){
                    nodoAux=nodoAuxiliarHorizontal->abajo;
                    while(nodoAux->abajo!=nullptr){
                        nodoAux=nodoAux->abajo;
                    }
                    nodo->arriba=nodoAux;
                    nodoAux->abajo=nodo;
                }

                }else{
                    nodoAuxiliarHorizontal->abajo=nodo;
                    nodo->arriba=nodoAuxiliarHorizontal;
                }
            }
         }
             this->size++;
     }

    bool comparar(QString horizontal, QString vertical){
    nodoMatriz *aux = lst_horizontal->buscar(horizontal);

    while(aux!=NULL){
        if(aux->getY()== vertical){
            return true;
        }else
            aux = aux->abajo;
    }
    return false;
    }

    bool eliminar(QString posx, QString posy){
        nodoMatriz * horizontal = lst_horizontal->primero;
        while(horizontal != NULL){
            nodoMatriz *vertical = horizontal->abajo;
            while(vertical != NULL){
                if(vertical->x == posx  && horizontal->y == posy){
                    vertical->dato.getpalabra().toStdString();
                            return true;
                }
                vertical = vertical->abajo;
            }
            horizontal = horizontal->derecha;
        }
        return false;
    }

    void insertarfila(QString val){
        lst_horizontal->insertar(val);
    }
    void insertarcomluna(QString val){
        lst_vertical->insertar(val);
    }
    void imprimirfila(){
        lst_horizontal->imprimir();
    }
    void imprimircolumna(){
        lst_vertical->imprimir();
    }

    void Graficar(){

            ficheroSalida.open("matriz.txt");
            ficheroSalida << "digraph{ bgcolor = gray \n node[fontcolor = black, height = 0.5, color = black ] \n [shape=box, style=filled, color=white] \n rankdir=LR \n edge  [color=\"black\", dir=fordware]\n";
            nodoMatriz *derecha = lst_horizontal->primero;
            nodoMatriz *Actual= derecha;
            int contador = 1;
            ficheroSalida << "inicial[style = \"filled\" ; label = \"inicial\" ; pos = \"0,0!\"] \n";

            //Obtener cabecera Horizontal
            while(derecha!=nullptr){
                ficheroSalida<< '\"'<< "Fi" <<Actual->numero.toStdString() << '\"'<< "[style =\"filled\"; label=\"" <<Actual->numero.toStdString() << "\";pos= \""<< std::to_string(contador)<< ",0! \"]\n";
                contador++;
                derecha= derecha->derecha;
                Actual=derecha;
            }

            //Obtener Cabecera Vertical
            contador= -1;
            nodoMatriz *abajo = lst_vertical->primero;
            Actual= abajo;

            while(abajo!=nullptr){
                ficheroSalida<< '\"'<<"Co" <<Actual->numero.toStdString() << '\"'<< "[style =\"filled\"; label=\"" << Actual->numero.toStdString() << "\";pos= \"0,"<< std::to_string(contador)<< "! \"]\n";
                contador--;
                abajo = abajo->abajo;
                Actual=abajo;

            }

            //Obtener Valores;
            derecha= lst_horizontal->primero;
            Actual=derecha;
            while(derecha!=nullptr){
                abajo= lst_vertical->primero;
                while(abajo!=nullptr){
                   if(Actual->abajo!=nullptr){
                    Actual= Actual->abajo;
                         ficheroSalida <<Actual->getCorrelativo().toStdString()<<"[shape=box ,style =\"filled\"; label=\"" << Actual->dato.getpalabra().toStdString() << "\";pos = \""<<std::to_string(posX(Actual->getX()))<<','<<std::to_string(posY(Actual->getY()))<<"!\"]\n" ;
                   }
                    abajo=abajo->abajo;
                }
                derecha=derecha->derecha;
                Actual=derecha;
            }

            //Enlazamos horizontal a la derecha
            derecha= lst_horizontal->primero;
            abajo=lst_vertical->primero;

            ficheroSalida << "inicial->" <<'\"'<< "Fi"<<derecha->numero.toStdString()<< '\"' << "-> inicial -> "<<'\"'<<"Co"<<abajo->numero.toStdString()<<'\"'<<"->inicial; \n";
            bool first = true;
            Actual=derecha;

            while(derecha!=nullptr){
                if (first==true){
                    ficheroSalida << '\"'<< "Fi"<< Actual->numero.toStdString() << '\"';
                    first=false;
                }else
                    ficheroSalida <<"->"<<'\"'<< "Fi"<<Actual->numero.toStdString() << '\"';
                derecha=derecha->derecha;
                Actual=derecha;
            }
            ficheroSalida<<";\n";

            //Enlazar Horizontales izquierda
            derecha= lst_horizontal->ultimo;
            first = true;
            Actual = derecha;
            while(derecha!=nullptr){
                    if (first==true){
                        ficheroSalida << '\"'<< "Fi"<<Actual->numero.toStdString() << '\"';
                        first=false;
                    }else
                        ficheroSalida <<"->"<<'\"'<< "Fi"<<Actual->numero.toStdString() << '\"';
                    derecha=derecha->izquierda;
                    Actual=derecha;
                }
            ficheroSalida<<";\n";


            //Enlazamos vertical a la derecha
            derecha= lst_horizontal->primero;
            abajo=lst_vertical->primero;

            first = true;
            Actual=abajo;

            while(abajo!=nullptr){
                if (first==true){
                    ficheroSalida << '\"'<< "Co"<<Actual->numero.toStdString() << '\"';
                    first=false;
                }else
                    ficheroSalida <<"->"<<'\"'<<"Co"<<Actual->numero.toStdString() << '\"';
                abajo=abajo->abajo;
                Actual=abajo;
            }
            ficheroSalida<<";\n";

            //Enlazar verticales izquierda
            abajo= lst_vertical->ultimo;
            first = true;
            Actual = abajo;
            while(abajo!=nullptr){
                if (first==true){
                    ficheroSalida << '\"'<<"Co" <<Actual->numero.toStdString() << '\"';
                    first=false;
                }else
                    ficheroSalida <<"->"<<'\"'<< "Co"<<Actual->numero.toStdString() << '\"';
                abajo=abajo->arriba;
                Actual=abajo;
            }
            ficheroSalida<<";\n";

            //enlazar valores hacia abajo
          /*  derecha= lst_horizontal->primero;
            while(derecha!=nullptr){
                ficheroSalida << '\"'<< "Fi"<<derecha->numero.toStdString() << '\"';
                abajo=derecha->abajo;
                while(abajo!=nullptr){
                    if(abajo!=nullptr)
                        ficheroSalida << "->\""<<abajo->getCorrelativo().toStdString()<< '\"';
                    abajo=abajo->abajo;
                }
                derecha=derecha->derecha;
                ficheroSalida << "; \n";
            }
            //enlazar valores hacia derecha
            abajo = lst_vertical->primero;
            while(abajo!=nullptr){
                ficheroSalida << '\"'<< "Co"<<abajo->numero.toStdString() << '\"';
                derecha = abajo->derecha;
                while(derecha!=nullptr){
                    if(derecha != nullptr)
                    ficheroSalida << "->\""<<derecha->getCorrelativo().toStdString() << '\"';
                    derecha=derecha->derecha;
                }
                abajo=abajo->abajo;
                ficheroSalida << "; \n";
            }
            //enlazar valores hacia arriba
            derecha=lst_horizontal->primero;
            Actual=derecha;
            while(derecha!=nullptr){
                while(Actual->abajo!=nullptr){
                    Actual=Actual->abajo;
                }
                while(Actual->arriba!=nullptr){
                    if(Actual != nullptr)
                        ficheroSalida << '\"'<< Actual->getCorrelativo().toStdString()<< "\"->";
                    Actual=Actual->arriba;
                }

                ficheroSalida << '\"'<< "Fi"<< derecha->numero.toStdString() << '\"';
                ficheroSalida <<"; \n";
                derecha=derecha->derecha;
                Actual=derecha;
            }

            //Enlazar valores hacia izquierda
            abajo=lst_vertical->primero;
            Actual=abajo;
            while(abajo!=nullptr){

                while(Actual->derecha!=nullptr){
                    Actual=Actual->derecha;
                }
                while(Actual->izquierda!=nullptr){
                    if(Actual != nullptr)
                        ficheroSalida << '\"'<< Actual->getCorrelativo().toStdString()<< "\"->";
                    Actual=Actual->izquierda;
                }
                ficheroSalida << '\"'<<"Co"<< abajo->numero.toStdString() << '\"';
                ficheroSalida <<"; \n";
                abajo=abajo->abajo;
                Actual=abajo;
            }*/
            ficheroSalida<<"}\n";

            qInfo() <<"Se imprimio";
            ficheroSalida.close();
            system("fdp -Tpng matriz.txt -o matriz.png");
        }

    void Graficar_enlaces(){

            ficheroSalida.open("matriz.txt");
            ficheroSalida << "digraph{ bgcolor = gray \n node[fontcolor = black, height = 0.5, color = black ] \n [shape=box, style=filled, color=white] \n rankdir=LR \n edge  [color=\"black\", dir=fordware]\n";
            nodoMatriz *derecha = lst_horizontal->primero;
            nodoMatriz *Actual= derecha;
            int contador = 1;
            ficheroSalida << "inicial[style = \"filled\" ; label = \"inicial\" ; pos = \"0,0!\"] \n";

            //Obtener cabecera Horizontal
            while(derecha!=nullptr){
                ficheroSalida<< '\"'<< "Fi" <<Actual->numero.toStdString() << '\"'<< "[style =\"filled\"; label=\"" <<Actual->numero.toStdString() << "\";pos= \""<< std::to_string(contador)<< ",0! \"]\n";
                contador++;
                derecha= derecha->derecha;
                Actual=derecha;
            }

            //Obtener Cabecera Vertical
            contador= -1;
            nodoMatriz *abajo = lst_vertical->primero;
            Actual= abajo;

            while(abajo!=nullptr){
                ficheroSalida<< '\"'<<"Co" <<Actual->numero.toStdString() << '\"'<< "[style =\"filled\"; label=\"" << Actual->numero.toStdString() << "\";pos= \"0,"<< std::to_string(contador)<< "! \"]\n";
                contador--;
                abajo = abajo->abajo;
                Actual=abajo;

            }

            //Obtener Valores;
            derecha= lst_horizontal->primero;
            Actual=derecha;
            while(derecha!=nullptr){
                abajo= lst_vertical->primero;
                while(abajo!=nullptr){
                   if(Actual->abajo!=nullptr){
                    Actual= Actual->abajo;
                         ficheroSalida <<Actual->getCorrelativo().toStdString()<<"[shape=box ,style =\"filled\"; label=\"" << Actual->dato.getpalabra().toStdString() << "\";pos = \""<<std::to_string(posX(Actual->getX()))<<','<<std::to_string(posY(Actual->getY()))<<"!\"]\n" ;
                   }
                    abajo=abajo->abajo;
                }
                derecha=derecha->derecha;
                Actual=derecha;
            }

            //Enlazamos horizontal a la derecha
            derecha= lst_horizontal->primero;
            abajo=lst_vertical->primero;

            ficheroSalida << "inicial->" <<'\"'<< "Fi"<<derecha->numero.toStdString()<< '\"' << "-> inicial -> "<<'\"'<<"Co"<<abajo->numero.toStdString()<<'\"'<<"->inicial; \n";
            bool first = true;
            Actual=derecha;

            while(derecha!=nullptr){
                if (first==true){
                    ficheroSalida << '\"'<< "Fi"<< Actual->numero.toStdString() << '\"';
                    first=false;
                }else
                    ficheroSalida <<"->"<<'\"'<< "Fi"<<Actual->numero.toStdString() << '\"';
                derecha=derecha->derecha;
                Actual=derecha;
            }
            ficheroSalida<<";\n";

            //Enlazar Horizontales izquierda
            derecha= lst_horizontal->ultimo;
            first = true;
            Actual = derecha;
            while(derecha!=nullptr){
                    if (first==true){
                        ficheroSalida << '\"'<< "Fi"<<Actual->numero.toStdString() << '\"';
                        first=false;
                    }else
                        ficheroSalida <<"->"<<'\"'<< "Fi"<<Actual->numero.toStdString() << '\"';
                    derecha=derecha->izquierda;
                    Actual=derecha;
                }
            ficheroSalida<<";\n";


            //Enlazamos vertical a la derecha
            derecha= lst_horizontal->primero;
            abajo=lst_vertical->primero;

            first = true;
            Actual=abajo;

            while(abajo!=nullptr){
                if (first==true){
                    ficheroSalida << '\"'<< "Co"<<Actual->numero.toStdString() << '\"';
                    first=false;
                }else
                    ficheroSalida <<"->"<<'\"'<<"Co"<<Actual->numero.toStdString() << '\"';
                abajo=abajo->abajo;
                Actual=abajo;
            }
            ficheroSalida<<";\n";

            //Enlazar verticales izquierda
            abajo= lst_vertical->ultimo;
            first = true;
            Actual = abajo;
            while(abajo!=nullptr){
                if (first==true){
                    ficheroSalida << '\"'<<"Co" <<Actual->numero.toStdString() << '\"';
                    first=false;
                }else
                    ficheroSalida <<"->"<<'\"'<< "Co"<<Actual->numero.toStdString() << '\"';
                abajo=abajo->arriba;
                Actual=abajo;
            }
            ficheroSalida<<";\n";

            //enlazar valores hacia abajo
            derecha= lst_horizontal->primero;
            while(derecha!=nullptr){
                ficheroSalida << '\"'<< "Fi"<<derecha->numero.toStdString() << '\"';
                abajo=derecha->abajo;
                while(abajo!=nullptr){
                    if(abajo!=nullptr)
                        ficheroSalida << "->\""<<abajo->getCorrelativo().toStdString()<< '\"';
                    abajo=abajo->abajo;
                }
                derecha=derecha->derecha;
                ficheroSalida << "; \n";
            }
            //enlazar valores hacia derecha
            abajo = lst_vertical->primero;
            while(abajo!=nullptr){
                ficheroSalida << '\"'<< "Co"<<abajo->numero.toStdString() << '\"';
                derecha = abajo->derecha;
                while(derecha!=nullptr){
                    if(derecha != nullptr)
                    ficheroSalida << "->\""<<derecha->getCorrelativo().toStdString() << '\"';
                    derecha=derecha->derecha;
                }
                abajo=abajo->abajo;
                ficheroSalida << "; \n";
            }
            //enlazar valores hacia arriba
            derecha=lst_horizontal->primero;
            Actual=derecha;
            while(derecha!=nullptr){
                while(Actual->abajo!=nullptr){
                    Actual=Actual->abajo;
                }
                while(Actual->arriba!=nullptr){
                    if(Actual != nullptr)
                        ficheroSalida << '\"'<< Actual->getCorrelativo().toStdString()<< "\"->";
                    Actual=Actual->arriba;
                }

                ficheroSalida << '\"'<< "Fi"<< derecha->numero.toStdString() << '\"';
                ficheroSalida <<"; \n";
                derecha=derecha->derecha;
                Actual=derecha;
            }

            //Enlazar valores hacia izquierda
            abajo=lst_vertical->primero;
            Actual=abajo;
            while(abajo!=nullptr){

                while(Actual->derecha!=nullptr){
                    Actual=Actual->derecha;
                }
                while(Actual->izquierda!=nullptr){
                    if(Actual != nullptr)
                        ficheroSalida << '\"'<< Actual->getCorrelativo().toStdString()<< "\"->";
                    Actual=Actual->izquierda;
                }
                ficheroSalida << '\"'<<"Co"<< abajo->numero.toStdString() << '\"';
                ficheroSalida <<"; \n";
                abajo=abajo->abajo;
                Actual=abajo;
            }
            ficheroSalida<<"}\n";

            qInfo() <<"Se imprimio";
            ficheroSalida.close();
            system("fdp -Tpng matriz.txt -o matriz.png");
        }




       nodoMatriz * buscar(QString x, QString y){
           nodoMatriz *horizontal = lst_horizontal->primero;
           while(horizontal!=nullptr){
               nodoMatriz *vertical = horizontal->abajo;
               while(vertical!=nullptr){
                   if(vertical->getY()==y && vertical->getX()==x){
                       return vertical;
                   }
                   vertical=vertical->abajo;
               }
               horizontal=horizontal->derecha;
           }
           return nullptr;
       }

       bool existe(QString x, QString y){
           nodoMatriz *horizontal = lst_horizontal->primero;
           while(horizontal!=nullptr){
               nodoMatriz *vertical = horizontal->abajo;
               while(vertical!=nullptr){
                   if(vertical->getY()==y && vertical->getX()==x){
                       return true;
                   }
                   vertical=vertical->abajo;
               }
               horizontal=horizontal->derecha;
           }
           return false;
       }

       int posX(QString horizontal)
       {
           int x =1;
          nodoMatriz*derecha = lst_horizontal->primero;

           while(derecha!=nullptr){
               if(derecha->numero==horizontal)
                   return x;
               else{
                   x++;
                   derecha=derecha->derecha;
               }
           }
           return -1;
       }


       int posY(QString vertical)
       {
           int y =-1;
           nodoMatriz *abajo=lst_vertical->primero;

           while(abajo!=nullptr){
               if(abajo->numero==vertical)
                   return y;
               else{
                   y--;
                   abajo=abajo->abajo;
               }
           }
           return -1;
       }



};



#endif // MATRIZDISPERSA_H
