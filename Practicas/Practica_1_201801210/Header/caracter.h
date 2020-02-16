#ifndef CARACTER_H
#define CARACTER_H
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
class Caracter{
private:
    char caracter;
    Caracter *Siguiente;
    Caracter *Anterior;
public:
    char getcaracter(){
        return caracter;
    }
    void setcaracter(char carac){
        caracter=carac;
    }
    Caracter *getsiguiente(){
        return Siguiente;
    }
    void setsiguiente(Caracter *sig){
        Siguiente=sig;
    }
    Caracter * getanterior(){
        return Anterior;
    }
    void setanterior(Caracter *ante){
        Anterior=ante;
    }
};
#endif // CARACTER_H
