/*************************************************************************
    > File Name: killrecver.c
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Organization: Xiyou Linux Group
    > Created Time: 2015年12月10日 星期四 15时23分30秒
 ************************************************************************/
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>
#include<stdlib.h>

void handle(int signo) {
    printf("\nreceive signal = %d\n", signo);
}

int main(int argc, char *argv[])
{
    if(signal(SIGUSR1, handle) == SIG_ERR)  {
        perror("signal");
        return;
    }
    printf("my pid is %d\n", getpid());
    printf("waiting for SIGUSR1...\n");

    pause();
    return EXIT_SUCCESS;
}

