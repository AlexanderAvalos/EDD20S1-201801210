#include "abrir_en_editor.h"
#include "lista_circular.h"
#include "lista_doble.h"
#include <stdlib.h>
#include <iostream>
#include <ncurses.h>
#include <curses.h>
#include <fstream>
#include <string>
#include <iomanip>
#include <string.h>
#include <stdio.h>
#include "pilaB.h"
#include "iniciar_lista.h"
using namespace std;

void generadorE();
void generador2E();
void generador3E();
void reporte_palabrasE();
void reporte_palabrasRE();
void generar_ReporteE();

WINDOW *nueva_ventana_E(int largo, int ancho, int pos_y, int pos_x);
void buscar_y_reemplazar(string cadenaL, string palabra_B, string palabra_N);
bool cont = false;
string nombre;
void reconocer_Nombre(string dir);
void leer_archivo(string direccion);
void guardar_archivo_E(string ruta);
int x,y;
Nodo *nodo = new Nodo();
static NodoC *nodoC = new NodoC();
NodoP *pilaBE = new NodoP();
NodoP *pilaRE = new NodoP();


void Abrir_En_Editor::crear_EditorA(){
    string cadenaL;
    string bus, rem;
    char buscar,reemplazar;
  string ruta;
    WINDOW *ventana;
    int marcox=75,marcoy=20;
    char cadena;
    initscr();
    refresh();
    ventana = nueva_ventana_E(marcoy, marcox, 2,2);
    wprintw(ventana,"^W buscar y editar  ^C Reportes  ^S Guardar");
        wmove(ventana,2,2);
    Caracter *actual = new Caracter;
    actual = nodo->primero;
    while(actual != NULL){
        if(actual->getcaracter() == '/n'){
           getyx(ventana,y,x);
           wmove(ventana,y+1,2);
        }else{
            wprintw(ventana,"%c",actual->getcaracter());}
        actual = actual->getsiguiente();
    }
    keypad(ventana,true);
    raw();
    char ele;
    int caracter;
    while(cont != true){
        getyx(ventana,y,x);
        if(x == 73){
            getyx(ventana,y,x);
            wmove(ventana,y+1,2);
        }
        if(y==18){
           getyx(ventana,y,x);
            wclear(ventana);
            crear_EditorA();
        }
        caracter =  wgetch(ventana);
        switch (caracter) {
        case KEY_LEFT:
            getyx(ventana,y,x);
            wmove(ventana,y,x-1);
            break;
        case KEY_RIGHT:
            getyx(ventana,y,x);
            wmove(ventana,y,x+1);
            break;
        case KEY_UP:
            getyx(ventana,y,x);
            wmove(ventana,y-1,x);
            break;
        case KEY_DOWN:
            getyx(ventana,y,x);
            wmove(ventana,y+1,x);
            break;
        case KEY_DC:
            getyx(ventana,y,x);
            wmove(ventana,y,x-1);
            wprintw(ventana," ");
            wmove(ventana,y,x-1);
            nodo->borrar_ultimo();
            break;
        case KEY_BACKSPACE:
            getyx(ventana,y,x);
            wmove(ventana,y,x-1);
            break;
        case 3:
            wmove(ventana,18,2);
            wprintw(ventana,"a.lista b.palabras c. ordenadas");
            ele = wgetch(ventana);
            if(ele == 97){
            generar_ReporteE();
            generadorE();}
            else if(ele == 98){
              reporte_palabrasE();
              generador2E();
              reporte_palabrasRE();
              generador3E();}
            break;
        case 10:
            getyx(ventana,y,x);
            wmove(ventana,y+1,2);
            nodo->insertar_Nodo('\n');
            break;
        case 19:
            wmove(ventana,marcoy-1,2);
            wprintw(ventana,"Escriba nombre: ");
            do{
            cadena = wgetch(ventana);
            ruta = ruta + cadena ;
        }while(cadena != 10);
            guardar_archivo_E(ruta);
            refresh();
            break;
        case 23:
            actual=nodo->primero;
            while (actual != NULL) {
                cadenaL = cadenaL + actual->getcaracter();
                actual = actual->getsiguiente();
            }
            wmove(ventana,marcoy-1,2);
            wprintw(ventana,"buscar: ");
            do{
            buscar = wgetch(ventana);
            if(buscar != ';'){bus = bus + buscar ;}
            }while(buscar != ';');
          wmove(ventana,marcoy-1,2);
          wprintw(ventana,"Remplazar: ");
          do{
                reemplazar = wgetch(ventana);
                rem = rem +reemplazar;
            }while(reemplazar != 10);
          wclear(ventana);
          buscar_y_reemplazar(cadenaL,bus,rem);
          ventana = nueva_ventana_E(20,75,2,2);
          wmove(ventana,2,2);
          actual = nodo->primero;
          wmove(ventana,2,2);
          while(actual != NULL){
              getyx(ventana,y,x);
              if(actual->getcaracter() == '\n'){
                  wmove(ventana,y+1,2);
              }else{
                  wprintw(ventana,"%c",actual->getcaracter());}
              actual = actual->getsiguiente();
          }
          pilaBE->push(bus,rem,"No Revertido");
             break;
         case 24:
             cont = true;
            break;
        case 25:
            pilaRE->pop();
            buscar_y_reemplazar(cadenaL,bus,rem);
            wclear(ventana);
            ventana = nueva_ventana_E(20,75,2,2);
            wmove(ventana,2,2);
            actual = nodo->primero;
            wmove(ventana,2,2);
            while(actual != NULL){
                getyx(ventana,y,x);
                if(actual->getcaracter() == '\n'){
                    wmove(ventana,y+1,2);
                }else{
                    wprintw(ventana,"%c",actual->getcaracter());}
                actual = actual->getsiguiente();
            }
            pilaBE->push(bus,rem,"No Revertido");
            break;
        case 26:
            pilaBE->pop();
            buscar_y_reemplazar(cadenaL,rem,bus);
            wclear(ventana);
            ventana = nueva_ventana_E(20,75,2,2);
            wmove(ventana,2,2);
            actual = nodo->primero;
            wmove(ventana,2,2);
            while(actual != NULL){
                getyx(ventana,y,x);
                if(actual->getcaracter() == '\n'){
                    wmove(ventana,y+1,2);
                }else{
                    wprintw(ventana,"%c",actual->getcaracter());}
                actual = actual->getsiguiente();
            }
             pilaRE->push(bus,rem,"Revertido");
            break;
         default:
            nodo->insertar_Nodo(caracter);
            break;
         }
     }
    refresh();
    endwin();
}

