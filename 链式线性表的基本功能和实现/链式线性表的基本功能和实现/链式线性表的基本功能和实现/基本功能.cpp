#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW 0
#define ElemType int
#define Status int
//NULL 地址空 null值空
//--------单链表的存储结构-----------
typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;
//-------1.线性表的初始化------------
Status InitLisy(LinkList &L)
{
	/*LinkList *L = (LinkList*)malloc(sizeof(LNode));
	(*L)->next = NULL;
	(*L)->data = 0;*/
	L = new LNode;
	L->next = NULL;
	return OK;
}
//-------2.线性表的建立--------------
//可以看作是插入一个元素，头插法，每次插入一个元素，当满足时不在插入
Status Creat(LinkList L)
{
	int len, i = 0;
	LNode *head = (LNode*)malloc(sizeof(LNode));
	LNode *p, *r;
	p = head;
	printf("请输入链表的长度:len=");
	scanf_s("%d", &len);
	for (; i<len; i++)
	{
		int num = 0;
		r = (LNode *)malloc(sizeof(LNode));//生成一个新的结点
		printf("请输入第%d元素的值:", i);
		scanf_s("%d", &num);
		p->data = num;
		r->next = p;
		r = p;
		r->next = NULL;
	}
	
	return OK;

}

void main()
{
	int c = 0;//switch选择参数

	LinkList MyList= nullptr;
	while (1)
	{

		printf("------------------------\n");
		printf("|-1.线性表的初始化-----|\n");//完成
		printf("|-2.线性表的建立-------|\n");//完成
		printf("|-3.线性表的遍历-------|\n");//
		printf("|-4.线性表的插入-------|\n");//
		printf("|-5.线性表的表长-------|\n");
		printf("|-6.线性表的按值插入---|\n");//
		printf("|-7.线性表的按位删除---|\n");//
		printf("|-8.线性表的按值删除---|\n");
		printf("|-9.查询线性表的元素---|\n");//
		printf("|-10.退出--------------|\n");//
		printf("------------------------\n");
		scanf_s("%d", &c);
		switch (c)
		{
		case 1:
			if (InitLisy(MyList))
				printf("线性表的建立成功\n");
			else
				printf("线性表的建立失败\n");
			break;
		case 2:
			if (Creat(MyList) == OK)
				printf("初始化成功\n");
			else
				printf("初始化失败\n");
			break;
		case 10:
			exit(OK); break;

		}
	}
	getchar();
}