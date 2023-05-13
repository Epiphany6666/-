#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define MAXV 200
#define INF 32767

typedef struct ANode
{
	int adjvex;//�ñߵ��ڽӵ���
	struct ANode* nextarc;//ָ����һ���ߵ�ָ��
	int weight;//�ñߵ������Ϣ������Ȩֵ��������������ʾ��
}ArcNode;

typedef struct Vnode
{
	//InfoType info;//�����������Ϣ
	ArcNode* firstarc;//ָ���һ���߽��
}VNode;

typedef struct
{
	VNode adjlist[MAXV];
	int n, e;
}AdjGraph;

void CreateAdj(AdjGraph*& G, int A[MAXV][MAXV], int n, int e);

void DispAdj(AdjGraph* G);