#define _CRT_SECURE_NO_WARNINGS
typedef struct
{
	int u;
	int v;
	int w;
}Edge;

void Kruskal(MatGraph g)
{
	int i, j, ul, vl, snl, sn2, k;
	int vest[MAXV];
	Edge E[MaxSize];
	k = 0;
	for (i = 0; i < g.n; i++)
	{
		for (j = 0; j < g.n; j++)
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
	for (i = 0; i < g.n; i++)
	{
		vest[i] = i;
	}
}