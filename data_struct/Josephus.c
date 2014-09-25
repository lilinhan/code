/*
 * =====================================================================================
 *
 *       Filename:  Josephus.c
 *
 *    Description:  约瑟夫环求m
 *
 *        Version:  1.0
 *        Created:  2014年09月17日 17时26分12秒
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

typedef struct data
{
	int data;
	struct data * next;
}Data;

int n;

Data * creat (int n)
{
	int i = 1;
	Data * head , *p , *q;
	head = p = (Data *)malloc(sizeof(Data));
	q = (Data *)malloc(sizeof(Data));
	q->data = i;
	p->next = q;
	for( i = 2; i <= n+1 ; i++ )  {
		p = q;
		q = (Data *)malloc(sizeof(Data));
		q->data = i;
		p->next = q;
	}
	p->next = head->next;

/*	p = head->next;
	i = 0;
	while( i < 7)  {
		printf("%d  ",p->data);
		p = p->next;
		i++;
	}
*/	
}

void get_m(int a[],int m,Data * head)
{
	Data *p,*q;
	int i = 0, m1 = 1 , n1;

	p = head->next;
	q = p->next;
	while( q->next != p )  {
		q = q->next;
	}

	while( p->next != p)  {
		if( m1 == m )  {
			q->next = p->next;
			a[i] = p->data;
			m1 = 1;
			free(p);
			p = q->next;
			i++;
			continue;
		}
		q = q->next;
		p = p->next;
		m1++;
	}
	a[i] = p->data;

}

int main(int argc, char *argv[])
{
	Data * head;
	int i,k,m ,a[100],x,b[100],flag = 0;
	printf("请输入人数:");
	scanf("%d",&n);
	printf("您要输入后几位？\n");
	scanf("%d",&x);
	printf("请输入出来的序列的子集:");
	for( i = 0 ; i < x ; i++ )  {
		scanf("%d",&b[i]);
	}

	for( m = 1; m < n ; m++ )  {
		flag = 0;
		head = creat(n);
		get_m(a,m,head);
		for( i = 0 ,k = n-x ; k<n ; k++ , i++ )  {
			if(a[k] != b[i] )  {
				flag = 1;
			}
		}
		if( flag == 0 )  {
			printf(" m = %d",m);
			return 0;
		}
		

	}


	return EXIT_SUCCESS;
}

