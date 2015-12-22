/*************************************************************************
    > File Name: RequestManager.h
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Organization: Xiyou Linux Group
    > Created Time: 2015年12月22日 星期二 21时00分55秒
 ************************************************************************/
#pragma once

#include<iostream>

class RequestManager
{
    public:
        RequestManager();   //init the RequestManager;
        ~RequestManager() {}  //delete the RequestManager;

    private:
        Request * getRequestHandle();

        int filefd;
        Request * request;

};
