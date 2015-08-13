/*************************************************************************
    > File Name: fun8.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: 2015年08月13日 星期四 09时57分30秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cerrno>
class A{
    public:
        A(){}
        A(int v):v(v) {}
        A(const A & b) {
            v = b.v + 10;
        }
        int v;
};

A test(A a)  {
    std::cout << a.v << std::endl;
    return a;
}

int main( int argc , char * argv[] )  {
    A a(1);
    A b = test(a);
    std::cout << test(a).v << std::endl;
    std::cout << b.v <<  std::endl;

    A arr[] = {a};
    std::cout << arr[0].v << std::endl;
    return EXIT_SUCCESS;
}

