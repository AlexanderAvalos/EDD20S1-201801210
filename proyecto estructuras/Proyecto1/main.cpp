#include <arbol_buscar.h>
#include <listadoble.h>
#include <listacirulardoble.h>
#include <listaletras.h>
#include <listasimplejp.h>
#include <matrizdispersa.h>
#include <cola.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <QString>
#include <juego.h>
#include <stdio.h>
#include<random>
using namespace std;

string no;
 int smenu;

void menu(){
    do{
    cout << "_________________________________________________\n";
    cout << "|                                         \t|\n";
    cout <<("| UNIVERSIADAD DE SAN CARLOS DE GUATEMALA  \t| \n");
    cout << "| FACULTAD DE INGENIERIA                  \t|\n";
    cout << "| ESTRUCTURA DE DATOS                     \t|\n";
    cout << "| PROYECTO1                              \t|\n";
    cout << "| Rodolfo Alexander Avalos Soto           \t|\n";
    cout << "| Carnet: 201801210                       \t|\n";
    cout << "|                                         \t|\n";
    cout << "|\t\t MENÚ                           |\n";
    cout << "| 1. Crear jugador                        \t|\n";
    cout << "| 2. cargar json                          \t|\n";
    cout << "| 3. jugar                                \t|\n";
    cout << "| 4. reportes                             \t|\n";
    cout << "| 5. salir                                \t|\n";
    cout << "|                                         \t|\n";
    cout << "|_______________________________________________|\n";


    cin >> smenu;
    switch(smenu){
    case 1:
        juego::crearJugador();
        break;
    case 2:
        juego::leerjason();
        break;
    case 3:
        juego::elegirJugadores();
        break;
    case 4:
        juego::reportes();
        break;
    }
    }while(smenu < 5);
}
int main()
{
menu();
return 0;

}



/*

    matrizDisperza *matriz = new matrizDisperza();
    QString a = "1", b = "1";
    QString aa = "2", bb= "2";
    QString aaa = "3", bbb= "3";
    matriz->insertarfila(b);
    matriz->insertarcomluna(a);
    matriz->insertarfila(bb);
    matriz->insertarcomluna(aa);
    matriz->insertarfila(bbb);
    matriz->insertarcomluna(aaa);
    cout<<"fila"<<endl;
    matriz->imprimirfila();
    cout<<"columna"<<endl;
    matriz->imprimircolumna();

    string letra1 = "a",letra2 = "a",letra3 = "c";
    QString val1,val2,val3;
    val1 = QString::fromStdString(letra1);
    val2 = QString::fromStdString(letra2);
    val3 = QString::fromStdString(letra3);
    matriz->insertar(val1,bbb,a);
    matriz->insertar(val2,bbb,aaa);
    matriz->insertar(val3,b,aaa);
    matriz->insertar(val3,bb,aa);
    matriz->Graficar();



int pun,pun2;
       listasimpleJP *lista = new listasimpleJP();
       cout<<"ingrese punteo"<<endl;
       cin>>pun;
       lista->agregarpunteo(pun);
       lista->recorrer();
       cout<<"ingrese punteo"<<endl;
       cin>>pun2;
       lista->agregarpunteo(pun2);
       lista->recorrer();
       cout<<"ingrese punteo"<<endl;
       cin>>pun2;
       lista->agregarpunteo(pun2);
       lista->recorrer();
       cout<<"ingrese punteo"<<endl;
       cin>>pun2;
       lista->agregarpunteo(pun2);
       lista->recorrer();

       lista->grafica();

    cola *lcola = new cola();
    char letra;
    int punto;
    int cant;
    for (int i = 0; i < 3; i++) {
        cout<<"ingrese letra"<<endl;
        cin>> letra;
        cout<<"ingrese punto"<<endl;
        cin>> punto;
        cout<<"ingrese cantidad"<<endl;
        cin>> cant;
        lcola->insertar(letra,punto);
    }

     listaciruclardoble *listaC = new listaciruclardoble();
    string letra;
    for (int i = 0; i < 5; i++) {
        cout<<"ingrese palabra"<<endl;
        cin>> letra;
        listaC->insertar_Palabra(letra);
    }
    listaC->graficar();

    ListaDoble *listaD = new ListaDoble();
    char letra;
    for (int i = 0; i < 5; i++) {
        cout<<"ingrese letra"<<endl;
        cin>> letra;
        listaD->insertar_Nodo(letra);
    }
    listaD->graficar();

    ARBOL_BUSCAR *arbol = new ARBOL_BUSCAR();
    string nombre = "";
    QString nombreC = "";
    for (int var = 0; var < 3; var++) {
        cout<<"ingrese nombre"<<endl;
            cin>>nombre;
            nombreC = QString::fromStdString(nombre);
            arbol->insertarDato(nombreC);
    }
    arbol->graphviz();
*/
