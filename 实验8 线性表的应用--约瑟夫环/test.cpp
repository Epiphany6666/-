#include"huan.cpp"
int main()
{
	linklist* L;
	int n, m;
	printf("����������\n");
	scanf("%d", &n);
	printf("������m��ֵ��\n");
	scanf("%d", &m);
	CreateList(L, n);
	DeleteList(L, m, n);
	return 0;
}
