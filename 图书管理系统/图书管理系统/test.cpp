#include"Library.h"
LinkList_book* L_book;
LinkList_student* L_student;
int main()
{
	//readInfoToFile("book.txt");
	CreateList_book();
	CreateList_student();
	srand((unsigned int)time(NULL));
	int input = 0;// �����û�������ı���
	do
	{
		welcome();//����˵�
		printf("��ѡ��0-2:>");
		scanf("%d", &input);//�û�ѡ��
		switch(input)
		{
		case 1://ѡ�����Ա
			Librarian();//�������Ա����
			break;
		case 2://ѡ���û�
			User();//�����û�����
			break;
		case 0:
			printf("�˳�����\n");
			break;
		default:
			printf("��������������0-2�������\n");
			break;
		}
		//system("cls");
	} while (input);//����Ϊ0�Զ��˳�
	return 0;
}