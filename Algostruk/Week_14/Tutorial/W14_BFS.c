#include <stdio.h>
#include <stdlib.h>

typedef struct Edge
{
    int dest;
    struct Edge *next;
} Edge;

typedef struct Queue
{
    int data;
    struct Queue *next;
} Queue;

void addEdge(Edge *adjList[], int src, int dest)
{
    Edge *temp;
    temp = (Edge *)malloc(sizeof(Edge));
    temp->dest = dest;
    temp->next = NULL;

    if (adjList[src] == NULL)
        adjList[src] = temp;
    else
    {
        Edge *p = adjList[src];
        while (p->next != NULL)
            p = p->next;
        p->next = temp;
    }
}

int isEmpty(Queue *queue)
{
    if (queue == NULL)
        return 1;
    else
        return 0;
}

void enqueue(Queue **queue, int start)
{
    Queue *data = (Queue *)malloc(sizeof(Queue));
    data->data = start;
    data->next = NULL;

    if (isEmpty(*queue))
    {
        *queue = data;
    }
    else
    {
        Queue *temp = *queue;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = data;
    }
}

int dequeue(Queue **queue)
{
    if (isEmpty(*queue))
        return;
    else
    {
        Queue *trash = *queue;
        int data = trash->data;
        *queue = trash->next;
        free(trash);
    }
}

int front(Queue *queue)
{
    if (queue == NULL)
        return 0;
    return queue->data;
}

void BFS(int start, int visited[], Edge *adjList[])
{
    Queue *queue = NULL;

    visited[start] = 1;
    enqueue(&queue, start);

    while (isEmpty(queue))
    {
        int v = front(queue);
        printf("%d ", v);
        dequeue(&queue);

        Edge *it;
        for (it = adjList[v]; it != NULL; it = it->next)
        {
            if (visited[it->dest] == 0)
            {
                visited[it->dest] = 1;
                enqueue(&queue, it->dest);
            }
        }
    }
}

int main()
{
    int i, src, dest, start, V;

    printf("Jumlah vertex  = ");
    scanf("%d", &V);
    Edge *adjList[V];

    for (i = 0; i < V; i++)
    {
        adjList[i] = NULL;
    }

    i = 0;
    while (1)
    {
        printf("Adjacency List %d\n", ++i);
        printf("Source = ");
        scanf("%d", &src);
        printf("Destination = ");
        scanf("%d", &dest);
        printf("\n");

        if (src <= -1 || dest <= -1)
            break;
        else
        {
            addEdge(adjList, src, dest);
            addEdge(adjList, dest, src);
        }
    }

    int visited[V + 2];
    for (i = 0; i < V + 2; i++)
    {
        visited[i] = 0;
    }

    printf("Starting node = ");
    scanf("%d", &start);
    BFS(start, visited, adjList);
}