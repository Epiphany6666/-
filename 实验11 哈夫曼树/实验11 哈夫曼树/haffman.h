#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define N 8
#define M 2 * N - 1

typedef struct
{
	char data;
	int weight;
	int parent;
	int lchild;
	int rchild;
}HTNode;

typedef struct
{
	char hcd[N];
	int start;
}HcdNode;//HCode

void CreateHT(HTNode ht[]);

void Hcod(HTNode ht[], HcdNode hc[]);

void DispHcd(HTNode ht[], HcdNode hc[]);