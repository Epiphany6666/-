#include"LoopSqQueue.cpp"
int main()
{
	SqQueue *q;
	ElemType e;
	int i,j;
	InitQueue(q);
	
	if(QueueEmpty(q))
		printf("q为空队列\n");
	else
		printf("q不为空队列\n");
		
	enQueue(q,'a');
	enQueue(q,'b');
	enQueue(q,'c');
	deQueue(q,e);
	printf("出队列元素为：%c \n",e);
	
	printf("该队列长度为：%d\n",Count(q));
	enQueue(q,'d');
	enQueue(q,'e');
	enQueue(q,'f');
	printf("该队列长度为：%d\n",Count(q));
	printf("该队列序列为：");
	j = Count(q);
	for(i = 0;i < j;i++)
	{
	deQueue(q,e);
	printf("%c ",e);	
	}
	printf("\n");
	DestroyQueue(q);
	return 0;
}




