#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    struct node *parent;
    struct node *child;
    struct node *left;
    struct node *right;
    int key;
} node;

void insertion(node **mini, int val)
{
    struct node *new_node = (node *)malloc(sizeof(node));
    new_node->key = val;
    new_node->parent = NULL;
    new_node->child = NULL;
    new_node->left = new_node;
    new_node->right = new_node;
    if ((*mini) != NULL)
    {
        ((*mini)->left)->right = new_node;
        new_node->right = *mini;
        new_node->left = (*mini)->left;
        (*mini)->left = new_node;
        if (new_node->key < (*mini)->key)
        {
            (*mini) = new_node;
        }
    }
    else
    {
        (*mini) = new_node;
    }
}

void display(node *mini, int no_of_nodes)
{
    node *ptr = mini;
    if (ptr == NULL)
        printf("The Heap is Empty\n");
    else
    {
        printf("The root nodes od Heap are: \n");
        do
        {
            printf("%d", ptr->key);
            ptr = ptr->right;
            if (ptr != mini)
            {
                printf("-->");
            }
        } while (ptr != mini && ptr->right != NULL);
        printf("\nThe heap has %d nodes\n", no_of_nodes);
    }
}

void find_min(node *mini)
{
    printf("min of heap is %d\n", mini->key);
}

int main()
{
    node *mini = NULL;

    int no_of_nodes = 0;
    no_of_nodes = 7;
    insertion(&mini, 4);
    insertion(&mini, 3);
    insertion(&mini, 7);
    insertion(&mini, 5);
    insertion(&mini, 2);
    insertion(&mini, 1);
    insertion(&mini, 10);

    display(mini, no_of_nodes);

    find_min(mini);
}