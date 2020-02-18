#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
class datosP{
private:
    string palabraB;
    string palabraR;
    string estado;
    datosP *Siguiente;
public:
    string getpalabraB(){
        return palabraB;
    }
    void setpalabraB(string palabraB){
        palabraB=palabraB;
    }
    string getpalabraR(){
        return palabraB;
    }
    void setpalabraR(string palabraR){
       palabraR=palabraR;
    }
    string getestado(){
        return estado;
    }
    void setestado(string estado){
        estado=estado;
    }
    datosP *getsiguiente(){
        return Siguiente;
    }
    void setsiguiente(datosP *sig){
        Siguiente=sig;
    }
};
