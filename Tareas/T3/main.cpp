#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */



struct Nodo {
	int dato;
	string nombre;
	Nodo *sig;
};

void insertar(Nodo *&lista, int data, string nom ) {
	Nodo *nuevo = new Nodo();
	nuevo->dato = data;
	nuevo->nombre = nom;
	Nodo *aux1 = lista;
	Nodo *aux2;
	if(lista == aux1) {
		lista = nuevo;
	} else {
		aux2->sig = nuevo;
	}
	nuevo->sig = aux1;
};
void mostrar(Nodo *lista) {
	Nodo *actual = new Nodo();
	actual = lista;
	while(actual != NULL) {
		cout<<actual->dato<<" "<<actual->nombre <<"-->";
		actual = actual->sig;
	}
	cout<<"\n";
}
void *Buscar (Nodo *lista,int car) {
	bool ver = false;
	Nodo *actual = new Nodo();
	actual = lista;
	while((actual != NULL)&&(actual->dato <=car)) {
		if(actual->dato == car) {
			ver = true;
		}
		actual = actual->sig;
	}
	if(ver == true) {
		cout<< "Carnet "<< car << " si esta en la lista \n";
	} else {
		cout<< "Carnet "<< car << " no esta en la lista \n";
	}
}
Nodo *BuscarN (Nodo *lista,int car) {
	Nodo *actual = new Nodo();
	actual = lista;
	while((actual != NULL)&&(actual->dato <=car)) {
		if(actual->dato == car) {
			return actual;
			break;
		}
		actual = actual->sig;
	}
}
void Eliminar(Nodo *lista) {
	Nodo *actual = new Nodo();
	actual = lista;
	if(actual->sig != NULL) {
		actual->sig = NULL;
	}else{
		cout<<"error";
	}
	mostrar(actual)
};


Nodo *lista = NULL;
int main() {

	int menu = 0;
	while(menu <=4) {

		cout<<"          Menu \n";
		cout<<"1. Insertar Nodo \n";
		cout<<"2. Eliminar Nodo \n";
		cout<<"3. Buscar Nodo \n";
		cout<<"4. Salir \n";
		cin >> menu;
		switch(menu) {
			case 1: {
				string nom;
				int car;
				cout<<"Inserte Carnet \n";
				cin >> car;
				cout<<"Inserte Nombre \n";
				cin>>nom;
				insertar(lista,car,nom);
				mostrar(lista);
				break;
			}
			case 2: {
				mostrar(lista);
				int no;
				cout<<"Inserte No carnet \n";
				cin >> no;
				Eliminar(BuscarN(lista,no));
				break;
			}
			case 3: {
				int carn;
				cout<<"Inserte Carnet \n";
				cin >> carn;
				Buscar(lista,carn);
				break;
			}

		}
	}
	return 0;
}