void guardar_archivo_E(string ruta){
    ofstream archivo_s(ruta);
    Caracter *ac = new Caracter();
    ac = nodo->primero;
    while(ac != NULL){
            archivo_s << ac->getcaracter();
            ac = ac->getsiguiente();
    }
    archivo_s.close();
}

void  reconocer_Nombre(string dir){
    int contador = 0,contador2=0;

    bool cona = false;
    int cantidad = dir.length();
    while(cona != true){
        if(dir[contador] == '.'){
            contador2=contador;
              while (dir[contador2] != '/') {
                  contador2--;
          }
              while(contador2!=cantidad){
                  nombre = nombre + dir[contador2+1];
                  contador2++;
              }
        }
        if(contador == cantidad){
            cona = true;
            nodoC->insertar_NodoC(nombre,dir);

        }
        contador++;
    }
}

void Abrir_En_Editor::leer_archivo(string direccion){
    string texto;
    ifstream archivo;
    reconocer_Nombre(direccion);
    char prue;
    if(!archivo.is_open()){
        archivo.open(direccion,ios::in);
        if(archivo.fail()){
            cout<<" "<<endl;
            cout<<direccion<<endl;
            cout<<"Error";
            exit(1);
        }else{
            while ( !archivo.eof()) {
                getline(archivo,texto);
                for(int i=0; i <= texto.length(); i++){
                    prue = texto[i];
                    nodo->insertar_Nodo(prue);
                }

                 nodo->insertar_Nodo('\n');
            }
        }
        archivo.close();
    }
}

