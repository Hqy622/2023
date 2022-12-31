#define _CRT_NONSTDC_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include"Book.h"
int main()
{
	int num;
	LinkList L = (LinkList)malloc(sizeof(LinkList));
	L->size = 0;
	assert(L);
	L->next = NULL;
	do {
		menu();
		scanf("%d",&num);
		switch (num)
		{
		case Add:
			AddBook(L);
			L->size++;
			break;
		case Delete:
			DeleteBook(L);
			L->size--;
			break;
		case Find:
			FindBook(L);
			break;
		case Order:
			OrderBook(L);
			break;
		case Change:
			ChangeBook(L);
			break;
		case Show:
			ShowBook(L);
			break;
		case Clear:
			ClearBook(L);
			break;
		case Exit:
			break;
		default :
			printf("输入错误，请重新输入\n");
		}
	} while (num);
	return 0;
}