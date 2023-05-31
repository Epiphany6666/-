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
    printf("******  5.�鿴��ĳ�����ѧ��  ***\n");
    printf("******  0.������һ��    *********\n");
    printf("---------------------------------\n");
}

void Librarian()
{
    int input = 0;
    int ret = 0;
    do
    {
        LibrarianMenu();
        printf("�����0-4:>");
        scanf("%d", &input);
        LinkList_book* temp_book = NULL;//��ʱ�鱾
        CreateList_book(temp_book);
        char temp_name[MAX];//��ʱ�鱾��
        char temp_number[MAX];//��ʱ�鱾���
        double temp_price;//��ʱ�鱾�۸�
        int temp_num;//��ʱ�鱾����
        int temp;//��ʱѡ��
        switch (input)
        {
        case 1:
            system("cls");
            printf("--------��ע����ͼ�顿---------\n");
            printf("����:>");
            scanf("%s", temp_book->data.name);
            printf("\n���:>");
            scanf("%s", temp_book->data.number);
            printf("\n�۸�:>");
            scanf("%lf", &temp_book->data.price);
            printf("\n����:>");
            scanf("%d", &temp_book->data.num);
            printf("\n");
            insert_book(temp_book->data);
            saveInfoToFile_book("book.txt");
            break;
        case 2:
            system("cls");
            printf("--------���鿴�Ѵ�ͼ�顿---------\n");
            Disp_Book();
            break;
        case 3:
            system("cls");
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
            saveInfoToFile_book("book.txt");
            break;
        case 4:
            system("cls");
            printf("--------��ע���ִ�ͼ�顿---------\n");
            printf("������Ҫɾ��������:>");
            scanf("%s", temp_name);
            ret = Delete_book(temp_name);
            if (ret == 1)
            {
                printf("-----ɾ���ɹ���%s��-----\n", temp_name);
                saveInfoToFile_book("book.txt");
            }
            else
            {
                printf("-----ɾ��ʧ��-----\n");
            }
            break;
        case 5:
            printf("--------���鿴��ĳ�����ѧ����---------\n");
            printf("������Ҫ��ѯ���鱾����:>");
            scanf("%s", temp_name);
            temp_book = Find_book(temp_name);
            Disp_student(temp_book);
            break;
        case 0:
            system("cls");
            printf("-----------������һ��------------\n");
            input = 0;
            break;
        default:
            system("cls");
            printf("��������������0-4�������\n");
            break;
        }
    } while (input);
}
