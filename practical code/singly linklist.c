#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head = malloc(sizeof(struct node));
    struct node *second = malloc(sizeof(struct node));
    struct node *third = malloc(sizeof(struct node));
    
    // assign data to each node
    head->data = 10;
    second->data = 20;
    third->data = 10;

    // link the node together
    head->next = second;
    second->next = third;
    third->next = NULL;

    // display the lined list
    struct  node *temp = head;
    printf("Linked list element: ");
    while(temp != NULL){
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    // free allocated memory
    free(head);
    free(second);
    free(third);

    return 0;
    
}
