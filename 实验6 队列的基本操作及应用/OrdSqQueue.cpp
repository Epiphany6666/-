#include<stdio.h>
#include<malloc.h>
#define Max 1024
typedef char ElemType;
//定义队列 
typedef struct
{
	ElemType data[Max];
	int front,rear;
}SqQueue;

// 
void InitQueue(SqQueue *&q)
{
	q = (SqQueue *)malloc(sizeof(SqQueue));
	q->front = q->rear = -1;
}

bool QueueEmpty(SqQueue *q)
{
	return (q->front == q->rear);
}

void enQueue(SqQueue *&q,ElemType e)
{
	if(q->rear == Max - 1)
		return;
	q->rear++;
	q->data[q->rear] = e;
}

void deQueue(SqQueue *&q,ElemType &e)
{
	if(q->front == q->rear)
	{
		return;
	}
	q->front++;
	e = q->data[q->front];
}

int Count(SqQueue *q)
{
	return (q->rear-q->front);
}

void DestroyQueue(SqQueue *&q)
{
	free(q);
}
