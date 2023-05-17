#include"AdjGraph.h"
void CreateAdjGraph(AdjGraph*& G, int A[MAXV][MAXV], int n, int e)
{
	ArcNode* p = NULL;
	G = (AdjGraph*)malloc(sizeof(AdjGraph));
	int i = 0;
	int j = 0;
	for (i = 0; i < n; i++)
	{
		G->adjlist[i].firstarc = NULL;
		for (j = 0; j < n; j++)
		{
			if (A[i][j] != INF && A[i][j] != 0)
			{
				p = (ArcNode*)malloc(sizeof(ArcNode));
				p->adjvex = j;
				p->weight = A[i][j];
				p->nextarc = G->adjlist[i].firstarc;
				G->adjlist[i].firstarc = p;
			}
		}
	}
	G->n = n;
	G->e = e;
}

void DispAdjGraph(AdjGraph* G)
{
	int i = 0;
	ArcNode* p = NULL;
	for (i = 0; i < G->n; i++)
	{
		p = G->adjlist[i].firstarc;
		printf("%d:", i);
		while (p != NULL)
		{
			printf("%d[%d]->", p->adjvex, p->weight);
			p = p->nextarc;
		}
		printf("^\n");
	}
}

int visited[MAXV] = { 0 };
void DFS(AdjGraph* G, int v)
{
	ArcNode* p = NULL;
	p = G->adjlist[v].firstarc;
	//printf("%d", p->adjvex);
	printf("%d", v);
	visited[v] = 1;
	while (p != NULL)
	{
		if (visited[p->adjvex] != 1)
		{
			DFS(G, p->adjvex);
		}
		p = p->nextarc;
	}
}

void DFSTraverse(AdjGraph* G, int v)
{
	int i = 0;
	for (i = 0; i < G->n; i++)
	{
		if (visited[i] != 1)
		{
			DFS(G, v);
		}
	}
	printf("\n");
}

int visited1[MAXV] = { 0 };
void BFS(AdjGraph* G, int v)
{
	ArcNode* p = NULL;
	int Queue[MAXV];
	int front = 0;
	int rear = 0;
	printf("%d", v);
	visited1[v] = 1;
	rear = (rear + 1) % MAXV;
	Queue[rear] = v;
	while (front != rear)
	{
		front = (front + 1) % MAXV;
		int e = Queue[front];
		p = G->adjlist[e].firstarc;
		while (p != NULL)
		{
			if (visited1[p->adjvex] != 1)
			{
				printf("%d", p->adjvex);
				rear = (rear + 1) % MAXV;
				Queue[rear] = p->adjvex;
				visited1[p->adjvex] = 1;
			}
			p = p->nextarc;
		}
	}
	printf("\n");
}

void BFSTraverse(AdjGraph* G, int v)
{
	int i = 0;
	for (i = 0; i < G->n; i++)
	{
		if (visited1[i] != 1)
		{
			BFS(G, v);
		}
	}
}

//int visited2[MAXV] = { 0 };
//void FindaPath(AdjGraph* G, int u, int v, int path[], int d)
//{
//	ArcNode* p = NULL;
//	int i = 0;
//	visited2[u] = 1;
//	d++;
//	path[d] = u;
//	if (u == v)
//	{
//		for (i = 0; i <= d; i++)
//		{
//			printf("%d", path[i]);
//		}
//		printf("\n");
//		return;
//	}
//	p = G->adjlist[u].firstarc;
//	while (p != NULL)
//	{
//		int e = p->adjvex;
//		if (visited2[e] != 1)
//			FindaPath(G, e, v, path, d);
//		p = p->nextarc;
//	}
//}

int visited2[MAXV] = { 0 };
void FindaPath(AdjGraph* G, int u, int v, int path[], int d)
{
	ArcNode* p = NULL;
	int i = 0;
	d++;
	path[d] = u;
	visited2[u] = 1;
	if (u == v)
	{
		for (i = 0; i <= d; i++)
		{
			printf("%d", path[i]);
		}
		printf("\n");
		return;
	}
	p = G->adjlist[u].firstarc;
	while (p != NULL)
	{
		if (visited2[p->adjvex] != 1)
		{
			FindaPath(G, p->adjvex, v, path, d);
		}
		p = p->nextarc;
	}
}