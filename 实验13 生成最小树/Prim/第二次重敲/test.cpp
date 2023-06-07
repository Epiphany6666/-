#include"Prim.h"
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

void Prim(MatGraph g, int v)
{
	int lowcost[MAXV] = { 0 };
	int closest[MAXV] = { 0 };
	int i = 0;
	int j = 0;
	int mindist = 32767;
	int k = 0;
	for (i = 0; i < g.n; i++)
	{
		lowcost[i] = g.edges[v][i];
		closest[i] = v;
	}
	//for (i = 0; i < g.n; i++)
	for (i = 1; i < g.n; i++)
	{
		mindist = INF;
		for (j = 0; j < g.n; j++)
		{
			if (lowcost[j] != 0 && lowcost[j] < mindist)
			{
				mindist = lowcost[j];
				k = j;
			}
		}
		printf("(%d, %d)[%d]\n", closest[k], k, mindist);
		lowcost[k] = 0;
		for (j = 0; j < g.n; j++)
		{
			if (lowcost[j] != 0 && g.edges[k][j] < lowcost[j])
			{
				lowcost[j] = g.edges[k][j];
				closest[j] = k;
			}
		}
	}
}