#pragma once
#include<stdio.h>
#include<stdlib.h>

#define MaxSize 1024

typedef char ElemType;

typedef struct node
{
	ElemType data;
	int ltag, rtag;
	struct node* lchild;
	struct node* rchild;
}BTNode;

//����������
void CreateBT(BTNode*& b, char *str);

//��ӡ������
void DispBT(BTNode* b);

//������������
BTNode* pre = NULL;
void Tread(BTNode*& b);

//����������������
BTNode* CreateTread(BTNode*& b);

//����������������
void ThInOrder(BTNode* b);