#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define MAXV 20 /*<��󶥵����>*/
#define INF 32767

typedef struct
{
	int no;//����ı��
	//InfoType info;//�����������Ϣ
}VerType;

typedef struct
{
	int edges[MAXV][MAXV];//�ڽӾ�������
	int n, e;//n�Ƕ�������e�Ǳ���
	VerType vexs[MAXV];
}MatGraph;

void CreateMat(MatGraph& G, int A[MAXV][MAXV], int n, int e);

void DispMat(MatGraph& G);