//Librerias
#include <stdlib.h>
#include <iostream>
#include <ncurses.h>
#include <curses.h>
using namespace std;
//clases
#include "pilaB.h"

#include "lista_doble.h"
#include "editor.h"
#include "abrir_en_editor.h"
#include "editor_rutas.h"


NodoC *nodoC1 = new NodoC();

string no;
 int smenu;

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
       nodoC1 = Abrir_En_Editor::leer_archivo(no, nodoC1);
       Abrir_En_Editor::crear_EditorA();
        break;
    case 3:
        Editor_Rutas::e_rutas(nodoC1);

        break;
    case 4:
        cout<<"see you later";
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
