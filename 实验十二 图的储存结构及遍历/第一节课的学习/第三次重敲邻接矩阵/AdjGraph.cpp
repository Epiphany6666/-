#include"AdjGraph.h"
void CreateGraph(AdjGraph*& G, int A[MAXV][MAXV], int n, int e)
{
	ArcNode* p = NULL;
	G = (AdjGraph*)malloc(sizeof(AdjGraph));
	G->n = n;
	G->e = e;
	int i = 0;
	int j = 0;
	for (i = 0; i < G->n; i++)
	{
		G->adjlist[i].firstarc = NULL;
		for (j = 0; j < G->n; j++)
		{
			if (A[i][j] != 0 && A[i][j] != INF)
			{
				p = (ArcNode*)malloc(sizeof(ArcNode));
				p->adjvex = j;
				p->weight = A[i][j];
				p->nextarc = G->adjlist[i].firstarc;
				G->adjlist[i].firstarc = p;
			}
		}
	}
}

void DispGraph(AdjGraph* G)
{
	ArcNode* p;
	int i = 0;
	for (i = 0; i < G->n; i++)
	{
		printf("%d£º", i);
		p = G->adjlist[i].firstarc;
		while (p != NULL)
		{
			printf("%d[%d]->", p->adjvex, p->weight);
			p = p->nextarc;
		}
		printf("^\n");
	}
}

int visited[MAXV] = { 0 };
void BFS(AdjGraph* G, int v)
{
	ArcNode* p = NULL;
	printf("%d", v);
	visited[v] = 1;
	int i = 0;
	p = G->adjlist[v].firstarc;
	while (p != NULL)
	{
		if (visited[p->adjvex] != 1)
		{
			BFS(G, p->adjvex);
		}
		p = p->nextarc;
	}
}

void  BFSTraverse(AdjGraph* G)
{
	int i = 0;
	for (i = 0; i < G->n; i++)
	{
		if (visited[i] != 1)
		{
			BFS(G, i);
		}
	}
	printf("\n");
}

int visited1[MAXV] = { 0 };
void DFS(AdjGraph* G, int v)
{
	int w = 0;
	ArcNode* p = NULL;
	int Queue[MAXV];
	int front = 0;
	int rear = 0;
	rear = (rear + 1) % MAXV;
	Queue[rear] = v;
	printf("%d", v);
	visited1[v] = 1; 
	while (front != rear)
	{
		front = (front + 1) % MAXV;
		w = Queue[front];
		
		p = G->adjlist[w].firstarc;
		while (p != NULL)
		{
			if (visited1[p->adjvex] != 1)
			{
				rear = (rear + 1) % MAXV;
				Queue[rear] = p->adjvex;
				printf("%d", p->adjvex);
				visited1[p->adjvex] = 1;
			}
			p = p->nextarc;
		}
	}
}

void DFSTraverse(AdjGraph* G)
{
	int i = 0; 
	for (i = 0; i < G->n; i++)
	{
		if (visited1[i] != 1)
		{
			DFS(G, i);
		}
	}
	printf("\n");
}

int visited2[MAXV] = { 0 };
void FindPath(AdjGraph* G, int path[], int d, int u, int v)
{
	ArcNode* p = NULL;
	d++;
	path[d] = u;
	visited2[u] = 1;
	if (u == v)
	{
		int i = 0;
		for (i = 0; i <= d; i++)
		{
			printf("%d", path[i]);
		}
		printf("\n");
		return;
	}
	else
	{
		p = G->adjlist[u].firstarc;
		while (p != NULL)
		{
			if (visited2[p->adjvex] != 1)
			{
				FindPath(G, path, d, p->adjvex, v);
			}
			p = p->nextarc;
		}
	}
}

void ShortPath(AdjGraph* G, int u, int v)
{
	ArcNode* p = NULL;
	int w = 0;
	int visited3[MAXV] = { 0 };
	Queue queue[MAXV];
	int front = -1;
	int rear = -1;
	rear++;
	queue[rear] = { u, -1 };
	visited3[u] = 1;
	while (front != rear)
	{
		front++;
		w = queue[front].data;
		if (w == v)
		{
			int f = front;
			while (queue[f].parent != -1)
			{
				printf("%d", queue[f].data);
				f = queue[f].parent;
			}
			printf("%d", queue[f].data);
			break;
		}
		p = G->adjlist[w].firstarc;
		while(p != NULL)
		{
			if (visited3[p->adjvex] != 1)
			{
				visited3[p->adjvex] = 1;
				rear++;
				queue[rear].data = p->adjvex;
				queue[rear].parent = front;
			}
			p = p->nextarc;
		}
	}
}