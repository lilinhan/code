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
#include<fcntl.h>

#include<sys/time.h>

int lock = 1; //0 = lock, 1 = unclock;

void WriteFile() {
    struct itimerval time;
    time.it_interval.tv_usec = 0;
    time.it_interval.tv_sec = 1;
    time.it_value.tv_usec = 0;
    time.it_value.tv_sec = 1;
    if(setitimer(ITIMER_REAL, &time, NULL) < 0) {
        fprintf(stderr, "Setitimer Failed.");
        return;
    }
    char *buf = "hello world!\n";
    while(1) {
        int fd = open("./1.text", O_APPEND | O_WRONLY, 0666);
        if(lock == 1)  {
            lock = 0;
            if(write(fd, (void *)buf, strlen(buf)) == -1) {
                fprintf(stderr, "Write Failed!\n");
                return;
            }
            lock = 1;
        }
        close(fd);
    }
}

void ReadFile()  {
    struct itimerval time;
    time.it_interval.tv_usec = 0;
    time.it_interval.tv_sec = 3;
    time.it_value.tv_usec = 0;
    time.it_value.tv_sec = 1;
    if(setitimer(ITIMER_REAL, &time, NULL) < 0) {
        fprintf(stderr, "Setitimer Failed.");
        return;
    }
    char buf[10000];
    while(1)  {
        int fd = open("./1.text", O_RDONLY, 0666);
        if(lock == 1)  {
            lock = 0;
            if(read(fd, (void *)buf, 10000) == -1) {
                fprintf(stderr, "Read Failed!\n");
                return;
            }
            lock = 1;
            printf("%s\n",buf);
        }
        close(fd);
        sleep(3);
    }
}

int main(int argc , char * argv[])  {
    int childfd = fork();
    switch(childfd) {
        case 0:WriteFile();break;
        case -1:fprintf(stderr, "Fork Failed.");break;
        default:ReadFile();break;
    }
    return EXIT_SUCCESS;
}

