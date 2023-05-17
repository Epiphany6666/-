#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAXV 20
#define INF 32767
typedef struct ANode
{
	int adjvex;
	struct ANode* nextarc;
	int weight;
}ArcNode;

typedef struct
{
	//InfoType info;//∂•µ„–≈œ¢
	ArcNode* firstarc;
}VNode;

typedef struct
{
	VNode adjlist[MAXV];
	int n, e;
}AdjGraph;

void CreateAdjGraph(AdjGraph*& G, int A[MAXV][MAXV], int n, int e);

void DispAdjGraph(AdjGraph* G);

void DFSTraverse(AdjGraph* G, int v);

void BFSTraverse(AdjGraph* G, int v);

void FindaPath(AdjGraph* G, int u, int v, int path[], int d);