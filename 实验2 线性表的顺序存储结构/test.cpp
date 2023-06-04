#include"sqlist.cpp"

int main()

{

	elemtype e;

	linklist* L;

	initlist(L);

	insertlist(L, 1, 'a');

	insertlist(L, 2, 'b');

	insertlist(L, 3, 'c');

	insertlist(L, 4, 'd');

	insertlist(L, 5, 'e');

	displist(L);

	printf("顺序表的长度为：%d\n", L->length);

	listempty(L);

	getlist(L, 3, &e);

	dispposition(L, 'a');

	insertlist(L, 4, 'f');

	displist(L);

	deletelist(L, 3, e);

	displist(L);

	free(L);

	return 0;

}