#include"Library.h"
LinkList_book* L_book;
LinkList_student* L_student;
int main()
{
	//readInfoToFile("book.txt");
	CreateList_book();
	CreateList_student();
	srand((unsigned int)time(NULL));
	int input = 0;// 控制用户的输入的变量
	do
	{
		welcome();//进入菜单
		printf("请选择0-2:>");
		scanf("%d", &input);//用户选择
		switch(input)
		{
		case 1://选择管理员
			Librarian();//进入管理员界面
			break;
		case 2://选择用户
			User();//进入用户界面
			break;
		case 0:
			printf("退出程序\n");
			break;
		default:
			printf("输入有误，请输入0-2间的数字\n");
			break;
		}
		//system("cls");
	} while (input);//输入为0自动退出
	return 0;
}