#include"Library.h"
extern LinkList_book* L_book;
extern LinkList_student* L_student;
void UserMenu()//�û��˵�
{
	printf("------     �û�����    ----------\n");
	printf("******  1.��¼         **********\n");
	printf("******  2.ע��            *******\n");
	printf("******  0.������һ��   **********\n");
	printf("---------------------------------\n");
}

void UserMenu2()
{
	printf("------     �û�ʹ�ý��� ---------\n");
	printf("******  1.����ͼ��     **********\n");
	printf("******  2.�鿴�Ѵ�ͼ��    *******\n");
	printf("******  3.����ͼ��        *******\n");
	printf("******  4.�黹ͼ��        *******\n");
	printf("******  5.���ռ۸�ͼ������*******\n");
	printf("******  0.������һ��   **********\n");
	printf("---------------------------------\n");
}

void Register(LinkList_student* student)
{
	int input;
	char temp_name[MAX];
	LinkList_book* temp_book;
	do
	{
		UserMenu2();
		printf("������0-5:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("--------������ͼ�顿---------\n");
			printf("��������Ҫ���ҵ�ͼ����:>");
			scanf("%s", temp_name);
			temp_book = Find_book(temp_name);
			if (temp_book != NULL)
			{
				DispBook(temp_book);
			}
			else
			{
				printf("û���ҵ���ͼ��\n");
			}
			break;
		case 2:
			printf("--------���鿴�Ѵ�ͼ�顿---------\n");
			Disp_Book();
			break;
		case 3:
			printf("--------������ͼ�顿---------\n");
			printf("������Ҫ����ͼ�������:>");
			scanf("%s", temp_name);
			temp_book = Find_book( temp_name);
			if (temp_book != NULL)
			{
				student->data.book[student->data.num++] = temp_book->data;//ѧ������鱾����+1
				temp_book->data.num--;//ͼ������鱾������1
			}
			else
			{
				printf("��ͼ�����һ�δע��\n");
			}
			break;
		case 4:
			printf("--------���黹ͼ�顿---------\n");
			printf("������Ҫ�黹ͼ�������:>");
			scanf("%s", temp_name);
			temp_book = Find_book(temp_name);
			if (temp_book != NULL)
			{
				student->data.num--;
				Delete_book(temp_name);
			}
			else
			{
				printf("����δ����ñ���\n");
			}
			break;
		case 5:
			printf("--------�����ռ۸�ͼ������---------\n");
			Sort_book();
			break;
		case 0:
			printf("-----------������һ��------------\n");
			input = 0;
			break;
		default:
			printf("��������������0-5�������\n");
			break;
		}
	} while (input);
}

void User()
{
	int input;
	int account;
	do
	{
		UserMenu();
		printf("������0-2:>");
		scanf("%d", &input);
		switch (input)
		{
			{
		case 1://��¼
			LinkList_student * temp = NULL;//
			int account;//�����û����˺�
			char password[MAX];//�����û�������
			printf("--------����¼���桿---------\n");
			printf("�������˺ź����룺\n");
			printf("�˺�:>");
			scanf("%d", &account);
			temp = Find_student(account);
			if (temp == NULL)//δ�ҵ����˻�
			{
				char ret = 0;
				printf("���û������ڣ��Ƿ�ע�ᣬ��ע���򷵻���һ�㣺y/n:>");
				scanf(" %c", &ret);/////////////////////////////////////////
				if (ret == 'n')
				{
					break;
				}
				printf("\n");
			}
			else//�ҵ���
			{
				while (1)
				{
					printf("����:>");
					scanf("%s", password);
					if (!strcmp(password, temp->data.password))
					{
						printf("============��¼�ɹ�==============\n");
						Register(temp);
						break;
					}
					else
					{
						printf("\n�����������������:>\n");
					}
				}
				break;
			}
			}
		case 2:
			printf("--------��ע����桿---------\n");
			char temp_password[MAX];
			printf("����������:>");
			scanf("%s", temp_password);
			char temp_name[MAX];
			printf("\n����������:>");
			scanf("%s", temp_name);
			char temp_student_number[MAX];
			printf("\n������ѧ��:>");
			scanf("%s", temp_student_number);
			insert_student(temp_password, temp_name, temp_student_number, account);
			printf("\nע��ɹ�������˺�Ϊ��%d\n", account);
			break;
		case 0:
			printf("-----------������һ��------------\n");
			input = 0;
			break;
		default:
			printf("��������������0-2�������\n");
			break;
		}
	} while (input);
}