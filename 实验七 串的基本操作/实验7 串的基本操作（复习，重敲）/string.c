#define _CRT_SECURE_NO_WARNINGS
#include"string.h"
//�ַ����ĳ�ʼ��
void InitString(SqString* q)
{
	q->length = 0;
}

//���ַ�������
int LengthString(SqString q)
{
	return  q.length;
}

//���ַ���str��ֵ��t
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

//��ӡ�ַ���q
void DispString(SqString q)
{
	int i = 0;
	for (i = 0; i < q.length; i++)
	{
		printf("%c", q.data[i]);
	}
	printf("\n");
}

//�����Ӵ�t
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
	//p.length += t.length;�����������Ҫ
	for (i = n-1; i < q->length; i++)
	{
		p.data[i + t.length] = q->data[i];//+t.length,������i
	}
	p.length = q->length + t.length;
	return p;
}

//ɾ���Ӵ�
SqString DeleteString(SqString* q, int n, int m)
{
	int i;
	SqString p;
	if (n<1 || n > q->length || m > q->length)
		return *q;
	for (i = 0; i < n -1; i++)//����Ҳһ����n - 1
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

//����������
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