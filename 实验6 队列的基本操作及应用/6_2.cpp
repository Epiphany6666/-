#include"LinkQueue.cpp"
int main()
{
	LinkQuNode *q;
	ElemType e;
	int s;
	InitQueue(q);
	if(QueueEmpty(q))
	{
		printf("�ö���Ϊ��\n");
	}
	else
	{
		printf("�ö��в�Ϊ��\n");
	}
	enQueue(q,'a');
	enQueue(q,'b');
	enQueue(q,'c');
	deQueue(q,e);
	printf("ɾ����Ԫ��Ϊ��%c\n",e);
	enQueue(q,'d');
	enQueue(q,'e');
	enQueue(q,'f');
	printf("�ö���Ϊ��") ;
	while(q->front != q->rear)
	{
		deQueue(q,e);
		printf("%c ",e);
	}
	deQueue(q,e);
	printf("%c ",e);
	printf("\n");
	DestroyQueue(q);
	return 0;
}
