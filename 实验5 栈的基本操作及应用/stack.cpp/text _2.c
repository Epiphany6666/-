#include<stdio.h>
#include<malloc.h>
#include<math.h>
#include<string.h>
#define max 1024
typedef char elemtype;
typedef struct
{
	elemtype data[max];
	int top;
}sqstack;


//栈的初始化 
void initstack(sqstack* p)
{
	p = (sqstack*)malloc(sizeof(sqstack));
	p->top = 0;
}

//进栈
void push(sqstack* p, elemtype e)
{
	if (p->top == max - 1)
	{
		return;
	}
	p->top++;
	p->data[p->top] = e;
}

//出栈的数为a
void pop(sqstack* p, elemtype &e)
{
	if (p->top == -1)
	{
		return;
	}
	e = p->data[p->top];
	p->top--;
}

//判断栈是否为空
bool stackempty(sqstack* p)
{
	return (p->top == -1);
}

//取栈顶元素，返回当前的栈顶元素，并赋值给e
void gettop(sqstack* p, elemtype e)
{
	if (stackempty(p))
	{
		return;
	}
	e = p->data[p->top - 1];
}

//求栈的长度
int lengthstack(sqstack* p)
{
	return (p->top);
}

//获取一个二进制字符串
void getbinary(elemtype* str)
{
	//输入一个二进制字符串并以'#'结束 
	int i = 0;
	printf("请输入一个二进制数，并以‘#’结束\n");
	scanf("%c", &str[i++]);
	while (str[i - 1] != '#')
	{
		scanf("%c", &str[i++]);
	}
}

int reverse2_10(elemtype str[], sqstack* p)
{
	elemtype e;
	int i = 0, sum = 0;
	int len = strlen(str);
	//将字符串进栈 
	for (i = 0; i < len; i++)
	{
		push(p, str[i]);
	}
	//出栈，并转化为10进制 
	for (i = 0; i < len; i++)
	{
		pop(p, e);
		sum += (e - 48) * pow(2, i);
	}
	return sum;
}

//二进制转八进制 
void reverse2_8(elemtype str[], sqstack* p)
{
	elemtype e;
	sqstack* t;
	initstack(t);
	int i = 0, j, sum = 0;
	//将字符串进栈 
	for (i = 0; i < strlen(str); i++)
	{
		push(p, str[i]);
	}
	//出栈，并转化为8进制 
	for (i = 0; i < strlen(str); i += 3)
	{
		int sum = 0;
		for (j = 0; j < lengthstack(p); j++)
		{
			pop(p, e);
			sum += e * pow(e, j);
			if (stackempty(p))
			{
				break;
			}
		}
		push(t, sum + 48);
	}
	while (!stackempty(t))
	{
		pop(t, e);
		printf("%c", e);
	}
	printf("\n");
}

//二进制转十六进制 
void reverse2_16(elemtype str[], sqstack* p)
{
	elemtype e;
	sqstack* t;
	initstack(t);
	int i = 0, j, sum = 0;
	//将字符串进栈 
	for (i = 0; i < strlen(str); i++)
	{
		push(p, str[i]);
	}
	//出栈，并转化为8进制 
	for (i = 0; i < strlen(str); i += 4)
	{
		int sum = 0;
		for (j = 0; j < lengthstack(p); j++)
		{
			pop(p, e);
			sum += e * pow(e, j);
			if (stackempty(p))
			{
				break;
			}
		}
		push(t, sum + 48);
	}
	while (!stackempty(t))
	{
		pop(t, e);
		printf("%c", e);
	}
	printf("\n");
}

//十进制转二进制
void  convert(sqstack* p)
{
	elemtype a, e;
	printf("请输入一个十进制数");
	scanf("%d", &a);
	while (a != 1 || a != 0)
	{
		push(p, a % 2);
		a = a / 2;
	}
	while (!stackempty(p))
	{
		pop(p, e);
		printf("%d", e);
	}
	printf("\n");
}