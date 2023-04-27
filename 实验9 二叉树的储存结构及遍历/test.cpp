#include"btree.h"
int main()
{
	BTNode* b;
	char str[MaxSize] = "A(B(D(,G),C(E,F))";
	createTree(b, str);
	DispBTree(b);
	printf("\n");
	BTNode* e = FindNode(b, 'C');
	if (e->lchild != NULL) {
		BTNode* t = LchildNode(e);
		printf("H�ڵ������ֵΪ%c\n", t->data);
	}
	if (e->rchild != NULL) {
		BTNode* t = RchildNode(e);
		printf("C�ڵ���Һ���ֵΪ%c\n", t->data);
	}
	int h = BTHeight(b);
	printf("b���ĸ߶�Ϊ��%d\n", h);
	printf("���������ܽ�����Ϊ��%d\n", (int)pow(2, h) - 1);
	PreOrder(b);
	printf("\n");
	InOrder(b);
	printf("\n");
	PostOrder(b);
	printf("\n");
	DispLeaf(b);
	printf("\n");

	char c1 = '0';
	printf("��������Ҫ��ѯ��εĽ��:>");
	scanf("%c",&c1);
	DispBTree(FindNode(b,c1));
	printf("\n");

	DestroyBTree(b);
	return 0;
}