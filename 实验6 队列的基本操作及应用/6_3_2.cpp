#include"LinkQueue.cpp"
//��ʽ���� 
bool exist(LinkQuNode *q,ElemType e)
{
	DataNode *p;
	p = q->front;
	while(p)
	{
		if(p->data == e)
		{
			return 1;
		}
		p = p->next;
	} 
	return 0;
}
int main()
{
	int a,b,c,i;
	int flag = 1; 
	ElemType e;
	LinkQuNode *q;
	DataNode *p;
	InitQueue(q);
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
						break;
				
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
			printf("����%d����\n",e);
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
			printf("�ŶӲ����У�\n");
			while(p)
			{
				printf("%d ",p->data);
				p=p->next;
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
				while(q->front)
				{
					deQueue(q,e);
					printf("%d ",e);
				}
				printf("\n");
			} 
			flag = 0;
			DestroyQueue(q);
			break;
		case 5://�°� 
			if(p)
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
