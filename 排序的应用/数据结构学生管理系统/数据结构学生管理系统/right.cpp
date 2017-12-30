/**
*������;��ѧ������ϵͳ
*@author �ƾ���
*С���Ա��307�ƾ��ա�306��ٻ��410������
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

typedef struct Student		//����ѧ���ṹ�� 
{
	int Sno;				/*ѧ��*/
	char Name[20] = { '\0' };			/*����*/
	float Mscore;		/*��ѧ�ɼ�*/
	float Cscore;		/*���ĳɼ�*/
	float Escore;		/*Ӣ��ɼ�*/
}Stu;
typedef struct
{
	Stu elem[MAXSIZE];
	int length;			/*��ǰ�Ѵ�����*/
}SqList;
/*�T�T�T�T�T�T�T�T�[
�U��ʼ�� student  �U
�^�T�T�T�T�T�T�T�T*/
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
/*�T�T�T�T�T�T�T�[
�U����ѧ����Ϣ  �U
�^�T�T�T�T�T�T�T*/
void stu_ifo(int i,SqList &L)			//i�����λ��
{
	int length = L.length;
	printf("�����%d��ѧ��\n", i);
	while (1)
	{
		int sno=0;
		printf("������ѧ�ţ�");
		int flag = 0;
		scanf("%d", &sno);
		
		for (int j = 1; j <= length; j++)
		{
			if (L.elem[j].Sno == sno)
			{
				printf("ѧ��������󣬸�ѧ���Ѵ��ڣ�");
				flag = 1;
				break;
			}
		}
		/*bug:�����ѧ�ŷ�����ֵ��δ���д�����ʾҲδ���¸�ֵ*/
		if (flag == 1)	continue;
		else if (sno <= 0)			//ѧ�Ų�Ϊ�� 
		{
			printf("ѧ���������,ѧ��Ӧ�ô���0,");
			flag = 1;
			
		}
		else
		{
			L.elem[i].Sno = sno;
			break;
		}
		
	}
	printf("������������");
	scanf("%s", &L.elem[i].Name);
	
	while (1)
	{
		printf("��������ѧ�ɼ���");
		scanf("%f", &L.elem[i].Mscore);
		if (L.elem[i].Mscore < 0 || L.elem[i].Mscore>100)
		{
			printf("�ɼ����������ѧ�ɼ�Ӧ�ڣ�0-100��֮��,");
		}
		else
			break;
	}
	while (1)
	{
		printf("���������ĳɼ���");
		scanf("%f", &L.elem[i].Cscore);
		if (L.elem[i].Cscore < 0 || L.elem[i].Cscore>100)
		{
			printf("�ɼ�����������ĳɼ�Ӧ�ڣ�0-100��֮��,");
		}
		else
			break;
	}
	while (1)
	{
		printf("������Ӣ��ɼ���");
		scanf("%f", &L.elem[i].Escore);
		if (L.elem[i].Escore < 0 || L.elem[i].Escore>100)
		{
			printf("�ɼ��������Ӣ��ɼ�Ӧ�ڣ�0-100��֮��,");
		}
		else
			break;
	}
}

