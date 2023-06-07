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
	ArcNode* firstarc;
	int count;
}VNode;

typedef struct
{
	VNode adjlist[MAXV];
	int n, e;
}AdjGraph;

void CreateGraph(AdjGraph*& G, int A[][MAXV], int n, int e);

void KeyPath(AdjGraph* G);