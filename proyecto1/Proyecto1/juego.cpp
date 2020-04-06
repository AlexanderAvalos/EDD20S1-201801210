#include <listadoble.h>
#include <listacirulardoble.h>
#include <listaletras.h>
#include <listasimplejp.h>
#include <arbol_buscar.h>
#include <matrizdispersa.h>
#include <listaletras.h>
#include "nodo_arbol_busqueda.h"
#include <listatop.h>
#include <cola.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <QString>
#include <stdio.h>
#include<random>
#include <json.h>
#include <juego.h>
using namespace std;
using json = nlohmann::json;
bool fin = false;
int turno = 0;
arbol_busqueda *arbol = new arbol_busqueda();
cola *COLA = new cola();
listaciruclardoble *diccionario = new listaciruclardoble();
matrizDisperza *tablero = new matrizDisperza();
listaTop *topgeneral = new listaTop();
listasimpleJP *prueba = new listasimpleJP();
nodoArbol *jp1 ;
nodoArbol *jp2 ;
void juego::crearJugador(){
    string aux;
    QString nombre;
    cout<<"ingrese nombre jugador"<<endl;
    cin>>aux;
    nombre = QString::fromStdString(aux);
    arbol->insertarDato(nombre);
}

void juego::reportes(){
    int con = 0;
    int dato = 0;
    QString nombre ;
    string temp;
    int menujuego = 0;
        cout<<"opciones:"<<endl;
        cout<<"1. recorridos"<<endl;
        cout<<"2. topJugador"<<endl;
        cout<<"3. topGeneral"<<endl;
         cout<<"4. matriz"<<endl;
        cin>>menujuego;
        switch (menujuego) {
        case 1:
            arbol->graphviz();
            arbol->inOrden();
            arbol->preOrden();
            arbol->postOrden();
            break;
        case 2:
            cout<<"ingresa cantidad datos"<<endl;
            cin>>con;
            for (int var = 0; var < con; ++var) {
                cout<<"ingrese dato"<<endl;
                cin>>dato;
                prueba->agregarpunteo(dato);
            }
            prueba->graficaj1();
            break;
        case 3:
            cout<<"ingresa cantidad datos"<<endl;
            cin>>con;
            for (int var = 0; var < con; ++var) {
                cout<<"ingrese nombre"<<endl;
                cin>>temp;
                nombre = QString::fromStdString(temp);
                cout<<"ingrese dato"<<endl;
                cin>>dato;
                topgeneral->agregarpunteo(dato,nombre);
            }
            topgeneral->grafica();
            break;
          case 4:
            tablero->Graficar_enlaces();
            break;
    }
}


void juego::elegirJugadores(){
    arbol->graphviz();
    diccionario->graficar();
    tablero->Graficar();
    COLA->listaa();
    COLA->graficar();
    string aux;
    QString nombre1,nombre2;
    cout<<"ingrese nombre jugador 1"<<endl;
    cin>>aux;
    nombre1 = QString::fromStdString(aux);
    jp1 = arbol->buscar(nombre1);
    ListaDoble *lista1 = jp1->lista;
    listasimpleJP *top1 = jp1->top;
    ponerfichas(lista1);
    lista1->graficar1();
    cout<<"ingrese nombre jugador 2"<<endl;
    cin>>aux;
    nombre2 = QString::fromStdString(aux);
    jp2 = arbol->buscar(nombre2);
    ListaDoble *lista2 = jp2->lista;
    listasimpleJP *top2 =jp2->top;
    ponerfichas(lista2);
    lista2->graficar2();
  while(fin != true){
      cout <<"turno "<< turno<<endl;
      cout<<"empezo el turno juegador 1"<<endl;
      menujuego(jp1);
      jp1->lista->graficar1();
      tablero->Graficar();
      cout<<"termino turno jugador 1"<<endl;
      if(fin == false){
          cout<<"empezo el turno juegador 2"<<endl;
          menujuego(jp2);
          jp2->lista->graficar2();
          tablero->Graficar();
          cout<<"termino turno jugador 2"<<endl;
      }
  }
  tablero->Graficar();
  jp1->top->graficaj1();
  jp2->top->graficaj2();
  int total1,total2;
  total1 = jp1->top->recorrer();
  total2 = jp2->top->recorrer();
  topgeneral->agregarpunteo(total1,jp1->datos);
  topgeneral->agregarpunteo(total2,jp2->datos);
  topgeneral->grafica();
}

