//(1)��ʼ��˳���L
//(2)���β��� a, b, c, d, e Ԫ��
//(3) ���˳���
//(4) ���˳���ĳ���
//(5)�ж�˳���L�Ƿ�ǿ�
//(6) ���˳���L�ĵ�����Ԫ��
//(7)���Ԫ��a��λ��
//(8)�ڵ�4��Ԫ��λ���ϲ���f Ԫ�أ�Ȼ�����˳���
//(9)ɾ��˳����еĵ� 3 ��Ԫ�أ������˳���
//(10)�ͷ�˳���
#include"SqList.h"
int main()
{
	//(1)��ʼ��˳���L
	SqList* L;
	CreateList(L);
	//(2)���β��� a, b, c, d, e Ԫ��
	InsertList(L, 1, 'a');
	InsertList(L, 1, 'b');
	InsertList(L, 1, 'c');
	InsertList(L, 1, 'd');
	InsertList(L, 1, 'e');
	//(3) ���˳���
	DispList(L);
	printf("\n");
	//(5)�ж�˳���L�Ƿ�ǿ�
	if (EmptyList(L) == true)
	{
		printf("L����Ϊ��\n");
	}
	else
	{
		printf("����Ϊ��\n");
	}
	//(6) ���˳���L�ĵ�����Ԫ��
	ElemType e;
	FindElem(L, 3, &e);
	printf("������Ԫ��Ϊ��%c\n", e);
	//(7)���Ԫ��a��λ��
	int ret = LocateElem(L, 'a');
	if (ret != 0)
	{
		printf("%c��λ��Ϊ%d\n", 'a', ret);
	}
	//(8)�ڵ�4��Ԫ��λ���ϲ���f Ԫ�أ�Ȼ�����˳���
	InsertList(L, 4, 'f');
	DispList(L);
	printf("\n"); 
	//(9)ɾ��˳����еĵ� 3 ��Ԫ�أ������˳���
	DeleteList(L, 3, &e);
	printf("ɾ����Ԫ��Ϊ��%c\n", e);
	DispList(L);
	//(10)�ͷ�˳���
	DestroyList(L);
	return 0;
}