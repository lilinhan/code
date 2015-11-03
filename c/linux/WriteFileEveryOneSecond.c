/*************************************************************************
  > File Name: WriteFileEveryOneSecond.c
  > Author: lewin
  > Mail: lilinhan1303@gmail.com
  > Company:  Xiyou Linux Group
  > Created Time: Tue 03 Nov 2015 09:34:38 CST
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

int lock = 1; //0 = lock, 1 = unclock;

void WriteFile(int fd) {
    char *buf = "hello world!\n";
    while(1) {
        if(lock == 1)  {
            lock = 0;
            if(write(fd, (void *)buf, strlen(buf)) == -1) {
                fprintf(stderr, "Write Failed!\n");
                return -1;
            }
            lock = 1;
        }
        sleep(1);
    }
}

void ReadFile(int fd)  {
    char buf[10000];
    while(1)  {
        if(lock == 1)  {
            lock = 0;
            if(read(fd, (void *)buf, 10000) == -1) {
                fprintf(stderr, "Read Failed!\n");
                return -1;
            }
            lock = 1;
        }
        sleep(3);
    }
}

int main(int argc , char * argv[])  {
    int childfd = fork();
    switch(childfd) {
        case 0:;break;
        case -1:;break;
        default:;break;
    }

    return EXIT_SUCCESS;
}

