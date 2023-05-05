#include"bitree.h"
int main()
{
	BTNode* b;
	char pre[] = "ABDGCEF";
	char in[] = "DGBAECF";
	char post[] = "GDBEFCA";
	int n = strlen(pre);
	printf("由先序序列和中序序列构造二叉树：\n");
	b = CreateBT1(pre, in, n);
	DispBT(b);
	printf("\n");
	printf("由中序序列和后序序列构造二叉树：\n");
	b = CreateBT2(in, post, n);
	DispBT(b);
	printf("\n");
	return 0;
}