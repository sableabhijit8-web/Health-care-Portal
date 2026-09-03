#include<stdio.h>

#define SIZE 100

int stack[SIZE];
int top = -1;
 void push(int element){
    if(top == SIZE-1){
        printf("syack is overflow!!", element);
    }
    else{
        printf("stack element:5d\n ");
        top++;
        stack[top] = element;
        printf("elementy pushed in stack %d\n");
        
    }
 }
 void pop(){
    if(top == -1){
        printf("stack is empty");
    }
    else{
        printf("poped form stack %d\n",stack[top]);
        top--;
    }
 }
 display(){
    if(top == -1){
        printf("stack is empty!!");
    }
    printf("stack element are: %d\n ");
    for(int i= top; i>=0; i--){
    printf("%d\n",stack[i]);
    }
 }
int main(){
push(10);
push(20);
push(30);
pop(10);
display();

return 0;
}