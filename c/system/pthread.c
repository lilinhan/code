/*************************************************************************
    > File Name: pthread.c
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: Tue 27 Oct 2015 09:12:58 CST
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

#define MAX_THREAD 3
unsigned long long main_counter, counter[MAX_THREAD];
void *thread_work(void *);

int main(int argc , char * argv[])  {
    int i, rtn, ch;
    pthread_t ntid;
    pthread_t pthread_id[MAX_THREAD] = {0};
    for(i = 0; i < MAX_THREAD; i++)  {
        if(pthread_create(&ntid, NULL, thread_work, NULL) != 0)  {
            printf("Can't create new pthread!\n");
            return -1;
        }else {

        }

    }
    do{
        unsigned long long sum = 0;
        //
        for(i = 0; i < MAX_THREAD; i++) {
            sum += counter[i];
            printf("%llu\n",counter[i]);
        }
        printf("%llu/%llu\n", main_counter, sum);
    }while((ch = getchar()) != 'q');
    return EXIT_SUCCESS;
}

void *thread_work(void *p) {
    int thread_num;
    while(1) {
        counter[thread_num]++;
        main_counter++;
    }
}

