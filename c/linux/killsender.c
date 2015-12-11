/*************************************************************************
    > File Name: killsender.c
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Organization: Xiyou Linux Group
    > Created Time: 2015年12月10日 星期四 15时07分41秒
 ************************************************************************/
#include<stdio.h>
#include<signal.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    int pid, signo;
    if(argc != 3) {
        perror("usage: killsender pid signo");
        exit(1);
    }

    sscanf(argv[1], "%d", &pid);
    sscanf(argv[2], "%d", &signo);

    if(kill(pid, signo) < 0)  {
        perror("kill");
        exit(1);
    }
    printf("OK,send signal finished\n");
    return EXIT_SUCCESS;
}

