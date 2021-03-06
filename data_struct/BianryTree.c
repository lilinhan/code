/*
 * =====================================================================================
 *
 *       Filename:  BianryTree.cpp
 *
 *    Description:  二叉树
 *
 *        Version:  1.0
 *        Created:  2014年10月23日 13时11分25秒
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


int main(int argc, char *argv[])
{
	BitNode * TreeHead;
	TreeHead = CreatTree();
/*	PreOrder(TreeHead);
	printf("\n");
	InOrder(TreeHead);
	printf("\n");
	PostOrder(TreeHead);
	printf("\n");
*/
	PreOrdernon(TreeHead);
	printf("\n");
	InOrdernon(TreeHead);
	return EXIT_SUCCESS;
}

