/*
 * =====================================================================================
 *
 *       Filename:  1.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年05月16日 10时02分56秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lewin (lilinhan), lilinhan1303@gmail.com
 *        Company:  Xiyou Linux Group
 *
 * =====================================================================================
 */

#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FALSE 1
#define TRUE 0
struct stu
{
	int i;
	struct stu *next;
	struct stu *next1;

};
struct stu * creat()
{
	struct stu * head=NULL,*p,*pnew;
	int count=0;
        pnew=in(1);
	printf("input:\n");
	scanf("%d",&(pnew->i));
	pnew->next=NULL;
	p=pnew;
	head=pnew;
	while(pnew->i)
	{
		pnew=in(count);
		pnew->next=NULL;
		p->next=pnew;
		p=pnew;
	}
	p->next=NULL;
	free(pnew);
	return head;

}
struct stu * in(int count)
{
	struct stu* q;
	q=(struct stu*)malloc(sizeof(struct stu));
	if(q==NULL)
	      exit(0);
	if(count==1)
	      return q;
	scanf("%d",&(q->next));
	return q;
}
struct stu*insert(struct stu*head)
{
	struct stu *p=head,*pnew;
	while(p->next!=NULL)
		p=p->next;
	pnew=in(1);
	printf("input:\n");
	scanf("%d",&(pnew->i));
	p->next=pnew;
	pnew->next=NULL;
	return head;
}
struct stu * out(struct stu* head)
{
	struct stu *p=head,*p1=head;
	p=p->next;
	head=p;
	free(p1);
	return head;

}
int emp(struct stu *head)
{
	if(head->next==NULL)
	      return FALSE;
	return TRUE;
}

print(struct stu *head)
{
	struct stu *p=head;
	while(p!=NULL)
	{
		printf("%d   ",p->i);
		p=p->next;
	}
}
int main(int argc, char *argv[])
{
	struct stu *head;
	head=creat();
	print(head);

	return EXIT_SUCCESS;
}

