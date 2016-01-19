/*************************************************************************
    > File Name: Socket.h
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Organization: Xiyou Linux Group
    > Created Time: 2016年01月19日 星期二 20时36分29秒
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<strings.h>

class Socket{
    private:
        int socketfd;   //socket id
        struct sockaddr_in ServerAddress;  //server address
        struct sockaddr_in ClientAddress;  //client address

    public:
        Socket();
        void SetSocketNonBlocking();
        void InitSocket();
};
