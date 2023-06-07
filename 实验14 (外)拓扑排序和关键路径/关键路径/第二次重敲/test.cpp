#include"KeyPath.h"
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
				p->weight = A[i][j];
				p->nextarc = G->adjlist[i].firstarc;
				G->adjlist[i].firstarc = p;
			}
		}
	}
}

void TopSort(AdjGraph* G, int topsort[])
{
	int i = 0;
	ArcNode* p = NULL;
	int St[MAXV];
	int top = -1;
	int k = -1;
	for (i = 0; i < G->n; i++)
	{
		G->adjlist[i].count = 0;
	}
	for (i = 0; i < G->n; i++)
	{
		p = G->adjlist[i].firstarc;
		while (p != NULL)
		{
			G->adjlist[p->adjvex].count++;
			p = p->nextarc;
		}
	}
	for (i = 0; i < G->n; i++)
	{
		if (G->adjlist[i].count == 0)
		{
			St[++top] = i;
		}
	}
	while (top > -1)
	{
		i = St[top--];
		topsort[++k] = i;
		p = G->adjlist[i].firstarc;
		while (p != NULL)
		{
			G->adjlist[p->adjvex].count--;
			if (G->adjlist[p->adjvex].count == 0)
			{
				St[++top] = p->adjvex;
			}
			p = p->nextarc;
		}
	}
	if (k < G->n)
		return;
	else
	{
		printf("ÍØÆËÐòÁÐÎª£º\n");
		for (i = 0; i < G->n; i++)
			printf("%c ", (char)(topsort[i] + 'A'));
		printf("\n");
	}
}

void KeyPath(AdjGraph* G)
{
	int ee[MAXV] = { 0 };
	int el[MAXV];
	int ve;
	int vl;
	int topsort[MAXV];
	TopSort(G, topsort);
	int lnode = topsort[0];
	int enode = topsort[G->n - 1];
	int i = 0;
	ArcNode* p = NULL;
	for (i = 0; i < G->n; i++)
	{
		p = G->adjlist[i].firstarc;
		while (p != NULL)
		{
			if (p->weight + ee[i] > ee[p->adjvex])
			{
				ee[p->adjvex] = p->weight + ee[i];
			}
			p = p->nextarc;
		}
	}
	for (i = 0; i < G->n; i++)
	{
		el[i] = ee[enode];
	}
	for (i = G->n - 2; i >= 0; i--)
	{
		p = G->adjlist[i].firstarc;
		while (p != NULL)
		{
			//if (ee[i] - p->weight < el[i])
			if (el[i] - p->weight < el[i])
			{
				el[i] = ee[i] - p->weight;
			}
			p = p->nextarc;
		}
	}
	for (i = 0; i < G->n; i++)
	{
		p = G->adjlist[i].firstarc;
		while (p != NULL)
		{
			ve = ee[i];
			vl = el[p->adjvex] - p->weight;
			if (ve == vl)
			{
				printf("%3d%3d%3d\n", i, p->adjvex, p->weight);
			}
			p = p->nextarc;
		}
	}
}