/*�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[
�U����ָ��ѧ���������������ѧ����Ϣ  �U
�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T*/
int StuCreat(SqList &L)
{
	int a;
	int flag;
	L.length=0;
	printf("����༶������");
	scanf("%d",&a);
	if(a<1||a>MAXSIZE)
		return ERROR;
	for(int i=1;i<=a;i++)
	{
		stu_ifo(i,L);		//i λ��
		L.length++;
		printf("���������밴1��������һ���˵��밴2���˳��밴0: ");
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
/*�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[
�U �����ʾѧ����������ѧ���������Ϣ �U
�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T*/
int Display(SqList &L,int star,int end,int index)	//star��ʼ��ʾ��λ��  end������ʾ��λ��	flag ���� 0��ͨ��ʾ 1��ѯ��ʾ
{
	int flag;
	
	printf("/*�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
	printf("�U                   ѧ����Ϣ                     �U\n");
	printf("�U�������������������������������������������������U\n");
	printf("�U ��� |ѧ�� |  ����  | ���ĳɼ� | ��ѧ�ɼ� | Ӣ��ɼ� �U\n");
	if(index==0)
	{
		for (int i = star; i <= end; i++)
		{
			printf("�U�������������������������������������������������U\n");
			printf("�U%d |%d  | %s |  %.2f  |  %.2f   |  %.2f   �U\n", i, L.elem[i].Sno, L.elem[i].Name, L.elem[i].Cscore, L.elem[i].Mscore, L.elem[i].Escore);
		}
	}
	if (index == 1)
	{
		for (int i = star; i <= end; i++)
		{
			int no = 1;
			printf("�U�������������������������������������������������U\n");
			printf("�U%d |%d  | %s |  %.2f  |  %.2f   |  %.2f   �U\n",no , L.elem[i].Sno, L.elem[i].Name, L.elem[i].Cscore, L.elem[i].Mscore, L.elem[i].Escore);
		}
	}
	
	printf("�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T*/\n");
	printf("������һ���˵��밴1���˳��밴0: ");
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
/*�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[
�U ����һ��ѧ����Ϣ�����뵽����ָ����λ�� �U
�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T*/
int Insert(SqList &L)//
{
	while (1)
	{
		int flag;
		int index;
		printf("������������λ�ã�");
		scanf("%d", &index);
		int length = L.length;
		if ((index < 1) || (index > length + 1))
			return ERROR;
		if(	 (L.length>= MAXSIZE))
			return ERROR;
		if (index == length+1)						//ĩ�˲�����ֵ
		{
			L.length=L.length+1;
			for (int i = index ; i <= index ; i++)
			{
				stu_ifo(i, L);						//i�����λ��
			}
		}
		else
		{
			L.elem[0] = L.elem[index];
			for (int i = L.length; i >= 0; i--)					//��λ 
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
		printf("����ɹ�\n");
		printf("���������밴1��������һ���˵��밴2���˳��밴0: ");
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

/*�T�T�T�T�T�T�T�T�T�T�T�T�[
�U ɾ��ָ��λ�õ�ѧ����¼ �U
�^�T�T�T�T�T�T�T�T�T�T�T�T*/
int Delete(SqList &L)
{
	int flag;
	int i;
	int num = 0;
	while (1)
	{
		printf("��������Ҫɾ�����ݵ�ѧ�ţ�");
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
		printf("ɾ���ɹ�\n");
		printf("ɾ�������밴 1��������һ���˵��밴2���˳��밴0: ");
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
/*�T�T�T�T�T�T�T�T�T�[
�U ͳ�Ʊ���ѧ������ �U
�^�T�T�T�T�T�T�T�T�T*/
int count(SqList &L)
{
	int flag;
	int a;
	printf("ͳ�Ƴɹ���");
	printf("����ѧ������Ϊ��%d\n", L.length);
	printf("������һ���˵��밴1���˳��밴0: ");
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
/*�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[
�U ��������������ѧ�ţ�����˳�����   �U
�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T*/
int order(SqList &L)
{
	int a;
	int sno;
	char sname[8]{'\0'};
	
	while (1)
	{
		printf("��������Ҫ�Ĳ��ҷ�ʽ��0���������ң�1��ѧ�Ų��ң�");
		scanf("%d", &a);
		
		switch (a)
		{
			case 0:
			{
				
				printf("������Ҫ���ҵ�������");
				scanf("%s", sname);
				if (!strcmp(sname, "\0"))
				{
					printf("�����������������\n");
					continue;
				}
				else
				{
					int num = 0;
					for (int i = 1; i <= L.length; i++)
					{
						if (strcmp(L.elem[i].Name, sname) == 0)	//strcmp�������Ƚ������ַ���
						{
							num = i;
							Display(L, i, i,1);
							return OK;
						}
					}
					if (num == 0)
					{
						printf("��ѯʧ�ܸ�ѧ��������\n");
						return ERROR;
					}
				}
			}
			case 1:
			{	int num = 0;
				printf("������Ҫ���ҵ�ѧ�ţ�");
				scanf("%d", &sno);
				if (sno == 0)
				{
					printf("�����������������\n");
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
						printf("��ѯʧ�ܸ�ѧ��������\n");
						return ERROR;
					}
				}
			}
			default:
				printf("�����������������\n");
		}
	}
}
/*�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[
�U ����ֱ�Ӳ���������ѧ�Ž�������   �U
�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T*/
int StraightInsertionSort(SqList &L)	//ѧ�Ŵ�С�����˳����     ��������������
{
	int i, j;
	for(i=2;i<=L.length;i++)			//ѭ���ӵڶ�������ʼ
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
	
	return OK;
}
/*�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[
�U ����ð����������ѧ�ɼ���������   �U
�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T*/
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
	return OK;
}
/*�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[
�U ���ü�ѡ�����������ĳɼ��������� �U
�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T*/
int SimpleSelectionSort(SqList &L)
{
	Stu min[MAXSIZE] = { '\0' };
	//Stu empty[MAXSIZE] = { '\0' };
	for (int i = 1; i <= L.length; i++)
	{
		min[i] = L.elem[i];
		for (int j = i + 1; j <= L.length; j++)
		{
			if (L.elem[j].Cscore < min[i].Cscore)			//�ҳ���Сֵ
			{
				min[i] = L.elem[j];
			}
			if (min[i].Cscore != L.elem[i].Cscore)
			{
				L.elem[0] = L.elem[i];
				L.elem[i] = min[i];						//����Сֵ�Ƶ���ǰ
				L.elem[j] = L.elem[0];
			}

		}
	}
	Display(L,1,L.length,0);
	printf("����ɹ�\n");
	return OK;
}

/*�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[
�U ���ÿ���������Ӣ��ɼ���������   �U
�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T*/
//�����ϵ���Ƶ��д��д�ģ�����ʦ��������㷨֮���ڸ�д��2018�ټ���(*^_^*)
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
	//L.elem[low].Escore = pivotkey;
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
/*�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[
�U ����ѧ�Ž����۰���ң��ɹ����ش�ѧ���������͸��Ƴɼ�   �U
�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T*/
int binsearch(SqList &L)
{
	
	int k = 0;							//Ŀ��ѧ��
	int No = -1;						//Ŀ�����ڵ����
	printf("������Ҫ��ѯ��ѧ�ţ�");
	scanf("%d", &k);
	if (k <= 0)
		return ERROR;
	for (int i = 2; i <= L.length; i++)	//�۰��������
	{
		L.elem[0] = L.elem[i];
		int low = 1;					//��Сֵ
		int high = i-1;			//���ֵ
		int mid;						//�м�ֵ
		while (low <= high)
		{
			mid = (low + high) / 2;//low + ((high - low) / 2);
			/*if (L.elem[mid].Sno =)
				return mid;*/
			if (L.elem[0].Sno < L.elem[mid].Sno)
				high = mid - 1;
			else
				low = mid + 1;
		}
		for (int j = i - 1; j >= high; j--)
		{
			L.elem[j + 1] = L.elem[j];	//����
		}
		L.elem[high + 1] = L.elem[0];	//����
	}
	//Display(L, 1, L.length);
	int low = 1;						//��Сֵ
	int high = L.length;				//���ֵ
	int mid=0;							//�м�ֵ
	while (low <= high)					//�۰����
	{
		if (L.elem[low].Sno == k)
			return low;
		if (L.elem[high].Sno == k)
			return high;

		mid = low + ((high - low) / 2);	//���ⷢ�����

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
		printf("����ɹ�\n");
		return k;
	}
}



int main()
{
	SqList Students;
	int c = 0;				//ѡ����
	int k = 0;				//������������λ��
	if (InitList(Students) == OK)
		printf("��ʼ���ɹ�\n");
	else
		printf("��ʼ��ʧ��\n");

	while (1)
	{
		printf("/*�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
		printf("�U       1 ����ָ��ѧ���������������ѧ����Ϣ                               �U\n");//��ɡ�
		printf("�U       2 �����ʾѧ����������ѧ���������Ϣ                               �U\n");//��ɡ�	
		printf("�U       3 ����һ��ѧ����Ϣ�����뵽����ָ����λ��                           �U\n");//��ɡ�
		printf("�U       4 ɾ��ָ��ѧ�ŵ�ѧ����¼                                           �U\n");//��ɡ�
		printf("�U       5 ͳ�Ʊ���ѧ������                                                 �U\n");//��ɡ�
		printf("�U       6 ��������������ѧ�ţ�����˳�����                                 �U\n");//��ɡ�
		printf("�U       7 ����ֱ�Ӳ���������ѧ�Ž�������                                 �U\n");//��ɡ�	
		printf("�U       8 ����ð����������ѧ�ɼ���������                                 �U\n");//��ɡ�	
		printf("�U       9 ���ü�ѡ�����������ĳɼ���������                             �U\n");//��ɡ�	
		printf("�U       10 ���ÿ���������Ӣ��ɼ���������                                �U\n");//��ɡ�	
		printf("�U       11 ����ѧ�Ž����۰���ң��ɹ����ش�ѧ���������͸��Ƴɼ�            �U\n");//��ɡ�
		printf("�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T*/\n");
		printf("��ѡ���ܣ�");
		scanf("%d", &c);
		switch (c)
		{
		case 1:
			if(StuCreat(Students)==OK)
			{
				printf("�����ɹ���?(��?�ޡ�)?\n");
				printf("��ǰ�Ѵ�������%d\n",Students.length);
			}
			else
				printf("����ʧ��(�Уߩ�)\n");
			break;
		case 2:
			if( Display(Students,1,Students.length,0)==OK)
				printf("��ʾ���\n");
			break;
		case 3:
			
			if (Insert(Students) == ERROR)
				printf("����ʧ��\n");
			else
				Display(Students, 1, Students.length,0);
			break;
		case 4:
			if (Delete(Students) == ERROR)
				printf("ɾ��ʧ�ܣ�ѧ�Ų�����\n");
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
				printf("����ɹ���\n");
				Display(Students, 1, Students.length,0);
			}
			break;
		case 11:
			k = binsearch(Students);
			if(k==ERROR)
				printf("��ѯʧ�ܣ���ѧ�Ų�����\n");
			else
			{
				Display(Students, k, k,1);
			}
			break;
		case 12:
			exit(OK);
			break;
		default:
			printf("�������\n");
		}
	}
	getchar();
}

