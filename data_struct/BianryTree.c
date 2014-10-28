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
#define TRUE 1
#define FALSE 0

typedef struct BitreeData
{
	char data;
	struct BitreeData * LT;
	struct BitreeData * RT;
}BitNode;

BitNode *  CreatTree()
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
	return p;
}

void PreOrder(BitNode * TrHead)
{
	if( TrHead )  {
		printf("%c  ",TrHead->data);
		PreOrder(TrHead->LT);
		PreOrder(TrHead->RT);
	}
}

void InOrder(BitNode * TrHead)
{
	if( TrHead )  {
		PreOrder(TrHead->LT);
		printf("%c  ",TrHead->data);
		PreOrder(TrHead->RT);
	}
}

void PostOrder(BitNode * TrHead)
{
	if( TrHead )  {
		PreOrder(TrHead->LT);
		PreOrder(TrHead->RT);
		printf("%c  ",TrHead->data);
	}
}



int main(int argc, char *argv[])
{
	BitNode * TreeHead;
	TreeHead = CreatTree();
	PreOrder(TreeHead);
	printf("\n");
	InOrder(TreeHead);
	printf("\n");
	PostOrder(TreeHead);
	printf("\n");
	return EXIT_SUCCESS;
}

