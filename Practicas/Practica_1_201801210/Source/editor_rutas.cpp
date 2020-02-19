#include "editor_rutas.h"
#include <stdlib.h>
#include <iostream>
#include <ncurses.h>
#include <curses.h>
#include "abrir_en_editor.h"
#include "fstream"
#include "string"
using namespace std;

WINDOW *nueva_ventana_R(int largo, int ancho, int pos_y, int pos_x);
void generador4();
void Editor_Rutas::e_rutas(NodoC *lista){
    Rutas *actual = new Rutas();
    NodoC *nodoC = lista;
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
    if(nodoC->primeroC!=NULL)
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
        for(int i=0; i<= actual->getnombre().length();i++){
            nom = actual->getnombre()[i];
            wprintw(ventana,"%c",nom);
        }
          for(int j=0; j<=actual->getdireccion().length();j++){
              dire = actual->getdireccion()[j];
              wprintw(ventana,"%c",dire);
          }
}
    int caracter;

   wmove(ventana,marcoy-2,x);
   if((caracter=wgetch(ventana)) == 24 ){
       ofstream archivo_s("reporte4.dot");
       Rutas *actual = new Rutas;
       actual= nodoC->primeroC;
       int indice=1;
       string letra;
       archivo_s<<"graph circular{"<<endl;
       do{
               letra = "Nodo"+to_string(indice) +" [label= \u0022 Buscada: \u0022"+ actual->getnombre()+
             +", fillcolor=red, style=filled, shape=rectangle];";
               archivo_s <<letra<<endl;
               actual = actual->getsiguiente();
               indice++;
       }while(actual != nodoC->primeroC);
       actual = nodoC->primeroC;
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
       generador4();
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


void generador4(){
     system("dot -Tpng reporte4.dot -o reporte4.png");
}
