#include"BTree.h"
//(1)创建二叉树
//
//(2)输出二叉树
//
//(3)输出H结点的左右孩子结点值
//
//(4)二叉树b的高度
//
//(5)二叉树的总结点数
//
//(6)先序遍历二叉树序列
//
//(7)中序遍历二叉树序列
//
//(8)后序遍历二叉树序列
//
//(9)输出所有的叶子结点
//
//(10)从键盘输入一个结点，输出其结点的层次。
//
//(11)销毁二叉树

int main()
{
	//(1)创建二叉树
	char str[MaxSize] = "A(B(D(,G)),C(E,F))";
	BTNode* b;
	CreateBT(b, str);
	//(2)输出二叉树
	DispBT(b);
	printf("\n");
	//(3)输出H结点的左右孩子结点值
	BTNode* t = FindNode(b, 'C');
	if (t != NULL)
	{
		DispChild(t);
	}
	else
	{
		printf("没有找到%c结点\n", 'E');
	}
	//(4)二叉树b的高度
	int height = BTHeight(b);
	printf("二叉树b的高度为：%d\n", height);
	//(5)二叉树的总结点数
	int nodenum = NodeNum(b);
	printf("二叉树总结点数为：%d\n", nodenum);
	//(6)先序遍历二叉树序列
	PreOrder0(b);
	printf("\n");
	PreOrder1(b);
	PreOrder2(b);
	InOrder(b);
	PostOrder(b);

	return 0;
}