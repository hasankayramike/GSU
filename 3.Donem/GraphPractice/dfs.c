// #include <stdio.h>
// #include <stdlib.h>

// typedef struct node {
//     int vertex;
//     struct node *next;
// }node;

// typedef struct adjList {
//     node* head;
// }adjList;

// typedef struct graph {
//     int numVertices;
//     int* visited;
//     adjList* adjLists;
// }graph;

// node* createNode(int v)
// {
//     node* newNode = malloc(sizeof(node));
//     newNode->vertex = v;
//     newNode->next = NULL;
//     return newNode;
// }

// graph* createGraph(int v)
// {
//     graph* newGraph = malloc(sizeof(graph));
//     newGraph->numVertices = v;
//     newGraph->adjLists = malloc(v * sizeof(adjList));
//     newGraph->visited = malloc(v * sizeof(int));
//     for (int i = 0; i < v; i++)
//     {
//         newGraph->adjLists[i].head = NULL;
//         newGraph->visited[i] = 0;
//     }
//     return newGraph;
// }

// void addEdge(graph* g, int src, int dest)
// {
//     node* vertex = createNode(src);
//     vertex->next = g->adjLists[dest].head;
//     g->adjLists[dest].head = vertex;
//     vertex = createNode(dest);
//     vertex->next = g->adjLists[src].head;
//     g->adjLists[src].head = vertex; 
// }

// void printGraph(graph* g)
// {
//     for (int i = 0; i < g->numVertices; i++)
//     {
//         printf("Adjacency List of vertex %d :", i);
//         for (node* j = g->adjLists[i].head; j != NULL; j = j->next)
//         {
//             printf("%d --> ", j->vertex);
//         }
//         printf("xxxxx\n");        
//     }
// }

// void DFS(graph* g, int v)
// {
//     g->visited[v] = 1;
//     printf("Visited %d\n", v);
//     for (node* i = g->adjLists[v].head; i != NULL;)
//     {
//         int connected = i->vertex;
//         if (g->visited[connected] == 0) DFS(g, connected); 
//         i = i->next;
//     }
// }

// int main() {
//     graph* graph = createGraph(4);
//     addEdge(graph, 0, 1);
//     addEdge(graph, 0, 2);
//     addEdge(graph, 0, 3);
//     addEdge(graph, 1, 2);
//     addEdge(graph, 2, 4); 
//     printGraph(graph);
//     DFS(graph, 0);
//     return 0;
// }



#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

struct Vertex {
   char label;
   bool visited;
};

//stack variables

int stack[MAX]; 
int top = -1; 

//graph variables

//array of vertices
struct Vertex* lstVertices[MAX];

//adjacency matrix
int adjMatrix[MAX][MAX];

//vertex count
int vertexCount = 0;

//stack functions

void push(int item) { 
   stack[++top] = item; 
} 

int pop() { 
   return stack[top--]; 
} 

int peek() {
   return stack[top];
}

bool isStackEmpty() {
   return top == -1;
}

//graph functions

//add vertex to the vertex list
void addVertex(char label) {
   struct Vertex* vertex = (struct Vertex*) malloc(sizeof(struct Vertex));
   vertex->label = label;  
   vertex->visited = false;     
   lstVertices[vertexCount++] = vertex;
}

//add edge to edge array
void addEdge(int start,int end) {
   adjMatrix[start][end] = 1;
   adjMatrix[end][start] = 1;
}

//display the vertex
void displayVertex(int vertexIndex) {
   printf("%c ",lstVertices[vertexIndex]->label);
}       

//get the adjacent unvisited vertex
int getAdjUnvisitedVertex(int vertexIndex) {
   int i;

   for(i = 0; i < vertexCount; i++) {
      if(adjMatrix[vertexIndex][i] == 1 && lstVertices[i]->visited == false) {
         return i;
      }
   }

   return -1;
}

void depthFirstSearch() {
   int i;

   //mark first node as visited
   lstVertices[0]->visited = true;

   //display the vertex
   displayVertex(0);   

   //push vertex index in stack
   push(0);

   while(!isStackEmpty()) {
      //get the unvisited vertex of vertex which is at top of the stack
      int unvisitedVertex = getAdjUnvisitedVertex(peek());

      //no adjacent vertex found
      if(unvisitedVertex == -1) {
         pop();
      } else {
         lstVertices[unvisitedVertex]->visited = true;
         displayVertex(unvisitedVertex);
         push(unvisitedVertex);
      }
   }

   //stack is empty, search is complete, reset the visited flag        
   for(i = 0;i < vertexCount;i++) {
      lstVertices[i]->visited = false;
   }        
}

int main() {
   int i, j;

   for(i = 0; i < MAX; i++)    // set adjacency {
      for(j = 0; j < MAX; j++) // matrix to 0
         adjMatrix[i][j] = 0;
   }

   addVertex('S');   // 0
   addVertex('A');   // 1
   addVertex('B');   // 2
   addVertex('C');   // 3
   addVertex('D');   // 4

   addEdge(0, 1);    // S - A
   addEdge(0, 2);    // S - B
   addEdge(0, 3);    // S - C
   addEdge(1, 4);    // A - D
   addEdge(2, 4);    // B - D
   addEdge(3, 4);    // C - D

   printf("Depth First Search: ")
   depthFirstSearch(); 

   return 0;   
}