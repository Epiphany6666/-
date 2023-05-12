#include"BTree.h"
//(1)����������
//
//(2)���������
//
//(3)���H�������Һ��ӽ��ֵ
//
//(4)������b�ĸ߶�
//
//(5)���������ܽ����
//
//(6)�����������������
//
//(7)�����������������
//
//(8)�����������������
//
//(9)������е�Ҷ�ӽ��
//
//(10)�Ӽ�������һ����㣬�������Ĳ�Ρ�
//
//(11)���ٶ�����

int main()
{
	//(1)����������
	char str[MaxSize] = "A(B(D(,G)),C(E,F))";
	BTNode* b;
	CreateBT(b, str);
	//(2)���������
	DispBT(b);
	printf("\n");
	//(3)���H�������Һ��ӽ��ֵ
	BTNode* t = FindNode(b, 'C');
	if (t != NULL)
	{
		DispChild(t);
	}
	else
	{
		printf("û���ҵ�%c���\n", 'E');
	}
	//(4)������b�ĸ߶�
	int height = BTHeight(b);
	printf("������b�ĸ߶�Ϊ��%d\n", height);
	//(5)���������ܽ����
	int nodenum = NodeNum(b);
	printf("�������ܽ����Ϊ��%d\n", nodenum);
	//(6)�����������������
	PreOrder0(b);
	printf("\n");
	PreOrder1(b);
	PreOrder2(b);
	InOrder(b);
	PostOrder(b);

	return 0;
}