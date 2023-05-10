#include"sqstack2.cpp"
int main()
{
	ElemType str[max];
	int D,O,H;
	sqstack *p;//定义栈p 
	initstack(p);//初始化p 
	getbinary(str);//获取一串二进制数字 
	
	D = reverse2_10(str, p);// 2转10 
	printf("转为十进制后的数为:% d\n", D);
	printf("二进制转八进制后的数为：") ;
	reverse2_8(str, p);// 2转8 
	convert(p);
	return 0;
}
