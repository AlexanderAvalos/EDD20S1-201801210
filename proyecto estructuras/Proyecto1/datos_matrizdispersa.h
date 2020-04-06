#ifndef DATOS_MATRIZDISPERSA_H
#define DATOS_MATRIZDISPERSA_H
#include "QString"
class datosMatriz
{
private:
    int punteo;
    QString palabra;
public:
    int getpunteo(){
        return punteo;
    }
    void setpunteo(int pun){
        punteo = pun;
    }
    QString getpalabra(){
        return palabra;
    }
    void setpalabra(QString palabra){
        this->palabra = palabra;
    }
};

#endif // DATOS_MATRIZDISPERSA_H
