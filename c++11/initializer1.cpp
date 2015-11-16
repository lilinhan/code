/*************************************************************************
    > File Name: initializer1.cpp
    > Author: lewin
    > Mail: lilinhan1303@gmail.com
    > Company:  Xiyou Linux Group
    > Created Time: Mon 16 Nov 2015 10:57:43 CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cerrno>

class Foo
{
    public:
        Foo(int) {}

    private:
        Foo(const Foo &);
};

int main( int argc , char * argv[] )  {
    Foo a1(123);
    Foo a2 = {123};
    Foo a3 {123};

    int a5 = {3};
    int a6 {3};

    return EXIT_SUCCESS;
}