WINDOW *nueva_ventana_E(int largo, int ancho, int pos_y, int pos_x)
{ WINDOW *local_win;
  local_win = newwin(largo, ancho, pos_y, pos_x);
  box(local_win, 0, 0);
  wrefresh(local_win);
  return local_win;
}
void buscar_y_reemplazar(string cadenaL,string palabra_B,string palabra_N){
    int posicion = cadenaL.find(palabra_B);
    while(posicion != -1){
    cadenaL.replace(posicion,palabra_B.size(),palabra_N);
    posicion = cadenaL.find(palabra_B, posicion + palabra_N.size());
    }
    nodo->borrar_lista();
    char carac;
    for(int i= 0; i <= cadenaL.length(); i++){
        carac = cadenaL[i];
        nodo->insertar_Nodo(carac);
    }
}




void generar_ReporteE(){
    ofstream archivo_s("reporte.dot");
    Caracter *actual=new Caracter();
    int indice=1;
    string letra;
    actual = nodo->primero;
    archivo_s<<"graph lista{"<<endl;
    while(actual != NULL){
        if(actual->getcaracter() == ' '){
            letra = "Nodo"+to_string(indice) +" [label= "+"Espacio"+"];";
            archivo_s <<letra<<endl;
        }else if(actual->getcaracter() == 10){
            letra = "Nodo"+to_string(indice) +" [label= "+"salto"+"];";
            archivo_s <<letra<<endl;
        }else{
            letra = "Nodo"+to_string(indice) +" [label= "+ actual->getcaracter()+"];";
            archivo_s <<letra<<endl;
        }
      actual = actual->getsiguiente();
      indice++;
    }actual = nodo->primero;
    indice =1;
    while (actual != NULL) {
        letra = " ";
        letra = "Nodo"+to_string(indice)+"--"+"Nodo"+to_string(indice+1)+";";
        archivo_s<<letra;
        actual = actual->getsiguiente();
          indice++;
    }
    archivo_s<<"}"<<endl;
    archivo_s.close();
}
void generadorE(){
     system("dot -Tpng reporte.dot -o reporte.png");
}

void reporte_palabrasE(){
    ofstream archivo_s("reporte2.dot");
    datosP *actual = new datosP;
    actual= pilaBE->ultimoP;
    int indice=1;
    string letra;
    archivo_s<<"graph buscar{"<<endl;
    while(actual != NULL){
            letra = "Nodo"+to_string(indice) +" [label= \u0022 Buscada: \u0022"+ actual->getpalabraB()+
          +", fillcolor=green, style=filled, shape=rectangle];";
            archivo_s <<letra<<endl;
            actual = actual->getsiguiente();
            indice++;
    }actual = pilaBE->ultimoP;
    indice =1;
    while (actual != NULL) {
        letra = " ";
        letra = "Nodo"+to_string(indice+1)+"--"+"Nodo"+to_string(indice)+";";
        archivo_s<<letra;
        actual = actual->getsiguiente();
          indice++;
    }
    archivo_s<<"}"<<endl;
    archivo_s.close();
}

void generador2E(){
     system("dot -Tpng reporte2.dot -o reporte2.png");
}

void reporte_palabrasRE(){
    ofstream archivo_s("reporte3.dot");
    datosP *actual = new datosP;
    actual= pilaRE->ultimoP;
    int indice=1;
    string letra;
    archivo_s<<"graph buscar{"<<endl;
    while(actual != NULL){
            letra = "Nodo"+to_string(indice) +" [label= \u0022 Buscada: \u0022"+ actual->getpalabraB()+
          +", fillcolor=red, style=filled, shape=rectangle];";
            archivo_s <<letra<<endl;
            actual = actual->getsiguiente();
            indice++;
    }actual = pilaRE->ultimoP;
    indice =1;
    while (actual != NULL) {
        letra = " ";
        letra = "Nodo"+to_string(indice+1)+"--"+"Nodo"+to_string(indice)+";";
        archivo_s<<letra;
        actual = actual->getsiguiente();
          indice++;
    }
    archivo_s<<"}"<<endl;
    archivo_s.close();
}

void generador3E(){
     system("dot -Tpng reporte3.dot -o reporte3.png");
}
