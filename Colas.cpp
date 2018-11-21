//colas
#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;
struct Nodo{
	int Dato;
	Nodo *Siguiente;
};
void agregarCola (Nodo *&, Nodo *&, int);
bool colaVacia(Nodo *);
void eliminarCola (Nodo *&, Nodo *&, int &);
int main(){
	Nodo *inicio=NULL;
	Nodo *fin=NULL;
	int valor, datos;
	cout << "\t¿Cuantos datos va a insertar? ";
	cin >> datos;
	for (int i=0; i<datos; i++){
		cout << i+1 << ": ";
		cin >> valor;
		agregarCola(inicio,fin,valor);
	}
	cout << "Eliminar cola" << endl;
	while(inicio  != NULL){
		eliminarCola(inicio, fin, valor);
		if (inicio != NULL){
			cout << valor << " , ";
		}
		else{
			cout << valor << ".";
		}
	}
	return 0;
}
void agregarCola (Nodo *&inicio, Nodo *&fin, int n){
	Nodo *nuevoNodo = new Nodo();
	nuevoNodo->Dato = n;
	nuevoNodo->Siguiente = NULL;
	if(colaVacia(inicio)){
		inicio = nuevoNodo;
	}
	else{
		fin->Siguiente = nuevoNodo;
	}
	fin = nuevoNodo;
	//Mostrar cola
	cout << "\t\"" << n <<"\"" << endl;
}
bool colaVacia (Nodo *inicio){
	if (inicio == NULL){
		return true;
	}
	else{
		return false; 
	}
}
void eliminarCola (Nodo *&inicio, Nodo *&fin, int &n){
	n = inicio->Dato;
	Nodo *aux = inicio;
	if (inicio == fin){
		inicio = NULL;
		fin = NULL;
	}
	else{
		inicio = inicio->Siguiente;
	}
	 delete aux;
}


