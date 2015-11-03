/*************************************************************************
    > File Name: templatet.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: Fri 30 Oct 2015 11:20:53 CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cerrno>

template<typename T1, typename T2>
struct selectlst
{
    typedef T1 type;
};
int main( int argc , char * argv[] )  {
    std::cout << selectlst<10, 10>::type << std::endl;
    return EXIT_SUCCESS;
}

