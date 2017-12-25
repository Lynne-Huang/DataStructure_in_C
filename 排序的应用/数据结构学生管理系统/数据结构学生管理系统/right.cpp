/**
*程序用途：学生管理系统
*@author 黄景琳
*小组成员：307黄景琳、306吴倩、410倪文宇
*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<assert.h>
#include <string.h>

#define MAXSIZE 1000
#define OK 1
#define ERROR 0
#define OVERFLOW 0

typedef struct Student		//定义学生结构体 
{
	int No;					/*序号*/
	int Sno;				/*学号*/
	char Name[20] = { '\0' };			/*姓名*/
	float Mscore;		/*数学成绩*/
	float Cscore;		/*语文成绩*/
	float Escore;		/*英语成绩*/
}Stu;
typedef struct
{
	Stu elem[MAXSIZE];
	int length;			/*当前已存人数*/
}SqList;
/*════════╗
║初始化 student  ║
╚════════*/
int InitList(SqList &L)
{
	for (int i = 0; i <=MAXSIZE; i++)
	{
		L.elem[i].No = NULL;
		L.elem[i].Sno = NULL;
		//L.elem[i].Name = '0';
		L.elem[i].Cscore = NULL;
		L.elem[i].Escore = NULL;
		L.elem[i].Mscore = NULL;
	}
	if(!L.elem)
		exit(OVERFLOW);
	L.length=0;
	return OK;
}
/*═══════╗
║输入学生信息  ║
╚═══════*/
void stu_ifo(int i,SqList &L)
{
	printf("输入第%d个学生\n", i);
	L.elem[i].No = i;
	while (1)
	{
		printf("请输入学号：");
		scanf("%d", &L.elem[i].Sno);
		if (L.elem[i].Sno <= 0)
		{
			printf("学号输入错误，数学成绩应大于0,");
		}
		else
			break;
	}
	printf("请输入姓名：");
	scanf("%s", &L.elem[i].Name);
	while (1)
	{
		printf("请输入数学成绩：");
		scanf("%f", &L.elem[i].Mscore);
		if (L.elem[i].Mscore < 0 || L.elem[i].Mscore>100)
		{
			printf("成绩输入错误，数学成绩应在（0-100）之间,");
		}
		else
			break;
	}
	while (1)
	{
		printf("请输入语文成绩：");
		scanf("%f", &L.elem[i].Cscore);
		if (L.elem[i].Cscore < 0 || L.elem[i].Cscore>100)
		{
			printf("成绩输入错误，语文成绩应在（0-100）之间,");
		}
		else
			break;
	}
	while (1)
	{
		printf("请输入英语成绩：");
		scanf("%f", &L.elem[i].Escore);
		if (L.elem[i].Escore < 0 || L.elem[i].Escore>100)
		{
			printf("成绩输入错误，英语成绩应在（0-100）之间,");
		}
		else
			break;
	}
}

