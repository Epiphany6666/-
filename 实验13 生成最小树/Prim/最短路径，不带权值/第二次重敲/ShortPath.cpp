#include"ShortPath.h"
void CreateGraph(AdjGraph*& G, int A[][MAXV], int n, int e)
{
	G = (AdjGraph*)malloc(sizeof(AdjGraph));
	G->n = n;
	G->e = e;
	int i = 0;
	int j = 0;
	ArcNode* p = NULL;
	for (i = 0; i < G->n; i++)
	{
		G->adjlist[i].firstarc = NULL;
		for (j = 0; j < G->n; j++)
		{
			if (A[i][j] != 0 && A[i][j] != INF)
			{
				p = (ArcNode*)malloc(sizeof(ArcNode));
				p->adjvex = j;
				p->nextarc = G->adjlist[i].firstarc;
				G->adjlist[i].firstarc = p;
			}
		}
	}
}

void ShortPath(AdjGraph* G, int u, int v)
{
	Queue queue[MAXV];
	int front = 0;
	int rear = 0;
	int w = 0;
	ArcNode* p = NULL;
	int f = 0;
	int visited[MAXV] = { 0 };
	rear = (rear + 1) % MAXV;
	queue[rear].data = u;
	queue[rear].parent = -1;
	visited[u] = 0;
	int i = 0;
	while (front != rear)
	{
		front = (front + 1) % MAXV;
		w = queue[front].data;
		if (w == v)
		{
			/*f = queue[w].parent;
			printf("%d", w);
			while (f != -1)
			{
				printf("%d", f);
				f = queue[f].parent;
			}*/
			i = front;
			while (i != -1)
			{
				printf("%d", queue[i].data);
				i = queue[i].parent;
			}
			//printf("%d", queue[i].data);
			break;
		}
		p = G->adjlist[w].firstarc;
		while (p != NULL)
		{
			rear = (rear + 1) % MAXV;
			queue[rear].data = p->adjvex;
			queue[rear].parent = front;
			p = p->nextarc;
		}
	}
}