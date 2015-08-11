/*************************************************************************
    > File Name: fun6.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: 2015年08月09日 星期日 11时01分01秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cerrno>
#include<memory>
#include<vector>

int main( int argc , char * argv[] )  {
    std::shared_ptr<std::string>  sp;
    std::make_shared<std::string>();

    std::make_shared<std::string>("a");

    std::shared_ptr<std::string> sp2 = std::make_shared<std::string>();
    std::shared_ptr<std::string> sp3 = std::make_shared<std::string>("b");
    return EXIT_SUCCESS;
}

