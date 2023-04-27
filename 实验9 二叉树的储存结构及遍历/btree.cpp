#include"btree.h"

void createTree(BTNode*& b, char* str) {
	BTNode* St[MaxSize], * p = NULL;
	b = NULL;
	int top = -1, k = 0;
	char ch = *str;
	while (*str != '\0') {
		switch (ch) {
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
			p->data = ch;
			p->lchild = NULL;
			p->rchild = NULL;
			if (b == NULL) {
				b = p;
			}
			else {
				switch (k) {
				case 1:
					St[top]->lchild = p;
					break;
				case 2:
					St[top]->rchild = p;
					break;
				}
			}
			break;
		}
		str++;
		ch = *str;
	}
}

void DispBTree(BTNode* b)
{
	if (b != NULL) {
		printf("%c", b->data);
		//if (b->lchild != NULL && b->rchild != NULL) {
		if (b->lchild != NULL || b->rchild != NULL) {
			printf("(");
			DispBTree(b->lchild);
			if (b->rchild != NULL) {
				printf(",");
			}
			DispBTree(b->rchild);
			printf("%c", ')');
		}
	}
}

BTNode* FindNode(BTNode* b, char e) {
	BTNode* p;
	if (b == NULL) {
		return NULL;
	}
	else if (b->data == e) {
		return b;
	}
	else {
		p = FindNode(b->rchild, e);
		if (p != NULL) {
			return p;
		}
		else {
			return FindNode(b->lchild, e);
		}
	}
}

BTNode* LchildNode(BTNode* b) {
	return b->lchild;
}

BTNode* RchildNode(BTNode* b) {
	return b->rchild;
}

int BTHeight(BTNode* b) {
	int rchildh, lchildh;
	if (b == NULL){
		return 0;
	}
	else {
		lchildh = BTHeight(b->lchild);
		rchildh = BTHeight(b->rchild);
		return (rchildh > lchildh ? (rchildh + 1) : (lchildh + 1));
	}
}

void PreOrder(BTNode* b) {
	if (b != NULL) {
		printf("%c", b->data);
		PreOrder(b->lchild);
		PreOrder(b->rchild);
	}
}

void InOrder(BTNode* b) {
	if (b != NULL) {
		InOrder(b->lchild);
		printf("%c", b->data);
		InOrder(b->rchild);
	}
}

void PostOrder(BTNode* b) {
	if (b != NULL) {
		InOrder(b->lchild);
		InOrder(b->rchild);
		printf("%c", b->data);
	}
}

void DispLeaf(BTNode* b) {
	if (b != NULL) {
		if (b->lchild == NULL && b->rchild == NULL) {
			printf("%c", b->data);
		}else{
			DispLeaf(b->lchild);
			DispLeaf(b->rchild);
		}
	}
}

void DestroyBTree(BTNode*& b) {
	if (b != NULL)
	{
		DestroyBTree(b->lchild);
		DestroyBTree(b->rchild);
		free(b);
	}
}