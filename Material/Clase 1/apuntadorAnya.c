
#include <stdio.h>

int main()
{
    int anya_edge = 6;
    int *direcction_mem_anya = &anya_edge;
    
    printf("%p\n",direcction_mem_anya);
    printf("La edad de Anya Forger: %d\n",anya_edge);
    printf("Pasando un año...\n");
    //Paso un año después...
    
    *direcction_mem_anya = 7; //Contenido de la variable anya_edge.
    printf("La edad actual de Anya Forger: %d",anya_edge);
    
    
}


