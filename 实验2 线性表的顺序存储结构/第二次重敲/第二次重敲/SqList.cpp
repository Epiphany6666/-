#include"SqList.h"
void CreateList(SqList*& L)
{
	L = (SqList*)malloc(sizeof(SqList));
	L->length = 0;
}

void DestroyList(SqList*& L)
{
	free(L);
}

void ClearList(SqList*& L)
{
	L->length = 0;
}

void ListInsert(SqList*& L, int i, char e)//在第i个位置插入e
{
	//if (L->length >= MAXSIZE)
	if (L->length == MAXSIZE)
	{
		return;
	}
	//if (i <= 0 && i >= MAXSIZE - 1)
	if (i < 1 || i > L->length + 1)
	{
		return;
	}
	//int k = 0;
	i--;//将顺序表逻辑序号转化为顺序符号
	//L->length++;
	/*for (k = L->length - 2; k >= i ; k++)
	{
		L->data[k + 1] = L->data[k];
	}*/
	int j = 0;
	//for (j = L->length; j > i; j++)
	for (j = L->length; j > i; j--)
	{
		L->data[j] = L->data[j - 1];
	}
	L->data[i] = e;
	L->length++;
}

void DispList(SqList* L)
{
	int i = 0; 
	for (i = 0; i < L->length; i++)
	{
		printf("%c", L->data[i]);
	}
	printf("\n");
}

int ListLength(SqList* L)
{
	return L->length;
}

bool ListEmpty(SqList* L)
{
	//bool flag = true;
	if (L->length == 0)
	{
		//flag = false;
		return true;
	}
	//return flag;
	return false;
}

void DispElem(SqList* L, int i)//GetElem
{
	/*if (i > 0 && i <= L->length)
	{
		printf("第%d个元素为;%c\n", i, L->data[i - 1]);
	}
	else
	{
		printf("%d上的元素不存在\n", i);
	}*/
	if (L->length == 0 || i < 1 || i > L->length)
		return;

}

void GetElem(SqList* L, int i, ElemType* e)
{
	if (L->length == 0 || i > L->length)
	{
		return;
	}
	*e = L->data[i - 1];
}

int LocatedElem(SqList* L, ElemType e)
{
	int i = 0;
	if (L->length == 0)
	{
		return 0;
	}
	for (i = 0; i < L->length; i++)
	{
		if (L->data[i] == e)
		{
			//e = i + 1;
			break;
		}
	}
	if (i >= L->length)
		return 0;
	return i + 1;
}

//void DeleteElem(SqList*& L, int i)//ListDelete
//{
//	int j = 0;
//	i--;
//	for (j = i; j < L->length - 1; j++)
//	{
//		L->data[j] = L->data[j + 1];
//	}
//	L->length--;
//}

void ListDelete(SqList*& L, int i, ElemType* e)
{
	int j;
	if (L->length == 0)
		return;
	if (i < 1 || i > L->length + 1)
		return;
	i--;
	*e = L->data[i];
	for (j = i; j < L->length - 1; j++)
	{
		L->data[j] = L->data[j + 1];
	}
	L->length--;
}