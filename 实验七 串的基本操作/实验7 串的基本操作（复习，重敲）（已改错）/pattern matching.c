#define _CRT_SECURE_NO_WARNINGS
#include"String.h"
//BF�㷨
int index_BF(SqString s1, SqString s2)
{
	int i = 0, j = 0;
	while (i < s1.length && j < s2.length)//forѭ������õģ���û�в���whileѭ��//i < s1.length!!!
	{
		if (s1.data[i] == s2.data[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}
	if (j >= s2.length)
		return i - j;
	else
		return -1;
}

//��next[j]ֵ
void GetNext(SqString s2, int* next)
{
	int i = 0;//i��ʾ��׺
	int k = -1;//k��ʾǰ׺
	next[0] = -1;
	while (i < s2.length - 1)//����Ҫ-1
	{
		if (k == -1 || s2.data[i] == s2.data[k])
		{
			i++;
			k++;
			next[i] = k;
		}
		else
		{
			k = next[k];
		}
	}
}

//��nextval[j]ֵ
void GetNextval(SqString s2, int* nextval)//ע��������int
{
	int i = 0;
	int k = -1;
	nextval[0] = -1;
	while (i < s2.length)
	{
		if (k == -1 || s2.data[i] == s2.data[k])
		{
			i++;
			k++;
			if (s2.data[i] != s2.data[k])
			{
				nextval[i] = k;
			}
			else
			{
				nextval[i] = nextval[k];
			}
		}
		/*if (k == -1)
		{
			i++;
			k++;
			if (s2.data[i] != s2.data[k])
			{
				nextval[i] = k;
			}
			else
			{
				nextval[i] = nextval[k];
			}
		}
		else if (s2.data[i] == s2.data[k])
		{
			i++;
			k++;
			if (s2.data[i] != s2.data[k])
			{
				nextval[i] = k;
			}
			else
			{
				nextval[i] = nextval[k];
			}
		}*/
		else
		{
			k = nextval[k];
		}
	}
}

//KMP�㷨
int index_KMP(SqString s, SqString t)
{
	int i = 0, j = 0;
	int next[MaxSize] = { 0 };
	GetNext(t, next);
	while (i < s.length && j < t.length)
	{
		if (j == -1 || s.data[i] == t.data[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}
	if (j >= t.length)
	{
		return i - t.length;
	}
	else
	{
		return -1;
	}
}

//�Ľ���KMP�㷨
int index_KMP1(SqString s, SqString t)
{
	int i = 0;
	int j = 0;
	int nextval[MaxSize] = { 0 };
	GetNextval(t, nextval);
	while (i < s.length && j < t.length)
	{
		if (j == -1 || s.data[i] == t.data[j])
		{
			i++;
			j++;
		}
		else
		{
			j = nextval[j];
		}
	}
	if (j >= t.length)
	{
		return i - j;
	}
	else
	{
		return -1;
	}
}