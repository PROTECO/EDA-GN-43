#include <stdio.h>
//Paso por valor.

int Upper(int numero); //n^n


int main()
{
    int numero = 5;
    printf("Numero antes de aplicar la funcion: %d\n",numero);
    Upper(numero);
    printf("Numero despues de aplicar la funcion: %d\n",numero);
    printf("El valor de la copia: %d",Upper(numero));
    return 0;
}

int Upper(int numero){
    numero = numero*numero;
}
