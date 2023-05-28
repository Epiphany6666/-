#include"Library.h"
extern LinkList_book* L_book;
extern LinkList_student* L_student;
void UserMenu()//用户菜单
{
	printf("------     用户界面    ----------\n");
	printf("******  1.登录         **********\n");
	printf("******  2.注册            *******\n");
	printf("******  0.返回上一层   **********\n");
	printf("---------------------------------\n");
}

void UserMenu2()
{
	printf("------     用户使用界面 ---------\n");
	printf("******  1.查找图书     **********\n");
	printf("******  2.查看已存图书    *******\n");
	printf("******  3.借阅图书        *******\n");
	printf("******  4.归还图书        *******\n");
	printf("******  5.按照价格图书排序*******\n");
	printf("******  0.返回上一层   **********\n");
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
		printf("请输入0-5:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("--------【查找图书】---------\n");
			printf("请输入需要查找的图书名:>");
			scanf("%s", temp_name);
			temp_book = Find_book(temp_name);
			if (temp_book != NULL)
			{
				DispBook(temp_book);
			}
			else
			{
				printf("没有找到该图书\n");
			}
			break;
		case 2:
			printf("--------【查看已存图书】---------\n");
			Disp_Book();
			break;
		case 3:
			printf("--------【借阅图书】---------\n");
			printf("请输入要借阅图书的名字:>");
			scanf("%s", temp_name);
			temp_book = Find_book( temp_name);
			if (temp_book != NULL)
			{
				student->data.book[student->data.num++] = temp_book->data;//学生借的书本数量+1
				temp_book->data.num--;//图书馆里书本数量少1
			}
			else
			{
				printf("该图书尚且还未注册\n");
			}
			break;
		case 4:
			printf("--------【归还图书】---------\n");
			printf("请输入要归还图书的名字:>");
			scanf("%s", temp_name);
			temp_book = Find_book(temp_name);
			if (temp_book != NULL)
			{
				student->data.num--;
				Delete_book(temp_name);
			}
			else
			{
				printf("您还未借过该本书\n");
			}
			break;
		case 5:
			printf("--------【按照价格图书排序】---------\n");
			Sort_book();
			break;
		case 0:
			printf("-----------返回上一层------------\n");
			input = 0;
			break;
		default:
			printf("输入有误，请输入0-5间的数字\n");
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
		printf("请输入0-2:>");
		scanf("%d", &input);
		switch (input)
		{
			{
		case 1://登录
			LinkList_student * temp = NULL;//
			int account;//储存用户的账号
			char password[MAX];//储存用户的密码
			printf("--------【登录界面】---------\n");
			printf("请输入账号和密码：\n");
			printf("账号:>");
			scanf("%d", &account);
			temp = Find_student(account);
			if (temp == NULL)//未找到该账户
			{
				char ret = 0;
				printf("该用户不存在，是否注册，不注册则返回上一层：y/n:>");
				scanf(" %c", &ret);/////////////////////////////////////////
				if (ret == 'n')
				{
					break;
				}
				printf("\n");
			}
			else//找到了
			{
				while (1)
				{
					printf("密码:>");
					scanf("%s", password);
					if (!strcmp(password, temp->data.password))
					{
						printf("============登录成功==============\n");
						Register(temp);
						break;
					}
					else
					{
						printf("\n密码错误，请重新输入:>\n");
					}
				}
				break;
			}
			}
		case 2:
			printf("--------【注册界面】---------\n");
			char temp_password[MAX];
			printf("请设置密码:>");
			scanf("%s", temp_password);
			char temp_name[MAX];
			printf("\n请输入姓名:>");
			scanf("%s", temp_name);
			char temp_student_number[MAX];
			printf("\n请输入学号:>");
			scanf("%s", temp_student_number);
			insert_student(temp_password, temp_name, temp_student_number, account);
			printf("\n注册成功，你的账号为：%d\n", account);
			break;
		case 0:
			printf("-----------返回上一层------------\n");
			input = 0;
			break;
		default:
			printf("输入有误，请输入0-2间的数字\n");
			break;
		}
	} while (input);
}