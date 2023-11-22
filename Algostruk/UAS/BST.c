#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *left, *right;
} Node;

Node *newNode(int key)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->value = key;
    temp->left = temp->right = NULL;
    return temp;
}

int *insertNode(Node *node, int key)
{
    if (node == NULL)
        return newNode(key);
    else if (key < node->value)
        node->left = insertNode(node->left, key);
    else if (key > node->value)
        node->right = insertNode(node->right, key);
    return node;
}

void inorder(Node *node)
{
    if (node != NULL)
    {
        inorder(node->left);
        printf("%d ", node->value);
        inorder(node->right);
    }
}

void postorder(Node *node)
{
    if (node != NULL)
    {
        postorder(node->left);
        postorder(node->right);
        printf("%d ", node->value);
    }
}

void preorder(Node *node)
{
    if (node != NULL)
    {
        printf("%d ", node->value);
        preorder(node->left);
        preorder(node->right);
    }
}

Node *minValueNode(Node *node)
{
    Node *current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

Node *deleteNode(Node *node, int key)
{
    if (node == NULL)
        return node;
    else if (key < node->value)
        node->left = deleteNode(node->left, key);
    else if (key > node->right)
        node->right = deleteNode(node->right, key);
    else
    {
        if (node->left == NULL)
        {
            Node *temp = node->right;
            free(node);
            return temp;
        }
        else if (node->right == NULL)
        {
            Node *temp = node;
            free(node);
            return temp;
        }
        Node *temp = minValueNode(node->right);
        node->value = temp->value;
        node->right = deleteNode(node->right, temp->value);
    }
}

int main()
{
    Node *root = NULL;
    root = insertNode(root, 50);

    insertNode(root, 40);
}