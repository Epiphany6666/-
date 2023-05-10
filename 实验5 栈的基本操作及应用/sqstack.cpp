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
void initstack(sqstack *&p)
{
	p = (sqstack*)malloc(sizeof(sqstack));
	p->top = -1;
}

//进栈
void push(sqstack*& p, elemtype e)
{
	if (p->top == max - 1)
	{
		return;
	}
	p->top++;
	p->data[p->top] = e;
}

//出栈的数为a
void pop(sqstack*& p, elemtype& e)
{
	if (p->top == -1)
	{
		return;
	}
	e = p->data[p->top];
	p->top--;
}

//判断栈是否为空
bool stackempty(sqstack *&p)
{
	return (p->top == -1);
}

//取栈顶元素，返回当前的栈顶元素，并赋值给e
void gettop(sqstack *&p,elemtype e)
{
	if(stackempty(p))
	{
		return;
	}
	e = p ->data[p -> top -1];
}

//求栈的长度
int lengthstack(sqstack *&p)
{
	return (p -> top);
} 

//获取一个二进制字符串
void getbinary(elemtype * str)
{
	gets(str);
	
}

int reverse2_10(elemtype str[], sqstack *&p)
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
		sum += (e-48)*pow(2, i);
	}
	return sum;
}

//二进制转八进制 
void reverse2_8(elemtype str[], sqstack*& p)
{
	elemtype e;
	sqstack *t;
	initstack(t);
	int i = 0,j, sum = 0;
	//将字符串进栈 
	for (i = 0; i < strlen(str); i++)
	{
		push(p, str[i]);
	}
	//出栈，并转化为8进制 
	for (i = 0; i < strlen(str); i+=3)
	{
		int sum = 0;
		for(j = 0;j < lengthstack(p);j++)
		{
			pop(p, e);
			sum += e*pow(e,j);
			if(stackempty(p))
			{
				break;
			}
		}
		push(t,sum+48);
	}
	while(!stackempty(t))
	{
		pop(t,e);
		printf("%c",e);
	}
	printf("\n");
}

//二进制转十六进制 
void reverse2_16(elemtype str[], sqstack*& p)
{
	elemtype e;
	sqstack *t;
	initstack(t);
	int i = 0,j, sum = 0;
	//将字符串进栈 
	for (i = 0; i < strlen(str); i++)
	{
		push(p, str[i]);
	}
	//出栈，并转化为8进制 
	for (i = 0; i < strlen(str); i+=4)
	{
		int sum = 0;
		for(j = 0;j < lengthstack(p);j++)
		{
			pop(p, e);
			sum += e*pow(e,j);
			if(stackempty(p))
			{
				break;
			}
		}
		push(t,sum+48);
	}
	while(!stackempty(t))
	{
		pop(t,e);
		printf("%c",e);
	}
	printf("\n");
}

//十进制转二进制
void  convert(sqstack *&p)
{
	elemtype a,e;
	printf("请输入一个十进制数\n");
	scanf("%d",&a);
	while(a != 0)
	{
		push(p,a%2);
		a = a/2;
	}
	while(!stackempty(p))
	{
		pop(p,e);
		printf("%d  ",e);
	}
	printf("\n");
}

//将算术表达式exp转换成后缀表达式postexp
void trans(char *exp,char postexp[])
{
	sqstack *optr;
	elemtype e;
	int i = 0;
	while(*exp != '\0')
	{
		switch(*exp != '\0')
		{
			case '(':
				push(optr,'(');
				exp++;
				break;
			case ')':
				pop(optr,e);
				while(e!='(')
				{
					postexp[i++];
					pop(optr,e);
				}
				exp++;
				break;
			case '+':
			case '-':
				while(!stackempty(optr))
				{
					gettop(optr,e);
					if(e!='(')
					{
						postexp[i++] = e;
						pop(optr,e);
					}
					else
					{
						break;
					}	
				}
			push(optr,*exp);
			exp++;
			break;
			case '*':
			case '/':
				while(!stackempty(optr))
				{
					gettop(optr,e);
					if(e == '*' || e == '/')
					{
						postexp[i++] = e;
						pop(optr,e);
					}
					else
						break;
				}
				push(optr,*exp);
				exp++;
				break;
			default:
				while(*exp >= '0' && *exp <= '0')
				{
					postexp[i++] = *exp;
					exp++;
				}
				postexp[i++] = '#';
		}
	}
	
	while(!stackempty(optr))
	{
		pop(optr,e);
		postexp[i++] = e;
	} 
	postexp[i++] = '\0';
	destroystack(optr);
} 

void comvalue(char *postexp)
{
	
}
