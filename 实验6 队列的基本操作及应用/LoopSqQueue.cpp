#include<stdio.h>
#include<malloc.h>
#define Max 1024
typedef int ElemType;
typedef struct
{
	ElemType data[Max];
	int front,rear;
}SqQueue;

void InitQueue(SqQueue *&q)
{
	q = (SqQueue*)malloc(sizeof(SqQueue));
	q->front = q ->rear = 0;
}

bool QueueEmpty(SqQueue *q)
{
	return (q->front == q->rear);
}

void enQueue(SqQueue *&q,ElemType e)
{
	if((q->rear+1)%Max == q->front)
	{
		return;
	}
	q->rear = (q->rear+1)%Max;
	q->data[q->rear] = e;
}

void deQueue(SqQueue *&q,ElemType &e)
{
	if(q->front == q->rear)
	{
		return;
	}
	q->front = (q->front+1)%Max;
	e = q->data[q->front];
}

int Count(SqQueue *q)
{
	return (q->rear-q->front+Max)%Max;
}

void DestroyQueue(SqQueue *&q)
{
	free(q);
}
