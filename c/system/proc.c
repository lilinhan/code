/*************************************************************************
    > File Name: proc.c
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: Tue 27 Oct 2015 08:09:50 CST
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
#include<ctype.h>

#define MAX_CHILD_NUMBER 10
#define SLEEP_INTERVAL 2

int proc_number = 0;
void do_something();

int main(int argc , char * argv[])  {
    int child_proc_number = MAX_CHILD_NUMBER;
    int i, ch;
    pid_t child_pid, father_pid;
    pid_t pid[10] = {0};

    if(argc > 1)  {
        child_proc_number = atoi(argv[1]);
        child_proc_number = (child_proc_number > 10) ? 10 : child_proc_number;
    }
    for(i = 0; i < child_proc_number; i++)  {
        child_pid = fork();
        pid[i] = child_pid;
        if(child_pid == 0)  {
            proc_number++;
            printf("process %d , proc_number = %d\n", getpid(), proc_number);
            pid[i] = getpid();
            do_something();
        }else{
            father_pid = getpid();
            printf("This is father! ID = %d\n", father_pid);
        }
    }
/*
    for(i = 0; i <child_proc_number; i++) {
        printf("id = %d , pid = %d\n", i, pid[i]);
    }
*/
    while((ch = getchar()) != 'q') {
        if(isdigit(ch))  {
            if(kill(pid[ch-'0'], SIGTERM) == -1)  {
                printf("kill failed!\n");
                return -1;
            }
            printf("child process NO.%d is killed!\n",pid[ch-'0']);
        }
    }

    if(kill(-child_pid, SIGTERM) == 0)  {
        printf("Already killed all process!\n");
    }else {
        printf("Kill all process is failed!\n");
        return -1;
    }

    pause();
    return EXIT_SUCCESS;
}


void do_something() {
    printf("This is son.waiting....");
    pause();
}
