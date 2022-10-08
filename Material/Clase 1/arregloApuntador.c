
#include <stdio.h>

int main()
{
    int a[7] = {1,2,0,4,-4,3,0};
    int *pointer = a;
    for(int i =0;i<7;i++){
        printf("Valor en memoria de p(%d) es: %p. Valor numerico: %d\n",i,pointer+i,*(pointer+i));
    }
    return 0;
    //Reto es hacerlo arreglo de dos dimenciones, matrices.
}