void juego::menujuego(nodoArbol  *jugador){
    int menujuego = 0;
    if(turno == 0){
    jugador->lista->graficar1();}
        cout<<"opciones:"<<endl;
        cout<<"1. ingresar palabra"<<endl;
        cout<<"2. cambiar ficha"<<endl;
        cout<<"3. terminar partida"<<endl;
        cin>>menujuego;
        switch (menujuego) {
        case 1:
            insertarpalabra(jugador);
            break;
        case 2:
            pedirficha(jugador);
            break;
        case 3:
            fin = true;
            break;
    }
}


void juego::insertarpalabra(nodoArbol *jugador){
    QString palabra,psx,psy,temy,temx;
    QString letra;
    string bus;
    char le;
    int valido=0;
    int posx,posy,totalp, punteo,op =0,temx1,temy1;
    int cont = 0,orientacion;
    if(turno == 0){

        cout<<"ingrese palabra"<<endl;
        cin>>bus;
        if(cont <= 6){
            cout<<"ingrese cordenada inicial x"<<endl;
            cin>>posx;
            cout<<"ingrese cordenada inicial y"<<endl;
            cin>>posy;
            cout<<"1.vertical   2.horizontal"<<endl;
            cin>>orientacion;
            palabra = QString::fromStdString(bus);
            if(diccionario->buscar(palabra) == true){
                if(orientacion == 2){
                    for(int i = 0; i <= bus.length() ; i++){
                        le = bus[i];
                        if(jugador->lista->buscar1(le) == true){
                            letra = le;
                            posx = posx+i;
                            psx = QString::number(posx);
                            psy = QString::number(posy);
                            punteo = jugador->lista->buscar(le);
                            if(tablero->lst_horizontal->buscarx(psx)==false){
                                tablero->insertarfila(psx);
                            }
                            if(tablero->lst_vertical->buscary(psy)== false){
                                tablero->insertarcomluna(psy);
                            }
                            tablero->insertar(letra,punteo,(psx),psy);
                            op = punteo * buscarTD(letra,psx,psy);
                            totalp = totalp + op;
                            jugador->lista->sacar(le);
                        }else{
                            jugador->top->agregarpunteo(totalp);
                            break;
                        }
                    }

                }else if (orientacion == 1){
                    for(int i = 0; i <= bus.length() ; i++){
                        le = bus[i];
                        if(jugador->lista->buscar1(le) == true){
                            letra = le;
                            posy = posy+i;
                            psx = QString::number(posx);
                            psy = QString::number(posy);
                            punteo = jugador->lista->buscar(le);
                            if(tablero->lst_horizontal->buscarx(psx)==false){
                                tablero->insertarfila(psx);
                            }
                            if(tablero->lst_vertical->buscary(psy)== false){
                                tablero->insertarcomluna(psy);
                            }
                            tablero->insertar(letra,punteo,(psx),psy);
                            op = punteo * buscarTD(letra,psx,psy);
                            totalp = totalp + op;
                            jugador->lista->sacar(le);
                        }else{
                            jugador->top->agregarpunteo(totalp);
                            break;
                        }
                    }
                }else{
                        cout<<"especifique orientacion"<<endl;
                        menujuego(jugador);
                    }
                }else{
                    cout<<"palabra no valida"<<endl;
                    menujuego(jugador);
                }
            }
        turno++;
        }else{
        cout<<"ingrese palabra"<<endl;
        cin>>bus;
        if(cont <= 6){
            cout<<"ingrese cordenada inicial x"<<endl;
            cin>>posx;
            cout<<"ingrese cordenada inicial y"<<endl;
            cin>>posy;
            cout<<"1.vertical   2.horizontal"<<endl;
            cin>>orientacion;
            palabra = QString::fromStdString(bus);
            if(diccionario->buscar(palabra) == true){
                if(orientacion == 2){
                    for(int i = 0; i <= bus.length() ; i++){
                        le = bus[i];
                        if(jugador->lista->buscar1(le) == true){
                            letra = le;
                            posx = posx+i;
                            psx = QString::number(posx);
                            psy = QString::number(posy);
                            punteo = jugador->lista->buscar(le);
                            if(tablero->lst_horizontal->buscarx(psx)==false){
                                tablero->insertarfila(psx);
                            }
                            if(tablero->lst_vertical->buscary(psy)== false){
                                tablero->insertarcomluna(psy);
                            }
                            tablero->insertar(letra,punteo,(psx),psy);
                            op = punteo * buscarTD(letra,psx,psy);
                            totalp = totalp + op;
                            jugador->lista->sacar(le);
                        }else{
                            jugador->top->agregarpunteo(totalp);
                            break;
                        }
                    }

                }else if (orientacion == 1){
                    for(int i = 0; i <= bus.length() ; i++){
                        le = bus[i];
                        if(jugador->lista->buscar1(le) == true){
                            letra = le;
                            posy = posy+i;
                            psx = QString::number(posx);
                            psy = QString::number(posy);
                            punteo = jugador->lista->buscar(le);
                            if(tablero->lst_horizontal->buscarx(psx)==false){
                                tablero->insertarfila(psx);
                            }
                            if(tablero->lst_vertical->buscary(psy)== false){
                                tablero->insertarcomluna(psy);
                            }
                            tablero->insertar(letra,punteo,(psx),psy);
                            op = punteo * buscarTD(letra,psx,psy);
                            totalp = totalp + op;
                            jugador->lista->sacar(le);
                        }else{
                            jugador->top->agregarpunteo(totalp);
                            break;
                        }
                    }
                }else{
                        cout<<"especifique orientacion"<<endl;
                    }
                }else{
                    cout<<"palabra no valida"<<endl;
                }
            }
        turno++;

    }
}

