#include<stdio.h>
#include<malloc.h>
#define max 1024
typedef struct Sqlist
{
	char data[max];
	int top;
}sqstack1;
void initstack(sqstack1 *&s)//³õÊ¼»¯Ë³ÐòÕ»
{
	s=(sqstack1 *)malloc(sizeof(sqstack1));
	s->top=-1;
}

int stackempty(sqstack1 *s)//ÅÐ¶ÏÕ»ÊÇ·ñÎª¿Õ
{
	return(s->top==-1);
}
bool push(sqstack1 *&s,char e)//½øÕ»
{
	if(s->top ==max-1)//Õ»Âú£¬²»ÄÜ½øÕ»
		return false;
	s->top ++;
	s->data [s->top ]=e;
	return true;
}
int stacksength(sqstack1 *s)//Õ»µÄ³¤¶È
{
	return s->top+1;
}

bool pop(sqstack1 *&s,char &e)//³öÕ»
{
	if(s->top ==-1)//Õ»¿Õ
		return false;
	e=s->data [s->top ];
	s->top --;
	return true;
}

void destorystack(sqstack1 *&s)//Ïú»ÙË³ÐòÕ»
{
	free(s);
}

bool gettop(sqstack1 *s,char &e)
{
	if(s->top ==-1)
		return false;
	e=s->data [s->top ];
	return true;
}

void destroystack(sqstack1 *&s)
{
	free(s);
}

