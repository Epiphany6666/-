#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define MAXV 20
#define INF 32767

typedef struct
{
	int Edges[MAXV][MAXV];
	int n;
	int e;
}MatGraph;

typedef struct
{
	int u;
	int v;
	int w;
}Edge;

void CreateGraph(MatGraph& G, int A[MAXV][MAXV], int n, int e);

void Prim(MatGraph G, int v);

void Kruskal(MatGraph G);