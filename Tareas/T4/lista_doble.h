#ifndef LISTA_DOBLE_H
#define LISTA_DOBLE_H
#include <string.h>
#include <iostream>
#include <iomanip>
using namespace std;
class lista_Doble
{
public:
    lista_Doble();
    static bool vacio();
    static void mostrar_Izquierda_a_Derecha();
    static void mostrar_Derecha_a_Izquierda();
    static void insertar_Nodo(char dato);
    static void eliminar_Ultimo();
    static void buscar_Cadena(string cadenaE, int lar);

};

#endif // LISTA_DOBLE_H
