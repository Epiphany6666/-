#include"Library.h"
extern LinkList_book* L_book;
extern LinkList_student* L_student;

void welcome()
{
    printf("------  图书管理系统  -----------\n");
    printf("******  1.管理员身份   **********\n");
    printf("******  2.用户身份     **********\n");
    printf("******  0.退出程序     **********\n");
    printf("---------------------------------\n");
}

//创建链表
void CreateList_book(LinkList_book*& book)
{
    book = (LinkList_book*)malloc(sizeof(LinkList_book));
    book->next = NULL;
}
void CreateList_student(LinkList_student*& student)
{
    student = (LinkList_student*)malloc(sizeof(LinkList_student));
    student->next = NULL;
}

//链表的插入
void insert_book(Book book)
{
    LinkList_book* p = NULL;
    p = (LinkList_book*)malloc(sizeof(LinkList_book));
    //Book book = { name, book_number, price, num};//?
    //Book book;
    strcpy(p->data.name, book.name);
    strcpy(p->data.number, book.number);
    p->data.price = book.price;
    p->data.num = book.num;
    p->data.num_comment = 0;
    p->data.num_student = 0;
    p->data.num_lend = 0;
    //p->data = book;
    LinkList_book* q = NULL;
    q = L_book;
    while (q->next != NULL)
    {
        q = q->next;
    }
    p->next = q->next;
    q->next = p;
}

void insert_student(Student student)
{
    LinkList_student* p = NULL;
    p = (LinkList_student*)malloc(sizeof(LinkList_student));
    //account = rand();//随机分配一个账户
   /* while (1)
    {
        account = rand();
        if (Find_student(account) == NULL)
        {
            break;
        }
    }*/
    //Student student = { temp_account, password, name, student_number, 0 };//?
    //Student student;
    p->data.student.account = student.student.account;
    strcpy(p->data.student.password, student.student.password);
    strcpy(p->data.student.name, student.student.name);
    strcpy(p->data.student.student_number, student.student.student_number);
    p->data.num_book = 0;
    p->data.num_comment = 0;
    p->data.num_student = 0;
    //p->data = student;
    LinkList_student* q = NULL;
    q = L_student;
    while (q->next != NULL)
    {
        q = q->next;
    }
    p->next = q->next;
    q->next = p;
}

//根据账号查找
LinkList_student* Find_student(int account)
{
    LinkList_student* p = NULL;
    p = L_student->next;
    while (p != NULL)
    {
        if (p->data.student.account == account)
        {
            break;
        }
        p = p->next;
    }
    return p;
}
//根据图书名字查找
LinkList_book* Find_book(char name[])
{
    LinkList_book* p = NULL;
    p = L_book->next;
    while (p != NULL)
    {
        if (strcmp(p->data.name, name) == 0)
        {
            break;
        }
        p = p->next;
    }
    return p;
}

