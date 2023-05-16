#include"MatGraph.h"
void CreateGraph(MatGraph*& G, int A[MAXV][MAXV], int n, int e)
{
	G = (MatGraph*)malloc(sizeof(MatGraph));
	int i = 0;
	int j = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			G->edges[i][j] = A[i][j];
		}
	}
	G->n = n;
	G->e = e;
}

void DispGraph(MatGraph* G)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < G->n; i++)
	{
		for (j = 0; j < G->n; j++)
		{
			if (G->edges[i][j] == INF)
			{
				printf("%4s", "¡Þ");
			}
			else
			{
				printf("%4d", G->edges[i][j]);
			}
		}
		printf("\n");
	}
}

int visited[MAXV] = { 0 };
void DFS(MatGraph* G, int v)
{
	printf("%d", v);
	visited[v] = 1;
	int i = 0;
	for (i = 0; i < G->n; i++)
	{
		if (G->edges[v][i] != 0 && G->edges[v][i] != INF && visited[i] != 1)
		{
			DFS(G, i);
		}
	}
}

void DFSTraverse(MatGraph* G, int v)
{
	int i = 0; 
	for (i = 0; i < G->n; i++)
	{
		if (visited[i] == 0)
		{
			DFS(G, v);
		}
	}
	printf("\n");
}

int visited1[MAXV] = { 0 };
void BFS(MatGraph* G, int v)
{
	int Queue[MAXV] = { 0 };
	int front = 0;
	int rear = 0;
	printf("%d", v);
	visited1[v] = 1;
	rear = (rear + 1) % MAXV;
	Queue[rear] = v;
	int i = 0;
	while(front != rear)
	{
		front = (front + 1) % MAXV;
		int e = Queue[front];
		for (i = 0; i < G->n; i++)
		{
			if (G->edges[e][i] != 0 && G->edges[e][i] != INF && visited1[i] != 1)
			{
				printf("%d", i);
				visited1[i] = 1;
				rear = (rear + 1) % MAXV;
				Queue[rear] = i;
			}
		}
	}
}

void BFSTraverse(MatGraph* G, int v)
{
	int i = 0;
	for (i = 0; i < G->n; i++)
	{
		if (visited1[i] != 1)
		{
			BFS(G, v);
		}
	}
	printf("\n");
}