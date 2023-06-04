#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#define max 10
typedef char elemtype;

typedef struct Node
{
	elemtype data[max];

	int length;
}linklist;

void initlist(linklist *&L)

{

	L = (linklist*)malloc(sizeof(linklist));

	L->length = 0;

}

void insertlist(linklist*& L, int i, elemtype e)

{

	int j;

	if (L->length == max)

	{

		return;

	}

	if (i<1 || i > L->length + 1)

	{

		return;

	}

	i--;

	for (j = L->length - 1; j > i - 1; j--)

	{

		L->data[j + 1] = L->data[j];

	}

	L->data[i] = e;

	L->length++;

}



void displist(linklist* L)

{

	int i;

	for (i = 0; i < L->length; i++)

	{
		printf("%c ", L->data[i]);
	}
	printf("\n");
}

void listempty(linklist* L)

{
	if (L == NULL)
	{
		printf("LΪ��˳���");
	}
	else
	{
		printf("L��Ϊ��˳���");
	}
	printf("\n");
}



void getlist(linklist* L, int i, elemtype* e)

{
	*e = L->data[i - 1];
	printf("��%d��Ԫ��Ϊ%c\n", i, L->data[i - 1]);
}



void dispposition(linklist* L, char j)

{

	elemtype i;

	for (i = 0; i < L->length; i++)

	{

		if (L->data[i] == j)

		{

			printf("%c��λ���ǵ�%dλ", j, i + 1);

			printf("\n");

			break;

		}
	}
}



void deletelist(linklist* L, int i, elemtype e)

{

	int j;

	e = L->data[i - 1];

	for (j = i; j < L->length; j++)

	{
		L->data[j - 1] = L->data[j];
	}
	L->length--;
}