int juego::buscarTD(QString letra,QString x,QString y){
    if(tablero->buscar(x,y) != NULL){
       if( tablero->buscar(x,y)->dato.getpalabra() == "triples"){
           tablero->buscar(x,y)->dato.setpalabra(letra);
           return 3;
       }else if(tablero->buscar(x,y)->dato.getpalabra() == "dobles"){
          tablero->buscar(x,y)->dato.setpalabra(letra);
           return 2;
       }else{
           return 1;
       }
    }
    return 1;
}

void juego::pedirficha(nodoArbol *jugador){
    jugador->lista->vaciar(COLA);
     jugador->lista->limpiar();
    ponerfichas( jugador->lista);
    if(turno ==  0){
        menujuego(jugador);
    }
}

void juego::ponerfichas(ListaDoble *lista){
    for (int var = 0; var <= 6; var++) {
        lista->insertar_Nodo(COLA->top(),COLA->pop());
    }
}

void juego::leerjason(){
 std::ifstream i("entrada.json");
 json file = json::parse(i) ;
 tablero->maxmatriz( file.at("dimension"));
 QString pun,posx,posy;
 for (int x = 0; x < file.at("casillas").at("dobles").size(); x++) {
     int psx =0,psy = 0;
     pun = "dobles";
     psx = file.at("casillas").at("dobles")[x].at("x");
     psy = file.at("casillas").at("dobles")[x].at("y");
     posx = QString::number(psx);
     posy = QString::number(psy);
     if(tablero->lst_horizontal->buscarx(posx)==false){
         tablero->insertarfila(posx);
     }
     if(tablero->lst_vertical->buscary(posy)==false){
         tablero->insertarcomluna(posy);
     }
     tablero->insertar(pun,2,posx,posy);
 }
 for(int x = 0; x < file.at("casillas").at("triples").size(); x++){
     int psx=0,psy=0;
     pun = "triples";
     psx = file.at("casillas").at("triples")[x].at("x");
     psy = file.at("casillas").at("triples")[x].at("y");
     posx = QString::number(psx);
     posy = QString::number(psy);
     if(tablero->lst_horizontal->buscarx(posx)==false){
         tablero->insertarfila(posx);
     }
     if(tablero->lst_vertical->buscary(posy)==false){
         tablero->insertarcomluna(posy);
     }
     tablero->insertar(pun,3,posx,posy);
    }
 string palabra = "";
 QString pa;
 for(int x = 0; x < file.at("diccionario").size(); x++){
     palabra = file.at("diccionario")[x].at("palabra");
     pa = QString::fromStdString(palabra);
     diccionario->insertar_Palabra(pa.toUpper());
 }
}


