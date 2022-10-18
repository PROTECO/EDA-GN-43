#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5 // Tamaño máximo de la cola

// Crear cola
int queue[MAX];

// Crear referencias HEAD y TAIL
int HEAD = -1;
int TAIL = -1;

// Para comprobar si la cola esta llena
bool isFull() {
    bool isQueueFull = false;
    if (TAIL == MAX-1) {
        isQueueFull = true;
    }
    return isQueueFull;
}

// Para comprobar si la cola esta vacia
bool isEmpty() {
    bool isQueueEmpty = false;
    if (HEAD == -1) {
        isQueueEmpty = true;
    }
    return isQueueEmpty;
}

// Meter, encolar, enqueue
void enqueue() {
    if (isFull() == true) {
        printf("Error: La cola esta llena (Queue is FULL)\n");
    }
    else {
        if (HEAD == -1) {
            HEAD = 0;
        }
        TAIL++;
        int value;
        printf("Enter a value to enqueue:");
        scanf("%d", &value);
        queue[TAIL] = value;
        printf("%d is added to the queue\n", value);
    }
}

// Sacar, desencolar, dequeue
void dequeue() {
    if (isEmpty() == true) {
        printf("Error: la cola esta vacia (Queue is empty)");
    }
    else {
        printf("%d is dequeued\n", queue[HEAD]);
        HEAD++;
        if (HEAD > TAIL) {
            HEAD = TAIL = -1;
        }
    }
}

void peek() {
    if (isEmpty() == true) {
        printf("Queue is empty \n");
    }
    else {
        printf("Top element is %d\n", queue[HEAD]);
    }
}

void display() {
    if (isEmpty() == true) {
        printf("Queue is empty \n");
    }
    else {
        int i;
        printf("Queue elements: \n");
        for (i = HEAD; i <= TAIL; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice;
    printf("----Queue using arrays----");
    while(1) {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display all the elements\n4.Peek top element\nEnter a choice:");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
            default:
                printf("\nPlease enter a valid choice:");
                break;
        }
    }
}