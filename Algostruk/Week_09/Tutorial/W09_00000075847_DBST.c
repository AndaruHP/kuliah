#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int key;
    struct Node *left, *right;
} Node;

Node *newNode(int item)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

Node *insert(Node *node, int key)
{
    if (node == NULL)
    {
        return newNode(key);
    }
    if (key < node->key)
    {
        node->left = insert(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = insert(node->right, key);
    }

    return node;
}

void inorder(Node *node)
{
    if (node != NULL)
    {
        inorder(node->left);
        printf("%d ", node->key);
        inorder(node->right);
    }
}

void preorder(Node *node)
{
    if (node != NULL)
    {
        printf("%d ", node->key);
        preorder(node->left);
        preorder(node->right);
    }
}

void postorder(Node *node)
{
    if (node != NULL)
    {
        postorder(node->left);
        postorder(node->right);
        printf("%d ", node->key);
    }
}

int main()
{
    Node *root = NULL;

    root = insert(root, 50);

    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Base Tree\n");
    printf("\nPreorder\t: ");
    preorder(root);
    printf("\nInorder\t: ");
    inorder(root);
    printf("\nPostorder\t: ");
    postorder(root);

    printf("Deleting node 20\n");
    deteleNode(root, 20);

    printf("\nPreorder\t: ");
    preorder(root);
    printf("\nInorder\t: ");
    inorder(root);
    printf("\nPostorder\t: ");
    postorder(root);

    printf("Deleting node 30\n");
    deteleNode(root, 30);

    printf("\nPreorder\t: ");
    preorder(root);
    printf("\nInorder\t: ");
    inorder(root);
    printf("\nPostorder\t: ");
    postorder(root);

    printf("Deleting node 70\n");
    deteleNode(root, 70);

    return 0;
}

Node *minValueNode(Node *node)
{
    Node *current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

Node *deteleNode(Node *root, int key)
{
    if (root == NULL)
    {
        return root;
    }

    if (key < root->key)
    {
        root->left = deteleNode(root->left, key);
    }
    else if (key > root->key)
    {
        root->right = deteleNode(root->right, key);
    }
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        Node *temp = minValeuNode(root->right);
        root->key = temp->key;
        root->right = deteleNode(root->right, temp->key);
    }
    return root;
}