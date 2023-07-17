#include <stdio.h>
#include <stdlib.h>

typedef struct vertex
{
    int dest;
    struct vertex *next;
} Vertex;

typedef struct graph
{
    int numVertices;
    int required;
    Vertex **adjList;
} Graph;

Vertex *CreateVertex(int dest)
{
    Vertex *newNode = (Vertex *)malloc(sizeof(Vertex));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

Graph *CreateGraph(int numVertices)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = numVertices;

    // Create an array of adjacency lists
    graph->adjList = (Vertex **)malloc(numVertices * sizeof(Vertex *));

    // Initialize each adjacency list as empty
    for (int i = 0; i < numVertices; ++i)
    {
        graph->adjList[i] = NULL;
    }

    return graph;
}

void AddEdge(Graph *graph, int src, int dest)
{
    Vertex *newVertex = CreateVertex(dest);
    newVertex->next = graph->adjList[src];
    graph->adjList[src] = newVertex;

    newVertex = CreateVertex(src);
    newVertex->next = graph->adjList[dest];
    graph->adjList[dest] = newVertex;
}

void PrintGraph(Graph *graph)
{
    int min = graph->required, tempVertex = -1;

    for (int v = 0; v < graph->numVertices; ++v)
    {
        Vertex *temp = graph->adjList[v];
        printf("Adjacency list of vertex %d\n", v);
        int counter = 0;
        while (temp)
        {
            counter++;
            printf("%d -> ", temp->dest);
            temp = temp->next;
        }
        if (counter < min)
        {
            min = counter;
            tempVertex = v;
        }
        printf("NULL\n");
    }

    if (tempVertex != -1)
    {
        printf("\nVertex %d adalah wibu nolep\n", tempVertex);
    }
    else
    {
        printf("\nTidak Ada Yang Nolep\n", tempVertex);
        
    }
}

int main()
{
    // Membuat graph dengan 5 vertex
    Graph *graph = CreateGraph(5);
    graph->required = 3;

    // Menambahkan edge
    AddEdge(graph, 0, 1);
    AddEdge(graph, 0, 4);
    AddEdge(graph, 1, 2);
    AddEdge(graph, 1, 3);
    AddEdge(graph, 1, 4);
    AddEdge(graph, 2, 3);
    AddEdge(graph, 2, 4);
    AddEdge(graph, 3, 4);

    PrintGraph(graph);

    return 0;
}
