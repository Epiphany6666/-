#include"sqstack2.cpp"
int main()
{
	ElemType str[max];
	int D,O,H;
	sqstack *p;//����ջp 
	initstack(p);//��ʼ��p 
	getbinary(str);//��ȡһ������������ 
	
	D = reverse2_10(str, p);// 2ת10 
	printf("תΪʮ���ƺ����Ϊ:% d\n", D);
	printf("������ת�˽��ƺ����Ϊ��") ;
	reverse2_8(str, p);// 2ת8 
	convert(p);
	return 0;
}
