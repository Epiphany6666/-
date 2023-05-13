#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define MAXV 200
#define INF 32767

typedef struct ANode
{
	int adjvex;//该边的邻接点编号
	struct ANode* nextarc;//指向下一条边的指针
	int weight;//该边的相关信息，例如权值（这里用整数表示）
}ArcNode;

typedef struct Vnode
{
	//InfoType info;//顶点的其他信息
	ArcNode* firstarc;//指向第一个边结点
}VNode;

typedef struct
{
	VNode adjlist[MAXV];
	int n, e;
}AdjGraph;

void CreateAdj(AdjGraph*& G, int A[MAXV][MAXV], int n, int e);

void DispAdj(AdjGraph* G);