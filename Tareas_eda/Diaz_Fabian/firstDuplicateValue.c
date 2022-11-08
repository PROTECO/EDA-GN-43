/*

    First Duplicate Value | C

    Curso Prebecarios Estructura de Datos | PROTECO

    Elaboro: Fabian Josafat Diaz Silleros

*/

// Librerias
#include <stdio.h>

// Prototipos
int firstDuplicateValue(int [], int);

// Funcion Main
int main(){

    int result = 0, n = 7; // result es el resultado y n el numero de datos en el array
    int array[7] = {2,1,3,1,3,2,4}; // declaramos el array (por practicidad ponemos uno pre hecho)

    result = firstDuplicateValue(array, n); // llamamos la funcion firstDuplicateValue
    if(result != -1){ // si no es -1

        printf("\n\t%d\n\n", result); // imprimimos el resultado

    }
    else{ // si es -1

        printf("\nNo duplicate values\n"); // indicamos que no hay numero duplicado

    }


    return 0;
}

// Primer valor duplicado
int firstDuplicateValue(int array[], int n){
    
    int value; // declaramos value, para guardar el valor a comparar
    int actual = 0; // declaramos el termino actual 
    value = array[actual]; // le asignamos a value el primer termino

    for(int i=1; i<n; i++){ // for que empieza a iterar en el segundo termino

        if(value == array[i]){ // si se repite lo almacenado en value y el termino actual

            if(i - actual > 1){ // si hay mas de una iteracion entre el numero a comparar y en donde se hizo match

                int rec = 0; // declaramos una variable para almacenar el resultado de la ejecucion de la funcion recursiva
                rec = firstDuplicateValue(array, i); // llamamos la funcion misma pero con un tamanio menor a donde se encontro el match

                if (rec == -1){ // si no hubo un match dentro del match
                    return value; // retornamos el valor
                }
                else{ // si hubo match
                    return rec; // regresamos el resultado
                }

            }
            else{ // si no hubo mas de una iteracion entre el numero a comparar y el match
                return value; // retornamos el valor
            }
        }

        if(i == n-1 && actual != n-1){ // si i ya esta en su ultima iteracion y todavia no estamos comparando el ultimo termino

            actual += 1; // sumamos uno a actual
            i = actual; // le asignamos actual a i para reiniciar la iteracion
            value = array[actual]; // le asignamos a value el termino siguiente

        }

    }

    // en caso de que no retorne dentro del for (no hay match de valor duplicado)
    return -1;
}
