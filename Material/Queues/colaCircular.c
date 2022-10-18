#include <stdio.h>
#include <stdlib.h>

#define LIMIT 5

int cqueue[LIMIT];
int choice, item;
int front, rear;

void insert() {
    if ((front == 0 && rear == LIMIT - 1) || (front == rear + 1)){
        printf("Queue overflow\n");
    }
    else {
        if (front == -1) {
            front = 0;
        }
        printf("Enter the element to be inserted in the queue:");
        scanf("%d", &item);
        if (rear == LIMIT - 1) {
            rear = 0;
        }
        else {
            rear++;
        }
        cqueue[rear] = item;
    }
}

void delete() {
    if (front == -1) {
        printf("Queue underflow\n");
    }
    else {
        if (front != -1) {
            printf("Element deleted from queue is: %d\n", cqueue[front]);
            if (front == rear) {
                front = rear = -1;
            }
            else {
                if (front == LIMIT-1) {
                    front = 0;
                }
                else {
                    front++;
                }
            }
        }
    }
}

void display() {
    int front_position = front;
    int rear_position = rear;
    if (front == -1) {
        printf("Empty queue\n");
    }
    else {
        if (front != -1) {
            printf("The elements of the queue are: \n");
        }
        if (front_position <= rear_position) {
            while(front_position <= rear_position){
                printf("%d\n", cqueue[front_position]);
                front_position++;
            }
        }
        else {
            while(front_position <= LIMIT-1) {
                printf("%d\n", cqueue[front_position]);
                front_position++;
            }
            front_position = 0;
            while(front_position <= rear_position) {
                printf("%d\n", cqueue[front_position]);
                front_position++;
            }
        }
    }
}

int main() {
    front = rear = -1;
    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice!!! \n");
                break;
        }
    } while(choice != 4);
    return 0;
}