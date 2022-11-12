/*

	Archivo de cabecera cola.h
	Aqui vamos a definir al alumno, al nodo y la lista

*/

#ifndef LISTA_H_
#define LISTA_H_

// Estructuras

typedef struct Alumno{ // Estructura Alumno
    
	char nombre[31]; // Arreglo de caracteres del nombre
    char num_cuenta[16]; // Arreglo de caracteres del numero de cuenta
    int edad; // Edad
    
} Alumno;

typedef struct Nodo{ // Estructura de los Nodos
	
	struct Alumno * alumno; // Alumno
	struct Nodo * next; // siguiente
	struct Nodo * prev; // anterior
	
}Nodo;

typedef struct Lista{ // Estructura de la Lista
	
	struct Nodo *cabeza; // Cabeza de la cola
	struct Nodo *cola; // Cola ... de la cola
	int tamanio; // tamanio de la cola
	
}Lista;

// Funciones
Alumno * getAlumno(char [], char [], int); // Funcion que genera un alumno
Nodo * getNodo(Alumno *, Nodo *); // Funcion que genera un nodo
Lista * getLista(); // Funcion que genera la cola
void encolarAlumno(Lista *, char [], char [], int); // Funcion que encola un nodo
int desenlistarAlumno(Lista *); // Funcion que desencola un nodo
void imprimirLista(Lista *); // Imprime la lista
void recorrerLista(Lista *); // Recorre la lista y tiene la opcion de desencolar
int estaVacia(Lista *); // Comprueba si esta vacia la lista
int limpiarLista(Lista *); // Limpia la lista
int buscarAlumno(Lista *); // Busca un Alumno en la lista

#endif
