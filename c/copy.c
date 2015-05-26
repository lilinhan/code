/*************************************************************************
    > File Name: copy.c
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: 2015年05月26日 星期二 09时34分06秒
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

#ifndef BUF_SIZE
#define BUF_SIZE 1024
#endif

int main(int argc , char * argv[])  {
    int inputfd , outputfd , openflags;
    mode_t filePerms;
    ssize_t numRead;
    char buf[BUF_SIZE];

    if( argc != 3 || strcmp(argv[1] , "--help") == 0 ) {
        fflush(stdout);
        exit(EXIT_FAILURE);
    }

    inputfd = open(argv[1] , O_RDONLY);
    if(inputfd == -1)  {
        printf("%s","can not open file!\n");
        exit(EXIT_FAILURE);
    }

    openflags = O_CREAT | O_WRONLY | O_TRUNC;
    filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;

    outputfd = open(argv[2] , openflags , filePerms);
    if( outputfd == -1 )  {
        printf("%s\n" , "File error!");
        exit(EXIT_FAILURE);
    }

    while ((numRead = read( inputfd , buf , BUF_SIZE)) > 0 )  {
        if (write(outputfd , buf , numRead ) != numRead )  {
            printf("%s\n" , "couldn't write whole buf!");
            exit(EXIT_FAILURE);
        }
    }
    if ( numRead == -1 )  {
        printf ("read error");
        exit(EXIT_FAILURE);
    }
    if(close(inputfd) == -1 )  {
        printf("%s\n" , "close error");
        exit(EXIT_FAILURE);
    }
    if (close(outputfd) == -1 ) {
        printf("%s\n", "close error");
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}

