#include"Library.h"
extern LinkList_book* L_book;
extern LinkList_student* L_student;
//文件写操作
//void saveInfoToFile_book(const char* FileName)//书
//{
//	FILE* pf = fopen(FileName, "w");
//	LinkList_book* pMove = L_book->next;
//	while (pMove != NULL)
//	{
//		fprintf(pf, "%s\t%s\t%d\t%d\n", pMove->data.name, pMove->data.number, pMove->data.price, pMove->data.num);
//		pMove = pMove->next;
//	}
//	fclose(pf);
//	pf = NULL;
//}

//void saveInfoToFile_student(const char* FileName)
//{
//	FILE* pf = fopen(FileName, "w");
//	LinkList_student* pMove = L_student->next;
//	while (pMove != NULL)
//	{
//		fprintf(pf, "%d\t%s\t%s\t%s\t%d\n", pMove->data.account, pMove->data.password, pMove->data.name,
//			pMove->data.student_number, pMove->data.num);
//		fwrite(&pf, sizeof(Book), 1, pf);
//	}
//}
//文件读操作
//void readInfoToFile_book(const char* FileName)
//{
//	FILE* pf = fopen(FileName, "r");
//	if (pf == NULL)
//	{
//		pf = fopen(FileName, "w+");
//	}
//	Book temp_book;
//	while (fscanf(pf, "%s\t%s\t%d\t%d\n", temp_book.name, temp_book.number, temp_book.price, temp_book.num) != EOF);
//	{
//		insert_book(temp_book.name, temp_book.number, temp_book.price, temp_book.num);
//	}
//	fclose(pf);
//	pf = NULL;
//}

void welcome()
{
	printf("------  图书管理系统  -----------\n");
	printf("******  1.管理员身份   **********\n");
	printf("******  2.用户身份     **********\n");
	printf("******  0.退出程序     **********\n");
	printf("---------------------------------\n");
}

//创建链表
void CreateList_book()
{
	L_book = (LinkList_book*)malloc(sizeof(LinkList_book));
	L_book->next = NULL;
}
void CreateList_student()
{
	L_student = (LinkList_student*)malloc(sizeof(LinkList_student));
	L_student->next = NULL;
}

//链表的插入
void insert_book(char name[], char book_number[], double price, int num)
{
	LinkList_book* p = NULL;
	p = (LinkList_book*)malloc(sizeof(LinkList_book));
	//Book book = { name, book_number, price, num};//?
	Book book;
	strcpy(book.name, name);
	strcpy(book.number, book_number);
	book.price = price;
	book.num = num;
	p->data = book;
	LinkList_book* q = NULL;
	q = L_book;
	while (q->next != NULL)
	{
		q = q->next;
	}
	p->next = q->next;
	q->next = p;
}

void insert_student( char password[], char name[], char student_number[],int &account)
{
	LinkList_student* p = NULL;
	p = (LinkList_student*)malloc(sizeof(LinkList_student));
	//account = rand();//随机分配一个账户
	while(1)
	{
		account = rand(); 
		if (Find_student(account) == NULL)
		{
			break;
		}
	}
	//Student student = { temp_account, password, name, student_number, 0 };//?
	Student student;
	student.account = account;
	strcpy(student.password, password);
	strcpy(student.name, name);
	strcpy(student.student_number, student_number);
	student.num = 0;
	p->data = student;
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
		if (p->data.account == account)
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
		if (!strcmp(p->data.name, name))
		{
			break;
		}
		p = p->next;
	}
	return p;
}

//打印单本书
void DispBook(LinkList_book* book)
{
	printf("书名\t编号\t价格\t数量\n");
	printf("%s\t%s\t%f\t%d\n", book->data.name, book->data.number, book->data.price, book->data.num);
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
void Delete_book(char name[])

{
	LinkList_book* p = NULL, *q = NULL;
	p = L_book;
	q = p->next;
	while (q != NULL)
	{
		if (strcmp(q->data.name, name) == 0)
		{
			p->next = q->next;
			free(q);
			break;
		}
		p = p->next;
		q = p->next;
	}
}

//删除学生账号
void Delete_student(char name[])
{
	LinkList_student* p = NULL, * q;
	q = p = L_student->next;
	while (p != NULL)
	{
		if (!strcmp(p->data.name, name))
		{
			q = q->next;
			break;
		}
		p = p->next;
		q = q->next;
	}
	p->next = q->next;
	free(q);
}

//按照价格图书排序
void Sort_book()
{
	LinkList_book* temp_book = L_book;//复制单链表
	LinkList_book* p = NULL, * q = NULL, *r = NULL;//使用两个指针
	r = temp_book;
	while (p != NULL && q != NULL)
	{
		p = r->next;
		q = p->next;
		if (p->data.price > q->data.price)
		{
			p->next = q->next;
			q->next = p;
			r->next = q;
		}
		r = p;
		DispBook(r);
	}
}