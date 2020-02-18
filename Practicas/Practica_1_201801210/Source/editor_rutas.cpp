#include "editor_rutas.h"
#include <stdlib.h>
#include <iostream>
#include <ncurses.h>
#include <curses.h>
#include "lista_circular.h"
#include "abrir_en_editor.h"
#include "fstream"
#include "string"
using namespace std;

WINDOW *nueva_ventana_R(int largo, int ancho, int pos_y, int pos_x);

void Editor_Rutas::e_rutas(){
    Rutas *actual = new Rutas();
    NodoC *nodoC;
    WINDOW *ventana;
    int x,y;
    int marcox=75,marcoy=20;
    initscr();
    raw();
    refresh();
    ventana = nueva_ventana_R(marcoy, marcox, 2,2);
    keypad(ventana,true);
    wprintw(ventana,"^x generar reporte");
    wmove(ventana,2,2);
    actual = nodoC->primeroC;
    char nom,dire;
    if(actual!=NULL)
     {  getyx(ventana,y,x);
          do{
            for(int i=0; i<= actual->getnombre().length();i++){
                nom = actual->getnombre()[i];
                wprintw(ventana,"%c",nom);
            }
              for(int j=0; j<=actual->getdireccion().length();j++){
                  dire = actual->getdireccion()[j];
                  wprintw(ventana,"%c",dire);
              }
               actual = actual->getsiguiente();
               wmove(ventana,y+1,x);
          }while(actual!= nodoC->primeroC);
      }
     else{
        wprintw(ventana,"lista vacia");
}
    int caracter;
    noecho();
   wmove(ventana,marcoy-2,x);
   if((caracter=wgetch(ventana)) == 24 ){
       wprintw(ventana,"reporte");
   }
    wrefresh(ventana);
    endwin();

}
WINDOW *nueva_ventana_R(int largo, int ancho, int pos_y, int pos_x)
{ WINDOW *local_win;
  local_win = newwin(largo, ancho, pos_y, pos_x);
  box(local_win, 0, 0);
  wrefresh(local_win);
  return local_win;
}
