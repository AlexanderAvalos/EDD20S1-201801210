#include "abrir_en_editor.h"
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
void lectura(string rut);
int x,y;


void Abrir_En_Editor::crear_EditorA(){
    WINDOW *ventana;
    char buscar;
    int marcox=75,marcoy=20;
    char cadena,car;
    string direccion;
    int contador=0,canti;
    string ruta;
    initscr();
    refresh();
    ventana = nueva_ventana_E(marcoy, marcox, 2,2);
    wprintw(ventana,"^W buscar y editar  ^C Reportes  ^S Guardar");
    wmove(ventana,marcoy-2,2);
    wprintw(ventana,"Ingresar Ruta: ");
   do{
        cadena = wgetch(ventana);
            ruta = ruta + cadena;
    }while(cadena != 10);
    canti = ruta.length();
    while(contador!=canti){
        if(contador ==0){
            direccion = direccion+'/';
        }else{
        direccion = direccion + ruta[contador+1];}
        contador++;
    }
    reconocer_Nombre(direccion);
    wmove(ventana,2,2);
    string texto;
    ifstream archivo;
    char prue;
    if(!archivo.is_open()){
        archivo.open(direccion,ios::in);
        if(archivo.fail()){
            wmove(ventana,2,2);
            cout<<direccion<<endl;
            cout<<texto.length();
            wprintw(ventana,"error al leer archivo");
        }else{
            while (!archivo.eof()) {
                getline(archivo,texto);
            }

        }
        archivo.close();
        for(int i = 0; i <= texto.length();i++){
            prue = texto[i];
            wprintw(ventana,"%c",prue);
        }
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
        }                                                                          //home/alex/Escritorio/prueba2.txt

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
            break;
        case 19:
            printw("guardar");
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
            wprintw(ventana,"G");
            break;
         }
     }
    refresh();
    endwin();
}

void reconocer_Nombre(string dir){
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
            cout<< nombre;
        }
        contador++;
    }
}
//home/alex/Escritorio/prueba2.txt


WINDOW *nueva_ventana_E(int largo, int ancho, int pos_y, int pos_x)
{ WINDOW *local_win;
  local_win = newwin(largo, ancho, pos_y, pos_x);
  box(local_win, 0, 0);
  wrefresh(local_win);
  return local_win;
}
