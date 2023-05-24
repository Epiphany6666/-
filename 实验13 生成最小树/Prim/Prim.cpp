#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
typedef struct
{
	int u;
	int v;
	int w;
}Edge;

void Swap(Edge E[], int j)
{
	Edge temp = { 0, 0, 0 };
	temp = E[j];
	E[j] = E[j + 1];
	E[j + 1] = temp;
}

void InsertSort(Edge E[], int n)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (E[j].w > E[j + 1].w)
			{
				Swap(E, j);
			}
		}
	}
	printf("按权值排序之后的矩阵为:\n");
	for (i = 0; i < n; i++)
	{
		printf("(%d, %d)%d\n", E[i].u, E[i].v, E[i].w);
	}
}

int Find(int parent[], int f)
{
	while (parent[f] > 0)
	{
		f = parent[f];
	}
	return f;
}

void Kruskal(MatGraph g)
{
	int i, j, k, n, m;
	int parent[MAXV] = { 0 };
	Edge E[MAXV];
	k = 0;
	for (i = 0; i < g.n; i++)
	{
		for (j = i + 1; i < g.n; j++)
		{
			if (g.edges[i][j] != 0 && g.edges[i][j] != INF)
			{
				E[k].u = i;
				E[k].v = j;
				E[k].w = g.edges[i][j];
				k++;
			}
		}
	}
	InsertSort(E, g.e);
	for (i = 0; i < g.e; i++)
	{
		n = Find(parent, E[i].u);
		m = Find(parent, E[i].v);
		if (n != m)
		{
			parent[n] = m;
			printf("(%d, %d)%d\n", E[i].u, E[i].v, E[i].w);
		}
	}
	printf("顶点：");
	for (i = 0; i < g.n; i++)
		printf("%3d", i);
	printf("\n");
	for (i = 0; i < g.n; i++)
	{
		printf("%3d", parent[i]);
	}
	printf("\n");
}
