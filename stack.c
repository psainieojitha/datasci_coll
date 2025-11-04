#include <stdio.h>
#include <conio.h>
#define size 10
void push(int item);
void pop();
void display();
int stack[size], top=-1;
void main(){
    int value,choice;
    while(1){
        printf("\n MENU \n");
        printf("\n 1.PUSH \n 2.POP \n 3.DISPLAY \n 4.EXIT");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("ENTER THE ELEMENT TO PUSH\n");
                scanf("%d",&value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:exit(0);
            default : printf("\n invalid input \n");

        }
    }
}
void push(value){
    if(top==size-1){
        printf("stack is full\n");
    }
    else{
        top++;
        stack[top]=value;
    }
}
void pop(){
    if(top==-1){
        printf("empty stack\n");
    }
    else{
        printf("the element del is %d\n",stack[top]);
        top--;
    }
}
void display(){
    if(top==-1){
        printf("empty stack\n");
    }
    else{
        printf("the element is\n");
        for(int i=top;i>=0;i--){
            printf("%d",stack[i]);
            printf(" \n");
        }
    }
}
