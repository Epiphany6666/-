#define _CRT_SECURE_NO_WARNINGS
#pragma   once  
#define MaxSize 1024
#include<stdio.h>
typedef char ElemType;

ElemType N1 = ' ';


typedef ElemType SqBiTree[MaxSize];

void InitBiTree(SqBiTree& b);

void CreateBiTree(SqBiTree& b, ElemType* t);

ElemType Parent(SqBiTree b, ElemType t);

ElemType lclild(SqBiTree b, ElemType t);

ElemType rchild(SqBiTree b, ElemType t);