//Librerias
#include <stdlib.h>
#include <iostream>
#include <ncurses.h>
#include <curses.h>
using namespace std;
//clases
#include "pilaB.h"
#include "lista_circular.h"
#include "lista_doble.h"
#include "editor.h"
#include "abrir_en_editor.h"
#include "editor_rutas.h"
string no;

 int smenu;
 NodoC *nodoC1;
void menu(){
    do{
    cout << "_________________________________________________\n";
    cout << "|                                         \t|\n";
    cout <<("| UNIVERSIADAD DE SAN CARLOS DE GUATEMALA  \t| \n");
    cout << "| FACULTAD DE INGENIERIA                  \t|\n";
    cout << "| ESTRUCTURA DE DATOS                     \t|\n";
    cout << "| PRACTICA 1                              \t|\n";
    cout << "| Rodolfo Alexander Avalos Soto           \t|\n";
    cout << "| Carnet: 201801210                       \t|\n";
    cout << "|                                         \t|\n";
    cout << "|\t\t MENÚ                           |\n";
    cout << "| 1. Crear Archivo                        \t|\n";
    cout << "| 2. Abrir Archivo                        \t|\n";
    cout << "| 3. Archivos Recientes                   \t|\n";
    cout << "| 4. salir                                \t|\n";
    cout << "|                                         \t|\n";
    cout << "|_______________________________________________|\n";


    cin >> smenu;
    switch(smenu){
    case 1:
        Editor::crear_Editor();
        break;
    case 2:
       cout<<"Ingrese ruta: ";
       cin>>no;
       Abrir_En_Editor::leer_archivo(no);
       clear();
       Abrir_En_Editor::crear_EditorA();
        break;
    case 3:
        Editor_Rutas::e_rutas();

        break;
    case 4:
        exit(0);
        break;
    }
    }while(smenu < 5);
}

int main()
{
    menu();
return 0;
       }
