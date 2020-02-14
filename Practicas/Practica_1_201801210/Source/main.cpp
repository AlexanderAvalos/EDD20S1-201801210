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
#include"abrir_en_editor.h"


void menu(){
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

    int smenu;
    cin >> smenu;
    switch(smenu){
    case 1: cout<<"opcion 1\n";
        Editor::crear_Editor();
        break;
    case 2: cout<<"opcion 2\n";
        menu();
        break;
    case 3: cout<<"opcion 3\n";
        menu();
        break;
    case 4:
        exit(0);
        break;
    }
}

int main()
{
    Abrir_En_Editor::crear_EditorA();
return 0;
       }
