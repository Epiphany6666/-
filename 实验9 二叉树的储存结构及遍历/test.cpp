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
		printf("H节点的左孩子值为%c\n", t->data);
	}
	if (e->rchild != NULL) {
		BTNode* t = RchildNode(e);
		printf("C节点的右孩子值为%c\n", t->data);
	}
	int h = BTHeight(b);
	printf("b树的高度为：%d\n", h);
	printf("二叉树的总结点个数为：%d\n", (int)pow(2, h) - 1);
	PreOrder(b);
	printf("\n");
	InOrder(b);
	printf("\n");
	PostOrder(b);
	printf("\n");
	DispLeaf(b);
	printf("\n");

	char c1 = '0';
	printf("请输入想要查询层次的结点:>");
	scanf("%c",&c1);
	DispBTree(FindNode(b,c1));
	printf("\n");

	DestroyBTree(b);
	return 0;
}