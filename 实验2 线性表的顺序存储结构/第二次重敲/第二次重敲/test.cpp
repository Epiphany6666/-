#include"SqList.h"
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
int main()
{
	SqList* L;
	ElemType e;
	//(1)��ʼ��˳���L
	CreateList(L);
	//(2)���β��� a, b, c, d, e Ԫ��
	ListInsert(L, 1, 'a');
	ListInsert(L, 1, 'b');
	ListInsert(L, 1, 'c');
	ListInsert(L, 1, 'd');

	//(3) ���˳���
	DispList(L);
	//(4) ���˳���ĳ���
	printf("˳���ĳ���Ϊ��%d\n", ListLength(L));
	//(5)�ж�˳���L�Ƿ�ǿ�
	if (ListEmpty(L) == false)
	{
		printf("��˳���Ϊ��\n");
	}
	else
	{
		printf("������Ϊ��\n");
	}
	//(6) ���˳���L�ĵ�����Ԫ��,��e
	//DispElem(L, 1);
	GetElem(L, 1, &e);
	//(7)���Ԫ��a��λ��
	LocatedElem(L, 'e');
	printf("%c��λ��Ϊ%d\n", 'e', e);
	//(9)ɾ��˳����еĵ� 3 ��Ԫ�أ������˳���
	DeleteElem(L, 1);
	DispList(L);
	return 0;
}