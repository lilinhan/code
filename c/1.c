/*
 * =====================================================================================
 *
 *       Filename:  1.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年05月14日 21时03分45秒
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
#include <mysql.h>
int main(int argc, char *argv[])
{
	
	MYSQL mysql;

	int t,r;
	mysql_init(&mysql);

	if(!mysql_real_connect(&mysql , "localhost" , "root" , "lewin123" , "llh" , 0 , NULL , 0))  {
		printf("Error connecting  to Mysql!\n");
	}
	else {
		printf("Connected Mysql successful!\n");
	}

	mysql_close(&mysql);
	return EXIT_SUCCESS;
}

