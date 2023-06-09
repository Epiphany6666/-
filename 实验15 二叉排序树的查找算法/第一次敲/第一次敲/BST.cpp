//typedef int KeyType;
//typedef struct node
//{
//	KeyType key;
//	struct node* lchild, * rchild;
//}BSTNode;
//
//int main()
//{
//	BSTNode* bt;
//	int n = 9;
//	KeyType a[] = { 75, 105, 115, 104, 67, 46, 99, 111, 109 };
//	return 0;
//}
//
//BSTNode* InsertBST(BSTNode* bt, KeyType k)
//{
//	if (bt == NULL)
//	{
//		bt = (BSTNode*)malloc(sizeof(BSTNode));
//		bt->key = k;
//		bt->lchild = bt->rchild = NULL;
//	}
//	else if (k < bt->key)
//	{
//		bt->lchild = InsertBST(bt->lchild, k);
//	}
//	else (k > bt->key)
//	{
//		bt->rchild = InsertBST(bt->rchild, k);
//	}
//	return bt;
//}
//
//BSTNode* CreateBST(KeyType a[], int n)
//{
//	BSTNode* bt = NULL;
//	int i = 0;
//	while (i < n)
//	{
//		bt = InsertBST(bt, a[i]);
//		i++;
//	}
//	return bt;
//}
//
//BSTNode* SearchBST(BSTNode* bt, KeyType k)
//{
//	if (bt == NULL || bt->key == k)
//		return bt;
//	if (k < bt->key)
//	{
//		return SearchBST(bt->lchild, k);
//	}
//	else
//	{
//		return SearchBST(bt->rchild, k);
//	}
//}
//
////·ÇµÝ¹é
//BSTNode* SearchBST1(BSTNode* bt, KeyType k)
//{
//	BSTNode* p = bt;
//	while (p != NULL)
//	{
//		if (p->key == k)
//			break;
//		else if (k < p->key)
//			p = p->lchild;
//		else
//			p = p->rchild;
//	}
//	return p;
//}
//
//BSTNode* DeleteBST(BSTNode* bt, KeyType k)
//{
//	if (bt == NULL)
//		return bt;
//	BSTNode* p = bt, * f = NULL;
//	while (p != NULL)
//	{
//		if (p->key == k)
//			break;
//		f = p;
//		if (k < p->key)
//			p = p->lchild;
//		else
//			p = p->rchild;
//	}
//	if (p == NULL)
//		return bt;
//	if (p->lchild == NULL && p->rchild == NULL)
//	{
//		if (p == bt)
//			bt = NULL;
//		else
//		{
//			if (f->lchild == p)
//				f->lchild = NULL;
//			else
//				f->rchild = NULL;
//		}
//		free(p);
//	}
//	else if (p->rchild == NULL)
//	{
//		if (f == NULL)
//			bt = bt->lchild;
//		else
//		{
//			if (f->lchild == p)
//				f->lchild = p->lchild;
//			else
//				f->rchild = p->lchild;
//		}
//		free(p);
//	}
//	else if (p->lchild == NULL)
//	{
//		if (f == NULL)
//		{
//			bt = bt->lchild;
//		}
//		else
//		{
//			if (f->lchild == p)
//				f->lchild = p->rchild;
//			else
//				f->rchild = p->rchild;
//		}
//		free(p);
//	}
//	else
//	{
//		BSTNode* q = p->lchild;
//		f = p;
//		while (q->rchild != NULL)
//		{
//			f = q;
//			q = q->rchild;
//		}
//		p->key = q->key;
//		if (q == f->lchild)
//			f->lchild = q->lchild;
//		else
//			f->rchild = q->lchild;
//		free(q);
//	}
//	return bt;
//}

#include"BST.h"
BSTNode* InsertBST(BSTNode* bt, KeyType key)
{
	if (bt == NULL)
	{
		bt = (BSTNode*)malloc(sizeof(BSTNode));
		bt->key = key;
		bt->lchild = bt->rchild = NULL;
	}
	/*else
	{
		if (key == bt->key)
			return bt;*/
	else if (key < bt->key)
		bt->lchild = InsertBST(bt->lchild, key);
	else if (key > bt->key)
		bt->rchild = InsertBST(bt->rchild, key);
	return bt;
	//}
}

BSTNode* CreateBST(KeyType key[], int sz)
{
	BSTNode* bt = NULL;
	int i = 0;
	while (i < sz)
	{
		bt = InsertBST(bt, key[i]);
		i++;
	}
	return bt;
}

void DispBST(BSTNode* bt)
{
	if (bt == NULL)
		return;
	else
	{
		printf("%d", bt->key);
		if (bt->lchild != NULL || bt->rchild != NULL)
		{
			printf("(");
			/*if (bt->lchild != NULL)
			{
				*/DispBST(bt->lchild);
			//}
			//else
			//{
				if (bt->rchild != NULL)
					printf(",");
				DispBST(bt->rchild);
			//}
			printf(")");
		}
	}
}

BSTNode* DeleteBST(BSTNode* bt, KeyType key)
{
	if (bt == NULL)
		return bt;
	BSTNode* p = bt, *f = NULL;
	while (p != NULL)
	{
		if (key == p->key)
			break;
		f = p;
		if (key < p->key)
			p = p->lchild;
		else
			p = p->rchild;
	}
	if (p == NULL)//////////////////
		return bt;
	if (p->lchild == NULL && p->rchild == NULL)
	{
		if (p == bt)
			bt == NULL;
		else
		{
			if (f->lchild == p)
				f->lchild = NULL;
			else
				f->rchild = NULL;
		}
		free(p);
	}
	else if (p->rchild == NULL)
	{
		if (f == NULL)
			bt = bt->lchild;
		else
		{
			if (f->lchild == p)
				f->lchild = p->lchild;
			else
				f->rchild = p->lchild;
		}
		free(p);
	}
	else if (p->lchild == NULL)
	{
		if (f == NULL)
			bt = bt->rchild;
		else
		{
			if (f->lchild == p)
				f->lchild = p->rchild;
			else
				f->rchild = p->rchild;
		}
		free(p);
	}
	else
	{
		/*BSTNode* q = NULL;
		q = p->lchild;*/
		BSTNode* q = p->lchild;
		f = p;//////
		while (q->rchild != NULL)
		{
			f = q;
			q = q->rchild;
		}
		p->key = q->key;
		/*if (q->lchild == NULL && q->rchild == NULL)
			f->rchild = NULL;
		else if (q->rchild == NULL)
			f->rchild = q->lchild;
		else
			f->rchild = q->rchild;*/
		if (q == f->lchild)
			f->lchild = q->lchild;
		else
			f->rchild = q->lchild;
		free(q);
	}
	return bt;
}