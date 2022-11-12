# Aplicaciones de las estructuras de datos en la vida real
---
## Estructuras de datos Estáticas
Son aquellas que hacen uso de vectores para implementarse, por lo que tienen un número limitado de elementos.<br>
***
### - Pila
Una <u>pila</u> es un contenedor de datos, su comportamiento se rige a base de un principio _LIFO_ (Last Input First Output). En esta estructura de datos, los datos se insertan y solo se pueden suprimir por un extremo, conocido como tope o cima, basicamente, el último en entrar es el primero en salir.

![Pila](https://4.bp.blogspot.com/-Hnka4CO97Kk/UJFJU-a91BI/AAAAAAAAAUI/PjUC6P7J-0g/s320/Pilas%2Ben%2Bc%2B%2B.jpg&container=blogger&gadget=a&rewriteMime=image)

### Aplicación
Actualmente, <u>los navegadores de internet</u> almacenan las direcciones visitadas recientemente en una pila. <br>
Cada vez que el usuario visita una página, su dirección es almacenada, de forma que cada vez que el usuario haga click en la flecha "**back**" (⬅️), se retira el último elemento insertado en la pila para mostrar en pantalla (lo que seria la última página visitada).<br>
<u>Recursividad</u><br>
<u>Expresiones aritméticas</u>: Un problema interesante en computación consiste en convertir expresiones en notación infija a su equivalente en notación prefija o posfija o prefija.<br>
Otra apliación de las pilas se puede ver en el método de <u>ordenación</u> rápida. <br>
Cuando se tiene un programa que <u>llama a un subprograma</u>, internamente se usan pilas para almacenar el estado de las variables del programa, así como instrucciones pendientes de ejecución en el momento que se hace la llamada.

***
### - Cola
Una <u>cola</u> también es una estructura de datos estática, es casi lo mismo que una pila pero se rige bajo el principio _FIFO_ (First Input First Output). En una cola los datos se ingresan por un extremo conocido como "**final**" (rear) y se insertan por otro extremo llamado "**frente**" (front). Se puede asociar con una fila de personas intentando ingresar a algún lugar.

![Cola](https://estructuradedatosunivia.files.wordpress.com/2014/11/b10.jpg)

### Aplicación
Es una estructura de datos que está presente en muchos <u>sistemas</u> operativos, Unix es un ejemplo, lleva el control de la ejecución de procesos, cada proceso en el sistema es almacenado en una lista y la misma se va recorriendo, dando un pequeño tiempo al microprocesador de procesarlos.<br>
Se utilizan también en <u>sistemas informáticos</u>, <u>transportes</u> y <u>operaciones de investigación</u>, donde los objetos, personas o eventos son tomados como datos que se almacenan y se guardan mediante colas para su posterior procesamiento. Generalmente esta estructura de datos se implementa en <u>lenguajes orientados a objetos</u>.
***

### - Lista
Una <u>lista</u> es un contenedor secuencial donde se pueden insertar y eliminar elementos independientemente al tamaño del contenedor. Una lista enlazada consiste en una colección de **nodos** conectados entre sí, estos nodos se sitúan en la memoria dinámica en direcciones no consecutivas. Cada uno de estos nodos se compone de una sección de datos y una referencia hacia el siguiente nodo de la lista.

![Lista](https://estructuradedatosunivia.files.wordpress.com/2014/11/b11.png)

### Aplicación 
Dentro de las secuencias de algunos programas de auto servicio o de atención de clientes, siempre se entrega algún ticket o comprobante de lo que el cliente ha adquirido con una cantidad y nombre de los artículos que ha comprado, en otros casos, se usan en tareas por terminar, ya sea en agendas electrónicas u otras aplicaciones móviles.
***


