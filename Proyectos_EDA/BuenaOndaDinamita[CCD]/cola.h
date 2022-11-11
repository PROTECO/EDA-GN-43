/*

	Archivo de cabecera cola.h
	Aqui vamos a definir al alumno, al nodo y la cola

*/

#ifndef COLA_H_
#define COLA_H_

// Estructuras

typedef struct Alumno{ // Estructura Alumno
    
	char *nombre; // Arreglo de caracteres del nombre
    char *num_cuenta; // Arreglo de caracteres del numero de cuenta
    int edad; // Edad
    
} Alumno;

typedef struct Nodo{ // Estructura de los Nodos
	
	struct Alumno * alumno; // Alumno
	struct Nodo * next; // siguiente
	struct Nodo * prev; // anterior
	
}Nodo;

typedef struct Queue{ // Estructura de la Cola
	
	struct Nodo *cabeza; // Cabeza de la cola
	struct Nodo *cola; // Cola ... de la cola
	int tamanio; // tamanio de la cola
	
}Queue;

// Funciones
Alumno * getAlumno(char [], char [], int); // Funcion que genera un alumno
Nodo * getNodo(Alumno *, Nodo *); // Funcion que genera un nodo
Queue * getQueue(); // Funcion que genera la cola
void encolarAlumno(Queue *, char [], char [], int); // Funcion que encola un nodo
int desencolarAlumno(Queue *); // Funcion que desencola un nodo
void imprimirCola(Queue *); // Imprime la cola
void recorrerCola(Queue *); // Recorre la cola y tiene la opcion de desencolar
int estaVacia(Queue *); // Comprueba si esta vacia la cola
int limpiarCola(Queue *); // Limpia la cola
int buscarAlumno(Queue *); // Busca un Alumno en la cola

#endif
