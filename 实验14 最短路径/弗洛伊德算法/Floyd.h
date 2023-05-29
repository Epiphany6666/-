#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define MAXV 6
#define INF 32767

typedef struct
{
	int edges[MAXV][MAXV];
	int n;
	int e;
}MatGraph;

void CreateGraph(MatGraph& g, int A[][MAXV], int n, int e);
void Floyd(MatGraph g);