#include"sqstack1.cpp"
#include"sqstack2.cpp"
//将算术表达式exp转换成后缀表达式postexp
void trans(char *exp,char postexp[])
{
	sqstack1 *optr;
	initstack(optr);
	int i = 0;
	char e;
	while(*exp != '\0')
	{
		switch(*exp)
		{
			case '(':
				push(optr,'(');
				exp++;
				break;
			case ')':
				pop(optr,e);
				while(e!='(')
				{
					postexp[i++]=e;
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
				while(*exp >= '0' && *exp <= '9')
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

//计算后缀表达式的值 
double cmpvalue(char *postexp)
{
	double  d,a,b,c,e;
	sqstack2 *opnd;
	initstack2(opnd);
	while(*postexp != '\0')
	{
		switch(*postexp)
		{
			case '+':
				pop2(opnd,a);
				pop2(opnd,b);
				c = b+ a; 
				push2(opnd,c);
				break;
			case '-':
				pop2(opnd,a);
				pop2(opnd,b);
				c = b - a;
				push2(opnd,c);
				break;
			case '*':
				pop2(opnd,a);
				pop2(opnd,b);
				c = b * a;
				push2(opnd,c);
				break;
			case  '/':
				pop2(opnd,a);
				pop2(opnd,b);
				if(a != 0)
				{
					c = b / a;
					push2(opnd,c);
					break;
				}
				else
				{
					printf("\n\t除零错误！\n");
					exit(0);
				}
				break;
			default:
				d = 0;
				while(*postexp >= '0' && *postexp <= '9')
				{
					d = 10*d + *postexp - '0' ;
				postexp++;
				}
				push2(opnd,d);
				break;
		}
		postexp++;
	}
	gettop2(opnd,e);
	destroystack2(opnd);
	return e;
}
int main()
{
	char exp[] = "(56-20)/(4+2)";
	char postexp[max];
 	trans(exp,postexp);
	printf("中缀表达式：%s\n",exp);
	printf("后缀表达式：%s\n",postexp);
	printf("表达式的值：%g",cmpvalue(postexp));
	return 0;
}
