#ifndef ABRIR_EN_EDITOR_H
#define ABRIR_EN_EDITOR_H
#include <string>
#include "editor_rutas.h"

using namespace std;

class Abrir_En_Editor
{
public:
    Abrir_En_Editor();
    static void crear_EditorA();
    static NodoC * leer_archivo(string direccion, NodoC *lista);
};

#endif // ABRIR_EN_EDITOR_H

