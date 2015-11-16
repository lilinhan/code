/*************************************************************************
    > File Name: rename.c
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: Mon 09 Nov 2015 17:21:44 CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main(int argc , char * argv[])  {
    //我们用上一个刚创建foo文件
    if(rename("foo", "balabala") == -1) {
        fprintf(stderr, "rename failed!");
        exit(0);
    }

    return EXIT_SUCCESS;
}

