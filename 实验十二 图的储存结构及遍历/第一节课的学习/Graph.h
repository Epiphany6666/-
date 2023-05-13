#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define MAXV 20 /*<最大顶点个数>*/
#define INF 32767

typedef struct
{
	int no;//顶点的编号
	//InfoType info;//顶点的其他信息
}VerType;

typedef struct
{
	int edges[MAXV][MAXV];//邻接矩阵数据
	int n, e;//n是顶点数，e是边数
	VerType vexs[MAXV];
}MatGraph;

void CreateMat(MatGraph& G, int A[MAXV][MAXV], int n, int e);

void DispMat(MatGraph& G);