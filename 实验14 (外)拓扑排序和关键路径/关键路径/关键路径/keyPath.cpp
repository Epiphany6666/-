//void keyPath(AdjGraph* G)
//{
//	int topseq[max];
//	int enode;
//	int lnode;
//	int ee, el;
//	int i, w, k;
//	topsort(G, topseq);
//	ArcNode* p;
//	lnode = topseq[0];
//	enode = topseq[G->n - 1];
//	int ve[max];
//	int vl[max];
//	for (i = 0; i < G->n; i++)
//	{
//		ve[i] = 0;
//	}
//	for (i = 0; i < G->n; i++)
//	{
//		p = G->adjlist[i].firstarc;
//		while (p != NULL)
//		{
//			w = p->adjvex;
//			if (ve[i] + p->weight > ve[w])
//			{
//				ve[w] = ve[i] + p->weight;
//			}
//			p = p->nextarc;
//		}
//	}
//	for (i = 0; i < G->n; i++)
//	{
//		vl[i] = ve[enode];
//	}
//	for (i = G->n - 2; i >= 0; i--)
//	{
//		p = G->adjlist[i].firstarc;
//		while (p != NULL)
//		{
//			w = p->adjvex;
//			if (vl[w] - p->weight < vl[i])
//			{
//				vl[i] = vl[w] - p->weight;
//			}
//			p = p->nextarc;
//		}
//	}
//
//	printf("时间的最早和最晚开始时间:\n");
//	pirntf("ve:");
//	for (i = 0; i < G->n; i++)
//	{
//		printf("%2d ", ve[i]);
//	}
//	printf("\n");
//	printf("关键路径为：\n");
//	for (i = 0; i < G->n; i++)
//	{
//		p = G->adjlist[i].firstarc;
//		while (p != NULL)
//		{
//			k = p->adjvex;
//			ee = ve[i];
//			el = vl[k] - p->weight;
//			if (ee == el)
//			{
//				printf("%3d%3d%3d\n", i, k, p->weight);
//			}
//			p = p->nextarc;
// 		}
//	}
//}

#include"KeyPath.h"
void CreateGraph(AdjGraph*& G, int A[][MAXV], int n, int e)
{
	G = (AdjGraph*)malloc(sizeof(AdjGraph));
	int i = 0;
	int j = 0;
	ArcNode* p = NULL;
	G->n = n;
	G->e = e;
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
	int i = 0;
	ArcNode* p = NULL;
	for (i = 0; i < G->n; i++)
	{
		printf("%d：", i);
		p = G->adjlist[i].firstarc;
		while (p != NULL)
		{
			printf("%d[%d]->", p->adjvex, p->weight);
			p = p->nextarc;
		}
		printf("^\n");
	}
}

//void TopSort(AdjGraph* G)
//{
//	ArcNode* p = NULL;
//	int St[MAXV];
//	int top = -1;
//	int i = 0;
//	for (i = 0; i < G->n; i++)
//	{
//		G->adjlist[i].indegree = 0;//初始化入度
//	}
//	for (i = 0; i < G->n; i++)
//	{
//		p = G->adjlist[i].firstarc;
//		while (p != NULL)
//		{
//			G->adjlist[p->adjvex].indegree++;
//			p = p->nextarc;
//		}
//	}
//	for (i = 0; i < G->n; i++)//让入度为0的进栈
//	{
//		if (G->adjlist[i].indegree == 0)
//		{
//			St[++top] = i;
//		}
//	}
//	while (top != -1)//栈不为空
//	{
//		i = St[top--];
//		printf("%d", i);
//		p = G->adjlist[i].firstarc;
//		while (p != NULL)
//		{
//			G->adjlist[p->adjvex].indegree--;
//			if (G->adjlist[p->adjvex].indegree == 0)
//			{
//				St[++top] = p->adjvex;
//			}
//			p = p->nextarc;
//		}
//	}
//}

void TopSort(AdjGraph* G, int topsort[])
{
	int i = 0;
	ArcNode* p = NULL;
	int St[MAXV];
	int top = -1;
	int k = 0;
	for (i = 0; i < G->n; i++)
	{
		G->adjlist[i].indegree = 0;
	}
	for (i = 0; i < G->n; i++)
	{
		p = G->adjlist[i].firstarc;
		while (p != NULL)
		{
			G->adjlist[p->adjvex].indegree++;
			p = p->nextarc;
		}
	}
	for (i = 0; i < G->n; i++)
	{
		if (G->adjlist[i].indegree == 0)
		{
			St[++top] = i;
		}
	}
	while (top > -1)
	{
		i = St[top--];
		topsort[k++] = i;
		p = G->adjlist[i].firstarc;
		while (p != NULL)
		{
			G->adjlist[p->adjvex].indegree--;
			if (G->adjlist[p->adjvex].indegree == 0)
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
		printf("拓扑序列为：\n");
		for (i = 0; i < G->n; i++)
		{
			printf("%c ", (char)(topsort[i] + 'A'));
		}
		printf("\n");
	}
}


void KeyPath(AdjGraph* G)
{
	int topsort[MAXV];
	TopSort(G, topsort);
	int ve[MAXV] = { 0 };
	int vl[MAXV];
	int lnode = topsort[0];
	int enode = topsort[G->n - 1];
	int ee = 0;
	int el = 0;
	int i = 0;
	ArcNode* p = NULL;
	for (i = 0; i < G->n; i++)
	{
		p = G->adjlist[i].firstarc;
		while (p != NULL)
		{
			if (ve[p->adjvex] < ve[i] + p->weight)
			{
				ve[p->adjvex] = ve[i] + p->weight;
			}
			p = p->nextarc;
		}
	}
	for (i = 0; i < G->n; i++)//vl数组的初始化
	{
		//vl[i] = ve[G->n - 1];
		vl[i] = ve[enode];
	}
	for (i = G->n - 2; i >= 0; i++)//n -2
	{
		p = G->adjlist[i].firstarc;
		while (p != NULL)
		{
			//if (ve[i] - p->weight < vl[i])
			if (vl[p->adjvex] - p->weight < vl[i])
			{
				vl[i] = vl[p->adjvex] - p->weight;
			}
			p = p->nextarc;
		}
	}
	for (i = 0; i < G->n; i++)
	{
		p = G->adjlist[i].firstarc;
		while (p != NULL)
		{
			ee = ve[i];
			//el = vl[i] - p->weight;
			el = vl[p->adjvex] - p->weight;
			if (ee == el)
			{
				printf("%3d%3d%3d", i, p->adjvex, p->weight);
			}
			p = p->nextarc;
		}
	}
}