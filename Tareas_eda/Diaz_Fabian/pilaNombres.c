//----------------------Importamos bibliotecas------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Se declara la estructura del nodo
struct nodo {
    char letra;//contenido
    struct nodo *siguiente; //Apuntador a nodo siguiente
};

//Tope de la pila
struct nodo *superior = NULL;

//Tamaño de la pila
int tamanio=-1;

//Metodo para ver si esta vacia
bool vacia(){
    return superior == NULL;
}

//Metodo para agregar pushh
void agregar(char letra) {
    printf("Agregando %c\n", letra);
    // El que se agregará; reservamos memoria
    struct nodo *nuevoNodo = malloc(sizeof(struct nodo));
    // Le ponemos el dato
    nuevoNodo->letra = letra;
    // Y ahora el nuevo nodo es el superior, y su siguiente
    // es el que antes era superior
    nuevoNodo->siguiente = superior;
    superior = nuevoNodo;
    // le sumamos uno al tamaño
    tamanio += 1;
}

//Metodo para eliminar el ultimo nodo
void eliminarUltimo(void) {
    if (superior != NULL) {
        // Para liberar la memoria más tarde debemos
        // tener la referencia al que vamos a eliminar
        struct nodo *temporal = superior;
        // Ahora superior es a lo que apuntaba su siguiente
        superior = superior->siguiente;
 
        // Liberar memoria que estaba ocupando el que eliminamos
        free(temporal);
        // Le restamos uno al tamaño
        tamanio -= 1;
    }
}


//Metodo para imprimir la pila
void imprimir(void) {
    printf("Imprimiendo...\n");
    struct nodo *temporal = superior;
    while (temporal != NULL) {
        printf("%c\n", temporal->letra);
        temporal = temporal->siguiente;
    }
}


//Metodo que regresa el valor del ultimo nodo top
char ultimo(){
    if(superior == NULL) return -1;
    return superior->letra;
}

// Funcion para mostrar el nombre
void mostrarNombre(void) {
    //Arreglo para el nombre
    char nombre[tamanio+1];
    int a = 0; // variable para la iteracion
    printf("Imprimiendo...\n");
    struct nodo *temporal = superior;
    while (temporal != NULL) {
        nombre[a] = temporal->letra;
        a++;
        temporal = temporal->siguiente;
        
    }
    printf("\n");
    for(int i=0; i<=a; i++){
        printf("%c",nombre[i]);
        eliminarUltimo();
    }
}

int main() {
	int eleccion;
	char letra;
	while(eleccion != -1){
		printf("\n--BIENVENIDO--\n1.- Agregar\n2.- Eliminar\n3.- Imprimir pila\n4.- Comprobar si está vacía\n5.- Mostrar último elemento\n6.- Mostrar nombre\n-7.- Salir\n\n\tElige: ");
		scanf("%d", &eleccion);
		switch(eleccion){
			case 1:
				printf("Ingresa la letra por agregar: ");
				getchar(); // Limpiar buffer
				letra = getchar(); // Leer letra
				agregar(letra);
			break;
			case 2:
				eliminarUltimo();
				printf("Eliminando el último\n");
			break;
			case 3:
				imprimir();
			break;
			case 4:
				if(vacia()){
					printf("La pila está vacía\n");
				}else{
					printf("La pila NO está vacía\n");
				}
			break;
			case 5:
				printf("El último elemento es: %c\n", ultimo());
			break;
			case 6:
			    mostrarNombre();
			break;
			case 7:
			    eleccion = -1;
			break;
		}
	}
	
	printf("\n\n\nNos vemos.");
}