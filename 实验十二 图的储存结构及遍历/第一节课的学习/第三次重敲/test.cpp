#include"MatGraph.h"
void CreateMatGraph(MatGraph*& G, int A[MAXV][MAXV], int n, int e)
{
	G = (MatGraph*)malloc(sizeof(MatGraph));
	G->n = n;
	G->e = e;
	int i = 0;
	int j = 0;
	for (i = 0; i < G->n; i++)
	{
		for (j = 0; j < G->n; j++)
		{
			G->Edges[i][j] = A[i][j];
		}

	}
}

void DispGraph(MatGraph* G)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < G->n; i++)
	{
		for (j = 0; j < G->n; j++)
		{
			if (G->Edges[i][j] == INF)
			{
				printf("%4s", "¡Þ");
			}
			else
			{
				printf("%4d", G->Edges[i][j]);
			}
		}
		printf("\n");
	}
}

int visited[MAXV] = { 0 };
void DFS(MatGraph* G, int u)
{
	int i = 0;
	printf("%d", u);
	visited[u] = 1;
	for (i = 0; i < G->n; i++)
	{
		if (G->Edges[u][i] != 0 && G->Edges[u][i] != INF && visited[i] != 1)
		{
			DFS(G, i);
		}
	}
}

void DFSTraverse(MatGraph* G)
{
	int i = 0;
	for (i = 0; i < G->n; i++)
	{
		if (visited[i] != 1)
		{
			DFS(G, i);
		}
	}
	printf("\n");
}

int visited1[MAXV] = { 0 };
void BFS(MatGraph* G, int u)
{
	int w = 0;
	int Queue[MAXV];
	int front = 0;
	int rear = 0;
	printf("%d", u);
	rear = (rear + 1) % MAXV;
	Queue[rear] = u;
	visited1[u] = 1;
	int i = 0;
	while (front != rear)
	{
		front = (front + 1) % MAXV;
		w = Queue[front];
		for (i = 0; i < G->n; i++)
		{
			if (G->Edges[w][i] != INF && G->Edges[w][i] != 0 && visited1[i] != 1)
			{
				printf("%d", i);
				visited1[i] = 1;
				rear = (rear + 1) % MAXV;
				Queue[rear] = i;
			}
		}
	}
}

void BFSTraverse(MatGraph* G)
{
	int i = 0;
	for (i = 0; i < G->n; i++)
	{
		if (visited1[i] != 1)
		{
			BFS(G, i);
		}
	}
	printf("\n");
}