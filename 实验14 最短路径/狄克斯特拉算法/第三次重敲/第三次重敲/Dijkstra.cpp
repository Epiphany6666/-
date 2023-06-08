#include"Dijkstra.h"
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

void DispPath(MatGraph g, int v, int s[], int dist[], int path[])
{
	int i = 0;
	int d = 0;
	int apath[MAXV] = { 0 };
	int k = 0;
	int j = 0;
	for (i = 0; i < g.n; i++)
	{
		if (s[i] == 1 && i != v)
		{
			printf("%d到%d的路径长度为：%d，路径为：", v, i, dist[i]);
			if (path[i] == -1)
			{
				printf("无路径\n");
			}
			else
			{
				d = 0;
				apath[d] = i;
				k = path[i];
				while (k != v)
				{
					apath[++d] = k;
					k = path[k];
				}
				apath[++d] = v;
				printf("%d", apath[d]);
				for (j = d - 1; j >= 0; j--)
				{
					printf(", %d", apath[j]);
				}
				printf("\n");
			}
		}
	}
}

void Dijkstra(MatGraph g, int v)
{
	int s[MAXV] = { 0 };
	int dist[MAXV] = { 0 };
	int path[MAXV] = { 0 };
	int i = 0;
	int j = 0;
	int mindist = 32767;
	int k = 0;
	for (i = 0; i < g.n; i++)
	{
		dist[i] = g.edges[v][i];
		if (dist[i] != 0 && dist[i] != INF)
		{
			path[i] = v;
		}
		else
		{
			path[i] = -1;
		}
	}
	s[v] = 1;
	for (j = 0; j < g.n; j++)
	{
		mindist = INF;
		for (i = 0; i < g.n; i++)
		{
			if (s[i] != 1 && dist[i] < mindist)
			{
				mindist = dist[i];
				k = i;
			}
		}
		s[k] = 1;
		for (i = 0; i < g.n; i++)
		{
			if (s[i] != 1 && dist[k] + g.edges[k][i] < dist[i])
			{
				dist[i] = dist[k] + g.edges[k][i];
				path[i] = k;
			}
		}
	}
	DispPath(g, v, s, dist, path);
}