/*
        cout<<"ingrese palabra"<<endl;
        cin>>bus;
        if(cont <= 6){
            cout<<"ingrese cordenada inicial x"<<endl;
            cin>>posx;
            cout<<"ingrese cordenada inicial y"<<endl;
            cin>>posy;
            cout<<"1.vertical   2.horizontal"<<endl;
            cin>>orientacion;
            palabra = QString::fromStdString(bus);
            if(diccionario->buscar(palabra) == true){
                if(orientacion == 2){
                    temx1 = posx;
                    temy1 = posy;
                    for(int i = 0; i <= bus.length() ; i++){
                        temx1 = temx1+i;
                        temx = QString::number(temx1);
                        temy = QString::number(temy1);
                        if(tablero->existe(temx,temy)){
                          if( tablero->buscar(temx,temy)->dato.getpalabra() != "triples"|| tablero->buscar(temx,temy)->dato.getpalabra() == "dobles"){
                            valido++;
                          }
                        }
                    }
                    for(int i = 0; i <= bus.length() ; i++){
                        le = bus[i];
                       if(valido != 0){
                              letra = le;
                             if(tablero->buscar(psx,psy)->dato.getpalabra() != letra){
                                 if(jugador->lista->buscar1(le) == true){
                                     posx = posx+i;
                                     psx = QString::number(posx);
                                     psy = QString::number(posy);
                                     punteo = jugador->lista->buscar(le);
                                     if(tablero->lst_horizontal->buscarx(psx)==false){
                                         tablero->insertarfila(psx);
                                     }
                                     if(tablero->lst_vertical->buscary(psy)== false){
                                         tablero->insertarcomluna(psy);
                                     }
                                     tablero->insertar(letra,punteo,(psx),psy);
                                     op = punteo * buscarTD(letra,psx,psy);
                                     totalp = totalp + op;
                                     jugador->lista->sacar(le);
                                 }else{
                                     jugador->top->agregarpunteo(totalp);
                                     break;
                                 }
                             }else{
                                 totalp = totalp + tablero->buscar(psx,psy)->dato.getpunteo();
                             }
                       }else{
                           cout<<"Palabra en espacio no valido"<<endl;
                       }
                    }
                }else if (orientacion == 1){
                    temx1 = posx;
                    temy1 = posy;
                    for(int i = 0; i <= bus.length() ; i++){
                        temy1 = temy1+i;
                        temx = QString::number(temx1);
                        temy = QString::number(temy1);
                        if(tablero->existe(temx,temy)){
                            if( tablero->buscar(temx,temy)->dato.getpalabra() != "triples"|| tablero->buscar(temx,temy)->dato.getpalabra() == "dobles"){
                                valido++;
                            }
                        }
                    }
                    for(int i = 0; i <= bus.length() ; i++){
                        le = bus[i];
                        if(valido != 0){
                            letra = le;
                            if(tablero->buscar(psx,psy)->dato.getpalabra() != letra){
                                if(jugador->lista->buscar1(le) == true){
                                    posy = posy+i;
                                    psx = QString::number(posx);
                                    psy = QString::number(posy);
                                    punteo = jugador->lista->buscar(le);
                                    if(tablero->lst_horizontal->buscarx(psx)==false){
                                        tablero->insertarfila(psx);
                                    }
                                    if(tablero->lst_vertical->buscary(psy)== false){
                                        tablero->insertarcomluna(psy);
                                    }
                                    tablero->insertar(letra,punteo,(psx),psy);
                                    op = punteo * buscarTD(letra,psx,psy);
                                    totalp = totalp + op;
                                    jugador->lista->sacar(le);
                                }else{
                                    jugador->top->agregarpunteo(totalp);
                                    break;
                                }
                            }else{
                                totalp = totalp + tablero->buscar(psx,psy)->dato.getpunteo();
                            }
                        }else{
                            cout<<"Palabra en espacio no valido"<<endl;
                            break;
                        }
                    }
                }else{
                    cout<<"especifique orientacion"<<endl;
                }
            }else{
                cout<<"palabra no valida"<<endl;
            }
        }
        turno++;
*/
