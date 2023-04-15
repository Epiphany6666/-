#pragma once
#define MaxSize 1024
#include<string.h>
typedef struct
{
	char data[MaxSize];
	int length;
}SqString;

//�ַ����ĳ�ʼ��
void InitString(SqString* q);

//���ַ�������
int LengthString(SqString q);

//���ַ���str��ֵ��t
void AssertString(char* str, SqString* t);

//��ӡ�ַ���q
void DispString(SqString q);

//�����Ӵ�t
SqString InsertString(SqString* q,int n, SqString t);

//ɾ���Ӵ�,��n��ʼ��m��Ԫ��
SqString DeleteString(SqString* q, int n, int m); 

//����������
SqString Connect(SqString q, SqString t);

//BF�㷨
int index_BF(SqString s1, SqString s2);

//��next[j]ֵ
void GetNext(SqString s2, int* next);

//��nextval[j]ֵ
void GetNextval(SqString s2, int* nextval);

//KMP�㷨
int index_KMP(SqString s, SqString t);

//�Ľ���KMP�㷨
int index_KMP1(SqString s, SqString t);