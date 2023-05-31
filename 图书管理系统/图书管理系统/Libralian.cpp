#include"Library.h"
extern LinkList_book* L_book;
extern LinkList_student* L_student;
void LibrarianMenu()//管理员菜单
{
    printf("-------    管理员界面   ---------\n");
    printf("******  1.注册新图书   **********\n");
    printf("******  2.查看已存图书    *******\n");
    printf("******  3.修改已有图书    *******\n");
    printf("******  4.注销现存图书    *******\n");
    printf("******  5.查看借某本书的学生  ***\n");
    printf("******  0.返回上一层    *********\n");
    printf("---------------------------------\n");
}

void Librarian()
{
    int input = 0;
    int ret = 0;
    do
    {
        LibrarianMenu();
        printf("请输出0-4:>");
        scanf("%d", &input);
        LinkList_book* temp_book = NULL;//临时书本
        CreateList_book(temp_book);
        char temp_name[MAX];//临时书本名
        char temp_number[MAX];//临时书本编号
        double temp_price;//临时书本价格
        int temp_num;//临时书本数量
        int temp;//临时选项
        switch (input)
        {
        case 1:
            system("cls");
            printf("--------【注册新图书】---------\n");
            printf("书名:>");
            scanf("%s", temp_book->data.name);
            printf("\n编号:>");
            scanf("%s", temp_book->data.number);
            printf("\n价格:>");
            scanf("%lf", &temp_book->data.price);
            printf("\n数量:>");
            scanf("%d", &temp_book->data.num);
            printf("\n");
            insert_book(temp_book->data);
            saveInfoToFile_book("book.txt");
            break;
        case 2:
            system("cls");
            printf("--------【查看已存图书】---------\n");
            Disp_Book();
            break;
        case 3:
            system("cls");
            printf("--------【修改已有图书】---------\n");
            printf("请输入需要修改书本的名字:>");
            scanf("%s", temp_name);
            printf("\n");
            temp_book = Find_book(temp_name);
            if (temp_book == NULL)
            {
                printf("该图书尚未注册\n");
            }
            else
            {
                printf("-----------------------\n");
                printf("********1.书名*********\n");
                printf("********2.编号*********\n");
                printf("********3.价格*********\n");
                printf("********4.数量*********\n");
                printf("请选择需要修改的选项:>");
                scanf("%d", &temp);
                switch (temp)
                {
                case 1:
                    printf("修改后的书名:>");
                    scanf("%s", temp_name);
                    strcpy(temp_book->data.name, temp_name);
                    break;
                case 2:
                    printf("修改后的编号:>");
                    scanf("%s", temp_number);
                    strcpy(temp_book->data.number, temp_number);
                    break;
                case 3:
                    printf("修改后的价格:>");
                    scanf("%lf", &temp_price);
                    temp_book->data.price = temp_price;
                    break;
                case 4:
                    printf("修改后的数量:>");
                    scanf("%lf", &temp_num);
                    temp_book->data.num = temp_num;
                    break;
                }
            }
            saveInfoToFile_book("book.txt");
            break;
        case 4:
            system("cls");
            printf("--------【注销现存图书】---------\n");
            printf("请输入要删除的书名:>");
            scanf("%s", temp_name);
            ret = Delete_book(temp_name);
            if (ret == 1)
            {
                printf("-----删除成功《%s》-----\n", temp_name);
                saveInfoToFile_book("book.txt");
            }
            else
            {
                printf("-----删除失败-----\n");
            }
            break;
        case 5:
            printf("--------【查看借某本书的学生】---------\n");
            printf("请输入要查询的书本名字:>");
            scanf("%s", temp_name);
            temp_book = Find_book(temp_name);
            Disp_student(temp_book);
            break;
        case 0:
            system("cls");
            printf("-----------返回上一层------------\n");
            input = 0;
            break;
        default:
            system("cls");
            printf("输入有误，请输入0-4间的数字\n");
            break;
        }
    } while (input);
}
