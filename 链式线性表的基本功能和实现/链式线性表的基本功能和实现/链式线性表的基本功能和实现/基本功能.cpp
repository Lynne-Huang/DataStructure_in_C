#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#define OK 1
#define ERROR 0
typedef int Status;
typedef int ElemType;

//����洢�ṹ
typedef struct LNode {
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

//����ĳ�ʼ��
Status InitList(LinkList &L) {
	L = new LNode;
	L->next = NULL;
	return OK;
}

//��巨��������
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

//��������
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

//�������
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

//ɾ�������ֵ
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

//���������  
int LinkedListLength(LinkList L)
{
	LNode *p;            //p��Ҫ����ΪLNode����  
	p = L->next;
	int j = 0;
	while (p != NULL)
	{
		j++;
		p = p->next;         //��p�����ƶ�һ�����  
	}
	printf("������ %d \n", j);
	return j;
}

//����İ�λ��ɾ��
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

//����İ�ֵɾ��
void ListDelete2(LinkList L, LinkList Q, ElemType e)
{
	while ((L != NULL) && (L->next->data != e))      //����Ԫ��e��ǰ��  
		L = L->next;
	Q = L->next;

	if (Q != NULL)                //�ҵ���Ҫɾ���Ľ��  
	{
		L->next = Q->next;
		free(Q);
	}
}

//������ֵ��ѯ  
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
		printf("------��ʽ��Ļ�������-------\n");
		printf("|   1.���Ա�ĳ�ʼ��        |\n");
		printf("|   2.���Ա�Ĵ���          |\n");
		printf("|   3.���Ա�ı���          |\n");
		printf("|   4.���Ա�Ĳ���          |\n");
		printf("|   5.���Ա���������      |\n");
		printf("|   6.���Ա��ɾ����������ֵ|\n");
		printf("|   7.���Ա�ı�          |\n");
		printf("|   8.���Ա�λ��ɾ��      |\n");
		printf("|   9.���Ա�İ�ֵɾ��      |\n");
		printf("|  10.��ѯ���Ա��Ԫ��      |\n");
		printf("|  11.�˳�                  |\n");
		printf("-----------------------------\n");
		printf("������Ҫ�����Ĳ��裺");
			scanf_s("%d", &c);

		switch (c) {
		case 1:
			if (InitList(MyList) == OK, InitList(L1) == OK) {
				printf("���Ա��ʼ���ɹ���\n");
			}
			else {
				printf("���Ա��ʼ��ʧ�ܣ�\n");
			}
			break;
		case 2:
			printf("������10���б�Ԫ�أ��Իس�������\n");
			for (i = 0; i < 10; i++)
			{
				scanf_s("%d", &a[i]);
			}  printf("������Ϊ��\n");
			MyList = LinkListCreateTailL(a);
			LinkListPrint(MyList);
			break;
		case 3:
			printf("����������\n");
			LinkListPrint(MyList);
			break;
		case 4:
			printf("��������Ҫ�����λ�ã�");
			scanf_s("%d", &i);
			printf("��������Ҫ�����ֵ��");
			scanf_s("%d", &e);
			if (ListInstert(MyList, i, e) == OK) {
				printf("����ɹ���\n");
				LinkListPrint(MyList);
			}
			else {
				printf("����ʧ�ܣ�\n");
			}
			break;
		case 5:break;
		case 6:
			printf("������ɾ�����׽��");
			scanf_s("%d", &min);
			printf("������ɾ����β���");
			scanf_s("%d", &max);
			if (ListDelete1(MyList, min, max) == OK) {
				printf("ɾ���ɹ���\n");
				LinkListPrint(MyList);
			}
			else {
				printf("ɾ��ʧ�ܣ�\n");
			}
			break;
		case 7:
			LinkedListLength(MyList);
			break;
		case 8:
			printf("��������Ҫɾ����λ�ã�");
			scanf_s("%d", &i);
			if (ListDelete(MyList, i) == OK) {
				printf("ɾ���ɹ���\n");
				LinkListPrint(MyList);
			}
			else {
				printf("ɾ��ʧ�ܣ�\n");
			}
			break;
		case 9:
			printf("������Ҫɾ����Ԫ�ص�ֵ��");
			scanf_s("%d", &e);
			ListDelete2(MyList, L1, e);
			LinkListPrint(MyList);
			break;
		case 10:
			printf("��������Ҫ���ҵ����ݣ�");
			scanf_s("%d", &e);
			res = LocateElem(MyList, e);
			if (res != 0) {
				printf("���ҳɹ����������ݵ�λ��Ϊ��%d\n", res);
			}
			else {
				printf("����ʧ�ܣ�\n");
			}
			break;
		case 11:
			exit(OK);
		default:
			printf("��������\n");
			break;
		}
		
	}
	getchar();
}
