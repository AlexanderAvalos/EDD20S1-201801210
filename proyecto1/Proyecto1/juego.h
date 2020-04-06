#ifndef JUEGO_H
#define JUEGO_H
#include <listadoble.h>
#include "arbol_buscar.h"
class juego
{
public:
    juego();
    static void crearJugador();
    static void elegirJugadores();
    static void ponerfichas(ListaDoble *lista);
    static void leerjason();
    static void menujuego(nodoArbol *jugador);
    static void insertarpalabra(nodoArbol *jugador);
    static void pedirficha(nodoArbol *jugador);
    static void reportes();
    static int buscarTD(QString letra,QString x, QString y);
};

#endif // JUEGO_H
