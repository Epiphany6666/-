#include<stdio.h>
#include<string.h>
#define Max 1024
typedef struct
{
	char data[Max];
	int length;
}SqString;

//初始化串 
void InitString(SqString &s)
{
	s.length = 0;
}

//将字符串常量赋给串s 
void StrAssign(SqString &s,const char str[])
{
	int i = 0;
	for(i = 0; i < strlen(str); i++)
	{
		s.data[i] = str[i];
		
	}
	s.length = i;
	
}

//求字符串长度 
int StrLength(SqString s)
{
	return s.length;
}

//插入子串
////法1： 
//void InsertString(SqString &s,int i,SqString s1)
//{
//	if(i < 0 || i > s.length + 1)
//		return;
//	int n = 0, j = 0, q = 0;
//	for(j = s.length; j < i; j--)
//	{
//		for(q = 0; q < StrLength(s1); q++ )
//		{
//			s.data[j] = s.data[j+1];
//		}
//	}
//	int len = StrLength(s1);
//	for(n = 0; n < len; n++)
//	{
//		s.data[i++] = s1.data[n];
//		
//	}
//	s.length += s1.length;
//}
//法2：
SqString InsertString(SqString &s,int i,SqString s1)
{
	int j = 0;
	SqString str;
	str.length = 0;
	if(i<= 0||i>s.length+1)
		return str;
	for(j = 0; j < i-1; j++)
	{
		str.data[j] = s.data[j];
	}
	for(j = 0; j < s1.length ; j++)
	{
		str.data[i + j -1] = s1.data[j];
	}
	for(j = i-1; j < s.length ;j++)
	{
		str.data[j+s1.length] = s.data[j];
	}
	str.length = s.length + s1.length;
	return str;
}

//输出串 
void DispString(SqString s)
{
	int i = 0;
	for(i = 0; i < s.length; i++)
	{
		printf("%c",s.data[i]);
	}
	printf("\n");
}

//删除子串
SqString DeletString(SqString &s,int n,int m)
{
	int j = 0;
	SqString str;
	for(j = 0; j < n - 1; j++)
	{
		str.data[j] = s.data[j];
	}
	for(j = n+m;j < s.length;j++)
	{
		str.data[j-m] = s.data[j];
	}
	str.length = s.length - m;
	return str;
}

//串链接
SqString Uion(SqString s,SqString s1)
{
	SqString str;
	int i;
	for(i = 0; i < s.length; i++)
	{
		str.data[i] = s.data[i];
	}
	for(i = 0;i< s1.length;i++)
	{
		str.data[i+s.length] = s1.data[i];
	}
	str.length = s.length+s1.length;
	return str;
} 
