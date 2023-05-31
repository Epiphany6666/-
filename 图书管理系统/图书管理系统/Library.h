#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define MAX 100
#include<stdio.h>
#include<stdlib.h>
#include<String.h>
#include<time.h>
//struct comment;
//struct book;
struct student1//����ѧ���˺Žṹ��
{
    int account;//�˺�
    char password[MAX];//����
    char name[MAX];//����
    char student_number[MAX];//ѧ��
    //int num;//��������
    //Book book[10];//����飬�������ֻ�ܽ�10��
};

typedef struct
{
    struct student1 student;
    char data[MAX];
    time_t timep;
    char time[MAX];
}Comment;

typedef struct book//������ṹ��
{
    char name[MAX];//����
    char number[MAX];//��ı��
    double price;//��ļ۸�
    int num;//�������
    Comment comment[MAX];
    int num_comment;//���۵�����
    struct student1 student[MAX];
    int num_student;
    int num_lend;//���������
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

typedef struct Node//����������
{
    Book data;
    struct Node* next;
}LinkList_book;

typedef struct Node1//����ѧ���˻�����
{
    Student data;
    struct Node1* next;
}LinkList_student;


//ȫ�ֱ���
//LinkList_book* L_book;//������
//LinkList_student* L_student;//ѧ���˻�����

void CreateList_book(LinkList_book*& book);
void CreateList_student(LinkList_student*& student);

void welcome();

void Librarian();

void User();

void insert_book(Book book);
void insert_student(Student student);

LinkList_student* Find_student(int account);
LinkList_book* Find_book(char name[]);
LinkList_book* Find_comment(char comment[]);//�����������ڵ��鼮

void DispBook(LinkList_book* book);//����
void Disp_Book();//����


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