/*══════════════════╗
║根据指定学生个数，逐个输入学生信息  ║
╚══════════════════*/
int StuCreat(SqList &L)
{
	int a;
	int flag;
	L.length=0;
	L.elem->No = 0;
	printf("输入班级人数：");
	scanf("%d",&a);
	if(a<1||a>MAXSIZE)
		return ERROR;
	for(int i=1;i<=a;i++)
	{
		stu_ifo(i,L);
	
		L.length++;
		printf("继续输入请按1，返回上一级菜单请按2，退出请按0: ");
		scanf("%d", &flag);
		
		if (flag == 0) {
			exit(0);
		}

		if (flag == 1) {
			continue;
		}

		if (flag == 2) {
			return OK;
			break;
		}
	}
	
}
/*══════════════════╗
║ 逐个显示学生表中所有学生的相关信息 ║
╚══════════════════*/
int Display(SqList &L)
{
	int flag;
	printf("/*════════════════════════╗\n");
	printf("║                   学生信息                     ║\n");
	printf("║————————————————————————║\n");
	printf("║ 序号 |学号 |  姓名  | 语文成绩 | 数学成绩 | 英语成绩 ║\n");

	for(int i=1;i<=L.length;i++)
	{
		printf("║————————————————————————║\n");
		printf("║%d |%d  | %s |  %.2f  |  %.2f   |  %.2f   ║\n",L.elem[i].No,L.elem[i].Sno,L.elem[i].Name,L.elem[i].Cscore,L.elem[i].Mscore,L.elem[i].Escore);
	}
	printf("╚════════════════════════*/\n");
	printf("返回上一级菜单请按1，退出请按0: ");
		scanf("%d", &flag);
		if (flag == 0) 
		{
			exit(0);
		}

		if (flag == 1) 
		{
			
			return OK;
		}
}
/*════════════════════╗
║ 给定一个学生信息，插入到表中指定的位置 ║
╚════════════════════*/
int Insert(SqList &L)
{
	while (1)
	{
		int flag;
		int index;
		printf("输入你想插入的位置：");
		scanf("%d", &index);
		
		if ((index < 1) || (index > L.length + 1))
			return ERROR;
		if(	 (L.length>= MAXSIZE))
			return ERROR;
		if (index == L.length+1)
		{
			L.length=L.length+1;
			for (int i = index ; i <= index ; i++)
			{
				stu_ifo(i, L);
			}
		}
		else
		{
			for (int i = L.length; i >= 0; i--)
			{
				if (i < index)
					break;
				else
				{
					L.elem[i + 1].Sno=L.elem[i].Sno;
					strcpy(L.elem[i + 1].Name, L.elem[i].Name);		//strcmp函数，比较两个字符串
					L.elem[i + 1].No = L.elem[i].No + 1;
					L.elem[i + 1].Cscore = L.elem[i].Cscore;
					L.elem[i + 1].Escore = L.elem[i].Escore;
					L.elem[i + 1].Mscore = L.elem[i].Mscore;
				}
			}
			L.length++;
			for (int i = index; i <= index; i++)
			{
				stu_ifo(i, L);
			}
		}
		printf("插入成功\n");
		printf("继续插入请按1，返回上一级菜单请按2，退出请按0: ");
		scanf("%d", &flag);

		if (flag == 0)
		{
			exit(0);
		}
		if (flag == 1)
		{
			continue;
		}
		if (flag == 2)
		{
			return OK;
		}
	}
}

/*════════════╗
║ 删除指定位置的学生记录 ║
╚════════════*/
int Delete(SqList &L)	
{
	int flag;
	int i;
	int num=0;
	printf("请输入你要删除数据的学号：");
	scanf("%d",&i);
	for (int j=0; j <=L.length; j++)
	{
		if (L.elem[j].Sno == i)	
		{
			num = L.elem[j].No;
			break;
		}
	}
	if (num==0)
		return ERROR;
	else
	{
		for (int k = num; k < L.length; k++)
		{
			L.elem[k] = L.elem[k + 1];
			L.elem[k].No = L.elem[k].No - 1;
		}
		L.length--;
	}
	printf("删除成功\n");
	printf("返回上一级菜单请按1，退出请按0: ");
	scanf("%d", &flag);
	
	if (flag == 0)
	{
		exit(0);
	}

	if (flag == 1)
	{
		return OK;
	}
}
/*═════════╗
║ 统计表中学生个数 ║
╚═════════*/
int count(SqList &L)
{
	int flag;
	int a;
	printf("表中学生个数为：%d\n", L.length);
	printf("返回上一级菜单请按1，退出请按0: ");
	scanf("%d", &flag);
	if (flag == 0)
	{
		exit(0);
	}

	if (flag == 1)
	{

		return OK;
	}
 } 
