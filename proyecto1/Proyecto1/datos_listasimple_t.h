#ifndef DATOS_LISTASIMPLE_T_H
#define DATOS_LISTASIMPLE_T_H
class datostop
{private:
    string jugadores;
    int puntuacion;
public:
    string getjugadores(){
        return jugadores;
    }
    void setjugadores(string jugar){
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
