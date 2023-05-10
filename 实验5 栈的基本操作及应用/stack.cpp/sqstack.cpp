//#include"sqstack.h"
//
////栈的初始化 
//void initstack(sqstack1* p)
//{
//	p = (sqstack1*)malloc(sizeof(sqstack1));
//	p->top = 0;
//}
//
////进栈
//void push(sqstack1* p, elemtype e)
//{
//	if (p->top == max - 1)
//	{
//		return;
//	}
//	p->top++;
//	p->data[p->top] = e;
//}
//
////出栈的数为a
//void pop(sqstack1* p, elemtype& a)
//{
//	if (p->top == -1)
//	{
//		return;
//	}
//	a = p->data[p->top];
//	p->top--;
//}
//
//
////获取一个二进制字符串
//void getbinary(elemtype * str)
//{
//	//输入一个二进制字符串并以'#'结束 
//	int i = 0;
//	printf("请输入一个二进制数，并以‘#’结束\n");
//	scanf("%c", &str[i++]);
//	while (str[i - 1] != '#')
//	{
//		scanf("%c", &str[i++]);
//	}
//}
//
//int reverse2_10(elemtype str[], sqstack1 *p)
//{
//	elemtype a;
//	int i = 0, sum = 0;
//	//将字符串进栈 
//	for (i = 0; i < strlen(str); i++)
//	{
//		push(p, str[i]);
//	}
//	//出栈，并转化为10进制 
//	for (i = 0; i < strlen(str); i++)
//	{
//		pop(p, a);
//		sum += pow(a, i);
//	}
//	return sum;
//}
//
//int reverse2_8(elemtype str[], sqstack1* p)
//{
//	elemtype a,b,c;
//	int i = 0, sum = 0;
//	//将字符串进栈 
//	for (i = 0; i < strlen(str); i++)
//	{
//		push(p, str[i]);
//	}
//	//出栈，并转化为8进制 
//	for (i = 0; i < strlen(str); i+=3)
//	{
//		pop(p, a);
//		pop(p, b);
//		pop(p, c);
//		sum = pow(a, 2) + pow(b, 1) + pow(c, 0);
//	}
//	return sum;
//}
//
//
//
