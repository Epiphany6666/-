#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef  struct Node
{
	int number;
	int password;
	struct Node* next;
}linklist;

void CreateList(linklist* &L,int n);

void DeleteList(linklist*& L, int m, int n);