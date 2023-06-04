#include"SqList.h"
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
int main()
{
	SqList* L;
	ElemType e;
	//(1)初始化顺序表L
	CreateList(L);
	//(2)依次插入 a, b, c, d, e 元素
	ListInsert(L, 1, 'a');
	ListInsert(L, 1, 'b');
	ListInsert(L, 1, 'c');
	ListInsert(L, 1, 'd');

	//(3) 输出顺序表
	DispList(L);
	//(4) 输出顺序表的长度
	printf("顺序表的长度为：%d\n", ListLength(L));
	//(5)判断顺序表L是否非空
	if (ListEmpty(L) == false)
	{
		printf("该顺序表为空\n");
	}
	else
	{
		printf("该链表不为空\n");
	}
	//(6) 输出顺序表L的第三个元素,给e
	//DispElem(L, 1);
	GetElem(L, 1, &e);
	//(7)输出元素a的位置
	LocatedElem(L, 'e');
	printf("%c的位置为%d\n", 'e', e);
	//(9)删除顺序表中的第 3 个元素，并输出顺序表
	DeleteElem(L, 1);
	DispList(L);
	return 0;
}