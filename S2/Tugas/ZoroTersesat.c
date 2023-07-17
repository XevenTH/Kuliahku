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

void PrintHimbauan(Graph *graph, int maxSimpang)
{
    printf("Persimpangan yang harus dihindari oleh Roronoa Zoro adalah:\n");
    int len = graph->numVertices;
    int LinkedCount[len];
    for (int i = 0; i < len; ++i)
    {
        Vertex *temp = graph->adjList[i];
        LinkedCount[i] = 0;
        while (temp)
        {
            LinkedCount[i]++;
            temp = temp->next;
        }
        if (LinkedCount[i] > maxSimpang)
            printf("Persimpangan %d\n", i);
    }
}

int main()
{
    int vertices, umur, src, dest;
    printf("Masukan Jumlah Persimpangan: ");
    scanf("%d", &vertices);

    Graph *graph = CreateGraph(vertices);
    printf("Masukan Umur Zoro: ");
    scanf("%d", &umur);

    do
    {
        scanf("%d %d", &src, &dest);
        AddEdge(graph, src, dest);
    } while (src > -1 && dest > -1);

    PrintHimbauan(graph, umur);

    return 0;
}
