
#include"LoopSqQueue.cpp"
//���ζ��� 
bool exist(SqQueue *q,ElemType e)//�ж��Ƿ����ظ��Ĳ����� 
{
	int i, j = Count(q),p = q->front;
	for(i = 0;i<j;i++)
	{
		if(q->data[++p] == e)
		{
			return 1;
		}
	} 
	return 0;
}
int main()
{
	int a,b,c,i;
	int flag = 1; 
	ElemType e;
	SqQueue *q;
	InitQueue(q);
	int p;
	while(flag)
	{
		printf("������������ţ�\n");
	printf("*****1.�Ŷ�-------�����ŶӲ��˵Ĳ����ţ����뵽�������ж�����***********\n");
	printf("*****2.����-------�����ŶӶ�������ǰ��Ĳ��˾��������Ӷ�����ɾ��\n");
	printf("**3���鿴�Ŷ�------�Ӷ��׵���β�г����е��ŶӲ��˵Ĳ�����***********\n");
	printf("*4�������Ŷӣ��������ξ���------�Ӷ��׵���β�г����е��ŶӲ��˵Ĳ����ţ����˳�����**\n");
	printf("*******************5���°�------�˳����С�**************************\n");
	scanf("%d",&a);
	switch(a)
	{
		case 1://�Ŷ� 
			printf("������ò��˵Ĳ����ţ�\n"); 
			while(1)
			{
				scanf("%d",&b);
				if(exist(q,b))
				{
					printf("����Ĳ������ظ�������������:\n");
				}
				else
				{
					break;
				}
			}
			enQueue(q,b);
			break;
		case 2://���� 
			if(QueueEmpty(q))
			{
				printf("û���ŶӵĲ���\n");
			}
			else
			{
			deQueue(q,e);
			printf("���ﲡ����Ϊ��%d\n",e);
			}
			
			break;
		case 3://�鿴�Ŷ� 
			if(QueueEmpty(q))
			{
				printf("û���ŶӵĲ���\n");
			}
			else
			{
			p = q->front;
			c = Count(q);
			printf("�ŶӲ����У�\n");
			for(i = 0;i<c;i++)
			{
				printf("%d ",q->data[p++]);
			}
			printf("\n");
			}
			break; 
			
		case 4://�����Ŷ� ,���µ�һ�ξ��� 
			if(QueueEmpty(q))
			{
				printf("û���ŶӵĲ���\n");
			}
			else
			{
				printf("���˰����´�����\n");
			c = Count(q);
			for(i = 0;i<c;i++)
			{
				deQueue(q,e);
				printf("%d ",e);
			}
			printf("\n");
			flag = 0;
			DestroyQueue(q);
			} 
			break;
		case 5://�°� 
			if(Count(q))
			{
				printf("���ŶӵĲ��������ҽ!\n");
			}
			flag = 0;
			DestroyQueue(q);
			break;
		default:
			printf("���벻�ԣ�����������\n");
			break;
	}
	}
	return 0;
}
