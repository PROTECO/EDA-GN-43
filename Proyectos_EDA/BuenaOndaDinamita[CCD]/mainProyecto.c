/*
	Proyecto Final Curso Prebecario Estructura de Datos | PROTECO
	
	Lista Doblemente Enlazada
	
	Elaboraron:

		Ulises Castro Rodriguez

		Alan Salvador Chilpa Navarro

		Fabian Josafat Diaz Silleros

*/

// Librerias y encabezado
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lista.h"

// Prototipos
void menu();

// Funcion Main
int main(){
	
	int opc = 0; // Opcion, para las elecciones en el switch
	Lista * lista = getLista(); // Declaramos la lista
	
	// Elemento a leer del alumno
	char nombre[30];
	char num_cuenta[15];
	int edad=0;
	
	while(opc != 8){ // Loop hasta que se seleccione la opcion salir (8)
		
		menu(); // Imprimimos el menu
		
		printf("\nElige una opcion: ");
		scanf("%d",&opc); // leemos la opcion
		getchar(); // para limpiar el buffer
		
		switch(opc){ // switch opcion
			
			case 1: // Case de Ingresar Alumno
				// Pedimos el nombre
				printf("\nDigite el nombre: ");
				//fgets(nombre, 30, stdin);
				gets(nombre);
				printf("\nDigite el numero de cuenta: ");
				//fgets(num_cuenta, 15, stdin);
				gets(num_cuenta);
				printf("\nDigite la edad: ");
				scanf("%d",&edad);
				getchar();
				enlistarAlumno(lista, nombre, num_cuenta, edad);
				break;
			
			case 2: // Case de Eliminar Alumno
				
				if(desenlistarAlumno(lista) == -1){
					
					printf("\nNo hay Alumnos para borrar\n\n");
					
				}
				else{
					
					printf("\nAlumno eliminado\n\n");
					
				}
				break;
				
			case 3: // Case para Imprimir toda la lista
				
				imprimirLista(lista);
				break;
				
			case 4: // Case para Mostrar Alumno por Alumno
				
				recorrerLista(lista);
				break;
				
			case 5: // Case de indicar si esta vacia la lista
				
				if(estaVacia(lista) == 1){
					
					printf("\n\nLista Vacia\n\n");
					
				}
				else{
					
					printf("\n\nExisten Alumnos en la Lista\n\n");
					
				}
				break;
				
			case 6: // Case de Limpiar la lista
				if(limpiarLista(lista) == 0){
					
					printf("\n\nLa Lista ya estaba vacia\n\n");
					
				}
				else{
					
					printf("\n\nLista limpiada\n\n");
					
				}
				break;
			
			case 7: // Case de ver si un Alumno esta en la lista
				if(buscarAlumno(lista) == 1){
					
					printf("\n\nEl Alumno se encuentra dentro de la lista\n");
					
				}
				else{
					
					printf("\n\nNo se encontro el Alumno o no hay Alumnos en la lista\n");
					
				}
				break;
				
			case 8: // Case de Salir
				break;
				
			default: // case de cualquier otra cosa
				printf("\n\nElija una opcion valida, intente de nuevo\n");
				break;
			
		}

		
	}
	free(lista);
	
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
