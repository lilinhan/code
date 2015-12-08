/*************************************************************************
    > File Name: exec.c
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Organization: Xiyou Linux Group
    > Created Time: 2015年12月07日 星期一 14时42分21秒
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
    //execl("/bin/ls", "ls", NULL);
    //execlp("ls", "ls", "-a", NULL);
    //char *envp[] = {"HOME=/usr/home", "LOGNAME=home", NULL};
    //execle("/bin/ls", "ls", "-l", NULL,envp);

    //char *cmd[] = {"ls", "-l", NULL};
    //execv("/bin/ls", cmd);

    //char *cmd[] = {"ls", "-a", NULL};
    //char *env[] = {"HOME=/usr/home", "LOGNAME=home", NULL};
    //execve("/bin/ls", cmd, env);

    char *cmd[] = {"ls", "-l", NULL};
    execvp("ls", cmd);

    return EXIT_SUCCESS;
}

