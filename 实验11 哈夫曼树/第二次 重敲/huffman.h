#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

#define N 8

#define M 2 * N - 1

typedef struct
{
    int data;
    int parent;
    int lchild;
    int rchild;
    int weight;
}HTNode;

typedef struct
{
    char data[N];
    int start;
}HCd;

int min(HTNode ht[], int i);

void select(HTNode ht[], int i);

void CreateHT(HTNode ht[]);

void CreateHcd(HTNode ht[], HCd hcd[]);

void DispHcd(HCd hcd[]);