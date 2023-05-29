//void TopSort(AdjGraph* G)
//{
//	int i, j;
//	int st[MAXV], top = -1;//
//	ArcNode* p = NULL;
//	for (i = 0; i < G->n; i++)
//	{
//		G->adjlist[i].count = 0;
//	}
//	for (i = 0; i < G->n; i++)
//	{
//		p = G->adjlist[i].firstarc;
//		while (p != NULL)
//		{
//			G->adjlist[p->adjvex].count++;
//			p = p->nextarc;
//		}
//	}
//
//	for (i = 0; i < G->n; i++)
//	{
//		if (G->adjlist[i].count == 0)
//		{
//			top++;
//			st[top] = i;
//		}
//	}
//	while (top > -1)
//	{
//		i = st[top];
//		top--;
//		printf("%2d ", i);
//		p = G->adjlist[i].firstarc;
//		while (p != NULL)
//		{
//			j = p->adjvex;
//			G->adjlist[j].count--;
//			if (G->adjlist[j].count == 0;)
//			{
//				top++;
//				st[top] = j;
//			}
//			p = p->nextarc;
//		}
//	}
//}

//void TopSort(AdjGraph* G)
//{
//	int i = 0;
//	int st[MAXV], top = -1;
//	ArcNode* p = NULL;
//	for (i = 0; i < G->n; i++)//count³õÊ¼»¯
//	{
//		G->adjlist[i].count = 0;
//	}
//	for (i = 0; i < G->n; i++)
//	{
//		p = NULL;
//		p = G->adjlist[i].firstarc;
//		while (p != NULL)
//		{
//			G->adjlist[p->adjvex].count++;
//			p = p->nextarc;
//		}
//	}
//	for (i = 0; i < G->n; i++)
//	{
//		if (G->adjlist[i].count == 0)
//		{
//			top++;
//			st[top] = i;
//		}
//	}
//	while (top > -1)
//	{
//		i = st[top--];
//		printf("%2d ", i);
//		p = G->adjlist[i].firstarc;
//		while (p != NULL)
//		{
//			G->adjlist[p->adjvex].count--;
//			if (G->adjlist[p->adjvex].count == 0)
//			{
//				st[++top] = p->adjvex;
//			}
//			p = p->nextarc;
//		}
//	}
//}
#include"AdjGraph.h"
int main()
{
	int A[MAXV][MAXV] = { 
		{0, 6, 4, 5, INF, INF, INF, INF, INF},
		{INF, 0, INF, INF, 1, INF, INF, INF, INF},
		{INF, INF, 0, INF, 1, INF, INF, INF, INF},
		{INF, INF, INF, 0, INF, INF, INF, 2, INF},
		{INF, INF, INF, INF, 0, 9, 7, INF, INF},
		{INF, INF, INF, INF, INF, 0, INF, INF, 2},
		{INF, INF, INF, INF, INF, INF, 0, INF, 4},
		{INF, INF, INF, INF, INF, INF, INF, 0, 4},
		{INF, INF, INF, INF, INF, INF, INF, INF, 0} };
	int n = 9, e = 11;
	AdjGraph* G;
	CreateGraph(G, A, n, e);
	TopSort(G);
	return 0;
}