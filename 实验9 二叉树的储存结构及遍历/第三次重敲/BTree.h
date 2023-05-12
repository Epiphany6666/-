#pragma once
#include<stdio.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#define MaxSize 1024
//typedef char ElemType;

typedef struct node
{
	char data;
	struct node* lchild;
	struct node* rchild;
}BTNode;

typedef BTNode* ElemType;


typedef struct
{
	ElemType data[MaxSize];
	int top;
}SqStack;

//初始化栈
void InitStack(SqStack*& q);

//销毁栈
void DestroyStack(SqStack*& q);

//判断栈是否为空
bool EmptyStack(SqStack* q);

//进栈
bool Push(SqStack*& q, ElemType e);

//出栈
bool Pop(SqStack*& q, ElemType& e);

//取栈顶元素
bool GetTop(SqStack* q, ElemType& e);

//树
void CreateBT(BTNode*& b, char* str);

void DispBT(BTNode* b);

BTNode* FindNode(BTNode* b, char e);

void DispChild(BTNode* t);

int BTHeight(BTNode* b);

int NodeNum(BTNode* b);

void PreOrder0(BTNode* b);

void PreOrder1(BTNode* b);

void PreOrder2(BTNode* b);

void InOrder(BTNode* b);

void PostOrder(BTNode* b);