#include<stdio.h>
#include<stdlib.h>

typedef struct{
	char *nombre;
	int   numCuenta;
	int   edad;
}Alumno;

typedef struct Elemento{
	Alumno alumno;				//Alumno tipo de dato alumno
	struct Elemento *siguiente;
	struct Elemento *atras;
		
}Nodo;

//PROTOTIPOS
void insertarAlumno(Nodo **inicio, Alumno alum);
Nodo *nuevoAlumno(Alumno alum);
void imprimirAlumos(Nodo *);
void buscarAlumo(Nodo *, Alumno alum);
Nodo *buscar_Alumno(Nodo *,Alumno alum);
/*void eliminarAlumo(Nodo *, Alumno alum);
Nodo *eliminar_Alumno(Nodo *,Alumno alum);*/

void eliminarAlumo(Nodo **, Alumno alum);

int main(){
	Nodo *inicio = NULL; Nodo *ptr=NULL;
	Alumno alumno;
	short opcion;
	printf("(1)  Ingresar alumno \n");
	printf("(2)  Eliminar alumno \n");
	printf("(3)  Imprimir lista de alumnos \n");
	printf("(4)  Muestra elemento por elemento la lista \n");
	printf("(5)  Indica si la lista esta vacia \n");
	printf("(6)  Limpia la lista de alumnos \n");
	printf("(7)  Buscar un alumno \n");
	printf("(0)  Terminar y limpiar \n");
	do {
		printf("Opcion >> ");
		scanf("%i",&opcion);
		fflush(stdin);
		switch(opcion){
			case 1:
				printf("Ingrea los datos siguientes \n");
				printf("Nombre:  ");
				scanf("%s", &alumno.nombre);
				printf("\nEdad:  ");
				scanf("%i", &alumno.edad);
				printf("\nNum de cuenta:  ");
				scanf("%i", &alumno.numCuenta);
				insertarAlumno(&inicio, alumno);
				break;
			case 2:
				printf("Proporcione el numero de cuenta del alumno a eliminar \n");
				printf("\nNum de cuenta:  ");
				scanf("%i", &alumno.numCuenta);
				eliminarAlumo(&inicio, alumno);
				break;
			case 3:
				imprimirAlumos(inicio);
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				printf("Ingrea los datos siguientes \n");
				printf("Nombre:  ");
				scanf("%s", &alumno.nombre);
				printf("\nNum de cuenta:  ");
				scanf("%i", &alumno.numCuenta);
				buscarAlumo(inicio, alumno);
				
				break;			
		}
	}while(opcion!=0); 
	
	return 0;
}



void insertarAlumno(Nodo **inicio, Alumno alum){
	Nodo *nuevo = nuevoAlumno(alum);
	nuevo -> siguiente = *inicio;
	nuevo -> atras =NULL;
	if (*inicio != NULL){
		(*inicio) -> atras = nuevo;
	}
	*inicio = nuevo; 
	
}


Nodo *nuevoAlumno(Alumno alum){
	Nodo *nodoAlu = (Nodo *) malloc(sizeof(Nodo));
	if(nodoAlu){
		nodoAlu -> alumno = alum;
		nodoAlu -> siguiente = nodoAlu -> atras =NULL;
	}else{
		printf("\nERROR AL ASIGNAR MEMORIA DINAMICA \n");
		exit(1);
	}
	return nodoAlu;
}

void imprimirAlumos(Nodo *p_alumno){
	printf("\nLista de alumnos \n");
	while(p_alumno){
		printf("Nombre: %s\n", &p_alumno->alumno.nombre);
		printf("Edad: %i\n", p_alumno->alumno.edad);
		printf("Num de cuenta: %i\n", p_alumno->alumno.numCuenta);
		printf("---------------------------------\n");
		p_alumno = p_alumno -> siguiente;
	}
} 

void buscarAlumo(Nodo *p_alumno, Alumno alum){
	Nodo *resultado = buscar_Alumno(p_alumno, alum);
	if(resultado){
		printf("\nAlumno encontrado\n");
		printf("--------------------------------------------\n");
		printf("Nombre: %s\n", &resultado->alumno.nombre);
		printf("Edad: %i\n", resultado->alumno.edad);
		printf("Num de cuenta: %i\n", resultado->alumno.numCuenta);
		printf("--------------------------------------------\n");		
	}else {
		printf("\n El alumno no se encuentra inscrito \n");
	}
}
Nodo *buscar_Alumno(Nodo *inicio, Alumno alum){
	while(inicio){
		if(alum.nombre == inicio->alumno.nombre){
			return inicio;
		}
		inicio = inicio->siguiente;
	}
	return inicio;
}

void eliminarAlumo(Nodo **inicio, Alumno alum){
	Nodo *actual;
	int encontrado = 0; //Banadera 
	actual = *inicio;
	/*Busqueda del nodo a eleiminar*/
	while((actual !=NULL)&&(!encontrado)){
		encontrado = (actual->alumno.numCuenta == alum.numCuenta);
		if (!encontrado){
			actual = actual->siguiente;
		}
	}
	if(actual !=NULL){
		if (actual == *inicio){
			*inicio = actual->siguiente;
			if(actual -> siguiente !=NULL){
				actual -> siguiente -> atras=NULL;
			}
		}else if (actual->siguiente!=NULL){
			actual->atras->siguiente = actual->siguiente; 
			actual->siguiente->atras= actual->atras;
		}else{
			actual->atras->siguiente=NULL;
		}
		free(actual);
	}
}

 
/*
https://www.youtube.com/watch?v=T63a0ZCPJ6Q
https://www.youtube.com/watch?v=XUO-vgqg0zc*/
