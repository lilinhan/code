/*
 * =====================================================================================
 *
 *       Filename:  Arithmetic.c
 *
 *    Description:  表达式求值
 *
 *        Version:  1.0
 *        Created:  2014年09月25日 16时26分20秒
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
#define Stack_Size 50
#define TRUE 1
#define FALSE 0

typedef struct NumStack
{
	float elem[Stack_Size];
	int numtop;
}NS;

typedef struct OperationStack
{
	char elem[Stack_Size];
	int optop;
}OS;

void InitNumStack(struct NumStack * s)
{
	s->elem = -1;
}
void InitOperationStack(struct OperationStack * s)
{
	s->optop = -1;
}

int NumIsFull()
{
	if(s->numtop == Stack_Size - 1 )  {
		return FALSE;
	}
	else 
	      return TRUE;
}

int OperationIsFull()
{
	if( s->optop == Stack_Size - 1)  {
		return FALSE;
	}
	else     
	      return TRUE;
}


int PushNum(NS * s , float x)
{
	if(!NumIsFull(s))
	      return FALSE;
	s->numtop++;
	s->elem[s->numtop] = x;
	return TRUE;
}

int PushOperation(OS * s , char x)
{
	if(!OperationIsFull(s))
		return FALSE;
	s->optop++;
	s->elem[s->optop] = x;
	return TRUE;
}

int PopNum(NS * s , int * x )
{
	if(s->numtop == -1)  {
		return FALSE;
	}	
	x = s->elem[s->numtop];
	s->numtop--;
	return TRUE;
}

int PopOperation(OS * s , char * ch)
{
	if(s->optop == -1)  {
		return FALSE;
	}
	ch = s->elem[s->optop];
	s->optop--;
	return TRUE;
}

int GetNumTop(NS * s , int * x)
{
	if(s->numtop == -1) {
		return FALSE ;
	}
	x = s->elem[s->numtop];
	return TRUE;
}

int GetOperationTop(OS * s , char * ch)
{
	if(s->optop == -1)  {
		return FALSE;
	}
	ch = s->elem[s->optop];
	return TRUE;
}


int main(int argc, char *argv[])
{
	
	
	return EXIT_SUCCESS;
}

