#include"Floyd.h"
void CreateGraph(MatGraph& g, int A[MAXV][MAXV], int n, int e)
{
	g.n = n;
	g.e = e;
	int i = 0; 
	int j = 0;
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
	int i = 0;
	int j = 0;
	int d = 0;
	int k = 0;
	int s = 0;
	int apath[MAXV] = { 0 };
	for (i = 0; i < g.n; i++)
	{
		for (j = 0; j < g.n; j++)
		{
			//k = path[i][j];
			//if (k == -1)
			if (A[i][j] != INF && i != j)
			/*{
				printf("%d到%d无路径\n", i, j);
			}
			else
			*/{
				printf("%d到%d路径大小为：%d，路径为：", i, j, A[i][j]);
				k = path[i][j];
				d = 0;
				apath[d] = j;
				while (k != -1 && k != i)
				{
					apath[++d] = k;
					k = path[i][k];
				}
				apath[++d] = i;
				printf("%d", apath[d]);
				for (s = d - 1; s >= 0; s--)
				{
					printf(",%d", apath[s]);
				}
				printf("\n");
			}
		}
	}
}

void Floyd(MatGraph g)
{
	int A[MAXV][MAXV];
	int path[MAXV][MAXV];
	int i = 0;
	int j = 0;
	int k = 0;
	for (i = 0; i < g.n; i++)
	{
		for (j = 0; j < g.n; j++)
		{
			A[i][j] = g.edges[i][j];
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
				if (g.edges[k][j] + g.edges[i][k] < A[i][j])
				{
					A[i][j] = g.edges[k][j] + g.edges[i][k];
					path[i][j] = path[k][j];
				}
			}
		}
	}
	DispPath(g, A, path);
}