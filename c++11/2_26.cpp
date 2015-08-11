/*************************************************************************
    > File Name: 2_26.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: 2015年07月21日 星期二 20时57分48秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cerrno>

template<typename T> void TempFun(T a)  {
    std::cout << a << std::endl;
}

int main( int argc , char * argv[] )  {
    TempFun(1);
    TempFun("1");
    return EXIT_SUCCESS;
}

