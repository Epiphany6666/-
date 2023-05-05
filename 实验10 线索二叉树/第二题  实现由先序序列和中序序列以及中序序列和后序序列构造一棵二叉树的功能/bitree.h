#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MaxSize 1024

typedef char ElemType;

typedef struct node
{
	ElemType data;
	struct node* lchild;
	struct node* rchild;
}BTNode;

//���������к��������й��������
BTNode* CreateBT1(char* pre, char* in, int n);

//���������кͺ������й��������
BTNode* CreateBT2(char* in, char* post, int n);

//�����
void DispBT(BTNode* b);