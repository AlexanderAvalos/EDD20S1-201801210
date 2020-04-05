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
      turno++;
  }
  tablero->Graficar();
  jp1->top->graficaj1();
  jp2->top->graficaj2();
  int total1,total2;
  total1 = jp1->top->recorrer();
  total2 = jp2->top->recorrer();
  topgeneral->agregarpunteo(total1,jp1->datos);
  topgeneral->agregarpunteo(total2,jp2->datos);
}

void juego::menujuego(nodoArbol  *jugador){
    int menujuego = 0;
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
            pedirficha(jugador->lista);
            turno++;
            break;
        case 3:
            fin = true;
            break;
    }
}

void juego::insertarpalabra(nodoArbol *jugador){
    QString palabra,psx,psy;
    QString letra;
    string bus;
    char le;
    int posx,posy,totalp, punteo;
    int cont = 0,orientacion;
    if(turno == 0){
        cout<<"ingrese palabra"<<endl;
        cin>>bus;
        cout<<""<<endl;
        if(cont <= 6){
            cout<<"ingrese cordenada inicial x"<<endl;
            cin>>posx;
            cout<<"ingrese cordenada inicial y"<<endl;
            cin>>posy;
            cout<<"1.vertical   2.horizontal"<<endl;
            cin>>orientacion;
            palabra = QString::fromStdString(bus);
            if(diccionario->buscar(palabra)){
                if(orientacion == 2){
                    for(int i = 0; i <= bus.length() ; i++){
                        le = bus[i];
                        if(jugador->lista->sacar(bus[i]) != NULL){
                            letra = jugador->lista->sacar(le)->ficha;
                            posx = posx+i;
                            psx = QString::number(posx);
                            psy = QString::number(posy);
                            punteo = jugador->lista->sacar(bus[i])->puntos;
                            tablero->insertarfila(posy);
                            tablero->insertarcomluna(posx);
                            tablero->insertar(letra,punteo,(psx),psy);
                            punteo = punteo * buscarTD(psx,psy);
                            totalp = totalp + punteo;
                        }else{
                            cout<<"palabra incorrecta"<<endl;
                            menujuego(jugador);
                            break;
                        }
                    }
                }else if (orientacion == 1){
                    for(int i = 0; i <= bus.length() ; i++){
                        le = bus[i];
                        if(jugador->lista->sacar(bus[i]) != NULL){
                            letra = jugador->lista->sacar(le)->ficha;
                            posy = posy+i;
                            psx = QString::number(posx);
                            psy = QString::number(posy);
                            punteo = jugador->lista->sacar(bus[i])->puntos;
                            tablero->insertar(letra,punteo,(psx),psy);
                            punteo = punteo * buscarTD(psx,psy);
                            totalp = totalp + punteo;
                        }else{
                            cout<<"palabra incorrecta"<<endl;
                            menujuego(jugador);
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
         cout<<"aqqui val el otro turno"<<endl;
        }

}

int juego::buscarTD(QString x,QString y){
    if(tablero->buscar(x,y) != NULL){
       if( tablero->buscar(x,y)->dato.getpalabra() == "triples"){
           return 3;
       }else if(tablero->buscar(x,y)->dato.getpalabra() == "dobles"){
           return 2;
       }
    }
    return 1;
}

void juego::pedirficha(ListaDoble *fichas){
    fichas->vaciar(COLA);
    fichas = new ListaDoble();
    ponerfichas(fichas);
}

void juego::ponerfichas(ListaDoble *lista){
    for (int var = 0; var <= 6; var++) {
        lista->insertar_Nodo(COLA->pop(),COLA->top());
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
