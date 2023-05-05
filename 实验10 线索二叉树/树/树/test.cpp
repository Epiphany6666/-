#include"bitree.h"
int main() {
	char str[] = "A(B(D(,G)),C(E,F))";
	BTNode* b;
	CreateBT(b, str);
	DispBT(b);
	printf("\n");
	BTNode* root = CreateTread(b);
	ThInOrder(root);
	printf("\n");
	return 0;
}