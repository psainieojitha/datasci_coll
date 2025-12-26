#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
int cq[SIZE];
int front=-1;
int rear=-1;
void enqueue(int val){
    if(front==(rear+1)%SIZE){
        printf("the queue if full\n");
        return;
    }
    if(front==-1&&rear==-1){
        rear=0;
        front=0;
    }else{
        rear=(rear+1)%SIZE;
    }
    cq[rear]=val;
}
void Dequeue(){
    if(front==-1&&rear==-1){
        printf("the queeu empty");
    }
    int ele=cq[front];
    if(front==rear){
        front=-1;
        rear=-1;
    }else{
        cq[front++];
    }
}
void diaplay(){
    int b=rear;
    int a=front;
    while(a!=(b+1)){
        printf("%d\t",cq[a]);
        a=(a+1)%SIZE;
    }
    printf("\n");
}
int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    diaplay();
    Dequeue();
    diaplay();
}
