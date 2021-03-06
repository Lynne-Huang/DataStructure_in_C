﻿#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW 0

typedef int ElemType;
//——————顺序表的存储结构————
typedef struct
{
	ElemType *elem;
	int length;
}SqList;

//—————1.顺序表的初始化——————
int InitList(SqList &L)
{
	L.elem = new ElemType(MAXSIZE);
	if (!L.elem)
		exit(OVERFLOW);
	L.length = 0;
	return OK;
}
//—————2.顺序表的建立————
int Creat(SqList &L)
{
	int a = 0;
	printf("请输入你要创建的元素个数:");
	scanf_s("%d", &a);
	if (a<1 || a>MAXSIZE)
		return ERROR;
	for (int i = 0; i < a; i++)
	{
		printf("请输入第%d个元素", i + 1);
		scanf_s("%d", &L.elem[i]);
		L.length++;
	}
	return OK;
}
//—————3.顺序表的取值————————
int GetElem(SqList L, int i, ElemType &e)
{
	if (i<1 || i>L.length)
		return ERROR;
	e = L.elem[i - 1];
	//printf("找到第%d的值为%d\n", i, e);
	return OK;
}
//—————4.顺序表的插入————————
int ListInsert(SqList&L, int i, ElemType e)
{
	int j = 0;
	if ((i<1) || (i>L.length + 1))
		return ERROR;
	if (L.length == MAXSIZE)
		return ERROR;
	for (j = L.length; j >= i - 1; j--)
		L.elem[j + 1] = L.elem[j];//L.elem[j ] = L.elem[j - 1]; 下次测试
	L.elem[i - 1] = e;
	++L.length;
	return OK;
}
//—————5.顺序表的表长——————
int Length(SqList &L)
{
	return(L.length);
}
//—————6.顺序表的删除——————
int ListDelete(SqList &L, int i)
{
	int j = 0;
	if ((i<1) || (i>L.length))
		return ERROR;
	for (j = i; j <= L.length - 1; j++)
		L.elem[j - 1] = L.elem[j];
	--L.length;
	return OK;
}
//—————7.按位置查询线性表的元素————
int LocateElem(SqList L, ElemType e)
{
	for (int i = 0; i < L.length; i++)
	{
		if (L.elem[i] == e) return i + 1;
	}
	return ERROR;
}
//—————8.显示线性表元素————————
int Display(SqList &L)
{
	int i;
	printf("线性表中的元素为\n");
	for (i = 0; i < L.length; i++)
	{
		printf("%d\t", L.elem[i]);
	}printf("\n");
	return OK;
}
//----9.线性表的按值插入———
int ListInsertValues(SqList &L, ElemType e)
{
	if (L.length == MAXSIZE)
		return ERROR;
	int rnum = 0;
	for (int j = L.length - 1; j >= 0; j--)
	{
		GetElem(L, j + 1, rnum);
		if (rnum >= e)
		{
			L.elem[j + 1] = L.elem[j];
		}
		else
		{
			L.elem[j + 1] = e;
			break;
		}
	}
	L.length++;
	return OK;
}
//-——10.顺序A表的初始化并建立————
int InitListA(SqList &A)
{
	A.elem = new ElemType(MAXSIZE);
	if (!A.elem)
		exit(OVERFLOW);
	A.length = 0;
	return OK;
}
int CreatA(SqList &A)
{
	int a = 0;
	printf("请输入你要创建的元素个数:");
	scanf_s("%d", &a);
	if (a<1 || a>MAXSIZE)
		return ERROR;
	for (int i = 0; i < a; i++)
	{
		printf("请输入第%d个元素", i + 1);
		scanf_s("%d", &A.elem[i]);
		A.length++;
	}
	return OK;
}
//-----11.两个线性表的合并——————
int HEBING(SqList &L, SqList A)
{
	if (L.length == MAXSIZE)
		return ERROR;
	int rnum = 0;
	for (int i = 0; i<A.length + L.length - 1; i++)
	{
		if (i >L.length - 1)
		{
			for (int j = 1; j <= A.length; j++)
			{
				GetElem(A, j, rnum);
				if (!LocateElem(L, rnum))
				{
					ListInsert(L, L.length + 1, rnum);
				}
			}
		}
	}
	return OK;
}
//-----12.两个线性表的有序合并——————
int ListhebingValues(SqList &L, SqList A)
{
	if (L.length == MAXSIZE)
		return ERROR;
	int rnum = 0;
	for (int i = 0; i<A.length + L.length - 1; i++)
	{
		if (i >L.length - 1)
		{
			for (int j = 1; j <= A.length; j++)
			{
				GetElem(A, j, rnum);
				if (!LocateElem(L, rnum))
				{
					ListInsertValues(L, rnum);
				}
			}
		}
	}
	return OK;
}
void main()
{
	int c = 0;//switch选择参数
	int a = 0;//需要创建表元素的个数
	int x = 0;//插入的数据值
	int pos = 0;//插入数据的位置
	int rnum = 0;//返回的数据值
	int Lnum = 0;//查询的元素
	int Locate = 0;//查询的元素所在的位置
	int del = 0;//要删除的位置
	int Long = 0;//顺序表的长度
	SqList MyList;
	SqList MyList1;
	while (1)
	{

		printf("———————————————\n");
		printf("|—1.顺序表的初始化—————|\n");//完成
		printf("|—2.顺序表的建立——————|\n");//完成
		printf("|—3.顺序表的取值——————|\n");//完成
		printf("|—4.顺序表的插入——————|\n");//完成
		printf("|—5.顺序表的表长——————|\n");
		printf("|—6.顺序表的按位置删除———|\n");//完成
		printf("|—7.按位置查询线性表的元素—|\n");//完成
		printf("|—8.显示线性表———————|\n");//完成
		printf("|-9.顺序表的按值插入---------|\n");
		printf("|-10.顺序表A的初始化并建立---|\n");//完成
		printf("|-11.线性表的和并------------|\n");//完成
		printf("|-12.线性表的有序和并--------|\n");
		printf("|-13.退出--------------------|\n");//完成
		printf("———————————————\n");
		scanf_s("%d", &c);
		switch (c)
		{
		case 1: if (InitList(MyList) == OK)
			printf("初始化成功\n");
				else
					printf("初始化失败\n"); break;

		case 2:

			if (Creat(MyList) == ERROR)
			{
				printf("顺序表建立不成功\n");
			}
			else
			{
				printf("顺序表建立成功\n");
				Display(MyList);
			}
			break;
		case 3:
			printf("请输入你要取值的位置：");
			scanf_s("%d", &pos);
			if (GetElem(MyList, pos, rnum) == OK)
			{
				printf("取值成功\n");
				printf("找到第%d的值为%d\n", pos, rnum);

			}
			else
			{
				printf("取值失败\n");
			}
			break;
		case 4:
			printf("请输入你要插入的数据：");
			scanf_s("%d", &x);
			printf("\n请输入你要插入的位置：");
			scanf_s("%d", &pos);
			if (ListInsert(MyList, pos, x) == OK)
			{
				printf("插入成功：\n");
				printf("插入后的数据为：\n");
				Display(MyList);
			}
			else
			{
				printf("插入失败\n");
			}
			break;
		case 5:
			Long = Length(MyList);
			printf("线性表的长度为%d\n", Long);
			break;
		case 6:
			printf("输入你要删除的位置：");
			scanf_s("%d", &del);
			if (ListDelete(MyList, del) == OK)
			{
				printf("删除成功");
				Display(MyList);
			}
			else
			{
				printf("删除不成功");
			}
			break;
		case 7:
			printf("输入你要查询的元素：");
			scanf_s("%d", &Lnum);
			if (LocateElem(MyList, Lnum) == ERROR)
			{
				printf("查询失败\n");
			}
			else
			{
				Locate = LocateElem(MyList, Lnum);
				printf("%d在表中第%d个\n", Lnum, Locate);
				printf("查询成功\n");
			}
			break;
		case 8:
			if (Display(MyList) == OK)
				printf("线性表的显示成功\n");
			else
				printf("线性表的显示不成功\n");
			break;
		case 9:
			printf("请输入你要插入的数据：");
			scanf_s("%d", &x);
			if (ListInsertValues(MyList, x) == OK)
			{
				printf("插入成功：\n");
				printf("插入后的数据为：\n");
				Display(MyList);
			}
			else
			{
				printf("插入失败\n");
			}
			break;
		case 10:
			if (InitList(MyList1) == OK)
				printf("初始化成功\n");
			else
			{
				printf("初始化失败\n"); break;
			}
			if (CreatA(MyList1) == ERROR)
			{
				printf("顺序表建立不成功\n");
			}
			else
			{
				printf("顺序表建立成功\n");
				Display(MyList1);
			}
			break;

		case 11:
			if (HEBING(MyList, MyList1) == OK)
			{
				printf("顺序表合并成功\n");
				Display(MyList);
			}
			else
			{
				printf("顺序表合并不成功\n");
			}
			break;
			case 12:
			if (ListhebingValues(MyList, MyList1) == OK)
			{
			printf("顺序表合并成功\n");
			Display(MyList);
			}
			else
			{
			printf("顺序表合并不成功\n");
			}
			break;
		case 13:
			exit(OK); break;

		default:
			printf("输入错误！");

		}
	}
	getchar();
}