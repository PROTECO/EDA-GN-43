/*

	Archivo C del archivo de cabecera cola.h
	
	Aqui se 

*/

// Encabezados y librerias
#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

// Funciones

// Funcion que genera un alumno
Alumno * getAlumno(char * nombre, char * num_cuenta, int edad){
	
	// Crea el Alumno
	Alumno * ref = (Alumno * ) malloc(sizeof(Alumno));
	
	// Asignamos nombre, num cuenta y edad
	ref->nombre = nombre;
    ref->num_cuenta = num_cuenta;
    ref->edad = edad;
	
	// Retornamos el Alumno creado
	return ref;
}

// Funcion que genera un nodo
Nodo * getNodo(Alumno * alumnito, Nodo * prev){
	
	// Crea el Nodo
    Nodo * ref = (Nodo * ) malloc(sizeof(Nodo));
    
    // Asignamos Alumno, siguiente (en null) y anterior
    ref->alumno = alumnito;
    ref->next = NULL;
    ref->prev = prev;
	
	// Retornamos el Nodo creado
    return ref;
	
}

// Funcion que genera la cola
Queue * getQueue(){
	
	// Creamos la cola
    Queue * ref = (Queue * ) malloc(sizeof(Queue));
    
    // asignamos Null al nodo cabeza (primer nodo) y al nodo cola (ultimo nodo)
    ref->cabeza = NULL;
    ref->cola = NULL;
    
    // retornamos
    return ref;
	
}


void encolarAlumno(Queue *, char *, char *, int); // Funcion que encola un nodo
int desencolarAlumno(Queue *); // Funcion que desencola un nodo
void imprimirCola(Queue *); // Imprime la cola
void recorrerCola(Queue *); // Recorre la cola y tiene la opcion de desencolar
int estaVacia(Queue *); // Comprueba si esta vacia la cola
int limpiarCola(Queue *); // Limpia la cola
int buscarAlumno(Queue *); // Busca un Alumno en la cola
