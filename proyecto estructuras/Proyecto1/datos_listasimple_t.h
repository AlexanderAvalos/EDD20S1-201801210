#ifndef DATOS_LISTASIMPLE_T_H
#define DATOS_LISTASIMPLE_T_H
#include "QString"

class datostop
{
    QString jugadores;
    int puntuacion;
public:
    QString getjugadores(){
        return jugadores;
    }
    void setjugadores(QString jugar){
        jugadores = jugar;
    }
    int getpuntuacion(){
        return puntuacion;
    }
    void setpuntuacion(int puntos){
        puntuacion = puntos;
    }
};
#endif // DATOS_LISTASIMPLE_T_H
