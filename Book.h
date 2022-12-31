#pragma once
#pragma warning(disable:6031)

#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#include<string.h>

//每本书的信息
typedef struct Book {
	char ID[11];
	char name[20];
	int price;
}Book;

//节点
typedef struct LNode {
	Book data;
	struct LNode* next;
	int size ;
}LNode, * LinkList;

//内容 用于case
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

//菜单
void menu();
//增加
void AddBook(LinkList L);
//删除
void DeleteBook(LinkList L);
//查找
void FindBook(LinkList L);
//通过ID查找
void IDFind(LinkList *p, LinkList L);
//通过书名查找
void NameFind(LinkList *p, LinkList L);
//排序
void OrderBook(LinkList L);
//以ID进行排序
void IDOrder(LinkList L);
//以书名进行排序
void NameOrder(LinkList L);
//更改书的信息
void ChangeBook(LinkList L);
//展示现有书
void ShowBook(LinkList L);
//清除所有书的信息
void ClearBook(LinkList L);