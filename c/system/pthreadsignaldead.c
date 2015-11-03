/*************************************************************************
    > File Name: pthradsignaldead.c
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: Wed 28 Oct 2015 19:11:48 CST
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
#include<semaphore.h>

#define LOOP_TIMES 10000

sem_t S1, S2;

void *thread_worker(void *);
void critical_section(int thread_num, int i);

int main(int argc , char * argv[])  {
    int rtn, i;
    sem_init(&S1, 0, 1);
    sem_init(&S2, 0, 1);

    pthread_t pthread_id = 0;

    rtn = pthread_create(&pthread_id, NULL, thread_worker, NULL);
    if(rtn != 0)  {
        printf("pthread_create ERROR!\n");
        return -1;
    }
    for(i = 0; i < LOOP_TIMES; ++i)  {
        sem_wait(&S1);
        sem_wait(&S2);
        critical_section(1, i);
        sem_post(&S1);
        sem_post(&S2);
    }
    sem_destroy(&S1);
    sem_destroy(&S2);

    return EXIT_SUCCESS;
}

void *thread_worker(void *p)  {
    int i;
    for(i = 0; i < LOOP_TIMES; ++i) {
        sem_wait(&S2);
        sem_wait(&S1);
        critical_section(2, i);
        sem_post(&S1);
        sem_post(&S2);
    }
}

void critical_section(int thread_num, int i)  {
    printf("Thread %d: %d\n",thread_num, i);
}

