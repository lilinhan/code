/*************************************************************************
    > File Name: test.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: 2015年07月04日 星期六 10时33分21秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cerrno>
#include<vector>
#include<list>

template<typename T>
void Print(T value)
{
    std::cout<< value <<std::endl;
}

template<typename Head , typename... Rail>
void Print(Head head , Rail... rail)
{
    std::cout << head << ",";
    Print(rail...);
}

int main( int argc , char * argv[] )  {
    Print(1);
    Print(1 , "hello");
    Print(1 , "hello" , 'H');
    return EXIT_SUCCESS;
}

