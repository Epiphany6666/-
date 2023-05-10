#include"SqStack.h"
//初始化栈
//销毁栈
//判断栈是否为空
//进栈
//出栈
//取栈顶元素

int main()
{
	SqStack q;
	ElemType e;
	//初始化栈
	InitStack(q);
	//判断栈是否为空
	if (!EmptyStack(q))
	{
		printf("不为空\n");
	}
	//进栈
	Push(q, 'a');
	Push(q, 'b');

	//出栈
	Pop(q, e);
	printf("出栈元素为：%c\n", e);
	//取栈顶元素
	GetTop(q, e);
	printf("栈顶元素为：%c\n", e);
	return 0;
}