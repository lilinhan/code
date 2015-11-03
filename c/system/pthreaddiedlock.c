/*************************************************************************
    > File Name: pthreaddiedlock.c
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: Tue 27 Oct 2015 19:36:10 CST
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
#include<pthread.h>

#define LOOP_TIMES 10000

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex2 = PTHREAD_MUTEX_INITIALIZER;

void *thread_worker(void *);
void critical_section(int thread_num, int i);

int main(int argc , char * argv[])  {
    int rtn, i;
    pthread_t pthread_id = 0;
    rtn = pthread_create(&pthread_id, NULL, thread_worker, NULL);
    if(rtn == -1)  {
        printf("pthread_create ERROR!\n");
        return -1;
    }
    for(i = 0; i < LOOP_TIMES; ++i) {
        pthread_mutex_lock(&mutex1);
        pthread_mutex_lock(&mutex2);
        critical_section(1, i);
        pthread_mutex_unlock(&mutex2);
        pthread_mutex_unlock(&mutex1);
    }
    pthread_mutex_destroy(&mutex1);
    pthread_mutex_destroy(&mutex2);
    pause();
    return EXIT_SUCCESS;
}

void *thread_worker(void *p) {
    int i;
    for(i = 0 ; i < LOOP_TIMES; i++) {
        pthread_mutex_lock(&mutex1);
        pthread_mutex_lock(&mutex2);
        critical_section(2, i);
        pthread_mutex_unlock(&mutex2);
        pthread_mutex_unlock(&mutex1);
    }
}

void critical_section(int thread_num, int i) {
    printf("Thread %d: %d\n",thread_num, i);
}

