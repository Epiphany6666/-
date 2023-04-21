#define _CRT_SECURE_NO_WARNINGS
#include"String.h"
//BF算法
int index_BF(SqString s1, SqString s2)
{
	int i = 0, j = 0;
	while (i < s1.length && j < s2.length)//for循环是最常用的，但没有不用while循环//i < s1.length!!!
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

//求next[j]值
void GetNext(SqString s2, int* next)
{
	int i = 0;//i表示后缀
	int k = -1;//k表示前缀
	next[0] = -1;
	while (i < s2.length - 1)//这里要-1
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

//求nextval[j]值
void GetNextval(SqString s2, int* nextval)//注意这里是int
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

//KMP算法
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

//改进的KMP算法
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