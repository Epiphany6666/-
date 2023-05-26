#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#define MAXV 20
#define INF  32767

typedef struct
{
	int edges[MAXV][MAXV];
	int n;
	int e;
}MatGraph;

void CreateGraph(MatGraph& G, int A[MAXV][MAXV], int n, int e);

void Dijkstra(MatGraph G, int u);