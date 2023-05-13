#include"SqStack.h"
void InitStack(SqStack& q)
{
	q.top = -1;
}

void DestroyStack(SqStack& q)
{
	q.top = -1;
	free(q.data);
}

bool EmptyStack(SqStack q)
{
	/*if (q.top == -1)
	{
		return true;
	}
	else
	{
		return false;
	}*/
	return q.top == -1;
}

bool Push(SqStack& q, ElemType e)//Ãû×Ö¶¼Ð´·´
{
	if (q.top == MaxSize - 1)
	{
		return false;
	}
	/*q.top++;
	q.data[q.top] = e;*/
	q.data[++q.top] = e;
	return true;
}

bool Pop(SqStack& q, ElemType& e)
{
	if (q.top == -1)
	{
		return false;
	}
	/*e = q.data[q.top];
	q.top--;*/
	e = q.data[q.top--];
	return true;
}

bool GetTop(SqStack q, ElemType& e)
{
	//if (EmptyStack)
	if (EmptyStack(q))
	{
		return false;
	}
	e = q.data[q.top];
	return true;
}