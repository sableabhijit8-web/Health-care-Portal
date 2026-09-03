// Algorithm: Inorder Traversal of Binary Tree

// 1Start

// 2Define a structure node having three members:

// data (integer)

// left (pointer to left child)

// right (pointer to right child)

// 3Create a function createNode(value)

// Allocate memory for a new node.

// Set node->data = value.

// Set node->left = NULL and node->right = NULL.

// Return the new node.

// Create a function inOrder(root)

// If root is NULL, return.

// Recursively call inOrder(root->left).

// Print root->data.

// Recursively call inOrder(root->right).

// In main() function:

// Create the root and child nodes using createNode().

// Connect them to form the binary tree.

// Call inOrder(root) to print the nodes in inorder.

// Stop

#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *left;
  struct node *right;
};

// function to create a new node
struct node* createNOde(int value){
   struct  node* newNode = (struct  node*)malloc(sizeof(struct node));
   newNode->data =  value;
   newNode->left = NULL;
   newNode->right = NULL;
   return newNode;

}

//inorder traversal
void inOrder(struct node* root){
    if(root == NULL){
    return;
}
inOrder(root->left);
printf("%d", root->data);
inOrder(root->right);
}
int main(){
    // create newnode
    struct node *root = createNOde(5);
    root->left = createNOde(2);
    root->right = createNOde(6);
    root->left->left = createNOde(1);
    root->right->right = createNOde(9);

    printf("Inorder traversal of tree: ");
    inOrder(root);
    printf("\n");

    return 0;
    
    
}
