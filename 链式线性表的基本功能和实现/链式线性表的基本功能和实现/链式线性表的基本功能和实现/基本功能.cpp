#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW 0
#define ElemType int
#define Status int
//NULL ��ַ�� nullֵ��
//--------������Ĵ洢�ṹ-----------
typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;
//-------1.���Ա�ĳ�ʼ��------------
Status InitLisy(LinkList &L)
{
	/*LinkList *L = (LinkList*)malloc(sizeof(LNode));
	(*L)->next = NULL;
	(*L)->data = 0;*/
	L = new LNode;
	L->next = NULL;
	return OK;
}
//-------2.���Ա�Ľ���--------------
//���Կ����ǲ���һ��Ԫ�أ�ͷ�巨��ÿ�β���һ��Ԫ�أ�������ʱ���ڲ���
Status Creat(LinkList L)
{
	int len, i = 0;
	LNode *head = (LNode*)malloc(sizeof(LNode));
	LNode *p, *r;
	p = head;
	printf("����������ĳ���:len=");
	scanf_s("%d", &len);
	for (; i<len; i++)
	{
		int num = 0;
		r = (LNode *)malloc(sizeof(LNode));//����һ���µĽ��
		printf("�������%dԪ�ص�ֵ:", i);
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
	int c = 0;//switchѡ�����

	LinkList MyList= nullptr;
	while (1)
	{

		printf("------------------------\n");
		printf("|-1.���Ա�ĳ�ʼ��-----|\n");//���
		printf("|-2.���Ա�Ľ���-------|\n");//���
		printf("|-3.���Ա�ı���-------|\n");//
		printf("|-4.���Ա�Ĳ���-------|\n");//
		printf("|-5.���Ա�ı�-------|\n");
		printf("|-6.���Ա�İ�ֵ����---|\n");//
		printf("|-7.���Ա�İ�λɾ��---|\n");//
		printf("|-8.���Ա�İ�ֵɾ��---|\n");
		printf("|-9.��ѯ���Ա��Ԫ��---|\n");//
		printf("|-10.�˳�--------------|\n");//
		printf("------------------------\n");
		scanf_s("%d", &c);
		switch (c)
		{
		case 1:
			if (InitLisy(MyList))
				printf("���Ա�Ľ����ɹ�\n");
			else
				printf("���Ա�Ľ���ʧ��\n");
			break;
		case 2:
			if (Creat(MyList) == OK)
				printf("��ʼ���ɹ�\n");
			else
				printf("��ʼ��ʧ��\n");
			break;
		case 10:
			exit(OK); break;

		}
	}
	getchar();
}