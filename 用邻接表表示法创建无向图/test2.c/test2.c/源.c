#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <math.h>
#include <time.h>
#define OK 1
#define	ERROR 0
#define TURE 1
#define FALSE 0
#define MVNum 100			//最大顶点数
typedef char VerTexType;	//假设顶点的数据为字符型
typedef int ArcType;		//假设边的权值为整型
typedef int Status;			 /* Status 是函数的类型,其值是函数结果状态代码,如 OK 等 */
							 /*  边表结点	*/
typedef struct EdgeNode
{
	int adjvex;														/*  邻接点域,存储该顶点对应的下标 */
	Status info;													/*  用于存储权值,对于非网图可以不需要 */
	struct ArcNode *nextarc; 										/*  链域,指向下一个邻接点 */
}ArcNode;
/*  顶点表结点 */
typedef struct VNode
{
	VerTexType data; 												/*  顶点域,存储顶点信息 */
	ArcNode *firstarc;												/*  边表头指针 */
}VNode, AdjList[MVNum];


typedef struct
{
	AdjList vertices;
	int vexnum, arcnum; 											/*  图中当前顶点数和边数 */
}ALGraph;

/*  建立图的邻接表结构 */
int CreateUDG(ALGraph *G)
{
	int i, j, k;
	ArcNode *e;
	printf("输入顶点数和边数:\n");
	scanf_s("%d,%d", &G->vexnum, &G->arcnum); 						/*  输入顶点数和边数 */
	for (i = 0; i < G->vexnum; i++) 								/*  读入顶点信息,建立顶点表 */
	{
		scanf_s(&G->vertices[i].data);								/*  输入顶点信息 */
		G->vertices[i].firstarc = NULL;								/*  将边表置为空表 */
	}
	for (k = 0; k < G->arcnum; k++)									/*  建立边表 */
	{
		printf("输入边(vi,vj)上的顶点序号:\n");
		scanf_s("%d,%d", &i, &j); 									/*  输入边(vi,vj)上的顶点序号 */
		e = (ArcNode *)malloc(sizeof(ArcNode)); 					/*  向内存申请空间,生成边表结点 */
		e->adjvex = j;												/*  邻接序号为 j */

		e->nextarc = G->vertices[i].firstarc;						/*  将 e 的指针指向当前顶点上指向的结点 */
		G->vertices[i].firstarc = e;								/*  将当前顶点的指针指向 e */


		e = (ArcNode *)malloc(sizeof(ArcNode));						/*  向内存申请空间,生成边表结点 */
		e->adjvex = i;												/*  邻接序号为 i */
		e->nextarc = G->vertices[j].firstarc;						/*  将 e 的指针指向当前顶点上指向的结点 */
		G->vertices[j].firstarc = e;								/*  将当前顶点的指针指向 e */
	}
}
int main(void)
{
	ALGraph G;
	CreateUDG(&G);
	getchar();
}