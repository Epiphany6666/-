#include"Prim.h"
void CreateGraph(MatGraph& G, int A[MAXV][MAXV], int n, int e)
{
	G.n = n;
	G.e = e;
	int i = 0;
	int j = 0;
	for (i = 0; i < G.n; i++)
	{
		for (j = 0; j < G.n; j++)
		{
			G.Edges[i][j] = A[i][j];
		}
	}
}

void Prim(MatGraph G, int v)
{
	int closest[MAXV] = { 0 };
	int lowcost[MAXV] = { 0 };
	int i = 0;
	int j = 0;
	int mindist = INF;
	int k = 0;
	for (i = 0; i < G.n; i++)
	{
		closest[i] = v;
		lowcost[i] = G.Edges[v][i];
	}
	for (i = 1; i < G.n; i++)
	{
		mindist = INF;
		for (j = 0; j < G.n; j++)
		{
			if (lowcost[j] != 0 && lowcost[j] < mindist)
			{
				mindist = lowcost[j];
				k = j;
			}
		}
		printf("(%d,%d)[%d]\n", closest[k], k, mindist);
		lowcost[k] = 0;
		for (j = 0; j < G.n; j++)
		{
			if (lowcost[j] != 0 && lowcost[j] > G.Edges[k][j])
			{
				closest[j] = k;
				lowcost[j] = G.Edges[k][j];
			}
		}
	}
}

void InsertSort(Edge E[MAXV], int e)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < e; i++)
	{
		for (j = 0; j < e - i - 1; j++)
		{
			if (E[j].w > E[j + 1].w)
			{
				Edge temp;
				temp = E[j];
				E[j] = E[j + 1];
				E[j + 1] = temp;
			}
		}
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

void Kruskal(MatGraph G)
{
	int parent[MAXV] = { 0 };
	int i = 0;
	int j = 0;
	Edge E[MAXV];
	int k = 0;
	int n = 0;
	int m = 0;
	for (i = 0; i < G.n; i++)
	{
		for (j = i + 1; j < G.n; j++)
		{
			if (G.Edges[i][j] != 0 && G.Edges[i][j] != INF)
			{
				E[k].u = i;
				E[k].v = j;
				E[k].w = G.Edges[i][j];
				k++;
			}
		}
	}
	InsertSort(E, G.e);
	for (i = 0; i < G.e; i++)
	{
		n = Find(parent, E[i].u);
		m = Find(parent, E[i].v);
		if (n != m)
		{
			printf("(%d, %d)[%d]\n", E[i].u, E[i].v, E[i].w);
			parent[n] = m;
		}
	}
}