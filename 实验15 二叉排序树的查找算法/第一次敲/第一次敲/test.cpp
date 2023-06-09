#include"BST.h"
int main()
{
	BSTNode* bt = NULL;
	KeyType key[] = { 75, 105, 115, 104, 67, 46, 99, 111, 109 };
	int sz = sizeof(key) / sizeof(key[0]);
	//bt = CreateBST(bt, key, sz);
	bt = CreateBST(key, sz);
	DispBST(bt);
	printf("\n");
	bt = DeleteBST(bt, 99);
	DispBST(bt);
	printf("\n");
	return 0;
}