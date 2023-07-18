#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int item;
    struct node *left;
    struct node *right;
} Node;

Node *Create(int val)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->item = val;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

Node *Left(Node *root, int val)
{
    root->left = Create(val);
    return root->left;
}

Node *Right(Node *root, int val)
{
    root->right = Create(val);
    return root->right;
}

void TravPreOrder(Node *root)
{
    if (root == NULL)
        return;

    printf("%d -> ", root->item);
    TravPreOrder(root->left);
    TravPreOrder(root->right);
}

void TravInOrder(Node *root)
{
    if(root == NULL) return;

    TravInOrder(root->left);
    printf("%d -> ", root->item);
    TravInOrder(root->right);
}

void TravPostOrder(Node *root)
{
    if(root == NULL) return;

    TravPostOrder(root->left);
    TravPostOrder(root->right);
    printf("%d -> ", root->item);
}

int main()
{
    Node *root = Create(1);
    Left(root, 2);
    Right(root, 3);

    Left(root->left, 4);
    Right(root->left, 5);

    printf("Pre-Order Traversal: ");
    TravPreOrder(root);
    printf("\n");

    printf("In-Order Traversal: ");
    TravInOrder(root);
    printf("\n");
    
    printf("Post-Order Traversal: ");
    TravPostOrder(root);

    return 0;
}
