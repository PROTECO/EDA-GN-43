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
Alumno * getAlumno(char nombre[], char num_cuenta[], int edad){
	
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

// Recorre la cola y tiene la opcion de desencolar
void recorrerCola(Queue * ref){
	
	if (estaVacia(ref) == 1){
    	
    	// Retornamos (No se puede imprimir si no hay nodos)
    	printf("\n\nNo hay alumnos que imprimir.\n");
        return;
        
    }
	
	// Declaramos numero de alumno actual y opcion (para el switch case)
	int num=1;
	int opc=0;
	
	// Asignamos la cabeza a un nodo cabeza
    Nodo * nodo = ref->cabeza;
    
    printf("\n\n");
    
    // Ciclo iterativo mientras el nodo actual no sea nulo
    while (nodo != NULL){
    	
    	// Imprimimos al alumno
    	printf("\t---------------------------\n");
    	printf("\tAlumno: %d", num);
		printf("\n\tNombre: %s", nodo->alumno->nombre);
    	printf("\n\tNumero de cuenta: %s", nodo->alumno->num_cuenta);
        printf("\n\tEdad: %d", nodo->alumno->edad);
    	printf("\n\t---------------------------\n\n");
    	
    	printf("1. Alumno Anterior \t 2. Borrar Alumno \t 3. Siguiente Alumno \t 4. Salir");
    	printf("\n\nSeleccione una opcion: ");
    	
		// Leemos opcion
		scanf("%d", &opc);
    	getchar();
    	
    	switch(opc){
    		
    		case 1: // Case de ir al Alumno anterior
    			// En caso de ser el primer alumno (cabeza)
				if(num == 1){
    				
    				printf("\n\nNo hay alumno interior, intente otra opcion.\n");
    				// Para ir directo a la siguiente iteracion
					continue;
    				
    			}
				else{ // En caso de no ser el primer alumno
					
					// Asignamos al nodo el nodo anterior y bajamos uno en la cuenta de alumno
					nodo = nodo->next;
					num--;
    				
    			}
    			
    			break;
    			
    		case 2: // Case de borrar al Alumno actual
			        
			    // Si la cabeza y la cola son el mismo nodo
			    if (ref->cabeza == ref->cola){
			     	
			    	// Borramos el unico nodo
			    	ref->cola = NULL;
			    	ref->cabeza = NULL;
			    	
			    	// Disminuimos el tamanio de la cola
			    	ref->tamanio--;
						
			    	printf("\n\nYa no hay alumnos unu\n");
			    	
			    	return; // Salimos de la funcion
			        
			    }
				else{ // Si hay mas de un nodo
					
					if(ref->cabeza == nodo){
											
						// Asignamos a la cabeza el nodo siguiente de la cola y ponemos al puntero previo del siguiente nodo en nulo
			        	ref->cabeza = ref->cabeza->next;
			        	ref->cabeza->prev = NULL;
			        
			        	// Disminuimos el tamanio de la cola
			    		ref->tamanio--;
			    		
			    		return; // Salimos de la funcion
						
					}
					else if(ref->cola == nodo){
						
						// Asignamos a la cola el nodo previo de la cola y ponemos al puntero siguiente nodo en nulo
			        	ref->cola = ref->cola->prev;
			        	ref->cola->next = NULL;
						
						// Disminuimos el tamanio de la cola
			    		ref->tamanio--;
						
						return; // Salimos de la funcion
						
					}
					else{
						
						// 
			        	nodo->next->prev = nodo->prev;
			        	nodo->prev->next = nodo->next;
						
						// Disminuimos el tamanio de la cola
			    		ref->tamanio--;
						
						return; // Salimos de la funcion
						
					}		
			        
			    }
			    
    			break;
    			
    		case 3: // Case de ir al Alumno siguiente
    			// En caso de ser el ultimo alumno (cola)
				if(ref->cola == nodo){
    				
    				printf("\n\nNo hay alumno siguiente, intente otra opcion.\n");
    				
    			}
				else{ // En caso de no ser el ultimo alumno
					
					// Asignamos al nodo el nodo siguiente y bajamos uno en la cuenta de alumno
					nodo = nodo->next;
					num++;
    				
    			}
    			break;
    		
    		case 4: // Caso de salir
    			break;
    		
    		default: // Caso de cualquier otra respuesta	
    			printf("\n\nIntente con una opcion valida.\n");
				break;
    		
    	}
		
		if(opc == 4){ // Si se eligio la opcion salir
			
			break; // rompemos el while y salimos
			
		}
		
    }
    
    printf("\n\n");
	
}

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

// Limpia la cola
int limpiarCola(Queue * ref){
	
	if (estaVacia(ref) == 1){
		
		// Retornamos falso si no tiene nodos
        return 0;
        
    }
    else{ 
		
		// Creamos un nodo que apunte a la cabeza
		Nodo * nodo = ref->cabeza;
		
		while(nodo != NULL){
			
			if(nodo->next == NULL){ // si no hay siguiente nodo
				
				// Eliminamos el nodo
				nodo = NULL;
				
			}
			else{ // Si hay siguiente nodo
				
				// asignamos nodo al nodo siguiente
				nodo = nodo->next;
				// eliminamos el nodo anterior
				nodo = NULL;
				
			}
			
		}
		
		// Reasignamos null a cabeza cola y 0 a tamanio
		ref->cabeza = NULL;
		ref->cola = NULL;
		ref->tamanio = 0;
		
		// Retornamos verdadero
        return 1;

    }
	
}

// Busca un Alumno en la cola
int buscarAlumno(Queue * ref){
	
	if (estaVacia(ref) == 1){
		
		// Retornamos 0 si no tiene nodos
        return 0;
        
    }
    else{ 

		char nom[30];
		printf("\n\nIngrese el nombre a buscar: ");
		gets(nom);
		
		Nodo * nodo = ref->cabeza;
		
		while(nodo != NULL){
			
			// Si nombre buscado es igual al nombre
			if(strcmp(nodo->alumno->nombre, nom) == 0){
				
				// Retornamos 1 de que si se encontro el nombre
				return 1;
				
			}
			
			// Asignamos el siguiente nodo
			nodo = nodo->next;
		}
		
		// Retornamos 2 de que no se encontro el nombre
        return 2;

    }
	
}
