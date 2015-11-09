/*************************************************************************
    > File Name: chown.c
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: Fri 06 Nov 2015 17:26:01 CST
 ************************************************************************/

#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc , char * argv[])  {
    /*我们可以在当前目录下使用"touch 1.text"命令创建一个文件
     *使用"ls -l 1.text"命令查看文件所属的用户和组
     *我们首先在程序中打印出文件所属的用户和组
     *我们使用chmod系统调用来更改文件所属的用户和组
     *打印更改之后的文件所属的用户和组
     */

    struct stat st;
    if(stat("1.text", &st) == -1) {
        fprintf(stderr, "stat:");
        exit(0);
    }
    printf("Before change, file owner is %d\t file group is %d\n",st.st_uid, st.st_gid);

    //因为我要将文件改为root用户和root组，因此运行时候需要加sudo权限.或者使用root用户执行
    if(chown("1.text", 0, 0) == -1) {
        fprintf(stderr, "chown :");
        exit(0);
    }
    if(stat("1.text", &st) == -1) {
        fprintf(stderr, "stat:");
        exit(0);
    }
    printf("After change, file owner is %d\t file group is %d\n",st.st_uid, st.st_gid);
    return EXIT_SUCCESS;
}

