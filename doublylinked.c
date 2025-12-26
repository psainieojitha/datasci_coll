#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* rptr;
    struct Node* lptr;
};
struct Node* head=NULL;

void insert(int val){
    struct Node* newnode=(struct Node*) malloc(sizeof(struct Node));
    newnode->data=val;
    if(head==NULL){
        head=newnode;
        newnode->rptr=NULL;
        newnode->lptr=NULL;
    }
    else{
        newnode->lptr=NULL;
        newnode->rptr=head;
        head->lptr=newnode;
        head=newnode;
    }   
}
void insert_end(int val){
    struct Node* newnode=(struct Node*) malloc(sizeof(struct Node));
    struct Node* temp=(struct Node*) malloc(sizeof(struct Node));
    newnode->data=val;
    if(head==NULL){
        insert(val);
    }
    else{
        temp=head;
        while(temp->rptr!=NULL){
            temp=temp->rptr;

        }
        temp->rptr=newnode;
        newnode->rptr=NULL;
        newnode->lptr=temp;
    }
}
void insertatpos(int val,int pos){
    struct Node* newnode=(struct Node*) malloc(sizeof(struct Node));
    struct Node* temp;
    struct Node* curr;
    newnode->data=val;
    if(head==NULL){
        insert(val);
    }
    else{
        temp=head;
        if(pos==0){
            insert(val);
        }
        for(int i=1;i<=pos;i++){
            curr=temp;
            temp=temp->rptr;
        }
        curr->rptr=newnode;
        newnode->lptr=curr;
        newnode->rptr=temp;
        temp->lptr=newnode;
    }
}
void delval(int val){
    struct Node* curr=head;
    struct Node* prev=NULL;
    while(curr->rptr!=NULL&&curr->data!=val){
        prev=curr;
        curr=curr->rptr;
    }
    prev->rptr=curr->rptr;
    curr->rptr->lptr=prev;
    free(curr);
}
void display(){
    struct Node* temp = head;
    while(temp != NULL){
        printf("%d <-> ", temp->data);
        temp = temp->rptr;
    }
    printf("NULL\n");
}
int main(){
    insert_end(10);
    insert_end(20);
    insert_end(30);
    display();
    insertatpos(15,1);
    display();
    delval(20);
    display();
    return 0;   
}
