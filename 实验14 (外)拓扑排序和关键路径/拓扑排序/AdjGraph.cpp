#include"AdjGraph.h"
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
				p->adjvex = i;
				p->nextarc = G->adjlist[i].firstarc;
				G->adjlist[i].firstarc = p;
			}
		}
	}
}

void TopSort(AdjGraph* G)
{
	int i = 0;
	ArcNode* p = NULL;
	int st[MAXV], top = -1;
	for (i = 0; i < G->n; i++)//初始化count
	{
		G->adjlist[i].count = 0;
	}
	for (i = 0; i < G->n; i++)//计算每个结点的入度
	{
		p = G->adjlist->firstarc;
		while (p != NULL)
		{
			G->adjlist[p->adjvex].count++;
			p = p->nextarc;
		}
	}
	for (i = 0; i < G->n; i++)//让每个度为0的入栈
	{
		if (G->adjlist[i].count == 0)
		{
			st[++top] = i;
		}
	}
	while (top != -1)
	{
		i = st[top--];
		printf("%d ", i);
		p = G->adjlist[i].firstarc;
		while (p != NULL)
		{
			G->adjlist[p->adjvex].count--;
			if (G->adjlist[p->adjvex].count == 0)
			{
				st[++top] = p->adjvex;
			}
			p = p->nextarc;
		}
	}
}