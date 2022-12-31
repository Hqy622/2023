#define _CRT_NONSTDC_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include"Book.h"

void menu()
{
	printf("**** [1]Add    *** [2]Delete **\n");
	printf("**** [3]Find   *** [4]Order  **\n");
	printf("**** [5]change *** [6]Show   **\n");
	printf("**** [7]clear  *** [0]Exit   **\n");
}

void AddBook(LinkList L)
{
	LinkList p = (LinkList)malloc(sizeof(LNode));
	assert(p);
	printf("请输入书的ID(10位):>");
	scanf("%s",&p->data.ID);
	printf("请输入书名(20字以内):>");
	scanf("%s",&p->data.name);
	printf("请输入书的价钱:>");
	scanf("%d",&p->data.price);
	p->next = L->next;
	L->next = p;
}

void DeleteBook(LinkList L)
{
	char get;
	int num=1;
	LinkList p=NULL,s;
	while(num){
		printf("请问您要以什么方式进行删除\n\tA.ID\tB.name\n请选择:>");
		rewind(stdin);
		scanf("%c", &get);
		if (get == 'A'||get=='B')
		{
			num = 0;
			get == 'A' ? IDFind(&p,L) : NameFind(&p,L);
			s = p->next;
			p->next = s->next;
			free(s);
			s = NULL;
		}
		else
			printf("输入错误，请重新输入\n");
	}
}

void IDFind(LinkList *p, LinkList L)
{
	char id[11];
	do {
		LinkList h = L;
		printf("请输入ID:>");
		scanf("%s", id);
		while (h)
		{
			if (h->next && !(strcmp(h->next->data.ID, id)))
			{
				(*p) = h;
				return;
			}
			h = h->next;
		}
		printf("未查找到您所输入的ID,请重新输入\n");
	} while (1);
}

void NameFind(LinkList *p, LinkList L)
{
	char name[20];
	do {
		LinkList h = L;
		printf("请输入书名:>");
		scanf("%s", name);
		while (h)
		{
			if (h->next && !strcmp(h->next->data.name, name))
			{
				(*p) = h;
				return;
			}
			h = h->next;
		}
		printf("未查找到您所输入的书名,请重新输入\n");
	} while (1);
}

void ShowBook(LinkList L)
{
	LinkList p = L->next;
	printf("%-20s%-20s%s\n","ID","name","price");
	while (p)
	{
		printf("%-20s%-20s%d\n", p->data.ID, p->data.name, p->data.price);
		p = p->next;
	}
}

void FindBook(LinkList L)
{
	char get;
	int num = 1;
	LinkList p = NULL,s;
	do {
		printf("请问您要以什么样的方式进行查找\n\tA.ID\tB.name\n请选择:>");
		rewind(stdin);
		scanf("%c", &get);
		if (get == 'A' || get == 'B')
		{
			num = 0;
			get == 'A' ? IDFind(&p, L) : NameFind(&p, L);
			s = p->next;
			printf("%-20s%-20s%s\n", "ID", "name", "price");
			printf("%-20s%-20s%d\n", s->data.ID, s->data.name, s->data.price);
		}
		else
			printf("输入错误，请重新输入\n");
	} while (num);
}

void OrderBook(LinkList L)
{
	char get;
	int num = 1;
	do {
		printf("您希望以什么样的方式进行排序\n\tA.ID\tB.name\n请选择:>");
		rewind(stdin);
		scanf("%c", &get);
		if (get == 'A' || get == 'B')
		{
			num = 0;
			get == 'A' ? IDOrder(L) :NameOrder(L);
		}
		else
			printf("输入错误，请重新输入\n");
	} while (num);
}

void IDOrder(LinkList L)
{
	LinkList l, s, p;
	int i, j;
	for (j = 0; j < L->size; j++)
	{
		l = L;
		s = L->next;
		p = s->next;
		for (i = 0; i < L->size - j&&p; i++)
		{
			if (strcmp(s->data.ID,p->data.ID)>0)
			{
				l->next = p;
				s->next = p->next;
				p->next = s;
				s = p;
				p = p->next;
			}
				l = l->next;
				s = s->next;
				p = p->next;
		}
	}
}

void NameOrder(LinkList L)
{
	LinkList l, s, p;
	int i, j;
	for (j = 0; j < L->size; j++)
	{
		l = L;
		s = L->next;
		p = s->next;
		for (i = 0; i < L->size - j && p; i++)
		{
			if (strcmp(s->data.name, p->data.name) > 0)
			{
				l->next = p;
				s->next = p->next;
				p->next = s;
				s = p;
				p = p->next;
			}
			l = l->next;
			s = s->next;
			p = p->next;
		}
	}
}
void ChangeBook(LinkList L)
{
	char get;
	int num = 1;
	LinkList p = NULL, s;
	do {
		printf("请问您要以什么样的方式找到书\n\tA.ID\tB.name\n请选择:>");
		rewind(stdin);
		scanf("%c", &get);
		if (get == 'A' || get == 'B')
		{
			num = 0;
			get == 'A' ? IDFind(&p, L) : NameFind(&p, L);
			s = p->next;
			do
			{
				printf("请问您要更改此书的什么\n\tA.ID\tB.name\tC.price\n请选择:>");
				rewind(stdin);
				scanf("%c", &get);
				if (get == 'A' || get == 'B' || get == 'C')
				{
					num = 0;
					if (get == 'A')
					{
						printf("请输入您要更改的ID:>");
						scanf("%s",&s->data.ID);
					}
					else if (get == 'B')
					{
						printf("请输入您要更改的姓名:>");
						scanf("%s", &s->data.name);
					}
					else
					{
						printf("请输入您要更改的价钱:>");
						scanf("%d", &s->data.price);
					}
				}
				else
				{
					num = 1;
					printf("输入错误，请重新输入\n");
				}
			} while (num);
		}
		else
			printf("输入错误，请重新输入\n");
	} while (num);

}

void ClearBook(LinkList L)
{
	LinkList p = L->next;
	if (!L->size)
		return;
	while (p)
	{
		L->next= p->next;
		free(p);
		p = L->next;
	}
	L->size = 0;
}
