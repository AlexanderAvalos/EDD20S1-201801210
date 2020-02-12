#include "lista_doble.h"
#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;

int menu = 0;
int largoC;
string cadena;
int main()
{
    while(menu<=5){
    cout<<"Menu"<<endl;
    cout<<"1.Insertar Inicio"<<endl;
    cout<<"2.Eliminar Ultimo"<<endl;
    cout<<"3.Buscar"<<endl;
    cout<<"4.Mostrar"<<endl;
    cout<<"5.salir"<<endl;
    cin>>menu;
    switch (menu) {
    case 1:
        char entrada;
        cout<<"ingrese caracter"<<endl;
        cin>> entrada;
        lista_Doble::insertar_Nodo(entrada);
        break;
    case 2:
        lista_Doble::eliminar_Ultimo();
        break;
    case 3:
        cout<<"inserte cadena a buscar"<<endl;
        cin>> cadena;
        largoC = cadena.length();
        lista_Doble::buscar_Cadena(cadena, largoC);
        break;
    case 4:
        lista_Doble::mostrar_Izquierda_a_Derecha();
        break;
    case 5:
        exit(0);
        break;
    }

}
    return 0;
}
