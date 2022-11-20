/*
	Cola doblemente enlazada en C
	
	Curso Prebecarios Estructura de Datos | PROTECO
	
	Elaboro: Fabian Josafat Diaz Silleros

*/

// Librerias
#include <stdio.h>
#include <stdlib.h>

// Estructura de la cola
typedef struct Nodo{
	
	int data; // Dato
	struct Nodo * next; // siguiente
	struct Nodo * prev; // anterior
	
}Nodo;

typedef struct queue{
	
	struct Nodo *head; // Cabeza
	struct Nodo *tail; // Cola ... de la cola
	int size; // tamanio de la cola
	
}Queue;

// Prototipos
void menu(); // Funcion del menu
Nodo * getNodo(int, Nodo *); // Funcion que genera un nodo
Queue * getQueue(); // Funcion que genera la cola
void enqueue(Queue *, int); // Funcion que encola un nodo
int dequeue(Queue *); // Funcion que desencola un nodo
int isEmpty(Queue *); // Comprueba si esta vacia la cola
int peek(Queue *); // Toma el primer nodo de la cola
void displayQueue(Queue *); // Imprime la cola

// Funcion principal

int main(){
	
	int opc = 0, number=0; // Declaramos las variables, para el switch y el numero del nodo
	Queue * queue = getQueue(); // Declaramos la cola
	
	while(opc != 6){ // while mientras la opcion no sea salir (5)
		
		
		
		menu(); // Imprimimos el menu
		printf("\nChoice an option: ");
		scanf("%d",&opc); // leemos la opcion
		getchar(); // para limpiar el buffer
		
		switch(opc){ // switch opcion
			
			case 1: // case de enqueue
				printf("\nEnter a number: ");
				scanf("%d",&number);
				getchar();
				enqueue(queue, number);
				break;
			
			case 2: // case de dequeue
				printf("\n\nDeleting the element...");
				
				if(dequeue(queue) == -1){
					
					printf("\nData not found\n\n");
					
				}
				else{
					
					printf("\nData succesfully deleted\n\n");
					
				}
				
				break;
				
			case 3: // case de si esta vacia la cola
				if(isEmpty(queue) == 1){
					
					printf("\n\nQueue is empty\n\n");
					
				}
				else{
					
					printf("\n\nQueue is not empty\n\n");
					
				}
				break;
				
			case 4: // case de imprimir todos los nodos
				displayQueue(queue);
				break;
				
			case 5: // case de imprimir el primer nodo
				
				if(isEmpty(queue) == -1){
					
					
				}
				else{
					
					printf("\n\n %d \n\n", peek(queue));
					
				}
				break;
				break;
				
			case 6: // case de salir
				break;
				
			default: // case de cualquier otra cosa
				printf("\n\nChoise a valid option\n");
				break;
			
		}

		
	}
	
	return 0;
}

// Funcion menu
void menu(){

    printf("\n1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Is the Queue Empty?\n");
    printf("4. Display all the elements\n");
    printf("5. Peek\n");
    printf("6. Exit\n");

}

// Funcion que genera un nodo 

Nodo * getNodo(int data, Nodo * prev){
	
	// Crea el nodo
    Nodo * ref = (Nodo * ) malloc(sizeof(Nodo));
    
    // asignamos dato, siguiente y anterior
    ref->data = data;
    ref->next = NULL;
    ref->prev = prev;
	
	// retorna
    return ref;
    
}

// Funcion de crear cola
Queue * getQueue(){
	
	// creamos la cola
    Queue * ref = (Queue * ) malloc(sizeof(Queue));
    
    // asignamos null al nodo cabeza y al nodo cola
    ref->head = NULL;
    ref->tail = NULL;
    
    // retornamos
    return ref;
    
}

// Funcion de encolar nodo
void enqueue(Queue * ref, int data){
	
	// se crea el nodo por medio de la funcion de crear nodo
    Nodo * nodo = getNodo(data, ref->tail);
    
    // si no hay nodos
    if (ref->head == NULL){
    	
    	// el nuevo nodo es la cabeza
        ref->head = nodo;
        ref->size++; // se aumenta en uno el tamanio de la queue
        
    }
    else{ // si hay nodos
    	
    	// se asigna el nuevo nodo al pointer de la cola
        ref->tail->next = nodo;
        ref->size = ref->size + 1; // se aumenta en uno el tamanio de la queue
        
    }
    
    // el nuevo nodo se asigna a la cola
    ref->tail = nodo;
    
}

// Funcion para desencolar un nodo
int dequeue(Queue * ref){
	
	// Comprobamos que no este vacia la cola
    if (isEmpty(ref) == 1){
    	
    	// si esta vacia la cola
        return -1;
        
    }
    else{ // si no esta vacia
    	
    	// tomamos el dato de la cabeza
        int data = peek(ref);
        
        // creamos un nodo auxiliar y le asignamos el nodo de la cabeza
        Nodo * aux = ref->head;
        
        // si el nodo de la cabeza es igual al de la cola
        if (ref->head == ref->tail){
        	
        	// ponemos en nulo la cola de la cola y la cabeza
            ref->tail = NULL;
            ref->head = NULL;
            
        }
		else{ // si hay mas nodos
			
			// asignamos a la cabeza el nodo siguiente y ponemos al puntero previo del siguiente nodo en nulo
            ref->head = ref->head->next;
            ref->head->prev = NULL;
            
        }
        
        // reducimos el tamaño y regresamos el dato 
        ref->size--;
        return data;
        
    }
}

// Funcion de imprimir cola
void displayQueue(Queue * ref){
	
	// creamos un nodo y le asignamos la cabeza
    Nodo * nodo = ref->head;
    
    printf("\n\n");
    
    // Si el nodo no es nulo
    while (nodo != NULL){
    	
    	// imprimimos el dato
        printf("  %d", nodo->data);
        // cambiamos al siguiente nodo
        nodo = nodo->next;
        
    }
    printf("\n\n");
    
}

// Funcion para saber si esta vacia la cola
int isEmpty(Queue * ref){
    
    // si el tamanio es cero
	if (ref->size == 0){
		
		// regresamos verdadero
        return 1;
        
    }
    else{ // si tiene nodos

		// regresamos falso
        return 0;

    }
}

// Funcion para obtener el primer dato de la cola
int peek(Queue * ref){
    
    // comprobamos si esta vacia la cola
	if (isEmpty(ref) == 1){
        
		printf("\n\n Empty Queue");
		// retornamos -1 si esta vacia
        return -1;
        
    }
    else{
        
        // retornamos el dato si no esta vacia
		return ref->head->data;
		
    }
}
