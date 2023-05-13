#include"BTree.h"

void CreateBT(BTNode*& b, char* str)
{
	BTNode* p = NULL;
	b = NULL;
	BTNode* St[MaxSize];
	int top = -1;
	int k = 0;
	while (*str != '\0')
	{
		switch (*str)
		{
		case '(':
			top++;
			St[top] = p;
			k = 1;
			break;
		case ')':
			top--;
			break;
		case ',':
			k = 2;
			break;
		default:
			p = (BTNode*)malloc(sizeof(BTNode));
			p->data = *str;
			p->lchild = p->rchild = 0;
			if (b == NULL)
			{
				b = p;
			}
			else
			{
				switch (k)
				{
				case 1:
					St[top]->lchild = p;
					break;
				case 2:
					St[top]->rchild = p;
					break;
				default:
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
			printf(")");
		}
	}
}

BTNode* FindNode(BTNode* b, char e)
{
	/*BTNode* p = NULL;
	if (b == NULL)
		return NULL;
	if (b->data == e)
	{
		return b;
	}
	p = FindNode(b->lchild, e);
	p = FindNode(b->rchild, e);
	if(p != NULL)
		return p;
	else
		return NULL;*/

	BTNode* p = NULL;

	if (b == NULL)
	{
		return NULL;
	}
	else if (b->data == e)
	{
		return b;
	}
	else
	{
		p = FindNode(b->lchild, e);
		if (p != NULL)
		{
			return p;
		}
		else
		{
			return FindNode(b->rchild, e);
		}
	}
}

void DispChild(BTNode* t)
{
	if (t->lchild != NULL)
	{
		printf("%c的左孩子为:%c\n", t->data, t->lchild->data);
	}
	else
	{
		printf("%c没有右孩子\n", t->data);
	}
	if(t->lchild != NULL)
	{
		printf("%c的左孩子为:%c\n", t->data, t->rchild->data);
	}
	else
	{
		printf("%c没有左孩子\n", t->data);
	}
}

//int BTHeight(BTNode* b)
//{
//	int lheight = 0;
//	int rheight = 0;
//	if (b->lchild == NULL && b->rchild == NULL)
//	{
//		return 0;
//	}
//	return (lheight > rheight ? (lheight + 1) : (rheight + 1));
//}

int BTHeight(BTNode* b)
{
	int lheight = 0;
	int rheight = 0;
	if (b == NULL)
	{
		return 0;
	}
	else
	{
		lheight = BTHeight(b->lchild);
		rheight = BTHeight(b->rchild);
		return (lheight > rheight ? (lheight + 1) : (rheight + 1));
	}
}

int NodeNum(BTNode* b)
{
	//int lnum, rnum;
	if (b == NULL)
	{
		return 0;
	}
	else
	{
		/*NodeNum(b->lchild);
		NodeNum(b->rchild);
		return lnum + rnum;*/
		return NodeNum(b->lchild) + NodeNum(b->rchild) + 1;
	}
}

//递归方法
void PreOrder0(BTNode* b)
{
	if (b != NULL)
	{
		printf("%c", b->data);
		PreOrder0(b->lchild);
		PreOrder0(b->rchild);
	}
}

//非递归方法
void PreOrder1(BTNode* b)
{
	BTNode* p = NULL;
	SqStack* st;
	InitStack(st);
	if (b != NULL)
	{
		Push(st, b);
		while (!EmptyStack(st))
		{
			Pop(st, p);
			printf("%c", p->data);
			if (p->rchild != NULL)
			{
				Push(st, p->rchild);
			}
			if (p->lchild != NULL)
			{
				Push(st, p->lchild);
			}
		}
		printf("\n");
	}
	DestroyStack(st);
}

void PreOrder2(BTNode* b)
{
	BTNode* p;
	SqStack* st;
	InitStack(st);
	p = b;
	while (!EmptyStack(st) || p != NULL)
	{
		while (p != NULL)
		{
			printf("%c", p->data);
			Push(st, p);
			p = p->lchild;
		}
		if (!EmptyStack(st))
		{
			Pop(st, p);
			p = p->rchild;
		}
	}
	printf("\n");
	DestroyStack(st);
}

void InOrder(BTNode* b)
{
	BTNode* p;
	SqStack* st;
	InitStack(st);
	p = b;
	while (!EmptyStack(st) || p != NULL)
	{
		while (p != NULL)
		{
			Push(st, p);
			p = p->lchild;
		}
		if (!EmptyStack(st))
		{
			GetTop(st, p);
			printf("%c", p->data);
			Pop(st, p);
			p = p->rchild;
		}
	}
	printf("\n");
	DestroyStack(st);
}

void PostOrder(BTNode* b)
{
	BTNode* p, * r;
	SqStack* st;
	bool flag;
	p = b;
	InitStack(st);
	do
	{
		while (p != NULL)
		{
			Push(st, p);
			p = p->lchild;
		}
		r = NULL;
		flag = true;
		while (!EmptyStack(st) && flag)
		{
			GetTop(st, p);
			if (p->rchild == r)
			{
				printf("%c", p->data);
				Pop(st, p);
				r = p;
			}
			else
			{
				p = p->rchild;
				flag = false;
			}
		}
	} while (!EmptyStack(st));
	printf("\n");
	DestroyStack(st);
}

//void DispLeaf(BTNode* b)
//{
//	BTNode* p;
//	p = b;
//	if (b != NULL)
//	{
//		while (p->lchild != NULL || p->rchild != NULL)
//		{
//			p
//		}
//	}
//}

void DispLeaf(BTNode* b)
{
	if (b != NULL)
	{
		if (b->lchild == NULL && b->rchild == NULL)
		{
			printf("%c", b->data);
		}
		/*DispLeaf(b->lchild);
		DispLeaf(b->rchild);*/
		else
		{
			DispLeaf(b->lchild);
			DispLeaf(b->rchild);
		}
	}
}

int Level1(BTNode* b, char x)//求结点在第几层，从1开始
{
	int t = 1;
	if (b == NULL)
	{
		return 0;
	}
	else if (b->data == x)
	{
		return t;
	}
	else
	{
		t = Level1(b->lchild, x);
		if (t != 0)
		{
			return t + 1;
		}
		else
		{
			t = Level1(b->rchild, x);
			if (t != 0)
			{
				return t + 1;
			}
		}
		return 0;
	}
}

int Level2(BTNode* b, char x, int h)
{
	int l = 0;
	if (b == NULL)
	{
		return 0;
	}
	else if (b->data == x)
	{
		return h;
	}
	else
	{
		l = Level2(b->lchild, x, h + 1);
		if (l != 0)
		{
			return l;
		}
		l = Level2(b->rchild, x, h + 1);
	}
}

void DestroyBTree(BTNode* b)
{
	if (b != NULL)
	{
		DestroyBTree(b->lchild);
		DestroyBTree(b->rchild);
		free(b);
	}
}