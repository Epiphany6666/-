#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef int KeyType;
typedef struct node
{
	KeyType key;
	struct node* lchild, * rchild;
}BSTNode;

BSTNode* InsertBST(BSTNode* bt, KeyType key);
BSTNode* CreateBST(KeyType key[], int sz);

void DispBST(BSTNode* bt);

BSTNode* DeleteBST(BSTNode* bt, KeyType key);