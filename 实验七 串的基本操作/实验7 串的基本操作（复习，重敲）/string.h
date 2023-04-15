#pragma once
#define MaxSize 1024
#include<string.h>
typedef struct
{
	char data[MaxSize];
	int length;
}SqString;

//字符串的初始化
void InitString(SqString* q);

//求字符串长度
int LengthString(SqString q);

//将字符串str赋值给t
void AssertString(char* str, SqString* t);

//打印字符串q
void DispString(SqString q);

//插入子串t
SqString InsertString(SqString* q,int n, SqString t);

//删除子串,从n开始的m个元素
SqString DeleteString(SqString* q, int n, int m); 

//链接两个串
SqString Connect(SqString q, SqString t);

//BF算法
int index_BF(SqString s1, SqString s2);

//求next[j]值
void GetNext(SqString s2, int* next);

//求nextval[j]值
void GetNextval(SqString s2, int* nextval);

//KMP算法
int index_KMP(SqString s, SqString t);

//改进的KMP算法
int index_KMP1(SqString s, SqString t);