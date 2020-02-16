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
using namespace std;


WINDOW *nueva_ventana_E(int largo, int ancho, int pos_y, int pos_x);

bool cont = false;
string nombre;
void reconocer_Nombre(string dir);
void leer_archivo(string direccion);
void guardar_archivo_E(string ruta);
int x,y;
Nodo *nodo = new Nodo();
static NodoC *nodoC = new NodoC();
void Abrir_En_Editor::crear_EditorA(){

  string ruta;
    WINDOW *ventana;
    char buscar;
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
            printw("Reportes");
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
            wmove(ventana,marcoy-1,2);
            wprintw(ventana,"buscar y reemplazar: ");
            buscar = wgetch(ventana);
            refresh();
            wmove(ventana,2,2);
             break;
         case 24:
             cont = true;
            break;
         default:
            nodo->insertar_Nodo(caracter);
            break;
         }
     }
    refresh();
    endwin();
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
void Abrir_En_Editor::leer_archivo(string direccion){
    string texto;
    ifstream archivo;
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
