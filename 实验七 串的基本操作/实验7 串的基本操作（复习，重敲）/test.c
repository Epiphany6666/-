#define _CRT_SECURE_NO_WARNINGS
#include"string.h"
#include<stdio.h>
int main()
{
	SqString q, t;
	char str[] = "abcdefg";
	AssertString(str, &t);
	DispString(t);
	InitString(&q);
	printf("�ַ�������Ϊ��%d\n",LengthString(q));
	q = InsertString(&q, 1, t);
	DispString(q);
	q = DeleteString(&q, 1, 3);
	DispString(q);
	DispString(Connect(q, t));

	SqString s1, s2;
	InitString(&s1);
	InitString(&s2);
	int j = 0;
	int next[MaxSize], nextval[MaxSize];
	AssertString( "abcabcdabcdeabcedfabcdefg", &s1);
	AssertString( "abcdeabcdefab",&s2);
	printf("��s:");
	DispString(s1);
	printf("��s2��");
	DispString(s2);
	printf("��ƥ���㷨��\n");
	printf("t��s�е�λ�� = %d\n", index_BF(s1, s2));
	GetNext(s2, next);
	GetNextval(s2, nextval);
	printf("   j   ");
	for (j = 0; j < s2.length; j++)
	{
		printf("%4d", next[j]);
	}
	printf("\n");
	printf("  next  ");
	for (j = 0; j < s2.length; j++)
	{
		printf("%4d", next[j]);
	}
	printf("\n");
	printf("  nextval");
	for (j = 0; j < s2.length; j++)
	{
		printf("%4d", nextval);
	}
	printf("\n");
	printf("KMP�㷨��\n");
	printf("t��s���е�λ�� = %d\n", index_KMP(s1, s2));
	printf("\n");
	printf("�Ľ���KMP�㷨��\n");
	printf("t��s���е�λ�� = %d\n", index_KMP1(s1, s2));
	return 0;
}