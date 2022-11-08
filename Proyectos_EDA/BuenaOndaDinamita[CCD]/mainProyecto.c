/*
	Proyecto Final Curso Prebecario Estructura de Datos | PROTECO
	
	Cola Doblemente Enlazada
	
	Elaboraron:

		Ulises Castro Rodriguez

		Alan Chilpa Navarro

		Fabian Josafat Diaz Silleros

*/

// Librerias y encabezado
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cola.h"

// Prototipos
void menu();

// Funcion Main
int main(){
	
	int opc = 0; // Opcion, para las elecciones en el switch
	Queue * queue = getQueue(); // Declaramos la cola
	
	while(opc != 8){ // Loop hasta que se seleccione la opcion salir (8)
		
		menu(); // Imprimimos el menu
		
		printf("\nElige una opcion: ");
		scanf("%d",&opc); // leemos la opcion
		getchar(); // para limpiar el buffer
		
		switch(opc){ // switch opcion
			
			case 1: // Case de Ingresar Alumno
				break;
			
			case 2: // Case de Eliminar Alumno
				break;
				
			case 3: // Case para Imprimir toda la cola
				break;
				
			case 4: // Case para Mostrar Alumno por Alumno
				break;
				
			case 5: // Case de indicar si esta vacia la cola
				break;
				
			case 6: // Case de Limpiar la lista
				break;
			
			case 7: // Case de ver si un Alumno esta en la cola
				break;
				
			case 8: // Case de Salir
				break;
				
			default: // case de cualquier otra cosa
				printf("\n\nElija una opcion valida, intente de nuevo\n");
				break;
			
		}

		
	}
	
	return 0;
}

// Funcion Menu
void menu(){

    printf("\n1. Ingresar Alumno\n");
    printf("2. Eliminar Alumno\n");
    printf("3. Imprimir lista de Alumnos\n");
    printf("4. Mostrar Alumno por Alumno\n");
    printf("5. Indicar si la lista esta vacia\n");
    printf("6. Limpiar lista\n");
    printf("7. Ver si un Alumno esta en la lista\n");
    printf("8. Salir\n");

}
