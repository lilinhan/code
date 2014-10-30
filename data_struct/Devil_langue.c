/*
 * =====================================================================================
 *
 *       Filename:  Devil_langue.c
 *
 *    Description:  魔王语言
 *
 *        Version:  1.0
 *        Created:  2014年10月08日 19时12分25秒
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
#define FALSE 0
#define TRUE 1
#define Maxsize 100

typedef struct queue   //定义队列
{
	int front;
	int rear;
	char s[Maxsize];
}Que;


void InitQueue(Que * q)
{
	q->rear = q->front = 0;
}


int PushQue( Que * q , char x )
{
	if( (q->rear+1)%Maxsize == q->front )  {
		return FALSE;
	}
	else  {
		q->s[q->rear] = x;
		q->rear++;
	}
}

int PopQue( Que * q , char * x )  {
	if(q->rear == q->front )  {
		return FALSE;
	}
	else  {
		*x = q->s[q->front];
		q->front++;
	}
}

char GetTop(Que * q)
{
	return q->s[q->front];
}

int main(int argc, char *argv[])
{
	char str[Maxsize] , s[Maxsize] , ch;
	int i,j,k;
	Que que;

	InitQueue(&que);
	printf("请输入魔王语言!\n");
	scanf("%s",str);


	printf("%s\n",str);
	k = strlen(str);
	printf("%d\n",k);
	while (k >= 0 ){
		PushQue(&que ,str[k]);
		k--;
	}
	

/*
	for( i = 0 ; que.rear != que.front ; i++,que.front++ )  {
		if((ch = GetTop(&que)) == '(' )  {
			for( que.front++ ; ((ch = GetTop(&que)) != ')') ; i++ ,que.front++) {
				s[i] = que.s[que.front];
			}
		}
		else   {
			s[i] = que.s[que.front];
		}
	}
*/
	return EXIT_SUCCESS;
}

