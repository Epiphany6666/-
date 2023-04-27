#include"LinkQueue.cpp"
int main()
{
	LinkQuNode *q;
	ElemType e;
	int s;
	InitQueue(q);
	if(QueueEmpty(q))
	{
		printf("该队列为空\n");
	}
	else
	{
		printf("该队列不为空\n");
	}
	enQueue(q,'a');
	enQueue(q,'b');
	enQueue(q,'c');
	deQueue(q,e);
	printf("删除的元素为：%c\n",e);
	enQueue(q,'d');
	enQueue(q,'e');
	enQueue(q,'f');
	printf("该队列为：") ;
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
