#include"bitree.h"
BTNode* CreateBT1(char* pre, char* in, int n)
{
	BTNode* b;
	char* p;
	int k;
	if (n <= 0)
	{
		return NULL;
	}
	b = (BTNode*)malloc(sizeof(BTNode));
	b->data = *pre;
	for (p = in; p < in + n; p++)
	{
		if (*p == *pre)
		{
			break;
		}
	}
	k = p - in;
	b->lchild = CreateBT1(pre + 1, in, k);
	b->rchild = CreateBT1(pre + k + 1, p + 1, n - k - 1);
	return b;
}

BTNode* CreateBT2(char* in, char* post, int n)
{
	BTNode* b;
	char r, * p;
	int k;
	if (n <= 0)
	{
		return NULL;
	}
	r = *(post + n - 1);
	b = (BTNode*)malloc(sizeof(BTNode));
	b->data = r;
	for (p = in; p < in + n; p++)
	{
		if (*p == r)
		{
			break;
		}
	}
	k = p - in;
	b->lchild = CreateBT2(in, post, k);
	b->rchild = CreateBT2(p + 1, post + k, n - k - 1);
	return b;
}

void DispBT(BTNode* b)
{
	if (b != NULL)
	{
		printf("%c", b->data);
		if (b->lchild != NULL || b->rchild != NULL)
		{
			printf("(");
			DispBT(b->lchild);
			if (b->rchild != NULL)
			{
				printf(",");
			}
			DispBT(b->rchild);
			printf(")");
		}
	}
}