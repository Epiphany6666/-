#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef  struct Node
{
	int number;
	int password;
	struct Node* next;
}linklist;


void CreateList(linklist*& L,int n)
{
	int i;
	linklist* p, * q;
	printf("请依次输入各位的密码:>\n");
	for (i = 1; i <= n; i++)
	{
		if (i == 1)
		{
			L = p = (linklist*)malloc(sizeof(linklist));
			if (!L)
				return;
		}
		else
		{
			q = (linklist*)malloc(sizeof(linklist));
			if (!q)
				return;
			p->next = q;
			p = q;
		}
		scanf("%d", &(p->password));
		p->number = i;
	}
	p->next = L;
}

void DeleteList(linklist*& L, int m, int n)
{
	linklist* p, * q;
	int i, j;
	p = L;
	for (j = 1; j < n; j++)
	{
		for (i = 1; i < m; i++, p = p->next)
			m = p->password;
		printf("%d->", p->number);
		p->number = p->next->number;
		p->password = p->next->password;
		q = p->next;
		p->next = p->next->next;
		free(q);
	}
	printf("%d", p->number);
	free(p);
}
