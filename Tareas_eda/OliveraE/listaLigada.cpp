#include <stdlib.h> 
#include <stdio.h>

//Nodo de una lista enlazada 
struct Nodo{
	char *nombre;
	Nodo *siguiente; 
};

//Prototipos de función
void insertar(Nodo *&,Nodo *&, char name[16]);		  //Introduce un nodo a la cola 
bool listaVacia(Nodo *); 					// Permite saber si una lista tiene elementos 

int main(){
	char nombre[16];
	
	// Declracion de punteros que indican el inicio y fin de una cola 
	Nodo *frente = NULL;
	Nodo *final = NULL;
	
	printf("inserte un elemento a la cola\n");
	scanf("%s",&nombre);
	insertar(frente, final, nombre);
	
	printf("inserte un elemento a la cola\n");
	scanf("%s",&nombre);
	insertar(frente, final, nombre);
	
	printf("inserte un elemento a la cola\n");
	scanf("%s",&nombre);
	insertar(frente, final, nombre);

	for(frente;final != NULL; frente= frente ->siguiente){
		printf("%s ", frente->nombre);		
	}
	printf("\n\n");
}

void insertar(Nodo *&frente, Nodo *&final , char name[]){
	Nodo *nuevoNodo = new Nodo();
	nuevoNodo -> nombre = name;
	nuevoNodo -> siguiente = NULL;
	if(listaVacia(frente)){
		frente = nuevoNodo;
	}else{
		final -> siguiente = nuevoNodo;
	}
	final = nuevoNodo;
	printf("Elemento insertado\n");
}

bool listaVacia(Nodo *frente){
	//Condicion if de una solo linea
	return (frente == NULL)? true: false;
}
