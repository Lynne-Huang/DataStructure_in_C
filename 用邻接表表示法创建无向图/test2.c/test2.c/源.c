#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <math.h>
#include <time.h>
#define OK 1
#define	ERROR 0
#define TURE 1
#define FALSE 0
#define MVNum 100			//��󶥵���
typedef char VerTexType;	//���趥�������Ϊ�ַ���
typedef int ArcType;		//����ߵ�ȨֵΪ����
typedef int Status;			 /* Status �Ǻ���������,��ֵ�Ǻ������״̬����,�� OK �� */
							 /*  �߱���	*/
typedef struct EdgeNode
{
	int adjvex;														/*  �ڽӵ���,�洢�ö����Ӧ���±� */
	Status info;													/*  ���ڴ洢Ȩֵ,���ڷ���ͼ���Բ���Ҫ */
	struct ArcNode *nextarc; 										/*  ����,ָ����һ���ڽӵ� */
}ArcNode;
/*  ������� */
typedef struct VNode
{
	VerTexType data; 												/*  ������,�洢������Ϣ */
	ArcNode *firstarc;												/*  �߱�ͷָ�� */
}VNode, AdjList[MVNum];


typedef struct
{
	AdjList vertices;
	int vexnum, arcnum; 											/*  ͼ�е�ǰ�������ͱ��� */
}ALGraph;

/*  ����ͼ���ڽӱ�ṹ */
int CreateUDG(ALGraph *G)
{
	int i, j, k;
	ArcNode *e;
	printf("���붥�����ͱ���:\n");
	scanf_s("%d,%d", &G->vexnum, &G->arcnum); 						/*  ���붥�����ͱ��� */
	for (i = 0; i < G->vexnum; i++) 								/*  ���붥����Ϣ,��������� */
	{
		scanf_s(&G->vertices[i].data);								/*  ���붥����Ϣ */
		G->vertices[i].firstarc = NULL;								/*  ���߱���Ϊ�ձ� */
	}
	for (k = 0; k < G->arcnum; k++)									/*  �����߱� */
	{
		printf("�����(vi,vj)�ϵĶ������:\n");
		scanf_s("%d,%d", &i, &j); 									/*  �����(vi,vj)�ϵĶ������ */
		e = (ArcNode *)malloc(sizeof(ArcNode)); 					/*  ���ڴ�����ռ�,���ɱ߱��� */
		e->adjvex = j;												/*  �ڽ����Ϊ j */

		e->nextarc = G->vertices[i].firstarc;						/*  �� e ��ָ��ָ��ǰ������ָ��Ľ�� */
		G->vertices[i].firstarc = e;								/*  ����ǰ�����ָ��ָ�� e */


		e = (ArcNode *)malloc(sizeof(ArcNode));						/*  ���ڴ�����ռ�,���ɱ߱��� */
		e->adjvex = i;												/*  �ڽ����Ϊ i */
		e->nextarc = G->vertices[j].firstarc;						/*  �� e ��ָ��ָ��ǰ������ָ��Ľ�� */
		G->vertices[j].firstarc = e;								/*  ����ǰ�����ָ��ָ�� e */
	}
}
int main(void)
{
	ALGraph G;
	CreateUDG(&G);
	getchar();
}