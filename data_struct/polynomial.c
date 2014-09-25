/*
 * =====================================================================================
 *
 *       Filename:  polynomial.c
 *
 *    Description:  多项式的相加，相减，相乘，求导
 *
 *        Version:  1.0
 *        Created:  2014年09月18日 22时19分49秒
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

#define Maxcoef 10

typedef struct data 
{
	float coef;  //系数
	int expn;  //指数
	struct data * next;
}Data;

Data * CreatPolyn( )  //创建多项式
{
	Data * head,*p,*q;

	head = p = (Data *)malloc(sizeof(Data));
	q = (Data *)malloc(sizeof(Data));

	printf("输入各项系数、指数,系数为零结束\n");
	scanf("%f%d",&q->coef,&q->expn);
	while(q->coef != 0)  {
		p->next = q;
		p = q;
		q = (Data *)malloc(sizeof(Data));
		printf("输入各项系数、指数,系数为零结束\n");
		scanf("%f%d",&q->coef,&q->expn);
	}
	free(q);
	p->next = NULL;
/*
	p = head->next;
	while( p != NULL)  {
		printf("%f  %d\n",p->coef,p->expn);
		p = p->next;
	}
*/	
	return head;
}

void PrintPolyn(Data * h) //打印多项式
{
	Data * p;
	p = h->next;

	printf("y = ");
	while(p->next != NULL )  {
		printf("%0.2fx^%d ",p->coef,p->expn);
		p = p->next;
			printf(" + ");
	}
	printf("%0.2fx^%d ",p->coef,p->expn);
	printf("\n");

}



void DeletePolyn( Data * h )  //删除多项式
{
	Data * p , *q;
	p = h->next;
	q = p->next;

	while(p->next != NULL)  {
		free(p);
		p = q;
		q = q->next;
	}
	free(h);
	free(p);

}


Data * AddPolyn( Data * ha , Data * hb )  //多项式相加
{
	Data * head, * p ,* q , * r , *s;
	p = ha->next;
	q = hb->next;
	
	head = r = (Data *)malloc(sizeof(Data));
	s = (Data *)malloc(sizeof(Data));

	while( p != NULL  && q != NULL )  {
		if( p->expn > q->expn )  {
			s->coef = q->coef;
			s->expn = q->expn;
			q = q->next;
		}
		else if( p->expn < q->expn)  {
			s->coef = p->coef;
			s->expn = p->expn;
			p = p->next;
		}
		else if( p->expn == q->expn )  {
			s->coef = p->coef + q->coef;
			s->expn = p->expn;
			p = p->next;
			q = q->next;
		}
		r->next = s;
		r = s;
		s = (Data *)malloc(sizeof(Data));
	}
	r->next = NULL;
	free(s);
	if( p != NULL )  {
		r->next = p;
	}
	if( q != NULL )  {
		r->next = q;
	}
	return head;
			
}

Data * SubtractPolyn( Data * ha , Data * hb )  //多项式相减
{
	Data * p;

	p = hb->next;
	while( p != NULL)  {
		p->coef = (-1) * p->coef;
		p = p->next;
	}
	
	return (AddPolyn(ha,hb));
	
}

Data * MuitiplyPolyn( Data * ha , Data * hb  )  // 多项式相乘
{
	float a[Maxcoef] = {0} , b[Maxcoef] = {0} , c[100] = {0};
	Data * p , *q;
	int i , j;

	p = ha->next;
	while(p)  {
		a[p->expn] = p->coef;
		p = p->next;
	}
	p = hb->next;
	while(p)  {
		b[p->expn] = p->coef;
		p = p->next;
	}

	for( i = 0 ; i < Maxcoef ; i++ )  {
		j = 0;
		for( ; j < Maxcoef ; j++ )  {
			c[i+j] += a[i] * b[j];
		}
	}

	printf("y = ");
	if(c[0] == 0 )  {
		printf("%0.2fx^%d ",c[0]);
	}
	for( i = 1 ; i < 99 ; i++ )  {
		if( c[i] != 0 )  {
			printf(" + ");
			printf("%0.2fx^%d ",c[i],i);
		}
	}
	if( c[i] != 0 )  {
		printf("%0.2fx^%d ",c[i],i);
	}
	printf("\n");
	


}
void * DerivationPolyn( Data * ha , Data * hb )  //多项式求导
{
	Data * p , *q;
	q = ha;
	p = ha->next;
	while(p)  {
		if(p->expn == 0)  {
			q->next = p->next;
			free(p);
			p = q->next;
			continue;
		}
		else  {
			p->coef = p->coef * p->expn;
			p->expn = p->expn - 1;
			p = p->next;
			q = q->next;
		}
	}

	q = hb;
	p = hb->next;
	while(p)  {
		if(p->expn == 0)  {
			q->next = p->next;
			free(p);
			p = q->next;
			continue;
		}
		else  {
			p->coef = p->coef * p->expn;
			p->expn = p->expn - 1;
			p = p->next;
			q = q->next;
		}
	}
	
}

int function_sight()
{
	int m;
	printf("\t\t1、多项式相加\n");
	printf("\t\t2、多项式相减\n");
	printf("\t\t3、多项式相乘\n");
	printf("\t\t4、多项式求导\n");

	printf("请选择功能:");
	scanf("%d",&m);
	return m;

}
int main(int argc, char *argv[])
{
	int i , m;
	Data * head1, *head2 , *head3;

	printf("创建多项式1：\n");
	head1 = CreatPolyn();
	printf("创建多项式2：\n");
	head2 = CreatPolyn();
	PrintPolyn(head1);PrintPolyn(head2);
	m = function_sight();
	switch (m)  {
		case 1:{
			       head3 = AddPolyn(head1 , head2);PrintPolyn(head3);
			}break;
		case 2:{
			       head3 = SubtractPolyn(head1 , head2);PrintPolyn(head3);
			}break;
		case 3:{
			       head3 = MuitiplyPolyn(head1 , head2);
		       }break;
		case 4:{
			       DerivationPolyn(head1 , head2);PrintPolyn(head1);PrintPolyn(head2);
		       }break; 
		default:{
				DeletePolyn(head3);
			}break;
	}

	



	return EXIT_SUCCESS;
}

