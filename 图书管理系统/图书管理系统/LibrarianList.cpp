#include"Library.h"
extern LinkList_book* L_book;
extern LinkList_student* L_student;
void LibrarianMenu()//����Ա�˵�
{
	printf("-------    ����Ա����   ---------\n");
	printf("******  1.ע����ͼ��   **********\n");
	printf("******  2.�鿴�Ѵ�ͼ��    *******\n");
	printf("******  3.�޸�����ͼ��    *******\n");
	printf("******  4.ע���ִ�ͼ��    *******\n");
	printf("******  0.������һ��    *********\n");
	printf("---------------------------------\n");
}

void Librarian()
{
	int input = 0;
	do
	{
		LibrarianMenu();
		printf("�����0-4:>");
		scanf("%d", &input);
		LinkList_book* temp_book = NULL;//��ʱ�鱾
		char temp_name[MAX];//��ʱ�鱾��
		char temp_number[MAX];//��ʱ�鱾���
		double temp_price;//��ʱ�鱾�۸�
		int temp_num;//��ʱ�鱾����
		int temp;//��ʱѡ��
		switch (input)
		{
		case 1:
			printf("--------��ע����ͼ�顿---------\n");
			printf("����:>");
			scanf("%s", temp_name);
			printf("\n���:>");
			scanf("%s", temp_number);
			printf("\n�۸�:>");
			scanf("%lf", &temp_price);
			printf("\n����:>");
			scanf("%d", &temp_num);
			printf("\n");
			insert_book(temp_name, temp_number, temp_price, temp_num);
			break;
		case 2:
			printf("--------���鿴�Ѵ�ͼ�顿---------\n");
			Disp_Book();
			break;
		case 3:
			printf("--------���޸�����ͼ�顿---------\n");
			printf("��������Ҫ�޸��鱾������:>");
			scanf("%s", temp_name);
			printf("\n");
			temp_book = Find_book(temp_name);
			if (temp_book == NULL)
			{
				printf("��ͼ����δע��\n");
			}
			else
			{
				printf("-----------------------\n");
				printf("********1.����*********\n");
				printf("********2.���*********\n");
				printf("********3.�۸�*********\n");
				printf("********4.����*********\n");
				printf("��ѡ����Ҫ�޸ĵ�ѡ��:>");
				scanf("%d", &temp);
				switch (temp)
				{
				case 1:
					printf("�޸ĺ������:>");
					scanf("%s", temp_name);
					strcpy(temp_book->data.name, temp_name);
					break;
				case 2:
					printf("�޸ĺ�ı��:>");
					scanf("%s", temp_number);
					strcpy(temp_book->data.number, temp_number);
					break;
				case 3:
					printf("�޸ĺ�ļ۸�:>");
					scanf("%lf", &temp_price);
					temp_book->data.price = temp_price;
					break;
				case 4:
					printf("�޸ĺ������:>");
					scanf("%lf", &temp_num);
					temp_book->data.num = temp_num;
					break;
				}
			}
			break;
		case 4:
			printf("--------��ע���ִ�ͼ�顿---------\n");
			printf("������Ҫɾ��������:>");
			scanf("%s", temp_name);
			Delete_book(temp_name);
			printf("-----ɾ���ɹ�%s-----\n", temp_name);
			break;
		case 0:
			printf("-----------������һ��------------\n");
			input = 0;
			break;
		default:
			printf("��������������0-4�������\n");
			break;
		}
	} while (input);
}