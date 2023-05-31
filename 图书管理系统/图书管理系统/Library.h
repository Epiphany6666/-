#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define MAX 100
#include<stdio.h>
#include<stdlib.h>
#include<String.h>
#include<time.h>
//struct comment;
//struct book;
struct student1//定义学生账号结构体
{
    int account;//账号
    char password[MAX];//密码
    char name[MAX];//姓名
    char student_number[MAX];//学号
    //int num;//借书数量
    //Book book[10];//借的书，并且最多只能借10本
};

typedef struct
{
    struct student1 student;
    char data[MAX];
    time_t timep;
    char time[MAX];
}Comment;

typedef struct book//定义书结构体
{
    char name[MAX];//书名
    char number[MAX];//书的编号
    double price;//书的价格
    int num;//书的数量
    Comment comment[MAX];
    int num_comment;//评论的数量
    struct student1 student[MAX];
    int num_student;
    int num_lend;//借书的数量
}Book;


typedef struct
{
    struct student1 student;
    Book book[MAX];
    int num_book;
    int num_student;
    Comment comment[MAX];
    int num_comment;
}Student;

typedef struct Node//定义书链表
{
    Book data;
    struct Node* next;
}LinkList_book;

typedef struct Node1//定义学生账户链表
{
    Student data;
    struct Node1* next;
}LinkList_student;


//全局变量
//LinkList_book* L_book;//书链表
//LinkList_student* L_student;//学生账户链表

void CreateList_book(LinkList_book*& book);
void CreateList_student(LinkList_student*& student);

void welcome();

void Librarian();

void User();

void insert_book(Book book);
void insert_student(Student student);

LinkList_student* Find_student(int account);
LinkList_book* Find_book(char name[]);
LinkList_book* Find_comment(char comment[]);//查找评论所在的书籍

void DispBook(LinkList_book* book);//单本
void Disp_Book();//所有


int Delete_book(char name[]);
void delete_book(Book book[], int num, char name[]);
int Delete_student(char name[]);

void Sort_book();
void welcome_book();

void saveInfoToFile_book(const char* FileName);
void saveInfoToFile_student(const char* FileName);
void readInfoToFile_book(const char* FileName);
void readInfoToFile_student(const char* FileName);

void DispComment_book(Book book);
void DispComment_student(Student student);

void Disp_student(LinkList_book* book);

int Find_book11(LinkList_book* book1[MAX], int &count, char name[]);