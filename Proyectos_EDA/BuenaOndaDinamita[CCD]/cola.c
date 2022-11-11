/*

	Archivo C del archivo de cabecera cola.h
	
	Aqui se encuentran las funciones de las structs

*/

// Encabezados y librerias
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include "cola.h"

// Funciones

// Funcion que genera un alumno
Alumno * getAlumno(char * nombre, char * num_cuenta, int edad){
	
	// Crea el Alumno
	Alumno * alumno = (Alumno * ) malloc(sizeof(Alumno));
	
	// Asignamos nombre, num cuenta y edad
	sprintf(alumno->nombre, "%s", nombre);
    sprintf(alumno->num_cuenta, "%s", num_cuenta);
    alumno->edad = edad;
	
	// Retornamos el Alumno creado
	return alumno;
}

// Funcion que genera un nodo
Nodo * getNodo(Alumno * alumno, Nodo * prev){
	
	// Crea el Nodo
    Nodo * nodo = (Nodo * ) malloc(sizeof(Nodo));
    
    // Asignamos Alumno, siguiente (en null) y anterior
    nodo->alumno = alumno;
    nodo->next = NULL;
    nodo->prev = prev;
	
	// Retornamos el Nodo creado
    return nodo;
	
}

// Funcion que genera la cola
Queue * getQueue(){
	
	// Creamos la cola
    Queue * ref = (Queue * ) malloc(sizeof(Queue));
    
    // asignamos Null al nodo cabeza (primer nodo) y al nodo cola (ultimo nodo)
    ref->cabeza = NULL;
    ref->cola = NULL;
    ref->tamanio = 0;
    
    // retornamos
    return ref;
	
}

// Funcion que encola un nodo
void encolarAlumno(Queue * ref, char nombre[], char num_cuenta[], int edad){
	
	// Creamos el alumno por medio de la funcion getAlumno
	Alumno * alumno = getAlumno(nombre, num_cuenta, edad);
	
	// Creamos el nodo por medio de la funcion de getNodo
    Nodo * nodo = getNodo(alumno, ref->cola);
    
    // Si no hay nodo en la cabeza de la cola
    if (ref->cabeza == NULL){
    	
    	// Hacemos la cabeza al nuevo nodo
        ref->cabeza = nodo;
        // Aumentamos el tamanio de la cola
		ref->tamanio++;
        
    }
    else{ // En caso de que ya existan nodos
    	
    	// Asignamos el nuevo nodo al apuntador de siguiente de la cola de la cola
        ref->cola->next = nodo;
        // Aumentamos el tamanio de la cola
        ref->tamanio = ref->tamanio + 1;
        
    }
    
    // Asignamos como cola al nuevo nodo
    ref->cola = nodo;
		
}

// Funcion que desencola un nodo
int desencolarAlumno(Queue * ref){
	
	// Si la cola esta vacia
    if (estaVacia(ref) == 1){
    	
    	// Retornamos -1 (No se puede realizar la operacion sin nodos)
        return -1;
        
    }
    else{ // En caso de que la cola tenga nodos
        
        // Asignamos la cabeza a un nodo auxiliar
        Nodo * aux = ref->cabeza;
        
        // Si la cabeza y la cola son el mismo nodo
        if (ref->cabeza == ref->cola){
        	
        	// Borramos el unico nodo
            ref->cola = NULL;
            ref->cabeza = NULL;
            
        }
		else{ // Si hay mas de un nodo
			
			// Asignamos a la cabeza el nodo siguiente de la cola y ponemos al puntero previo del siguiente nodo en nulo
            ref->cabeza = ref->cabeza->next;
            ref->cabeza->prev = NULL;
            
        }
        
        // Disminuimos el tamanio de la cola
        ref->tamanio--;
        
        // Retornamos 1 (Se ha realizado la operacion)
        return 1;
        
    }
	
}

// Imprime la cola
void imprimirCola(Queue * ref){
	
	if (estaVacia(ref) == 1){
    	
    	// Retornamos (No se puede imprimir si no hay nodos)
    	printf("\n\nNo hay alumnos que imprimir.\n");
        return;
        
    }
	
	int num=1;
	
	// Asignamos la cabeza a un nodo cabeza
    Nodo * nodo = ref->cabeza;
    
    printf("\n\n");
    
    // Ciclo iterativo mientras el nodo actual no sea nulo
    while (nodo != NULL){
    	
    	// Imprimimos al alumno
    	printf("---------------------------\n");
    	printf("Alumno: %d", num);
		printf("\nNombre: %s", nodo->alumno->nombre);
    	printf("\nNumero de cuenta: %s", nodo->alumno->num_cuenta);
        printf("\nEdad: %d", nodo->alumno->edad);
    	printf("\n---------------------------\n");
		    
		// Asignamos al siguiente nodo
        nodo = nodo->next;
        num++;
        
    }
    
    printf("\n\n");
	
}

void recorrerCola(Queue *); // Recorre la cola y tiene la opcion de desencolar

// Comprueba si esta vacia la cola
int estaVacia(Queue * ref){
	
	if (ref->tamanio == 0){
		
		// Retornamos verdadero si no tiene nodos
        return 1;
        
    }
    else{ 

		// Retornamos falso si tiene nodos
        return 0;

    }
}


void encolarAlumno(Queue *, char *, char *, int); // Funcion que encola un nodo
int desencolarAlumno(Queue *); // Funcion que desencola un nodo
void imprimirCola(Queue *); // Imprime la cola
void recorrerCola(Queue *); // Recorre la cola y tiene la opcion de desencolar
int estaVacia(Queue *); // Comprueba si esta vacia la cola
int limpiarCola(Queue *); // Limpia la cola
int buscarAlumno(Queue *); // Busca un Alumno en la cola
