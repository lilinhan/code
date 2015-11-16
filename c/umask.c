/*************************************************************************
    > File Name: umask.c
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: Fri 06 Nov 2015 18:02:18 CST
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

#define RWRWRW (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)

int main(int argc , char * argv[])  {
    //使用umask将所有的权限撤销
    umask(0);
    if(creat("foo", RWRWRW) < 0) {
        fprintf(stderr, "create error for foo");
        exit(0);
    }
    //使用umask只撤销S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH权限
    umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    if(creat("bar", RWRWRW) < 0) {
        fprintf(stderr, "create error for bar");
        exit(0);
    }

    //执行结束之后，回到终端下，我们使用ls -al命令查看刚才创建的两个文件
    return EXIT_SUCCESS;
}

