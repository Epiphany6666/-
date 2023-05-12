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

//初始化栈
void InitStack(SqStack &q);

//销毁栈
void DestroyStack(SqStack& q);

//判断栈是否为空
bool EmptyStack(SqStack q);

//进栈
bool Push(SqStack& q, ElemType e);

//出栈
bool Pop(SqStack& q, ElemType &e);

//取栈顶元素
bool GetTop(SqStack q, ElemType& e);