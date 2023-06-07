#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define INF 32767
#define MAXV 20
typedef struct
{
	int edges[MAXV][MAXV];
	int n, e;
}MatGraph;

void CreateGraph(MatGraph& g, int A[][MAXV], int n, int e);

void Floyd(MatGraph g);