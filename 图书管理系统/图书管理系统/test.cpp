#include"Library.h"
LinkList_book* L_book;
LinkList_student* L_student;
int main()
{
    CreateList_book(L_book);
    CreateList_student(L_student);
    readInfoToFile_book("book.txt");
    readInfoToFile_student("student.txt");
    srand((unsigned int)time(NULL));
    int input = 0;// �����û�������ı���
    do
    {
        welcome();//����˵�
        printf("��ѡ��0-2:>");
        scanf("%d", &input);//�û�ѡ��
        switch (input)
        {
        case 1://ѡ�����Ա
            system("cls");
            Librarian();//�������Ա����
            break;
        case 2://ѡ���û�
            system("cls");
            User();//�����û�����
            break;
        case 0:
            system("cls");
            printf("�˳�����\n");
            break;
        default:
            system("cls");
            printf("��������������0-2�������\n");
            break;
        }
        //system("cls");
    } while (input);//����Ϊ0�Զ��˳�
    return 0;
}