#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define MAX 50
#include<stdio.h>
#include<stdlib.h>
#include<String.h>
#include<time.h>

typedef struct//定义书结构体
{
	char name[MAX];//书名
	char number[MAX];//书的编号
	double price;//书的价格
	int num;//书的数量
}Book;

typedef struct//定义学生账号结构体
{
	int account;//账号
	char password[MAX];//密码
	char name[MAX];//姓名
	char student_number[MAX];//学号
	int num;//借书数量
	Book book[10];//借的书，并且最多只能借10本
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

void CreateList_book();
void CreateList_student();

void welcome();

void Librarian();

void User();

void insert_book(char name[], char book_number[], double price, int num);
void insert_student(char password[], char name[], char student_number[],int &account);

LinkList_student* Find_student(int account); 
LinkList_book* Find_book(char name[]);

void DispBook(LinkList_book* book);//单本
void Disp_Book();//所有


void Delete_book(char name[]);
void Delete_student(char name[]);

void Sort_book();

//void saveInfoToFile_book(const char* FileName);
//void readInfoToFile_student(const char* FileName);