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

#include <stdio.h>
#define SIZE 100

int queue[SIZE];
int front = -1;
int rear = -1;

// enqueue (insert element in queue)
void enqueue(int value) {
    if (rear == SIZE - 1) {
        printf("Queue Overflow! Cannot insert %d\n", value);
    } else {
        if (front == -1) {
            front = 0; // first element being inserted
        }
        rear++;
        queue[rear] = value;
        printf("%d inserted into the queue.\n", value);
    }
}

// dequeue (delete element from queue)
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow! Cannot delete.\n");
    } else {
        printf("%d deleted from the queue.\n", queue[front]);
        front++;
    }
}

// display (show elements)
void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements are:\n");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- QUEUE OPERATIONS ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
