#include"SqList.h"
void CreateList(SqList*& L)//InitList
{
	L = (SqList*)malloc(sizeof(SqList));
	L->length = 0;
}

void InsertList(SqList*& L, int i, ElemType e)
{
	if (L->length == MAX)
		return;
	if (i <1 || i > L->length + 1)
		return;
	int j = 0;
	i--;
	for (j = L->length - 1; j >= i; j--)
	{
		L->data[j + 1] = L->data[j];
	}
	L->data[i] = e;
	L->length++;
}

void DispList(SqList* L)
{
	int i = 0;
	for (i = 0; i < L->length; i++)
	{
		printf("%2c", L->data[i]);
	}
	printf("\n");
}

bool EmptyList(SqList* L)
{
	return L->length == 0;
}

void FindElem(SqList* L, int i, ElemType* e)//GetElem
{
	if (L->length == 0 || i < 1 || i > L->length)
		return;
	i--;
	*e = L->data[i];
}

int LocateElem(SqList* L, ElemType e)
{
	int i = 0;
	if (L->length == 0)
		return 0;
	for (i = 0; i < L->length; i++)
	{
		if (L->data[i] == e)
		{
			break;
		}
	}
	if (i >= L->length)
		return 0;
	//return i;
	return i + 1;
}

void DeleteList(SqList* L, int i, ElemType* e)
{
	int j = 0;
	if (L->length == 0)
		return;
	if (i < 1 || i > L->length)
	{
		return;
	}
	i--;
	*e = L->data[i];
	for (j = i; j < L->length - 1; j++)
	{
		L->data[j] = L->data[j + 1];
	}
	L->length--;
}

void DestroyList(SqList*& L)
{
	free(L);
}