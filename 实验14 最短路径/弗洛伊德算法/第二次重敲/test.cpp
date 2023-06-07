#include"Floyd.h"
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

void DispPath(MatGraph g, int A[][MAXV], int path[][MAXV])
{
	int apath[MAXV];
	int d;
	int i = 0;
	int j = 0;
	int k = 0;
	int s = 0;
	for (i = 0; i < g.n; i++)
	{
		for (j = 0; j < g.n; j++)
		{
			if (A[i][j] != INF && i != j)
			{
				printf("%d到%d的路径长度为，路径为：", i, j, A[i][j]);
				d = 0;
				apath[d] = j;
				k = path[i][j];
				while (k != i)
				{
					apath[++d] = k;
					k = path[i][k];
				}
				apath[++d] = i;
				printf("%d", apath[d]);
				for (s = d - 1; s >= 0; s--)
				{
					printf(", %d", apath[s]);
				}
				printf("\n");
			}
		}
	}
}

void Floyd(MatGraph g)
{
	int i = 0;
	int A[MAXV][MAXV];
	int path[MAXV][MAXV];
	int j = 0;
	int k = 0;
	for (i = 0; i < g.n; i++)
	{
		for (j = 0; j < g.n; j++)
		{
			A[i][j] = path[i][j];
			if (A[i][j] != 0 && A[i][j] != INF)
			{
				path[i][j] = i;
			}
			else
			{
				path[i][j] = -1;
			}
		}
	}
	for (k = 0; k < g.n; k++)
	{
		for (i = 0; i < g.n; i++)
		{
			for (j = 0; j < g.n; j++)
			{
				//if (i != k && j != k)
				//{
					if (A[i][k] + A[k][j] < A[i][j])
					{
						A[i][j] = A[i][k] + A[k][j];
						path[i][j] = path[k][j];
					}
				//}
			}
		}
	}
	DispPath(g, A, path);
}