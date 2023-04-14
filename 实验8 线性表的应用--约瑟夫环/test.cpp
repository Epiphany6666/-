#include"huan.cpp"
int main()
{
	linklist* L;
	int n, m;
	printf("请输入人数\n");
	scanf("%d", &n);
	printf("请输入m的值：\n");
	scanf("%d", &m);
	CreateList(L, n);
	DeleteList(L, m, n);
	return 0;
}