LinkList_book* Find_comment(char comment[])//查找评论所在的书籍//不能返回Book，因为p有可能为空
{
    int i = 0;
    LinkList_book* p = NULL;
    p = L_book->next;
    int flag = 0;
    while (p != NULL && flag == 0)
    {
        for (i = 0; i < p->data.num_comment; i++)
        {
            if (strcmp(p->data.comment[i].data, comment) == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        p = p->next;
    }
    return p;
}


//打印单本书
void DispBook(LinkList_book* book)
{
    char name[] = "书名";
    char number[] = "编号";
    char price[] = "价格";
    char num[] = "数量";
    char num1[] = "借出数量";
    printf("%-16s%-16s%-16s%-16s%s\n", name, number, price, num, num1);
    printf("%-16s%-16s%-16f%-16d%d\n", book->data.name,
        book->data.number, book->data.price, book->data.num, book->data.num_lend);
}

//打印所有图书
void Disp_Book()
{
    LinkList_book* temp_book = L_book->next;
    while (temp_book != NULL)
    {
        DispBook(temp_book);
        temp_book = temp_book->next;
    }
}

//删除书
int Delete_book(char name[])

{
    LinkList_book* p = NULL, * q = NULL;
    p = L_book;
    q = p->next;
    int flag = 0;
    while (q != NULL)
    {
        if (strcmp(q->data.name, name) == 0)
        {
            p->next = q->next;
            free(q);
            flag = 1;
            break;
        }
        p = p->next;
        q = p->next;
    }
    return flag;
}

void delete_book(Book book[], int num, char name[])//学生账号里面删除书
{
    int i = 0;
    int j = 0;
    for (i = 0; i < num; i++)
    {
        if (strcmp(book[i].name, name))
        {
            break;
        }
    }
    for (j = i; j < num - 1; j++)
    {
        book[j] = book[j + 1];
    }
}

//删除学生账号
int Delete_student(char name[])
{
    int flag = 0;
    LinkList_student* p = NULL, * q;
    q = p = L_student->next;
    while (p != NULL)
    {
        if (strcmp(p->data.student.name, name) == 0)
        {
            p->next = q->next;
            free(q);
            flag = 1;
            break;
        }
        p = p->next;
        q = p->next;
    }
    return flag;
}

//按照价格图书排序
void Sort_book()
{
    LinkList_book* p = L_book->next;
    LinkList_book* book1 = NULL;
    Book book[MAX];
    int count = 0;
    while (p != NULL)
    {
        book[count++] = p->data;
        p = p->next;
    }
    int i = 0;
    int j = 0;
    for (i = 0; i < count - 1; i++)
    {
        for (j = 0; j < count - i - 1; j++)
        {
            if (book[j].price > book[j + 1].price)
            {
                Book temp_book = book[j];
                book[j] = book[j + 1];
                book[j + 1] = temp_book;
            }
        }
    }
    for (i = 0; i < count; i++)
    {
        book1 = (LinkList_book*)malloc(sizeof(LinkList_book));
        book1->data = book[i];
        DispBook(book1);
    }
}

//按受欢迎程度排序
void welcome_book()
{
    LinkList_book* p = L_book->next;
    LinkList_book* book1 = NULL;
    Book book[MAX];
    int count = 0;
    while (p != NULL)
    {
        book[count++] = p->data;
        p = p->next;
    }
    int i = 0;
    int j = 0;
    for (i = 0; i < count - 1; i++)
    {
        for (j = 0; j < count - i - 1; j++)
        {
            if (book[j].num_lend < book[j + 1].num_lend)
            {
                Book temp_book = book[j];
                book[j] = book[j + 1];
                book[j + 1] = temp_book;
            }
        }
    }
    for (i = 0; i < count; i++)
    {
        book1 = (LinkList_book*)malloc(sizeof(LinkList_book));
        book1->data = book[i];
        DispBook(book1);
    }
}

//文件写操作
void saveInfoToFile_book(const char* FileName)//书
{
    FILE* pf = fopen(FileName, "w");
    LinkList_book* pMove = L_book->next;
    while (pMove != NULL)
    {
        //fwrite(&pMove, sizeof(Book), 1, pf);
        fwrite(&pMove->data, sizeof(Book), 1, pf);
        pMove = pMove->next;
    }
    fclose(pf);
    pf = NULL;
}

void saveInfoToFile_student(const char* FileName)
{
    FILE* pf = fopen(FileName, "w");
    LinkList_student* pMove = L_student->next;
    while (pMove != NULL)
    {
        //fwrite(&pMove, sizeof(Student), 1, pf);
        fwrite(&pMove->data, sizeof(Student), 1, pf);
        pMove = pMove->next;
    }
    fclose(pf);
    pf = NULL;
}
//文件读操作
void readInfoToFile_book(const char* FileName)
{
    FILE* pf = fopen(FileName, "r");
    if (pf == NULL)
    {
        pf = fopen(FileName, "w+");
    }
    //LinkList_book* pMove = NULL;
    Book book;
    //while (fread(&pMove, sizeof(Book), 1, pf) != 0)
    while (1)
    {
        /*pMove = (LinkList_book*)malloc(sizeof(LinkList_book));
        insert_book(pMove->data.name, pMove->data.number, pMove->data.price, pMove->data.num);*/
        if (fread(&book, sizeof(Book), 1, pf) != 1)
            break;
        insert_book(book);
    }
    fclose(pf);
    pf = NULL;
}

void readInfoToFile_student(const char* FileName)
{
    FILE* pf = fopen(FileName, "r");
    if (pf == NULL)
    {
        pf = fopen(FileName, "w+");
    }
    //LinkList_student* pMove = NULL;
    Student student1;
    //while (fread(&pMove, sizeof(Book), 1, pf) != 0)
    while (1)
    {
        /*pMove = (LinkList_student*)malloc(sizeof(LinkList_student));
        insert_student(pMove->data.password, pMove->data.name, pMove->data.student_number, pMove->data.account);*/
        if (fread(&student1, sizeof(Student), 1, pf) != 1)
            break;
        insert_student(student1);
    }
    fclose(pf);
    pf = NULL;
}

void DispComment_book(Book book)
{
    int i = 0;
    printf("========该书共有%d条评论=======\n", book.num_comment);
    for (i = 0; i < book.num_comment; i++)
    {
        printf("%-10s%s评论内容：%s\n", book.comment[i].student.name, book.comment[i].time, book.comment[i].data);
    }
}

void DispComment_student(Student student)
{
    int i = 0;
    LinkList_book* temp_book;
    for (i = 0; i < student.num_comment; i++)
    {
        temp_book = Find_comment(student.comment[i].data);
        printf("《%s》%-5s评论内容：%s\n", temp_book->data.name, student.comment[i].time, student.comment[i].data);
    }
}

void Disp_student(LinkList_book* book)
{
    int i = 0;
    for (i = 0; i < book->data.num_lend; i++)
    {
        char account[] = "账号";
        char name[] = "姓名";
        char student_number[] = "学号";
        printf("%-8s%-8s%s\n", account, name, student_number);
        printf("%-8d%-8s%s\n", book->data.student[i].account, book->data.student[i].name, book->data.student[i].student_number);
    }
}

int Find_book11(LinkList_book* book1[MAX], int &count, char name[])
{
    LinkList_book* p = L_book->next;
    char temp_name[MAX];
    int flag = 0;//标记是否找到
    while (p != NULL)
    {
        strncpy(temp_name, p->data.name, strlen(name));
        temp_name[strlen(name)] = '\0';
        if (strcmp(temp_name, name) == 0)
        {
            flag = 1;
            book1[count++] = p;
        }
        p = p->next;
    }
    return flag;
}