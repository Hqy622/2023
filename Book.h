#pragma once
#pragma warning(disable:6031)

#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#include<string.h>

//ÿ�������Ϣ
typedef struct Book {
	char ID[11];
	char name[20];
	int price;
}Book;

//�ڵ�
typedef struct LNode {
	Book data;
	struct LNode* next;
	int size ;
}LNode, * LinkList;

//���� ����case
enum Choice {
	Exit,
	Add,
	Delete,
	Find,
	Order,
	Change,
	Show,
	Clear
};

//�˵�
void menu();
//����
void AddBook(LinkList L);
//ɾ��
void DeleteBook(LinkList L);
//����
void FindBook(LinkList L);
//ͨ��ID����
void IDFind(LinkList *p, LinkList L);
//ͨ����������
void NameFind(LinkList *p, LinkList L);
//����
void OrderBook(LinkList L);
//��ID��������
void IDOrder(LinkList L);
//��������������
void NameOrder(LinkList L);
//���������Ϣ
void ChangeBook(LinkList L);
//չʾ������
void ShowBook(LinkList L);
//������������Ϣ
void ClearBook(LinkList L);