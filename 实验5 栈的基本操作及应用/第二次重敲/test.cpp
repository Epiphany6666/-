#include"SqStack.h"
//��ʼ��ջ
//����ջ
//�ж�ջ�Ƿ�Ϊ��
//��ջ
//��ջ
//ȡջ��Ԫ��

int main()
{
	SqStack q;
	ElemType e;
	//��ʼ��ջ
	InitStack(q);
	//�ж�ջ�Ƿ�Ϊ��
	if (!EmptyStack(q))
	{
		printf("��Ϊ��\n");
	}
	//��ջ
	Push(q, 'a');
	Push(q, 'b');

	//��ջ
	Pop(q, e);
	printf("��ջԪ��Ϊ��%c\n", e);
	//ȡջ��Ԫ��
	GetTop(q, e);
	printf("ջ��Ԫ��Ϊ��%c\n", e);
	return 0;
}