#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define MAXV 20
#define INF 32767

typedef struct
{
	int edges[MAXV][MAXV];
	int n, e;
}MatGraph;

typedef struct
{
	int u;
	int v;
	int w;
}Edges;

void CreateGraph(MatGraph& g, int A[][MAXV], int n, int e);

void Kruskal(MatGraph g);