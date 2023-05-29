//void Floyd(MatGraph g)
//{
//	int A[MAXV][MAXV], path[MAXV][MAXV];
//	int i, j, k;
//	for (i = 0; i < g.n; i++)
//	{
//		for (j = 0; j < g.n; j++)
//		{
//			A[i][j] = g.edges[i][j];
//			if (i != j && g.edges[i][j] < INF)
//			{
//				path[i][j] = i;
//			}
//			else
//			{
//				path[i][j] = -1;
//			}
//		}
//	}
//}

//void DispPath(MatGraph g, int path[MAXV][MAXV], int A[MAXV][MAXV])
//{
//	int i = 0;
//	int j = 0;
//	int f = 0;
//	int apath[MAXV];
//	for (i = 0; i < g.n; i++)
//	{
//		for (j = 0; j < g.n; j++)
//		{
//			if (A[i][j] != 0 && A[i][j] != INF)
//			{
//				printf("%d到%d的最短路径为：", i, j);
//				f = path[i][j];
//				//while (f != -1)
//				/*while (f != i)
//				{
//					printf("%d ", f);
//					f = path[i][f];
//				}*/
//				d = 0;
//				apath[d] = j;
//				while (f != i)
//				{
//					d++;
//					apath[d] = f;
//					f = path[i][f];
//				}
//				d++;
//				apath[d] = i;
//				printf("%d", apath[d]);
//				int s = 0;
//				for (s = d - 1; s >= 0; s--)
//				{
//					printf(",%d", apath[s]);
//				}
//				printf("\t路径长度为:%d\n", A[i][j]);
//			}
//		}
//	}
//}

#include"Floyd.h"
void DispPath(MatGraph g, int A[][MAXV], int path[][MAXV])
{
	int i = 0;
	int j = 0;
	int apath[MAXV];
	int k = 0;
	int d = 0; 
	for (i = 0; i < g.n; i++)
	{
		for (j = 0; j < g.n; j++)
		{
			if (A[i][j] != 0 && A[i][j] != INF)
			{
				printf("从%d到%d的路径为:", i, j);
				k = path[i][j];
				d = 0;
				apath[d] = j;
				while (k != -1 && k != i)
				{
					d++;
					apath[d] = k;
					k = path[i][k];
				}
				d++;
				apath[d] = i;
				printf("%d", apath[d]);
				int s = 0;
				for (s = d - 1; s >= 0; s--)
				{
					printf(",%d", apath[s]);
				}
				printf("\t\t路径长度为:%d\n", A[i][j]);
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
	for (k = 0; k < g.n; k++)//以谁为转折点
	{
		for (i = 0; i < g.n; i++)
		{
			for (j = 0; j < g.n; j++)
			{
				if (i != j && i != k && j != k && A[k][j] + A[i][k] < A[i][j])
				{
					A[i][j] = A[k][j] + A[i][k];
					path[i][j] = path[k][j];
				}
			}
		}
	}
	//DispPath(g, path, A);
	DispPath(g, A, path);
}

void CreateGraph(MatGraph& g, int A[][MAXV], int n, int e)
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