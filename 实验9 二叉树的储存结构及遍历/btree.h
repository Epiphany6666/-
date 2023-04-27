#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<math.h>

#define MaxSize 1024

typedef char ElemType;
typedef struct node {
	ElemType data;
	struct node* lchild;
	struct node* rchild;
}BTNode;

void createTree(BTNode*& b, char* str);

void DispBTree(BTNode* b);

BTNode* FindNode(BTNode* b, char e);

BTNode* LchildNode(BTNode* b);

BTNode* RchildNode(BTNode* b);

int BTHeight(BTNode* b);

void PreOrder(BTNode* b);
void InOrder(BTNode* b);
void PostOrder(BTNode* b);

void DispLeaf(BTNode* b);

void DestroyBTree(BTNode*& b);