#define _CRT_SECURE_NO_WARNINGS
#include"string.h"
//字符串的初始化
void InitString(SqString* q)
{
	q->length = 0;
}

//求字符串长度
int LengthString(SqString q)
{
	return  q.length;
}

//将字符串str赋值给t
void AssertString(char* str, SqString* t)//StrAssign
{
	/*int i = 0;
	for (i = 0; i < strlen(str); i++)
	{
		t->data[i] = str[i];
	}
	t->data[i] = '\0';*/
	strcpy(t->data, str);
	t->length = strlen(str);
}

//打印字符串q
void DispString(SqString q)
{
	int i = 0;
	for (i = 0; i < q.length; i++)
	{
		printf("%c", q.data[i]);
	}
	printf("\n");
}

//插入子串t
SqString InsertString(SqString* q, int n, SqString t)
{
	int i = 0;
	SqString p ;
	if (n<1 || i>q->length+1)//+1!!!
		return;
	for (i = 0; i < n-1; i++)//n-1
	{
		p.data[i] = q->data[i];
		
	}
	//p.length = n - 1;
	for (i = 0; i < t.length; i++)
	{
		p.data[n + i - 1] = t.data[i];
		
	}
	//p.length += t.length;这里根本不需要
	for (i = n-1; i < q->length; i++)
	{
		p.data[i + t.length] = q->data[i];//+t.length,后面是i
	}
	p.length = q->length + t.length;
	return p;
}

//删除子串
SqString DeleteString(SqString* q, int n, int m)
{
	int i;
	SqString p;
	if (n<1 || n > q->length || m > q->length)
		return *q;
	for (i = 0; i < n -1; i++)//这里也一样是n - 1
	{
		p.data[i] = q->data[i];
	}
	//p.length = n - 1;
	for (i = n - 1; i < q->length; i++)
	{
		p.data[i] = q->data[i + m ];
	}
	p.length = q->length - m;
	return p;
}

//链接两个串
SqString Connect(SqString q, SqString t)
{
	SqString p;
	int i = 0;
	for (i = 0; i < q.length; i++)
	{
		p.data[i] = q.data[i];
	}
	for (i = 0; i < t.length; i++)
	{
		p.data[i + q.length] = t.data[i];
	}
	p.length = q.length + t.length;
	return p;
}