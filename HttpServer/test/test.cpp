/*************************************************************************
    > File Name: test.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Organization: Xiyou Linux Group
    > Created Time: 2016年01月19日 星期二 21时39分20秒
 ************************************************************************/
#include<iostream>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<strings.h>

#define PORT 8000

int main(int argc, char *argv[])
{
    int socketfd;
    struct sockaddr_in ServerAddress;
    struct sockaddr_in ClientAddress;
    socklen_t size = sizeof(ClientAddress);
    bzero(&ServerAddress, sizeof(ServerAddress));
    ServerAddress.sin_family = AF_INET;
    ServerAddress.sin_addr.s_addr = htons(INADDR_ANY);
    ServerAddress.sin_port = htons(PORT);

    if((socketfd = socket(PF_INET, SOCK_STREAM, 0)) < 0)  {
        std::cout << "socket error!" << std::endl;
        exit(0);
    }

    int enable = 1;
    if(setsockopt(socketfd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(enable)) < 0)  {
        std::cout << "Set socket option error" << std::endl;
        exit(0);
    }

    if(bind(socketfd, (struct sockaddr *)&ServerAddress, sizeof(ServerAddress)))  {
        std::cout << "bind error!" << std::endl;
        exit(0);
    }

    if(listen(socketfd, 20)) {
        std::cout << "Listen error" << std::endl;
        exit(0);
    }

    while(1) {
        int connfd = accept(socketfd, (struct sockaddr *)&ClientAddress, &size);
        if(connfd < 0) {
            std::cout << "accept error!" << std::endl;
            break;
        }

        char buf[1024];
        bzero(buf, 1024);
        int length = recv(connfd, buf, 1024, 0);

        if(length < 0) {
            std::cout << "recv error" << std::endl;
            break;
        }

        std::cout << buf << std::endl;
        close(connfd);
    }
    close(socketfd);
    return EXIT_SUCCESS;
}

