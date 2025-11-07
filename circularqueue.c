#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int front = -1;
int rear = -1;
int cq[SIZE];

void enque(int val) {
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1)) {
        printf("Queue is full\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % SIZE;
        cq[rear] = val;
        printf("Inserted value: %d\n", val);
    }
}

int deque() {
    int ele;
    if (front == -1) {
        printf("Queue is empty (underflow)\n");
        return -1;
    } else {
        ele = cq[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
        printf("Deleted value: %d\n", ele);
        return ele;
    }
}

void disp() {
    int i;
    if (front == -1) {
        printf("Empty queue\n");
    } else {
        printf("\nFront = %d\n", front);
        printf("Items: ");
        for (i = front; i != rear; i = (i + 1) % SIZE) {
            printf("%d ", cq[i]);
        }
        printf("%d ", cq[i]);
        printf("\nRear = %d\n", rear);
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
                enque(value);
                break;

            case 2:
                deque();
                break;

            case 3:
                disp();
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