/*══════════════════╗
║ 根据姓名（或者学号）进行顺序查找； ║
╚══════════════════*/
int order(SqList &L)
{
	int a;
	int sno;
	char sname[8]{'\0'};
	
	while (1)
	{
		printf("输入你想要的查找方式，0按姓名查找，1按学号查找：");
		scanf("%d", &a);
		
		switch (a)
		{
			case 0:
			{
				
				printf("输入你要查找的姓名：");
				scanf("%s", sname);
				if (!strcmp(sname, "\0"))
				{
					printf("输入错误，请重新输入\n");
					continue;
				}
				else
				{
					int num = 0;
					for (int i = 1; i <= L.length; i++)
					{
						if (strcmp(L.elem[i].Name, sname) == 0)	//strcmp函数，比较两个字符串
						{
							num = L.elem[i].No;
							printf("/*════════════════════════╗\n");
							printf("║                   学生信息                     ║\n");
							printf("║————————————————————————║\n");
							printf("║ 序号 |学号 |  姓名  | 语文成绩 | 数学成绩 | 英语成绩 ║\n");
							printf("║————————————————————————║\n");
							printf("║ %d |%d  | %s |  %.2f  |  %.2f   |  %.2f   ║\n",L.elem[i].No, L.elem[i].Sno, L.elem[i].Name, L.elem[i].Cscore, L.elem[i].Mscore, L.elem[i].Escore);
							printf("╚════════════════════════*/\n");
							return OK;
						}
					}
					if (num == 0)
					{
						printf("查询失败该学生不存在\n");
						return ERROR;
					}
				}
			}
			case 1:
			{	int num = 0;
				printf("输入你要查找的学号：");
				scanf("%d", &sno);
				if (sno == 0)
				{
					printf("输入错误，请重新输入\n");
					continue;
				}
				else
				{
					for (int i = 0; i <= L.length; i++)
					{
						if (L.elem[i].Sno == sno)	//strcmp函数，比较两个字符串
						{
							num = L.elem[i].No;
							printf("/*════════════════════════╗\n");
							printf("║                   学生信息                     ║\n");
							printf("║————————————————————————║\n");
							printf("║ 序号 | 学号 |  姓名  | 语文成绩 | 数学成绩 | 英语成绩 ║\n");
							printf("║————————————————————————║\n");
							printf("║ %d |%d  | %s |  %.2f  |  %.2f   |  %.2f   ║\n", L.elem[i].No, L.elem[i].Sno, L.elem[i].Name, L.elem[i].Cscore, L.elem[i].Mscore, L.elem[i].Escore);
							printf("╚════════════════════════*/\n");
							return OK;
						}
					}
					if (num == 0)
					{
						printf("查询失败该学生不存在\n");
						return ERROR;
					}
				}

			}
			default:
				printf("输入错误请重新输入\n");
		}
	}
}

//(7)  利用直接插入排序按照学号进行排序；

//(8)  利用冒泡排序按照数学成绩进行排序；

//(9)  利用简单选择排序按照语文成绩进行排序；

//(10)  利用快速排序按照英语成绩进行排序；

//(11) 根据学号进行折半查找，成功返回此学生的姓名和各科成绩。

int main()
{
	SqList Students;
	int c = 0;

	if (InitList(Students) == OK)
		printf("初始化成功\n");
	else
		printf("初始化失败\n");

	while (1)
	{
		printf("/*═════════════════════════════════════╗\n");
		printf("║       1 根据指定学生个数，逐个输入学生信息                               ║\n");//完成√
		printf("║       2 逐个显示学生表中所有学生的相关信息                               ║\n");//完成√
		printf("║       3 给定一个学生信息，插入到表中指定的位置                           ║\n");//完成√
		printf("║       4 删除指定位置的学生记录                                           ║\n");//完成√
		printf("║       5 统计表中学生个数                                                 ║\n");//完成√
		printf("║       6 根据姓名（或者学号）进行顺序查找                                 ║\n");//完成√
		printf("║       7 利用直接插入排序按照学号进行排序                                 ║\n");
		printf("║       8 利用冒泡排序按照数学成绩进行排序                                 ║\n");
		printf("║       9 利用简单选择排序按照语文成绩进行排序                             ║\n");
		printf("║       10 利用快速排序按照英语成绩进行排序                                ║\n");
		printf("║       11 根据学号进行折半查找，成功返回此学生的姓名和各科成绩            ║\n");
		printf("╚═════════════════════════════════════*/\n");
		printf("请选择功能：");
		scanf("%d", &c);
		switch (c)
		{
		case 1:
			if(StuCreat(Students)==OK)
			{
				printf("创建成功！?(＾?＾●)?\n");
				printf("当前已存人数：%d\n",Students.length);
			}
			else
				printf("创建失败(┬＿┬)\n");
			break;
		case 2:
			if( Display(Students)==OK)
				printf("显示完毕\n");
			break;
		case 3:
			
			if(Insert(Students)==ERROR)
				printf("插入失败\n");
			break;
		case 4:
			if (Delete(Students) == ERROR)
				printf("删除失败，学号不存在\n");
			break;
		case 5:
			if (count(Students) == OK)
				printf("统计成功\n");
			else
				printf("统计失败\n");
			break;
		case 6:
			order(Students);
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			break;
		case 10:
			break;
		case 11:
			break;
		case 12:
			exit(OK);
			break;
		default:
			printf("输入错误\n");
		}
	}
	getchar();
}

