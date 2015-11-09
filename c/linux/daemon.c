/*************************************************************************
    > File Name: daemon.c
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: Thu 05 Nov 2015 08:26:32 CST
 ************************************************************************/

#include<sys/types.h>
#include<sys/stat.h>
#include<limits.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<signal.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

#include<sys/param.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

void init_daemon() {
    pid_t pid;
    int i = 0, fd;
    char * str = "hello world!\n";
    if((pid = fork()) == -1)  {
        fprintf(stderr, "Fork error!");
        exit(0);
    }
    if(pid != 0)  {
        exit(0);
    }
    setsid();
    chdir("./");
    umask(0);
    for(; i < getdtablesize() ; ++i) {
        close(i);
    }

    while(1) {
        if((fd = open("hello", O_APPEND | O_WRONLY, 0666)) < 0)  {
            fprintf(stderr, "open error!\n");
            exit(0);
        }
        if(write(fd, (void *)str, strlen(str)) == -1) {
            fprintf(stderr, "write failed!\n");
            exit(0);
        }
        close(fd);
        sleep(1);
    }
}
int main(int argc , char * argv[])  {
    init_daemon();
    return EXIT_SUCCESS;
}

