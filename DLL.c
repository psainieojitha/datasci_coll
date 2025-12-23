#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *lptr;
    struct node *rptr;
};

struct node *head = NULL;

/* Insert at front */
void insertfront(int val) {
    struct node *new_node = malloc(sizeof(struct node));

    new_node->data = val;
    new_node->lptr = NULL;
    new_node->rptr = head;

    if (head != NULL) {
        head->lptr = new_node;
    }

    head = new_node;
}

/* Insert at rear */
void insertrear(int val) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = val;
    new_node->rptr = NULL;

    if (head == NULL) {
        new_node->lptr = NULL;
        head = new_node;
        return;
    }

    struct node *temp = head;
    while (temp->rptr != NULL) {
        temp = temp->rptr;
    }

    temp->rptr = new_node;
    new_node->lptr = temp;
}

/* Display list */
void display() {
    struct node *temp = head;
    printf("DLL: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->rptr;
    }
    printf("NULL\n");
}

int main() {
    insertfront(3);
    insertfront(4);
    insertfront(5);
    display();

    insertrear(9);
    insertrear(0);
    display();

    return 0;
}
