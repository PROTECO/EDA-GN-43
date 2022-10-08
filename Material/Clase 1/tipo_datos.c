//Tipos de datos.
#include <stdio.h>
#include <stdbool.h>

int main()
{
    /*
    Tamano en memoria de enteros(int) 2 bytes. 
    Rango32768 a 32767
    */
    int i = 7852;
    printf("Entero: %d\n",i);
    /*
    Tamano en memoria de flotantes(float) 4 bytes.
    3.4E-38 a 3.4E+38
    */
    float f = 43.487;
    
    printf("Float: %f\n",f);
    
    
    /* Valores enteros cortos (sort int)
    Tamano en bytes: 2.
    Rango: -128 a 127
    */
    short s = 25; 
    printf("Short Int: %i\n",s);
    /*
    Entero con valor con mayores a 0.
    Tamano en bytes: 2.
    Rango: 0 a 65535
    */
    unsigned int d =3; //tamaño= 2bytes  Rango:0...65535
    printf("Unsigned Int: %i\n", d);
    
    // En el caso que se quiera un cierto numero de decimas.
    
    printf("Float con una decima: %.2f\n",f);
    
    /*
    Tamano en memoria de caracter (char) 1 byte
    Rango: 0 a 255
    */
    
    char c = 'c';
    printf("Caracter: %c\n",c);
    
    /* 
    Valores muy amplios (long)
    Tamano: 4 bytes
    Rango: 2147483648 a 2147483637
    */
    long l=46683513;
    printf("Long: %li\n",l);//Long int.
    
    /*
    Valores flotantes muy grandes (double)
    Tamano: 8 bytes.
    Rango: 1.7E-308 a 1.7E+308
    */
    
    double pi = 3.1415926535897932384;
    printf("Double: %lf\n",pi);
    
    /* Strings */
    /*
    En el caso que queriamos no solo tener un solo 
    caracter entonces sería un string un arreglo de
    caracteres.
    */

    char saludo[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
    printf("Mensaje: %s\n", saludo );

    char texto[50] =  "Esto es una cadena de texto";
    printf("%s\n",texto);
    
    
    /*
    Valores booleanos (bool) toma valores 0 y 1.
    Tamano: 1 byte.
    Rango: 0 y 1.
    Para en C se tiene que incluir en la biblioteca.
    
    #include<stdbool.h>
    */
    
    bool b = true;
    printf("booleano: %d\n",b);
    
    b = false;
    printf("booleano: %d\n",b);
    
    // Algo curioso con los valores booleanos.
    
    b = 45; //Tomara este valor. Cual sera el resultado?
    printf("Resultado: %d",b);
    
    return 0;
}
