#include"bitree.h"
int main()
{
	BTNode* b;
	char pre[] = "ABDGCEF";
	char in[] = "DGBAECF";
	char post[] = "GDBEFCA";
	int n = strlen(pre);
	printf("���������к��������й����������\n");
	b = CreateBT1(pre, in, n);
	DispBT(b);
	printf("\n");
	printf("���������кͺ������й����������\n");
	b = CreateBT2(in, post, n);
	DispBT(b);
	printf("\n");
	return 0;
}