#include <stdio.h>
#include <stdlib.h>

/* Node structure */
struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

/* Insert at front */
void insertfront(int val) {
    struct node *new_node = malloc(sizeof(struct node));

    new_node->data = val;
    new_node->next = head;
    head = new_node;
}

/* Insert at rear */
void insertrear(int val) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = val;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        return;
    }

    struct node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = new_node;
}

/* Insert at specific position (1-based index) */
void insertatpos(int val, int pos) {
    if (pos == 1) {
        insertfront(val);
        return;
    }

    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = val;

    struct node *temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range!\n");
        free(new_node);
        return;
    }

    new_node->next = temp->next;
    temp->next = new_node;
}

/* Display list */
void display() {
    struct node *temp = head;
    printf("Singly Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    insertfront(10);
    insertfront(20);
    insertfront(30);

    insertrear(40);
    insertrear(50);

    insertatpos(25, 3);

    display();

    return 0;
}
