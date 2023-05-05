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

//由先序序列和中序序列构造二叉树
BTNode* CreateBT1(char* pre, char* in, int n);

//由中序序列和后序序列构造二叉树
BTNode* CreateBT2(char* in, char* post, int n);

//输出树
void DispBT(BTNode* b);