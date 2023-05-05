#include"bitree.h"
extern BTNode* pre;
void CreateBT(BTNode*& b, char* str) {
	b = NULL;
	BTNode* St[MaxSize];
	int top = -1, k;
	BTNode* p = NULL;
	while (*str != '\0') {
		switch (*str) {
		case '(':
			top++;
			St[top] = p;
			k = 1;
			break;
		case ',':
			k = 2;
			break;
		case ')':
			top--;
			break;
		default:
			p = (BTNode*)malloc(sizeof(BTNode));
			p->data = *str;
			p->lchild = p->rchild = NULL;
			if (b == NULL) {
				b = p;
			}
			else {
				switch (k) {
				case 1:
					St[top]->lchild = p;
					break;
				case 2:
					//b->rchild = p;
					St[top]->rchild = p;
					break;
				}
			}
			break;
		}
		str++;
	}
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
				printf(")");//这句话不能放if里面
			
		}
	}
}

void Tread(BTNode*& b)
{
	if (b != NULL)
	{
		Tread(b->lchild);
		if (b->lchild == NULL)
		{
			b->lchild = pre;
			b->ltag = 1;
		}
		else
		{
			b->ltag = 0;
		}
		if (pre->rchild == NULL)
		{
			pre->rchild = b;
			pre->rtag = 1;
		}
		else
		{
			pre->rtag = 0;
		}
		pre = b;
		Tread(b->rchild);
	}
}

BTNode* CreateTread(BTNode*& b)
{
	BTNode* root = NULL;
	root = (BTNode*)malloc(sizeof(BTNode));
	root->ltag = 0;
	root->rtag = 1;
	root->rchild = b;
	if (b == NULL)
	{
		root->lchild = root;
	}
	else
	{
		root->lchild = b;
		pre = root;
		Tread(b);
		pre->rchild = root;
		pre->rtag = 1;
		root->rchild = pre;
	}
	return root;
}

void ThInOrder(BTNode* b)
{
	BTNode* p = b->lchild;
	while (p != b)
	{
		while (p->ltag == 0)
		{
			p = p->lchild;
		}
		printf("%c", p->data);
		while (p->rtag == 1 && p->rchild != b)
		{
			p = p->rchild;
			printf("%c", p->data);
		}
		p = p->rchild;
	}
}