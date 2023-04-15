#include"SqString.cpp"
int main()
{
	SqString s, s1, s2, s3;
	InitString(s1);
	StrAssign(s,"abcdef");
	StrAssign(s1,"123456");
	InitString(s);
	printf("该串的长度为：%d\n",StrLength(s));
	s2 = InsertString(s,1,s1);
	printf("s2 = ");
	DispString(s2);
	s2 = DeletString(s,2,2);
	DispString(s2);
	s3 = Uion(s,s1);
	printf("s3 = ");
	DispString(s3);
	return 0;
}
