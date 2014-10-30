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

void InitNumStack(NS * s)
{
	s->numtop = -1;
}
void InitOperationStack(OS * s)
{
	s->optop = -1;
}

int NumIsFull(NS * s)
{
	if(s->numtop == Stack_Size - 1 )  {
		return FALSE;
	}
	else 
	      return TRUE;
}

int OperationIsFull( OS * s )
{
	if( s->optop == Stack_Size - 1)  {
		return FALSE;
	}
	else     
	      return TRUE;
}


int PushNum(NS * s , float x)
{
	if( s->numtop == Stack_Size - 1 )
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

int PopNum(NS * s , float * x )
{
	if(s->numtop == -1)  {
		return FALSE;
	}	
	*x = s->elem[s->numtop];
	s->numtop--;
	return TRUE;
}

int PopOperation(OS * s , char * ch)
{
	if(s->optop == -1)  {
		return FALSE;
	}
	*ch = s->elem[s->optop];
	s->optop--;
	return TRUE;
}

int GetNumTop(NS * s , float * x)
{
	if(s->numtop == -1) {
		return FALSE ;
	}
	*x = s->elem[s->numtop];
	return TRUE;
}

int GetOperationTop(OS * s , char * ch)
{
	if(s->optop == -1)  {
		return FALSE;
	}
	*ch = s->elem[s->optop];
	return TRUE;
}

float Calculation(float x , float y , char ch)
{
	float z;
	switch(ch)  {
		case'+':z = x + y;break;
		case'-':z = x - y;break;
		case'*':z = x * y;break;
		case'/':z = x / y;break;
	}
	return z;
}

int Result( NS * n , OS * o ,char a[])
{
	int flag = 1;
	float x = 0 , y = 0  , sum = 0;
	char sh;

	printf("%s = ",a);
	PopNum(n , &sum);
	while( n->numtop != -1 )  {
		PushOperation(o ,sh);
		PopNum(n , &x);
		sum = Calculation(sum,x,sh);
	}
	printf("%0.2f",sum);
}

int Judge( NS * n,OS * o , char a[])
{
	float x,y,z;
	int i = 0;
	char sh;
	if(o->optop == Stack_Size - 1 )  {
		return FALSE;
	}
	sh = '#';
	PushOperation(o,sh);
	while(a[i] != '#')    {//全部进栈并且将所有操作全部转化，仅剩+ -
		if(a[i] >= 48 && a[i]<=57 )  {
			x = a[i] - 48;
			PushNum(n,x);
		}
		else if(a[i] == '+' && ( o->elem[o->optop - 1] == '*' || o->elem[o->optop - 1] == '/'))  {
			PopNum(n,&x);
			PopNum(n,&y);
			PopOperation(o , &sh);
			z = Calculation( x, y , sh);
			PushNum(n , z);
		}
		else if(a[i] == '-' && (o->elem[o->optop - 1] == '*' || o->elem[o->optop - 1] == '/'))  {
			PopNum(n,&x);
			PopNum(n,&y);
			PopOperation(o , &sh);
			z = Calculation( x, y , sh);
			PushNum(n , z);
		}
		else if( a[i] == '*' || a[i] == '/') {
			sh = a[i];
			PopNum( n , &x);
			y = a[i+1] - 48;
			z = Calculation( x, y ,sh);
			PushNum(n,z);	
			i++;
		}
		else  {
		
			sh = a[i];
			PushOperation(o , sh);
		}
		i++;
	}
	
	Result(n , o , a);

	return TRUE;	
}

int main(int argc, char *argv[])
{
	NS  n;
	OS  o;
	char s[50];

	InitNumStack(&n);
	InitOperationStack(&o);
	printf("请输入多项式(以‘#’结束):");
	scanf("%s",s);
	printf("%s\n",s);
	Judge(&n,&o,s);


	
	return EXIT_SUCCESS;
}

