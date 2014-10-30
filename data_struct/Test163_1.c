/*
 * =====================================================================================
 *
 *       Filename:  Test163_1.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年10月29日 19时49分02秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lilinhan, lilinhan1303@gmail.com      693465363@qq.com
 *        Company:  Xiyou Linux Group
 *
 * =====================================================================================
 */
#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxSize 100
#define TRUE 1
#define FALSE 0

int count = 0;
int LeafNum = 0;
int HightTree = 0;


typedef struct BitreeData     //定义二叉树结构
{
	char data;
	struct BitreeData * LT;
	struct BitreeData * RT;
}BitNode;

typedef struct TreeStack    //定义栈
{
	BitNode Bt[MaxSize];
	int top;
}TS;

BitNode *  CreatTree()   //创建二叉树
{
	char c;
	BitNode * p;
	c = getchar();
	if( c == '#' )  {
		p = NULL;
	}
	else  {
		p = (BitNode *)malloc(sizeof(BitNode));
		p->data = c;
		p->LT = CreatTree();
		p->RT = CreatTree();
	}
	return p;   //两个条件最终都要返回p
}

void PreOrder(BitNode * TrHead)   //先序递归遍历二叉树
{
	if( TrHead )  {
		printf("%c  ",TrHead->data);
		PreOrder(TrHead->LT);
		PreOrder(TrHead->RT);
	}
}

void InOrder(BitNode * TrHead)   //中序递归遍历二叉树
{
	if( TrHead )  {
		PreOrder(TrHead->LT);
		printf("%c  ",TrHead->data);
		PreOrder(TrHead->RT);
	}
}

void PostOrder(BitNode * TrHead)     //后序递归遍历二叉树
{
	if( TrHead )  {
		PreOrder(TrHead->LT);
		PreOrder(TrHead->RT);
		printf("%c  ",TrHead->data);
	}
}

void InitStack( TS * s )   //初始化栈
{
	s->top = -1;
}

int StackIsEmpty(TS * s)   //判断栈是否为空
{
	if(s->top == -1)
	      return TRUE;
	else
	      return FALSE;
}

int PushStack( TS * s , BitNode *ch)
{
	if(s->top == MaxSize-1)  
	      	return FALSE;
	else  {
		s->top++;
		s->Bt[s->top] = *ch;
		return TRUE;
	}
}

int PopStack(TS * s , BitNode **ch)
{
	if(s->top == -1)
		return FALSE;
	else  {
		*ch = &(s->Bt[s->top]);
		s->top--;
		return TRUE;
	}
}

void PrintStack(TS * s)
{
	int i = 0;
	for( ; i < s->top ; i++)  {
		printf("%c  ",s->Bt[i].data);
	}
}

void PreOrdernon(BitNode * TrHead)    //先序非递归遍历二叉树
{
	TS s;
	BitNode *p;
	InitStack(&s);
	p = TrHead;
	while( p || !StackIsEmpty(&s) )  {
		while( p )  {
			printf("%c  ",p->data);
			PushStack(&s,p);
			p = p->LT;
		}
		if(!StackIsEmpty(&s))  {
			PopStack(&s , &p);
			p = p->RT;
		}
	}
}
void InOrdernon(BitNode * TrHead)    //先序非递归遍历二叉树
{
	TS s;
	BitNode *p;
	InitStack(&s);
	p = TrHead;
	while( p || !StackIsEmpty(&s) )  {
		while( p )  {
			PushStack(&s,p);
			p = p->LT;
		}
		if(!StackIsEmpty(&s))  {
			PopStack(&s , &p);
			printf("%c  ",p->data);
			p = p->RT;
		}
	}
}

void TwoCount(BitNode * TrHead)   //求度为2的节点个数
{
	if( TrHead )  {
		if(TrHead->LT != NULL && TrHead->RT !=NULL)
		      LeafNum++;
		TwoCount(TrHead->LT);
		TwoCount(TrHead->RT);
	}
}

void Exchanges(BitNode * TrHead)     //交换二叉树子树
{
	BitNode * p , *q;
	if( TrHead )  {

		if(TrHead->LT != NULL || TrHead->RT != NULL)  {
			q = TrHead->RT;
			p = TrHead->LT;
			TrHead->LT = q;
			TrHead->RT = p;
			Exchanges(TrHead->LT);
			Exchanges(TrHead->RT);
		}
	}
}

void FindPath( BitNode * TrHead , TS * s)    // 打印所有叶子节点到根的路径
{
	BitNode * p;
	if( TrHead )  {
		PushStack(s,TrHead);
		if(TrHead->LT == NULL && TrHead->RT == NULL)  {
			printf("%c:",TrHead->data);
		        PrintStack(s);
			printf("\n");
		}
		else   {
			FindPath(TrHead->LT,s);
			FindPath(TrHead->RT,s);
		}
		PopStack(s,&p);
	}
}

void TuplePrint( BitNode * TrHead , TS * s)  //用三元组的办法先序打印树的节点以及层数
{
	if( TrHead )  {
		PushStack(s,TrHead);
		printf("(%c,%d)",TrHead->data,s->top+1);
		TuplePrint(TrHead->LT,s);
		TuplePrint(TrHead->RT,s);
		PopStack(s,&TrHead);
	}

}

void NumsLesf(BitNode * TrHead)   //先序遍历求叶子节点个数
{
	if( TrHead )  {
		if(TrHead->LT == NULL && TrHead->RT == NULL)  
		      LeafNum++;
		NumsLesf(TrHead->LT);
		NumsLesf(TrHead->RT);
	}
}

void TreeHight(BitNode * TrHead,TS *s)   //先序求树的高度
{
	if( TrHead )  {
		PushStack(s,TrHead);
		if(TrHead->LT == NULL && TrHead->RT==NULL && HightTree < s->top )
		      HightTree = s->top;
		TreeHight(TrHead->LT,s);
		TreeHight(TrHead->RT,s);
	}
}

int main(int argc, char *argv[])
{
	TS s;
	InitStack(&s);
	BitNode * TreeHead;
	TreeHead = CreatTree();
/*	PreOrder(TreeHead);
	printf("\n");
	InOrder(TreeHead);
	printf("\n");
	PostOrder(TreeHead);
	printf("\n");
	PreOrdernon(TreeHead);
	printf("\n");
	InOrdernon(TreeHead);
	TwoCount(TreeHead);
	printf("%d\n",count);
	Exchanges(TreeHead);
	PreOrder(TreeHead);
	FindPath(TreeHead,&s);
	TuplePrint(TreeHead,&s);
	NumsLesf(TreeHead);
	printf("%d\n",LeafNum);
*/
	TreeHight(TreeHead,&s);
	printf("%d\n",HightTree);
	return EXIT_SUCCESS;
}

