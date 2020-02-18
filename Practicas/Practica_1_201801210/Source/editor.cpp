#include "editor.h"
#include <stdlib.h>
#include <iostream>
#include <ncurses.h>
#include <curses.h>
#include "lista_doble.h"
#include "fstream"
#include "pilaB.h"
using namespace std;
WINDOW *nueva_ventana(int largo, int ancho, int pos_y, int pos_x);
bool con = false;
void guardar_archivo(string ruta);
void mostrar(WINDOW *vent);
void buscar_y_reeplazar(string cadenaL, string palabra_B, string palabra_N);
Nodo *nodo1 = new Nodo();
NodoP *pilaB=new NodoP();
NodoP *pilaR = new NodoP();
void Editor::crear_Editor(){
    Caracter *actual = new Caracter;
    char cadena;
    string ruta;
    string cadenaL;
    string bus, rem;
    char buscar,reemplazar;
    int x,y;
    int marcox=75,marcoy=20;
    WINDOW *ventana;
    initscr();
    raw();
    refresh();
    ventana = nueva_ventana(marcoy, marcox, 2,2);
    keypad(ventana,true);
    wprintw(ventana,"^W buscar y editar  ^C Reportes  ^S Guardar");
    wmove(ventana,2,2);
    int caracter;
    while(con != true){
        getyx(ventana,y,x);
        if(x == 73){
            getyx(ventana,y,x);
            wmove(ventana,y+1,2);
        }
        if(y==18){
           getyx(ventana,y,x);
            wclear(ventana);
            crear_Editor();
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
            nodo1->borrar_ultimo();
            break;
        case KEY_BACKSPACE:
            getyx(ventana,y,x);
            wmove(ventana,y,x-1);
            break;
        case 3:
            printw("Reportes");
            break;
        case 10:
            getyx(ventana,y,x);
            wmove(ventana,y+1,2);
            nodo1->insertar_Nodo('\n');
            break;
        case 19:
            wmove(ventana,marcoy-1,2);
            wprintw(ventana,"Escriba nombre: ");
            do{
            cadena = wgetch(ventana);
            ruta = ruta + cadena ;
        }while(cadena != 10);
            guardar_archivo(ruta);
            break;
        case 23:
            actual=nodo1->primero;
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
          buscar_y_reeplazar(cadenaL,bus,rem);
          ventana = nueva_ventana(20,75,2,2);
          wmove(ventana,2,2);
          actual = nodo1->primero;
          wmove(ventana,2,2);
          while(actual != NULL){
              getyx(ventana,y,x);
              if(actual->getcaracter() == '\n'){
                  wmove(ventana,y+1,2);
              }else{
                  wprintw(ventana,"%c",actual->getcaracter());}
              actual = actual->getsiguiente();
          }
          pilaB->push(bus,rem,"No Revertido");
             break;
         case 24:
             con = true;
             delwin(ventana);
             break;
        case 25:
            pilaR->pop();
            buscar_y_reeplazar(cadenaL,bus,rem);
            wclear(ventana);
            ventana = nueva_ventana(20,75,2,2);
            wmove(ventana,2,2);
            actual = nodo1->primero;
            wmove(ventana,2,2);
            while(actual != NULL){
                getyx(ventana,y,x);
                if(actual->getcaracter() == '\n'){
                    wmove(ventana,y+1,2);
                }else{
                    wprintw(ventana,"%c",actual->getcaracter());}
                actual = actual->getsiguiente();
            }
            pilaB->push(bus,rem,"No Revertido");
            break;
        case 26:
            pilaB->pop();
            buscar_y_reeplazar(cadenaL,rem,bus);
            wclear(ventana);
            ventana = nueva_ventana(20,75,2,2);
            wmove(ventana,2,2);
            actual = nodo1->primero;
            wmove(ventana,2,2);
            while(actual != NULL){
                getyx(ventana,y,x);
                if(actual->getcaracter() == '\n'){
                    wmove(ventana,y+1,2);
                }else{
                    wprintw(ventana,"%c",actual->getcaracter());}
                actual = actual->getsiguiente();
            }
             pilaR->push(bus,rem,"Revertido");
            break;
         default:
           nodo1->insertar_Nodo(caracter);
            break;
         }
     }
    refresh();
    endwin();
}

void guardar_archivo(string ruta){
    ofstream archivo_s(ruta);
    Caracter*actual=new Caracter();
    actual = nodo1->primero;
    while(actual != NULL){
            archivo_s << actual->getcaracter();
            actual = actual->getsiguiente();
    }
    archivo_s.close();
}
WINDOW *nueva_ventana(int largo, int ancho, int pos_y, int pos_x)
{ WINDOW *local_win;
  local_win = newwin(largo, ancho, pos_y, pos_x);
  box(local_win, 0, 0);
  wrefresh(local_win);
  return local_win;
}

void buscar_y_reeplazar(string cadenaL,string palabra_B,string palabra_N){
    int posicion = cadenaL.find(palabra_B);
    while(posicion != -1){
    cadenaL.replace(posicion,palabra_B.size(),palabra_N);
    posicion = cadenaL.find(palabra_B, posicion + palabra_N.size());
    }
    nodo1->borrar_lista();
    char carac;
    for(int i= 0; i <= cadenaL.length(); i++){
        carac = cadenaL[i];
        nodo1->insertar_Nodo(carac);
    }
}
