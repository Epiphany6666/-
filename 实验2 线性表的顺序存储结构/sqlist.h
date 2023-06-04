#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#define max 10
typedef char elemtype;

typedef struct Node
{
	elemtype data[max];

	int length;
}linklist;