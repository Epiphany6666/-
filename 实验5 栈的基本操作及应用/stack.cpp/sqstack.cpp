//#include"sqstack.h"
//
////ջ�ĳ�ʼ�� 
//void initstack(sqstack1* p)
//{
//	p = (sqstack1*)malloc(sizeof(sqstack1));
//	p->top = 0;
//}
//
////��ջ
//void push(sqstack1* p, elemtype e)
//{
//	if (p->top == max - 1)
//	{
//		return;
//	}
//	p->top++;
//	p->data[p->top] = e;
//}
//
////��ջ����Ϊa
//void pop(sqstack1* p, elemtype& a)
//{
//	if (p->top == -1)
//	{
//		return;
//	}
//	a = p->data[p->top];
//	p->top--;
//}
//
//
////��ȡһ���������ַ���
//void getbinary(elemtype * str)
//{
//	//����һ���������ַ�������'#'���� 
//	int i = 0;
//	printf("������һ���������������ԡ�#������\n");
//	scanf("%c", &str[i++]);
//	while (str[i - 1] != '#')
//	{
//		scanf("%c", &str[i++]);
//	}
//}
//
//int reverse2_10(elemtype str[], sqstack1 *p)
//{
//	elemtype a;
//	int i = 0, sum = 0;
//	//���ַ�����ջ 
//	for (i = 0; i < strlen(str); i++)
//	{
//		push(p, str[i]);
//	}
//	//��ջ����ת��Ϊ10���� 
//	for (i = 0; i < strlen(str); i++)
//	{
//		pop(p, a);
//		sum += pow(a, i);
//	}
//	return sum;
//}
//
//int reverse2_8(elemtype str[], sqstack1* p)
//{
//	elemtype a,b,c;
//	int i = 0, sum = 0;
//	//���ַ�����ջ 
//	for (i = 0; i < strlen(str); i++)
//	{
//		push(p, str[i]);
//	}
//	//��ջ����ת��Ϊ8���� 
//	for (i = 0; i < strlen(str); i+=3)
//	{
//		pop(p, a);
//		pop(p, b);
//		pop(p, c);
//		sum = pow(a, 2) + pow(b, 1) + pow(c, 0);
//	}
//	return sum;
//}
//
//
//
