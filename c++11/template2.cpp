/*************************************************************************
    > File Name: template2.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: Mon 16 Nov 2015 10:31:52 CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cerrno>

template<typename T>
struct identity
{
    typedef T type;
};

template<typename T = int>
void func(typename identity<T>::type val, T = 0)
{
    std::cout << "In func  " << val << "    " << std::endl;
}


int main( int argc , char * argv[] )  {
    func(123);
    func(123, 213.0);
    return EXIT_SUCCESS;
}

