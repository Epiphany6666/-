//(1)初始化顺序表L
//(2)依次插入 a, b, c, d, e 元素
//(3) 输出顺序表
//(4) 输出顺序表的长度
//(5)判断顺序表L是否非空
//(6) 输出顺序表L的第三个元素
//(7)输出元素a的位置
//(8)在第4个元素位置上插入f 元素，然后输出顺序表
//(9)删除顺序表中的第 3 个元素，并输出顺序表
//(10)释放顺序表
#include"SqList.h"
int main()
{
	//(1)初始化顺序表L
	SqList* L;
	CreateList(L);
	//(2)依次插入 a, b, c, d, e 元素
	InsertList(L, 1, 'a');
	InsertList(L, 1, 'b');
	InsertList(L, 1, 'c');
	InsertList(L, 1, 'd');
	InsertList(L, 1, 'e');
	//(3) 输出顺序表
	DispList(L);
	printf("\n");
	//(5)判断顺序表L是否非空
	if (EmptyList(L) == true)
	{
		printf("L链表为空\n");
	}
	else
	{
		printf("链表不为空\n");
	}
	//(6) 输出顺序表L的第三个元素
	ElemType e;
	FindElem(L, 3, &e);
	printf("第三个元素为：%c\n", e);
	//(7)输出元素a的位置
	int ret = LocateElem(L, 'a');
	if (ret != 0)
	{
		printf("%c的位置为%d\n", 'a', ret);
	}
	//(8)在第4个元素位置上插入f 元素，然后输出顺序表
	InsertList(L, 4, 'f');
	DispList(L);
	printf("\n"); 
	//(9)删除顺序表中的第 3 个元素，并输出顺序表
	DeleteList(L, 3, &e);
	printf("删除的元素为：%c\n", e);
	DispList(L);
	//(10)释放顺序表
	DestroyList(L);
	return 0;
}