#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node {
    char data;
    struct node *left;
    struct node *right;
};

struct node *create(char data) {
    struct node *p;
    p = (struct node *) malloc(sizeof(struct node));
    p->data = data;
    p->left = p->right = NULL;
    return p;
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int evaluate(struct node *r) {
    int leftval, rightval;

    if (r == NULL)
        return 0;

    if (r->left == NULL && r->right == NULL)
        return (r->data - '0');

    leftval = evaluate(r->left);
    rightval = evaluate(r->right);

    switch (r->data) {
        case '+': return leftval + rightval;
        case '-': return leftval - rightval;
        case '*': return leftval * rightval;
        case '/': return leftval / rightval;
    }
    return 0;
}

void inorder(struct node *r) {
    if (r != NULL) {
        if (isOperator(r->data))
            printf("(");
        inorder(r->left);
        printf("%c", r->data);
        inorder(r->right);
        if (isOperator(r->data))
            printf(")");
    }
}

int main() {
    struct node *r, *p;

    r = create('*');
    r->left = create('+');
    r->right = create('-');

    p = r->left;
    p->left = create('3');
    p->right = create('2');

    p = r->right;
    p->left = create('4');
    p->right = create('2');

    printf("Inorder Expression: ");
    inorder(r);

    int result = evaluate(r);
    printf("\nEvaluated Result: %d\n", result);

    return 0;
}