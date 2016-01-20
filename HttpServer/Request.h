/*************************************************************************
    > File Name: Request.h
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Organization: Xiyou Linux Group
    > Created Time: 2016年01月19日 星期二 20时48分53秒
 ************************************************************************/
#pragma once

#include<iostream>
#include<cstdlib>
#include<string>

class Request{
    public:
        std::string RequestMethod;
        std::string RequestPath;
        std::string RequestVersion;
        std::string RequestConnection;  //keep-alive
        std::string RequestContent;
        std::string RequestContentLength;
        std::string RequestParam;


};
