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

//��ʼ��ջ
void InitStack(SqStack*& q);

//����ջ
void DestroyStack(SqStack*& q);

//�ж�ջ�Ƿ�Ϊ��
bool EmptyStack(SqStack* q);

//��ջ
bool Push(SqStack*& q, ElemType e);

//��ջ
bool Pop(SqStack*& q, ElemType& e);

//ȡջ��Ԫ��
bool GetTop(SqStack* q, ElemType& e);

//��
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