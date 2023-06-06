#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef char ElemType;
#define MAX 100

typedef struct
{
	ElemType data[100];
	int length;
}SqList;

void CreateList(SqList*& L);

void InsertList(SqList*& L, int i, ElemType e);

void DispList(SqList* L);

bool EmptyList(SqList* L);

void FindElem(SqList* L, int i, ElemType* e);

int LocateElem(SqList* L, ElemType e);

void DeleteList(SqList* L, int i, ElemType* e);

void DestroyList(SqList*& L);