#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 1024
typedef char ElemType;
typedef struct
{
	ElemType data[MAXSIZE];
	int length;
}SqList;

void CreateList(SqList*& L);
void DestroyList(SqList*& L);

//初始化条件：顺序线性表L已存在
void ClearList(SqList*& L);

void ListInsert(SqList*& L, int i, char e);

void DispList(SqList* L);

int ListLength(SqList* L);

bool ListEmpty(SqList* L);

void DispElem(SqList* L, int i);
void GetElem(SqList* L, int i, ElemType* e);

//void LocatedElem(SqList* L, char a, int& e);
int LocatedElem(SqList* L, ElemType e);

void DeleteElem(SqList*& L, int i);