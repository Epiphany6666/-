#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define MAXV 20
#define INF 32767
#include<stdio.h>
typedef struct
{
	int edges[MAXV][MAXV];
	int n, e;
}MatGraph;

void CreateGraph(MatGraph& g, int A[][MAXV], int n, int e);

void Dijkstra(MatGraph g, int v);