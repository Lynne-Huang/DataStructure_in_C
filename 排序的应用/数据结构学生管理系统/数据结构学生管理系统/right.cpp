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
	int No;					/*���*/
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
/*�T�T�T�T�T�T�T�[
�U����ѧ����Ϣ  �U
�^�T�T�T�T�T�T�T*/
void stu_ifo(int i,SqList &L)
{
	printf("�����%d��ѧ��\n", i);
	L.elem[i].No = i;
	while (1)
	{
		printf("������ѧ�ţ�");
		scanf("%d", &L.elem[i].Sno);
		if (L.elem[i].Sno <= 0)
		{
			printf("ѧ�����������ѧ�ɼ�Ӧ����0,");
		}
		else
			break;
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
	L.elem->No = 0;
	printf("����༶������");
	scanf("%d",&a);
	if(a<1||a>MAXSIZE)
		return ERROR;
	for(int i=1;i<=a;i++)
	{
		stu_ifo(i,L);
	
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
int Display(SqList &L)
{
	int flag;
	printf("/*�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
	printf("�U                   ѧ����Ϣ                     �U\n");
	printf("�U�������������������������������������������������U\n");
	printf("�U ��� |ѧ�� |  ����  | ���ĳɼ� | ��ѧ�ɼ� | Ӣ��ɼ� �U\n");

	for(int i=1;i<=L.length;i++)
	{
		printf("�U�������������������������������������������������U\n");
		printf("�U%d |%d  | %s |  %.2f  |  %.2f   |  %.2f   �U\n",L.elem[i].No,L.elem[i].Sno,L.elem[i].Name,L.elem[i].Cscore,L.elem[i].Mscore,L.elem[i].Escore);
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
int Insert(SqList &L)
{
	while (1)
	{
		int flag;
		int index;
		printf("������������λ�ã�");
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
					strcpy(L.elem[i + 1].Name, L.elem[i].Name);		//strcmp�������Ƚ������ַ���
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
	int num=0;
	printf("��������Ҫɾ�����ݵ�ѧ�ţ�");
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
	printf("ɾ���ɹ�\n");
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
/*�T�T�T�T�T�T�T�T�T�[
�U ͳ�Ʊ���ѧ������ �U
�^�T�T�T�T�T�T�T�T�T*/
int count(SqList &L)
{
	int flag;
	int a;
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
�U ��������������ѧ�ţ�����˳����ң� �U
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
							num = L.elem[i].No;
							printf("/*�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
							printf("�U                   ѧ����Ϣ                     �U\n");
							printf("�U�������������������������������������������������U\n");
							printf("�U ��� |ѧ�� |  ����  | ���ĳɼ� | ��ѧ�ɼ� | Ӣ��ɼ� �U\n");
							printf("�U�������������������������������������������������U\n");
							printf("�U %d |%d  | %s |  %.2f  |  %.2f   |  %.2f   �U\n",L.elem[i].No, L.elem[i].Sno, L.elem[i].Name, L.elem[i].Cscore, L.elem[i].Mscore, L.elem[i].Escore);
							printf("�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T*/\n");
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
					for (int i = 0; i <= L.length; i++)
					{
						if (L.elem[i].Sno == sno)	//strcmp�������Ƚ������ַ���
						{
							num = L.elem[i].No;
							printf("/*�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
							printf("�U                   ѧ����Ϣ                     �U\n");
							printf("�U�������������������������������������������������U\n");
							printf("�U ��� | ѧ�� |  ����  | ���ĳɼ� | ��ѧ�ɼ� | Ӣ��ɼ� �U\n");
							printf("�U�������������������������������������������������U\n");
							printf("�U %d |%d  | %s |  %.2f  |  %.2f   |  %.2f   �U\n", L.elem[i].No, L.elem[i].Sno, L.elem[i].Name, L.elem[i].Cscore, L.elem[i].Mscore, L.elem[i].Escore);
							printf("�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T*/\n");
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

//(7)  ����ֱ�Ӳ���������ѧ�Ž�������

//(8)  ����ð����������ѧ�ɼ���������

//(9)  ���ü�ѡ�����������ĳɼ���������

//(10)  ���ÿ���������Ӣ��ɼ���������

//(11) ����ѧ�Ž����۰���ң��ɹ����ش�ѧ���������͸��Ƴɼ���

int main()
{
	SqList Students;
	int c = 0;

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
		printf("�U       4 ɾ��ָ��λ�õ�ѧ����¼                                           �U\n");//��ɡ�
		printf("�U       5 ͳ�Ʊ���ѧ������                                                 �U\n");//��ɡ�
		printf("�U       6 ��������������ѧ�ţ�����˳�����                                 �U\n");//��ɡ�
		printf("�U       7 ����ֱ�Ӳ���������ѧ�Ž�������                                 �U\n");
		printf("�U       8 ����ð����������ѧ�ɼ���������                                 �U\n");
		printf("�U       9 ���ü�ѡ�����������ĳɼ���������                             �U\n");
		printf("�U       10 ���ÿ���������Ӣ��ɼ���������                                �U\n");
		printf("�U       11 ����ѧ�Ž����۰���ң��ɹ����ش�ѧ���������͸��Ƴɼ�            �U\n");
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
			if( Display(Students)==OK)
				printf("��ʾ���\n");
			break;
		case 3:
			
			if(Insert(Students)==ERROR)
				printf("����ʧ��\n");
			break;
		case 4:
			if (Delete(Students) == ERROR)
				printf("ɾ��ʧ�ܣ�ѧ�Ų�����\n");
			break;
		case 5:
			if (count(Students) == OK)
				printf("ͳ�Ƴɹ�\n");
			else
				printf("ͳ��ʧ��\n");
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
			printf("�������\n");
		}
	}
	getchar();
}

