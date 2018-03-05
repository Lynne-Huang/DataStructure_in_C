/**
*程序用途：学生管理系统
*@author 黄景琳
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
		L.elem[i].Sno = NULL;
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
void stu_ifo(int i,SqList &L)			//i插入的位置
{
	int length = L.length;
	printf("输入第%d个学生\n", i);
	while (1)
	{
		int sno=0;
		printf("请输入学号：");
		int flag = 0;
		scanf("%d", &sno);
		
		for (int j = 1; j <= length; j++)
		{
			if (L.elem[j].Sno == sno)
			{
				printf("学号输入错误，该学号已存在，");
				flag = 1;
				break;
			}
		}
		/* bug:输入的学号非数字值，未能有错误提示也未重新赋值
		 * 修改方案：把学号换成char型，利用String函数中的函数比较每个字符是否是数字，不是返回错误信息并提示重新输入
		 * 其中查询中也要使用String函数中的比较来完成查找
		 * 由于修改工程浩大，此功能等到2018期末考完再修改 QYQ
		 * emnmnm就这样吧，新年快乐，再见2017
		*/
		if (flag == 1)	continue;
		else if (sno <= 0)			//学号不为零 
		{
			printf("学号输入错误,学号应该大于0,");
			flag = 1;
			
		}
		else
		{
			L.elem[i].Sno = sno;
			break;
		}
		
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
	int a;	//班级人数
	int flag;
	L.length=0;
	printf("输入班级人数：");
	scanf("%d",&a);
	if(a<1||a>MAXSIZE)
		return ERROR;
	for(int i=1;i<=a;i++)
	{
		stu_ifo(i,L);		//i 位置
		L.length++;
	}
	while (true)
	{
		printf("继续输入请按1，返回上一级菜单请按2，退出请按0: ");
		scanf("%d", &flag);
		if (flag == 0) {
			exit(0);
		}
		else if (flag == 1) {
			if (L.length == a)
			{

				printf("\n你当前已存人数已达到你设定的上限，不能再录入学生信息，\n\n如需继续插入学生,请返回上一级菜单，\n\n选择插入功能或选择本功能，重新录入学生信息\n\n");
				printf("输入功能错误,请重新输入\n");
				continue;
			}
			else
			break;
		}

		else if (flag == 2) {
			return OK;
		}
		else
			printf("输入功能错误,请重新输入\n");
	}

}
/*══════════════════╗
║ 逐个显示学生表中所有学生的相关信息 ║
╚══════════════════*/
int Display(SqList &L,int star,int end,int index)	//star开始显示的位置  end结束显示的位置	flag 功能 0普通显示 1查询显示
{
	int flag;
	
	printf("/*-----------------------------------------------------╗\n");
	printf("║                       学生信息                       ║\n");
	printf("║------------------------------------------------------║\n");
	printf("║ 序号 |学号 |  姓名  | 语文成绩 | 数学成绩 | 英语成绩 ║\n");
	if(index==0)
	{
		for (int i = star; i <= end; i++)
		{
			printf("║------------------------------------------------------║\n");
			if(strlen(L.elem[i].Name) ==4)
			{
				printf("║   %d  | %d |  %s  |   %.2f  |   %.2f  |   %.2f  ║\n", i, L.elem[i].Sno, L.elem[i].Name, L.elem[i].Cscore, L.elem[i].Mscore, L.elem[i].Escore);
			}
			else
				printf("║   %d  | %d | %s |   %.2f  |   %.2f  |   %.2f  ║\n", i, L.elem[i].Sno, L.elem[i].Name, L.elem[i].Cscore, L.elem[i].Mscore, L.elem[i].Escore);
		}
	}
	if (index == 1)
	{
		for (int i = star; i <= end; i++)
		{
			int no = 1;
			printf("║------------------------------------------------------║\n");
			if (strlen(L.elem[i].Name) == 4)
			{
				printf("║   %d  | %d |  %s  |   %.2f  |   %.2f  |   %.2f  ║\n", no, L.elem[i].Sno, L.elem[i].Name, L.elem[i].Cscore, L.elem[i].Mscore, L.elem[i].Escore);
			}
			else
				printf("║   %d  | %d | %s |   %.2f  |   %.2f  |   %.2f  ║\n", no, L.elem[i].Sno, L.elem[i].Name, L.elem[i].Cscore, L.elem[i].Mscore, L.elem[i].Escore);
		}
	}
	
	printf("╚-------------------------------------------------------*/\n");
	while (true)
	{
		printf("返回上一级菜单请按1，退出请按0: ");
		scanf("%d", &flag);
		if (flag == 0)
		{
			exit(0);
		}

		else if (flag == 1)
		{
			return OK;
		}
		else
			printf("功能选择错误，请重新输入\n");
	}
	
}
/*════════════════════╗
║ 给定一个学生信息，插入到表中指定的位置 ║
╚════════════════════*/
int Insert(SqList &L)//
{
	while (1)
	{
		int flag;
		int index;
		printf("输入你想插入的位置：");
		scanf("%d", &index);
		int length = L.length;
		if ((index < 1) || (index > length + 1))
			return ERROR;
		if(	 (L.length>= MAXSIZE))
			return ERROR;
		if (index == length+1)						//末端插入新值
		{
			L.length=L.length+1;
			for (int i = index ; i <= index ; i++)
			{
				stu_ifo(i, L);						//i插入的位置
			}
		}
		else
		{
			L.elem[0] = L.elem[index];
			for (int i = L.length; i >= 0; i--)					//移位 
			{
				if (i <= index)
					break;
				else
				{
					L.elem[i + 1] = L.elem[i];
				}
			}
			L.elem[index+1] = L.elem[0];
			L.elem[index].Sno = NULL;
			L.length++;
			for (int i = index; i <= index; i++)
			{
				stu_ifo(i, L);
			}
		}
		printf("插入成功\n");
		
		while (true)
		{
			printf("继续插入请按1，返回上一级菜单请按2，退出请按0: ");
			scanf("%d", &flag);
			if (flag == 0)
			{
				exit(0);
			}
			else if (flag == 1)
			{
				break;
			}
			else if (flag == 2)
			{
				return OK;
			}
			else
				printf("功能选择错误，请重新输入\n");
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
	int num = 0;
	while (1)
	{
		printf("请输入你要删除数据的学号：");
		scanf("%d", &i);
		for (int j = 0; j <= L.length; j++)
		{
			if (L.elem[j].Sno == i)
			{
				num = j;
				break;
			}
		}
		if (num == 0)
			return ERROR;
		else
		{
			for (int k = num; k < L.length; k++)
			{
				L.elem[k] = L.elem[k + 1];
			}
			L.length--;
		}
		printf("删除成功\n");
		
		while(1)
		{
			printf("删除插入请按 1，返回上一级菜单请按2，退出请按0: ");
			scanf("%d", &flag);
			if (flag == 0)
			{
				exit(0);
			}
			else if (flag == 1)
			{
				break;
			}
			else if (flag == 2)
			{
				return OK;
			}
			else
				printf("功能选择错误，请重新输入\n");
		}
		
	}
}
/*═════════╗
║ 统计表中学生个数 ║
╚═════════*/
int count(SqList &L)
{
	int flag;
	int a;
	printf("统计成功，");
	printf("表中学生个数为：%d\n", L.length);
	while(1)
	{
		printf("返回上一级菜单请 按1，退出 请按0: ");
		scanf("%d", &flag);
		if (flag == 0)
		{
			exit(0);
		}

		else if (flag == 1)
		{

			return OK;
		}
		else
			printf("功能选择错误，请重新输入\n");
	}
	
 } 
/*══════════════════╗
║ 根据姓名（或者学号）进行顺序查找   ║
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
							num = i;
							Display(L, i, i,1);
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
					for (int j = 1; j <= L.length; j++)
					{
						if (L.elem[j].Sno == sno)	
						{
							num = j;
							Display(L, j, j,1);
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
/*══════════════════╗
║ 利用直接插入排序按照学号进行排序   ║
╚══════════════════*/
int StraightInsertionSort(SqList &L)	//学号从小到大的顺序排     序号有问题待调整
{
	int i, j;
	for(i=2;i<=L.length;i++)			//循环从第二个数开始
	{
		if(L.elem[i].Sno < L.elem[i - 1].Sno)
		{
			L.elem[0] = L.elem[i];
			L.elem[i] = L.elem[i - 1];
		
			for(j = i - 2; L.elem[0].Sno < L.elem[j].Sno; --j)
			{
				L.elem[j + 1] = L.elem[j];
			}
			L.elem[j + 1] = L.elem[0];
		}
	}
	Display(L,1,L.length,0);
	printf("排序成功\n");
	return OK;
}
/*══════════════════╗
║ 利用冒泡排序按照数学成绩进行排序   ║
╚══════════════════*/
int BubbleSort(SqList &L)
{
	int m=L.length;
	int flag = 1;
	while((flag==1)&&(m>0))
	{
		flag = 0;
		for (int j = 1; j < m; j++)
		{
			if (L.elem[j].Mscore > L.elem[j + 1].Mscore)
			{
				flag = 1;
				L.elem[0] = L.elem[j];
				L.elem[j] = L.elem[j + 1];
				L.elem[j + 1] = L.elem[0];
			}
		}
		--m;
	}
	Display(L,1,L.length,0);
	printf("排序成功\n");
	return OK;
}
/*═══════════════════╗
║ 利用简单选择排序按照语文成绩进行排序 ║
╚═══════════════════*/
int SimpleSelectionSort(SqList &L)
{
	Stu min[MAXSIZE] = { '\0' };
	//Stu empty[MAXSIZE] = { '\0' };
	for (int i = 1; i <= L.length; i++)
	{
		min[i] = L.elem[i];
		for (int j = i + 1; j <= L.length; j++)
		{
			if (L.elem[j].Cscore < min[i].Cscore)			//找出最小值
			{
				min[i] = L.elem[j];
			}
			if (min[i].Cscore != L.elem[i].Cscore)
			{
				L.elem[0] = L.elem[i];
				L.elem[i] = min[i];						//把最小值移到最前
				L.elem[j] = L.elem[0];
			}

		}
	}
	Display(L,1,L.length,0);
	printf("排序成功\n");
	return OK;
}

/*══════════════════╗
║ 利用快速排序按照英语成绩进行排序   ║
╚══════════════════*/
//用书上的视频的写法写的，等老师讲过这个算法之后在改写，2018再见把(*^_^*)
int Partition(SqList &L,int low,int high)
{
	L.elem[0] = L.elem[low];
	int pivotkey = L.elem[low].Escore;
	while (low < high)
	{
		while ((low < high) && (L.elem[high].Escore >= pivotkey))
		{
			--high;
		}
		L.elem[low] = L.elem[high];
		while ((low < high) && (L.elem[low].Escore <= pivotkey))
		{
			++low;
		}
		L.elem[high] = L.elem[low];
	}
	L.elem[low] = L.elem[0];
	return low;
}
int QSort(SqList &L, int low, int high)
{
	if (low < high)
	{
		int pivotloc = Partition(L, low, high);
		Partition(L, low, pivotloc - 1);
		Partition(L, pivotloc + 1, high);
	}
	return OK;
}
/*════════════════════════════╗
║ 根据学号进行折半查找，成功返回此学生的姓名和各科成绩   ║
╚════════════════════════════*/
int binsearch(SqList &L)
{
	
	int k = 0;							//目标学号
	int No = -1;						//目标所在的序号
	printf("输入你要查询的学号：");
	scanf("%d", &k);
	if (k <= 0)
		return ERROR;
	for (int i = 2; i <= L.length; i++)	//折半插入排序
	{
		L.elem[0] = L.elem[i];
		int low = 1;					//最小值
		int high = i-1;			//最大值
		int mid;						//中间值
		while (low <= high)
		{
			mid = (low + high) / 2;//low + ((high - low) / 2);
			if (L.elem[0].Sno < L.elem[mid].Sno)
				high = mid - 1;
			else
				low = mid + 1;
		}
		for (int j = i - 1; j >= high; j--)
		{
			L.elem[j + 1] = L.elem[j];	//后移
		}
		L.elem[high + 1] = L.elem[0];	//插入
	}
	int low = 1;						//最小值
	int high = L.length;				//最大值
	int mid=0;							//中间值
	while (low <= high)					//折半查找
	{
		if (L.elem[low].Sno == k)
			return low;
		if (L.elem[high].Sno == k)
			return high;

		mid = low + ((high - low) / 2);	//避免发生溢出

		if (L.elem[mid].Sno == k)
			return mid;
		if (L.elem[mid].Sno < k)
			low = mid + 1;
		else
			high = mid + 1;
	}
	if (No == -1)
		return ERROR;
	else
	{
		printf("排序成功\n");
		return k;
	}
}
/*═════╗
║  主函数  ║
╚═════*/
int main()
{
	SqList Students;
	int c = 0;				//选择功能
	int k = 0;				//返回数据所在位置
	if (InitList(Students) == OK)
		printf("初始化成功\n");
	else
		printf("初始化失败\n");

	while (1)
	{
		printf("/*-------------------------------------------------------------------------╗\n");
		printf("║       1 根据指定学生个数，逐个输入学生信息                               ║\n");//完成√
		printf("║       2 逐个显示学生表中所有学生的相关信息                               ║\n");//完成√	
		printf("║       3 给定一个学生信息，插入到表中指定的位置                           ║\n");//完成√
		printf("║       4 删除指定学号的学生记录                                           ║\n");//完成√
		printf("║       5 统计表中学生个数                                                 ║\n");//完成√
		printf("║       6 根据姓名（或者学号）进行顺序查找                                 ║\n");//完成√
		printf("║       7 利用直接插入排序按照学号进行排序                                 ║\n");//完成√	
		printf("║       8 利用冒泡排序按照数学成绩进行排序                                 ║\n");//完成√	
		printf("║       9 利用简单选择排序按照语文成绩进行排序                             ║\n");//完成√	
		printf("║       10 利用快速排序按照英语成绩进行排序                                ║\n");//完成√	
		printf("║       11 根据学号进行折半查找，成功返回此学生的姓名和各科成绩            ║\n");//完成√
		printf("║       12                      退出                                       ║\n");//完成√
		printf("╚--------------------------------------------------------------------------*/\n");
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
			if( Display(Students,1,Students.length,0)==OK)
				printf("显示完毕\n");
			break;
		case 3:
			
			if (Insert(Students) == ERROR)
				printf("插入失败\n");
			else
				Display(Students, 1, Students.length,0);
			break;
		case 4:
			if (Delete(Students) == ERROR)
				printf("删除失败，学号不存在\n");
			else
				Display(Students, 1, Students.length,0);
			break;
		case 5:
			count(Students);
			break;
		case 6:
			order(Students);
			break;
		case 7:
			StraightInsertionSort(Students);
			break;
		case 8:
			BubbleSort(Students);		
			break;
		case 9:
			SimpleSelectionSort(Students);
			break;
		case 10:
			if (QSort(Students, 1, Students.length) == OK)
			{
				printf("排序成功！\n");
				Display(Students, 1, Students.length,0);
			}
			break;
		case 11:
			k = binsearch(Students);
			if(k==ERROR)
				printf("查询失败，该学号不存在\n");
			else
			{
				Display(Students, k, k,1);
			}
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
