#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

class Rutas{
private:
    string nombre;
    string direccion;
    Rutas *Siguiente;
public:
    string getnombre(){
        return nombre;
    }
    void setnombre(string nombr){
        nombre=nombr;
    }
    string getdireccion(){
        return direccion;
    }
    void setdireccion(string dir){
        direccion = dir;
    }
    Rutas *getsiguiente(){
        return Siguiente;
    }
    void setsiguiente(Rutas *sig){
        Siguiente=sig;
    }
};
