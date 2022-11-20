#include<stdio.h>
#include<stdlib.h>
#include <csignal>

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
//inicializando lista
Nodo *inicio = NULL; Nodo *ptr=NULL;
//PROTOTIPOS
void insertarAlumno(Nodo **inicio, Alumno alum);
Nodo *nuevoAlumno(Alumno alum);
void imprimirAlumos(Nodo *);
void buscarAlumo(Nodo *, Alumno alum);
Nodo *buscar_Alumno(Nodo *,Alumno alum);
/*void eliminarAlumo(Nodo *, Alumno alum);
Nodo *eliminar_Alumno(Nodo *,Alumno alum);*/
void eliminarAlumo(Nodo **, Alumno alum);
void porpartesAlumno(Nodo *);
void inidicandoListaVacia(Nodo *);
void limpiarlista(Nodo **);
void menu();
int main(){
    menu();
    return 0;
}
//en el menu mandamos a llamar a cada uno de los metodos con lo que recibe
void menu(){
    Alumno alumno;
    short opcion;
    //menu
    printf("(1)  Ingresar alumno \n");
    printf("(2)  Eliminar alumno \n");
    printf("(3)  Imprimir lista de alumnos \n");
    printf("(4)  Muestra elemento por elemento la lista \n");
    printf("(5)  Indica si la lista esta vacia \n");
    printf("(6)  Limpia la lista de alumnos \n");
    printf("(7)  Buscar un alumno \n");
    printf("(0)  Terminar y limpiar \n");
    //un do para que se repita
    do {
        //lector de opciones
        printf("Opcion >> ");
        scanf("%i",&opcion);
        fflush(stdin);
        switch(opcion){
            //pedimos datos y mandamos a llamar al metodo insertar alumno
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
                //pedimos numero de cuenta para borrar a esa persona
                printf("Proporcione el numero de cuenta del alumno a eliminar \n");
                printf("\nNum de cuenta:  ");
                scanf("%i", &alumno.numCuenta);
                eliminarAlumo(&inicio, alumno);
                break;
            case 3:
                //mandamos a llamar al metodo imprimir alumnos
                imprimirAlumos(inicio);
                break;
            case 4:
                //mandamos al metodo imprimir por partes
                porpartesAlumno(inicio);
                break;
            case 5:
                //indicamos si la lista esta vacia mandando a llamar a este metodo
                inidicandoListaVacia(inicio);
                break;
            case 6:
                //limpiamos la lista borrando todos los nodos
                limpiarlista(&inicio);
                break;
            case 7:
                //buscamos un alumno con el metodo y pedimos datos
                printf("Ingrea los datos siguientes \n");
                printf("Nombre:  ");
                scanf("%s", &alumno.nombre);
                printf("\nNum de cuenta:  ");
                scanf("%i", &alumno.numCuenta);
                buscarAlumo(inicio, alumno);

                break;
            case 8:
                //cerramos y limpiamos lista
                limpiarlista(&inicio);
                opcion=0;
                break;
        }
    }while(opcion!=0);
}
//Aqui estan como se desarrollo cada metodo con sus argumentos que recibe
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
void inidicandoListaVacia(Nodo *p_alumno) {
    if (p_alumno == NULL) {
        printf("\nLA LISTA ESTA VACIA\n\n");
        printf("TE REGRESARE AL MENU...\n");
        for (int i = 1; i < 4 ; ++i) {
            sleep(1);
            printf("%d\n",i);
        }
        menu();
    }
}
void limpiarlista(Nodo **inicio){
    Nodo *actual;
    actual = *inicio;
    Nodo *temp;
    if (actual == NULL){
        printf("\nLA LISTA ESTA VACIA\n\n");
        printf("SACANDOTE AL MENU...\n");
        for (int i = 1; i < 4 ; ++i) {
            sleep(1);
            printf("%d\n",i);
        }
        menu();
    }
    else {
        while (actual!=NULL){
            if (actual == *inicio) {
                *inicio = actual->siguiente;
                if (actual->siguiente != NULL) {
                    actual->siguiente->atras = NULL;
                }
            } else if (actual->siguiente != NULL) {
                actual->atras->siguiente = actual->siguiente;
                actual->siguiente->atras = actual->atras;

            } else {
                actual->atras->siguiente = NULL;
            }
            free(actual);
            actual=*inicio;
        }
    }
}
void eliminarAlumo(Nodo **inicio, Alumno alum){
    Nodo *actual;
    int encontrado = 0; //Banadera
    actual = *inicio;
    while((actual !=NULL)&&(!encontrado)){
        encontrado = (actual->alumno.numCuenta == alum.numCuenta);
        if (!encontrado){
            actual = actual->siguiente;
        }
    }
    if(actual != NULL){
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

void porpartesAlumno(Nodo *p_alumno){
    short opcion1;
    if (p_alumno == NULL){
        printf("\nLA LISTA ESTA VACIA\n\n");
        printf("SACANDOTE AL MENU...\n");
        for (int i = 1; i < 4 ; ++i) {
            sleep(1);
            printf("%d\n",i);
        }
        menu();
    }
    else {
        printf("\nAlumnos Por partes \n");
        do {
            printf("Nombre: %s\n", &p_alumno->alumno.nombre);
            printf("Edad: %i\n", p_alumno->alumno.edad);
            printf("Num de cuenta: %i\n", p_alumno->alumno.numCuenta);
            printf("---------------------------------\n");
            printf("1)Siguiente 2)anterior 3)salir\n");
            printf("Opcion >> ");
            scanf("%i", &opcion1);
            fflush(stdin);
            switch (opcion1) {
                case 1:
                    if (p_alumno->siguiente == NULL) {
                        printf("Ya no hay mas alumnos despues de este\n");
                        p_alumno = p_alumno;
                    } else {
                        p_alumno = p_alumno->siguiente;
                    }
                    break;
                case 2:
                    if (p_alumno->atras == NULL) {
                        printf("ya no hay mas alumnos antes de este\n");
                        p_alumno = p_alumno;
                    } else {
                        p_alumno = p_alumno->atras;
                    }
                    break;
                case 3:
                    printf("\n");
                    menu();
                    break;
            }
        } while (opcion1 != 0);
    }
}