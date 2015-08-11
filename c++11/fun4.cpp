/*************************************************************************
    > File Name: fun4.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: 2015年08月07日 星期五 15时51分54秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cerrno>
#include<list>
#include<algorithm>

int main( int argc , char * argv[] )  {
    std::string  line = "abc,def,qaz,xyz";

    auto com = std::find(line.cbegin() , line.cend() , ',');
    std::cout << std::string(line.cbegin() , com)  << std::endl;

    return EXIT_SUCCESS;
}

