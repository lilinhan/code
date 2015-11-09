/*************************************************************************
    > File Name: chmod.c
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: Fri 06 Nov 2015 15:40:30 CST
 ************************************************************************/

#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>

int main(int argc , char * argv[])  {
    /*我们可以在当前目录下使用"touch 1.text"命令创建一个文件
     *使用"ls -l 1.text"命令查看文件的属性
     *我们首先在程序中打印出文件的属性
     *我们使用chmod系统调用来更改文件的属性
     *打印更改之后的文件属性
     */
    struct stat buffer;
    if(stat("1.text", &buffer) == -1) {
        fprintf(stderr, "stat:");
        exit(1);
    }
    printf("Before change, file mode is %o\n",buffer.st_mode);

    //更改文件属性
    if(chmod("1.text", S_IRUSR | S_IWUSR | S_IXUSR) == -1) {
        fprintf(stderr, "chmod:");
        exit(0);
    }
    if(stat("1.text", &buffer) == -1) {
        fprintf(stderr, "stat:");
        exit(1);
    }
    printf("After change, file mode is %o\n",buffer.st_mode);
    return EXIT_SUCCESS;
}

