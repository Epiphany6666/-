#include"LoopSqQueue.cpp"
int main()
{
	SqQueue *q;
	ElemType e;
	int i,j;
	InitQueue(q);
	
	if(QueueEmpty(q))
		printf("qΪ�ն���\n");
	else
		printf("q��Ϊ�ն���\n");
		
	enQueue(q,'a');
	enQueue(q,'b');
	enQueue(q,'c');
	deQueue(q,e);
	printf("������Ԫ��Ϊ��%c \n",e);
	
	printf("�ö��г���Ϊ��%d\n",Count(q));
	enQueue(q,'d');
	enQueue(q,'e');
	enQueue(q,'f');
	printf("�ö��г���Ϊ��%d\n",Count(q));
	printf("�ö�������Ϊ��");
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




