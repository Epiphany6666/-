#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#define MAXV 20
#define INF 32767

typedef struct
{
	int Edges[MAXV][MAXV];
	int n;
	int e;
}MatGraph;

void CreateMatGraph(MatGraph*& G, int A[MAXV][MAXV], int n, int e);

void DispGraph(MatGraph* G);

void DFS(MatGraph* G, int u);

void DFSTraverse(MatGraph* G);

void BFS(MatGraph* G, int u);

void BFSTraverse(MatGraph* G);