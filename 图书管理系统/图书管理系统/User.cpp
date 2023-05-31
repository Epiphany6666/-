#include"Library.h"
extern LinkList_book* L_book;
extern LinkList_student* L_student;

char temp_name[MAX];
Comment temp_comment;
LinkList_book* temp_book;
LinkList_student* temp = NULL;//
char choice = 0;//功能里的其他选择临时变量

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
    printf("******  6.写评论          *******\n");
    printf("******  7.查看我的评论    *******\n");
    printf("******  8.查看已借图书    *******\n");
    printf("******  9.按照受欢迎程度排序*****\n");
    printf("******  10.输入部分字查找图书   *\n");
    printf("******  0.返回上一层   **********\n");
    printf("---------------------------------\n");
}

void seekBook()
{
    printf("--------【查找图书】---------\n");
    printf("请输入需要查找的图书名:>");
    scanf("%s", temp_name);
    temp_book = Find_book(temp_name);
    if (temp_book != NULL)
    {
        DispBook(temp_book);

        printf("是否查看《%s》评论？y/n:>", temp_name);
        scanf(" %c", &choice);
        if (choice == 'y')
        {
            //printf("=========该书共有%d条评论=======\n", temp_book->data.num_comment);
            DispComment_book(temp_book->data);
        }
    }
    else
    {
        printf("没有找到该图书\n");
    }
}

void Register(LinkList_student* student)
{
    int input;
    int count = 0;
    int i = 0;
    int ret = 0;
    CreateList_book(temp_book);
    do
    {
        UserMenu2();
        printf("请输入0-5:>");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            system("cls");
            seekBook();
            break;
        case 2:
            system("cls");
            printf("--------【查看已存图书】---------\n");
            Disp_Book();
            break;
        case 3:
            system("cls");
            printf("--------【借阅图书】---------\n");
            printf("请输入要借阅图书的名字:>");
            scanf("%s", temp_name);
            temp_book = Find_book(temp_name);
            if (temp_book != NULL)
            {
                student->data.book[student->data.num_book++] = temp_book->data;//学生借的书本数量+1
                temp_book->data.student[temp_book->data.num_lend++] = student->data.student;
                temp_book->data.num--;//图书馆里书本数量少1
            }
            else
            {
                printf("该图书尚且还未注册\n");
            }
            saveInfoToFile_book("book.txt");
            saveInfoToFile_student("student.txt");
            break;
        case 4:
            system("cls");
            printf("--------【归还图书】---------\n");
            printf("请输入要归还图书的名字:>");
            scanf("%s", temp_name);
            temp_book = Find_book(temp_name);
            if (temp_book != NULL)
            {
                temp_book->data.num_lend--;//借书的数量-1
                temp_book->data.num++;//图书馆里书本数量加1
                delete_book(student->data.book, student->data.num_book, temp_name);
                student->data.num_book--;//学生借的书本数量-1
            }
            else
            {
                printf("您还未借过该本书\n");
            }
            saveInfoToFile_book("book.txt");
            break;
        case 5:
            system("cls");
            printf("--------【按照价格图书排序】---------\n");
            Sort_book();
            break;
        case 6:
            system("cls");
            printf("--------【评论】---------\n");
            printf("请输入需要评论的书籍:>");
            scanf("%s", temp_name);
            temp_book = Find_book(temp_name);
            if (temp_book != NULL)
            {
                printf("请输入你的评论:>");
                temp_comment.student = student->data.student;
                scanf("%s", temp_comment.data);
                time(&temp_comment.timep);
                strcpy(temp_comment.time, asctime(gmtime(&temp_comment.timep)));//字符串复制用strcpy
                temp_book->data.comment[temp_book->data.num_comment++] = temp_comment;
                student->data.comment[student->data.num_comment++] = temp_comment;
                saveInfoToFile_book("book.txt");
                saveInfoToFile_student("student.txt");
                printf("====成功写入评论====\n");
            }
            else
            {
                printf("==========该书尚未注册=======\n");
            }
            break;
        case 7:
            system("cls");
            printf("--------【查看我的评论 】---------\n");
            printf("======我共有%d条评论========\n", student->data.num_comment);
            DispComment_student(student->data);
            break;
        case 8:
            system("cls");
            printf("--------【查看已借图书 】---------\n");
            for (i = 0; i < student->data.num_book; i++)
            {
                temp_book = Find_book(student->data.book[i].name);
                DispBook(temp_book);
            }
            break;
        case 9:
            system("cls");
            printf("--------【查看已借图书 】---------\n");
            welcome_book();
            break;
        case 10:
            system("cls");
            LinkList_book * book1[MAX];
            count = 0;//记录数量
            printf("--------【输入部分字查找图书】---------\n");
            printf("请输入需要查找的图书名:>");
            scanf("%s", temp_name);
            ret = Find_book11(book1, count, temp_name);
            if (ret == 1)
            {
                for (i = 0; i < count; i++)
                {
                    DispBook(book1[i]);
                }
            }
            else
            {
                printf("没有找到该图书\n");
            }
            break;
        case 0:
            system("cls");
            printf("-----------返回上一层------------\n");
            input = 0;
            break;
        default:
            system("cls");
            printf("输入有误，请输入0-5间的数字\n");
            break;
        }
    } while (input);
}

void User()
{
    CreateList_student(temp);
    int input;
    int account;
    do
    {
        UserMenu();
        printf("请输入0-2:>");
        scanf("%d", &input);
        switch (input)
        {
            //{
        case 1://登录
            //LinkList_student * temp = NULL;//
            system("cls");
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
                    if (strcmp(password, temp->data.student.password) == 0)
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
            //}
        case 2:
            system("cls");
            CreateList_student(temp);
            printf("--------【注册界面】---------\n");
            while (1)
            {
                account = rand();
                if (Find_student(account) == NULL)
                {
                    break;
                }
            }
            //char temp_password[MAX];
            temp->data.student.account = account;
            printf("请设置密码:>");
            scanf("%s", temp->data.student.password);
            //char temp_name[MAX];
            printf("\n请输入姓名:>");
            scanf("%s", temp->data.student.name);
            //char temp_student_number[MAX];
            printf("\n请输入学号:>");
            scanf("%s", temp->data.student.student_number);
            insert_student(temp->data);
            printf("\n注册成功，你的账号为：%d\n", account);
            saveInfoToFile_student("student.txt");
            break;
        case 0:
            system("cls");
            printf("-----------返回上一层------------\n");
            input = 0;
            break;
        default:
            system("cls");
            printf("输入有误，请输入0-2间的数字\n");
            break;
        }
    } while (input);
}
