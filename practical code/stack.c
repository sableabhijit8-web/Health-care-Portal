// Algorithm: Queue Operations Using Array

// Step 1: Start
// Step 2: Initialize variables
//  front = -1, rear = -1, and define an array queue[SIZE]

// ENQUEUE (Insert Element)

// Step 3: To insert an element into the queue
//  • If rear == SIZE - 1, then
//   → Print “Queue Overflow!”
//  • Else
//   → If front == -1, set front = 0 (first element insertion)
//   → Increment rear by 1
//   → Insert element at queue[rear]
//   → Print “Element inserted successfully”

// DEQUEUE (Delete Element)

// Step 4: To delete an element from the queue
//  • If front == -1 or front > rear, then
//   → Print “Queue Underflow!”
//  • Else
//   → Print “Deleted element = queue[front]”
//   → Increment front by 1

// DISPLAY (Show Elements)

// Step 5: To display queue elements
//  • If front == -1 or front > rear, then
//   → Print “Queue is empty!”
//  • Else
//   → Print all elements from queue[front] to queue[rear]

// Step 6: Repeat the above operations according to user choice (1 to 4)
// Step 7: If the choice is 4, then exit the program
// Step 8: Stop

#include<stdio.h>
#define SIZE 100

int stack[SIZE];
int top = -1;

// function to push the element in stack
void push(int element){
    if(top == SIZE-1){
      printf("stack is overflow!! can't push %d \n", element);
    }
    else{
        top++;
        stack[top]= element;
        printf("%d Element push in stack/n");
    }
}
// function to pop the element form stack
void pop(){
    if(top == -1){
        printf("Stack is empty!!.\n");
    }
    else{
        printf("%d poped form stack\n: ",stack[top]);
        top--;
        }
    }
    // display function
    void Display(){
        if(top ==-1){
            printf("stack is empty:");
        }
        else{
            printf("stack elements are:");
            for(int i=top; i>=0; i--){
            printf("%d\n",stack[i]);
        }
    }
}
int main(){

    int choice, element;

    while(1){
        printf("\n...stack opration...\n");
        printf("1. push\n");
        printf("2. pop\n");
        printf("3. Display\n");                                          
        printf("4. exits\n");
        printf("enter choice: ");
        scanf("%d", &choice);
        
        switch (choice)
        {

        case 1:
        printf("enter element in stack: ");
        scanf("%d", &element);
        push(element);
        break;
        
        case 2:
        pop();
        break;

        case 3:
        Display();
        break;

        case 4:
        printf("Existing\n");
        return 0;

        default:
        printf("invalid choice try again: ");
        
        }

     }
    // push(10);
    // push(20);
    // push(30);
    // Display();     // Show stack
    // pop();
    // Display();     // Show after pop
    // push(40);
    // push(50);
    // push(60);      // This will show overflow
    // Display();
    // return 0;
}
