//#define _CRT_SECURE_NO_WARNINGS
//void Dispath(MatGraph g, int dist[], int path[], int S, int v)
//{
//	int i, j, k;
//	int apath[MAXV], d;
//	for (i = 0; i < g.n; i++)
//	{
//		if (S[i] == 1 && i != v)
//		{
//			printf("从顶点%d到顶点%d的路径长度为：%d\t路径为：", v, i, dist[i]);
//			d = 0;
//			apath[d] = i;
//			k = path[i];
//			if (k == -1)
//				printf("无路径\n");
//			else
//			{
//				while (k != v)
//				{
//					d++;
//					apath[d] = v;
//					printf("%d", apath[d]);
//					for (j = d - 1; j >= 0; j--)
//					{
//						printf(",%d", apath[j]);
//					}
//					printf("\n");
//				}
//			}
//		}
//	}
//}
//
//void Dijkstra(MatGraph g, int v)
//{
//	int dist[MAXV], path[MAXV];
//	int S[MAXV];
//	int mindist, i, j, u;
//	for (i = 0; i < g.n; i++)
//	{
//		dist[i] = g.edges[v][i];
//		S[i] = 0;
//		if (g.edges[v][i] < INF)
//		{
//			path[i] = v;
//		}
//		else
//		{
//			path[i] = -1;
//		}
//	}
//	S[v] = 1;
//	path[v] = 0;
//	for (i = 0; j < g.n - 1; i++)
//	{
//		mindist = INF;
//		for (j = 0; j < g.n; j++)
//		{
//			if (S[j] == 0 && dist[j] < mindist)
//			{
//				u = j;
//				mindist = dist[j];
//			}
//		}
//		S[u] = 1;
//		for (j = 0; j < g.n; j++)
//		{
//			if (S[j] == 0)
//			{
//				if (g.edges[u][j] < INF && dist[u] + g.edges[u][j] < dist[j])
//				{
//					dist[j] = dist[u] + g.edges[u][j];
//					path[j] = u;
//				}
//			}
//		}
//	}
//	Dispath(g, dist, path, S, v);
//}

#include"Dijkstra.h"
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
			G.edges[i][j] = A[i][j];
		}
	}
}

void Dispath(MatGraph g, int S[], int dist[], int path[], int v)
{
	int i = 0;
	int k = 0;
	int apath[MAXV];
	int d = 0;
	int j = 0;
	for (i = 0; i < g.n; i++)
	{
		if (S[i] == 1 && i != v)
		{
			printf("从顶点%d到顶点%d的路径长度为：%d\t路径为：", v, i, dist[i]);
			d = 0;
			apath[d] = i;
			k = path[i];
			if (k == -1)
			{
				printf("无路径\n");
			}
			else
			{
				while (k != v)
				{
					d++;
					apath[d] = k;
					k = path[k];
				}
				d++;
				apath[d] = v;
				printf("%d", apath[d]);
				for (j = d - 1; j >= 0; j--)
				{
					printf(",%d", apath[j]);
				}
				printf("\n");
			}
		}
	}
}

void Dijkstra(MatGraph g, int u)
{
	int S[MAXV] = { 0 };
	int dist[MAXV] = { 0 };
	int path[MAXV] = { 0 };
	int i = 0;
	int j = 0;
	int mindist = INF;
	int k = 0;
	for (i = 0; i < g.n; i++)
	{
		dist[i] = g.edges[u][i];
		if (dist[i] != 0 && dist[i] != INF)
		{
			path[i] = u;
		}
		else
		{
			path[i] = -1;
		}
	}
	S[u] = 1;
	path[u] = 0;
	for (i = 0; i < g.n - 1; i++)
	{
		mindist = INF;
		for (j = 0; j < g.n; j++)
		{
			if (S[j] == 0 && mindist > dist[j])
			{
				mindist = dist[j];
				k = j;
			}
		}
		S[k] = 1;
		for (j = 0; j < g.n; j++)
		{
			if (S[j] != 1)
			{
				if (g.edges[k][j] < INF && dist[j] > dist[k] + g.edges[k][j])
				{
					dist[j] = dist[k] + g.edges[k][j];
					path[j] = k;
				}
			}
		}
	}
	Dispath(g, S, dist, path, u);
}
