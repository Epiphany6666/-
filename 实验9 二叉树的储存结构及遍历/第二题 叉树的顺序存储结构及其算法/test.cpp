#include"Sqtree.h"
extern ElemType N1;

int main() {
	SqBiTree b;
	ElemType t[MaxSize] = "ABCDE#F##GH##I#";
	//��ʼ��˳�������
	InitBiTree(b);
	//���ɶ�����
	CreateBiTree(b,t);

	//��˫�׽��
	printf("������һ�����:>");
	ElemType e, i;
	scanf("%c", &e);
	printf("%c��˫�׽��Ϊ��%c\n",e, Parent(b, e));

	//������
	i = lclild(b, e);
	if (i != '#' && i != N1) {
		printf("%c��������%c\n", e, i);
	}
	else {
		printf("%c������\n",e);
	}

	//���Һ���
	i = rchild(b, e);
	if (i != '#' && i != N1) {
		printf("%c���Һ�����%c\n", e, i);
	}
	else {
		printf("%c���Һ���\n",e);
	}
	return 0;
}