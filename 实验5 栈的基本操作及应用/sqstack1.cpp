#include<stdio.h>
#include<malloc.h>
#define max 1024
typedef struct Sqlist
{
	char data[max];
	int top;
}sqstack1;
void initstack(sqstack1 *&s)//��ʼ��˳��ջ
{
	s=(sqstack1 *)malloc(sizeof(sqstack1));
	s->top=-1;
}

int stackempty(sqstack1 *s)//�ж�ջ�Ƿ�Ϊ��
{
	return(s->top==-1);
}
bool push(sqstack1 *&s,char e)//��ջ
{
	if(s->top ==max-1)//ջ�������ܽ�ջ
		return false;
	s->top ++;
	s->data [s->top ]=e;
	return true;
}
int stacksength(sqstack1 *s)//ջ�ĳ���
{
	return s->top+1;
}

bool pop(sqstack1 *&s,char &e)//��ջ
{
	if(s->top ==-1)//ջ��
		return false;
	e=s->data [s->top ];
	s->top --;
	return true;
}

void destorystack(sqstack1 *&s)//����˳��ջ
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

