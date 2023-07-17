#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

// Struktur graph
typedef struct
{
	int edges[MAX_VERTICES][MAX_VERTICES];
	int numVertices;
} Graph;

// Inisialisasi graph
void CreateGraph(Graph *graph, int numVertices)
{
	graph->numVertices = numVertices;

	for (int i = 0; i < numVertices; i++)
	{
		for (int j = 0; j < numVertices; j++)
		{
			graph->edges[i][j] = -1;
		}
	}
}

// Tambahkan edge ke graph
void AddEdge(Graph *graph, int start, int end)
{
	graph->edges[start][end] = 1;
}

// DFS traversal
void Dfs(Graph *graph, int currentVertex, int visited[], int *stack, int *stackIdx)
{
	visited[currentVertex] = 1;

	for (int i = 0; i < graph->numVertices; i++)
	{
		if (graph->edges[currentVertex][i] == 1 && visited[i] == 0)
		{
			Dfs(graph, i, visited, stack, stackIdx);
		}
	}

	// Push vertex ke stack setelah selesai traversal pada vertex tersebut
	stack[++(*stackIdx)] = currentVertex;
}

// Topological sort menggunakan DFS dan stack
void TopologicalSort(Graph *graph)
{
	int visited[MAX_VERTICES] = {0};
	int stack[MAX_VERTICES];
	int stackIdx = -1;

	for (int i = 0; i < graph->numVertices; i++)
	{
		if (visited[i] == 0) Dfs(graph, i, visited, stack, &stackIdx);
	}

	// Print hasil topological sort
	printf("\nHasil Topological Sort: ");
	while (stackIdx >= 0)
	{
		printf("%d ", stack[stackIdx--]);
	}
	printf("\n\n");
}

void PrintGraph(Graph *graph)
{
	for (int i = 0; i < graph->numVertices; i++)
	{
		for (int j = 0; j < graph->numVertices; j++)
		{
			if (graph->edges[i][j] == -1)
			{
				printf("0 ");
			}
			else
			{
				printf("1 ");
			}
		}

		printf("\n");
	}
}

int main()
{
	// Buat graph contoh
	Graph graph;
	int numVertices = 8;
	CreateGraph(&graph, numVertices);

	// Tambahkan edge
	AddEdge(&graph, 0, 2);
	AddEdge(&graph, 0, 3);
	AddEdge(&graph, 1, 3);
	AddEdge(&graph, 1, 4);
	AddEdge(&graph, 2, 5);
	AddEdge(&graph, 3, 5);
	AddEdge(&graph, 3, 6);
	AddEdge(&graph, 4, 6);
	AddEdge(&graph, 5, 7);
	AddEdge(&graph, 6, 7);

	printf("\n");
	PrintGraph(&graph);
	// Lakukan topological sort
	TopologicalSort(&graph);

	return 0;
}
