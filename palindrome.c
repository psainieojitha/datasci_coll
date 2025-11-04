#include <stdio.h>
#define MAX 50

int Queue[MAX];
int front = -1;
int rear = -1;

void insert(int n) {
    if (rear == MAX - 1) {
        printf("Queue is full!\n");
    } else {
        if (front == -1) 
            front = 0;
        Queue[++rear] = n;
        printf("%d inserted into queue.\n", n);
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
        front = rear = -1; 
    } else {
        printf("Element dequeued: %d\n", Queue[front++]);
        if (front > rear) 
            front = rear = -1;
    }
}

void display() {
    if (front == -1)
        printf("Queue is empty!\n");
    else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", Queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int value, ch;

    while (1) {
        printf("\nMENU\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &value);
                insert(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
