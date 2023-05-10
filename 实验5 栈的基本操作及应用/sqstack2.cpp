#include<stdio.h>
#include<malloc.h>
#define max 1024
typedef struct Sqlist2
{
	double data[max];
	int top;
}sqstack2;
void initstack2(sqstack2 *&s)//³õÊ¼»¯Ë³ÐòÕ»
{
	s=(sqstack2 *)malloc(sizeof(sqstack2));
	s->top=-1;
}

int stackempty2(sqstack2 *s)//ÅÐ¶ÏÕ»ÊÇ·ñÎª¿Õ
{
	return(s->top==-1);
}
bool push2(sqstack2 *&s,double e)//½øÕ»
{
	if(s->top ==max-1)//Õ»Âú£¬²»ÄÜ½øÕ»
		return false;
	s->top ++;
	s->data [s->top ]=e;
	return true;
}
int stacksength2(sqstack2 *s)//Õ»µÄ³¤¶È
{
	return s->top+1;
}

bool pop2(sqstack2 *&s,double &e)//³öÕ»
{
	if(s->top ==-1)//Õ»¿Õ
		return false;
	e=s->data [s->top ];
	s->top --;
	return true;
}

void destorystack2(sqstack2 *&s)//Ïú»ÙË³ÐòÕ»
{
	free(s);
}

bool gettop2(sqstack2 *s,double &e)
{
	if(s->top ==-1)
		return false;
	e=s->data [s->top ];
	return true;
}

void destroystack2(sqstack2 *&s)
{
	free(s);
}
