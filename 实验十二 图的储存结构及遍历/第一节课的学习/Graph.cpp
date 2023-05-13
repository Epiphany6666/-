#include"Graph.h"
void CreateMat(MatGraph& G, int A[MAXV][MAXV], int n, int e)
{
	int i, j;
	G.n = n;
	G.e = e;
	for (i = 0; i < G.n; i++)
	{
		for (j = 0; j < G.n; j++)
		{
			G.edges[i][j] = A[i][j];
		}
	}
}

void DispMat(MatGraph& G)
{
	int i, j;
	for (i = 0; i < G.n; i++)
	{
		for (j = 0; j < G.n; j++)
		{
			if (G.edges[i][j] != INF)
			{
				printf("%4d", G.edges[i][j]);
			}
			else
			{
				printf("%4s", "¡Þ");
			}
		}
		printf("\n");
	}
}