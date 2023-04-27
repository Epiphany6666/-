#include"Sqtree.h"
extern ElemType N1;

int main() {
	SqBiTree b;
	ElemType t[MaxSize] = "ABCDE#F##GH##I#";
	//初始化顺序二叉树
	InitBiTree(b);
	//生成二叉树
	CreateBiTree(b,t);

	//求双亲结点
	printf("请输入一个结点:>");
	ElemType e, i;
	scanf("%c", &e);
	printf("%c的双亲结点为：%c\n",e, Parent(b, e));

	//求左孩子
	i = lclild(b, e);
	if (i != '#' && i != N1) {
		printf("%c的左孩子是%c\n", e, i);
	}
	else {
		printf("%c无左孩子\n",e);
	}

	//求右孩子
	i = rchild(b, e);
	if (i != '#' && i != N1) {
		printf("%c的右孩子是%c\n", e, i);
	}
	else {
		printf("%c无右孩子\n",e);
	}
	return 0;
}