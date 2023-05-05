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

//创建二叉树
void CreateBT(BTNode*& b, char *str);

//打印二叉树
void DispBT(BTNode* b);

//线索化二叉树
BTNode* pre = NULL;
void Tread(BTNode*& b);

//中序线索化二叉树
BTNode* CreateTread(BTNode*& b);

//遍历线索化二叉树
void ThInOrder(BTNode* b);