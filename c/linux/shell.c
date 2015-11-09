#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <dirent.h>


void print_prompt()
{
	printf("lewin@shell~$ ");
}


/*得到整行命令存入buf,命令不得大于256,以回车符结束*/
void get_input(char *buf, int *argcount, char arglist[100][256])
{
	int	len=0, j=0;
	char 	ch;
	char*	ptemp = NULL;

	ch = getchar();						//从键盘获取命令
	if(ch == '\n')
		return;						//遇换行符直接退出
	while((len < 256) && (ch != '\n')) {			//遇换行符或等于256时跳出循环
		buf[len] = ch;
		ch = getchar();
		len++;
	}
	if(len == 256) {					//若命令太长,则退出程序
		printf("the command is too long \n");
		exit(1);
	}
	buf[len] = '\0';					//给字符串加结束符
	if(strcmp(buf, "exit") == 0)
		exit(0);					//如果输入exit则退出程序

	/*解析命令,将结果存入二维数组*/
	int	i=0,k=0;
	for(i=0; i<100; i++) {
		arglist[i][0] = '\0';				//atglist[]用来存放解析后的命令,全部初始化为空字符串
	}
	i = 0;
	*argcount = 0;						//argcount 记录空格分离后的命令个数,初始化为0
	while(buf[i] != '\0') {					//结束符时停止

		if(buf[i] != ' ') {				//若当前字符不是空格,则加入arglist数组

			arglist[k][j] = buf[i];
			j++;
		}

		else {						//若遇空格,一维+1,二维赋0,即在第二行存储
			arglist[k][j] = '\0';
			k++;
			j=0;
		}
	 	arglist[k][j] = '\0';
		i++;
	}

	*argcount = k + 1;					//k为命令行下标,argcount为待执行命令数

}

/*判断命令是否存在于以下目录*/
int find_command(char *command)
{
	DIR 		*dp;
	struct dirent*	dirp;
	char* path[] = {"./","/bin","/usr/bin",NULL};
	int i=0;

	if(strncmp(command, "./",2) == 0)			//如当前命令可执行,取出命令
		command = command + 2;

	while(path[i] != NULL) {
		if( (dp = opendir(path[i])) == NULL ) { 	//打开目录
			printf("can not open the mulu\n");
			return 0;
		}
		else{
			while((dirp = readdir(dp)) != NULL) {	//读取目录流
				if(strcmp(dirp->d_name, command) == 0) {
					closedir(dp);
					return 1;		//若path 环境中找到该命令,关闭目录流,返回1
				}
			}
			closedir(dp);
		}
		i++;
	}
	return 0;						//未找到返回0
}



int do_cmd(int *argcount, char arglist[100][256])
{
	int i, len, j, p=0;
	int how=0, background=0 ;
	int	pid, fd;
	char *argnext[256];
	int status;
	char*	arg[256];

	int	flag=0;


	if ((pid = fork()) != -1){					//fork一个子进程

    }

}


int main(int argc, char **argv)
{
	int		i,j,len;
	int		argcount;
	char		arglist[100][256];
	char		**arg = NULL;
	char 		*buf;
	char 		*buffer;
	char		a[80];
	char		b[80];
	buf = (char *)malloc(256);					//分配空间
	buffer = (char *)malloc(80);
	if(buf == NULL) {
		printf("malloc failed\n");				//分配失败
		exit(-1);
	}

	while(1) {
		memset(buf, 0, 256);					//初始化数组
		print_prompt();						//输出提示符
		get_input(buf, &argcount, arglist);			//按空格分解命令
		if(strcmp(arglist[0], "cd") == 0) {
			if(argcount == 1) {
				chdir("/home/lewin");
			} else if(argcount == 2) {
				if(strcmp(arglist[1],"..") == 0) {
					 getcwd(buffer, 80);
					 len = strlen(buffer);
					 strcpy(a, buffer);
					 for(i=len; i>0; i--) {
						if(a[i] == '/'){
						a[i] = '\0';
						break;
						}
					}
					chdir(a);
				}

				else if(strcmp(arglist[1], ".") == 0){
					continue;
				} else if(strcmp(arglist[1],"~") == 0) {
					chdir("/home/lewin");
				} else {
					if(chdir(arglist[1]) == -1)
					printf("dir is wrong!\n");
 				}
			}
	}
		else if (do_cmd(&argcount, arglist) == 1){			//解析命令并执行
			wait(NULL);
            getchar();			//等待子进程结束
			printf("已完成\n");
		}

	}

	if(buf != NULL) {
		free(buf);						//释放buf内存
		buf = NULL;
	}

	exit(0);
}
