#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#define OK 1
#define ERROR 0
typedef int Status;
typedef int ElemType;

//链表存储结构
typedef struct LNode {
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

//链表的初始化
Status InitList(LinkList &L) {
	L = new LNode;
	L->next = NULL;
	return OK;
}

//后插法创建链表
LinkList LinkListCreateTailL(int a[10])
{
	LinkList p, L, tail;
	int i = 0;
	L = (struct LNode*)malloc(sizeof(struct LNode));
	tail = L;

	for (i = 0; i<10; i++)
	{
		p = (struct LNode*)malloc(sizeof(struct LNode));
		p->data = a[i];
		tail->next = p;
		tail = p;
	}
	tail->next = NULL;
	return L;
}

//遍历链表
void LinkListPrint(LinkList L)
{
	LinkList p;
	p = L->next;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

//链表插入
Status ListInstert(LinkList &L, int i, ElemType e) {
	LNode *p;
	LNode *s;
	p = L;
	int j = 0;
	while (p && (j<i - 1))
	{
		p = p->next; ++j;
	}
	if (!p || j>i - 1) return ERROR;
	s = new LNode;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}

//删除区间的值
Status ListDelete1(LinkList &L, int min, int max) {
	LNode *p;
	LNode *q;
	p = L;
	int j = 0;
	for (int m = min; m <= max; m++) {
		while ((p->next) && (j<min - 1))
		{
			p = p->next; ++j;
		}
		if (!(p->next) || (j>min - 1)) return ERROR;
		q = p->next;
		p->next = q->next;
		delete q;
	}
	return OK;
}

//单链表求表长  
int LinkedListLength(LinkList L)
{
	LNode *p;            //p需要声明为LNode类型  
	p = L->next;
	int j = 0;
	while (p != NULL)
	{
		j++;
		p = p->next;         //将p向下移动一个结点  
	}
	printf("链表长度 %d \n", j);
	return j;
}

//链表的按位置删除
Status ListDelete(LinkList &L, int i) {
	LNode *p;
	LNode *q;
	p = L;
	int j = 0;
	while ((p->next) && (j<i - 1))
	{
		p = p->next; ++j;
	}
	if (!(p->next) || (j>i - 1)) return ERROR;
	q = p->next;
	p->next = q->next;
	delete q;
	return OK;
}

//链表的按值删除
void ListDelete2(LinkList L, LinkList Q, ElemType e)
{
	while ((L != NULL) && (L->next->data != e))      //查找元素e的前驱  
		L = L->next;
	Q = L->next;

	if (Q != NULL)                //找到需要删除的结点  
	{
		L->next = Q->next;
		free(Q);
	}
}

//单链表按值查询  
int LocateElem(LinkList L, ElemType e)
{
	LNode *p;
	p = L->next;
	int i = 1;
	while ((p != NULL) && (p->data != e))
	{
		p = p->next;
		i++;
	}
	if (p == NULL) return 0;
	else
		return (i);
}

void main() {
	int c = 0;
	int a[10], i, e, res;
	int min, max;
	LinkList MyList, L1;
	while (1)
	{
		printf("------链式表的基本操作-------\n");
		printf("|   1.线性表的初始化        |\n");
		printf("|   2.线性表的创建          |\n");
		printf("|   3.线性表的遍历          |\n");
		printf("|   4.线性表的插入          |\n");
		printf("|   5.线性表的有序插入      |\n");
		printf("|   6.线性表的删除介于区间值|\n");
		printf("|   7.线性表的表长          |\n");
		printf("|   8.线性表按位置删除      |\n");
		printf("|   9.线性表的按值删除      |\n");
		printf("|  10.查询线性表的元素      |\n");
		printf("|  11.退出                  |\n");
		printf("-----------------------------\n");
		printf("请输入要操作的步骤：");
			scanf_s("%d", &c);

		switch (c) {
		case 1:
			if (InitList(MyList) == OK, InitList(L1) == OK) {
				printf("线性表初始化成功！\n");
			}
			else {
				printf("线性表初始化失败！\n");
			}
			break;
		case 2:
			printf("请输入10个列表元素，以回车结束：\n");
			for (i = 0; i < 10; i++)
			{
				scanf_s("%d", &a[i]);
			}  printf("该链表为：\n");
			MyList = LinkListCreateTailL(a);
			LinkListPrint(MyList);
			break;
		case 3:
			printf("遍历该链表：\n");
			LinkListPrint(MyList);
			break;
		case 4:
			printf("请输入您要插入的位置：");
			scanf_s("%d", &i);
			printf("请输入您要插入的值：");
			scanf_s("%d", &e);
			if (ListInstert(MyList, i, e) == OK) {
				printf("插入成功！\n");
				LinkListPrint(MyList);
			}
			else {
				printf("插入失败！\n");
			}
			break;
		case 5:break;
		case 6:
			printf("请输入删除的首结点");
			scanf_s("%d", &min);
			printf("请输入删除的尾结点");
			scanf_s("%d", &max);
			if (ListDelete1(MyList, min, max) == OK) {
				printf("删除成功！\n");
				LinkListPrint(MyList);
			}
			else {
				printf("删除失败！\n");
			}
			break;
		case 7:
			LinkedListLength(MyList);
			break;
		case 8:
			printf("请输入您要删除的位置：");
			scanf_s("%d", &i);
			if (ListDelete(MyList, i) == OK) {
				printf("删除成功！\n");
				LinkListPrint(MyList);
			}
			else {
				printf("删除失败！\n");
			}
			break;
		case 9:
			printf("请输入要删除的元素的值：");
			scanf_s("%d", &e);
			ListDelete2(MyList, L1, e);
			LinkListPrint(MyList);
			break;
		case 10:
			printf("请输入您要查找的数据：");
			scanf_s("%d", &e);
			res = LocateElem(MyList, e);
			if (res != 0) {
				printf("查找成功！所查数据的位置为：%d\n", res);
			}
			else {
				printf("查找失败！\n");
			}
			break;
		case 11:
			exit(OK);
		default:
			printf("输入有误！\n");
			break;
		}
		
	}
	getchar();
}
