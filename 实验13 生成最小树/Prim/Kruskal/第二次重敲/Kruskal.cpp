#include"Kruskal.h"
void CreateGraph(MatGraph& g, int A[][MAXV], int n, int e)
{
	int i = 0;
	int j = 0;
	g.n = n;
	g.e = e;
	for (i = 0; i < g.n; i++)
	{
		for (j = 0; j < g.n; j++)
		{
			g.edges[i][j] = A[i][j];
		}
	}
}

void InsertSort(Edges E[], int k)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < k - 1; i++)
	{
		for (j = 0; j < k - i - 1; j++)
		{
			if (E[j].w > E[j + 1].w)
			{
				Edges temp = E[j];
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

void Kruskal(MatGraph g)
{
	Edges E[MAXV];
	int k = 0;
	int i = 0;
	int j = 0;
	int s1, s2;
	int parent[MAXV] = {0};
	for (i = 0; i < g.n; i++)
	{
		for (j = i + 1; j < g.n; j++)
		{
			if (g.edges[i][j] != 0 && g.edges[i][j] != INF)
			{
				E[k].u = i;
				E[k].v = j;
				E[k++].w = g.edges[i][j];
 			}
		}
	}
	InsertSort(E, k);
	for (i = 0; i < g.n; i++)
	{
		s1 = Find(parent, E[i].u);
		s2 = Find(parent, E[i].v);
		if (s1 != s2)
		{
			parent[s1] = s2;
			printf("(%d, %d)[%d]\n", E[i].u, E[i].v, E[i].w);
		}
	}
}