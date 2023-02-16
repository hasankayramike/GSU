#include <stdio.h>
#include <stdlib.h>
#define LEN 1024

typedef struct node {
    int vertex;
    struct node *next;
}node;

typedef struct adjList {
    node* head;
}adjList;

typedef struct graph {
    int numVertices;
    int* visited;
    adjList* adjLists;
}graph;

typedef struct queue {
    int queue[LEN];
    int front;
    int rear;
}queue;

node* createNode(int v)
{
    node* newNode = malloc(sizeof(node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

graph* createGraph(int v)
{
    graph* newGraph = malloc(sizeof(graph));
    newGraph->numVertices = v;
    newGraph->adjLists = malloc(v * sizeof(adjList));
    newGraph->visited = malloc(v * sizeof(int));
    for (int i = 0; i < v; i++)
    {
        newGraph->adjLists[i].head = NULL;
        newGraph->visited[i] = 0;
    }
    return newGraph;
}

void addEdge(graph* g, int src, int dest)
{
    node* vertex = createNode(src);
    vertex->next = g->adjLists[dest].head;
    g->adjLists[dest].head = vertex;
    vertex = createNode(dest);
    vertex->next = g->adjLists[src].head;
    g->adjLists[src].head = vertex;
}

void printGraph(graph* g)
{
    for (int i = 0; i < g->numVertices; i++)
    {
        printf("Adjacency List of %d: ", i);
        for (node* j = g->adjLists[i].head; j != NULL; j = j->next)
        {
            printf("%d --> ", j->vertex);
        }
        printf("xxxxx\n");
    }
}

queue* createQueue(void) {
    queue* newQueue = malloc(sizeof(queue));
    newQueue->front = newQueue->rear = -1;
    return newQueue;
}

int isEmpty(queue* q)
{
    if (q->front == -1) return 1;
    return 0;
}

void enqueue(queue* q, int x)
{
    if (q->rear == LEN - 1)
    {
        printf("Queue is full!\n");
        return;
    }
    if (-1 == q->front)
    {
        q->front = 0;
    }
    q->queue[++q->rear] = x;
}

int dequeue(queue* q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty!\n");
        return -1;
    }
    int item = q->queue[q->front++];
    if (q->front > q->rear)
    {
        // printf("Resetting the queue!\n");
        q->front = q->rear = -1;
    }
    return item;
}

void printQueue(queue* q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty!\n");
        return;
    }
    for (int i = q->front; i <= q->rear; i++)
    {
        printf("%d ", q->queue[i]);
    }
}

void BFS(graph* g, int v)
{
    queue* q = createQueue();
    enqueue(q, v);
    g->visited[v] = 1;
    while (!isEmpty(q))
    {
        int current = dequeue(q);
        printf("Visited %d\n", current);
        for (node* i = g->adjLists[current].head; i != NULL; i = i->next)
        {
            if (g->visited[i->vertex] == 0)
            {
                g->visited[i->vertex] = 1;
                enqueue(q, i->vertex);
            }
        }
    }
}

int main() {
    graph* graph = createGraph(6);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 4);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    printGraph(graph);
    BFS(graph, 0);

  return 0;
}


