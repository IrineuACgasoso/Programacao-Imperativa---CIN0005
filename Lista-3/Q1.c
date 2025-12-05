#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));

    if (newNode != NULL)
    {
        newNode->data = value;
        newNode->left =NULL;
        newNode->right = NULL;
    }
    return newNode;
}

Node* insert(Node* root, int value) {
    if (root == NULL)
    {
        return createNode(value);
    }

    if (value > root->data)
    {
        root->right = insert(root->right, value);
    }
    else if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    
    return root; 
}

void inOrder(Node* root) {
    if (root == NULL)
    {
        return;
    }
    
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

void preOrder(Node* root) {
    if (root == NULL)
    {
        return;
    }

    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void posOrder(Node* root) {
    if (root == NULL)
    {
        return;
    }

    posOrder(root->left);
    posOrder(root->right);
    printf("%d ", root->data);
}

void freeNode(Node* root) {
    freeNode(root->left);
    freeNode(root->right);
    free(root);
}


int main() {
    Node* root = NULL;
    int numb_values, value;

    scanf("%d", &numb_values);
    for (int i = 0; i < numb_values; i++)
    {
        scanf("%d", &value);
        root = insert(root, value);
    }
    
    //Pre
    printf("Pre order  : ");
    preOrder(root);
    printf("\n");
    //In
    printf("In order    : ");
    inOrder(root);
    printf("\n");
    //Pos
    printf("Post order: ");
    posOrder(root);
    printf("\n");

    return 0;
}