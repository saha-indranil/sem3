// Write a C program to implement Graph using Adjacency List along with the following function:
// a. To count number of vertices and edges present in a graph.
// b. To find the adjacent vertices of a given vertex.
// c. To search a node in a given graph.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int vertex;
    struct node *next;
};

struct Graph
{
    int numVertices;
    bool *visited;
    struct node **adjLists;
};

struct node *createNode(int);
struct Graph *createAGraph(int);
void addEdge(struct Graph *, int, int);
void printGraph(struct Graph *);
void DFS(struct Graph *, int);

int main()
{
    int n, m, u, v, i;
    printf("Enter Number of Vertices: ");
    scanf("%d", &n);
    printf("Enter Number of Edges: ");
    scanf("%d", &m);

    struct Graph *graph = createAGraph(n);
    for (i = 0; i < m; i++)
    {
        printf("Add Edge Between: ");
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    printGraph(graph);

    for (i = 0; i < n; i++)
    {
        if (graph->visited[i] != true)
        {
            DFS(graph, i);
        }
    }

    printf("Enter a Item to search: ");
    scanf("%d", &i);
    if (graph->visited[i] != true)
        printf("%d is not present in the graph", i);
    else
        printf("%d is present in the graph", i);

    return 0;
}

struct node *createNode(int v)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph *createAGraph(int vertices)
{
    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(struct node *));
    graph->visited = malloc(vertices * sizeof(bool));

    int i;
    for (i = 0; i < vertices; i++)
    {
        graph->adjLists[i] = NULL;
        graph->visited[i] = false;
    }

    return graph;
}

void addEdge(struct Graph *graph, int u, int v)
{
    struct node *newNode = createNode(v);
    newNode->next = graph->adjLists[u];
    graph->adjLists[u] = newNode;

    newNode = createNode(u);
    newNode->next = graph->adjLists[v];
    graph->adjLists[v] = newNode;
}

void printGraph(struct Graph *graph)
{
    int v;
    for (v = 0; v < graph->numVertices; v++)
    {
        struct node *temp = graph->adjLists[v];
        printf("Vertex %d", v);
        while (temp)
        {
            printf(" -> %d", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

void DFS(struct Graph *graph, int vertex)
{
    struct node *adjList = graph->adjLists[vertex];
    struct node *temp = adjList;

    graph->visited[vertex] = true;
    while (temp != NULL)
    {
        int connectedVertex = temp->vertex;

        if (graph->visited[connectedVertex] == 0)
        {
            DFS(graph, connectedVertex);
        }
        temp = temp->next;
    }
}

/*

    0-----1
   /  \   |      6
  3    \  |    /  \
  |     \ |   7----5
  4 ---- 2

*/

// OUTPUT

// Enter Number of Vertices: 8
// Enter Number of Edges: 9
// Add Edge Between: 0 1
// Add Edge Between: 0 2
// Add Edge Between: 0 3
// Add Edge Between: 1 2
// Add Edge Between: 2 4
// Add Edge Between: 3 4
// Add Edge Between: 5 6
// Add Edge Between: 5 7
// Add Edge Between: 6 7
// Vertex 0 -> 3 -> 2 -> 1
// Vertex 1 -> 2 -> 0
// Vertex 2 -> 4 -> 1 -> 0
// Vertex 3 -> 4 -> 0
// Vertex 4 -> 3 -> 2
// Vertex 5 -> 7 -> 6
// Vertex 6 -> 7 -> 5
// Vertex 7 -> 6 -> 5
// Enter a Item to search: 6
// 6 is present in the graph