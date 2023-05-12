#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MaxSize 1024
typedef char ElemType;


typedef struct
{
	ElemType data[MaxSize];
	int top;
}SqStack;

//��ʼ��ջ
void InitStack(SqStack &q);

//����ջ
void DestroyStack(SqStack& q);

//�ж�ջ�Ƿ�Ϊ��
bool EmptyStack(SqStack q);

//��ջ
bool Push(SqStack& q, ElemType e);

//��ջ
bool Pop(SqStack& q, ElemType &e);

//ȡջ��Ԫ��
bool GetTop(SqStack q, ElemType& e);