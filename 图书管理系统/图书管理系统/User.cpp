#include"Library.h"
extern LinkList_book* L_book;
extern LinkList_student* L_student;

char temp_name[MAX];
Comment temp_comment;
LinkList_book* temp_book;
LinkList_student* temp = NULL;//
char choice = 0;//�����������ѡ����ʱ����

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
    printf("******  6.д����          *******\n");
    printf("******  7.�鿴�ҵ�����    *******\n");
    printf("******  8.�鿴�ѽ�ͼ��    *******\n");
    printf("******  9.�����ܻ�ӭ�̶�����*****\n");
    printf("******  10.���벿���ֲ���ͼ��   *\n");
    printf("******  0.������һ��   **********\n");
    printf("---------------------------------\n");
}

void seekBook()
{
    printf("--------������ͼ�顿---------\n");
    printf("��������Ҫ���ҵ�ͼ����:>");
    scanf("%s", temp_name);
    temp_book = Find_book(temp_name);
    if (temp_book != NULL)
    {
        DispBook(temp_book);

        printf("�Ƿ�鿴��%s�����ۣ�y/n:>", temp_name);
        scanf(" %c", &choice);
        if (choice == 'y')
        {
            //printf("=========���鹲��%d������=======\n", temp_book->data.num_comment);
            DispComment_book(temp_book->data);
        }
    }
    else
    {
        printf("û���ҵ���ͼ��\n");
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
        printf("������0-5:>");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            system("cls");
            seekBook();
            break;
        case 2:
            system("cls");
            printf("--------���鿴�Ѵ�ͼ�顿---------\n");
            Disp_Book();
            break;
        case 3:
            system("cls");
            printf("--------������ͼ�顿---------\n");
            printf("������Ҫ����ͼ�������:>");
            scanf("%s", temp_name);
            temp_book = Find_book(temp_name);
            if (temp_book != NULL)
            {
                student->data.book[student->data.num_book++] = temp_book->data;//ѧ������鱾����+1
                temp_book->data.student[temp_book->data.num_lend++] = student->data.student;
                temp_book->data.num--;//ͼ������鱾������1
            }
            else
            {
                printf("��ͼ�����һ�δע��\n");
            }
            saveInfoToFile_book("book.txt");
            saveInfoToFile_student("student.txt");
            break;
        case 4:
            system("cls");
            printf("--------���黹ͼ�顿---------\n");
            printf("������Ҫ�黹ͼ�������:>");
            scanf("%s", temp_name);
            temp_book = Find_book(temp_name);
            if (temp_book != NULL)
            {
                temp_book->data.num_lend--;//���������-1
                temp_book->data.num++;//ͼ������鱾������1
                delete_book(student->data.book, student->data.num_book, temp_name);
                student->data.num_book--;//ѧ������鱾����-1
            }
            else
            {
                printf("����δ����ñ���\n");
            }
            saveInfoToFile_book("book.txt");
            break;
        case 5:
            system("cls");
            printf("--------�����ռ۸�ͼ������---------\n");
            Sort_book();
            break;
        case 6:
            system("cls");
            printf("--------�����ۡ�---------\n");
            printf("��������Ҫ���۵��鼮:>");
            scanf("%s", temp_name);
            temp_book = Find_book(temp_name);
            if (temp_book != NULL)
            {
                printf("�������������:>");
                temp_comment.student = student->data.student;
                scanf("%s", temp_comment.data);
                time(&temp_comment.timep);
                strcpy(temp_comment.time, asctime(gmtime(&temp_comment.timep)));//�ַ���������strcpy
                temp_book->data.comment[temp_book->data.num_comment++] = temp_comment;
                student->data.comment[student->data.num_comment++] = temp_comment;
                saveInfoToFile_book("book.txt");
                saveInfoToFile_student("student.txt");
                printf("====�ɹ�д������====\n");
            }
            else
            {
                printf("==========������δע��=======\n");
            }
            break;
        case 7:
            system("cls");
            printf("--------���鿴�ҵ����� ��---------\n");
            printf("======�ҹ���%d������========\n", student->data.num_comment);
            DispComment_student(student->data);
            break;
        case 8:
            system("cls");
            printf("--------���鿴�ѽ�ͼ�� ��---------\n");
            for (i = 0; i < student->data.num_book; i++)
            {
                temp_book = Find_book(student->data.book[i].name);
                DispBook(temp_book);
            }
            break;
        case 9:
            system("cls");
            printf("--------���鿴�ѽ�ͼ�� ��---------\n");
            welcome_book();
            break;
        case 10:
            system("cls");
            LinkList_book * book1[MAX];
            count = 0;//��¼����
            printf("--------�����벿���ֲ���ͼ�顿---------\n");
            printf("��������Ҫ���ҵ�ͼ����:>");
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
                printf("û���ҵ���ͼ��\n");
            }
            break;
        case 0:
            system("cls");
            printf("-----------������һ��------------\n");
            input = 0;
            break;
        default:
            system("cls");
            printf("��������������0-5�������\n");
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
        printf("������0-2:>");
        scanf("%d", &input);
        switch (input)
        {
            //{
        case 1://��¼
            //LinkList_student * temp = NULL;//
            system("cls");
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
                    if (strcmp(password, temp->data.student.password) == 0)
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
            //}
        case 2:
            system("cls");
            CreateList_student(temp);
            printf("--------��ע����桿---------\n");
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
            printf("����������:>");
            scanf("%s", temp->data.student.password);
            //char temp_name[MAX];
            printf("\n����������:>");
            scanf("%s", temp->data.student.name);
            //char temp_student_number[MAX];
            printf("\n������ѧ��:>");
            scanf("%s", temp->data.student.student_number);
            insert_student(temp->data);
            printf("\nע��ɹ�������˺�Ϊ��%d\n", account);
            saveInfoToFile_student("student.txt");
            break;
        case 0:
            system("cls");
            printf("-----------������һ��------------\n");
            input = 0;
            break;
        default:
            system("cls");
            printf("��������������0-2�������\n");
            break;
        }
    } while (input);
}
