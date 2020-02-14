#include "editor.h"
#include <stdlib.h>
#include <iostream>
#include <ncurses.h>
#include <curses.h>
using namespace std;
WINDOW *nueva_ventana(int largo, int ancho, int pos_y, int pos_x);
bool con = false;


void Editor::crear_Editor(){
    char buscar;
    int x,y;
    int marcox=75,marcoy=20;
    WINDOW *ventana;
    initscr();
    raw();
    refresh();
    ventana = nueva_ventana(marcoy, marcox, 2,2);
    keypad(ventana,true);
    wmove(ventana,24,2);
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
             con = true;
             break;
         default:
            wprintw(ventana,"G");
            break;
         }
     }
    refresh();
    endwin();
}

WINDOW *nueva_ventana(int largo, int ancho, int pos_y, int pos_x)
{ WINDOW *local_win;
  local_win = newwin(largo, ancho, pos_y, pos_x);
  box(local_win, 0, 0);
  wrefresh(local_win);
  return local_win;
}
