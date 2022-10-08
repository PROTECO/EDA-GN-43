#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//strncpy(p->nombre, "Luis Cabrera Benito", MAXIMA_LONGITUD_CADENA);

struct pelicula{
    char nombre[100];
    int year,month,day;
    char director[100];
    float dinero_acumulado;
};
typedef struct pelicula pelicula;

int main()
{
    pelicula *p = malloc(sizeof(pelicula));
    if (p==NULL){
        printf("No hay memoria suficiente");
        free(p);
        return -1;
    }
    //p->nombre = "Titanic";
    strncpy(p->nombre,"Titanic",100);
    p->year = 1997;
    p->month = 01;
    p->day = 01;
    
    //p->director = "James Cameron";
    strncpy(p->director,"James Cameron",100);
    p->dinero_acumulado = 2.202; //Millones de USD
    
    printf("Peliculas...\n");
    printf("Titulo: %s\nFecha: %d-%d-%d\nDirector: %s\nRecaudado: %f",p->nombre,p->year,p->month,p->day,p->director,p->dinero_acumulado);

    free(p);
}
