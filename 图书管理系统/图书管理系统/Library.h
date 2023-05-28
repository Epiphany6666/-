#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define MAX 50
#include<stdio.h>
#include<stdlib.h>
#include<String.h>
#include<time.h>

typedef struct//������ṹ��
{
	char name[MAX];//����
	char number[MAX];//��ı��
	double price;//��ļ۸�
	int num;//�������
}Book;

typedef struct//����ѧ���˺Žṹ��
{
	int account;//�˺�
	char password[MAX];//����
	char name[MAX];//����
	char student_number[MAX];//ѧ��
	int num;//��������
	Book book[10];//����飬�������ֻ�ܽ�10��
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

void CreateList_book();
void CreateList_student();

void welcome();

void Librarian();

void User();

void insert_book(char name[], char book_number[], double price, int num);
void insert_student(char password[], char name[], char student_number[],int &account);

LinkList_student* Find_student(int account); 
LinkList_book* Find_book(char name[]);

void DispBook(LinkList_book* book);//����
void Disp_Book();//����


void Delete_book(char name[]);
void Delete_student(char name[]);

void Sort_book();

//void saveInfoToFile_book(const char* FileName);
//void readInfoToFile_student(const char* FileName);